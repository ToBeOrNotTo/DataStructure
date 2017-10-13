#include<iostream>

using namespace std;

#define TRUE 1

#define FALSE 0

#define OK 1

#define ERROR 0

#define OVERFLOW -2

typedef int Status;

typedef int ElemType;

#define LIST_INIT_SIZE 100

#define LISTINCREMENT 10

typedef struct { //�ṹ��

	ElemType *elem;

	int length;

	int listsize;

}SqList;

SqList Lx;

Status InitList_Sq(SqList &L) //����ռ�

{
	L.elem = new ElemType[LIST_INIT_SIZE];

	if (!L.elem)exit(OVERFLOW);

	L.length = 0;

	L.listsize = LIST_INIT_SIZE;

	return OK;

}

Status ListInsert(SqList &L, int i, ElemType e) //������Ԫ��

{
	int *q, *p; ElemType *newbase;

	if (i<1 || i>L.length + 1) return ERROR;

	if (L.length >= L.listsize)

	{
		newbase = new ElemType[L.listsize + LISTINCREMENT];

		if (!newbase) exit(OVERFLOW);

		L.elem = newbase;

		L.listsize += LISTINCREMENT;

	}

	q = &(L.elem[i - 1]);

	for (p = &(L.elem[L.length - 1]); p >= q; --p)

		*(p + 1) = *p;

	*q = e;

	++L.length;

	return OK;

}

Status Listlength(SqList L) //����

{
	int *p = L.elem; //�ж����α��Ƿ����

	while (p)

	{
		return (L.length);
	}

}

void show(SqList L, int i) //��ʾ

{
	int j; ElemType k;

	cout << "˳�����ʾ����:" << endl;

	for (j = 0; j<i - 1; j++)

	{
		k = L.elem[j];

		cout << k << "->";
	}

	if (j == i - 1 && i>0)

	{
		k = L.elem[j]; cout << k;
	}

	cout << endl;

}

void create(SqList &L, int n) //����Ԫ��

{
	int e;

	for (int i = 0; i<n; i++)

	{
		cin >> e;

		L.elem[i] = e;

		L.length = i + 1;
	}

}

Status ListDelete_Sq(SqList &L, int i, ElemType &e) //ɾ��

{
	ElemType *p, *q;

	if (i<1 || i>L.length) return ERROR;

	p = &(L.elem[i - 1]);

	e = *p;

	q = L.elem + L.length - 1;

	for (++p; p <= q; ++p) *(p - 1) = *p;

	--L.length;

	return OK;

}

Status Listxiugei(SqList &L, int i, ElemType &e) //�޸�

{
	if (i<1 || i>L.length)

		return ERROR;

	else

	{
		L.elem[i - 1] = e;

		return OK;
	}

}

void shuru(SqList &L1) //˳���Ĵ���

{
	int a;

	InitList_Sq(L1);

	cout << "������˳���ĳ��ȣ�";

	cin >> a;

	cout << "������˳����Ԫ��(��" << a << "��)" << endl;

	create(L1, a);

	show(L1, a);

}

void zengjia(SqList &L1) //����Ԫ�ص�˳�����

{
	int a; int j; ElemType e1;

	a = L1.length;

	cout << "��ѡ����Ҫ����Ԫ�ص�λ��:";

	cin >> j;

	while (j<0 || j>Listlength(L1))

	{
		cout << "������������������" << endl;

		cout << "��ѡ����Ҫ����Ԫ�ص�λ��:";

		cin >> j;
	}

	cout << "Ҫ���ӵ�Ԫ��:";

	cin >> e1;

	ListInsert(L1, j, e1);

	cout << "�޸ĺ��˳�������:" << endl;

	show(L1, a + 1);

}

void shanchu(SqList &L1) //ɾ��˳������Ԫ��

{
	int a;

	int j; ElemType e1;

	a = L1.length;

	cout << "��ѡ����Ҫɾ��Ԫ�ص�λ��:";

	cin >> j;

	while (j<0 || j>Listlength(L1))

	{
		cout << "������������������" << endl;

		cout << "��ѡ����Ҫɾ��Ԫ�ص�λ��:";

			  cin >> j;
	}

	ListDelete_Sq(L1, j, e1);

	cout << "�޸ĺ��˳�������:" << endl;

	show(L1, a - 1);

}

void xiugai(SqList &L1) //�޸ĵ�i��λ�õ�Ԫ��

{
	int a;

	int j; ElemType e1;

	a = L1.length;

	cout << "��ѡ����Ҫ�޸�Ԫ�ص�λ��:";

	cin >> j;

	while (j<0 || j>Listlength(L1))

	{
		cout << "������������������" << endl;

		cout << "��ѡ����Ҫ�޸�Ԫ�ص�λ��:";

		cin >> j;
	}

	cout << "Ҫ�޸ĳɵ�Ԫ��:";

	cin >> e1;

	Listxiugei(L1, j, e1);

	cout << "�޸ĺ��˳�������:" << endl;

	show(L1, a);

}

void main() //���˵�

{
	int choice;

	for (;;)

	{
		cout << " ˳���Ļ�������" << endl;

		cout << " 1.˳���Ĵ���" << endl;

		cout << " 2.˳���ĳ���" << endl;

		cout << " 3.����Ԫ�ص�˳�����" << endl;

		cout << " 4.ɾ��˳������Ԫ��" << endl;

		cout << " 5.�޸ĵ�i��λ�õ�Ԫ��" << endl;

		cout << " 6.�˳�ϵͳ" << endl;

		cout << "��ѡ��";

		cin >> choice;

		switch (choice)

		{
		case 1: shuru(Lx); break;

		case 2: cout << "˳���ĳ���:" << Listlength(Lx) << endl; break;

		case 3: zengjia(Lx); break;

		case 4: shanchu(Lx); break;

		case 5: xiugai(Lx); break;

		case 6: cout << "�˳�ϵͳ!" << endl; exit(0); break;

		default: cout << "��������������ѡ��" << endl; break;
		}

	}

}