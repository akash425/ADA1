#include<stdio.h>
//#include<conio.h>
#define MAX 10

void main()
{
	char ele[MAX][MAX];
	int w[MAX][MAX], c[MAX][MAX], r[MAX][MAX], p[MAX], q[MAX];
	int temp=0, root, min, min1, n;
	int i,j,k,b;	
	//clrscr();
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("\n");
	for(i=1; i <= n; i++)
	{
		printf("Enter the Element of %d:",i);
		scanf("%d",&p[i]);
	}
	printf("\n");
	for(i=0; i <= n; i++)
	{
		printf("Enter the Probability of %d:",i);
		scanf("%d",&q[i]);
	}
	printf("W\t\tC\t\tR\n");	
	for(i=0; i <= n; i++)
	{
		for(j=0; j <= n; j++)
		{
			if(i == j)
			{
				w[i][j] = q[i];
			 	c[i][j] = 0;
				r[i][j] = 0;
				printf("W[%d][%d]: %d\tC[%d][%d]: %d\tR[%d][%d]: %d\n",i,j,w[i][j],i,j,c[i][j],i,j,r[i][j]);
			}
		}
	}
	printf("\n");
	for(b=0; b < n; b++)
	{
		for(i=0,j=b+1; j < n+1 && i < n+1; j++,i++)
		{
			if(i!=j && i < j)
			{
				w[i][j] = p[j] + q[j] + w[i][j-1];
				
				min = 30000;
				for(k = i+1; k <= j; k++)
				{
					min1 = c[i][k-1] + c[k][j] + w[i][j];
					if(min > min1)
					{
						min = min1;
						temp = k;
					}
				}
				c[i][j] = min;
				r[i][j] = temp;
			}
			printf("W[%d][%d]: %d\tC[%d][%d]: %d\tR[%d][%d]: %d\n",i,j,w[i][j],i,j,c[i][j],i,j,r[i][j]);
		}
		printf("\n");
	}
	printf("Minimum cost = %d\n",c[0][n]);
	root = r[0][n];
	printf("Root  = %d \n",root);
	//getch();
}



/*
Enter the number of elements:6

Enter the Element of 1:10
Enter the Element of 2:3
Enter the Element of 3:9
Enter the Element of 4:2
Enter the Element of 5:0
Enter the Element of 6:10

Enter the Probability of 0:5
Enter the Probability of 1:6
Enter the Probability of 2:4
Enter the Probability of 3:4
Enter the Probability of 4:3
Enter the Probability of 5:8
Enter the Probability of 6:0
W		C		R
W[0][0]: 5	C[0][0]: 0	R[0][0]: 0
W[1][1]: 6	C[1][1]: 0	R[1][1]: 0
W[2][2]: 4	C[2][2]: 0	R[2][2]: 0
W[3][3]: 4	C[3][3]: 0	R[3][3]: 0
W[4][4]: 3	C[4][4]: 0	R[4][4]: 0
W[5][5]: 8	C[5][5]: 0	R[5][5]: 0
W[6][6]: 0	C[6][6]: 0	R[6][6]: 0

W[0][1]: 21	C[0][1]: 21	R[0][1]: 1
W[1][2]: 13	C[1][2]: 13	R[1][2]: 2
W[2][3]: 17	C[2][3]: 17	R[2][3]: 3
W[3][4]: 9	C[3][4]: 9	R[3][4]: 4
W[4][5]: 11	C[4][5]: 11	R[4][5]: 5
W[5][6]: 18	C[5][6]: 18	R[5][6]: 6

W[0][2]: 28	C[0][2]: 41	R[0][2]: 1
W[1][3]: 26	C[1][3]: 39	R[1][3]: 3
W[2][4]: 22	C[2][4]: 31	R[2][4]: 3
W[3][5]: 17	C[3][5]: 26	R[3][5]: 5
W[4][6]: 21	C[4][6]: 32	R[4][6]: 6

W[0][3]: 41	C[0][3]: 79	R[0][3]: 2
W[1][4]: 31	C[1][4]: 53	R[1][4]: 3
W[2][5]: 30	C[2][5]: 56	R[2][5]: 3
W[3][6]: 27	C[3][6]: 53	R[3][6]: 6

W[0][4]: 46	C[0][4]: 96	R[0][4]: 3
W[1][5]: 39	C[1][5]: 78	R[1][5]: 3
W[2][6]: 40	C[2][6]: 89	R[2][6]: 4

W[0][5]: 54	C[0][5]: 121	R[0][5]: 3
W[1][6]: 49	C[1][6]: 115	R[1][6]: 3

W[0][6]: 64	C[0][6]: 158	R[0][6]: 3

Minimum cost = 158
Root  = 3

*/