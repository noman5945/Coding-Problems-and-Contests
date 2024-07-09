#include <bits/stdc++.h>
using namespace std;

/*
wrong approch:
vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    int i;
    int j;
    int k;
    vector<vector<int>> ans;
    set<vector<int>> uni;

    if(n==3){
        i=0;
        j=i+1;
        k=i+2;
        if((nums[i]+nums[j]+nums[k])==0){
            ans.push_back(nums);
            return ans;
        }else{
            return ans;
        }
    }else{
        i=0;
        while(i<n){
            j=i+1;
            k=i+2;
            while(j<n && k<n){
                if((nums[i]+nums[j]+nums[k])==0){
                    uni.insert({nums[i],nums[j],nums[k]});
                }
                j++;
                k++;
            }
            i++;
        }

        for(auto tup:uni){
            ans.push_back(tup);
        }
    }
    return ans;

}
*/
// Optimized Approach - O(n^2 logn + nlogn) - o(n^2 logn) time and O(n) space
vector<vector<int>> threeSum(vector<int> &nums)
{
    int target = 0;
    sort(nums.begin(), nums.end());
    set<vector<int>> s;
    vector<vector<int>> output;
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target)
            {
                s.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
            else if (sum < target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    for (auto triplets : s)
        output.push_back(triplets);
    return output;
}

int main()
{

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
