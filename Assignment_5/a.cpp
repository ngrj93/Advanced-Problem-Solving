#include<bits/stdc++.h>

using namespace std;

class Graph{
public:
	vector<vector<int> > adj;
	vector<vector<int> > transpose;
	vector<int> indegree;
	vector<bool> visited;
	vector<int> comp;
	stack<int> st;
	
	int v;
	int comp_id;

	void input(){
		cin>>v;
		adj.resize(v);
		transpose.resize(v);
		visited.resize(v,0);
		comp.resize(v,0);
		for(int i=0;i<v;i++){
			int c,val;
			cin>>c;
			while(c--){
				cin>>val;
				val--;
				adj[i].push_back(val);
			}
		}
	}

	void dfs(int cur){
		visited[cur]=true;
		for(unsigned int i=0;i<adj[cur].size();i++){
			if(!visited[adj[cur][i]])
				dfs(adj[cur][i]);
		}
		st.push(cur);	
	}

	void transpose_dfs(){
		for(int i=0;i<v;i++)
			for(unsigned int j=0;j<adj[i].size();j++)
				transpose[adj[i][j]].push_back(i);
		fill(visited.begin(),visited.end(),false);
		comp_id=0;
		while(!st.empty()){
			int i=st.top();
			st.pop();
			if(!visited[i]){
				transpose_dfs_util(i,comp_id);
				comp_id++;
			}
		}
	}

	void transpose_dfs_util(int cur, int comp_id){
		visited[cur]=true;
		comp[cur]=comp_id;
		for(unsigned int i=0;i<transpose[cur].size();i++){
			if(!visited[transpose[cur][i]])
				transpose_dfs_util(transpose[cur][i],comp_id);
		}
	}

	void traverse(){
		indegree.resize(comp_id,0);
		for(int i=0;i<v;i++){
			for(unsigned int j=0;j<transpose[i].size();j++){
				if(comp[i]!=comp[transpose[i][j]])
					indegree[comp[transpose[i][j]]]++;
			}
		}
	}
};


int main(){
	int t;
	cin>>t;
	while(t--){
		Graph g;
		g.input();
		for(int i=0;i<g.v;i++){
			if(!g.visited[i])
				g.dfs(i);
		}
		g.transpose_dfs();
		g.traverse();
		int final_component,final_count=0;
		for(unsigned int i=0;i<g.indegree.size();i++){
			if(g.indegree[i]==0){
				final_component=i;
				final_count++;
			}
		}
		if(final_count==0 || final_count>1)
			cout<<0<<endl;
		else{
			int ans=0;
			for(int i=0;i<g.v;i++){
				if(g.comp[i]==final_component)
					ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

