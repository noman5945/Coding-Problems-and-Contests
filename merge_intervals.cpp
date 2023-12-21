#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> merge_intervals(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    int row=intervals.size();
    int i=0;

    while(i<=row-1){
        if(i<row-1 && intervals[i][1]>=intervals[i+1][0]){
            ans.push_back({intervals[i][0],intervals[i+1][1]});
            i+=2;
        }
        else{
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> ques={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans=merge_intervals(ques);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<2;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
