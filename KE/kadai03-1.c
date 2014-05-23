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

//data[]�ɉ摜�f�[�^��ǂݍ���
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

//1�������̉摜�f�[�^���󂯎��C��ʂɕ\������֐�
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

//1�������̉摜�f�[�^���󂯎��Cchar�^��2�����z��ɓW�J���ĕۑ�����֐�
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

//expand�̋t����
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

//data[]���N���A����
void clear_ry(char data[512])
{
	int i;
	for(i=0;i<512;i++) data[i]='\0';
}

//p[]�̗֊s���o���s��
void outline(char p[64][64])
{
	//pget(int x, int y)        : ���͉摜�̎w�肵��x,y���W����s�N�Z���̐F��ǂݏo���i0��1�j
	//pset(int x, int y, int c) : �o�͉摜�̎w�肵��x,y���W�ɐF���Z�b�g����ic��0��1�j
	int sx, sy;    //�ǐՊJ�n�_
	int px, py;    //�ǐՓ_
	int flag;       //�����_�t���O
	int IsFirst;   //
	int ex=0;

	//�摜���𑖍����L����f��T��
	for(sy=0;sy< 64; sy++) {
		for(sx=0; sx < 64; sx++) {
			//printf("(sx,sy)=(%d,%d)\n",sx,sy);
			//printf("p[sx][sy]=%c\n",p[sx][sy]);
			//�L����f���������ꍇ���[�v���甲����
			if(p[sy][sx]==1){
				ex=1;
				break;
			}
		}
		if(ex){
			break;
		}
	}
	
	//�L����f���������Ă����ꍇ�A�ǐՏ����ɓ���
	if(ex){
		printf("sx:%d,sy:%d\n",sx,sy);
		px = sx;
		py = sy;
		p[py][px]=1;
		flag = 2;      //�ŏ��̒����_�������ɃZ�b�g����
		IsFirst = 1;
		//�ǐՊJ�n�_�ƒǐՓ_���������W�Ȃ�܂ŗ֊s�ǐՏ���
		while(px!=sx||py!=sy||IsFirst== 1 ) {
			switch(flag) {
				case 0:    //����𒲍�
					if(p[py-1][px-1]!=0){
						p[py-1][px-1]=1;
						px=px-1;
						py=py-1;
						flag=6;
						break;
					}
				case 1:    //���𒲍�
					if(p[py-1][px]!=0) {
						p[py-1][px-1]=1;
						py=py-1;
						flag=0;
						break;
					}
				case 2:    //�����𒲍�
					if(p[py-1][px+1]!=0){
						p[py-1][px+1]=1;
						py=py-1;
						px=px+1;
						IsFirst=0;
						flag=0;
						break;
					}
				case 3:    //���𒲍�
					if(p[py][px+1]!=0) {
						p[py][px+1]=1;
						px=px+1;
						IsFirst=0;
						flag=2;
						break;
					}
				case 4:    //�E���𒲍�
					if(p[py+1][px+1]!=0){
						p[py+1][px+1]=1;
						px=px+1;
						py=py+1;
						IsFirst=0;
						flag=2;
						break;
					}
				case 5:    //�E�𒲍�
					if(p[py+1][px]!=0){
						p[py+1][px]=1;
						py=py+1;
						IsFirst=0;
						flag=4;
						break;
					}
					else {
						//�Ǘ��_�ł������ꍇ
						if(IsFirst == 1){
							IsFirst=0;
							break;
						}
					}
				case 6:    //�E��𒲍�
					if(p[py+1][px-1]!=0){
						p[py+1][px-1]=1;
						py=py+1;
						px=px-1;
						flag=4;
						break;
					}
				case 7:    //��𒲍�
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