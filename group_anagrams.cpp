#include<bits/stdc++.h>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> mp;
    int i=0;
    while(i<strs.size()){
        string s=strs[i];
        sort(strs[i].begin(),strs[i].end());
        mp[strs[i]].push_back(s);
        i++;
    }

    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}
int main(){
    vector<string> ques={"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans=groupAnagrams(ques);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
