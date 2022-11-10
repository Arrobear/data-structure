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
}//��������
Complex Add(Complex a1, Complex a2)
{
	Complex sum;
	sum.real = a1.real + a2.real;
	sum.image = a1.image + a2.image;
	return sum;
}//�ӷ�
Complex Sub(Complex a1, Complex a2)
{
	Complex dif;
	dif.real = a1.real - a2.real;
	dif.image = a1.image - a2.image;
	return dif;
}//����
Complex Mul(Complex a1, Complex a2)
{
	Complex pro;
	pro.real = a1.real * a2.real - a1.image * a2.image;
	pro.image = a1.real * a2.image + a1.image * a2.real;
	return pro;
}//�˷�
Complex Div(Complex a1, Complex a2)
{
	Complex pou;
	pou.real = (a1.real * a2.real + a1.image * a2.image) / (a2.real * a2.real - a2.image * a2.image);
	pou.image = (a1.image * a2.real - a1.real * a2.image) / (a2.real * a2.real - a2.image * a2.image);
	return pou;
}//����
void Cor(Complex a1, Complex a2)
{
	Complex c = Sub(a1, a2);
	if (c.real == 0 && c.image == 0)
	printf("����������ȣ�\n");
}
void Print(Complex C)
{
	printf("��ȷ�����������ǣ�%.2f+%.2fi\n",C.real,C.image);
}
int main()
{
	Complex a, b, sum, dif, pro, qou;
	float m, n;
	int i;
	char s;
	for(i=0;;i++)
	{
		printf("����������Ҫ���е���������(+,-,*,/��$)��(����$ʱΪ�Ƚ�����������С)\n");
		scanf("%c", &s);
		printf("����a+bi��ʽ������������");
		scanf("%f+%fi", &m, &n);
		a = InitComplex(m, n);
		printf("����c+di��ʽ������������");
		scanf("%f+%fi", &m, &n);
		b = InitComplex(m, n);
		switch (s)
		{
		case '+': sum = Add(a, b); Print(sum); break;
		case '-': dif = Sub(a, b); Print(dif); break;
		case '*': pro = Mul(a, b); Print(pro); break;
		case '/': qou = Div(a, b); Print(qou); break;
		case '$': Cor(a, b); break;
		default:printf("�������������룡");
		}
	} 
	return 0;
}