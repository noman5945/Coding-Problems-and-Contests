#include<bits/stdc++.h>
using namespace std;

int sparse_search(string a[],int n,string key){
    int s=0;
    int e=n-1;


    while(s<=e){
        int mid=(s+e)/2;
        int mid_left=mid-1;
        int mid_right=mid+1;

        if(a[mid]==""){
            while(1){
                if(mid_left<s && mid_right>e){
                    return -1;
                }
                else if(a[mid_right]!=""){
                    mid=mid_right;
                    break;
                }
                else if(a[mid_left]!=""){
                    mid=mid_left;
                    break;
                }
                mid_left--;
                mid_right++;
            }

        }
        else if(a[mid]==key){
            return mid;
        }
        else if(a[mid]>key){
            e=mid-1;
        }
        else {
            s=mid+1;
        }
    }
    return -1;
}

int main(){
    string sen[50]={"ai","","","bat","","","car","cat","","dog","",""};
    int n=12;
    string finD;
    cin>>finD;
    cout<<sparse_search(sen,n,finD);
}
