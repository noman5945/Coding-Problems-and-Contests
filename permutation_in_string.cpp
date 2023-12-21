#include<bits/stdc++.h>
using namespace std;

/* optimized solution O(n)
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n) {
            return false;
        }

        vector<int> count(26);
        for (int i = 0; i < m; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if (isPermutation(count)) {
            return true;
        }

        for (int i = m; i < n; i++) {
            count[s2[i] - 'a']--;
            count[s2[i - m] - 'a']++;
            if (isPermutation(count)) {
                return true;
            }
        }

        return false;
    }
private:
    bool isPermutation(vector<int>& count) {
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }


*/



bool checkInclusion(string s1, string s2) {
    int start=0;
    int n=s2.length()-1;
    int mainWordlen=s1.length();
    int en=mainWordlen-1;
    sort(s1.begin(),s1.end());

    while(en<=n){
        string sub=s2.substr(start,mainWordlen);
        sort(sub.begin(),sub.end());
        if(s1==sub){
            return true;
        }
        start++;
        en++;
    }

    return false;
}



int main(){
    string s1={"ab"};
    string s2={"eidboaoo"};

    cout<<checkInclusion(s1,s2)<<endl;
}
