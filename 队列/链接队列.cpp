#include<stdio.h>
#include<malloc.h>
#define ok 1
typedef struct node
{
	int data;
	struct node *next;
};
typedef struct
{
	struct node *front;
	struct node *rear;
}LinkQueue;
typedef int status;

status InitQueue(LinkQueue *Q)
{
	Q->front = (struct node *)malloc(sizeof(struct node));
	Q->rear = Q->front;
	Q->front->next = NULL;
	return ok;
}

status EnQueue(LinkQueue *Q, int e)
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return ok;
}

status DeQueue(LinkQueue *Q, int e)
{
	struct node *p;
	if (Q->front == Q->rear)
		return 0;

	else{
		p = Q->front->next;
		Q->front->next = p->next;
		if (p->next = NULL)Q->rear = Q->front;
		return(p->data);
		free(p);
	}
	return ok;
}

status OutputQueue(LinkQueue *Q)
{
	struct node *p;
	p = Q->front->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	return ok;
}

status GetFront(LinkQueue *Q)
{
	struct node *p;
	p = Q->front->next;
	printf("%d", p->data);
	return ok;
}


void main()
{
	LinkQueue s;
	int i, max, e, item;
	InitQueue(&s);
	printf("put a max:");
	scanf("%d", &max);
	printf("shu ru yuan su");
	for (i = 0; i<max; i++){
		scanf("%d", &e);
		EnQueue(&s, e);
	}
	OutputQueue(&s);
	printf("\n");
	printf("di yi ge yuan su wei£º");
	GetFront(&s);
	printf("\n");
	printf("shu ru shan chu yuan su :");
	scanf("%d", &item);
	DeQueue(&s, item);
	OutputQueue(&s);
	printf("\n");
}