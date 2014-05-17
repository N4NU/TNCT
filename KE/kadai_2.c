#include <stdio.h>

void read_data(char data[512]);
void printimg(char data[512]);
void expand(char data[512],char pattern [64][64]);
void clear_ry(char data[]);
void compress(char data[512],char pattern[64][64]);


int main ()
{
	char data[512],pattern[64][64];
	read_data(data);
	printimg(data);
	expand(data,pattern);
	for(y=0;y<64;y++){
		for(x=0;x<64;x++){
			putchar(pattern[y][x]==1 ? '@':'o');
		}
		putchar('\n');
	}
	clear_ry(data);
	compress(data,pattern);
	printimg(data);
}

//data[]に画像データを読み込む
void read_data(char data[512])
{
	int main(int argc,char *argv[])
{
	FILE *fdr;
	int i,j,k,l,b,count=1;
	char fn[256];
	printf("Please input a filename :");
	scanf("%s",fn);
	if((fdr=fopen(fn,"rb"))==NULL){
		fprintf(stderr,"cannot open %s\n",fn);
		return;
	}
	if(fread(data,512,1,fdr)!=1){
		fprintf(stderr,"cannot read %s\n",fn);
		return;
	}
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
void expand(char data[512],char pattern [64][64]);
{
	
}

//expandの逆操作
void compress(char data[512],char pattern[64][64]);
{
	/*
	p[40][30]をd[512]に入れる
	p[40][30]は40*64+30
	d[]の(40*64+30)/8=323
	(40*64+30)%8=30%8=6
	左から6番目だけ1
	unsigned char m = 128
	m=m>>6
	これを足す
	*/
}

//data[]をクリアする
void clear_ry(char data[])
{
	int i=0;
	while(data[i]='\0') i++;
}


