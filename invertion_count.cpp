#include<bits/stdc++.h>
using namespace std;

int invertion_count(vector<int> &arr, int s, int e){
    int i=s;
    int m=(s+e)/2;
    int j=m+1;

    vector<int> temp;
    int cnt=0;

    while(i<=m && j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            cnt+=(m-i+1);
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
    return cnt;
}

int invertion(vector<int> &arr, int s, int e){
    if(s>=e){
        return 0;
    }

    int m=(s+e)/2;
    int c1=invertion(arr,s,m);
    int c2=invertion(arr,m+1,e);
    int ci=invertion_count(arr,s,e);
    return c1+c2+ci;
}

int main(){
    vector<int> nums={0,5,2,3,1};
    int s=0;
    int e=nums.size()-1;
    int inv=invertion(nums,s,e);
    cout<<" "<<inv;

}
