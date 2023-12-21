#include<bits/stdc++.h>
using namespace std;

int rotated_search(vector<int> nums,int key){

    int s=0;
    int e=nums.size()-1;

    while(s<=e){
        int mid=(s+e)/2;
        if(nums[mid]==key){
            return mid+1;
        }
        else if(nums[mid]>=nums[s]){
            //L1
            if(nums[s]<=key && key<=nums[mid]){
                //left
                e=mid-1;
            }else{
                s=mid+1;
            }
        }else{
            //L2
            if(nums[mid]<=key && nums[e]>=key){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
    }
    return -1;

}

int main(){
    vector<int> arr={3,4,5,1,2};
    int key;
    cin>>key;
    cout<<rotated_search(arr,key)<<endl;
}
