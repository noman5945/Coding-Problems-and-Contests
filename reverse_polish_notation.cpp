#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    int i=0;
    int n=tokens.size();
    int ans=0;

    while(i<n){
        if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            if(tokens[i]=="+"){
                int res=op2+op1;
                st.push(res);
            }else if(tokens[i]=="-"){
                int res=op2-op1;
                st.push(res);
            }else if(tokens[i]=="*"){
                int res=op2*op1;
                st.push(res);
            }else if(tokens[i]=="/"){
                int res=op2/op1;
                st.push(res);
            }
        }
        else{
            int num=stoi(tokens[i]);
            st.push(num);
        }
        i++;
    }
    return st.top();
}

int main(){
    vector<string> notes={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<evalRPN(notes)<<endl;
}
