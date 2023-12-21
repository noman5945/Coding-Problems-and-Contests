#include<bits/stdc++.h>
using namespace std;

/* better solution*/

class Cars{
public:
    string id;
    int x;
    int y;

    Cars(string id,int x,int y){
        this->id=id;
        this->x=x;
        this->y=y;
    }
    int cartesian_dist() const{
        int dist=sqrt(x*x+y*y);
        return dist;
    }
};

class Compare{
public:
    bool operator()(const Cars A,const Cars B){
        return A.cartesian_dist()<B.cartesian_dist();
    }
};


/* Complexity---> O(k+(N-k)logk)*/
void printNearestCars(vector<Cars> cars,int k){
    priority_queue<Cars,vector<Cars>,Compare> max_heap(cars.begin(),cars.begin()+k);

    for(int i=k;i<cars.size();i++){
        auto cab=cars[i];
        if(cab.cartesian_dist()<max_heap.top().cartesian_dist()){
            max_heap.pop();
            max_heap.push(cab);
        }
    }

    while(!max_heap.empty()){
        cout<<max_heap.top().id<<endl;
        max_heap.pop();
    }
}

int main(){

    int N,K;
    cin>>N>>K;
    vector<Cars> cabs;

    /*
    for(int i=0;i<N;i++){
        //cout<<"C"<<i+1<<"--> "<<coords[i][0]<<" ,"<<coords[i][1]<<"  distance-->"<<cartesian_dist(coords[i][0],coords[i][1])<<endl;
        dist=cartesian_dist(coords[i][0],coords[i][1]);
        if(dist<K){
            cout<<"C"<<i+1<<endl;
        }
    }

    */
    for(int i=0;i<N;i++){
        string id;
        int x,y;
        cin>>x>>y>>id;
        Cars car(id,x,y);
        cabs.push_back(car);
    }


    printNearestCars(cabs,K);


}
