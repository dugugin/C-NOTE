[toc]

# ���ǰα�����д�����淶��ʶ����

![1](pic/c���Թؼ���.png)
# headͷ�ļ�
![2](pic/ͷ�ļ�.png)

printf��ʹ��Ҫ�õ�stdioͷ�ļ�


ͷ�ļ�define.h�ı�д��

```
//����.h��д����һ��
#define lesson_1 1
//Ȼ����c�ļ�������
#include <stdio.h> //input & output
#include <stdlib.h> //pause
#include <math.h>
#include "define.h"
#if lesson_1
	int main(void)
	{
		printf("\"hello world\"\n");	
		//���{��hello world��}\n�س� \t����
		system("pause");
		return 0;
	}
#endif

```


- ����

```
//printf���
int main(void)	//����intֵ��main������void��()����ʾû�д���Ĳ���
{
	int height;
	float weight;
	height = 175;
	weight = 75.6;
	printf("height=%d\nweight=%.2f\n",height,weight);
	system("pause");
	return 0;
}

//scanf_s("%d,%f",&height,&weight);
//scanf���̼��룺��dos���ڼ���ʱ�Ķ��źͣ�%d��%f֮��Ķ���Ҫһ��


int main(void)	//����intֵ��main������void��()����ʾû�д���Ĳ���
{
	long float area, r;
	long float PI = 3.14159;
	printf("type in radius\n");
	scanf_s("%lf", &r); 	//����뾶ֵ
	area = PI * r*r;
	printf("area=%lf\n", area);
	system("pause");
	return 0;
}

```



# ����
![3](pic/function.png)
![4](pic/function1.png)


```

float cube(float x);	//��������
int main(void)
	{
		float x;
		float rx;
		x = 2.1;
		rx = cube(x);	//��������
		printf("result is %f\n", rx);
		system("pause");
		return 0;
	}

float cube(float x)
	{
		float y;
		y = x * x*x;
		return y;	//����x^3��ֵ��cube(x)����
	}

```


- ����x��y��ֵ��

```
void swap(float *x, float *y);	//��������
float main(void)
{
	float x = 5.0;
	float y = 6.0;
	printf("x=%f,y=%f\n", x, y);
	swap(&x, &y);	//����ʱҪ��ָ��,&��ȡַ��,���ݵ���ʵ�α���x,y�ĵ�ַ
	printf("result is %f,%f", x, y);
	system("pause");
	return 0;
}

void swap(float *x, float *y)
{
	float temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
```


����:���x��y�������ֵ����ʵ��x,y������ֵ��
```

float swap(float x, float y);	//��������
int main()
{
	float x = 5;
	float y = 6;
	float z;
	printf("x=%f,y=%f\n", x, y);
	swap(x, y);
	printf("x=%f,y=%f\n", x,y);
	system("pause");
	return 0;
}

float swap(float x, float y)
{
	float temp;
	temp = x;
	x = y;
	y = temp;
	printf("%f,%f\n", x, y);	
	return 0;
}
```



![4](pic/��������.png)

- �����ȡԲ�����
```
void carea();
int main(void)	
{
	carea();
	carea();
	system("pause");
	return 0;
}
void carea()
{
	long float area, r;
	long float PI = 3.14159;
	printf("type in radius\n");
	scanf_s("%lf", &r); 	//����뾶ֵ
	area = PI * r*r;
	printf("area=%lf\n", area);
}

```


# if else switch
```
switch ()
{
case 1:
	...; break;
case 2
	...; break;
	...
[default:...;]  //�о�֮����������������ִ��default����
}
```

