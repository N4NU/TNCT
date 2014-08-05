#include <stdio.h>
#include <stdlib.h>

#define DIM 196
#define N 200.0

int main()
{
	FILE *fp1, *fp2 ;
	char fn[0x80] ,spam[150];
	int i, j, k; /* Nはサンプル数,Dimは特徴の次元 */ 
	double ave[DIM] ;
	fp1 = fopen( "ave.dic", "w" ) ; 
	for( i = 0 ; i < 46 ; i++ ) {
		sprintf( fn, "c%02d.ftr", i+1 ) ;
		fp2 = fopen( fn, "r" ) ;
		for( j = 0; j < N; j++ ){
			for( k = 0; k < DIM ; k++ ){
				fgets(spam, 150, fp2);
				ave[k] += atoi(spam);
			}
		}
		for( j = 0; j < DIM ; j++){
			fprintf( fp1, "%f\n", ave[j] / N );
			ave[j]=0;
		} 
		fclose( fp2 ) ;
	}
	fclose( fp1 ) ;
}
