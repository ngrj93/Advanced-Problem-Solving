#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct Node Node;

struct Node{
	Node *arr[10];
	int visited;
};

Node* insert_trie(Node *root,char *input,int cur,int *flag){
	int i;
	if(root==NULL){
		*flag=0;
		root=(Node*)malloc(sizeof(Node));
		for(i=0;i<10;i++)
			root->arr[i]=NULL;
		root->visited=0;
	}
	else
		*flag=1;
	if(root->visited==1){
		*flag=1;
		return NULL;
	}
	if(input[cur]=='\0')
		root->visited=1;
	else{
		int index=input[cur]-'0';
		root->arr[index]=insert_trie(root->arr[index],input,cur+1,flag);
	}
	return root;
}

void delete_trie(Node *root){
	int i;
	if(root!=NULL){
		for(i=0;i<10;i++)
			delete_trie(root->arr[i]);
		free(root);
	}
}

int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		int n,flag=0;
		Node *root=(Node*)malloc(sizeof(Node));
		for(i=0;i<10;i++)
			root->arr[i]=NULL;
		root->visited=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			char s[12];
			scanf(" %s",s);
			int index=s[0]-'0';
			if(flag==0)
				root->arr[index]=insert_trie(root->arr[index],s,1,&flag);
		}
		if(flag==0)
			printf("YES\n");
		else
			printf("NO\n");
		delete_trie(root);
	}
	return 0;
}



