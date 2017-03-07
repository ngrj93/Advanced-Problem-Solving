#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		stack<int> s;
		string str;
		cin>>str;
		unsigned int height=0;
		for(unsigned int i=0;i<str.size();i++){
			if(str[i]=='n')
				s.push(1);
			else if(str[i]=='l'){
				if(!s.empty() && s.top()==1)
					s.top()=0;
				else{
					while(!s.empty() && s.top()==0)
						s.pop();
					if(!s.empty())
						s.top()=0;
				}
			}
			height=height<s.size()?s.size():height;
		}
		cout<<height<<endl;
	}
	return 0;
}





