#include<bits/stdc++.h>
using namespace std;

//GP=Geomatric Progression

void count_GP_triplets(vector<int> v,int r){
    unordered_map<long,long> left_freq;
    unordered_map<long,long> right_freq;
    int ans=0;
    
    for(int i=0;i<v.size();i++){
        right_freq[v[i]]++;
        left_freq[v[i]]=0;
    }

    for(int i=0;i<v.size();i++){
        right_freq[v[i]]--;
        
        if(v[i]%r==0){
            long left=v[i]/r;
            long middle=v[i];
            long right=v[i]*r;

            cout<<left_freq[left]<<"---"<<middle<<"---"<<right_freq[right]<<endl;

            ans += left_freq[left]*right_freq[right];

        }
        left_freq[v[i]]++;

    }

    cout<<ans<<endl;


}

int main(){
    vector<int> numbers={1,16,4,16,64,16};
    int ratio=4;
    count_GP_triplets(numbers,ratio);
}