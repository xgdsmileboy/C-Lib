#ifndef GRAGH_DEF_H
#define GRAGH_DEF_H

#define MAX 1e+6
#define FALSE 0
#define TRUE 1
typedef int CostType;
typedef int DistanceType;
typedef char VertexType[15];
enum Place           //�����������еص�
{
	Athens      =1,
    Amsterdam   =2,
    Bern        =3,
    Berlin      =4,
    Brussels    =5,
    Bucharest   =6,
    Budapest    =7,
    Copenhagen  =8,
    Lisbon      =9,
    London      =10,
    Madrid      =11,
    Paris       =12,
    Prague      =13,
    Rome        =14,
    Sarajevo    =15,
    Sofia       =16,
    Skopja      =17,
    Tirane      =18,
    Vienna      =19,
    Warsaw      =20,
	MAX_VERTEX_NUM =21,
};
typedef struct
{
	DistanceType dist;    //���ؾ���
	CostType     cost;    //��һ�ص���һ�صķ���
}AdjMatrix;               //ÿ���ص����Ϣ��������ͨ�����ľ���ͷ���
typedef struct 
{
	CostType      Cost;            //���ٷ���
	DistanceType  Smallestdist;	   //���·������
	int           preplace;        //��start�ص㵽�������ص�����·����ĳһ�ص��ǰ���ص�
}Path;                             //���ڱ����й����·�������÷��õ���Ϣ
typedef struct
{
	VertexType  Place_Name[MAX_VERTEX_NUM];              //�ص�����
	AdjMatrix   arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    //�ڽӾ���
    Path        path[MAX_VERTEX_NUM];                    //���·����Ϣ
    int         Start;                                   //�����ص��ַ
	int         vexnum;                                  //�ܵĵص���
	int         arcnum;                                  //�ܵı���
}DGragh,*PDGragh;
//==========================================================//
void ShortestPath_Dij(PDGragh gragh,Place start)  //�Ͻ�˹�����㷨�����·��
{
	int place=0,place2=0,nearplace=0;
	DistanceType min;
	DistanceType Curr_dist[MAX_VERTEX_NUM];    //��ʼ�㵱ǰ����ĳһ�ص����̾���
	bool final[MAX_VERTEX_NUM];                //Ϊtrue��ʾ�õص��Ѿ�·�����
	gragh->Start=start;                        //������ʼ�ص�
	for(place=1;place<=gragh->vexnum;place++)
	{
		if(start==place) continue;
		final[place]=FALSE;                               //��ȥ��ʼ�ص�ȫ����ʼ��
		Curr_dist[place]=gragh->arcs[start][place].dist;  //��ʼ����ʼ�㵱ǰ����ĳһ�ص����̾���
		if(Curr_dist[place]<MAX)                          //����ʼ����ֱ�ӵ���ĳ�أ���¼ǰ���ص��ַ
		{
			gragh->path[place].Smallestdist=Curr_dist[place];
			gragh->path[place].preplace=start;
		}
	}//end of for
	Curr_dist[start]=0;                                    //��㵽�������Ϊ0
	gragh->path[place2].preplace=start;
	gragh->path[place2].Smallestdist=0;  
	final[start]=TRUE;                                     //�������Ѿ����
	for(place=1;place<=gragh->vexnum;place++)              //�����еص����
	{
		min=MAX;                                           //��������С�����ʼ��һ�����ֵ
		for(place2=1;place2<=gragh->vexnum;place2++)       //ɸѡ��С����ص�
	    {
		    if(!final[place2])                             //��ǰplace��������С����
				if(Curr_dist[place2]<min)
			    {
			     	nearplace=place2;                      //��¼��ǰ����С����ص�
			    	min=Curr_dist[place2];                 //������С����
			   	}
		}
		final[nearplace]=TRUE;                             //�ص�nearplace������С
		for(place2=1;place2<=gragh->vexnum;place2++)       //���������ص㵽������С����
		{
			if(!final[place2] && min+gragh->arcs[nearplace][place2].dist<Curr_dist[place2])   //��ǰplace2����ʼ��ľ���ϴ󣬸���
			{
				Curr_dist[place2]=min+gragh->arcs[nearplace][place2].dist;    //���¾�����Ϣ
				gragh->path[place2].preplace=nearplace;                       //����ǰ����Ϣ
				gragh->path[place2].Smallestdist=Curr_dist[place2];           //�������·��
			}
		}//end of for
	}//end of for
}
//============================================================================//

#endif