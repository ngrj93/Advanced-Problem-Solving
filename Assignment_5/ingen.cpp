#include<bits/stdc++.h>

using namespace std;

int main(){
	srand(time(NULL));
	cout<<100000<<" "<<100000<<endl;
	for(int i=0;i<10000;i++)
		cout<<rand()%100000<<" "<<rand()%100000<<endl;
	return 0;
}
