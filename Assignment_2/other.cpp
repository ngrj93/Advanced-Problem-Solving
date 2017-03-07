#include <stdio.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <bitset>
#include <map>
using namespace std;
bitset <1000009> p;
int size;
int prime[1000000];

 void sieve()
 {
  size=0;
  long long i,j;
  p.set(0,1);
  p.set(1,1);
  prime[size++]=2;
  for(i=3;i<1000001;i=i+2){
     if(!p.test(i)){
          prime[size++]=i;
         for(j=i;j*i<1000001;j++){
            p.set(j*i,1);
        }
    }
}
}
int main()
{
 int t;
 sieve();
 scanf("%d",&t);
 int c=1;
 while(t--)
 {
  int n,j;
  int p[1000009]={0};
  scanf("%d",&n);
  int i,check=0,count=0;
  long long temp;
  map<long long ,int >mp;
  map<long long,int> :: iterator t;
  for(i=0;i<n;i++)
  {
   scanf("%lld",&temp);
   for(j=0;(j<size) && (prime[j]*prime[j]<=temp);j++)
   {
    check=0;
    while(temp%prime[j]==0)
    {
     temp/=prime[j];
     check=1;
    }
    if(check)
     mp[prime[j]]=1;
   }
   if(temp>0 && temp!=1)
    mp[temp]=1;
  }
  printf("Case #%d: %d\n",c,mp.size());
    for(t=mp.begin();t!=mp.end();t++)
        printf("%lld\n",(*t).first);
        c++;
 }
 return 0;
}
