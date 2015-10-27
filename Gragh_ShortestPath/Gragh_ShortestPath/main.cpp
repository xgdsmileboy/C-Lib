#include "Read_File.h"
#include "Gragh_Def.h"

int main()
{
	void print_Prompt_Msg();                                              //输出提示信息函数
	void Print_ShotestPath(PDGragh gragh,Place start,Place destination);  //输出最短路径函数
	PDGragh gragh=Read_File();                                            //读取文件
	int start,destination;      
   	print_Prompt_Msg();
	cout<<"Please enter your starting place and destination identifier:"<<endl;
	cin>>start>>destination;
	while(start>=MAX_VERTEX_NUM||start<=0||destination>=MAX_VERTEX_NUM||destination<=0)
	{
		cout<<"There is no such place! Please enter again!"<<endl;
		cin>>start>>destination;
	}
	ShortestPath_Dij(gragh,(Place)start);                      //计算从起始点到其余地点的最短路径
	Print_ShotestPath(gragh,(Place)start,(Place)destination);  //输出
	return 0;
} 
//==========================================================================================//
void print_Prompt_Msg()                                       //输出地点名称以及所对应的地点编号
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
void Print_ShotestPath(PDGragh gragh,Place start,Place destination)      //输出最短路径
{
	int place[MAX_VERTEX_NUM]={0};
	int i,pl;
	if(start==destination)                                               //在原地
	{
		cout<<"You are just there!"<<endl;
		return ;
	}
	if(gragh->path[destination].Smallestdist>=MAX)                      //从出发地到目的地没有路径
	{
		cout<<"You can't get to "<<gragh->Place_Name[destination]
		<<" from "<<gragh->Place_Name[start]<<endl;
		return ;
	}
	cout<<"The shortest path is:"<<endl;
	gragh->path[destination].Cost=0;                                    //总费用置0
	for(i=1,pl=destination;pl!=start;pl=gragh->path[pl].preplace,i++)   //由目的地逆推到出发地，并记下路径
		place[i]=pl;
	place[i]=pl;
	/*for(int j=i;j>0;j--)
		cout<<place[j]<<"   "<<endl;*/

	for(;i>0;i--)                                                       //place[]中存储的是路径的倒序地址
	{
		cout<<gragh->Place_Name[place[i]];                              //输出路线
		if(i>1)
		{
			if(gragh->path[destination].preplace==start)
				gragh->path[destination].Cost=gragh->arcs[start][destination].cost;
			else
				gragh->path[destination].Cost+=gragh->arcs[place[i]][place[i-1]].cost;   //统计和费用
			cout<<"-->";
		}
	}
	cout<<endl;
	cout<<"The total distance is:   "<<gragh->path[destination].Smallestdist<<endl;      //最短路径距离
	cout<<"The total cost is :      "<<gragh->path[destination].Cost<<endl;              //总的费用
}
//=================================================================================================//