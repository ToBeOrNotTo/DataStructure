#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 20
#define ElemType int /*定义顺序栈的存储结构*/
typedef struct 
{  ElemType stack[MAXNUM];    
int top; }SqStack; /*初始化顺序栈*/ 
void InitStack(SqStack *p) 
{  if(!p)         
printf("Eorror");   
p->top=-1; 
} /*入栈*/
void Push(SqStack *p, ElemType x) 
{ if (p->top<MAXNUM - 1)   
   { p->top = p->top + 1;    
    p->stack[p->top] = x; }  
 else            
	 printf("Overflow!\n");
} /*出栈*/ 
ElemType Pop(SqStack *p) {
	ElemType x;  
	if (p->top != 0)   
	{ x = p->stack[p->top];     
	printf("以前的栈顶数据元素%d已经被删除！\n", p->stack[p->top]); 
	p->top = p->top - 1;      
	return(x); }
	else    
	{ printf("Underflow!\n");
	return(0); }
}  /*获取栈顶元素*/ 
ElemType GetTop(SqStack *p)
{ ElemType x;  
if (p->top != 0)    
{ x = p->stack[p->top];     
return(x); }
else  
{ printf("Underflow!\n");    
return(0); }
}  /*遍历顺序栈*/ 
void OutStack(SqStack *p)
{ int i;    
printf("\n");    
if (p->top<0)        
	printf("这是一个空栈！");  
printf("\n");  
for (i = p->top; i >= 0; i--)    
printf("第%d个数据元素是：%6d\n", i, p->stack[i]);
}
/*置空顺序栈*/ 
void setEmpty(SqStack *p)
{ p->top = -1; } 
/*主函数*/ 
 int main() {
	SqStack *q;  
	q = (SqStack*)malloc(sizeof(SqStack));
	int y, cord; ElemType a;  
	do{
		printf("\n");       
		printf("第一次使用必须初始化！\n");     
		printf("\n");       
		printf("\n   主菜单         \n");  
		printf("\n    1    初始化顺序栈   \n");        
		printf("\n    2    插入一个元素   \n");       
		printf("\n    3    删除栈顶元素   \n");      
		printf("\n    4    取栈顶元素     \n");      
		printf("\n    5    置空顺序栈     \n");    
		printf("\n    6    结束程序运行   \n");     
		printf("\n--------------------------------\n");  
		printf("请输入您的选择( 1, 2, 3, 4, 5,6)");       
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
		{    printf("请输入要插入的数据元素：a=");     
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
		printf("\n栈顶元素为：%d\n", y);     
		OutStack(q);
		}break;         
		case 5:           
		{    setEmpty(q);        
		printf("\n顺序栈被置空！\n");      
		OutStack(q);                 
		}break;               
		case 6:                
			exit(0);
		}
	} while (cord <= 6);
}