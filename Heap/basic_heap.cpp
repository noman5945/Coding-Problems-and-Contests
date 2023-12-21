#include<bits/stdc++.h>
using namespace std;

class Comparator{
public:
    bool operator()(int a,int b){
        return a<b;
    }
};


int main(){
    vector<int> arr={5,8,4,1,0,-1,6};

    priority_queue<int,vector<int>,greater<int>> heap;

    for(int num:arr){
        heap.push(num);
    }


    while(!heap.empty()){
        cout<<heap.top()<<",";
        heap.pop();
    }

}
