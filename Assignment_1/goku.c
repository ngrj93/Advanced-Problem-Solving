#include<stdio.h>

int main(){
	int w,i;
	scanf("%d",&w);
	while(w--){
		long long x,y,ans=0;
		scanf("%lli%lli",&x,&y);
		int flag=0;
		for(i=31;i>=0;i--){
			if((x&((long long)1<<i)) && (y&((long long)1<<i))){
				flag=1;
				ans=ans|((long long)1<<i);
			}
			else if(!(x&((long long)1<<i)) && !(y&((long long)1<<i))){
			}
			else if(flag)
				break;
			else
				break;
		}
		printf("%lli\n",ans);
	}
	return 0;
}

