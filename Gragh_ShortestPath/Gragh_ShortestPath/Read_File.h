#ifndef READ_FILE_H
#define READ_FILE_H
#include"Gragh_Def.h"
#include<malloc.h>
#include<iostream>
using namespace std;

//=================================================================================//
int CharsToInt(char* chs)   //�����ļ��ж���ĵص���ת���ɶ�Ӧö����
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
void Locate(PDGragh gragh,char *Addr1,char *Addr2, int dist,int cost)   //�����ļ��ж������Ϣ��λ�÷����ڽӾ�����
{
	int addr1=CharsToInt(Addr1);                //��������ַ�����������ת����ö��int��
	int addr2=CharsToInt(Addr2);
	gragh->arcs[addr1][addr2].dist=dist;        //�ڽӾ������ؾ���
	gragh->arcs[addr1][addr2].cost=cost;        //�ڽӾ��������صķ���
	gragh->arcnum++;                            //�ܵ�·����
	/*cout<<addr1<<"      "<<addr2<<"      "<<gragh->arcs[addr1][addr2].cost
		<<" "<<gragh->arcs[addr1][addr2].dist<<endl;*/
}
//=================================================================================//
void Initial_Placename(PDGragh gragh)    //���ڽӾ����еĶ�Ӧ�ص��ʼ���ص���
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
void Initial_CostDist(PDGragh gragh)           //��ʼ�����ط��ú;���
{
	for(int i=1;i<MAX_VERTEX_NUM;i++)
	{
		for(int j=1;j<MAX_VERTEX_NUM;j++)
		{
			if(i==j)                          //ԭ�ص����ͷ��ó�ʼ��Ϊ0
			{
				gragh->arcs[i][j].dist=0;
				gragh->arcs[i][j].cost=0;
			}
			else                             //Ĭ���κ����ؾ���ͷ��úܴ�
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
PDGragh Read_File()                                //��ȡ�ļ����������ڽ��ص�������Ϣ�����ڴ�
{
	char Addr1[15],Addr2[15];
	int dist,cost;
	PDGragh Gragh=(PDGragh)malloc(sizeof(DGragh)); //����洢���ͣ�ͼ
	if(!Gragh)
	{
		cout<<"There is no space!"<<endl;
		exit(-1);
	}
	Initial_Placename(Gragh);                     //��ͼ�еĵص�����ʼ��
	Initial_CostDist(Gragh);                      //���ص��ľ���ͷ��ó�ʼ��
	FILE *fp;                                     //�ļ�ָ��
	fp=fopen("information.txt","rt");             //�򿪱���ص�;����Լ����õ��ļ�
	if(fp==NULL)
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d %d",Addr1,Addr2,&cost,&dist);        //���ļ��ж�ȡ���������ã�����
		/*cout<<Addr1<<" "<<Addr2<<" "<<cost<<" "<<dist<<endl;*/
		Locate(Gragh,Addr1,Addr2,dist,cost);                     //�����ļ��ж������Ϣ����ṹ��
	}
	return Gragh;
}
//==========================================================================//
#endif