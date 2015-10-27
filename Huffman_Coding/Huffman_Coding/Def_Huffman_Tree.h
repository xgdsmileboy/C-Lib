#ifndef DEF_HUFFMAN_TREE_H
#define DEF_HUFFMAN_TREE_H
#include<malloc.h>
#include<string.h>
#include<iostream>
using namespace std;
typedef struct {
	char letter;               //Ҷ�ӽڵ㱣����ĸ���ڲ��ڵ��ʼ��Ϊ��#��
	unsigned int weight;       //Ȩ��
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char *HuffmanCode;
///=============================================================///
HuffmanTree Init_HuffmanTree(int n)  //Huffman���ĳ�ʼ��
{
	HuffmanTree Huff_T;
	n*=2;
	if(!(Huff_T=(HuffmanTree)malloc(n*sizeof(HTNode))))  //ΪHuffman�������ڴ�ռ�
	{
		cout<<"Init Error!"<<endl;
		exit(0);
	}
	return Huff_T;
}
///============================================================///
void HuffmanCoding(HuffmanTree Huff_T,HuffmanCode Huff_C,int w[],int n,int total_num)
{                           //w���n�ֲ�ͬ�ַ���Ȩֵ��total_num�����ȡ�����ַ����������������Huff_T�������n���ַ��Ĺ���������Huff_C
	int m=2*n-1;            //���������ܽڵ�����������n��Ҷ�ӽڵ㣬n-1���ڲ��ڵ�
	int i=1,j=0,s1=0,s2=0;
	void Push_Code_to_File(char *code);
	void Select(HuffmanTree Huff_T,int n,int &s1,int &s2);
	if(n<=1) return ;

	for(i=1,j=1;i<=n&&j<Max_num;j++)     //��n����ĸ�������Huffman����ǰn���ڵ��У���ΪHuffman����Ҷ�ӽڵ�
	{ 
		if(w[j]==0) continue;
		Huff_T[i].weight=w[j];           //Ȩֵ
		Huff_T[i].lchild=0;              //��ʼ״̬���Һ��Ӻ͸�ĸ��Ϊ�㣬0�Ų���ΪHuffman���洢
		Huff_T[i].rchild=0;
		Huff_T[i].parent=0;
		Huff_T[i].letter=(char)(j+'A'-1);     //����Ȩ������Ӧ���ַ���ԭ��Huffman����
		i++;
	}
	for(;i<=m;i++)                            //��ȥǰn��Ҷ�ӽڵ㣬ʣ�½ڵ��ʼ��
	{
		Huff_T[i].weight=0;
		Huff_T[i].lchild=0;
		Huff_T[i].rchild=0;
		Huff_T[i].parent=0;
		Huff_T[i].letter='#';
	}
	for(i=n+1;i<=m;i++)
	{
		Select(Huff_T,i-1,s1,s2);     //��ǰi-1��Ԫ����ѡ��������СȨ�ؽڵ㣬�����½ڵ�
		Huff_T[s1].parent=i;          //�������ɵĽڵ㸸ĸָ��ָ�������ɵĽڵ�
		Huff_T[s2].parent=i;
		Huff_T[i].lchild=s1;          //�����ɵĽڵ�����Һ���ָ���޸�
		Huff_T[i].rchild=s2;
		Huff_T[i].weight=Huff_T[s1].weight+Huff_T[s2].weight;   //�����ɽڵ��Ȩ��Ϊ�������ɸýڵ�����ڵ��Ȩ�غ�
	}
	//=====================���Huffman��===================================================//
	cout<<"adress  "<<"weight  "<<"parent  "<<"lchild  "<<"rchild  "<<"letter  "<<endl;
	for(int w=1;w<=m;w++)
	{
		cout<<w<<"	  "<<Huff_T[w].weight<<"   	  "<<Huff_T[w].parent<<"	  "
			<<Huff_T[w].lchild<<"	  "<<Huff_T[w].rchild<<"	  "<<Huff_T[w].letter<<endl;
	}
	cout<<endl;
	//======================================================================================//
	FILE *fp0;
	fp0=fopen("code.txt","w");                             //��code.txt�ļ��е��������
	if(fp0==NULL)
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	fclose(fp0);

	int c,f;                                               //���²��ֶԴ��ļ��ж�����ַ����б��룬��������д���ļ�
	char cod[11]={'0'}, cods[11]={'0'};    
	for(i=1;i<=total_num;i++)                              //�������ַ�����
	{
		for(j=1;Huff_C[i]!=Huff_T[j].letter;j++);          //�ҵ���Ҫ�������ĸ��λ��
		cod[10]='\0';                                      //���ڵ��򱣴���ĸ�ı��룬��Ϊ��������Ǵ�Ҷ�ӽڵ�����ڵ�����
		int start=10;                                      //����ָʾ��ǰ�������cod[]��λ��
		for(c=j,f=Huff_T[j].parent;f!=0;c=f,f=Huff_T[f].parent) //��c���浱ǰ���Ƶ��Ľڵ㣬f����c�ĸ�ĸ
		{
			
			if(Huff_T[f].lchild==c)    //�ж�c��f�����ӻ����к���
				cod[--start]='0';      //�涨�����ӱ���Ϊ'0',�Һ��ӱ���Ϊ'1'
			else
				cod[--start]='1';

		}
		strcpy(cods,&cod[start]);     //����������ĸ���뱣�浽cods��
		Push_Code_to_File(cods);      //������д���ļ�����
	}
}
///=======================================================================================///
void Push_Code_to_File(char *code)    //��һ���ַ���д���ļ���
{
	FILE *fp;
	fp=fopen("code.txt","a");         //'a'Ϊ��׷�ӡ�ģʽ���ļ�
	if(fp==NULL)
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	fprintf(fp,"%s",code);
	fclose(fp);
}
///==================================================================================///
void Trans_Coding(HuffmanTree Huff_T)      //�����ļ��ж�ȡ�Ĵ��뷭����ַ�
{
	FILE *fp,*fp2;
	char code;
	int threading;

	fp2=fopen("trans_code.txt","w");       //��trans_code.txt�ļ��е��������
	if(fp2==NULL)
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	fclose(fp2);

	fp=fopen("code.txt","rt");             //�ļ�ָ��fpָ������ļ�
	fp2=fopen("trans_code.txt","a");       //�ļ�ָ��fp2ָ�����֮�󱣴���ĸ���ļ�
	if(fp==NULL||fp2==NULL)
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	if(feof(fp))                          //�жϱ����ļ��Ƿ�Ϊ��
	{
		cout<<"Empty !"<<endl;
		exit(0);
	}
	fscanf(fp,"%c",&code);               //�ӱ����ļ��ж���0��1��
	while(!feof(fp))
	{
		for(threading=1;Huff_T[threading].parent;threading++);            //Ѱ�Ҹ��ڵ�
		while(Huff_T[threading].rchild!=0 ||Huff_T[threading].lchild!=0)  //�Ӹ���ʼ�ߵ�Ҷ��
		{
			if(code=='1') threading=Huff_T[threading].rchild;             //�����ı�����'1'��rchild֧·
			else threading=Huff_T[threading].lchild;                      //������lchild֧·
			fscanf(fp,"%c",&code);                                        //ѭ������0��1��
		}
		fprintf(fp2,"%c",Huff_T[threading].letter);                       //�ߵ�Ҷ�ӽڵ㣬���ַ�д���ļ�
	}
	fclose(fp);
	fclose(fp2);
}
///==========================================================================///
void Select(HuffmanTree Huff_T,int n,int &s1,int &s2) 
{                                               //��Huffman����ǰn���ڵ���ѡ������Ȩ����С�Ľڵ㣬����λ����Ϣ��s1��s2                                  
	int i=1,lit,lit1,lit2;
	HuffmanTree p;
	for(p=Huff_T+1,s1=1;p->parent;p=p++,s1++);  //ѡ���л�û�и�ĸ�Ľڵ�
	lit1=p->weight;
	for(p++,s2=s1+1;p->parent;p++,s2++);        //ѡ���л�û�и�ĸ�Ľڵ�
	lit2=p->weight;
	if(lit1>lit2)                               //��֤lit1�б���Ľڵ��Ȩ�ز�����lit2��
	{
		lit=lit1;
		lit1=lit2;
		lit2=lit;
		lit=s1;s1=s2;s2=lit;
	}
	for(p=++Huff_T,i=1;i<=n;i++,p++)
	{
		if(i==s1 || i==s2) continue;      //s1��s2λ�ýڵ㲻����ѡ
		if(p->parent) continue;           //�Ѿ���ѡ���ڵ㣬������ѡ
		if(lit2<=p->weight) continue;     //��ǰ�ڵ��Ȩ�ر�lit1��lit2�еĽ̴�Ȩ�ػ���
		if(lit1<=p->weight)               //��ǰ�ڵ�Ȩ��λ��lit1��lit2֮��
		{                                 //ֻ���޸Ľϴ��
			lit2=p->weight;
			s2=i;	
			continue;
		}
		lit2=lit1;                        //��lit1��lit2ȫ������
		s2=s1;
		lit1=p->weight;
		s1=i;
	}
}
///==========================================================================///
#endif