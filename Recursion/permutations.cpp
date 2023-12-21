#include<bits/stdc++.h>
using namespace std;

void permutation(string& input,int i,int n){
    if(i==n){
        cout<<input<<endl;
        return;
    }
    for(int k=i;k<=n;k++){
        //swapping
        swap(input[i],input[k]);
        //recursion
        permutation(input,i+1,n);
        //backtrack (to get original form of the string)
        swap(input[i],input[k]);
    }
}

int main(){
    string input;
    cin>>input;

    int n=input.size();

    permutation(input,0,n-1);

}
