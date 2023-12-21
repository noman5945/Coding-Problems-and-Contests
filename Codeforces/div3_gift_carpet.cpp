#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    unordered_set<char> s;
    string name="akiv";
    string finaly="";
    while(t--){
        int n,m;
        cin>>n>>m;
        string temp="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c;
                cin>>c;
                temp+=c;
            }
        }

        for(int i=0;i<temp.size();i++){
            if(temp[i]=='v' || temp[i]=='i' || temp[i]=='k' || temp[i]=='a'){
                s.insert(temp[i]);
            }
        }

        for(char const& letter:s){
            finaly+=letter;
        }


        if(finaly==name){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}
