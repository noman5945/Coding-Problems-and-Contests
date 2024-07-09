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
    vector<int> test={1, 2 ,4 ,3};
    priority_queue<int,vector<int>,greater<int>> heap;

    for(int num:test){
        heap.push(num);
    }


    while(!heap.empty()){
        cout<<heap.top()<<",";
        heap.pop();
    }

}
