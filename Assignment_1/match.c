#include<stdio.h>

int main(){
	int n,m,i;
	scanf("%d%d",&n,&m);
	int original[n],changed[n];
	for(i=0;i<n;i++)
		scanf("%d",&changed[i]);
	for(i=0;i<n;i++)
		scanf("%d",&original[i]);
	int j=0,right=0;
	for(i=0;i<n;i++){
		if(original[j]==changed[i]){
			int temp=0,flag=1,k=i;
			while(temp<n){
				if(original[j]!=changed[k]){
					flag=0;
					break;
				}
				j++;k=(k+1)%n;temp++;
			}
			if(flag)
				break;
		}
		right++;
	}
	int left=n-right,flag=1;
	if(left==n)
		left=0;
	for(i=1;i<=m;i++){
		int num;
		char c;
		scanf(" %c",&c);
		scanf("%d",&num);
		if(c=='L'){
			left=(left+num)%n;
			right=right-num<0?n+(right-num):right-num;
		}
		else{
			right=(right+num)%n;
			left=left-num<0?n+(left-num):left-num;
		}
		if(left==0 || right==0){
			printf("%d\n",i);
			flag=0;
			break;
		}
	}
	if(flag)
		printf("%d\n",-1);
	return 0;
}
	
	
