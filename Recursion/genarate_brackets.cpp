#include<bits/stdc++.h>
using namespace std;

void generateBra(string output,int n,int open,int close,int i){

    //base case
    if(i==2*n){
        cout<<output<<endl;
        return;
    }

    //open
    if(open<n){
        generateBra(output+'(',n,open+1,close,i+1);
    }

    //close
    if(close<open){
        generateBra(output+')',n,open,close+1,i+1);
    }
}

int main(){
    string output;
    int n;
    cin>>n;
    generateBra(output,n,0,0,0);

}
