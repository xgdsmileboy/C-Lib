#include "Read_File.h"
#include "Gragh_Def.h"

int main()
{
	void print_Prompt_Msg();                                              //�����ʾ��Ϣ����
	void Print_ShotestPath(PDGragh gragh,Place start,Place destination);  //������·������
	PDGragh gragh=Read_File();                                            //��ȡ�ļ�
	int start,destination;      
   	print_Prompt_Msg();
	cout<<"Please enter your starting place and destination identifier:"<<endl;
	cin>>start>>destination;
	while(start>=MAX_VERTEX_NUM||start<=0||destination>=MAX_VERTEX_NUM||destination<=0)
	{
		cout<<"There is no such place! Please enter again!"<<endl;
		cin>>start>>destination;
	}
	ShortestPath_Dij(gragh,(Place)start);                      //�������ʼ�㵽����ص�����·��
	Print_ShotestPath(gragh,(Place)start,(Place)destination);  //���
	return 0;
} 
//==========================================================================================//
void print_Prompt_Msg()                                       //����ص������Լ�����Ӧ�ĵص���
{
	cout<<"Places identifiers"<<endl;
	cout<<"Athens      =1        "<<"Madrid      =11"<<endl
        <<"Amsterdam   =2        "<<"Paris       =12"<<endl
		<<"Bern        =3        "<<"Prague      =13"<<endl
		<<"Berlin      =4        "<<"Rome        =14"<<endl
		<<"Brussels    =5        "<<"Sarajevo    =15"<<endl
		<<"Bucharest   =6        "<<"Sofia       =16"<<endl
		<<"Budapest    =7        "<<"Skopja      =17"<<endl
		<<"Copenhagen  =8        "<<"Tirane      =18"<<endl
		<<"Lisbon      =9        "<<"Vienna      =19"<<endl
		<<"London      =10       "<<"Warsaw      =20"<<endl;
}
//===========================================================================================//
void Print_ShotestPath(PDGragh gragh,Place start,Place destination)      //������·��
{
	int place[MAX_VERTEX_NUM]={0};
	int i,pl;
	if(start==destination)                                               //��ԭ��
	{
		cout<<"You are just there!"<<endl;
		return ;
	}
	if(gragh->path[destination].Smallestdist>=MAX)                      //�ӳ����ص�Ŀ�ĵ�û��·��
	{
		cout<<"You can't get to "<<gragh->Place_Name[destination]
		<<" from "<<gragh->Place_Name[start]<<endl;
		return ;
	}
	cout<<"The shortest path is:"<<endl;
	gragh->path[destination].Cost=0;                                    //�ܷ�����0
	for(i=1,pl=destination;pl!=start;pl=gragh->path[pl].preplace,i++)   //��Ŀ�ĵ����Ƶ������أ�������·��
		place[i]=pl;
	place[i]=pl;
	/*for(int j=i;j>0;j--)
		cout<<place[j]<<"   "<<endl;*/

	for(;i>0;i--)                                                       //place[]�д洢����·���ĵ����ַ
	{
		cout<<gragh->Place_Name[place[i]];                              //���·��
		if(i>1)
		{
			if(gragh->path[destination].preplace==start)
				gragh->path[destination].Cost=gragh->arcs[start][destination].cost;
			else
				gragh->path[destination].Cost+=gragh->arcs[place[i]][place[i-1]].cost;   //ͳ�ƺͷ���
			cout<<"-->";
		}
	}
	cout<<endl;
	cout<<"The total distance is:   "<<gragh->path[destination].Smallestdist<<endl;      //���·������
	cout<<"The total cost is :      "<<gragh->path[destination].Cost<<endl;              //�ܵķ���
}
//=================================================================================================//