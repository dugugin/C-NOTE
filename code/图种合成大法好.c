
#if 0
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>

void copyt(char *pic1, char *file1, char *file2);

void main()
{
	printf("Note：输入图片与隐藏文件的文件名即可。\n\n");
	char pic1[50], file1[50], file2[50];

	printf("\nplease input pictrure:");
	scanf("%s", pic1);	//不能给字符串指针进行键入赋值，因为无法得知预留内存大小
	printf("\nplease input file:");
	scanf("%s", file1);
	printf("\n输入合成文件名：");
	scanf("%s", file2);

	copyt(pic1, file1, file2);

	printf("\nSuccess!");
	system("pause");
}

void copyt(char *pic1, char *file1, char *file2)
{
	FILE *p1 = NULL;
	FILE *p2 = NULL;
	FILE *p = NULL;
	void *buf = NULL;	//缓存buffer。或者这一行替换为char buf;
	if ((p1 = fopen(pic1, "rb")) == NULL)	//打开源文件p1
	{
		printf("\ncannot open pic!\n");
		exit(0);	//终止程序
	}
	else
	{
		printf("\nopen pic successfully!\n");
	}
	if ((p2 = fopen(file1, "rb")) == NULL)
	{
		printf("\ncannot open the file1!\n");
		exit(0);	//终止程序
	}
	else
	{
		printf("\nopen file1 successfully!\n");
	}
	if ((p = fopen(file2, "wb")) == NULL)	//wb+为读写建立一个新的二进制文件
	{
		printf("\ncannot open file2!\n");
		exit(0);	//终止程序
	}
	else
	{
		printf("\nopen file2 successfully!\n");
	}
	while (!feof(p1))
	{
		fread(&buf, 1, 1, p1);	//将原文件内容写到buffer中
		fwrite(&buf, 1, 1, p);	//将buffer中的内容写回到目标文件
	}
	fclose(p1);

	while (!feof(p2))
	{
		fread(&buf, 1, 1, p2);	//将原文件内容写到buffer中
		fwrite(&buf, 1, 1, p);	//将buffer中的内容写回到目标文件
	}
	fclose(p); fclose(p2);
}
#endif

