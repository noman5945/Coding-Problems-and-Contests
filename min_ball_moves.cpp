#include<bits/stdc++.h>
using namespace std;

vector<int> minOperations(string boxes) {
    vector<int> moves;
    int i=0,j=0,moveCount=0;
    int n=boxes.size();

    while(i<n){
        moveCount=0;
        j=0;
        while(j<n){

            if(i==j){
                j++;
                continue;
            }
            if(boxes[j]=='1'){
                moveCount+=abs(j-i);
            }
            j++;
        }
        moves.push_back(moveCount);
        i++;
    }
    return moves;
}

int main(){
    string boxes="001011";
    vector<int> moves;
    moves=minOperations(boxes);

    for(int i=0;i<moves.size();i++){
        cout<<moves[i]<<" ";
    }
}
