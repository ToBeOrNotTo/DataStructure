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

typedef struct { //结构体

	ElemType *elem;

	int length;

	int listsize;

}SqList;

SqList Lx;

Status InitList_Sq(SqList &L) //分配空间

{
	L.elem = new ElemType[LIST_INIT_SIZE];

	if (!L.elem)exit(OVERFLOW);

	L.length = 0;

	L.listsize = LIST_INIT_SIZE;

	return OK;

}

Status ListInsert(SqList &L, int i, ElemType e) //增加新元素

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

Status Listlength(SqList L) //长度

{
	int *p = L.elem; //判断线形表是否存在

	while (p)

	{
		return (L.length);
	}

}

void show(SqList L, int i) //显示

{
	int j; ElemType k;

	cout << "顺序表显示如下:" << endl;

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

void create(SqList &L, int n) //输入元素

{
	int e;

	for (int i = 0; i<n; i++)

	{
		cin >> e;

		L.elem[i] = e;

		L.length = i + 1;
	}

}

Status ListDelete_Sq(SqList &L, int i, ElemType &e) //删除

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

Status Listxiugei(SqList &L, int i, ElemType &e) //修改

{
	if (i<1 || i>L.length)

		return ERROR;

	else

	{
		L.elem[i - 1] = e;

		return OK;
	}

}

void shuru(SqList &L1) //顺序表的创建

{
	int a;

	InitList_Sq(L1);

	cout << "请输入顺序表的长度：";

	cin >> a;

	cout << "请输入顺序表的元素(共" << a << "个)" << endl;

	create(L1, a);

	show(L1, a);

}

void zengjia(SqList &L1) //增加元素到顺序表里

{
	int a; int j; ElemType e1;

	a = L1.length;

	cout << "请选择所要增加元素的位置:";

	cin >> j;

	while (j<0 || j>Listlength(L1))

	{
		cout << "输入有误，请重新输入" << endl;

		cout << "请选择所要增加元素的位置:";

		cin >> j;
	}

	cout << "要增加的元素:";

	cin >> e1;

	ListInsert(L1, j, e1);

	cout << "修改后的顺序表数据:" << endl;

	show(L1, a + 1);

}

void shanchu(SqList &L1) //删除顺序表里的元素

{
	int a;

	int j; ElemType e1;

	a = L1.length;

	cout << "请选择所要删除元素的位置:";

	cin >> j;

	while (j<0 || j>Listlength(L1))

	{
		cout << "输入有误，请重新输入" << endl;

		cout << "请选择所要删除元素的位置:";

			  cin >> j;
	}

	ListDelete_Sq(L1, j, e1);

	cout << "修改后的顺序表数据:" << endl;

	show(L1, a - 1);

}

void xiugai(SqList &L1) //修改第i个位置的元素

{
	int a;

	int j; ElemType e1;

	a = L1.length;

	cout << "请选择所要修改元素的位置:";

	cin >> j;

	while (j<0 || j>Listlength(L1))

	{
		cout << "输入有误，请重新输入" << endl;

		cout << "请选择所要修改元素的位置:";

		cin >> j;
	}

	cout << "要修改成的元素:";

	cin >> e1;

	Listxiugei(L1, j, e1);

	cout << "修改后的顺序表数据:" << endl;

	show(L1, a);

}

void main() //主菜单

{
	int choice;

	for (;;)

	{
		cout << " 顺序表的基本操作" << endl;

		cout << " 1.顺序表的创建" << endl;

		cout << " 2.顺序表的长度" << endl;

		cout << " 3.增加元素到顺序表里" << endl;

		cout << " 4.删除顺序表里的元素" << endl;

		cout << " 5.修改第i个位置的元素" << endl;

		cout << " 6.退出系统" << endl;

		cout << "请选择：";

		cin >> choice;

		switch (choice)

		{
		case 1: shuru(Lx); break;

		case 2: cout << "顺序表的长度:" << Listlength(Lx) << endl; break;

		case 3: zengjia(Lx); break;

		case 4: shanchu(Lx); break;

		case 5: xiugai(Lx); break;

		case 6: cout << "退出系统!" << endl; exit(0); break;

		default: cout << "输入有误，请重新选择" << endl; break;
		}

	}

}