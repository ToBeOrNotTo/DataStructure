#include<stdio.h>

#include<stdlib.h>

#define ERROR 0

#define OK 1

#define TRUE 1

#define FALSE 0

#define OVERFLOW 0

typedef int Status;

typedef int ElemType;

typedef struct LNode{

	ElemType data;

	int len;

	struct LNode *next;

}LNode, *LinkList;

Status CreateList_L(LinkList *L, int n)

{
	LinkList p;

	int LISTLEN = 0;

	int i;

	*L = (LinkList)malloc(sizeof(LinkList));

	if (!(*L)) exit(OVERFLOW);

	(*L)->len = 0;

	(*L)->next = NULL;

	for (i = n; i>0; --i)

	{

		p = (LinkList)malloc(sizeof(LNode));

		printf("请输入元素的值(前插):\n");

		scanf("%d", &p->data);

		p->next = (*L)->next; //插入到表头

		(*L)->next = p;

		(*L)->len++;

		LISTLEN++;

	}

}

int ListLength(LinkList *L)

{

	return (*L)->len;

}

Status ListInsert(LinkList *L, int i, ElemType e)

{
	LinkList p, s; int j;

	if (i<1 || i>ListLength(L) + 1)

	{

		printf("插入失败! 访问越界\n");

		return ERROR;

	}

	else

	{
		p = *L;

		for (j = 0; j<i - 1; j++) //for循环结束后p将指向第i-1个元素，即应该在p后插入元素e

			p = p->next;

		if (!p || j>i - 1)return ERROR;

		s = (LinkList)malloc(sizeof(LNode));

		s->data = e;

		s->next = p->next;

		p->next = s;

		(*L)->len++;

		return TRUE;

	}

}

Status ListDelete(LinkList * L, int i, ElemType *e)

{
	LinkList q, p; int j;

	if (i<1 || i>ListLength(L))

	{

		printf("删除失败! 访问越界\n");

		return ERROR;

	}

	else

	{

		p = *L;

		for (j = 0; j < i - 1; j++) //for循环后指针p将指向要删除的元素的前驱结点

			p = p->next;

		if (!p->next || j>i - 1)return ERROR;

		q = p->next;

		p->next = q->next;

		*e = q->data;

		(*L)->len--;

		free(q);

		return TRUE;

	}

}

Status GetElem(LinkList L, int i)

{

	if (i<1 || i>ListLength(&L))

	{

		printf("取值非法! 链表中无此位序元素\n");

		return ERROR;

	}

	else

	{

		LinkList p = L;

		int j;

		for (j = 0; j<i; j++)

			p = p->next;

		return p->data;

	}

}

Status EmptyList_L(LinkList L)

{

	if (L->next == NULL)

		return TRUE;

	return ERROR;

}

int LocateElem(LinkList L, ElemType e)

{

	int i = 0;

	LinkList p = L;

	while (p->next && p->next->data != e)

	{

		p = p->next;

		i++;

	}

	if (p->next == NULL)

	{

		printf("在链表中找不到元素\n ");

		return ERROR;

	}

	return (i + 1);

}

Status PriorElem(LinkList L, ElemType curr_e, ElemType *e)

{

	LinkList p = L;

	while (p->next && curr_e != p->next->data)

		p = p->next;

	if (p->next == NULL)

	{

		printf("在链表中找不到元素,无法求其前驱元素!\n");

		return ERROR;

	}

	if (p == L)

	{

		printf("元素 curr_e 是链表中的首元元素,无前驱\n");

		return ERROR;

	}

	*e = p->data;

	return OK;

}

Status NextElem(LinkList L, ElemType curr_e, ElemType *e)

{

	LinkList p = L->next;

	while (p && p->data != curr_e)

		p = p->next;

	if (p == L->next)

	{

		if (!p)

		{

			printf("链表是一个空表,无法做取后继操作\n!");

			return ERROR;

		}

	}

	if (p == NULL)

	{

		printf("\n在链表中未能找到元素: ");

		return ERROR;

	}

	if (p->next == NULL)

	{

		printf("\n元素 curr_e 是链表的尾元元素,无法求其后继!\n");

		return ERROR;

	}

	*e = p->next->data;

	return OK;

}

Status ListTraverse(LinkList L)

