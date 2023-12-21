#include<bits/stdc++.h>
using namespace std;

int reverse_(int x) {
    int a=x;
    int rem;
    long num=0;

    while(a!=0){
        rem=a%10;
        num=num*10+rem;
        a=a/10;
    }
    return num;
}

int main(){
    int num;
    long rev;
    cin>>num;

    rev=reverse_(num);
    cout<<rev;

}
