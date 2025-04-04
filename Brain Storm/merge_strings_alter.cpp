#include<bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
    string ans;
    int i=0,j=0,k=0;
    int small=word1.size()<word2.size()?word1.size():word2.size();
    
    while(i<small&&j<small){
        ans.push_back(word1[i++]) ;
        ans.push_back(word2[j++]) ;
        k++;
    }
    if(k<word1.length()){
        
       ans.append(word1.substr(k,word1.length()-k)); 
    }
    if(k<word2.length()){
       cout<<word2.length()-k<<endl;
        ans.append(word2.substr(k,word2.length()-k)); 
    }

    
    cout<<"last :"<<k<<endl;
    return ans;
}

int main(){
   string word1 = "abcd", word2 = "pq";
   string ans=mergeAlternately(word1,word2);
   cout<<ans<<endl;
}