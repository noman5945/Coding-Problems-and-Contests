#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n=height.size();
    int max_area=INT_MIN;
    int area=0;
    int i=0;
    int j=n-1;

    while(i<j){
        area=(j-i)*min(height[j],height[i]);
        max_area=max(max_area,area);
        if(height[j]>height[i]){
            i++;
        }else if(height[j]==height[i]){
            j--;
            i++;
        }else{
            j--;
        }
    }
    return max_area;
}

int main(){
    vector<int> h={1,8,6,2,5,4,8,3,7};
    int area=maxArea(h);
    cout<<area;
}
