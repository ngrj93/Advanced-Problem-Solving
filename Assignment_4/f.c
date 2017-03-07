#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000001
typedef struct Node Node;

struct Node{
	char left_string[26],right_string[26],middle_string[26];
	Node *children[3];
	int frequency;
};

int main(){
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		char *s=(char *)malloc(sizeof(char)*MAXSIZE);
		scanf("%s",&s);		
		Node *root=NULL;
		Node *heap=(Node*)malloc(sizeof(Node)*26);
		int string_size=strlen(s);
		int frequency[26]={0};
		for(i=0;i<string_size;i++)
			frequency[s[i]]++;
		for(i=0;i<26;i++){
			Node temp;
			memset(temp.left_string,0,sizeof(temp.left_string));
			memset(temp.right_string,0,sizeof(temp.right_string));
			char c='A'+i;
			strcpy(temp.middle_string,&c);
			temp.frequency=frequency[i];
			for(j=0;j<3;j++)
				temp.children[i]=NULL;
			heap[i]=temp;
		}
		int heapsize=27;
		build_min_heap(heap,heapsize);
		while(heapsize>0){
			extract_min(heap,heapsize);
		free(s);
	}
	return 0;
}
	
