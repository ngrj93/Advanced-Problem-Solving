#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node *right,*left;
	Node(int data){
		this->data=data;
		right=left=NULL;
	}
};

class BinaryTree{
public:
	Node *Head;
	int n;
	int distance;
	vector<int> inorder;
	vector<int> preorder;
	
	BinaryTree(){
		Head=NULL;
		distance=0;
	}

	void input(){
		cin>>n;
		int temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			inorder.push_back(temp);
		}
		for(int i=0;i<n;i++){
			cin>>temp;
			preorder.push_back(temp);
		}
	}

	Node* create_tree(vector<int>::iterator start, vector<int>::iterator end, Node *head,int &c){
		if(c<n){
			vector<int>::iterator it=find(start,end,preorder[c]);
			if(it!=end){
				head=new Node(*it);
				c++;
				head->left=create_tree(start,it,head->left,c);
				head->right=create_tree(it+1,end,head->right,c);
			}
		}
		return head;
	}

	int diameter(Node *head){
		if(head==NULL)
			return 0;
		int left_height=height(head->left);
		int right_height=height(head->right);
		int left_diameter=diameter(head->left);
		int right_diameter=diameter(head->right);
		distance=max(distance,max(max(left_diameter,right_diameter),1+left_height+right_height));
		return max(max(left_diameter,right_diameter),1+left_height+right_height);
	}

	int height(Node *head){
		if(head==NULL)
			return 0;
		return 1 + max(height(head->left),height(head->right));
	}

	void delete_t(Node *head){
		if(head==NULL)
			return;
		delete_t(head->left);
		delete_t(head->right);
		delete(head);
	}
};
		
int main(){
	int t;
	cin>>t;
	while(t--){
		BinaryTree t;
		t.input();
		int c=0;
		t.Head=t.create_tree(t.inorder.begin(),t.inorder.end(),t.Head,c);
		t.diameter(t.Head);
		cout<<t.distance-1<<endl;
		t.delete_t(t.Head);
	}
	return 0;
}
