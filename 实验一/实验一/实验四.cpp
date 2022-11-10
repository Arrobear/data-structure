/*
��ʱһ�����ʽ�п��ܳ����������Ų�ƥ������Σ�
��дһ������(�򽫲ο�����β�������):
1���Ӽ�������һ�����ʽ�������������������
2��������Ľ��
ע���ٶ����ʽ�п��ܳ��ֵ������У�������{ }��������[]�Լ�Բ����()��
*/

#include<stdio.h>
#include<iostream>;
using namespace std;
#define MAX 25

//������ջ�Ĵ洢�ṹ
struct Node;
typedef struct Node* PNode;
struct Node
{
	char info;
	PNode link;
};

struct LinkStack
{
	PNode top;
};
typedef struct LinkStack* PLinkStack;

PLinkStack creatEmptyStack()  //����һ��������ջ
{
	PLinkStack plstack;
	plstack = (PLinkStack)malloc(sizeof(struct LinkStack));
	if (plstack != NULL)
	{
		plstack->top = NULL;
	}
	else
		printf("����ʧ�ܣ�\n");
	return plstack;
}

int isEmptyStack(PLinkStack plstack) //�ж�����ջ�Ƿ�Ϊ��
{
	return(plstack->top == NULL);
}

void push_link(PLinkStack plstack, char a)  //����Ԫ��
{
	PNode p;
	p = (PNode)malloc(sizeof(struct Node));
	if (p == NULL)
		printf("����ʧ�ܣ�\n");
	else
	{
		p->info = a;
		p->link = plstack->top;
		plstack->top = p;
	}
}

void pop_link(PLinkStack plstack) //����Ԫ��
{
	PNode p;
	p = plstack->top;
	plstack->top = p->link;
	free(p);
}

void Check(char str[], PLinkStack plstack)  //��Ҫ�б���
{
/*
�ȽϹ���
	1������Ԫ����ջ��Ԫ�����������ջ��Ԫ��
	2������Ԫ����ջ��Ԫ�ز�ͬ�����ջ�У��򱨴�
	3���ж�ջ�Ƿ�Ϊ�գ���Ϊ�գ��򷵻ر��ʽ��ȷ�����򱨴�
*/
	int M=MAX;
	for (int i = 0; i < M; i++)
	{
		switch (str[i])
		{
		case'{':push_link(plstack, str[i]); break;

		case'[':push_link(plstack, str[i]); break;

		case'(':push_link(plstack, str[i]); break;

		case')':
		{
			if (plstack->top->info == '(')
			{
				pop_link(plstack); break;
			}
			else
			{
				printf("����ʹ�ã�()\n"); return;
			}
		}
		case']':
		{
			if (plstack->top->info == '[')
			{
				pop_link(plstack); break;
			}
			else
			{
				printf("����ʹ�ã�[]\n"); return;
			}
		}
		case'}':
		{
			if (plstack->top->info == '{')
			{
				pop_link(plstack); break;
			}
			else
			{
				printf("����ʹ�ã�{}\n"); return;
			}
		}
		default:
			break;
		}
	}
	if (isEmptyStack(plstack))
	{
		printf("���ʽ����ʹ����ȷ����\n");
	}
	else
	{
		printf("���ʽ����ʹ�ô��󣡣�\n");
	}
	return;
}

int main()
{
	int p = 0;
	char str[MAX];
	//����һ�����ʽ
	do
	{
		printf("������һ�����ʽ��\n");
	
		cin>>str;

		PLinkStack plstack = creatEmptyStack();

		Check(str, plstack);

		printf("����������г���������1���˳�����������0��\n");
		scanf("%d", &p);
	} while (p);
	system("pause");
	return 0;
}