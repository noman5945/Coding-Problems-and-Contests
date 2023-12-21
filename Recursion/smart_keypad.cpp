#include<bits/stdc++.h>
using namespace std;

string keypad[]={"","","ABC","DEF","GHI","JKL","MNO","PQES","TUV","WXYZ"};

void printPossibleLetters(string input,string output,int i){

    if(input[i]=='\0'){
        cout<<output<<endl;
        return;
    }
    int current_digit=input[i]-'0';
    if(current_digit==0 || current_digit==1){
        printPossibleLetters(input,output,i+1);
    }

    for( int k=0;k<keypad[current_digit].size();k++){
        printPossibleLetters(input,output+keypad[current_digit][k],i+1);
    }
    return;
}

int main(){
    string input;
    cin>>input;
    string output="";
    printPossibleLetters(input,output,0);
}
