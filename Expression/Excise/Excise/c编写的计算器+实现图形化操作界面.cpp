#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string>
#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 100   //�洢�ռ��ʼ������
#define STACKINCREMENT 10     //�洢�ռ��������
typedef int status;
typedef char SElemType;
typedef double ElemType;
typedef struct
{
	SElemType *base;   
	SElemType *top;
	int stacksize;   //��ǰ�ѷ���Ĵ洢�ռ�
}SqStack;
typedef struct
{
	double *base;   
	double *top;
	int stacksize;   //��ǰ�ѷ���Ĵ洢�ռ�
}SqStack1; //????������?????

//ջ�Ļ���ʵ��
status InitStack(SqStack &S)
{//����һ����ջS
    S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) 
	{ 
		printf("����ռ�ʧ��");
		exit(OVERFLOW);

	}

	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}//InitStack
status Push(SqStack &S,SElemType e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
	if(S.top-S.base>=S.stacksize)
	{//ջ����׷�Ӵ洢�ռ�
		S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) 
		{ 
		  
			printf("����ռ�ʧ��");
		    exit(OVERFLOW);

		}//�洢ʧ��
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;//------------��ô���????
	return OK;
}//Push
double Pop1(SqStack1 &S) 
{
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ�������� OK;���򷵻� ERROR
	double e;
	if(S.top==S.base) return ERROR;
	e=*--S.top;
	return e;
}//Pop1
char Pop2(SqStack &S) 
{
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ�������� OK;���򷵻� ERROR
	SElemType e;
	if(S.top==S.base) return ERROR;
	e=*--S.top;
	return e;
}//Pop2
char GetTop(SqStack S)
 {
	//��ջ���գ�����Ԫ��e����S��ջ��Ԫ�أ�������OK,���򷵻�ERROR
	if(S.top==S.base) return ERROR;
	SElemType e;
	e=*(S.top-1);
	return e;
	}//GetTop
status In(char c)//---------------��ô���?????
{//�������������1,��֮����0
	if(c>='0'&&c<='9')
		return ERROR; 
	else return OK;
}
int Precede(char m,char n)
{//�������������˳��
	int i,j;
	int a[7][7]={{1,1,-1,-1,-1,1,1},{1,1,-1,-1,-1,1,1},{1,1,1,1,-1,1,1},
	{1,1,1,1,-1,1,1},{-1,-1,-1,-1,-1,0,2},{1,1,1,1,2,1,1},{-1,-1,-1,-1,-1,2,0}};
	if(m-'+'==0) i=0;
	else if(m-'-'==0) i=1;
	else if(m-'*'==0) i=2;
	else if(m-'/'==0) i=3;
	else if(m-'('==0) i=4;
	else if(m-')'==0) i=5;
	else if(m-'#'==0) i=6;
	if(n=='+') j=0;
	else if(n=='-') j=1;
	else if(n=='*') j=2;
	else if(n=='/') j=3;
	else if(n=='(') j=4;
	else if(n==')') j=5;
	else if(n=='#') j=6;
	return a[i][j];
}

