#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check_bst(int preorder[],int start,int end,int* cur,int n){
	if(start>end)
		return 1;
	if(*cur<n && preorder[*cur]<=end && preorder[*cur]>=start){
		int prev=preorder[*cur];
		(*cur)++;
		int val1=check_bst(preorder,start,prev-1,cur,n);
		int val2=check_bst(preorder,prev+1,end,cur,n);
		if(val1!=-1 && val2!=-1)
			return 1;
	}
	return -1;
}

void print_postorder(int preorder[],int start,int end,int *cur,int n){
	if(start>end)
		return;
	int prev=preorder[*cur];
	(*cur)++;
	print_postorder(preorder,start,prev-1,cur,n);
	print_postorder(preorder,prev+1,end,cur,n);
	printf("%d\n",prev+1);
}
		

int main(){
	int t,q;
	scanf("%d",&t);
	for(q=1;q<=t;q++){
		int n,i,cur=0;
		scanf("%d",&n);
		int preorder[n];
		for(i=0;i<n;i++){
			scanf("%d",&preorder[i]);
			preorder[i]--;
		}
		int val=check_bst(preorder,0,n-1,&cur,n);	
		printf("Case %d:\n",q);
		if(val!=-1){
			cur=0;
			print_postorder(preorder,0,n-1,&cur,n);
		}
		else
			printf("%d\n",-1);
	}
	return 0;
}
	
