#include <stdio.h>
#include<stdlib.h>
typedef struct Complex
{
	float real;
	float image;
}Complex;
Complex InitComplex(float a, float b)
{
	Complex C;
	C.real = a;
	C.image = b;
	return C;
}//创建复数
Complex Add(Complex a1, Complex a2)
{
	Complex sum;
	sum.real = a1.real + a2.real;
	sum.image = a1.image + a2.image;
	return sum;
}//加法
Complex Sub(Complex a1, Complex a2)
{
	Complex dif;
	dif.real = a1.real - a2.real;
	dif.image = a1.image - a2.image;
	return dif;
}//减法
Complex Mul(Complex a1, Complex a2)
{
	Complex pro;
	pro.real = a1.real * a2.real - a1.image * a2.image;
	pro.image = a1.real * a2.image + a1.image * a2.real;
	return pro;
}//乘法
Complex Div(Complex a1, Complex a2)
{
	Complex pou;
	pou.real = (a1.real * a2.real + a1.image * a2.image) / (a2.real * a2.real - a2.image * a2.image);
	pou.image = (a1.image * a2.real - a1.real * a2.image) / (a2.real * a2.real - a2.image * a2.image);
	return pou;
}//除法
void Cor(Complex a1, Complex a2)
{
	Complex c = Sub(a1, a2);
	if (c.real == 0 && c.image == 0)
	printf("两个复数相等！\n");
}
void Print(Complex C)
{
	printf("正确！！！答案正是：%.2f+%.2fi\n",C.real,C.image);
}
int main()
{
	Complex a, b, sum, dif, pro, qou;
	float m, n;
	int i;
	char s;
	for(i=0;;i++)
	{
		printf("请输入您所要进行的四则运算(+,-,*,/，$)：(输入$时为比较两个复数大小)\n");
		scanf("%c", &s);
		printf("请以a+bi形式输入两个数：");
		scanf("%f+%fi", &m, &n);
		a = InitComplex(m, n);
		printf("请以c+di形式输入两个数：");
		scanf("%f+%fi", &m, &n);
		b = InitComplex(m, n);
		switch (s)
		{
		case '+': sum = Add(a, b); Print(sum); break;
		case '-': dif = Sub(a, b); Print(dif); break;
		case '*': pro = Mul(a, b); Print(pro); break;
		case '/': qou = Div(a, b); Print(qou); break;
		case '$': Cor(a, b); break;
		default:printf("有误，请重新输入！");
		}
	} 
	return 0;
}