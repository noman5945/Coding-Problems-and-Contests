#include<bits/stdc++.h>
using namespace std;

int rotated_search(vector<int> nums){

    int s=0;
    int e=nums.size()-1;

    int res=nums[0];

    while(s<=e){
        if(nums[s]<nums[e]){
            res=min(res,nums[s]);
            break;
        }

        int mid=(s+e)/2;
        res=min(res,nums[mid]);

        if(nums[mid]>=nums[s]){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return res;

}

int main(){
    vector<int> arr={3,4,5,1,2};

    cout<<rotated_search(arr)<<endl;
}

