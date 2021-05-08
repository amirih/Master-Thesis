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
		__m128 a0_i;


	programName="ADD2F";
	//REP_CODE(
	begin_rdtsc
 __m128 a0_i;//a0_i will store 4 numbers of float data type.
		for(i=0;i<MAX1;i++){	
			for(j=0;j<MAX2;j+=4){
				// resultVector = add(vector_a +vector_b), 
				//each vectors contain 4 float elements (4*32-bit = 128 bit SSE vector size)
				a0_i= _mm_add_ps( _mm_load_ps(&a[i][j]) ,  _mm_load_ps(&b[i][j]));
				
			//store the resultVector to the memory 
			_mm_store_ps(&c_result[i][j], a0_i);
			}
		}
		
	end_rdtsc //)
	
	//printf(" The best time: %lf sec in %d repetition for %dX%d matrix , result is %d \n",tBest,w, MAX1, MAX1, c_result[i/2][j/2]);
	//printf(" The best time: %lld sec in %d repetition for %dX%d matrix , result is %d \n",tBest,w, MAX1, MAX1, c_result[i/2][j/2]);

	
	
	
	return 0;
}
