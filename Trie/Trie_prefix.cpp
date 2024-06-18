#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char alpha;
        unordered_map<char,Node*> m;
        bool isTerminal;

        Node(char alpha){
            this->alpha=alpha;
            isTerminal=false;
        }
};

class Trie{
    public:
        Node* root;
        Trie(){
            root=new Node('\0');
        }
        void insert(string word){
            Node* temp=root;
            for(char lat:word){
                if(temp->m.count(lat)==0){
                    Node* node=new Node(lat);
                    temp->m[lat]=node;
                }
                temp=temp->m[lat];
            }
            temp->isTerminal=true;
        }
        bool search(string word){
            Node* temp=root;
            for(char lat:word){
                if(temp->m.count(lat)==0){
                    return false;
                }
                temp=temp->m[lat];
            }
            return temp->isTerminal;
        }
};

int main(){
    string words[]={"apple","ape","no","news","not","never"};
    Trie t;
    for(string word:words){
        t.insert(word);
    }

    int q;
    cin>>q;

    string query_word;
    while (q--)
    {   
        cin>>query_word;
        if(t.search(query_word)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    
}