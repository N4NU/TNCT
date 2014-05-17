#include <stdio.h>

int main(void)
{
	char ch[50];
	int num;
	FILE *fp;

	fp = fopen("aiueo.txt","r");

	//1バイトを5個読み込み(合計5バイト)
	fread(ch,1,5,fp);

	//文字列の末尾にヌル文字(\0)はつけられないので手動で追加。
	ch[5] = '\0';

	//表示
	printf("読み込んだ文字は→%s\n",ch);
	
	fread(ch,1,5,fp);

	//文字列の末尾にヌル文字(\0)はつけられないので手動で追加。

	//表示
	printf("読み込んだ文字は→%s\n",ch);
	
	fclose(fp);
	
	return 0;
}