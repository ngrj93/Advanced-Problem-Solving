#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main(){
	cout<<100<<endl;
	srand(time(NULL));
	for(int i=0;i<100;i++){
		cout<<100<<endl;
		for(int j=0;j<100;j++)
			cout<<rand()%1000000000000ull+1<<" ";
		cout<<endl;
	}
}
