#include<stdio.h>
#define STR 1000000009

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,i;
		scanf("%d",&n);
		int start=0,end=n-1;
		long long sum=0;
		for(i=0;i<n;i++){	
			int j;
			long cur;
			for(j=0;j<n;j++){
				scanf("%li",&cur);
				if(start==end && j==start)
					sum=(sum+cur%STR)%STR;
				else if(j==start)
					sum=(sum+cur%STR)%STR;
				else if(j==end)
					sum=(sum+cur%STR)%STR;
			}
			start++;end--;
		}
		printf("%lli\n",sum);
	}
	return 0;
}



		
	
