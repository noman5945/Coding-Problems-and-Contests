#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num){
    string th[] ={"","M","MM","MMM"};
    string hndrd[] ={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string tens[] ={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string ones[] ={"","I","II","III","IV","V","VI","VII","VIII","IX"};

    return th[num/1000]+hndrd[(num%1000)/100]+tens[(num%100)/10]+ones[(num%10)];
}

int main(){
    int num;
    string roman;
    cin>>num;

    roman=intToRoman(num);

    cout<<roman<<endl;
}
