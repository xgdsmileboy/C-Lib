#ifndef GRAGH_DEF_H
#define GRAGH_DEF_H

#define MAX 1e+6
#define FALSE 0
#define TRUE 1
typedef int CostType;
typedef int DistanceType;
typedef char VertexType[15];
enum Place           //所包含是所有地点
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
	DistanceType dist;    //两地距离
	CostType     cost;    //从一地到另一地的费用
}AdjMatrix;               //每个地点的信息，包括相通两点间的距离和费用
typedef struct 
{
	CostType      Cost;            //最少费用
	DistanceType  Smallestdist;	   //最短路径长度
	int           preplace;        //从start地点到达其他地点的最短路径上某一地点的前趋地点
}Path;                             //用于保存有关最短路径和所用费用的信息
typedef struct
{
	VertexType  Place_Name[MAX_VERTEX_NUM];              //地点名称
	AdjMatrix   arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    //邻接矩阵
    Path        path[MAX_VERTEX_NUM];                    //最短路径信息
    int         Start;                                   //出发地点地址
	int         vexnum;                                  //总的地点数
	int         arcnum;                                  //总的边数
}DGragh,*PDGragh;
//==========================================================//
void ShortestPath_Dij(PDGragh gragh,Place start)  //迪杰斯特拉算法求最短路径
{
	int place=0,place2=0,nearplace=0;
	DistanceType min;
	DistanceType Curr_dist[MAX_VERTEX_NUM];    //起始点当前到达某一地点的最短距离
	bool final[MAX_VERTEX_NUM];                //为true表示该地点已经路径最短
	gragh->Start=start;                        //设置起始地点
	for(place=1;place<=gragh->vexnum;place++)
	{
		if(start==place) continue;
		final[place]=FALSE;                               //除去起始地点全部初始化
		Curr_dist[place]=gragh->arcs[start][place].dist;  //初始化起始点当前到达某一地点的最短距离
		if(Curr_dist[place]<MAX)                          //从起始点能直接到达某地，记录前驱地点地址
		{
			gragh->path[place].Smallestdist=Curr_dist[place];
			gragh->path[place].preplace=start;
		}
	}//end of for
	Curr_dist[start]=0;                                    //起点到自身距离为0
	gragh->path[place2].preplace=start;
	gragh->path[place2].Smallestdist=0;  
	final[start]=TRUE;                                     //起点距离已经最近
	for(place=1;place<=gragh->vexnum;place++)              //对所有地点遍历
	{
		min=MAX;                                           //将两地最小距离初始化一个最大值
		for(place2=1;place2<=gragh->vexnum;place2++)       //筛选最小距离地点
	    {
		    if(!final[place2])                             //当前place还不是最小距离
				if(Curr_dist[place2]<min)
			    {
			     	nearplace=place2;                      //记录当前的最小距离地点
			    	min=Curr_dist[place2];                 //更新最小距离
			   	}
		}
		final[nearplace]=TRUE;                             //地点nearplace距离最小
		for(place2=1;place2<=gragh->vexnum;place2++)       //更新其他地点到起点的最小距离
		{
			if(!final[place2] && min+gragh->arcs[nearplace][place2].dist<Curr_dist[place2])   //当前place2到起始点的距离较大，更新
			{
				Curr_dist[place2]=min+gragh->arcs[nearplace][place2].dist;    //更新距离信息
				gragh->path[place2].preplace=nearplace;                       //更新前驱信息
				gragh->path[place2].Smallestdist=Curr_dist[place2];           //保存最短路径
			}
		}//end of for
	}//end of for
}
//============================================================================//

#endif