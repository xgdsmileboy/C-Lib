#ifndef BRACKETMATCHING_H
#define BRACKETMATCHING_H

#include"Definition.h"

//void BraketMatching(char *braket)          //检查表达式括号是否匹配的函数
//{
//	OPLinkStack openings=OCreat();           //初始化一个保存左括号的空栈
//	cout<<"Examine bracket matching..."<<endl;
//	for(bool is_matched=true;is_matched && *braket!='\0';)
//	{
//		if(*braket==')'||*braket=='('||(*braket<='9'&&*braket>='0')||*braket=='+'||*braket=='-'||*braket=='*'||*braket=='/')
//		{
//			if(*braket=='(')                 //如果是左括号直接进栈
//			{OPush(openings,*braket);braket++;continue;}
//			if(*braket==')')
//   
//				if(OisEmpty(openings))      //如果读入一个右括号却没有了左括号输出错误
//				{
//					cout<<"Unmatched closing bracket!"<<"	["<<*braket<<"]		"
//						<<"detected."<<endl;
//					exit(0);
//				}
//				else
//				{
//					char match;
//					match=OPop(openings);
//					is_matched=(*braket==')'&&match=='(');  //检查括号是否匹配
//					if(!is_matched)        //如果左右括号不匹配，输出出错信息
//					{
//						cout<<"Bad matched  "<<match<<"  "<<*braket<<endl;
//						exit(0);
//					}
//					braket++;
//					continue;
//				}
//				braket++;
//		}
//		else
//		{ cout<<"The character ["<<*braket<<"] is not avialable"<<endl;
//			exit(0);
//		}
//	}
//	if(!OisEmpty(openings))  //判断左括号是否多余
//	{cout<<"Unmatched openings bracket(s) detected!"<<endl<<endl; exit(0);}
//	else
//		cout<<"Well matched!"<<endl<<endl;
//}
void BraketMatching(char *braket)          //检查表达式括号是否匹配的函数
{
	PLinkStack openings=Creat();           //初始化一个保存左括号的空栈
	cout<<"Examine bracket matching..."<<endl;
	for(bool is_matched=true;is_matched && *braket!='\0';)
	{
		if(*braket==')'||*braket=='('||(*braket<='9'&&*braket>='0')||*braket=='+'||*braket=='-'||*braket=='*'||*braket=='/')
		{
			if(*braket=='(')              //如果是左括号直接进栈
			{Push(openings,*braket);braket++;continue;}
			if(*braket==')')
   
				if(isEmpty(openings))     //如果读入一个右括号却没有了左括号输出错误
				{
					cout<<"Unmatched closing bracket!"<<"	["<<*braket<<"]		"
						<<"detected."<<endl;
					exit(0);
				}
				else
				{
					char match;
					match=Pop(openings);
					is_matched=(*braket==')'&&match=='(');  //检查括号是否匹配
					if(!is_matched)                         //如果左右括号不匹配，输出出错信息
					{
						cout<<"Bad matched  "<<match<<"  "<<*braket<<endl;
						exit(0);
					}
					braket++;
					continue;
				}
				braket++;
		}
		else
		{ cout<<"The character ["<<*braket<<"] is not avialable"<<endl;
			exit(0);
		}
	}
	if(!isEmpty(openings))  //判断左括号是否多余
	{cout<<"Unmatched openings bracket(s) detected!"<<endl<<endl; exit(0);}
	else
		cout<<"Well matched!"<<endl<<endl;
}
#endif
