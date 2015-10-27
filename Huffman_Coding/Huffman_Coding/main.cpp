#include"Read_File.h"
#include"Def_Huffman_Tree.h"


int main()
 {
	char chs[500];        //保存从文件中读入的字母
	int weight[27]={0};   //保存不同字母的权重
	int total_num;        //保存总的读入字母数
	int n;                //保存读入字母的种类数

	n=Read_File(&weight[0],chs,total_num);   //从文件中读入权重、字母、总字母数，并返回字母种类数
	HuffmanTree Huff_T=Init_HuffmanTree(n);  //初始化Huffman树

	cout<<"The Huffman tree are here!"<<endl;
	HuffmanCoding(Huff_T,chs,&weight[0],n,total_num);  //将读入非字母编码并写入文件

	cout<<"The letters have been coded and written into file 'code.txt'!"<<endl<<endl;
	system("pause");

	cout<<endl<<"The codes in file 'code.txt' have been decoded "<<endl
		<<" and written into file 'Trans_code.txt'!"<<endl<<endl;
	Trans_Coding(Huff_T);                  //将文件中的编码解码并写入文件
	return 0;
}