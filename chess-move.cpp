#include<bits/stdc++.h>
using namespace std;

void solution(){
    string pos;
    cin>>pos;
    
    int row=pos[1]-'0';
    vector<string> moveSet;
    string nextPosCol;
    string nextPosRow;

    for(int i=1;i<8;i++){
        if(row!=i){
            nextPosRow=string(1,pos[0])+to_string(i);
            moveSet.push_back(nextPosRow);
        }
    }

    for(char c='a'; c<='h';c++){
        if(pos[0]!=c){
            nextPosCol=string(1,c)+to_string(row);
            moveSet.push_back(nextPosCol);
        }
    }

    for(auto &prob:moveSet){
        cout<<prob<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solution();
    }
}