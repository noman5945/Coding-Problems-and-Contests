#include<bits/stdc++.h>
using namespace std;

int minPartitions(string n) {
   int i=0;
   int max_=INT_MIN;
   int num=0;

   while(n[i]!='\0'){
    num=(int)n[i]-48;

    max_=max(num,max_);
    i++;
   }
   return max_;
}

int main(){
    string s;
    cin>>s;
    int m=minPartitions(s);
    cout<<m;
}