double Operate(double a,char theta ,double b)
{
	double f;
	if (theta=='+')
	{f=a+b;
	}
	if (theta=='-')
	{f=a-b;
	}
	if (theta=='*')
	{f=a*b;
	}
	if (theta=='/')
	{f=a/b;
	}
	return f;
}
status InitStack1(SqStack1 &S)
{//����һ����ջS
    S.base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S.base)
	{ 
		printf("����ռ�ʧ��");
		exit(OVERFLOW);

	}
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}//InitStack1
status Push1(SqStack1 &S,double e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
	if(S.top-S.base>=S.stacksize)
	{//ջ����׷�Ӵ洢�ռ�
		S.base=(ElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!S.base) 
		{ 
		    printf("����ռ�ʧ��");
		    exit(OVERFLOW);

		}//�洢ʧ��
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}//Push1
double GetTop1(SqStack1 S)
 {
	//��ջ���գ�����Ԫ��e����S��ջ��Ԫ�أ�������OK,���򷵻�ERROR
	if(S.top==S.base) return ERROR;
	ElemType e;
	e=*(S.top-1);
	return e;
}//GetTop1
double EvaluateExpression() 
{    
	//�������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ��������ջ
	char c,theta;
	//cΪҪ���������;theta
	double d,a,b,f;
	double ff, fff;
	int k=1;
	SqStack OPTR;
	SqStack1 OPND;
	InitStack(OPTR); Push(OPTR,'#');//����ջ,���ڴ�������
	InitStack1(OPND); //����ջ,���ڴ�������
	printf("\t���㹫ʽ��");
	getchar();
	c=getchar();
	while(c!='#'||GetTop(OPTR)!='#')//��OPTR��ջ��������Ƚ� 
	{
		if(c=='\n'&&GetTop(OPTR)!='#')
		{
			printf("�������ĸ�ʽ����\n\t\t���������룡��\n");
			return 0;
		}//if ������ʾ,�����������ʱ��������#��������ENTER,�����ʾ����
		 //��ֹ����
		  
		if(!In(c)) 
		{
		   f=c-48;
		   printf("\t");
	       c=getchar();
           while(c>='0'&&c<='9')
		   {
			  f=f*10+c-48;
			  printf("\t");
		      c=getchar();
		   }
		if (c == '.')
		{
			printf("\t");
			c=getchar();
			ff = 0;
			k=1;
			while(c>='0'&&c<='9')
			{
				k*=10;
				ff = ff*10+c-48;
				printf("\t");
				c=getchar();
			}
		}
		else ff = 0;
		     fff = f+ff*1.0/k;
		Push1(OPND,fff);
		} //������������ջ
		else switch(Precede(GetTop(OPTR),c))
					{
			
			case -1:
				Push(OPTR,c); 
				c=getchar(); 
				break;
			case 0:
				Pop2(OPTR); 
				c=getchar(); 
				break;
			case 1:
				theta=Pop2(OPTR);
				b=Pop1(OPND); 
				a=Pop1(OPND);
				Push1(OPND,Operate(a,theta,b));
				break;				
			case 2:
				printf("error");
		}//switch
	}//while
	d=GetTop1(OPND);
	return d;
}//EvaluateExpression

int GetValue(char ch)
{
	if(ch >='0' && ch <= '9')
		return ch - '0';
	else if(ch == '.')
		return -2;
	else return -1;
}

bool Compute(char str[], double &result)
{
	result = 0;
	char op;
	int index = -1;
	double a,b;
	double r=0;
	SqStack OPTR;
	SqStack1 OPND;
	InitStack(OPTR);
	Push(OPTR,'#');//����ջ
	InitStack1(OPND);
	while((str[++index]!='#' || GetTop(OPTR)!='#') && str[index]!='\0') 
	{
		int temp1=0;
		int temp2=0;
		int length=1;
		int value;
		while((value=GetValue(str[index++])) != -1)
		{
			if(value == -2)
			{
				while((value=GetValue(str[index])) != -1)
				{
					temp2 = temp2 * 10 + value;
					length *= 10;
					index++;
				}
				index--;
			}
			else
			{
				temp1 = temp1 * 10 + value;
			}
		}
		index--;
		double temp = temp1 + temp2*1.0/length;
		Push1(OPND,temp);
		switch(Precede(GetTop(OPTR),str[index]))
			{
			case -1:
				Push(OPTR,str[index]); 
				break;
			case 0:
				Pop2(OPTR);
				break;
			case 1:
				op=Pop2(OPTR);
				b=Pop1(OPND);
				a=Pop1(OPND);
				r = Operate(a,op,b);
				Push1(OPND,r);
				break;
			case 2:
				printf("error\n");
				break;
			}//switch
		}//while
		result=GetTop1(OPND);
	return true;
}

void EvaluateExpression(bool flag)
{
	if(flag == true)
	{
		char str[100];
		FILE *fp;
		FILE *fpOut;
		fp = fopen("input.txt", "r");
		fpOut = fopen("output.txt", "w");
		if(fp == NULL) exit(1);
		if(fpOut == NULL) exit(1);
		while(fscanf(fp, "%s", str) != EOF)
		{
			double result;
			if(Compute(str, result) == true)
			{
				fprintf(fpOut, "%s\b=%.3lf\n", str, result);
				printf("\n\t\t %s\b=%.7lf\n", str, result);
			}
		}
		fclose(fp);
		fclose(fpOut);
		printf("\n\t\t   ������ɣ�\n");
	}
}

void Show()
{
	char str[100];
	FILE *fpOut;
	fpOut = fopen("output.txt", "r");
	while(fscanf(fpOut, "%s", str) != EOF)
	{
		printf("\t\t%s\n", str);
	}
	fclose(fpOut);
}

void main()
{
	
	bool flag = true;
	bool computeFlag = false;
	printf("\t\t**********************************\n");
	printf("\t\t**  ��ӭʹ���ɱ�����Ƶļ�����  ** \n");
	printf("\t\t**********************************\n\n");
	printf("\t\t����С���Ա:\n\n");
	printf("\t\t\t�ſ���\n");
	printf("\t\t\t  ��  ��\n");
	printf("\t\t\t    ���\n");
	//freopen("input.txt", "r", stdin);
	do
	{
		FILE * fp;
		char ch;
		printf("\t\t----------------------------------\n");
		printf("\t\t\t     ��ܰ��ʾ\t\t\t\n");
		printf("\t\t�� �����밴 1 \n");
		printf("\t\t�� ��ҵ�����밴 2\n");
		//printf("\t\t�� ��ȡ�ļ��������밴 3\n");
		printf("\t\t�� �鿴�Ѿ���������ҵ 3 \n\n");
		printf("\t\t�� �˳��밴 Q(�����ִ�Сд)\n");
		printf("\t\t��ѡ��:  ");
	    ch=getchar();
	    switch(ch)
		{
	         case '1':
			       double d;
		   	       printf("\n");
			       printf("\t\t  ��������ʽ����#�Ž�����лл\n\n\t");
			       d=EvaluateExpression();
			       printf("���Ϊ%.7lf\n\n\n",d);//-------Ҫ��,������С�����7λ
			  break;
	         case '2':
		           EvaluateExpression(true);
		           computeFlag = true;
		      break;
	         case '3':
		          if(computeFlag == false)
				  {
			         printf("\t\t  ��δ��ȡ�ļ���\n");
			         break;
				  }
		         Show();
		         break;
	         case 'q':
	         case 'Q':
				flag = false;
		     break;
	         default:
		     break;
		}//switch
	     getchar();
	}while (flag);
}//main
