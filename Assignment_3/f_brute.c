#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int pid;
	struct node* next,*prev;
};

struct node *head=NULL;
struct node *tail=NULL;

void insert(int pid){
	if(tail==NULL){
		head=tail=(struct node*)malloc(sizeof(struct node));
		tail->prev=tail;
		tail->next=tail;
	}
	else{
		tail->next=(struct node*)malloc(sizeof(struct node));
		tail->next->prev=tail;
		tail=tail->next;
		tail->next=head;
		head->prev=tail;
	}
	tail->pid=pid;
}

struct node* delete(struct node* cur){
	cur->prev->next=cur->next;
	cur->next->prev=cur->prev;
	struct node* temp=cur->next;
	free(cur);
	return temp;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,p,k,i;
		scanf("%d%d%d",&n,&p,&k);
		for(i=1;i<=n;i++)
			insert(i);
		struct node* start=head;
		while(start->pid!=p)
			start=start->next;
		while(start->next!=start){
			int count=1;
			while(count<k){
				start=start->next;
				count++;
			}
			start=delete(start);
		}
		printf("%d\n",start->pid);
	}
	return 0;
}

		
