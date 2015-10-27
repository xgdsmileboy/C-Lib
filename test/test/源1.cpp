//#include<stdio.h>
//#include<math.h>
//typedef struct zuobiao
//{
//	double a1,a2,a3,a4,a5,a6;
//}zuo;
//int main()
//{
//	zuo A[20];
//	int n,n1;
//	scanf("%d",&n);
//	n1=n;
//	//p=(zuo *)malloc(n*sizeof(zuo));
//	while(n--)
//	{
//		scanf("%lf%lf%lf%lf%lf%lf",&A[n].a1,&A[n].a2,&A[n].a3,&A[n].a4,&A[n].a5,&A[n].a6);
//		double m,n11,sum;
//		m=(A[n].a4-A[n].a2)/(A[n].a3-A[n].a1);
//        n11=(A[n].a6-A[n].a2)/(A[n].a5-A[n].a1);
//		sum=(m-n11)/(1+m*n11);
//		printf("Case %d:%lf\n",n1-n,sqrt(pow(A[n].a3-A[n].a1,2)+pow(A[n].a4-A[n].a2,2))*fabs(atan(sum)));
//	}
//	return 0;
//}