#include<bits/stdc++.h>
using namespace std;

bool hasRedundend(string str){
    stack<char> st;

    for(char ch:str){
        if(ch!=')'){
            st.push(ch);
        }
        else{
            bool operator_found=false;
            while(!st.empty() && st.top()!='('){
                char top=st.top();
                if(top=='+' || top=='-' || top=='*' || top=='/' ){
                    operator_found=true;
                }
                st.pop();
            }
            st.pop();
            if(operator_found==false){
                return true;
            }
        }

    }
    return false;
}

int main(){
    string exp;
    cin>>exp;
    string des=hasRedundend(exp)? "Yes":"No";
    cout<<des<<endl;
}
