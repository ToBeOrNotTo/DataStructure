#include<iostream>  
#include <malloc.h>   //malloc     
using namespace std;
const int max_size = 100;
typedef struct queue
{
	int front, rear;
	int maxSize;
	int *q;
}queue;
//��ʼ���ն���  
void InitQueue(queue &s)
{
	s.maxSize = max_size;
	s.q = (int *)malloc(max_size*sizeof(int));  //��̬����һά����   
	s.front = s.rear = 0;
}
int isempty(queue &s)
{
	return s.front == s.rear;
}
int isfull(queue &s)
{
	return (s.rear + 1) % s.maxSize == s.front;
}
//��ȡ���׵�Ԫ��  
int getTop(queue &s)
{
	int x;
	if (isempty(s))
	{
		cout << "empty" << endl;
	}
	x = s.q[(s.front + 1) % s.maxSize];
	return x;
}
//����  
void enqueue(queue &s, int x)
{
	if (isfull(s))
	{
		cout << "Full" << endl;
	}
	s.q[(s.rear = (s.rear + 1) % s.maxSize)] = x;

}
//����  
void dequeue(queue &s)
{
	if (isempty(s))
	{
		cout << "underflow" << endl;
	}
	s.front = (s.front + 1) % s.maxSize;
}
void print(queue &s)
{
	if (isempty(s))
	{
		cout << "underflow" << endl;
		exit(0);
	}
	else
	{
		while (s.front != s.rear)
		{
			cout << s.q[++s.front] << " ";
		}
		cout << endl;
	}
}
int main()
{
	queue s;
	InitQueue(s);
	enqueue(s, 2);
	enqueue(s, 3);
	enqueue(s, 4);
	enqueue(s, 8);
	dequeue(s);
	dequeue(s);
	print(s);
	return 0;
}