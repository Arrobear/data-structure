/*
有时一个表达式中可能出现左右括号不匹配的情形，
编写一个程序(或将参考程序段补充完整):
1、从键盘输入一个表达式，检查左右括号配对情况
2、输出检查的结果
注：假定表达式中可能出现的括号有：花括号{ }、方括号[]以及圆括号()。
*/

#include<stdio.h>
#include<iostream>;
using namespace std;
#define MAX 25

//定义链栈的存储结构
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

PLinkStack creatEmptyStack()  //创建一个空链接栈
{
	PLinkStack plstack;
	plstack = (PLinkStack)malloc(sizeof(struct LinkStack));
	if (plstack != NULL)
	{
		plstack->top = NULL;
	}
	else
		printf("创建失败！\n");
	return plstack;
}

int isEmptyStack(PLinkStack plstack) //判断链接栈是否为空
{
	return(plstack->top == NULL);
}

void push_link(PLinkStack plstack, char a)  //插入元素
{
	PNode p;
	p = (PNode)malloc(sizeof(struct Node));
	if (p == NULL)
		printf("插入失败！\n");
	else
	{
		p->info = a;
		p->link = plstack->top;
		plstack->top = p;
	}
}

void pop_link(PLinkStack plstack) //弹出元素
{
	PNode p;
	p = plstack->top;
	plstack->top = p->link;
	free(p);
}

void Check(char str[], PLinkStack plstack)  //主要判别函数
{
/*
比较规则：
	1、若新元素与栈顶元素配对则消除栈顶元素
	2、若新元素与栈顶元素不同则存入栈中，或报错
	3、判断栈是否为空，若为空，则返回表达式正确，否则报错
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
				printf("错误使用：()\n"); return;
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
				printf("错误使用：[]\n"); return;
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
				printf("错误使用：{}\n"); return;
			}
		}
		default:
			break;
		}
	}
	if (isEmptyStack(plstack))
	{
		printf("表达式括号使用正确！！\n");
	}
	else
	{
		printf("表达式括号使用错误！！\n");
	}
	return;
}

int main()
{
	int p = 0;
	char str[MAX];
	//输入一个表达式
	do
	{
		printf("请输入一个表达式：\n");
	
		cin>>str;

		PLinkStack plstack = creatEmptyStack();

		Check(str, plstack);

		printf("若想继续运行程序请输入1，退出程序请输入0：\n");
		scanf("%d", &p);
	} while (p);
	system("pause");
	return 0;
}