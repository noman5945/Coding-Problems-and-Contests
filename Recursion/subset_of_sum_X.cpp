#include<bits/stdc++.h>
using namespace std;

int subsetSum(vector<int>& arr,int n,int i,int X,string tracker){

    cout<<i<<" "<<X<<" "<<tracker<<endl;
    //base case
    if(i==n){
        if(X==0){
            return 1;
        }
        else{
            return 0;
        }
    }

    // recursive op
    int inc=subsetSum(arr,n,i+1,X-arr[i],"Including i");
    int exc=subsetSum(arr,n,i+1,X,"Excluding i");
    return inc+exc;
}


int main(){
    vector<int> num={1,2,3,4,5};
    int sum=6;
    int n=num.size();
    cout<<subsetSum(num,n,0,sum,"Initial call")<<endl;
}
