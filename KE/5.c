#include <stdio.h>

int main(void)
{
	char ch[50];
	int num;
	FILE *fp;

	fp = fopen("aiueo.txt","r");

	//1�o�C�g��5�ǂݍ���(���v5�o�C�g)
	fread(ch,1,5,fp);

	//������̖����Ƀk������(\0)�͂����Ȃ��̂Ŏ蓮�Œǉ��B
	ch[5] = '\0';

	//�\��
	printf("�ǂݍ��񂾕����́�%s\n",ch);
	
	fread(ch,1,5,fp);

	//������̖����Ƀk������(\0)�͂����Ȃ��̂Ŏ蓮�Œǉ��B

	//�\��
	printf("�ǂݍ��񂾕����́�%s\n",ch);
	
	fclose(fp);
	
	return 0;
}