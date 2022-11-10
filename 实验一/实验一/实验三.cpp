//注：本程序使用了部分c++代码

#include<stdio.h>
#include<time.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

//定义元素结构
struct Info
{
	char color;
	int num;
};

//定义链表结构
typedef struct Node* PNode;  //定义结点指针类型
struct Node  //结点数据类型
{
	Info info;
	PNode link;
};
typedef struct Node* LinkList;  //单链表类型

LinkList CreatNull()//创建空链表
{
	LinkList llist = (LinkList)malloc(sizeof(struct Node));
	if (llist != NULL) llist->link = NULL;
	else printf("out of space!\n");

	return llist;
}

void Whatch(LinkList Card)  //打印玩家现有手牌
{
	printf("您现在的手牌有：");
	PNode p;
	if (Card->link == NULL)
	{
		printf(" \n");
	}
	p = Card->link;
	while (p!=NULL)
	{
		printf("%c %d  ", p->info.color, p->info.num);
		p = p->link;
	}
	printf("\n");
}

void WhatchD(LinkList Card)  //打印牌堆中所有的牌
{
	printf("所有的牌如下：\n");
	PNode p;
	if (Card->link == NULL)
	{
		printf(" \n");
	}
	p = Card->link;
	while (p != NULL)
	{
		printf("%c %d  ", p->info.color, p->info.num);
		p = p->link;
	}
	printf("\n");
}

Info Draw(LinkList Deck,int ret)  //随机从牌堆Deck中抽取一个结点
{

	PNode p;
	p = Deck->link;;
	if (ret == 0)
	{
		return p->info;
	}
	else
	{
		for (int i = 0; i < ret; i++)
		{
			p = p->link;
		}
		return p->info;
	}
}

PNode Check(LinkList Card, Info n)  //检查牌堆Card中是否有与n相同的数据
{
	PNode p;
	if (Card == NULL) return NULL;
	p = Card->link;
	while (p != NULL && p->info.num != n.num)
	{
		p = p->link;
	}
	return p;
}

PNode Locate(LinkList Card, Info n)  //返回Card中与n所含元素相同结点的存储位置
{
	PNode p;
	if (Card == NULL) return NULL;
	p = Card->link;
	while (p!=NULL&&p->info.num != n.num)
	{
		p = p->link;
	}
	return p;
}

int Delete(LinkList Card, Info x)  //删除Card中与n所含元素相同的结点
{
	PNode p, q;
	p = Card;
	if (p == NULL)
		return 0;
	while (p->link!=NULL&&p->link->info.num != x.num)
	{
		p = p->link;
	}
	if (p->link == NULL)
	{
		printf("Not exist!\n"); return 0;
	}
	else
	{
		q = p->link;
		p->link = q->link;
		free(q);
		return 1;
	}
}

PNode MLocate(LinkList Card, Info n)  //返回Card中比n所含元素次小结点的存储位置
{
	PNode p;
	PNode q;
	if (Card == NULL) return NULL;
	p = Card->link;
	q = Card;
	while (p != NULL && p->info.num < n.num)
	{
		p = p->link;
	}
	while (q != NULL && q->link != p) q = q->link;
	return q;
}

int Insert(LinkList Card,PNode p,Info x) //在位置p后插入元素
{
	PNode q = (PNode)malloc(sizeof(struct Node));
	if(q==NULL)
	{
		printf("out of space!!\n");
		return 0;
	}
	else 
	{
		q->info = x;
		q->link = p->link;
		p->link = q;
		return 1;
	}
}


void Initialize(LinkList &Deck)  //初始化牌堆
{
	char colo[] = { 'b','r','m','f' }; //花色：b：黑桃； r：红桃； m：梅花； f：方块
	Info arr[54];
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			arr[j + 13 * (i - 1)] = { colo[i - 1],j + 1 };
		}
	}
	arr[52] = { 'r',14 };
	arr[53] = { 'b',14 };
	PNode q = Deck;
	for (int i = 0; i < 54; i++)
	{
		Insert(Deck, q, arr[i]);
		q = q->link;
	}

}

int main()
{
	//欢迎词
	printf("欢迎词！！\n");
	LinkList Deck = CreatNull();  //创建牌堆链表
	PNode q = Deck;
	//初始化牌堆
	Initialize(Deck);
	WhatchD(Deck);
	LinkList Card = CreatNull();  //创建玩家手牌牌堆链表
	//开始游戏进程
	int p = 0;  //用来判断是否继续进行游戏的参数
	time_t t;
	do
	{
		Whatch(Card);  //展示玩家现有手牌
		printf("请输入数字1或0，输入1开始抽牌，输入0则退出程序:\n");
		cin >> p;
		if (p)
		{
			srand((unsigned)time(&t));
			int ret = rand() % 54;
			Info n = Draw(q,ret);  //随机从牌堆Deck中抽取一个结点
			cout << "您抽到的牌为：" << n.color << " " << n.num << " " << endl;
			
			PNode x = Check(Card, n);  //检查手牌中是否有相同的牌
			if (x!=NULL&&x->info.num==n.num)  //判断Card中是否有与n所含元素相同的结点
			{
				PNode v = Locate(Card, n);  //返回Card中与n所含元素相同的结点的存储位置
				Delete(Card,n);  //删除Card中与n所含元素相同的结点
			}
			else
			{
				PNode u = MLocate(Card, n);  //返回手牌中比抽到的牌次小的结点的存储位置
				Insert(Card, u, n);  //将抽到的牌插入手牌
			}
		}
		else
		{
			break;
		}
	} while (p);

	return 0;
}