#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 20
#define ElemType int /*����˳��ջ�Ĵ洢�ṹ*/
typedef struct 
{  ElemType stack[MAXNUM];    
int top; }SqStack; /*��ʼ��˳��ջ*/ 
void InitStack(SqStack *p) 
{  if(!p)         
printf("Eorror");   
p->top=-1; 
} /*��ջ*/
void Push(SqStack *p, ElemType x) 
{ if (p->top<MAXNUM - 1)   
   { p->top = p->top + 1;    
    p->stack[p->top] = x; }  
 else            
	 printf("Overflow!\n");
} /*��ջ*/ 
ElemType Pop(SqStack *p) {
	ElemType x;  
	if (p->top != 0)   
	{ x = p->stack[p->top];     
	printf("��ǰ��ջ������Ԫ��%d�Ѿ���ɾ����\n", p->stack[p->top]); 
	p->top = p->top - 1;      
	return(x); }
	else    
	{ printf("Underflow!\n");
	return(0); }
}  /*��ȡջ��Ԫ��*/ 
ElemType GetTop(SqStack *p)
{ ElemType x;  
if (p->top != 0)    
{ x = p->stack[p->top];     
return(x); }
else  
{ printf("Underflow!\n");    
return(0); }
}  /*����˳��ջ*/ 
void OutStack(SqStack *p)
{ int i;    
printf("\n");    
if (p->top<0)        
	printf("����һ����ջ��");  
printf("\n");  
for (i = p->top; i >= 0; i--)    
printf("��%d������Ԫ���ǣ�%6d\n", i, p->stack[i]);
}
/*�ÿ�˳��ջ*/ 
void setEmpty(SqStack *p)
{ p->top = -1; } 
/*������*/ 
 int main() {
	SqStack *q;  
	q = (SqStack*)malloc(sizeof(SqStack));
	int y, cord; ElemType a;  
	do{
		printf("\n");       
		printf("��һ��ʹ�ñ����ʼ����\n");     
		printf("\n");       
		printf("\n   ���˵�         \n");  
		printf("\n    1    ��ʼ��˳��ջ   \n");        
		printf("\n    2    ����һ��Ԫ��   \n");       
		printf("\n    3    ɾ��ջ��Ԫ��   \n");      
		printf("\n    4    ȡջ��Ԫ��     \n");      
		printf("\n    5    �ÿ�˳��ջ     \n");    
		printf("\n    6    ������������   \n");     
		printf("\n--------------------------------\n");  
		printf("����������ѡ��( 1, 2, 3, 4, 5,6)");       
		scanf("%d", &cord);      
		printf("\n");          
		switch (cord)       
		{
		case 1:                    
		{    
	   
		InitStack(q);           
		OutStack(q);       
		}break;         
		case 2:        
		{    printf("������Ҫ���������Ԫ�أ�a=");     
		scanf("%d", &a);                 
		Push(q, a);                   
		OutStack(q);                
		}break;             
		case 3:              
		{    Pop(q);         
		OutStack(q);         
		}break;             
		case 4:             
		{    y = GetTop(q); 
		printf("\nջ��Ԫ��Ϊ��%d\n", y);     
		OutStack(q);
		}break;         
		case 5:           
		{    setEmpty(q);        
		printf("\n˳��ջ���ÿգ�\n");      
		OutStack(q);                 
		}break;               
		case 6:                
			exit(0);
		}
	} while (cord <= 6);
}