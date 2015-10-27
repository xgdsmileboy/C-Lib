#ifndef BRACKETMATCHING_H
#define BRACKETMATCHING_H

#include"Function_LinkStack.h"
#include"LinkStruct_Define.h"

void BraketMatching()
{
	PLinkStack openings=Creat();
	char symbol;
	bool is_matched=true;
	while(is_matched && (symbol=getchar())!='\n')
	{
		if(symbol=='{' || symbol=='(' || symbol=='[')
			Push(openings,symbol);
		if(symbol=='}' || symbol==')' || symbol==']')
			if(isEmpty(openings))
			{
				cout<<"Unmatched closing bracket!"<<symbol
					<<"detected."<<endl;
				is_matched=false;
			}
			else
			{
				char match;
				match=Pop(openings);
				is_matched=(symbol=='}'&&match=='{'
					      ||symbol==')'&&match=='('
					      ||symbol==']'&&match=='[');
				if(!is_matched)
					cout<<"Bad matched  "<<match<<"  "<<symbol<<endl;
			}
	}
	if(!isEmpty(openings))
		cout<<"Unmatched openings bracket(s) detected!"<<endl;
	else
		cout<<"Bracket matched!"<<endl;
}
#endif