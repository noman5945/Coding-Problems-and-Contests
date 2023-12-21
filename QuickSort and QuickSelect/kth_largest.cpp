#include<bits/stdc++.h>
using namespace std;
/*
int partition(vector<int> &nums,int low,int high){
        int pivot = nums[low] , i = low , j = high;

        while(i < j){
            while(i <= high && nums[i] <= pivot)i++;
            while(j >= low && nums[j] > pivot)j--;
            if(i < j)swap(nums[i],nums[j]);
        }

        swap(nums[low] , nums[j]);
        return j;
    }
    void quicks(vector<int> &nums,int low,int high,int k,int &ans){
        if(low < high){
            int pIndx = partition(nums,low,high);
            if(pIndx == k){
                ans = nums[k];
                return;
            }
            else if(pIndx < k)quicks(nums,pIndx+1,high,k,ans);
            else quicks(nums,low,pIndx-1,k,ans);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int ans = 0;
        quicks(nums,0,nums.size()-1,nums.size()-k,ans);
        return nums[nums.size()-k];
    }
*/

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int e=nums.size();
    int pos=e-k;
    return nums[pos];
}

int main(){
    vector<int> ques={3,2,1,5,6,4};

    int k,element;

    cin>>k;

    element=findKthLargest(ques,k);
    cout<<element<<endl;
}
