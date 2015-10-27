#ifndef POS_EXPRESSION_H
#define POS_ECPRESSION_H

#include"Definition.h"
/////////////////////=========将中缀表达式转换成后缀表达式==========//////////////////////
void pos_Expression(PLinkStack OPRT,char *ch)    //参数为用于保存转换后的后缀表达式的空栈和待转换表达式
{
	PLinkStack Exp=Creat();      //初始化一个临时存储操作数的栈
	char theta;                  //用于接受从操作符栈中取出的操作符
    while(*ch!='\0')             //对表达式实现遍历
	{	DataType d=0;
		if(*ch<='9'&&*ch>='0')   //遇到操作数
		{
			while(*ch<='9'&&*ch>='0')    //循环读取数据，可以读取输入的大于10的数
			{
				d=d*10+*ch-'0'; ch++;
			}
			Push(Exp,d);                 //将数据进临时栈
			continue;
		}
		else
		{
			if(isEmpty(OPRT))            //操作符栈空，操作符直接进栈
				{Push(OPRT,*ch); ch++;continue;}
			switch(*ch)
			{
			case '(': Push(OPRT,*ch); ch++;  continue;   //遇到左括号，直接进栈
			case ')': theta=GetTop(OPRT);                //遇到右括号，将左括号之前是操作符依次退栈并进临时栈
					  while(theta!='('&& !isEmpty(OPRT))
					  {
						  theta=Pop(OPRT);Push(Exp,theta);
						  if(!isEmpty(OPRT))
							  theta=GetTop(OPRT);
					  }//while
					  theta=Pop(OPRT);
					  ch++;
					  continue;
			case '+':
			case '-':theta=GetTop(OPRT);                //遇到+或是-，将其前的运算符全部输出到临时栈中
					while(!isEmpty(OPRT)&&theta!='(')   //终止条件为没有运算符了或是遇到了左括号
					 {
						 theta=Pop(OPRT); 
						 Push(Exp,theta);
						 if(!isEmpty(OPRT))
							 theta=GetTop(OPRT);
					 }//while
					 Push(OPRT,*ch);             //将当前运算符进栈
					 ch++;
					 continue;
			case '*':
			case '/':theta=GetTop(OPRT);         //遇到*或是/，将其前的*和/全部输出到临时栈
				     while(theta=='*' || theta=='/')
					 {
						 theta=Pop(OPRT); Push(Exp,theta);
						 if(!isEmpty(OPRT))
							 theta=GetTop(OPRT);
					 }//while
				   	 Push(OPRT,*ch);             //将当前运算符进栈
					 ch++;
					 continue;
			}//switch
		}//else
	}//while 
	while(!isEmpty(Exp))                         //将临时栈中的数据转到保存栈中
	{
		theta=Pop(Exp);
		Push(OPRT,theta);
	};
}
/////////////////////======输出栈保存的后缀表达式========///////////////////////////
void Pos_Print(PLinkStack OPRT)                      //参数为待输出的栈类型
{
	DataType theta;
	cout<<"The postfix expression is:"<<endl;        //输出提示
	while(!isEmpty(OPRT))                            //输出后缀表达式
	{
		theta=Pop(OPRT);
		if(theta=='+'||theta=='-'||theta=='*'||theta=='/')      //遇到运算符，控制输出
			printf("%c ",int(theta));
		else
			cout<<theta<<" ";
	}
	cout<<endl<<endl;
}
///////////////////=========后缀表达式求值==========//////////////////////////
DataType Pos_Calculate(PLinkStack Exp)       //参数为保存后缀表达式的栈类型
{
	PLinkStack Calcu=Creat();                //初始化一个空栈保存后缀表达式计算过程中的数据
	DataType a,b,theta;                      //a,b用于读取操作数，theta用于读取操作符

	while(!isEmpty(Exp))   
	{
		theta=Pop(Exp);
		if(theta=='+' || theta=='-' || theta=='*' ||theta=='/')  //遇到运算符，在数据栈中取数运算
		{
			 b=Pop(Calcu);
			 a=Pop(Calcu); 
			 Push(Calcu,Oprate(a,theta,b));
		}
		else
			Push(Calcu,theta);      //遇到数据使其进数据栈
	}
    return (Pop(Calcu));            //返回计算结果
}
#endif