#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	int t=5000;
	cout<<t<<endl;
	srand(time(NULL));
	for(int i=0;i<t;i++)
		cout<<rand()%1000000000<<endl;
	return 0;
}
	
		
