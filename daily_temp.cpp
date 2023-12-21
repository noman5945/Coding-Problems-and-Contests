#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n=temperatures.size();
    int i=0;
    stack<pair<int,int>> stck;
    vector<int> ans;

    while(i<n){
        int currDay=i;
        int currTemp = temperatures[i];
        while(!stck.empty() && stck.top().second<currTemp){
            int prevDay = stck.top().first;
            int prevTemp = stck.top().second;
            stck.pop();

            ans[prevDay] = currDay - prevDay;
        }
        stck.push({currDay, currTemp});
        i++;
    }
    return ans;
}

int main(){
    vector<int> temp={73,74,75,71,69,72,76,73};
    vector<int> ans=dailyTemperatures(temp);
    for(auto x:ans){
        cout<<x<<" ";
    }
}