- eg:�û���������ѡ�������������ܳ�
```
//�ж�����ķ����ǲ��ǡ�a��
void main()
{
	char c;  //��*ctrl��������
	int treat;
	printf("\narea(a) or perimeter(p):\n ");
	//scanf("%s", c);
	c = getchar();
	treat = ('a' == c);
	printf("%d", treat);
	system("pause");
	return 0;
}



float area(float r);
float perimeter(float r);
void main()
{
	float r, result;
	char c;  //��*ctrl��������
	float treat;
	printf("\ninput radius and what u need\nradius=");
	scanf("%f", &r);
	getchar();	//��һ��getchar��Ȼ�ͳ�bug
	printf("\narea(a) or perimeter(p):\n ");
	//scanf("%s", c);
	c = getchar();
	treat = ('a' == c);	//������strcmp(a,b)==0�����ж�char�Ƿ���ͬ
	printf("now calculate %c\n", c);
	result = treat * area(r) + (1 - treat)*perimeter(r);
	printf("\n result=%f\n", result);
	system("pause");
	return 0;
}
float area(float r) {
	float y;
	y = 3.14*r*r;
	return y;
}
float perimeter(float r) {
	float y;
	y = 2 * 3.14 * r;
	return y;
}

```


# ȫ�ֱ������ֲ�����
```
int n = 10;	//ȫ�ֱ���
void func1() {
	int n = 20;
	printf("%d\n", n);
}
int func2(int n) {
	printf("%d\n", n);
}
void func3() {
	printf("%d\n", n);
}

void main() {
	int n = 30;
	func1();	//20
	func2(n);	//30
	func3();	//10����ȫ�ֱ���n

	{
		int n = 55;
		printf("55n=%d\n", n);	//55
	}
	printf("%d\n", n);	//30 ����main n
	system("pause");
}
```
# �Ĵ�������

```
static int a, b;
auto char c1, c2;
static int a[3] = { 1,2,3 };
extern int x, y;

```

δ�Ӵ洢����˵���ı�����Ϊ�Զ��洢���ͱ��� int i; <==> auto i;

register�Ĵ���������ֻ�оֲ��Զ���������ʽ�����ſ��Զ���Ϊ�Ĵ�������

extern�ⲿ������

static��̬�洢���ͱ��������Ƴ��������ڼ䶼���ڣ�b++֮�����µ��û���֮ǰ�Ļ����ϼ���

��֮ǰ��Щ����int a = 1; ÿ�ε���������ʧ������restore������Ķ���
```
void test() {
	auto a = 0.5;       //�����Զ��洢���ͱ���
	static int b = 3;   //���徲̬�洢���ͱ���
	a++;
	b++;
	printf("%d\n", a);
	printf("%d\n", b);
}

int main(){
	int i;
    /*��������test����*/
	test();
	test();
	test();
	system("pause");

}
```

# �⺯��

���˻��Լ�д�ĺ�������⣬���ϳɵ�ͷ�ļ��������˱�׼ͷ���ļ�������ʹ�ñ�׼�ⶨ����ĺ��������Ϊ����Ԫ�صı�ʶ����ͬʱ��׼ͷ�ж�������ļ�����������������������ļ����ض��塣

��׼���о����ڶ��庯����ͬʱ�����������뺯��ͬ���ĺꡣĬ�������ʹ�������ĺ�������ʹ�ú���ã����ú������߳���������ٶȡ����������С��ִ���ļ���С���ú���ָ���Ŀ����Ҫʹ��ʵ�ʵĺ�������ô����ʹ��sundef��ɾ���궨�壬ͬʱҲ����ͨ�����������ּ�Բ���ŵķ�ʽ�����κ���á�

```
#define max(x,y) printf("�����:"); \
  max(x,y)

/*���κ����*/
(max)(x, y);

#  undef max
max(x, y);
```

��the standard C library��c��׼�⣩��P.J.Plauger

![5](pic/c��׼��)

ͷ�ļ����ݣ�

1. �����Ŀ⺯��

stdio.h��stdlib.h����string.h�������⺯���������������е�c���Գ����ж��еĿ⺯�����������ֱ��ǣ�

stdio.h:��׼������������⣻

strlib.h : ��׼�ļ��⺯����

string.h : �ַ����������⣻

2. һЩ���õĿ⺯����

signal.h��float.h��math.h��time.h��ctype.h�⼸���⺯�����ʹ�õ�

