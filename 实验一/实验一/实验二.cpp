//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define MAXUNM 54
//struct Element  //定义顺序表元素类型
//{
//	char color;  //花色
//	int number;  //数字
//};
//
//struct SeqList  //定义顺序表
//{
//	int MAXNUM;
//	int n;
//	Element *element;
//};
//
//typedef struct SeqList* PSeqList;  //定义SeqList类型的指针变量
//
//PSeqList CreatNull(int m)  //创建空顺序表
//{
//	PSeqList palist=(PSeqList)malloc(sizeof(struct SeqList));
//	if (palist != NULL)
//	{
//		palist->element = (Element*)malloc(sizeof(Element) * m);
//		if (palist->element)
//		{
//			palist->MAXNUM = m;
//			palist->n = 0;
//			return palist;
//		}
//		else free(palist);
//	}
//	printf("存储分配失败！！\n");
//	return NULL;
//}
//
//Element draw(PSeqList palist)  //从牌堆中抽牌
//{
//	srand((unsigned int)time(NULL));
//	int ret = rand() % 54;
//	Element d = palist->element[ret];
//	return d;
//}
//
//int Check(Element n, PSeqList palist)  //与手中的牌比较是否有相同数字的牌（大小王视为数字相同）
//{
//	int i = 0;
//	for (i = 0; i < 14; i++)
//	{
//		if (palist->element[i].number == n.number)
//		{
//			return 1; 
//		}
//	}
//	return 0;
//}
//
//int Locate(PSeqList palist, Element n)  //定位手牌中与新元素相同的手牌位置并返回下标
//{
//	int q;
//	for (q = 0; q < palist->n; q++)
//	{
//		if (palist->element[q].number == n.number)
//		{
//			return q;
//		}
//	}
//	return -1;
//}
//
//void Delete(PSeqList palist, int v)  //删除下标为v的元素
//{
//	int q;
//	for (q = v; q < palist->n - 1; q++)
//	{
//		palist->element[q] = palist->element[q + 1];
//	}
//	palist->n = palist->n - 1;
//}
//
//int MLocate(PSeqList palist, Element n)  //定位手中比n数字大的牌的下标，若没有比n数字大的牌则返回-1
//{
//	int q;
//	for (q = 0; q < palist->n; q++)
//	{
//		if (palist->element[q].number > n.number)
//			return q;
//	}
//	return -1;
//}
//
//void Insert(PSeqList palist, int v,Element n)
//{
//	int q;
//	if (v == -1)
//	{
//		palist->element[palist->n] = n;
//		palist->n = palist->n + 1;
//	}
//	else
//	{
//		for (q = palist->n - 1; q >= v; q--)
//		{
//			palist->element[q + 1] = palist->element[q];
//			palist->element[v] = n;
//			palist->n = palist->n + 1;
//		}
//	}
//}
//
//void Whatch(PSeqList palist)  //查看玩家现在的手牌
//{
//	printf("您现在共有%d张牌，分别为：",palist->n);
//	int q;
//	for (q = 0;q<palist->n; q++)
//	{
//		printf("%c %d	",palist->element[q].color,palist->element[q].number);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	printf("欢迎词\n");
//	PSeqList Deck = CreatNull(54);  //创建牌堆
//	int i;
//	int j;
//	char colo[] = { 'b','r','m','f' }; //花色：b：黑桃； r：红桃； m：梅花； f：方块
//	for (i = 1; i < 5; i++)  //录入除大小王外的52张牌
//	{
//		for (j = 0; j < 13; j++)
//		{
//			Deck->element[j + 13 * (i - 1)] = { colo[i - 1],j + 1 };
//		}
//	}
//	Deck->element[52] = { 'r',14 }; //大王
//	Deck->element[53] = { 'b',14 }; //小王
//
//	PSeqList Card = CreatNull(14);  //玩家手牌
//
//	int p = 0;  //用来判断是否继续游戏的参数
//	do
//	{
//		Whatch(Card);
//		printf("请输入数字1或0，输入1开始抽牌，输入0则退出程序:\n");
//		scanf("%d", &p);
//		if (p)
//		{
//			Element n = draw(Deck);
//			if (Check(n, Card))
//			{
//				int v = Locate(Card, n);
//				Delete(Card,v);
//			}
//			else
//			{
//				int u = MLocate(Card, n);
//				Insert(Card, u, n);
//			}
//		}
//		else
//		{
//			break;
//		}
//	} while (p);
//	return 0;
//}