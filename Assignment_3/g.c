#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 3000

void max_in_window1(int **arr,int row,int n,int s){
	int i;
	int *dequeue=(int *)malloc(n*sizeof(int));
	int front=-1,rear=-1;
	for(i=0;i<s;i++){
		if(front==-1){
			dequeue[++front]=i;
			++rear;
		}
		else{
			while(rear!=-1 && arr[row][i]>=arr[row][dequeue[rear]])
				rear--;
			dequeue[++rear]=i;
		}
	}
	int j=0;
	for(;i<n;i++){
		arr[row][j++]=arr[row][dequeue[front]];
		if(dequeue[front]<=i-s)
			front++;
		while(rear!=front-1 && arr[row][i]>=arr[row][dequeue[rear]])
			rear--;
		dequeue[++rear]=i;
	}
	arr[row][j++]=arr[row][dequeue[front]];
	free(dequeue);
}
		
void max_in_window2(int **arr,int col,int n,int s){
	int i;
	int *dequeue=(int *)malloc(n*sizeof(int));
	int front=-1,rear=-1;
	for(i=0;i<s;i++){
		if(front==-1){
			dequeue[++front]=i;
			++rear;
		}
		else{
			while(rear!=-1 && arr[i][col]>=arr[dequeue[rear]][col])
				rear--;
			dequeue[++rear]=i;
		}
	}
	int j=0;
	for(;i<n;i++){
		arr[j++][col]=arr[dequeue[front]][col];
		if(dequeue[front]<=i-s)
			front++;
		while(rear!=front-1 && arr[i][col]>=arr[dequeue[rear]][col])
			rear--;
		dequeue[++rear]=i;
	}
	arr[j++][col]=arr[dequeue[front]][col];
	free(dequeue);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,s,p,q,j,i;
		scanf("%d%d%d%d",&n,&s,&p,&q);
		int **arr=(int**)malloc(sizeof(int*)*n);
		for(i=0;i<n;i++)
			arr[i]=(int*)malloc(sizeof(int)*n);
		int *a1=(int*)malloc(sizeof(int)*n);
		int *a2=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&a1[i]);
		for(i=0;i<n;i++)
			scanf("%d",&a2[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				arr[i][j]=(a1[i]*(i+1)+a2[j]*(j+1)+p)%q;
		free(a1);
		free(a2);
		for(i=0;i<n;i++)
			max_in_window1(arr,i,n,s);
		for(i=0;i<=n-s;i++)
			max_in_window2(arr,i,n,s);
		long long sum=0;
		for(i=0;i<=n-s;i++)
			for(j=0;j<=n-s;j++)
				sum+=arr[i][j];
		printf("%lld\n",sum);
		for(i=0;i<n;i++)
			free(arr[i]);
		free(arr);
	}
	return 0;
}
