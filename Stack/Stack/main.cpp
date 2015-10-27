#include"Evaluate_Expression.cpp"
#include"Function_LinkStack.h"
#include"LinkStruct_Define.h"

int main()
{
	DataType Evaluate_Expression(char *Exp);
	//BraketMatching();
	//DataType a= Oprate(91,'+',7);
	//cout<<a<<endl;
	char p[20]={0};
	cin>>p;
	DataType sum;
	sum=Evaluate_Expression(p);
	cout<<sum<<endl;
	return 0;
}



DataType Evaluate_Expression(char *Exp)
{
	DataType a,b;
	char theta;
	PLinkStack OPRT=Creat();
	PLinkStack OPND=Creat();
	while(*Exp!='\0')
	{
		if(*Exp>='0' && *Exp<='9')
		{
			float d=0;
			while(*Exp>='0' && *Exp<='9')
			{
				d=d*10+*Exp-'0';
				Exp++;
			}
			Push(OPND,d);  
			continue;
		}
		else
		{
			if(isEmpty(OPRT))
			{
					Push(OPRT,*Exp);
					Exp++;
			}
			else
				switch(*Exp)
				{
					case '(': Push(OPRT,*Exp);Exp++;break;
					case ')': while(GetTop(OPRT)!='(')
							  {
								  theta=Pop(OPRT);b=Pop(OPND); a=Pop(OPND);
								  Push(OPND,Oprate(a,theta,b));
							  }
							  theta=Pop(OPRT);
							  Exp++; break;
					case '+':
					case '-':theta=GetTop(OPRT);
							while(theta!='(' && !isEmpty)
							 {
									theta=Pop(OPRT);b=Pop(OPND); a=Pop(OPND);
								    Push(OPND,Oprate (a,theta,b)); theta=GetTop(OPRT);
							 }//while
							 Push(OPRT,*Exp);
							 Exp++;
							 break;
					case '*':
					case '/':theta=GetTop(OPRT);
							while(theta=='*' || theta=='/')
							{
									theta=Pop(OPRT);b=Pop(OPND); a=Pop(OPND);
								    Push(OPND,Oprate (a,theta,b)); theta=GetTop(OPRT);
							}//while
							Push(OPRT,*Exp);Exp++;
				}//switch
			}//else
	}//while
	theta=Pop(OPRT);b=Pop(OPND); a=Pop(OPND);
	Push(OPND,Oprate (a,theta,b));
	return (Pop(OPND));
}
