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

void quickSort(vector<int>& nums,int s,int e){
    //base case
    if(s>=e){
        return;
    }
    int p=pertition(nums,s,e);
    quickSort(nums,s,p-1);
    quickSort(nums,p+1,e);

}

int main(){
    vector<int> ques={3,2,3,1,2,4,5,5,6};
    int e=ques.size();
    quickSort(ques,0,e-1);
    for(int n:ques){
        cout<<n<<" ";
    }
}
