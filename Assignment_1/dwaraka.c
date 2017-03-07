#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,i;
		scanf("%d",&n);
		int height[n];
		for(i=0;i<n;i++)
			scanf("%d",&height[i]);
		int forward[n],backward[n];
		forward[0]=backward[0]=height[0];
		forward[n-1]=backward[n-1]=height[n-1];
		int max=height[0];
		for(i=1;i<n-1;i++){
			if(height[i]<=max)
				forward[i]=max;
			else{
				forward[i]=height[i];
				max=height[i];
			}
		}
		max=height[n-1];
		for(i=n-2;i>0;i--){
			if(height[i]<=max)
				backward[i]=max;
			else{
				backward[i]=height[i];
				max=height[i];
			}
		}
		long long water=0;
		for(i=0;i<n;i++){
			int cur=forward[i]>backward[i]?backward[i]:forward[i];
			water+=cur-height[i];
		}
		printf("%lli\n",water);
	}
	return 0;
}

