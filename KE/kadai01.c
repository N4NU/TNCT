#include <stdio.h> 

int main(int argc,char *argv[])
{
	FILE *fdr;
	int i,j,k,l,b,count=1;
	unsigned char pic[512];
	if(argc!=2){
		fprintf(stderr,"usage: %s image-file\n",argv[0]);
		exit(0);
	}
	if((fdr=fopen(argv[1],"rb"))==NULL){
		fprintf(stderr,"cannot open %s\n",argv[1]);
		exit(1);
	}
	
	for(l=0;l<20;l++){
		if(fread(pic,512,1,fdr)!=1){
			fprintf(stderr,"cannot read %s\n",argv[1]);
			exit(2);
		}
		printf("%d\n",count);
		for(k=0;k<64;k++){
			for(i=k*8;i<k*8+8;i++){
				b=0x80;
				for(j=0;j<8;j++){
					if((pic[i]&b)==0) printf(".");
					else printf("*");
					b=b>>1;
				}
			}
			printf("\n");
		}
		count++;
	}
	fclose(fdr);
	return 0;
}
