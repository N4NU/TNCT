#include <stdio.h>

void read_data(char data[512]);
void printimg(char data[512]);
void expand(char data[512],char pattern [64][64]);
void clear_ry(char data[]);
void compress(char data[512],char pattern[64][64]);
void outline(char p[64][64]);


int main ()
{
	char data[512],pattern[64][64],x,y;
	read_data(data);
	expand(data,pattern);
	outline(pattern);
	compress(data,pattern);
	printimg(data);
}

//data[]に画像データを読み込む
void read_data(char data[512])
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

//data[]をクリアする
void clear_ry(char data[512])
{
	int i;
	for(i=0;i<512;i++) data[i]='\0';
}

//p[]の輪郭抽出を行う
void outline(char p[64][64])
{
	//pget(int x, int y)        : 入力画像の指定したx,y座標からピクセルの色を読み出す（0か1）
	//pset(int x, int y, int c) : 出力画像の指定したx,y座標に色をセットする（cは0か1）
	int sx, sy;    //追跡開始点
	int px, py;    //追跡点
	int flag;       //調査点フラグ
	int IsFirst;   //
	int ex=0;

	//画像内を走査し有効画素を探す
	for(sy=0;sy< 64; sy++) {
		for(sx=0; sx < 64; sx++) {
			//printf("(sx,sy)=(%d,%d)\n",sx,sy);
			//printf("p[sx][sy]=%c\n",p[sx][sy]);
			//有効画素があった場合ループから抜ける
			if(p[sy][sx]==1){
				ex=1;
				break;
			}
		}
		if(ex){
			break;
		}
	}
	
	//有効画素が見つかっていた場合、追跡処理に入る
	if(ex){
		printf("sx:%d,sy:%d\n",sx,sy);
		px = sx;
		py = sy;
		p[py][px]=1;
		flag = 2;      //最初の調査点を左下にセットする
		IsFirst = 1;
		//追跡開始点と追跡点が同じ座標なるまで輪郭追跡処理
		while(px!=sx||py!=sy||IsFirst== 1 ) {
			switch(flag) {
				case 0:    //左上を調査
					if(p[py-1][px-1]!=0){
						p[py-1][px-1]=1;
						px=px-1;
						py=py-1;
						flag=6;
						break;
					}
				case 1:    //左を調査
					if(p[py-1][px]!=0) {
						p[py-1][px-1]=1;
						py=py-1;
						flag=0;
						break;
					}
				case 2:    //左下を調査
					if(p[py-1][px+1]!=0){
						p[py-1][px+1]=1;
						py=py-1;
						px=px+1;
						IsFirst=0;
						flag=0;
						break;
					}
				case 3:    //下を調査
					if(p[py][px+1]!=0) {
						p[py][px+1]=1;
						px=px+1;
						IsFirst=0;
						flag=2;
						break;
					}
				case 4:    //右下を調査
					if(p[py+1][px+1]!=0){
						p[py+1][px+1]=1;
						px=px+1;
						py=py+1;
						IsFirst=0;
						flag=2;
						break;
					}
				case 5:    //右を調査
					if(p[py+1][px]!=0){
						p[py+1][px]=1;
						py=py+1;
						IsFirst=0;
						flag=4;
						break;
					}
					else {
						//孤立点であった場合
						if(IsFirst == 1){
							IsFirst=0;
							break;
						}
					}
				case 6:    //右上を調査
					if(p[py+1][px-1]!=0){
						p[py+1][px-1]=1;
						py=py+1;
						px=px-1;
						flag=4;
						break;
					}
				case 7:    //上を調査
					if(p[py][px-1]!=0) {
						p[py][px-1]=1;
						py=py;
						px=px-1;
						flag=6;
						break;
					}
				flag=0;
			}
			printf("flag:%d\n",flag);
			printf("(px,py)=(%d,%d)\n",px,py);
		}
	}
}