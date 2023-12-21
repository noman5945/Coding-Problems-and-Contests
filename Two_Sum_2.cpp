#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    /*
    int left=0;
    int right=1;
    int n=numbers.size();

    while(right<n){
        int sum=numbers[left]+numbers[right];
        if(sum==target){
            return {left+1,right+1};
        }
        if(sum>target){
            left++;
        }
        right++;
    }

    return {};
    */
    
    /*************Better solution *************/
    int left=0;
        int right=numbers.size()-1;
        //int n=numbers.size();

    while(numbers[left]+numbers[right]!=target){
        int sum=numbers[left]+numbers[right];
        if(sum<target){
            left++;
        }else{
            right--;
        }
            
    }

    return {left+1,right+1};       
}

int main(){
    vector<int> nums={2,7,11,15},ans;
    vector<int> nums2={2,3,4};
    vector<int> nums3={-1,0};
    
    int target=-1;

    ans=twoSum(nums3,target);
    for(int num:ans){
        cout<<num<<",";
    }
}