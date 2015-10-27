#include"TSMatrix.h"
#include"Read_File.h"
int main()
{
	PTSMatrix Matrix_1=Init_TSMatrix();           //验证矩阵数据读取成功，Matrix_1保存初始矩阵
	TSMatrix_Storage(Matrix_1,"TSMatrix_1.txt");  //从TSMatrix_1.txt文件中读入矩阵
	cout<<"The original Matrix is "<<endl;
	Print_TSMatrix(Matrix_1);                     //输出
	cout<<endl;

	PTSMatrix Matrix_2=Init_TSMatrix();           //验证转置矩阵正确，Matrix_2保存Matrix_1转置后的矩阵
	Fast_Transpose_TSMatrix(Matrix_1,Matrix_2);   //矩阵转置
	cout<<"The transpose Matrix is "<<endl;
	Print_TSMatrix(Matrix_2);                     //输出
	cout<<endl;

	PTSMatrix Matrix_3=Init_TSMatrix();           //验证加法运算正确，Matrix_3保存与Matrix_1相加的矩阵
	PTSMatrix Matrix_4=Init_TSMatrix();           //Matrix_4保存矩阵Matrix_3保存与Matrix_1相加的和
	TSMatrix_Storage(Matrix_3,"TSMatrix_2.txt");
	TSMatrix_Add(Matrix_2,Matrix_3,Matrix_4);     //矩阵相加
	cout<<"The sum Matrix is "<<endl;
	Print_TSMatrix(Matrix_4);                   
	cout<<endl;

	
	PTSMatrix Matrix_5=Init_TSMatrix();               //保存矩阵的乘法结果
    TSMatrix_Multiply(Matrix_1,Matrix_2,Matrix_5);    //Matrix_1与Matrix_2（Matrix_1的转置）相乘保存到Matrix_5中
	cout<<"The multiply of these two Matrix is "<<endl;
	Print_TSMatrix(Matrix_5);
    cout<<endl;
	system("pause");

	return 0;
}