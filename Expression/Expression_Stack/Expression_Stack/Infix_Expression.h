#include"Definition.h"

//DataType Evaluate_Expression(char *Exp)   ///中缀法表达式求值，参数为字符数组
//{
//	DataType a,b;                    //a,b用于从操作数栈中读取数据运算
//	char theta;                      //用于从操作符栈中读取运算符计算
//	OPLinkStack OPRT=OCreat();       //初始化一个空的操作符栈
//	PLinkStack OPND=Creat();         //初始化一个空的操作数栈
//	while(*Exp!='\0')                //逐一读取数组中的元素
//	{
//		if(*Exp>='0' && *Exp<='9')   //如果遇到字符是数字
//		{
//			float d=0;
//			while(*Exp>='0' && *Exp<='9')  //循环读取数据，用于读入大于10的数
//			{
//				d=d*10+*Exp-'0';
//				Exp++;
//			}
//			Push(OPND,d);                 //使操作数进栈
//			continue;
//		}
//		else
//		{
//			if(OisEmpty(OPRT))            //如果操作符栈空，直接将运算符进栈
//			{
//					OPush(OPRT,*Exp);
//					Exp++;
//			}
//			else
//				switch(*Exp)      
//				{
//					case '(': OPush(OPRT,*Exp);Exp++;break;   //遇到左括号，直接进栈
//					case ')': while(OGetTop(OPRT)!='(')       //遇到右括号则循环将操作符栈中左括号之前的运算符运算结束
//							  {
//								  theta=OPop(OPRT);
//								  b=Pop(OPND); 
//								  a=Pop(OPND);
//								  Push(OPND,Oprate(a,theta,b));   //将运算的结果保存到操作数栈中
//								  theta=OGetTop(OPRT);
//							  }
//							  theta=OPop(OPRT);                   //将左括号删除
//							  Exp++; break;
//					case '+':
//					case '-':theta=OGetTop(OPRT);
//						while(theta!='(' && !OisEmpty(OPRT))      //当遇到+或是-，则将其前边的运算符全部运算直至遇到左括号或是栈空
//							 {
//								 theta=OPop(OPRT);
//								 b=Pop(OPND); 
//								 a=Pop(OPND);
//								 Push(OPND,Oprate (a,theta,b));
//								 if(!OisEmpty(OPRT))         //如果运算符栈不空，读取栈顶元素用于下次循环判断
//									 theta=OGetTop(OPRT);
//							 }//while
//							 OPush(OPRT,*Exp);               //将当前读取的运算符进栈
//							 Exp++;
//							 break;
//					case '*':
//					case '/':theta=OGetTop(OPRT);            //如果遇到*或是/，则将其前边的*或是/运算结束
//							while((theta=='*' || theta=='/') && !OisEmpty(OPRT))
//							{
//									theta=OPop(OPRT);
//									b=Pop(OPND); 
//									a=Pop(OPND);
//								    Push(OPND,Oprate (a,theta,b)); 
//									if(!OisEmpty(OPRT))
//										theta=OGetTop(OPRT);
//							}//while
//							OPush(OPRT,*Exp);
//							Exp++;
//				}//switch
//			}//else
//	}//while
//	while(!OisEmpty(OPRT))    //将剩余未计算的预算符运算完
//	{
//		theta=OPop(OPRT);
//		b=Pop(OPND); 
//		a=Pop(OPND);
//		Push(OPND,Oprate (a,theta,b));
//	}
//	return (Pop(OPND));     //返回计算结果
//}

DataType Evaluate_Expression(char *Exp)   //中缀法表达式求值，参数为字符数组
{
	DataType a,b;                         //a,b用于从操作数栈中读取数据运算
	char theta;                           //用于从操作符栈中读取运算符计算
	PLinkStack OPRT=Creat();              //初始化一个空的操作符栈
	PLinkStack OPND=Creat();              //初始化一个空的操作数栈
	while(*Exp!='\0')                     //逐一读取数组中的元素
	{
		if(*Exp>='0' && *Exp<='9')        //如果遇到字符是数字
		{
			float d=0;
			while(*Exp>='0' && *Exp<='9') //循环读取数据，用于读入大于10的数
			{
				d=d*10+*Exp-'0';
				Exp++;
			}
			Push(OPND,d);                 //使操作数进栈
			continue;
		}
		else
		{
			if(isEmpty(OPRT))             //如果操作符栈空，直接将运算符进栈
			{
					Push(OPRT,*Exp);
					Exp++;
			}
			else
				switch(*Exp)      
				{
					case '(': Push(OPRT,*Exp);Exp++;break;   //遇到左括号，直接进栈
					case ')': while(GetTop(OPRT)!='(')       //遇到右括号则循环将操作符栈中左括号之前的运算符运算结束
							  {
								  theta=Pop(OPRT);
								  b=Pop(OPND); 
								  a=Pop(OPND);
								  Push(OPND,Oprate(a,theta,b));   //将运算的结果保存到操作数栈中
								  theta=GetTop(OPRT);
							  }
							  theta=Pop(OPRT);                    //将左括号删除
							  Exp++; break;
					case '+':
					case '-':theta=GetTop(OPRT);
						while(theta!='(' && !isEmpty(OPRT))       //当遇到+或是-，则将其前边的运算符全部运算直至遇到左括号或是栈空
							 {
								 theta=Pop(OPRT);
								 b=Pop(OPND); 
								 a=Pop(OPND);
								 Push(OPND,Oprate (a,theta,b));
								 if(!isEmpty(OPRT))         //如果运算符栈不空，读取栈顶元素用于下次循环判断
									 theta=GetTop(OPRT);
							 }//while
							 Push(OPRT,*Exp);               //将当前读取的运算符进栈
							 Exp++;
							 break;
					case '*':
					case '/':theta=GetTop(OPRT);            //如果遇到*或是/，则将其前边的*或是/运算结束
							while((theta=='*' || theta=='/') && !isEmpty(OPRT))
							{
									theta=Pop(OPRT);
									b=Pop(OPND); 
									a=Pop(OPND);
								    Push(OPND,Oprate (a,theta,b)); 
									if(!isEmpty(OPRT))
										theta=GetTop(OPRT);
							}//while
							Push(OPRT,*Exp);
							Exp++;
				}//switch
			}//else
	}//while
	while(!isEmpty(OPRT))    //将剩余未计算的预算符运算完
	{
		theta=Pop(OPRT);
		b=Pop(OPND); 
		a=Pop(OPND);
		Push(OPND,Oprate (a,theta,b));
	}
	return (Pop(OPND));    //返回计算结果
}
