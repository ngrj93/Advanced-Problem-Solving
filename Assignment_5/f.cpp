#include<bits/stdc++.h>

using namespace std;

class Graph{
public:

	vector<vector<int> > adj;
	vector<int> toposort;
	vector<int> indegree;
	queue<int> q;
	int v,e;
	bool multiple_possible_flag;

	Graph(){
		multiple_possible_flag=false;
	}

	void input(){
		cin>>v>>e;
		adj.resize(v);
		indegree.resize(v,0);
		for(int i=0;i<e;i++){
			int a,b;
			cin>>a>>b;
			a--,b--;
			adj[a].push_back(b);
			indegree[b]++;
		}
	}
	
	void topological_sort(){
		int count=0;
		for(int i=0;i<v;i++){
			if(indegree[i]==0)
				q.push(i);
		}
		while(!q.empty()){
			if(q.size()>=2)
				multiple_possible_flag=true;
			int cur=q.front();
			q.pop();
			for(unsigned int i=0;i<adj[cur].size();i++){
				indegree[adj[cur][i]]--;
				if(indegree[adj[cur][i]]==0)
					q.push(adj[cur][i]);
			}
			toposort.push_back(cur);
			count++;
		}
		if(count!=v)
			cout<<"valar morghulis"<<endl;
		else if(multiple_possible_flag==true)
			cout<<"valar dohaeris"<<endl;
		else{
			for(unsigned int i=0;i<toposort.size()-1;i++)
				cout<<toposort[i]+1<<" ";
			cout<<toposort[toposort.size()-1]+1<<endl;
		}
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		Graph g;
		g.input();
		g.topological_sort();
	}
	return 0;
}
