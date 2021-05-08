

#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally





float __attribute__(( aligned(32))) a[MAX1][MAX2]  
    , __attribute__(( aligned(32))) t[MAX2][MAX3] 
    , __attribute__(( aligned(32))) c_result[MAX1][MAX3] 
    , __attribute__(( aligned(32))) c_tra[MAX3][MAX2] ;


int main()
{
	singleCore
	assignMatrixf32(a);
	assignMatrixf32(t);
	programName="MUL2F";
	int i, j,k;
	// variables for vector section
		__m128 row0, row1, row2, row3;
				
	float temp4[4];//به عنوان یه حافظه موقت استفاده میشه که باهاش اعداد رو جمع مکنیم
	__m128  sum0_i;//حاصلجمع ضربهایی که انجام میشه تا اخرین مرحله تو این ذخیره میشه 

 	begin_rdtsc
 	
		for( i=0;i<MAX2;i+=4)
		  for(j=0;j<MAX3;j+=4){//IACA_START
			row0 = _mm_load_ps(&t[i][j]);
			row1 = _mm_load_ps(&t[i+1][j]);
			row2 = _mm_load_ps(&t[i+2][j]);
			row3 = _mm_load_ps(&t[i+3][j]);
			
			_MM_TRANSPOSE4_PS ( row0, row1, row2, row3);
			
			_mm_store_ps(&c_tra[j  ][i], row0);
			_mm_store_ps(&c_tra[j+1][i], row1);
			_mm_store_ps(&c_tra[j+2][i], row2);
			_mm_store_ps(&c_tra[j+3][i], row3);
		

		 }//IACA_END
	
	for( i=0;i<MAX1;i++){
		for(j=0;j<MAX3;j++){
			sum0_i = _mm_setzero_ps();//برای مرحله بعد بردار حاصل جمع رو صفر میکنیم
			for(k=0;k<MAX2;k+=4){
				//ماتریس c_tra ترانهاده ماتریس دوم شرکت کننده تو ضرب هست که ترانهاده باعث میشه بتونیم
				// از دوتا مرتریس ردیف هارو با هم ضرب کنیم و حاصلجمع بگیریم به جای اینکه
				//از سطر ماتریس اول بخونیم و با ستون ماتریس دوم جمع کنیم 
				//دلیل این کار اینه که دستور مستقیم واسه خوندن ستونی تو SSE نیست
				sum0_i = _mm_add_ps(sum0_i , _mm_mul_ps(_mm_load_ps(&a[i][k]) , _mm_load_ps(&c_tra[j][k])));
			}
			_mm_store_ps(&temp4[0], sum0_i);	
			c_result[i][j] = temp4[0]+temp4[1]+temp4[2]+temp4[3];

		}
	}
	
	end_rdtsc
	
	return 0;
}
