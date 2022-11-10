//ע��������ʹ���˲���c++����

#include<stdio.h>
#include<time.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

//����Ԫ�ؽṹ
struct Info
{
	char color;
	int num;
};

//��������ṹ
typedef struct Node* PNode;  //������ָ������
struct Node  //�����������
{
	Info info;
	PNode link;
};
typedef struct Node* LinkList;  //����������

LinkList CreatNull()//����������
{
	LinkList llist = (LinkList)malloc(sizeof(struct Node));
	if (llist != NULL) llist->link = NULL;
	else printf("out of space!\n");

	return llist;
}

void Whatch(LinkList Card)  //��ӡ�����������
{
	printf("�����ڵ������У�");
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

void WhatchD(LinkList Card)  //��ӡ�ƶ������е���
{
	printf("���е������£�\n");
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

Info Draw(LinkList Deck,int ret)  //������ƶ�Deck�г�ȡһ�����
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

PNode Check(LinkList Card, Info n)  //����ƶ�Card���Ƿ�����n��ͬ������
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

PNode Locate(LinkList Card, Info n)  //����Card����n����Ԫ����ͬ���Ĵ洢λ��
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

int Delete(LinkList Card, Info x)  //ɾ��Card����n����Ԫ����ͬ�Ľ��
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

PNode MLocate(LinkList Card, Info n)  //����Card�б�n����Ԫ�ش�С���Ĵ洢λ��
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

int Insert(LinkList Card,PNode p,Info x) //��λ��p�����Ԫ��
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


void Initialize(LinkList &Deck)  //��ʼ���ƶ�
{
	char colo[] = { 'b','r','m','f' }; //��ɫ��b�����ң� r�����ң� m��÷���� f������
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
	//��ӭ��
	printf("��ӭ�ʣ���\n");
	LinkList Deck = CreatNull();  //�����ƶ�����
	PNode q = Deck;
	//��ʼ���ƶ�
	Initialize(Deck);
	WhatchD(Deck);
	LinkList Card = CreatNull();  //������������ƶ�����
	//��ʼ��Ϸ����
	int p = 0;  //�����ж��Ƿ����������Ϸ�Ĳ���
	time_t t;
	do
	{
		Whatch(Card);  //չʾ�����������
		printf("����������1��0������1��ʼ���ƣ�����0���˳�����:\n");
		cin >> p;
		if (p)
		{
			srand((unsigned)time(&t));
			int ret = rand() % 54;
			Info n = Draw(q,ret);  //������ƶ�Deck�г�ȡһ�����
			cout << "���鵽����Ϊ��" << n.color << " " << n.num << " " << endl;
			
			PNode x = Check(Card, n);  //����������Ƿ�����ͬ����
			if (x!=NULL&&x->info.num==n.num)  //�ж�Card���Ƿ�����n����Ԫ����ͬ�Ľ��
			{
				PNode v = Locate(Card, n);  //����Card����n����Ԫ����ͬ�Ľ��Ĵ洢λ��
				Delete(Card,n);  //ɾ��Card����n����Ԫ����ͬ�Ľ��
			}
			else
			{
				PNode u = MLocate(Card, n);  //���������бȳ鵽���ƴ�С�Ľ��Ĵ洢λ��
				Insert(Card, u, n);  //���鵽���Ʋ�������
			}
		}
		else
		{
			break;
		}
	} while (p);

	return 0;
}