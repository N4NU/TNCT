#include <stdio.h>

void read_data(char data[512]);
void printimg(char data[512]);
void expand(char data[512],char pattern [64][64]);
void clear_ry(char data[512]);
void compress(char data[512],char pattern[64][64]);
void outline(char p[64][64]);


int main ()
{
	char data[512],pattern[64][64];
	read_data(data);
	expand(data,pattern);
	clear_ry(data);
	outline(pattern);
	compress(data,pattern);
	printimg(data);
}

//dataに画像データを読み込む
void read_data(char data[512])
{
	FILE *fdr;
	char fn[256];
	printf("Please input a filename :");
	scanf("%s",fn);
	if((fdr=fopen(fn,"rb"))==NULL){
		fprintf(stderr,"cannot open %s\n",fn);
		exit(1);
	}
	if(fread(data,512,1,fdr)!=1){
		fprintf(stderr,"cannot read %s\n",fn);
		exit(1);
	}
	fread(data,sizeof(char),512,fdr);
	fclose(fdr);
}

//1文字分の画像データを受け取り，画面に表示する関数
void printimg(char data[512])
{
	int i,j,k,b;
	for(k=0;k<64;k++){
		for(i=k*8;i<k*8+8;i++){
			b=0x80;
			for(j=0;j<8;j++){
				if((data[i]&b)==0) printf(".");
				else printf("*");
				b=b>>1;
			}
		}
		printf("\n");
	}
}

//1文字分の画像データを受け取り，char型の2次元配列に展開して保存する関数
void expand(char data[512],char pattern [64][64])
{
	int i,j,k,b,l;
	for(k=0;k<64;k++){
		l=0;
		for(i=k*8;i<k*8+8;i++){
			b=0x80;
			for(j=0;j<8;j++){
				if((data[i]&b)==0) pattern[k][l]=0;
				else pattern[k][l]=1;
				b=b>>1;
				l++;
			}
		}
	}
}

//expandの逆操作
void compress(char data[512],char pattern[64][64])
{
	int i,j;
	unsigned char m;
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(pattern[i][j]==1){
				m = 128;
				m = m>>j%8;
				data[(i*64+j)/8] += m;
			}
		}
	}
}

//dataをクリアする
void clear_ry(char data[512])
{
	int i;
	for(i=0;i<512;i++) data[i]='\0';
}

//pの輪郭抽出を行う
void outline(char p[64][64])
{
	int i,j;
	for(i=1;i<63;i++){
		for(j=1;j<63;j++){
			if(p[i][j]==1){
				if(p[i][j-1]*p[i-1][j]*p[i][j+1]*p[i+1][j]!=0) p[i][j]=2;
			}
		}
	}
	for(i=1;i<63;i++){
		for(j=1;j<63;j++){
			if(p[i][j]==2) p[i][j]=0;
		}
	}
}