signal.h��ʹ���ź�����ʱ����Ҫ���øÿ⺯���ĺ�����

float.h�������ʹ������⣻

math.h�������߼�һ�����ѧ�������⣻

time.h����ʱ����Ҫʹ�õĺ�������⣻

ctype.h��������ַ��������⣻


��׼ͷ��	|����	    |����
---|---|---
<assert.h>	|���	    |������assert�ꡣ�����ڳ�����ʹ�øú�����ϳ���״̬������ĳ�������Ƿ�Ϊ0�ȣ��������ʧ�ܣ�������ֹ��
<ctype.h>   | �ַ�����  | �����ж��ַ����ͼ���Сдת���ĺ�����
<errno.h>   | ������  | �ṩ��errno�������ڵ����ض��⺯������errno��ֵ���жϵ��ù������Ƿ��д�������
<float.h>   | ����������| �ṩ���������������Եĺꡣ
<limits.h>  | ��������  | �ṩ�������������ͺ��ַ��������Եĺꡣ
<locale.h>  | ���ػ�    | �ṩ��һЩ֧�ֳ�����ʻ��ĺ�����
<math.h>    | ��ѧ����  | �ṩ�˴���������ѧ����ĺ�����
<setjmp.h>  | �Ǳ�����ת| �ṩ�������ƹ������ĺ������ػ��ƣ���һ��������ת����һ�����ڻ�ĺ�����setjmp��longjmp������
<signal.h>  | �źŴ���  | �ṩ�˰����жϺ�����ʱ�������ڵ��쳣�����������
<stdarg.h>  | ��������  | �ṩ��֧�ֺ�������������Ĳ����Ĺ��ߡ�
<stddef.h>  | ���ö���  | �ṩ�˳��õ����ͺͺꡣ
<stdio.h>   | �������  | �ṩ�˴����������������
<stdlib.h>  | ����ʵ�ú��� | �ṩ�˴���ʵ�õĺ�����
<string.h>  | �ַ�������| �ṩ�˴����ַ�����������
<time.h>    | ���ں�ʱ��| �ṩ�˻�ȡ�����ݺʹ������ڵĺ�����


## stdlib.h

![](pic/��1.png)

- ����0~RAND_MAX֮��������

```
int main()
{
	int i, j;
	srand((int)time(NULL)); //ʹ�����µ�ʱ����Ϊ������ĳ�ʼ����
	for (i = 0; i < 10; i++)
	{
		j = 1 + (int)(10.0*rand() / (RAND_MAX + 1.0));
		printf("%d\n", j);
	}

	system("pause");
	return 0;
}
```


![](pic / ��2.png)

![](pic / ��3.png)

![](pic / ��4.png)

## ������Ϳ����

```
///��дabc.h:
#ifndef __STATIC_H__
#define __STATIC_H_
#include <stdlib.h>
int func1(int a, int b);
#endif
///��д.c�ļ�
#include "abc.h"
int func1(int a, int b)
{
	return a + b;
}

///���ɵ�lib�ļ����Է���.c��ǰ·�����ڵ���ʱ����·����#include "d:/xxx/xxx/xxx.h"
///��"����ҳ/��������/vc++Ŀ¼/����Ŀ¼"�����lib·��
///"������/����/����������"���lib

```


# ѭ�����
```
for (i=0������ʼ����i<100�����жϣ�i++����ѭ������) {	
	//ִ��100�δ�������ĳ���
	...;
}
```

```
while (1.0/i>1e-6) {	//iС��e�ĸ����η�ʱͣ��ѭ����ֻҪ���Ʊ��ʽΪtrue�ͻᷴ��ִ�д������ڵĴ���
	i += 2;
}
```

```
do {

} while ()	//��ִ��һ�����жϣ������ִ����һ�Σ��������������
```


continue; continue��break�е����ƣ���������continueֻ����ֹ����ѭ�������Ż�ִ�к����ѭ����break����ȫ��ֹѭ����
�������Ϊcontinue����������ѭ����ʣ�µ���䣬ִ����һ��ѭ����



