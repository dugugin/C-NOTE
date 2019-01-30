#if(0)

#include <stdio.h>
#include<stdlib.h>	//system()
#include<malloc.h>

#define LEN sizeof(struct student)

struct student *insert(struct student *head, struct student *p0);
struct student *del(struct student *head, int id);
void print(struct student *head);

int n;	//ȫ�ֱ�����������¼����˶������ݡ�

struct student
{
	int num;
	float score;
	struct student *next;
};

void main()
{
	struct student *head=NULL,*p0,*p;
	int c,id;
	printf("Welcome to Score Management System!\n");
	loopt:printf("=========��1����ɼ�����2ɾ���ɼ�����3�˳�ϵͳ=========\n");
	//����������ɾ��
	while (scanf("%d", &c)!=1 && scanf("%d", &c) != 2 && scanf("%d", &c) != 3)
	{
		printf("\t\tError!Please input again.\n");
	}

	switch (c)
	{
	case 1:		//¼��ɼ�

		
		do {

			printf("����Ҫ�����ѧ�������\n");
		loop1:
			p0 = (struct student *)malloc(LEN);
			printf("\tid:");
			scanf("%d", &p0->num);
			printf("\tscore:");
			scanf("%f", &p0->score);

			if (p0->score > 100 || p0->score < 0 ||( p=insert(head, p0) )== NULL)
			{
				printf("\n\t\tError!Please input again.\n����Ҫ�����ѧ���������\n");
				goto loop1;
			}
			//head = insert(head, p0);	//if�����head�Ѿ�������һ��insert
			head = p;
			n++;
			printf("\n\t\t\t��enter������һ���ɼ�����ESC�����ɼ�¼�벢��ӡ�ɼ���\n\n");
		} while (getch() != 27);	// 27==ESC	13==enter
		printf("\n\n");
		printf("\nthere are %d records!\n\n", n);
		print(head);
		break;

	case 2:	//ɾ���ɼ�
		do {
			printf("\t����Ҫɾ����ѧ�ţ�");
			scanf("%d", &id);
			
			head = del(head, id);	//p�ǲ�����ѧ�ź��head
			n--;
			printf("\n\t\t\t��enter����ɾ����һ���ɼ�����ESC����ɾ����ӡ�ɼ���\n\n");
		} while (getch() != 27);	
		printf("\n\n");
		printf("\nthere are %d records!\n\n", n);
		print(head);
		break;

	case 3:	//�˳�ϵͳ
		goto loope;
		break;

	}
	printf("\n\t\t\t��ESC�˳�ϵͳ����Enter���ز˵�����������\n");
	switch (c = getch())	// 27==ESC	13==enter
	{
	case 27:goto loope;
	case 13:goto loopt;
	}
	loope:printf("\n\n...Good Bye!\n");
	system("pause");
}

struct student *insert(struct student *head, struct student *p0)
{
	struct student *p1, *p2,*initial;
	initial = head;
	p1 = p2 = (struct student *)malloc(LEN);	//��̬�ĳ�ʼ����������(*p)[x]��[x]�Ǵ������ڴ��С��
	p1 = head;

	if (head)
	{
		while (p1->next != NULL && p0->num > p1->num)
			//���ҵ������λ�á�
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->num < p1->num)
		{
			if (p1 == head)
			{
				head = p0;
			}
			else
			{
				p2->next = p0;
			}
			p0->next = p1;
		}
		else if (p0->num == p1->num)
		{
			printf("\tNo insert:�޷����룬�Ѿ��и�ѧ���ĳɼ���Ӧ��ɾ����ѧ��������¼�롣\n");
			return initial;
			goto loopend;
		}
		else
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	else
	{
		head = p0;
		p0->next = NULL;
	}
	return head;
loopend:;
}

struct student *del(struct student *head, int id)
{
	struct student *p1, *p2;
	if (head)
	{
		p1 = head;
		while (id != p1->num && p1->next != NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (id == p1->num)
		{
			printf("\nɾ����ѧ��%d\n", id);
			if (p1 == head) head = p1->next;
			else p2->next = p1->next;
		}
		else printf("\n�Ҳ�����ѧ��\n");
	}
	else printf("\n���ǿձ�");
	return head;
}

void print(struct student *head)
{	
	printf("\n\tid\t\t\tscore\n");
	while (NULL != head)
	{
		printf("\t%d\t\t\t%f\n", head->num, head->score);
		head = head->next;
	}
}
#endif