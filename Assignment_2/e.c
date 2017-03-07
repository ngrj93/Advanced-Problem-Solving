#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int lower_binary_search(int [],int,int,int);

int lower_binary_search(int arr[],int elem,int n,int m){
	int start=0;
	int end=n-1;
	int mid,best;
	while(start<=end){
		mid=(start+end)/2;
		if(elem-arr[mid]<=m){
			best=mid;
			end=mid-1;
		}
		else
			start=mid+1;
	}
	return best;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,i;
		scanf("%d%d",&n,&m);
		int arr[n+1];
		arr[0]=0;
		for(i=1;i<=n;i++)
			scanf("%d",&arr[i]);
		for(i=1;i<=n;i++)
			arr[i]+=arr[i-1];
		int pairs=0,cost=INT_MAX;
		for(i=1;i<=n;i++){
			int val=lower_binary_search(arr,arr[i],n+1,m);
			if(i-val>pairs){
				pairs=i-val;
				cost=arr[i]-arr[val];
			}
			else if(i-val==pairs){
				if(arr[i]-arr[val]<cost)
					cost=arr[i]-arr[val];
			}
		}
		if(cost==INT_MAX)
			printf("%d %d\n",0,pairs);
		else
			printf("%d %d\n",cost,pairs);
	}
	return 0;
}
				
