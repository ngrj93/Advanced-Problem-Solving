#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1000004

int main(){
	int t,i,j;
	scanf("%d",&t);
	char *prime=(char *)malloc(sizeof(char)*MAX);
	for(i=0;i<MAX;i++)
		prime[i]='0';
	prime[1]='1';
	for(i=4;i<MAX;i+=2)
		prime[i]='1';
	for(i=3;i<MAX;i+=2){
		if(prime[i]=='0'){
			for(j=i+i;j<MAX;j+=i)
				prime[j]='1';
		}
	}
	int arr[168];
	for(i=2,j=0;i<1000;i++){
		if(prime[i]=='0')
			arr[j++]=i;
	}
	while(t--){
		long n;
		scanf("%ld",&n);
		long num=MAX,count=0;
		if(prime[n]=='0')
			num=n;
		else{
			for(i=n;i<MAX;i++){
				if(prime[i]=='0'){
					num=i;
					break;
				}
			}
		}
		if(num>=1000)
			count=1;
		else{
			count=1;
			for(i=num*num;i<MAX;i+=num){
				int flag=1;
				for(j=0;j<168;j++){
					if(arr[j]<num && i%arr[j]==0){
						flag=0;
						break;
					}
					else if(arr[j]==num)
						break;
				}
				if(flag)
					count++;
			}
		}
		printf("%ld\n",count);
	}
	return 0;
}

