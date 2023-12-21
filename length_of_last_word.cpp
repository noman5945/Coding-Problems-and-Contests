#include<bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {
        int n=s.size();
        int len=0;
        int i=0;
        int j=i+1;

        while(j<n){
            if(s[j]==' '){
                i=j+1;
            }else{
                len=j-i;
            }
            j++;
        }
        return len+1;
}

/*
better solution
        stack<char> st;
       int x=0;
        int n = s.length();
       while(s[n] == ' '){
           n--;
       }
       for(int i=s.length()-1; i>=0; i--){
           char ch  = s[i];

           if(s[i]!=' '){

               st.push(ch);
           }
           else if(s[i]==' ' && !st.empty()){

              break;

           }
       }
        x = st.size();

       return x;
    }
*/

int main(){
    string s="Hello World";
    cout<<lengthOfLastWord(s)<<endl;
}
