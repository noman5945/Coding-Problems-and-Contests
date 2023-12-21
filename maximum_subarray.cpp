#include<bits/stdc++.h>
using namespace std;


// Kadanes Algorithm

/* pseudo code

Initialize:
    max_so_far = INT_MIN
    max_ending_here = 0

Loop for each element of the array

  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far

*/

int maxSubArray(vector<int>& nums) {

    int current_max_sum=0,maxSum=INT_MIN;

    for(auto num:nums){
        current_max_sum=max(num,current_max_sum+num);
        maxSum=max(maxSum,current_max_sum);
    }
    return maxSum;

}

int main(){
    vector<int> v={-2,1,-3,4,-1,2,1,-5,4};
    int sum=maxSubArray(v);
    cout<<sum;
}
