#include<bits/stdc++.h>
using namespace std;

void merge_(vector<int> &arr, int s, int e){
    int i=s;
    int m=(s+e)/2;
    int j=m+1;

    vector<int> temp;

    while(i<=m && j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=m){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=e){
        temp.push_back(arr[j]);
        j++;
    }

    int k=0;
    for( int idx=s;idx<=e;idx++){
        arr[idx]=temp[k++];
    }
    return;
}

void merge_sort(vector<int> &arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    merge_sort(arr,s,mid);
    merge_sort(arr,mid+1,e);
    return merge_(arr,s,e);

}

int main(){
    vector<int> nums={10,9,2,12,20,0,55,8};
    int s=0;
    int e=nums.size()-1;
    merge_sort(nums,s,e);
    for(int x:nums){
        cout<<x<<" ,";
    }
}
