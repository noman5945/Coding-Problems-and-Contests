#include<bits/stdc++.h>
using namespace std;
/**
 * Given an array of Boxes
 * Boxes in this array represented as (Width,Depth,Height)
 * Boxes will be stacked on top of each box in way that
 *  - A box must be "strictly smaller w,d,h than the box below it"
 *  - Maximise total height of the stack
 */
bool compareFunction(vector<int> b1,vector<int> b2){
    return b1[2]>b2[2];
}

bool canPlace(vector<int> b1,vector<int> b2){
    if(b1[0]>b2[0] && b1[1]>b2[1] && b1[2]>b2[2]){
        return  true;
    }
    return false;
}
int boxStacking(vector<vector<int>> boxes){
    sort(boxes.begin(),boxes.end(),compareFunction);

    int n=boxes.size();
    vector<int> dp(n+1,0);

    for(int i=0;i<n;i++){
        dp[i]=boxes[i][2];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(canPlace(boxes[j],boxes[i])){
                int currentHeight=boxes[i][2];
                if(dp[j]+currentHeight>dp[i]){
                    dp[i]=dp[j]+currentHeight;
                }
            }
        }
    }
    int max_height=0;
    for(int i=0;i<n;i++){
        max_height=max(dp[i],max_height);
    }
    return max_height;
}

int main(){
    vector<vector<int>> boxes={
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,2,1},
        {4,4,5},
    };
    int ans=boxStacking(boxes);
    cout<<ans<<endl;
}