
#if 0
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>

void copyt(char *pic1, char *file1, char *file2);

void main()
{
	printf("Note������ͼƬ�������ļ����ļ������ɡ�\n\n");
	char pic1[50], file1[50], file2[50];

	printf("\nplease input pictrure:");
	scanf("%s", pic1);	//���ܸ��ַ���ָ����м��븳ֵ����Ϊ�޷���֪Ԥ���ڴ��С
	printf("\nplease input file:");
	scanf("%s", file1);
	printf("\n����ϳ��ļ�����");
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
	void *buf = NULL;	//����buffer��������һ���滻Ϊchar buf;
	if ((p1 = fopen(pic1, "rb")) == NULL)	//��Դ�ļ�p1
	{
		printf("\ncannot open pic!\n");
		exit(0);	//��ֹ����
	}
	else
	{
		printf("\nopen pic successfully!\n");
	}
	if ((p2 = fopen(file1, "rb")) == NULL)
	{
		printf("\ncannot open the file1!\n");
		exit(0);	//��ֹ����
	}
	else
	{
		printf("\nopen file1 successfully!\n");
	}
	if ((p = fopen(file2, "wb")) == NULL)	//wb+Ϊ��д����һ���µĶ������ļ�
	{
		printf("\ncannot open file2!\n");
		exit(0);	//��ֹ����
	}
	else
	{
		printf("\nopen file2 successfully!\n");
	}
	while (!feof(p1))
	{
		fread(&buf, 1, 1, p1);	//��ԭ�ļ�����д��buffer��
		fwrite(&buf, 1, 1, p);	//��buffer�е�����д�ص�Ŀ���ļ�
	}
	fclose(p1);

	while (!feof(p2))
	{
		fread(&buf, 1, 1, p2);	//��ԭ�ļ�����д��buffer��
		fwrite(&buf, 1, 1, p);	//��buffer�е�����д�ص�Ŀ���ļ�
	}
	fclose(p); fclose(p2);
}
#endif

