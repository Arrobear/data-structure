/*ʵ�ֶ������Ĺ����������*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MAXNUM 50


//����������ݽṹ
struct SeqQueue
{
	int max;
	int f;
	int r;
	int* q;
};
typedef struct SeqQueue* PSeqQueue;

//������˳���ʾ����ȫ������
struct SeqBinTree
{
	int max = MAXNUM;   //�������н���������
	int n;  //�����������н����
	int* nodelist;
};
typedef struct SeqBinTree* PSeqBinTree;

//����������
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
		printf("�洢����ʧ�ܣ���");
		return NULL;
	}
}

//�����±�Ϊp�Ľ������ӽڵ���±�
int leftChild(PSeqBinTree t, int p)
{
	if (p < 0 || p >= t->n)
	{
		return -1;
	}
	return 2 * p + 1;
}

//�����±�Ϊp�Ľ������ӽڵ���±�
int rightChild(PSeqBinTree t, int p)
{
	if (p < 0 || p >= t->n)
	{
		return -1;
	}
	return 2 * (p + 1);
}

//�����ն���
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
		printf("�洢����ʧ�ܣ���");
		return NULL;
	}
}

//�ж϶����Ƿ�Ϊ��
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

//�ڶ���β������һ��Ԫ��
void enQueue(PSeqQueue paqu, int x)
{
	if ((paqu->r + 1) % paqu->max == paqu->f)
	{
		printf("������������");
	}
	else
	{
		paqu->q[paqu->r] = x;
		paqu->r = (paqu->r + 1) % paqu->max;
	}
}

//��������
void deQueue(PSeqQueue paqu)
{
	if (paqu->f == paqu->r)
	{
		printf("�ն��У�\n");
	}
	else
	{
		paqu->f = (paqu->f + 1) % paqu->max;
	}
}

//ȡ���е�ͷԪ��
int frontQueue(PSeqQueue paqu)
{
	if (paqu->f == paqu->r)
	{
		printf("�ն��У�\n");
	}
	else
	{
		return(paqu->q[paqu->f]);
	}
}

//��ʼ��һ����
void Ogrin(PSeqBinTree t)
{
	int p;
	printf("������������Ľ�������\n");
	cin >> p;
	t->n = p;
	for (int i = 0; i < p; i++)
	{
		int x;
		cin >> x;
		t->nodelist[i] = x;
	}
}


//����ڵ��±�
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

//������������ζ�����
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
		c = frontQueue(q);   //ȡ�������ж�������ͷ���
		printf("%d  ", c);
		deQueue(q);

		i = Check(t, c);

		left = leftChild(t, i);    //ȡ�������ж�������ͷ�����������ڶ����е��±�
		if (left != -1)
		{
			enQueue(q, t->nodelist[left]);
		}

		right = rightChild(t, i);    //ȡ�������ж�������ͷ�����������ڶ����е��±�
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