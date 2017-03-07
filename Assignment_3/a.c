#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int id;
	int visited;
	struct node* next;
	struct node* prev;
};

struct node *front=NULL, *rear=NULL;

void enqueue(int i){
	if(front==NULL){
		front=(struct node*)malloc(sizeof(struct node));
		front->id=i;
		front->visited=0;
		front->next=front->prev=NULL;
		rear=front;
	}
	else{
		rear->next=(struct node*)malloc(sizeof(struct node));
		rear->next->prev=rear;
		rear=rear->next;
		rear->id=i;
		rear->visited=0;
		rear->next=NULL;
	}
}

void dequeue(){
	struct node* temp=front;
	front=front->next;
	free(temp);
}

int main(){
	int t,q;
	scanf("%d",&t);
	for(q=1;q<=t;q++){
		int n,m,i,j;
		scanf("%d%d",&n,&m);
		int *occupied=(int*)malloc(m*sizeof(int));
		int **completed=(int**)malloc(m*sizeof(int*));
		for(i=0;i<m;i++){
			completed[i]=(int *)malloc(n*sizeof(int));
			occupied[i]=-1;
		}
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				completed[i][j]=0;
		for(i=0;i<n;i++)
			enqueue(i);
		int cur=0,total=0,time=0;
		while(total!=n*m){
			time++;
			if(occupied[cur]!=-1){
				completed[cur][occupied[cur]]=1;
				enqueue(occupied[cur]);
				occupied[cur]=-1;
				total++;
			}
			struct node* start=front;
			while(start!=NULL){
				if(start->visited==0 && completed[cur][start->id]==0){
					occupied[cur]=start->id;
					start->visited=1;
					break;
				}
				start=start->next;
			}
			start=front;
			while(start!=NULL && start->visited!=0){
				start=start->next;
				dequeue();
			}
			cur=(cur+1)%m;
		}
		printf("Case %d: %d\n",q,time*5);
		while(front!=NULL){
			struct node*	start=front;
			front=front->next;
			free(start);
		}
		free(occupied);
		for(i=0;i<m;i++)
			free(completed[i]);
		free(completed);
	}
	return 0;
}

			
			
				
			
			


		

