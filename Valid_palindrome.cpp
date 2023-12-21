#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    
    for(int i=0;i<s.length();i++){
        s[i]=tolower(s[i]);
        if(!isalnum(s[i])){
            s[i]=' ';
        }
        
    }
    s.erase(remove(s.begin(),s.end(),' '),s.end());
    
    if(s.length()==0){return true;}
    int left=0;
    int right=s.size()-1;

    while(left<right){
        if(s[left]!=s[right]){
            cout<<left<<" "<<right<<endl;
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main(){
    string s="A man, a plan, a canal: Panama";
    string s2="race a car";
    string s3="  ";
    string s4="0P";
    if(isPalindrome(s)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}