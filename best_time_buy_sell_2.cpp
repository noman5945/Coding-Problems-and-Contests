#include<bits/stdc++.h>
using namespace std;

//Bottom Up DP+iteration solution
/*Time Complexity: O(n), for single level for loop
Space Complexity: O(1), for fixed size of temporary variables*/

int maxProfit(vector<int>& prices) {
        // It is impossible to sell stock on first day, set -infinity as initial value for curHold
        int curHold = INT_MIN, curNotHold = 0;
        
        for( const int stockPrice : prices ){
            
            int prevHold = curHold, prevNotHold = curNotHold;
            
            // either keep hold, or buy in stock today at stock price
            curHold = max( prevHold, prevNotHold - stockPrice );
            
            // either keep not-hold, or sell out stock today at stock price
            curNotHold = max( prevNotHold, prevHold + stockPrice );
        }
        
        // Max profit must come from notHold state finally.
        return curNotHold;
}

int main(){
    vector<int> prices={7,1,5,3,6,4};
    cout<<maxProfit(prices)<<endl;
}