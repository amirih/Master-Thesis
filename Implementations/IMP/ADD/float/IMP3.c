#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally

float 	__attribute__(( aligned(32))) a[MAX1][MAX2],
		__attribute__(( aligned(32))) b[MAX2][MAX3],
		__attribute__(( aligned(32))) c_tra[MAX3][MAX2],
		__attribute__(( aligned(32))) c_result[MAX1][MAX3];//  	//will be used for operation 

//int a[MAX1], b[MAX1], c[MAX1] ;

int main()
{
	singleCore
	assignMatrixf32(a);
	assignMatrixf32(b);
	int i, j;
	__m256 a0_i , a_v, b_v;//, a1_i;


	programName="ADD3F";
	//REP_CODE(
	begin_rdtsc
	
	for(i=0;i<MAX1;i++){	
			for(j=0;j<MAX2;j+=8){//IACA_START
				a_v = _mm256_load_ps(&a[i][j]);
				b_v = _mm256_load_ps(&b[i][j]);
				a0_i= _mm256_add_ps( a_v ,  b_v);	
				_mm256_store_ps(&c_result[i][j], a0_i);

				
					//add 2 vector 
				//a1_i= _mm256_add_ps( _mm256_load_ps(&a[i+1][j]) ,  _mm256_load_ps(&b[i+1][j]));
				
			//_mm256_store_ps(&c_result[i+1][j], a1_i);
			}//IACA_END
		}
		
	end_rdtsc //)
	
	//printf(" The best time: %lf sec in %d repetition for %dX%d matrix , result is %d \n",tBest,w, MAX1, MAX1, c_result[i/2][j/2]);
	//printf(" The best time: %lld sec in %d repetition for %dX%d matrix , result is %d \n",tBest,w, MAX1, MAX1, c_result[i/2][j/2]);

	
	
	
	return 0;
}
