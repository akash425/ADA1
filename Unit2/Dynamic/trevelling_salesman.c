#include<stdio.h>
//#include<conio.h>
int a[10][10],visited[10],n,cost=0;

void get()
{
	int i,j;
	printf("Enter No. of Cities: ");
	scanf("%d",&n);
	printf("\nEnter Cost Matrix\n");
	for(i=0;i < n;i++)
	{
		printf("\nEnter Elements of Row # : %d\n",i+1);
		for( j=0;j < n;j++)
			scanf("%d",&a[i][j]);
		visited[i]=0;
	}
	printf("\n\nThe cost list is:\n\n");
	for( i=0;i < n;i++)
	{
		printf("\n\n");
		for(j=0;j < n;j++)
			printf("\t%d",a[i][j]);
	}
}

void mincost(int city)
{
	int i,ncity;
	visited[city]=1;	
	printf("%d -->",city+1);
	ncity=least(city);
	if(ncity==999)
	{
		ncity=0;
		printf("%d",ncity+1);
		cost+=a[city][ncity];
		return;
	}
	mincost(ncity);
}

int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
	for(i=0;i < n;i++)
	{
		if((a[c][i]!=0)&&(visited[i]==0))
			if(a[c][i] < min)
			{
				min=a[i][0]+a[c][i];
				kmin=a[c][i];
				nc=i;
			}
	}
	if(min!=999)
		cost+=kmin;
	return nc;
}

void put()
{
	printf("\n\nMinimum cost:");
	printf("%d",cost);
}

void main()
{
	//clrscr();
	get();
	printf("\n\nThe Path is:\n\n");
	mincost(0);
	put();
	//getch();
}

/*
output:


Enter No. of Cities: 3

Enter Cost Matrix

Enter Elements of Row # : 1
3 5 4

Enter Elements of Row # : 2
5 1 6

Enter Elements of Row # : 3
8 5 1


The cost list is:



        3       5       4

        5       1       6

        8       5       1

The Path is:

1 -->3 -->2 -->1
*/