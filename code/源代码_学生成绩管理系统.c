#if(0)

#include <stdio.h>
#include<stdlib.h>	//system()
#include<malloc.h>

#define LEN sizeof(struct student)

struct student *insert(struct student *head, struct student *p0);
struct student *del(struct student *head, int id);
void print(struct student *head);

int n;	//全局变量，用来记录存放了多少数据。

struct student
{
	int num;
	float score;
	struct student *next;
};

void main()
{
	struct student *head = NULL, *p0, *p;
	int c, id;
	printf("  Welcome to Score Management System!\n");
loopt:printf("=========按1插入成绩；按2删除成绩；按3退出系统=========\n");

	//控制输入与删除
	scanf("%d", &c);
	while (c != 1 && c != 2 && c != 3)
	{
		printf("\t\tError!Please input again.\n");
		scanf("%d", &c);
	}

	switch (c)
	{
	case 1:		//录入成绩


		do {

			printf("输入要插入的学号与分数\n");

			p0 = (struct student *)malloc(LEN);
			printf("\tid:");
			scanf("%d", &p0->num);
			printf("\tscore:");
			scanf("%f", &p0->score);

			while (p0->score > 100 || p0->score < 0 || (p = insert(head, p0)) == NULL)
			{
				printf("\n\t\tError!Please input again.\n\n重新输入要插入的学号与分数：\n");
				printf("\tid:");
				scanf("%d", &p0->num);
				printf("\tscore:");
				scanf("%f", &p0->score);
			}
			//head = insert(head, p0);	//if里面的head已经进行了一次insert
			head = p;
			n++;
			printf("\n\t\t\t按enter插入下一个成绩；按ESC结束成绩录入并打印成绩表。\n\n");
		} while (getch() != 27);	// 27==ESC	13==enter
		print(head);
		break;

	case 2:	//删除成绩
		do {
			printf("\t输入要删除的学号：");
			scanf("%d", &id);

			p = del(head, id);	//p是插入新学号后的head
			head = p;
			if (n > 0) n--;
			printf("\n\t\t\t按enter继续删除下一个成绩；按ESC结束删除并打印成绩表。\n\n");
		} while (getch() != 27);
		print(head);
		break;

	case 3:	//退出系统
		break;

	}

	printf("\n\t\t\t按ESC确认退出系统，按Enter返回菜单继续操作。\n");
	switch (c = getch())	// 27==ESC	13==enter
	{
	case 27:goto loope;
	default:goto loopt;
	}

loope:printf("\n\n...Good Bye!\n");
	system("pause");
}

struct student *insert(struct student *head, struct student *p0)
{
	struct student *p1, *p2, *initial;
	initial = head;
	p1 = p2 = (struct student *)malloc(LEN);	//动态的初始化，类似于(*p)[x]，[x]是待填充的内存大小。
	p1 = head;

	if (head)
	{
		while (p1->next != NULL && p0->num > p1->num)
			//先找到插入的位置。
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
			printf("\tNo insert:无法插入，已经有该学生的成绩。应先删除该学号再重新录入。\n");
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
			printf("\n删除了学号%d\n", id);
			if (p1 == head) head = p1->next;
			else p2->next = p1->next;
		}
		else printf("\n找不到该学号\n");
	}
	else printf("\n这是空表");
	return head;
}

void print(struct student *head)
{
	printf("\n\n");
	printf("\nthere are %d records!\n\n", n);
	if (NULL != head) printf("\n\tid\t\t\tscore\n");
	while (NULL != head)
	{
		printf("\t%d\t\t\t%f\n", head->num, head->score);
		head = head->next;
	}
}

#endif
