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
//初始化空队列  
void InitQueue(queue &s)
{
	s.maxSize = max_size;
	s.q = (int *)malloc(max_size*sizeof(int));  //动态申请一维数组   
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
//获取队首的元素  
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
//进队  
void enqueue(queue &s, int x)
{
	if (isfull(s))
	{
		cout << "Full" << endl;
	}
	s.q[(s.rear = (s.rear + 1) % s.maxSize)] = x;

}
//出队  
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