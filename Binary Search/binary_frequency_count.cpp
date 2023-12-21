#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>arr,int key){
    int s=0;
    int e=arr.size()-1;
    int ans=-1;

    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int>arr,int key){
    int s=0;
    int e=arr.size()-1;
    int ans=-1;

    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={0,1,1,1,1,1,2,2,2,4,4,4,5};
    int key;
    cin>>key;
    cout<<upperBound(arr,key)-lowerBound(arr,key)+1<<endl;
}
