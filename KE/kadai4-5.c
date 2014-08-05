#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define DIM 196

int main( int argc, char *argv[] )
{
	int i, j, k, sum, min, min_num, col_num = 0, finished = 0 , test_data[DIM]={0}, result[1000]={0};
	char spam[150]={0};
	FILE *test_file, *dic_file;
	fpos_t size;
	test_file = fopen( argv[1], "r" ) ;
	dic_file = fopen("ave.dic","r");
	while(1){
		min = INT_MAX;
		for( j = 0; j < DIM ; j++ ){
			if(fgets(spam, sizeof(spam), test_file)==NULL){
				finished = 1;
				break;
			}
			test_data[j]=atoi(spam);
		}
		if( finished ){
			break;
		}
		for(j=0;j<46;j++){
			sum=0;
			for(k=0;k<DIM;k++){
				fgets(spam, 150, dic_file);
				sum += pow(atoi(spam) - test_data[k],2);
			}
			if ( sum < min ) {
				min = sum;
				min_num = j;
			}
		}
		printf("%3d文字目:%d\n",i+1, min_num );
		result[i] = min_num;
		i++;
		fseek(dic_file, 0, SEEK_SET);
	}
	argv[1][0]='0';
	argv[1][3]='\0';
	for(j=0;j<i;j++){
		if (result[j] == ( atoi( argv[1] ) - 1 ) ){
			col_num += 1;
		}
	}
	printf("Result: %d / %d\n", col_num, i);
	fclose(test_file);
}
