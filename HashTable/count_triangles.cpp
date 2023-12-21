#include<bits/stdc++.h>
using namespace std;

class coordinates{
public:
    int x;
    int y;

    coordinates(){
        this->x=0;
        this->y=0;
    }

    coordinates(int x,int y){
        this->x=x;
        this->y=y;
    }
};

class Compare{
public:
    bool operator()(const coordinates c1,const coordinates c2){
        if(c1.x==c2.x){
            return c1.y<c2.y;
        }
        return c1.x<c2.x;
    }
};

int count_triangles(vector<coordinates> &cords){
    unordered_map<int,int> freq_X;
    unordered_map<int,int> freq_Y;
    int cnt=0;

    for(auto cord:cords){
        int x=cord.x;
        int y=cord.y;

        freq_X[x]++;
        freq_Y[y]++;
    }

    for(auto cord:cords){
        int x=cord.x;
        int y=cord.y;

        int fx=freq_X[x];
        int fy=freq_Y[y];

        cnt += (fx-1)*(fy-1);
    }

    return cnt;
}   

int main(){
    int N;
    cin>>N;
    vector<coordinates> cords;

    int i=0;
    while(i<N){
        int x,y;
        cin>>x>>y;
        coordinates c(x,y);
        cords.push_back(c);
        i++;
    }

    cout<<count_triangles(cords)<<endl;    
}