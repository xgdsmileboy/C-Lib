#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string>
#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 100   //存储空间初始分配量
#define STACKINCREMENT 10     //存储空间分配增量
typedef int status;
typedef char SElemType;
typedef double ElemType;
typedef struct
{
	SElemType *base;   
	SElemType *top;
	int stacksize;   //当前已分配的存储空间
}SqStack;
typedef struct
{
	double *base;   
	double *top;
	int stacksize;   //当前已分配的存储空间
}SqStack1; //????与上面?????

//栈的基本实现
status InitStack(SqStack &S)
{//构造一个空栈S
    S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) 
	{ 
		printf("申请空间失败");
		exit(OVERFLOW);

	}

	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}//InitStack
status Push(SqStack &S,SElemType e)
{//插入元素e为新的栈顶元素
	if(S.top-S.base>=S.stacksize)
	{//栈满，追加存储空间
		S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) 
		{ 
		  
			printf("申请空间失败");
		    exit(OVERFLOW);

		}//存储失败
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;//------------怎么理解????
	return OK;
}//Push
double Pop1(SqStack1 &S) 
{
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回 OK;否则返回 ERROR
	double e;
	if(S.top==S.base) return ERROR;
	e=*--S.top;
	return e;
}//Pop1
char Pop2(SqStack &S) 
{
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回 OK;否则返回 ERROR
	SElemType e;
	if(S.top==S.base) return ERROR;
	e=*--S.top;
	return e;
}//Pop2
char GetTop(SqStack S)
 {
	//若栈不空，则用元素e返回S的栈顶元素，并返回OK,否则返回ERROR
	if(S.top==S.base) return ERROR;
	SElemType e;
	e=*(S.top-1);
	return e;
	}//GetTop
status In(char c)//---------------怎么理解?????
{//若是运算符返回1,反之返回0
	if(c>='0'&&c<='9')
		return ERROR; 
	else return OK;
}
int Precede(char m,char n)
{//根据算符的优先顺序
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
{//构造一个空栈S
    S.base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S.base)
	{ 
		printf("申请空间失败");
		exit(OVERFLOW);

	}
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}//InitStack1
status Push1(SqStack1 &S,double e)
{//插入元素e为新的栈顶元素
	if(S.top-S.base>=S.stacksize)
	{//栈满，追加存储空间
		S.base=(ElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!S.base) 
		{ 
		    printf("申请空间失败");
		    exit(OVERFLOW);

		}//存储失败
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}//Push1
double GetTop1(SqStack1 S)
 {
	//若栈不空，则用元素e返回S的栈顶元素，并返回OK,否则返回ERROR
	if(S.top==S.base) return ERROR;
	ElemType e;
	e=*(S.top-1);
	return e;
}//GetTop1
double EvaluateExpression() 
{    
	//算术表达式求值的算符优先算法。设OPTR和OPND分别为运算符栈和运算数栈
	char c,theta;
	//c为要读入的数据;theta
	double d,a,b,f;
	double ff, fff;
	int k=1;
	SqStack OPTR;
	SqStack1 OPND;
	InitStack(OPTR); Push(OPTR,'#');//建立栈,用于存放运算符
	InitStack1(OPND); //建立栈,用于存运算数
	printf("\t计算公式：");
	getchar();
	c=getchar();
	while(c!='#'||GetTop(OPTR)!='#')//与OPTR的栈底运算符比较 
	{
		if(c=='\n'&&GetTop(OPTR)!='#')
		{
			printf("你的输入的格式错误！\n\t\t请重新输入！！\n");
			return 0;
		}//if 错误提示,若在运算结束时不是输入#而是输入ENTER,则会提示错误
		 //防止手误
		  
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
		} //不是运算符则进栈
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
	Push(OPTR,'#');//建立栈
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
		printf("\n\t\t   计算完成！\n");
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
	printf("\t\t**  欢迎使用由本组设计的计算器  ** \n");
	printf("\t\t**********************************\n\n");
	printf("\t\t制作小组成员:\n\n");
	printf("\t\t\t杜开敏\n");
	printf("\t\t\t  李  丹\n");
	printf("\t\t\t    李常秀\n");
	//freopen("input.txt", "r", stdin);
	do
	{
		FILE * fp;
		char ch;
		printf("\t\t----------------------------------\n");
		printf("\t\t\t     温馨提示\t\t\t\n");
		printf("\t\t¤ 计算请按 1 \n");
		printf("\t\t¤ 作业计算请按 2\n");
		//printf("\t\t¤ 读取文件计算结果请按 3\n");
		printf("\t\t¤ 查看已经做过的作业 3 \n\n");
		printf("\t\t¤ 退出请按 Q(不区分大小写)\n");
		printf("\t\t请选择:  ");
	    ch=getchar();
	    switch(ch)
		{
	         case '1':
			       double d;
		   	       printf("\n");
			       printf("\t\t  请输入表达式并以#号结束！谢谢\n\n\t");
			       d=EvaluateExpression();
			       printf("结果为%.7lf\n\n\n",d);//-------要求,保留到小数点后7位
			  break;
	         case '2':
		           EvaluateExpression(true);
		           computeFlag = true;
		      break;
	         case '3':
		          if(computeFlag == false)
				  {
			         printf("\t\t  还未读取文件！\n");
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
