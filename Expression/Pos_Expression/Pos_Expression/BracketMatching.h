#ifndef BRACKETMATCHING_H
#define BRACKETMATCHING_H

#include"Definition.h"

void BraketMatching(char *braket)          //检查表达式括号是否匹配的函数
{
	PLinkStack openings=Creat();           //初始化一个空的存储左括号栈
	cout<<"Examine the brackets matching..."<<endl;         //提示
	for(bool is_matched=true;is_matched && *braket!='\0';)  //循环检查括号匹配
	{
		if(*braket==')'||*braket=='('||(*braket<='9'&&*braket>='0')||*braket=='+'||*braket=='-'||*braket=='*'||*braket=='/')
		{                                                       //检查是否有不可识别字符
			if(*braket=='(')
				{Push(openings,*braket);braket++;continue;}     //左括号直接进栈
			if(*braket==')')                              
				if(isEmpty(openings))                           //右括号无左括号与之对应输出错误
				{
					cout<<"Unmatched closing bracket!"<<"	["<<*braket<<"]		"
						<<"detected."<<endl;
					exit(0);
				}//if
				else
				{
					char match;
					match=Pop(openings);                      //从操作符栈取出一个元素
					is_matched=(*braket==')'&&match=='(');    //检查括号是否匹配
					if(!is_matched)                           //不匹配，提示错误
					{
						cout<<"Bad matched  "<<match<<"  "<<*braket<<endl;
						exit(0);
					}//if
					braket++;
					continue;
				}//else
				braket++;
		}//if
		else
		{
			cout<<"The character ["<<*braket<<"] is not avialable"<<endl;   //有不可用字符，输出提示
			exit(0);
		}
	}//for
	if(!isEmpty(openings))    //判断左括号是否多余
		cout<<"Unmatched openings bracket(s) detected!"<<endl<<endl;
	else
		cout<<"Well matched!"<<endl<<endl;
}
#endif