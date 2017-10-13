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

		printf("������Ԫ�ص�ֵ(ǰ��):\n");

		scanf("%d", &p->data);

		p->next = (*L)->next; //���뵽��ͷ

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

		printf("����ʧ��! ����Խ��\n");

		return ERROR;

	}

	else

	{
		p = *L;

		for (j = 0; j<i - 1; j++) //forѭ��������p��ָ���i-1��Ԫ�أ���Ӧ����p�����Ԫ��e

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

		printf("ɾ��ʧ��! ����Խ��\n");

		return ERROR;

	}

	else

	{

		p = *L;

		for (j = 0; j < i - 1; j++) //forѭ����ָ��p��ָ��Ҫɾ����Ԫ�ص�ǰ�����

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

		printf("ȡֵ�Ƿ�! �������޴�λ��Ԫ��\n");

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

		printf("���������Ҳ���Ԫ��\n ");

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

		printf("���������Ҳ���Ԫ��,�޷�����ǰ��Ԫ��!\n");

		return ERROR;

	}

	if (p == L)

	{

		printf("Ԫ�� curr_e �������е���ԪԪ��,��ǰ��\n");

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

			printf("������һ���ձ�,�޷���ȡ��̲���\n!");

			return ERROR;

		}

	}

	if (p == NULL)

	{

		printf("\n��������δ���ҵ�Ԫ��: ");

		return ERROR;

	}

	if (p->next == NULL)

	{

		printf("\nԪ�� curr_e �������βԪԪ��,�޷�������!\n");

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

		printf("\n�����г�ͷ�����������������ѱ��ͷ�,��һ���ձ�!\n");

		printf("\n����ʧ��!\n");

		return ERROR;

	}

	if (LISTLEN == -1)

	{

		printf("\n���������ѱ��ͷ�,�����ѱ�����!\n");

		printf("\n����ʧ��!\n");

		return ERROR;

	}

	while (p)

	{

		printf("%4d", p->data);

		p = p->next;

	}

	printf("\n�����ɹ�!\n");

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

	int status; //���غ���ִ��״̬

	printf("���������贴����Ԫ�ظ���:\n");

	scanf("%d", &i);

	//����������

	CreateList_L(&L, i);

	//����

	ListTraverse(L);

	do{

		printf("1:����ĳ���\n");

		printf("2:����Ԫ��\n");

		printf("3:ɾ��Ԫ��\n");

		printf("4:ȡ�����е�i��Ԫ��\n");

		printf("5:�ж������Ƿ�Ϊ��\n");

		printf("6:��λ����\n");

		printf("7:��������Ԫ�ص�ǰ��\n");

		printf("8:��������Ԫ�صĺ��\n");

		printf("9:�ÿ�����\n");

		printf("0:����\n");

		scanf("%d", &select);

		switch (select){

			//���������

		case 1:

			ListLength(&L);

			printf("\n������ĳ�����%d\n", L->len); break;

			//����Ĳ������

		case 2:

			printf("\n��������Ҫ����Ԫ�ص�λ��i=");

			scanf("%d", &i);

			printf("\n����������Ԫ��ֵe=");

			scanf("%d", &e);

			status = ListInsert(&L, i, e);

			if (status)

				printf("\n����Ԫ�ز���ɹ�!\n");

			else

				printf("\n����Ԫ�ز���ʧ��!\n");

			status = ListTraverse(L); break;

			//�������ɾ������

		case 3:

			printf("��������Ҫɾ����Ԫ�ص�λ��i=");

			scanf("%d", &i);

			status = ListDelete(&L, i, &e);

			if (status)

			{

				printf("\nɾ���ɹ�!");

				printf("\nɾ����Ԫ����%d\n", e);

			}

			else

				printf("\nɾ��ʧ��!\n");

			status = ListTraverse(L); break;

			//��ȡ�������Ԫ��

		case 4:

			printf("�����������ȡ��Ԫ���������е�λ��i=");

			scanf("%d", &i);

			e = GetElem(L, i);

			if (i> 0 && i <= L->len)

				printf("\n�������i��Ԫ��ֵ��%d", e); break;

			//�������пղ���

		case 5:

			status = EmptyList_L(L);

			if (status)

				printf("\n������Ϊ�ձ�!\n");

			else

				printf("\n������ǿ�,���к���Ԫ��\n"); break;

			//���Ҷ�λԪ��

			case

				6:

					printf("\n������������ҵ�Ԫ��e=");

					scanf("%d", &e);

					i = LocateElem(L, e);

					if (i)

						printf("\nԪ��e�������е�λ����%d\n", i); break;

					//ǰ������

			case 7:

				printf("\n��Ҫ����ǰ����Ԫ��ֵ:");

				scanf("%d", &curr_e);

				status = PriorElem(L, curr_e, &e);

				if (status)

					printf("\nԪ�� curr_e ��ǰ����%d\n", e); break;

				//��̲���

			case 8:

				printf("\n��Ҫ�����̵�Ԫ��ֵ: ");

				scanf("%d", &curr_e);

				status = NextElem(L, curr_e, &e);

				if (status)

					printf("Ԫ�� curr_e �ĺ����%d\n", e); break;

				//���������ղ���

			case 9:

				printf("�������������\n");

				status = ClearList_L(&L);

				status = ListTraverse(L); break;

			case 0:

				printf("��������\n"); break;

			default:printf("����ѡ�����\n");

		}/*switch*/

	} while (select != 0);

	//����������ٲ���

	printf("\n�����������ٺ���");

	DestoryList_L(&L);

}