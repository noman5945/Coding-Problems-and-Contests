#include<bits/stdc++.h>
using namespace std;

class coord{
public:
    int x;
    int y;

    coord(){

    }
    coord(int x,int y){
        this->x=x;
        this->y=y;
    }
};

class Compare{
    public:
        bool operator()(const coord c1,const coord c2){
            if(c1.x==c2.x){
                return c1.y>c2.y;
            }
            return c1.x>c2.x;
        }
};

int count_recatngles(vector<coord> cords){
    set<coord,Compare> s;
    for(coord cord:cords){
        s.insert(cord);
    }

    for(auto i=s.begin();i!=s.end();i++){
        coord c=*i;
        cout<<c.x<<"-----"<<c.y<<endl;
    }

    int ans=0;
    for (auto it=s.begin();it!=prev(s.end());it++){
        for(auto jt=next(it);jt!=s.end();jt++){
            coord c1=*it;
            coord c2=*jt;
            if(c1.x==c2.x || c1.y==c2.y){
                continue;
            }

            coord c3(c1.x,c2.y);
            coord c4(c2.x,c1.y);

            if(s.find(c3)!=s.end() && s.find(c4)!=s.end()){
                ans++;
            }
        }
    }

    return ans/2;
    
}   

int main(){
    int N;
    cin>>N;
    vector<coord> coords;

    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        coord c(x,y);
        coords.push_back(c);
    }
    int rects=count_recatngles(coords);
    cout<<rects<<endl;
}