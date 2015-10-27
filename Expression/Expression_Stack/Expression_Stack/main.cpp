#include"Infix_Expression.h"
#include"Pos_Expression.h"
#include"BraketMatching.h"
#include"Definition.h"
int i=1;
int main()
{
	char p[50];    //定义一个字符数组保存输入的表达式
	DataType dat;  //定义一个变量保存运算后的结果
	cout<<"[-] [+] [*] [/] [0-9] [(] [)] are available!"<<endl  //提示语句
		<<"Please enter an infix expression:"<<endl;            //提示可输入的字符
	cin>>p;              //输入表达式
	cout<<endl;
	BraketMatching(p);   //检查括号的匹配
	dat=Evaluate_Expression(p);         //执行中缀表达式计算并返回结果
	cout<<endl<<"The result is:		";  //格式化输出
	cout<<dat<<endl<<endl;              //输出结果
	PLinkStack OPRT=Creat();            //初始化一个空栈保存中缀表达式转成的后缀表达式
	i=1;
	pos_Expression(OPRT,p);             //中缀表达式转换成后缀表达式
	Pos_Print(OPRT);				    //输出后缀表达式
	pos_Expression(OPRT,p);			    //中缀表达式转换成后缀表达式
    dat=Pos_Calculate(OPRT);		    //后缀表达式计算并返回结果
	cout<<endl<<"The result is:		"<<dat<<endl;       //输出表达式计算结果
	system("pause");
	return 0;
}

