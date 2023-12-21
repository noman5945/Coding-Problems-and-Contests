#include<bits/stdc++.h>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n=position.size();
    int i=0;

    int cnt=0;
    if(n==1){
        return 1;
    }

    vector<pair<int,double>> cars;
    for(int i=0;i<n;i++){
        double time=(double)(target-position[i])/speed[i];
        cars.push_back({position[i],time});
    }

    sort(cars.begin(),cars.end());

    for(auto car:cars){
        cout<<car.first<<" --- "<<car.second<<endl;
    }

    double maxTime=0.0;
    for(int i=n-1;i>=0;i--){
        double time=cars[i].second;
        if(time>maxTime){
            maxTime=time;
            cnt++;
        }
    }
    return cnt;

}

int main(){
    vector<int> position={10,8,0,5,3};
    vector<int> speed={2,4,1,1,3};
    int target=12;
    cout<<carFleet(target,position,speed)<<endl;
}
