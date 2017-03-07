#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	long long data;
	Node *right,*left;
	Node(long long data){
		this->data=data;
		right=left=NULL;
	}
};

class BinaryTree{
public:
	Node *head;
	long long bestsum;
	int n;

	BinaryTree(){
		head=NULL;
		bestsum=LLONG_MIN;
	}

	void insert(){
		int i=1;
		long long temp;
		cin>>n>>temp;
		queue<Node *> q;
		q.push(new Node(temp));
		head=q.front();
		while(i<n){
			Node *cur=q.front();
			q.pop();
			cin>>temp;
			if(temp!=-1){
				cur->left=new Node(temp);
				q.push(cur->left);
			}
			cin>>temp;
			if(temp!=-1){
				cur->right=new Node(temp);
				q.push(cur->right);
			}
			i+=2;
		}
	}

	long long find_max_sum(Node *start){
		if(start==NULL)
			return LLONG_MIN;
		long long largest=LLONG_MIN,largest2=LLONG_MIN;
		long long leftsum=find_max_sum(start->left);
		long long rightsum=find_max_sum(start->right);
		if(leftsum!=LLONG_MIN)
			largest=largest>leftsum+start->data?largest:leftsum+start->data;
		if(rightsum!=LLONG_MIN)
			largest=largest>rightsum+start->data?largest:rightsum+start->data;
		largest=largest>start->data?largest:start->data;
		if(leftsum!=LLONG_MIN && rightsum!=LLONG_MIN)
			largest2=rightsum+leftsum+start->data;
		bestsum=bestsum>largest?bestsum:largest;
		if(largest2!=LLONG_MIN)
			bestsum=bestsum>largest2?bestsum:largest2;
		return largest;
	}

	void delete_t(Node *start){
		if(start==NULL)
			return;
		delete_t(start->left);
		delete_t(start->right);
		delete(start);
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		BinaryTree t;
		t.insert();
		t.find_max_sum(t.head);
		cout<<t.bestsum<<endl;
		t.delete_t(t.head);
	}
	return 0;
}


