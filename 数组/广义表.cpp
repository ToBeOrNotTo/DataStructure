# include<stdio.h>
# include<stdlib.h>  
//—————————————————————————————————————————— 
typedef struct LNode        //广义表结点的类型描述
{
	int tag;        //tag为结点中的标记域 
	char data;           //data用于存储广义表中的字母   
	struct LNode *sublist,*next; //sublist为指向该结点下一层的指针，next为指向该结点同一层的指针 
}GLNode; 
//—————————————————————————————————————————— 
	typedef struct           //顺序栈的类型描述 
	{  GLNode *pin[20];    //指针数组，用于存储广义表结点指针  
	int top;            //栈顶指针 
	}SeqStack; 
	//——————————————————————————————————————————
	void Create(GLNode *G,SeqStack &K,char s[])   //建立广义表函数
	{    GLNode *p,*q;     //p指针指向当前结点,q指针指向新申请的结点  
	int j;           //j用于标记输入的字符在数组中的位置 
	printf("输入广义表:");   //提示输入广义表的 
	gets(s);         p=G;         //令p指向头结点  
	p->next=NULL;        //头结点的next域为空  
	for(j=0;s[j]!='\0';j++)     //进入循环，建立广义表 
	{    if(s[j]=='(')         //若字符为'('，执行以下操作  
	{    p->tag=1;         //当前结点的标记域赋值为1，表示存在子表  
	K.top++;                  //当前结点的指针进栈   
	K.pin[K.top]=p;    
	q=(GLNode *)malloc(sizeof(GLNode));   //申请新结点   
	q->tag=0;                  //初始化新结点，标记域赋值为0，data域 赋空字符  
	q->data=NULL;    p->sublist=q;        //当前结点的sublist域指向新申请的结点 
	p=q;                   //令新申请的结点成为当前结点  
	}   else   {    if(s[j]==',')               //若字符为','，执行以下操作  
	{     q=(GLNode *)malloc(sizeof(GLNode));  //申请新结点       
	q->tag=0;                //初始化新结点，标记域赋值为0，data域 赋空字符  
	q->data=NULL;     p->next=q;        //当前结点的next域指向新申请的结点     
	p=q;                 //令新申请的结点成为当前结点
	}
	else    {
		if (s[j] == ')')            //若字符为')'，执行以下操作     
		{        p->next=NULL;      //令当前结点的next域为空    
		p=K.pin[K.top];           //出栈，令当前结点为栈顶元素   
		K.top--;      }     else                //若字符为字母，执行以下操作  
		{        p->data=s[j];        //令当前结点的data域为该字母     
		p->sublist=NULL;         //当前结点的sublist域为空   
		}     }    }   }  } 
	//—————————————————————————————————————————— 
	void Display(GLNode *G,SeqStack &K)           //输出广义表的函数
	{    printf("输出结果为:");        //提示以下结果为输出的广义表 
	GLNode *p;           //p指针指向当前结点 
	p=G;            //初始时p指针指向头结点  
	K.top++;                      //指向头结点的指针入栈  
	K.pin[K.top]=p;  printf("(");            //输出第一个'(' 
	p=p->sublist;                    //令当前结点的sublist域所指结点为新的当 前结点 
	while(K.top!=-1)                 //当栈不为空时执行以下操作  
	{   if(p!=NULL)                  //若当前结点指针不为空，执行以下操作  
	{    if(p->tag==1)               //若当前结点标记域为1,执行以下操作    
	{     printf("(");       //输出'('   
	K.top++;                //当前结点指针入栈   
	K.pin[K.top]=p;     p=p->sublist;              //令当前结点的sublist域成为当前结点  
	}    else                  //若当前结点标记域为0,执行以下操作    
	{     if(p->data!=NULL)          //若当前结点的date域存有字母则输出该字母    
	printf("%c",p->data);
	if (p->next != NULL) printf(",");   //若当前结点的next域不为空，表示不是该层的最后一个 结点，输出','   
	p=p->next;               //令当前结点的next域成为当前结点  
	}    } 
	else                    //若当前结点指针为空，执行以下操作  
	{    p=K.pin[K.top];               //出栈，栈顶元素所指的结点作为当前结点  
	K.top--;    printf(")");             //输出')'   
	if(p->next!=NULL) printf(",");    //若当前结点之后仍有与之同一层的结点，输出',' 
	p=p->next;                 //令当前结点的next域成为当前结点 
	}   }   printf("\n");  }
	//——————————————————————————————————————————
	int main() { 
		int i;  char s[40];           //定义数组，存储输入的字符串
		GLNode *G;                     //定义头结点，并申请存储空间  
		G=(GLNode *)malloc(sizeof(GLNode));  SeqStack K;             //定义栈并初始化栈  
		K.top=-1;                  while(1)  {     Create(G,K,s);                  //调用输入广义表的函数  
		if(s[0]=='\0') printf("广义表未建立\n");   else Display(G,K);               //调用输出广义表的函数  
		printf("\n是否继续?（是,输入1;否,输入0）:"); //提示是否继续   
		scanf("%d",&i);       
		if(i==1) getchar();              //输入1表示继续   
		printf("\n");    
		if(i==0) break;     //输入0表示结束  
		} 
		return 0; 
	}