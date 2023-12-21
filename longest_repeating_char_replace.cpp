#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int longest=0;
    int res=0;
    int n=s.length();
    int en=0;
    int start=0;
    vector<int> freq(26);

    while(en<n){
        freq[s[en]-'A']++;
        longest=max(longest,freq[s[en]-'A']);

        if((en-start+1)-longest>k){
            freq[s[start]-'A']--;
            start++;
        }
        res=max(res,(en-start+1));
        en++;
    }

    return res;
}

int main(){
    string sen;
    int k;
    cin>>sen>>k;
    cout<<characterReplacement(sen,k)<<endl;

}
