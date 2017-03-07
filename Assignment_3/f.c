#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int solve(int n,int k){
	int ans=0,i;
	for(i=2;i<=n;i++)
		ans=(ans+k)%i;
	return ans;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,p,k;
		scanf("%d%d%d",&n,&p,&k);
		int ans=(solve(n,k)+p-1)%n+1;
		printf("%d\n",ans);
	}
	return 0;
}
