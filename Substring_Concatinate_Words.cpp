#include<bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    string concat_sub="";
    unordered_map<string,int> word_freq;
    
    if(s.empty() || words.empty()){
        return {};
    }
    
    for(string word:words){
        word_freq[word]++;
        concat_sub+=word;
    }
    int word_len=words[0].length();
    int sub_len=concat_sub.length();
    int left=0;
    
    while(left<s.size()-sub_len){
        string temp=s.substr(left,sub_len);
        int i=0;
        unordered_map<string,int> seen;
        while(i<temp.size()){
            string smol_word=temp.substr(i,word_len);
            
            if(word_freq.find(smol_word)!=word_freq.end()){
                seen[smol_word]++;
                if(seen[smol_word]>word_freq[smol_word]){
                    break;
                }
            }else{
                break;
            }
            i+=word_len;
        }
        
        if(i==sub_len){
           ans.push_back(left); 
        }
        left++;
    }

    return ans;
}

int main(){
    vector<string> words={"foo","bar"};
    vector<string> words2={"bar","foo","the"};
    vector<string> words3={"word","good","best","word"};

    string s="barfoothefoobarman";
    string s2="barfoofoobarthefoobarman";
    string s3="wordgoodgoodgoodbestword";
    
    vector<int> ans=findSubstring(s,words);
    
    for(int ele:ans){
        cout<<ele<<" ";
    }
}