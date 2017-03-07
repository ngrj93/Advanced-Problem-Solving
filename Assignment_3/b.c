#include<stdio.h>
#include<stdlib.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n,i,width,stack_top=-1;
		long long max_area=0,current_area;
		scanf("%lld",&n);
		long long *arr=(long long*)malloc(n*sizeof(long long));
		long long *stack=(long long*)malloc(n*sizeof(long long));
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		for(i=0;i<n;i++){
			if(stack_top==-1)
				stack[++stack_top]=i;
			else if(arr[i]>=arr[stack[stack_top]])
				stack[++stack_top]=i;
			else{
				while(stack_top>0 && arr[i]<arr[stack[stack_top]]){
					int temp=stack[stack_top--];
					width=i-stack[stack_top]-1;
					current_area=arr[temp]*width;
					if(current_area>max_area)
						max_area=current_area;
				}
				if(arr[i]<arr[stack[stack_top]]){
					long long temp=stack[stack_top--];
					current_area=arr[temp]*i;
					if(current_area>max_area)
						max_area=current_area;
				}
				stack[++stack_top]=i;
			}
		}
		while(stack_top>=0){
			long long temp=stack[stack_top--];
			if(stack_top!=-1)
				width=i-stack[stack_top]-1;
			else
				width=i;
			current_area=arr[temp]*width;
			if(current_area>max_area)
				max_area=current_area;
		}
		printf("%lld\n",max_area);
		free(arr);
		free(stack);
	}
	return 0;
}
