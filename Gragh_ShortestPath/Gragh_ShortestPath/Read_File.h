#ifndef READ_FILE_H
#define READ_FILE_H
#include"Gragh_Def.h"
#include<malloc.h>
#include<iostream>
using namespace std;

//=================================================================================//
int CharsToInt(char* chs)   //将从文件中读入的地点名转化成对应枚举量
{
	if(*chs=='A')
	{
		if(*(chs+1)=='t')       return Athens;
		else                    return Amsterdam;
	}
	else if(*chs=='B')
	{
		if(*(chs+1)=='r')       return Brussels;
		if(*(chs+3)=='n')       return Bern;
	    if(*(chs+3)=='l')       return Berlin;   
	    if(*(chs+3)=='a')       return Budapest;
		else                    return Bucharest;
	}
	else if(*chs=='C')          return Copenhagen;
	else if(*chs=='L')
	{
		if(*(chs+1)=='i')       return Lisbon;
	    else                    return London;
	}
	else if(*chs=='M')          return Madrid;
	else if(*chs=='P')
	{
		if(*(chs+1)=='a')       return Paris;
		else                    return Prague;
	}
	else if(*chs=='R')          return Rome;
	else if(*chs=='S')
	{
		if(*(chs+1)=='a')       return Sarajevo;
		if(*(chs+1)=='o')       return Sofia;
		else                    return Skopja;
	}
	else if(*chs=='T')          return Tirane;
	else if(*chs=='V')          return Vienna;
	else                        return Warsaw;
}
//===========================================================================//
void Locate(PDGragh gragh,char *Addr1,char *Addr2, int dist,int cost)   //将从文件中读入的信息按位置放入邻接矩阵中
{
	int addr1=CharsToInt(Addr1);                //将读入的字符串（地名）转换成枚举int型
	int addr2=CharsToInt(Addr2);
	gragh->arcs[addr1][addr2].dist=dist;        //邻接矩阵两地距离
	gragh->arcs[addr1][addr2].cost=cost;        //邻接矩阵中两地的费用
	gragh->arcnum++;                            //总的路径数
	/*cout<<addr1<<"      "<<addr2<<"      "<<gragh->arcs[addr1][addr2].cost
		<<" "<<gragh->arcs[addr1][addr2].dist<<endl;*/
}
//=================================================================================//
void Initial_Placename(PDGragh gragh)    //将邻接矩阵中的对应地点初始化地点名
{
	strcpy(gragh->Place_Name[1],"Athens");
    strcpy(gragh->Place_Name[2],"Amsterdam");
    strcpy(gragh->Place_Name[3],"Bern");
    strcpy(gragh->Place_Name[4],"Berlin");
    strcpy(gragh->Place_Name[5],"Brussels");
    strcpy(gragh->Place_Name[6],"Bucharest");
    strcpy(gragh->Place_Name[7],"Budapest");
    strcpy(gragh->Place_Name[8],"Copenhagen");
    strcpy(gragh->Place_Name[9],"Lisbon");
    strcpy(gragh->Place_Name[10],"London");
    strcpy(gragh->Place_Name[11],"Madrid");
    strcpy(gragh->Place_Name[12],"Paris");
    strcpy(gragh->Place_Name[13],"Prague");
    strcpy(gragh->Place_Name[14],"Rome");
    strcpy(gragh->Place_Name[15],"Sarajevo");
    strcpy(gragh->Place_Name[16],"Sofia");
    strcpy(gragh->Place_Name[17],"Skopja");
    strcpy(gragh->Place_Name[18],"Tirane");
    strcpy(gragh->Place_Name[19],"Vienna");
    strcpy(gragh->Place_Name[20],"Warsaw");
}
//================================================================================//
void Initial_CostDist(PDGragh gragh)           //初始化两地费用和距离
{
	for(int i=1;i<MAX_VERTEX_NUM;i++)
	{
		for(int j=1;j<MAX_VERTEX_NUM;j++)
		{
			if(i==j)                          //原地点距离和费用初始化为0
			{
				gragh->arcs[i][j].dist=0;
				gragh->arcs[i][j].cost=0;
			}
			else                             //默认任何两地距离和费用很大
			{
				gragh->arcs[i][j].dist=MAX;
				gragh->arcs[i][j].cost=MAX;
			}
		}
		gragh->path[i].Smallestdist=MAX; 
		gragh->path[i].Cost=0;
	}
	gragh->vexnum=MAX_VERTEX_NUM-1;
	gragh->arcnum=0;
}

///===================================================================///
PDGragh Read_File()                                //读取文件函数，用于将地点的相关信息读入内存
{
	char Addr1[15],Addr2[15];
	int dist,cost;
	PDGragh Gragh=(PDGragh)malloc(sizeof(DGragh)); //定义存储类型：图
	if(!Gragh)
	{
		cout<<"There is no space!"<<endl;
		exit(-1);
	}
	Initial_Placename(Gragh);                     //将图中的地点名初始化
	Initial_CostDist(Gragh);                      //将地点间的距离和费用初始化
	FILE *fp;                                     //文件指针
	fp=fopen("information.txt","rt");             //打开保存地点和距离以及费用的文件
	if(fp==NULL)
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d %d",Addr1,Addr2,&cost,&dist);        //从文件中读取地名，费用，距离
		/*cout<<Addr1<<" "<<Addr2<<" "<<cost<<" "<<dist<<endl;*/
		Locate(Gragh,Addr1,Addr2,dist,cost);                     //将从文件中读入的信息放入结构中
	}
	return Gragh;
}
//==========================================================================//
#endif