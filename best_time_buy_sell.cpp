#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit=0;
    int maxprofit=0;
    int n=prices.size();
    int buy=0;
    int sell=0;

    while(sell<n){
        if(prices[sell]>prices[buy]){
            profit=prices[sell]-prices[buy];
            maxprofit=max(maxprofit,profit);

        }
        else{
            buy=sell;
        }
        sell++;
    }


    return maxprofit;
}

int main(){
    vector<int> prices={7,1,5,3,6,4};
    cout<<maxProfit(prices)<<endl;
}
