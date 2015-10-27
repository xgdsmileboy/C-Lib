//#ifndef EVALUATE_EXPRESSION_H
//#define EVALUATE_EXPRESSION_H
//
//#include"Function_LinkStack.h"
//
//DataType Evaluate_Expression(char *Exp)
//{
//	DataType a,b;
//	char theta;
//	PLinkStack OPRT=Creat();
//	PLinkStack OPND=Creat();
//	while(*Exp!='\0')
//	{
//		if(*Exp>='0' && *Exp<='9')
//		{
//			float d=0;
//			while(*Exp>='0' && *Exp<='9')
//			{
//				d=d*10+*Exp-'0';
//			}
//			Push(OPND,d);  
//			continue;
//		}
//		else
//		{
//			if(isEmpty(OPRT))
//			{
//					Push(OPRT,*Exp);
//					Exp++;
//			}
//			else
//				switch(*Exp)
//				{
//					case '(': Push(OPRT,*Exp);Exp++;break;
//					case ')': while(GetTop(OPRT)!='(')
//							  {
//								  theta=Pop(OPRT);b=GetTop(OPND); a=GetTop(OPND);
//								  Push(OPND,Oprate(a,theta,b));
//							  }
//							  theta=Pop(OPRT);
//							  Exp++; break;
//					case '+':
//					case '-':theta=GetTop(OPRT);
//							while(theta!='(' && !isEmpty)
//							 {
//									theta=Pop(OPRT);b=GetTop(OPND); a=GetTop(OPND);
//								    Push(OPND,Oprate (a,theta,b)); theta=GetTop(OPRT);
//							 }//while
//							 Push(OPRT,*Exp);
//							 Exp++;
//							 break;
//					case '*':
//					case '/':theta=GetTop(OPRT);
//							while(theta=='*' || theta=='/')
//							{
//									theta=Pop(OPRT);b=GetTop(OPND); a=GetTop(OPND);
//								    Push(OPND,Oprate (a,theta,b)); theta=GetTop(OPRT);
//							}//while
//							Push(OPRT,*Exp);
//				}//switch
//			}//else
//	}//while
//	theta=Pop(OPRT);b=GetTop(OPND); a=GetTop(OPND);
//	Push(OPND,Oprate (a,theta,b));
//	return (Pop(OPND));
//}
//#endif