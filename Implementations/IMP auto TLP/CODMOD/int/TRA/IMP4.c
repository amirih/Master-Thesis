#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally


//numbers





//global data for sequentila matrix operations
int __attribute__(( aligned(32))) t[MAX1][MAX2]  
, __attribute__(( aligned(32))) c_tra[MAX3][MAX2] ;


int main()
{
	singleCore
	assignMatrixi32(t);
	int i, j;
	//that means TRA kernel That is modified and Scalar and the version is 1 
	programName="TRAMOD1V4";

	begin_rdtsc
		for(j=0;j<MAX3;j++){
			for( i=0;i<MAX2;i+=8){
				c_tra[j][i]   = t[i][j];
				c_tra[j][i+1] = t[i+1][j];
				c_tra[j][i+2] = t[i+2][j];
				c_tra[j][i+3] = t[i+3][j];
				c_tra[j][i+4] = t[i+4][j];
				c_tra[j][i+5] = t[i+5][j];
				c_tra[j][i+6] = t[i+6][j];
				c_tra[j][i+7] = t[i+7][j];
			
			}//IACA_END
		}
	end_rdtsc
	
	return 0;
}

