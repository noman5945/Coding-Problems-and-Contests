#include<bits/stdc++.h>
using namespace std;


int pertition(vector<int>& nums,int s,int e){
    int pivot=nums[e];
    int i=s-1;

    for(int j=s;j<e;j++){
        if(nums[j]<pivot){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1],nums[e]);
    return i+1;

}

int quickSelect(vector<int> nums,int s,int e,int k){

    int p=pertition(nums,s,e);
    //base case
    if(p==k){
        return nums[p];
    }else if(p>k){

        return quickSelect(nums,s,p-1,k);

    }else{
        return quickSelect(nums,p+1,e,k);
    }



}

int main(){
    vector<int> ques={1,5,8,4,8,18,9,1,56};
    int e=ques.size();
    int k,element;
    cin>>k;
    element=quickSelect(ques,0,e-1,k);
    cout<<element<<endl;
}

