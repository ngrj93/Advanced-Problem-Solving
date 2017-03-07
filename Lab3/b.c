#include<stdio.h>
#define MOD 1000000007 

int main(){
	long long t;
	scanf("%lld",&t);
	while(t--){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		long long np;
		int flag=0;
		if((y-x)%2)
			np=(y-x+1)/2;
		else{
			flag=1;
			y=y-1;
			np=(y-x+1)/2;
		}
		np=np%MOD;
		long long first_term=((((2*np)%MOD)%MOD)*(x%MOD))%MOD;
		long long second_term=((((2*np)%MOD)%MOD)*(np%MOD))%MOD;
		long long ans=(first_term%MOD+second_term%MOD)%MOD;
		ans=(ans%MOD-np%MOD)%MOD;
		if(flag){
			y+=1;
			ans=(ans%MOD+((y%MOD)*(y%MOD))%MOD)%MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
