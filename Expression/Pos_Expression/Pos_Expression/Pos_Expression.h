#ifndef POS_EXPRESSION_H
#define POS_ECPRESSION_H

#include"Definition.h"
/////////////////////=========����׺���ʽת���ɺ�׺���ʽ==========//////////////////////
void pos_Expression(PLinkStack OPRT,char *ch)    //����Ϊ���ڱ���ת����ĺ�׺���ʽ�Ŀ�ջ�ʹ�ת�����ʽ
{
	PLinkStack Exp=Creat();      //��ʼ��һ����ʱ�洢��������ջ
	char theta;                  //���ڽ��ܴӲ�����ջ��ȡ���Ĳ�����
    while(*ch!='\0')             //�Ա��ʽʵ�ֱ���
	{	DataType d=0;
		if(*ch<='9'&&*ch>='0')   //����������
		{
			while(*ch<='9'&&*ch>='0')    //ѭ����ȡ���ݣ����Զ�ȡ����Ĵ���10����
			{
				d=d*10+*ch-'0'; ch++;
			}
			Push(Exp,d);                 //�����ݽ���ʱջ
			continue;
		}
		else
		{
			if(isEmpty(OPRT))            //������ջ�գ�������ֱ�ӽ�ջ
				{Push(OPRT,*ch); ch++;continue;}
			switch(*ch)
			{
			case '(': Push(OPRT,*ch); ch++;  continue;   //���������ţ�ֱ�ӽ�ջ
			case ')': theta=GetTop(OPRT);                //���������ţ���������֮ǰ�ǲ�����������ջ������ʱջ
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
			case '-':theta=GetTop(OPRT);                //����+����-������ǰ�������ȫ���������ʱջ��
					while(!isEmpty(OPRT)&&theta!='(')   //��ֹ����Ϊû��������˻���������������
					 {
						 theta=Pop(OPRT); 
						 Push(Exp,theta);
						 if(!isEmpty(OPRT))
							 theta=GetTop(OPRT);
					 }//while
					 Push(OPRT,*ch);             //����ǰ�������ջ
					 ch++;
					 continue;
			case '*':
			case '/':theta=GetTop(OPRT);         //����*����/������ǰ��*��/ȫ���������ʱջ
				     while(theta=='*' || theta=='/')
					 {
						 theta=Pop(OPRT); Push(Exp,theta);
						 if(!isEmpty(OPRT))
							 theta=GetTop(OPRT);
					 }//while
				   	 Push(OPRT,*ch);             //����ǰ�������ջ
					 ch++;
					 continue;
			}//switch
		}//else
	}//while 
	while(!isEmpty(Exp))                         //����ʱջ�е�����ת������ջ��
	{
		theta=Pop(Exp);
		Push(OPRT,theta);
	};
}
/////////////////////======���ջ����ĺ�׺���ʽ========///////////////////////////
void Pos_Print(PLinkStack OPRT)                      //����Ϊ�������ջ����
{
	DataType theta;
	cout<<"The postfix expression is:"<<endl;        //�����ʾ
	while(!isEmpty(OPRT))                            //�����׺���ʽ
	{
		theta=Pop(OPRT);
		if(theta=='+'||theta=='-'||theta=='*'||theta=='/')      //������������������
			printf("%c ",int(theta));
		else
			cout<<theta<<" ";
	}
	cout<<endl<<endl;
}
///////////////////=========��׺���ʽ��ֵ==========//////////////////////////
DataType Pos_Calculate(PLinkStack Exp)       //����Ϊ�����׺���ʽ��ջ����
{
	PLinkStack Calcu=Creat();                //��ʼ��һ����ջ�����׺���ʽ��������е�����
	DataType a,b,theta;                      //a,b���ڶ�ȡ��������theta���ڶ�ȡ������

	while(!isEmpty(Exp))   
	{
		theta=Pop(Exp);
		if(theta=='+' || theta=='-' || theta=='*' ||theta=='/')  //�����������������ջ��ȡ������
		{
			 b=Pop(Calcu);
			 a=Pop(Calcu); 
			 Push(Calcu,Oprate(a,theta,b));
		}
		else
			Push(Calcu,theta);      //��������ʹ�������ջ
	}
    return (Pop(Calcu));            //���ؼ�����
}
#endif