#include<bits/stdc++.h>
using namespace std;

void merge_arrays(vector<vector<int>> &arrays){
    vector<int> output;
    priority_queue<int,vector<int>,greater<int>> heap;
    unordered_map<int,pair<int,int>> mp;
    for(int i=0;i<arrays.size();i++){
        int num=arrays[i][0];
        heap.push(num);
        mp[num]={0,i};
    }
    while(!heap.empty()){
        
        int num=heap.top();
        output.push_back(num);
        heap.pop();

        int nextArray=(mp[num].second)%arrays.size();
        int nextidx=(mp[num].first+1)%arrays[nextArray].size();
        int nextNum=arrays[nextArray][nextidx];
        
        if(mp[num].first+1<arrays[nextArray].size()){
            heap.push(nextNum);
            mp[nextNum]={nextidx,nextArray};
        }
    }

    for(int i=0;i<output.size();i++){
        cout<<output[i]<<endl;
    }
    
}

int main(){
    vector<vector<int>> TLR={{1,3,15},{2,4,6},{0,9,10,11}};
    merge_arrays(TLR);
}

/*
Time Complexity:O(N*K logN*K)
N=Number of arrays 
K=Number of elements in each array

Space complexity:???
*/