{
	int LISTLEN;

	LinkList p = L->next;
	LISTLEN = ListLength(&L);

	if (LISTLEN == 0)

	{

		printf("\n链表中除头结点以外的所有内容已被释放,是一个空表!\n");

		printf("\n遍历失败!\n");

		return ERROR;

	}

	if (LISTLEN == -1)

	{

		printf("\n所有内容已被释放,链表已被销毁!\n");

		printf("\n遍历失败!\n");

		return ERROR;

	}

	while (p)

	{

		printf("%4d", p->data);

		p = p->next;

	}

	printf("\n遍历成功!\n");

	return TRUE;

}

Status ClearList_L(LinkList *L)

{

	int LISTLEN;

	LinkList p = *L;

	while (p->next)

	{

		LinkList m = p->next;

		free(p);

		p = m;

	}

	(*L)->next = NULL;

	LISTLEN = 0;

	return OK;

}

void DestoryList_L(LinkList *L)

{
	int LISTLEN;

	LinkList p = *L;

	while (p->next)

	{

		LinkList m = p->next;

		free(p);

		p = m;

	}

	LISTLEN = -1;

}

void main()

{

	LinkList L;

	ElemType e;

	ElemType curr_e;

	int i, select;

	int status; //返回函数执行状态

	printf("请输入所需创建的元素个数:\n");

	scanf("%d", &i);

	//创建单链表

	CreateList_L(&L, i);

	//遍历

	ListTraverse(L);

	do{

		printf("1:链表的长度\n");

		printf("2:插入元素\n");

		printf("3:删除元素\n");

		printf("4:取链表中第i个元素\n");

		printf("5:判断链表是否为空\n");

		printf("6:定位查找\n");

		printf("7:返回数据元素的前驱\n");

		printf("8:返回数据元素的后继\n");

		printf("9:置空链表\n");

		printf("0:结束\n");

		scanf("%d", &select);

		switch (select){

			//返回链表表长

		case 1:

			ListLength(&L);

			printf("\n单链表的长度是%d\n", L->len); break;

			//链表的插入操作

		case 2:

			printf("\n请输入需要插入元素的位置i=");

			scanf("%d", &i);

			printf("\n请输入插入的元素值e=");

			scanf("%d", &e);

			status = ListInsert(&L, i, e);

			if (status)

				printf("\n链表元素插入成功!\n");

			else

				printf("\n链表元素插入失败!\n");

			status = ListTraverse(L); break;

			//单链表的删除操作

		case 3:

			printf("请输入需要删除的元素的位置i=");

			scanf("%d", &i);

			status = ListDelete(&L, i, &e);

			if (status)

			{

				printf("\n删除成功!");

				printf("\n删除的元素是%d\n", e);

			}

			else

				printf("\n删除失败!\n");

			status = ListTraverse(L); break;

			//获取单链表的元素

		case 4:

			printf("请输入你想获取的元素在链表中的位置i=");

			scanf("%d", &i);

			e = GetElem(L, i);

			if (i> 0 && i <= L->len)

				printf("\n单链表第i个元素值是%d", e); break;

			//单链表判空操作

		case 5:

			status = EmptyList_L(L);

			if (status)

				printf("\n单链表为空表!\n");

			else

				printf("\n单链表非空,其中含有元素\n"); break;

			//查找定位元素

			case

				6:

					printf("\n请输入所需查找的元素e=");

					scanf("%d", &e);

					i = LocateElem(L, e);

					if (i)

						printf("\n元素e在链表中的位置是%d\n", i); break;

					//前驱操作

			case 7:

				printf("\n需要求其前驱的元素值:");

				scanf("%d", &curr_e);

				status = PriorElem(L, curr_e, &e);

				if (status)

					printf("\n元素 curr_e 的前驱是%d\n", e); break;

				//后继操作

			case 8:

				printf("\n需要求其后继的元素值: ");

				scanf("%d", &curr_e);

				status = NextElem(L, curr_e, &e);

				if (status)

					printf("元素 curr_e 的后继是%d\n", e); break;

				//单链表的清空操作

			case 9:

				printf("调用清空链表函数\n");

				status = ClearList_L(&L);

				status = ListTraverse(L); break;

			case 0:

				printf("操作结束\n"); break;

			default:printf("输入选择出错！\n");

		}/*switch*/

	} while (select != 0);

	//单链表的销毁操作

	printf("\n调用链表销毁函数");

	DestoryList_L(&L);

}