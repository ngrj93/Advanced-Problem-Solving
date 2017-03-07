#include<stdio.h>
#include<stdlib.h>
#define MAX 1000001
int *el,*ind,*pre,*pos,*neg;

void quicksort(int,int);
int partition(int,int);

void quicksort(int start,int end){
	if(start<end)
	{
		int q=partition(start,end);
		quicksort(start,q-1);
		quicksort(q+1,end);
	}
}

int partition(int start,int end){
	int i=start,j=start,t1,t2,t3;
	while(j<end){
		if(el[j]<el[end] || (el[j]==el[end] && ind[j]<ind[end])){
			t1=el[j],t2=ind[j],t3=pre[j];
			el[j]=el[i];
			ind[j]=ind[i];
			pre[j]=pre[i];
			el[i]=t1;
			ind[i]=t2;
			pre[i]=t3;
			i++;
		}
		j++;
	}
	t1=el[i],t2=ind[i],t3=pre[i];
	el[i]=el[end];
	ind[i]=ind[end];
	pre[i]=pre[end];
	el[end]=t1;
	ind[end]=t2;
	pre[end]=t3;
	return i;
}

int main(){
	int n,i;
	scanf("%d",&n);
	el=(int*)malloc(n*sizeof(int));
	ind=(int*)malloc(n*sizeof(int));
	pre=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&el[i]);
		ind[i]=i;
		if(i>0 && el[i]==el[i-1])
			pre[i]=pre[i-1]+1;
		else
			pre[i]=0;
	}
	quicksort(0,n-1);
	for(i=0;i<n;i++)
		printf("%d",el[i]);
	int count=0;
	for(i=0;i<n;i++){
		if(ind[i]-i>0){
			count+=ind[i]-i-pre[i];
		}
		printf("%d\n",count);
	}
	printf("%d\n",count);
	free(el);
	free(ind);
	free(pre);
	free(pos);
	free(neg);
	return 0;
}

