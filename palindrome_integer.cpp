#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    int a=x;
    int rem;
    long num=0;

    if(x<0){
        return false;
    }

    while(a!=0){
        rem=a%10;
        num=num*10+rem;
        a=a/10;
    }

    if(x/num==1){
        return true;
    }

    return false;
}

int main(){
    int num;
    bool rev;
    cin>>num;

    rev=isPalindrome(num);
    if(rev){
        cout<<"true";
    }else{
        cout<<"false";
    }

}

