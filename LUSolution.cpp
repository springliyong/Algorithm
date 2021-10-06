 #include<stdio.h>

int main(){ 
	int n;
	printf("请输入n:");
	scanf("%d", &n);
	double a[n][n];
	double l[n][n], u[n][n];
	double b[n];
	double x[n], y[n];
	printf("请输入矩阵a系数：\n");
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%lf", &a[i][j]);
			
	printf("请输入b：\n");
	for(int j = 0; j < n; j++)
		scanf("%lf", &b[j]);
		
	// 得出矩阵L U
	// 1.先给l的对角线赋值1  u的第0行赋值为a的第0行 计算l的第0列 
	for(int i = 0; i < n; i++){
		u[0][i] = a[0][i];
		l[i][0] = a[i][0] / u[0][0];
		l[i][i] = 1;
	}
	// 2.计算u的第r行 l的第r列 从第1行列开始  
	double sum = 0.0;  
	for(int r = 1; r < n; r++){
		for(int j = r; j < n; j++){
			sum = 0.0;
			for(int k = 0; k <= r-1; k++)
				sum += l[r][k]*u[k][j];
			u[r][j] = a[r][j] - sum;
		}
		for(int i = r+1; i < n; i++){
			sum = 0.0;
			for(int k = 0; k <= r-1; k++)
				sum += l[i][k]*u[k][r];
			l[i][r] = (a[i][r] - sum) / u[r][r];
		}
	}	
	
	// 输出LU矩阵 
	printf("L：\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j< n; j++)
			printf("%7.2f",l[i][j]);
		printf("\n");
	}
	printf("U：\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j< n; j++)
			printf("%7.2f",u[i][j]);
		printf("\n");
	}
	
	// 由 A=b A=LU  得 Ly=b 其中Ux=y    先求出y   再求出x
	y[0] = b[0];
	for(int j = 1; j < n; j++){
		sum = 0.0;
		for(int k = 0; k <= j-1; k++)
			sum += l[j][k]*y[k];
		y[j] = b[j] - sum;
	}
	
	x[n-1] = y[n-1] / u[n-1][n-1];
	for(int i = n-2; i >=0; i--){
		sum = 0.0;
		for(int k = i; k <= n; k++)
			sum += u[i][k]*x[k];
		x[i] = (y[i] - sum) / u[i][i];
	}
	
	// 输出y矩阵 
	printf("y：\n");
	for(int i = 0; i < n; i++)
		printf("%7.2f",y[i]);
	printf("\n");

	// 输出y矩阵 
	printf("x：\n");
	for(int i = 0; i < n; i++)
		printf("%7.2f",x[i]);
	
	return 0;
}
