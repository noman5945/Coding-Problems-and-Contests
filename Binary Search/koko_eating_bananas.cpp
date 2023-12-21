#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int n=piles.size();
    int highPile=INT_MIN;
    int result;
    int st=1;
    int en;
    int mid;

    for(int idx=0;idx<n;idx++){
        highPile=max(piles[idx],highPile);
    }
    en=highPile;
    result=highPile;


    while(st<=en){
        mid=(st+en)/2;
        long int hours=0;
        for(int i=0;i<n;i++){
            hours += ceil((double) piles[i] / mid);
        }

        if(hours<=h){
            result=min(result,mid);
            en=mid-1;
        }else{
            st=mid+1;
        }
    }
    return result;
}

int main(){
    vector<int> piles={30,11,23,4,20};
    int h=8;
    cout<<minEatingSpeed(piles,h)<<endl;
}
