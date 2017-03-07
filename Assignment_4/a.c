#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node Node;

struct Node{
	int data;
	Node *left,*right;
	int visited;
};

Node* insert(int value,Node *root){
	if(root==NULL){
		root=(Node*)malloc(sizeof(Node));
		root->data=value;
		root->left=root->right=NULL;
	}
	else if(value<=root->data)
		root->left=insert(value,root->left);
	else
		root->right=insert(value,root->right);
	return root;
}

void find (int value1,int value2,Node *root){
	if(root==NULL)
		return;
	else if(root->data==value1||root->data==value2)
		printf("%d\n",root->data);
	else if(value1<root->data && value2<root->data)
		find(value1,value2,root->left);
	else if(value1>root->data && value2>root->data)
		find(value1,value2,root->right);
	else
		printf("%d\n",root->data);
}

void delete_tree(Node *root){
	if(root!=NULL){
		delete_tree(root->left);
		delete_tree(root->right);
		free(root);
	}
}

int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		int n,q,temp;
		Node *root=NULL;
		scanf("%d%d",&n,&q);
		for(i=0;i<n;i++){
			scanf("%d",&temp);
			root=insert(temp,root);
		}
		for(i=0;i<q;i++){
			int f1,f2;
			scanf("%d%d",&f1,&f2);
			find(f1,f2,root);
		}
		delete_tree(root);
	}
	return 0;
}
