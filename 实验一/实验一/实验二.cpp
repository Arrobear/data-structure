//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define MAXUNM 54
//struct Element  //����˳���Ԫ������
//{
//	char color;  //��ɫ
//	int number;  //����
//};
//
//struct SeqList  //����˳���
//{
//	int MAXNUM;
//	int n;
//	Element *element;
//};
//
//typedef struct SeqList* PSeqList;  //����SeqList���͵�ָ�����
//
//PSeqList CreatNull(int m)  //������˳���
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
//	printf("�洢����ʧ�ܣ���\n");
//	return NULL;
//}
//
//Element draw(PSeqList palist)  //���ƶ��г���
//{
//	srand((unsigned int)time(NULL));
//	int ret = rand() % 54;
//	Element d = palist->element[ret];
//	return d;
//}
//
//int Check(Element n, PSeqList palist)  //�����е��ƱȽ��Ƿ�����ͬ���ֵ��ƣ���С����Ϊ������ͬ��
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
//int Locate(PSeqList palist, Element n)  //��λ����������Ԫ����ͬ������λ�ò������±�
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
//void Delete(PSeqList palist, int v)  //ɾ���±�Ϊv��Ԫ��
//{
//	int q;
//	for (q = v; q < palist->n - 1; q++)
//	{
//		palist->element[q] = palist->element[q + 1];
//	}
//	palist->n = palist->n - 1;
//}
//
//int MLocate(PSeqList palist, Element n)  //��λ���б�n���ִ���Ƶ��±꣬��û�б�n���ִ�����򷵻�-1
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
//void Whatch(PSeqList palist)  //�鿴������ڵ�����
//{
//	printf("�����ڹ���%d���ƣ��ֱ�Ϊ��",palist->n);
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
//	printf("��ӭ��\n");
//	PSeqList Deck = CreatNull(54);  //�����ƶ�
//	int i;
//	int j;
//	char colo[] = { 'b','r','m','f' }; //��ɫ��b�����ң� r�����ң� m��÷���� f������
//	for (i = 1; i < 5; i++)  //¼�����С�����52����
//	{
//		for (j = 0; j < 13; j++)
//		{
//			Deck->element[j + 13 * (i - 1)] = { colo[i - 1],j + 1 };
//		}
//	}
//	Deck->element[52] = { 'r',14 }; //����
//	Deck->element[53] = { 'b',14 }; //С��
//
//	PSeqList Card = CreatNull(14);  //�������
//
//	int p = 0;  //�����ж��Ƿ������Ϸ�Ĳ���
//	do
//	{
//		Whatch(Card);
//		printf("����������1��0������1��ʼ���ƣ�����0���˳�����:\n");
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