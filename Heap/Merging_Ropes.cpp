#include<bits/stdc++.h>
using namespace std;

class minComp{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};

/* just return the lowest sum of given array*/
void merge_ropes(vector<int> &arr){
    priority_queue<int,vector<int>,minComp> min_heap(arr.begin(),arr.end());
    int min_sum=0;

    while(min_heap.size()>1){
        int num1=min_heap.top();
        min_heap.pop();

        int num2=min_heap.top();
        min_heap.pop();

        cout<<num1<<" "<<num2<<endl;

        int new_min=num1+num2;
        min_sum+=new_min;
        min_heap.push(new_min);
    }
    cout<<min_sum<<endl;
}

int main(){
    vector<int> arr={4,3,2,6};
    merge_ropes(arr);
}
