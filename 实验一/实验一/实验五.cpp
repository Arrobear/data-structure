/*实现二叉树的广度优先周游*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MAXNUM 50


//定义队列数据结构
struct SeqQueue
{
	int max;
	int f;
	int r;
	int* q;
};
typedef struct SeqQueue* PSeqQueue;

//定义用顺序表示的完全二叉树
struct SeqBinTree
{
	int max = MAXNUM;   //二叉树中结点的最大个数
	int n;  //二叉树中现有结点数
	int* nodelist;
};
typedef struct SeqBinTree* PSeqBinTree;

//创建二叉树
PSeqBinTree createEmptyBinTree()
{
	PSeqBinTree t = (PSeqBinTree)malloc(sizeof(struct SeqBinTree));
	if (t != NULL)
	{
		t->nodelist = (int*)malloc(sizeof(int) * MAXNUM);
		if (t->nodelist)
		{
			return t;
		}
		else
		{
			free(t);
		}
		printf("存储分配失败！！");
		return NULL;
	}
}

//返回下标为p的结点的左子节点的下标
int leftChild(PSeqBinTree t, int p)
{
	if (p < 0 || p >= t->n)
	{
		return -1;
	}
	return 2 * p + 1;
}

//返回下标为p的结点的右子节点的下标
int rightChild(PSeqBinTree t, int p)
{
	if (p < 0 || p >= t->n)
	{
		return -1;
	}
	return 2 * (p + 1);
}

//创建空队列
PSeqQueue createEmptyQueue(int n)
{
	PSeqQueue queue = (PSeqQueue)malloc(sizeof(struct SeqQueue));
	if (queue != NULL)
	{
		queue->q = (int*)malloc(sizeof(int) * n);
		if (queue->q)
		{
			queue->f = 0;
			queue->r = 0;
			int max = n;
			return queue;
		}
		else
		{
			free(queue);
		}
		printf("存储分配失败！！");
		return NULL;
	}
}

//判断队列是否为空
int isEmptyQueue(PSeqQueue paqu)  
{
	if (paqu->r == paqu->f)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//在队列尾部插入一个元素
void enQueue(PSeqQueue paqu, int x)
{
	if ((paqu->r + 1) % paqu->max == paqu->f)
	{
		printf("队列已满！！");
	}
	else
	{
		paqu->q[paqu->r] = x;
		paqu->r = (paqu->r + 1) % paqu->max;
	}
}

//出队运算
void deQueue(PSeqQueue paqu)
{
	if (paqu->f == paqu->r)
	{
		printf("空队列！\n");
	}
	else
	{
		paqu->f = (paqu->f + 1) % paqu->max;
	}
}

//取队列的头元素
int frontQueue(PSeqQueue paqu)
{
	if (paqu->f == paqu->r)
	{
		printf("空队列！\n");
	}
	else
	{
		return(paqu->q[paqu->f]);
	}
}

//初始化一颗树
void Ogrin(PSeqBinTree t)
{
	int p;
	printf("请输入二叉树的结点个数：\n");
	cin >> p;
	t->n = p;
	for (int i = 0; i < p; i++)
	{
		int x;
		cin >> x;
		t->nodelist[i] = x;
	}
}


//输出节点下标
int Check(PSeqBinTree t,int c)
{
	for (int i = 0; i < MAXNUM; i++)
	{
		if (c == t->nodelist[i])
		{
			return i;
		}
	}
}

//按广度优先周游二叉树
void levelOrder(PSeqBinTree t)
{
	int c, left,right;
	PSeqQueue q = createEmptyQueue(t->n);

	if (t == NULL)
	{
		return;
	}

	int i = 0;
	int count = 0;
	enQueue(q, t->nodelist[i]);

	while (!isEmptyQueue(q))
	{	
		c = frontQueue(q);   //取出队列中二叉树的头结点
		printf("%d  ", c);
		deQueue(q);

		i = Check(t, c);

		left = leftChild(t, i);    //取出队列中二叉树的头结点的左子树在队列中的下标
		if (left != -1)
		{
			enQueue(q, t->nodelist[left]);
		}

		right = rightChild(t, i);    //取出队列中二叉树的头结点的右子树在队列中的下标
		if (right != -1)
		{
			enQueue(q, t->nodelist[right]);
		}

		count++;
		if (count >= t->n)
		{
			break;
		}
	}
}

int main()
{
	PSeqBinTree t = createEmptyBinTree();
	Ogrin(t);
	levelOrder(t);
	return 0;
}