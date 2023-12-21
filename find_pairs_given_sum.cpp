#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X){
    vector<pair<int,int>> ans;
    map<int,int> mp;

    for(int i=0;i<N;i++){
        int op2=abs(X-A[i]);
        mp[A[i]]=op2;
    }


    for(int i=0;i<M;i++){
        for(auto& par:mp){
            if(par.second==B[i]){
                ans.push_back(make_pair(par.first,par.second));
            }
        }
    }

    sort(ans.begin(),ans.end());

    return ans;
}

int main(){
    vector<pair<int,int>> ans;
    int A[]={1, 2, 4, 5, 7};
    int B[]={5, 6, 3, 4, 8};

    int N=sizeof(A)/sizeof(int);
    int M=sizeof(B)/sizeof(int);

    int X;
    cin>>X;
    ans=allPairs(A,B,N,M,X);

    for(auto ele:ans){
        cout<<"["<<ele.first<<","<<ele.second<<"]"<<endl;
    }

}
