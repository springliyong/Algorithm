#include<stdio.h>

int main(){
	int n;
	printf("请输入n:");
	scanf("%d", &n);
	double a[n][n];
	double b[n];
	double x[n];
	printf("请输入矩阵a系数：\n");
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%lf", &a[i][j]);
			
	printf("请输入b：\n");
	for(int j = 0; j < n; j++)
		scanf("%lf", &b[j]);
	
	printf("初始输入数据：");	
	printf("\n");	
	for(int i = 0; i < n; i++){
		for(int j = 0; j< n; j++)
			printf("%6.1f",a[i][j]);
		printf("\n");
	}
		
	for(int j = 0; j < n; j++)
		printf("%6.1f", b[j]);
	
	printf("\n");
	for(int k = 1; k < n; k++){
		printf("第%d次消元数据：", k);
		printf("\n");
		for(int i = k; i < n; i++){
			double cs = a[i][k-1] / a[k-1][k-1];             
			for(int j = k-1; j < n; j++){
				printf("正在处理第%d行，第%d列，数字%4.1f, 除数cs = %4.1f, a[k-1][j]=%5.1f",i,j,a[i][j],cs, a[k-1][j]);        
				a[i][j] = a[i][j] + (-1) *  a[k-1][j] * cs; 
				printf("处理之后结果为：%6.1f", a[i][j]);
				printf("\n");
			}
			b[i] = b[i] + (-1) * b[k-1] * cs;
		}	
		printf("第%d次消元结果：", k);
		printf("\n");
		printf("系数a：\n");
		for(int i = 0; i < n; i++){
			for(int j = 0; j< n; j++)
				printf("%6.1f",a[i][j]);
			printf("\n");
		}
		printf("矩阵b：\n");
		for(int j = 0; j < n; j++)
			printf("%6.1f", b[j]);
		printf("\n");
	}	
	
	
	x[n-1] = b[n-1] / a[n-1][n-1];
	for(int i = n-2; i >= 0; i--){
		int sum=0;
		for(int j = n-1; j >= 0 ; j--){
			sum += x[j]*a[i][j]; 
//			printf("sum=%5.1f", x[j]*a[i][j]);
		}
			x[i] = (b[i] - sum) / a[i][i];
	}
	
	printf("结果x:");
	printf("\n");
	for(int i = 0; i < n; i++)
		printf("x[%d] = %5.1f",i, x[i]);

	return 0;
}
