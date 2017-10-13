
#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0 
#define OVERFLOW -2 
#define MAXSTRLEN 255 
typedef int ElemType; 
typedef int Status;  
typedef unsigned char SString[MAXSTRLEN+1];  
//串赋值操作 
Status StrAssign(SString T,char chars[]){  // 生成一个其值等于chars的串T 
	int i;      
	if(strlen(chars)>MAXSTRLEN)   return ERROR;   
	T[0]=strlen(chars); 
	for(i=0;i<=T[0];i++){   T[i+1]=chars[i];}     return OK;   }//StrAssign   
//输出串
void StrPrint(SString S){ 
	int i;     
	for(i=1;i<=S[0];i++){   printf("%c",S[i]);  }  
	printf("\n"); }//PrnStr 
//串复制操作 
Status StrCopy(SString T,SString S){   // 由串S复制得串T 
	int i;      for (i = 1; i <= S[0]; i++)         T[i] = S[i];  T[0] = S[0];     return OK;
}//StrCopy  
//判空操作
Status StrEmpty(SString S){ 
	if(S[0]==0)      return OK; 
	else       return ERROR;  }//StrEmpty 
//串比较操作  
int StrCompare(SString S,SString T){   
	int i;    
	for(i=1;i<=S[0]&&i<=T[0];++i)    
	if(S[i]!=T[i])           return S[i]-T[i];   
	return S[0]-T[0];  }//StrCompare  
//求长度操作 
int StrLength(SString S){  return S[0]; }//StrLength  
//串连接操作 
Status Concat(SString T,SString S1,SString S2){ 
	int i; 
	Status uncut; 
	if(S1[0]+S2[0]<=MAXSTRLEN){         
		for(i=1;i<=S1[0];i++){    T[i]=S1[i];}
		for(i=1;i<=S2[0];i++){       T[S1[0]+i]=S2[i];}   T[0]=S1[0]+S2[0];   uncut=TRUE;
	}
	else if (S1[0]<MAXSTRLEN){ for (i = 1; i <= S1[0]; i++){ T[i] = S1[i]; }   for (i = 1; i <= MAXSTRLEN - S1[0]; i++){ T[S1[0] + i] = S2[i]; }   T[0] = MAXSTRLEN;         uncut = FALSE; }
	else{ for (i = 0; i <= MAXSTRLEN; i++){ T[i] = S1[i]; }   uncut = FALSE; }  return uncut;
}//Concat  
//取子串操作
Status SubString(SString Sub,SString S,int pos,int len){ 
	int i; 
	if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)   return ERROR; 
	for(i=1;i<=len;i++){   Sub[i]=S[pos+i-1];}  Sub[0]=len;  return OK; }//SubString   
//求子串位置操作 
int Index(SString S,SString T,int pos){  
	int i,j;   
	i=pos;  
	j=1;    
	while(i<=S[0]&&j<=T[0]){  
		if(S[i]==T[j]) {         ++i;         ++j;      }    
		else{// 指针后退重新开始匹配      
			i=i-j+2;         j=1; 
		}
	}    
	if (j>T[0])        return i - T[0];//匹配成功  
	return 0;     //匹配失败 
}//Index 
	//串插入操作  
	Status StrInsert(SString S,int pos,SString T){  // 初始条件: 串S和T存在,1≤pos≤StrLength(S)+1      // 操作结果: 在串S的第pos个字符之前插入串T。完全插入返回TRUE,部分插入返回FALSE 
		int i;      if(pos<1||pos>S[0]+1)   return ERROR;   
		if(S[0]+T[0]<=MAXSTRLEN){ // 完全插入  
			for(i=S[0];i>=pos;i--){    S[i+T[0]]=S[i];}    
			for(i=pos;i<pos+T[0];i++){             S[i]=T[i-pos+1];}         S[0]=S[0]+T[0];         return TRUE;  } 
		else{   for(i=MAXSTRLEN;i>=pos;i++){    S[i]=S[i-T[0]];}   
		for(i=pos;i<pos+T[0];i++){    S[i]=T[i-pos+1];}   S[0]=MAXSTRLEN;   return FALSE;  } }//StrInsert  
	//串删除操作 
	Status StrDelete(SString S,int pos,int len){  // 初始条件: 串S存在,1≤pos≤StrLength(S)-len+1      // 操作结果: 从串S中删除第pos个字符起长度为len的子串 
		int i;  
		if(pos<1||pos>S[0]-len+1||len<0)   return ERROR; 
		for(i=pos+len;i<=S[0];i++){

			S[i - len] = S[i];
		}  S[0] -= len;  return OK;
	}//StrDelete  
	void main(){  
		int pos,len; 
		SString S1,S2,S3,T,Sub;
		char a[10],b[10];   
		printf("输入两个串分别赋值给S1,S2(串长均小于10)：\n");   
		scanf("%s%s",a,b);  
		if(StrAssign(S1,a)&&StrAssign(S2,b)){  
			printf("\n由串S1复制得串T："); 
			StrCopy(T,S1);   //printf("%s\n",S2+1);——错误的！ 
			StrPrint(T); 
			if(StrEmpty(T)==1)   
				printf("串T为空！\n");   
			else       printf("串T非空！\n");
			printf("\n比较串S1,S2：\n"); 
			if(StrCompare(S1,S2)>0)  printf("S1>S2\n");  
			else if(StrCompare(S1,S2)<0)    printf("S1<S2\n"); 
			else    printf("S1=S2\n");     printf("\n连接串S1,S2得串S3："); 
			if(Concat(S3,S1,S2)==1){    StrPrint(S3);   } 
			else    printf("串连接失败！");  
			printf("串S3的长度为%d：\n",StrLength(S3)); 
			printf("\n用Sub返回串S3中第pos个字符起长度为len的字符：\n");  
			printf("输入pos,len的值：\n");  
			scanf("%d%d", &pos, &len);   
			if (SubString(Sub, S3, pos, len) == 1){ printf("输出串Sub：");    StrPrint(Sub); }
			else    printf("序号不合法，取子串失败！\n");    printf("\n求串Sub在串S3中的位置：\n");
			if (Index(S3, Sub, pos))    printf("pos值为%d\n", pos);  
			else    printf("pos值不合法！\n");   
			printf("\n在串S1的第pos位置插入串S2\n"); 
			printf("输入pos的值：\n");  
			scanf("%d", &pos);  
			if (StrInsert(S1, pos, S2) == 1){ printf("输出串S1：");  
			StrPrint(S1); }
			else    printf("插入失败！\n");   
			printf("\n从串S1中删除第pos位置起长度为len的字符：\n");  
			printf("输入pos,len的值：\n");   scanf("%d%d", &pos, &len); 
			if (StrDelete(S1, pos, len)){ printf("输出串S1：");   
			StrPrint(S1); }
			else    printf("删除失败！\n");
		}
	}