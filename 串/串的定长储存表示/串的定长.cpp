
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
//����ֵ���� 
Status StrAssign(SString T,char chars[]){  // ����һ����ֵ����chars�Ĵ�T 
	int i;      
	if(strlen(chars)>MAXSTRLEN)   return ERROR;   
	T[0]=strlen(chars); 
	for(i=0;i<=T[0];i++){   T[i+1]=chars[i];}     return OK;   }//StrAssign   
//�����
void StrPrint(SString S){ 
	int i;     
	for(i=1;i<=S[0];i++){   printf("%c",S[i]);  }  
	printf("\n"); }//PrnStr 
//�����Ʋ��� 
Status StrCopy(SString T,SString S){   // �ɴ�S���Ƶô�T 
	int i;      for (i = 1; i <= S[0]; i++)         T[i] = S[i];  T[0] = S[0];     return OK;
}//StrCopy  
//�пղ���
Status StrEmpty(SString S){ 
	if(S[0]==0)      return OK; 
	else       return ERROR;  }//StrEmpty 
//���Ƚϲ���  
int StrCompare(SString S,SString T){   
	int i;    
	for(i=1;i<=S[0]&&i<=T[0];++i)    
	if(S[i]!=T[i])           return S[i]-T[i];   
	return S[0]-T[0];  }//StrCompare  
//�󳤶Ȳ��� 
int StrLength(SString S){  return S[0]; }//StrLength  
//�����Ӳ��� 
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
//ȡ�Ӵ�����
Status SubString(SString Sub,SString S,int pos,int len){ 
	int i; 
	if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)   return ERROR; 
	for(i=1;i<=len;i++){   Sub[i]=S[pos+i-1];}  Sub[0]=len;  return OK; }//SubString   
//���Ӵ�λ�ò��� 
int Index(SString S,SString T,int pos){  
	int i,j;   
	i=pos;  
	j=1;    
	while(i<=S[0]&&j<=T[0]){  
		if(S[i]==T[j]) {         ++i;         ++j;      }    
		else{// ָ��������¿�ʼƥ��      
			i=i-j+2;         j=1; 
		}
	}    
	if (j>T[0])        return i - T[0];//ƥ��ɹ�  
	return 0;     //ƥ��ʧ�� 
}//Index 
	//���������  
	Status StrInsert(SString S,int pos,SString T){  // ��ʼ����: ��S��T����,1��pos��StrLength(S)+1      // �������: �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE,���ֲ��뷵��FALSE 
		int i;      if(pos<1||pos>S[0]+1)   return ERROR;   
		if(S[0]+T[0]<=MAXSTRLEN){ // ��ȫ����  
			for(i=S[0];i>=pos;i--){    S[i+T[0]]=S[i];}    
			for(i=pos;i<pos+T[0];i++){             S[i]=T[i-pos+1];}         S[0]=S[0]+T[0];         return TRUE;  } 
		else{   for(i=MAXSTRLEN;i>=pos;i++){    S[i]=S[i-T[0]];}   
		for(i=pos;i<pos+T[0];i++){    S[i]=T[i-pos+1];}   S[0]=MAXSTRLEN;   return FALSE;  } }//StrInsert  
	//��ɾ������ 
	Status StrDelete(SString S,int pos,int len){  // ��ʼ����: ��S����,1��pos��StrLength(S)-len+1      // �������: �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ� 
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
		printf("�����������ֱ�ֵ��S1,S2(������С��10)��\n");   
		scanf("%s%s",a,b);  
		if(StrAssign(S1,a)&&StrAssign(S2,b)){  
			printf("\n�ɴ�S1���Ƶô�T��"); 
			StrCopy(T,S1);   //printf("%s\n",S2+1);��������ģ� 
			StrPrint(T); 
			if(StrEmpty(T)==1)   
				printf("��TΪ�գ�\n");   
			else       printf("��T�ǿգ�\n");
			printf("\n�Ƚϴ�S1,S2��\n"); 
			if(StrCompare(S1,S2)>0)  printf("S1>S2\n");  
			else if(StrCompare(S1,S2)<0)    printf("S1<S2\n"); 
			else    printf("S1=S2\n");     printf("\n���Ӵ�S1,S2�ô�S3��"); 
			if(Concat(S3,S1,S2)==1){    StrPrint(S3);   } 
			else    printf("������ʧ�ܣ�");  
			printf("��S3�ĳ���Ϊ%d��\n",StrLength(S3)); 
			printf("\n��Sub���ش�S3�е�pos���ַ��𳤶�Ϊlen���ַ���\n");  
			printf("����pos,len��ֵ��\n");  
			scanf("%d%d", &pos, &len);   
			if (SubString(Sub, S3, pos, len) == 1){ printf("�����Sub��");    StrPrint(Sub); }
			else    printf("��Ų��Ϸ���ȡ�Ӵ�ʧ�ܣ�\n");    printf("\n��Sub�ڴ�S3�е�λ�ã�\n");
			if (Index(S3, Sub, pos))    printf("posֵΪ%d\n", pos);  
			else    printf("posֵ���Ϸ���\n");   
			printf("\n�ڴ�S1�ĵ�posλ�ò��봮S2\n"); 
			printf("����pos��ֵ��\n");  
			scanf("%d", &pos);  
			if (StrInsert(S1, pos, S2) == 1){ printf("�����S1��");  
			StrPrint(S1); }
			else    printf("����ʧ�ܣ�\n");   
			printf("\n�Ӵ�S1��ɾ����posλ���𳤶�Ϊlen���ַ���\n");  
			printf("����pos,len��ֵ��\n");   scanf("%d%d", &pos, &len); 
			if (StrDelete(S1, pos, len)){ printf("�����S1��");   
			StrPrint(S1); }
			else    printf("ɾ��ʧ�ܣ�\n");
		}
	}