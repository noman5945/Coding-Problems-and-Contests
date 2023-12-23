#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    vector<int> setu;
    unordered_map<int,int> IndexHash;
    RandomizedSet() {
       
    }
    
    bool insert(int val) {
        if(IndexHash.find(val)!=IndexHash.end()){
            return false;
        }else{
            setu.emplace_back(val);
            IndexHash[val]=setu.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(IndexHash.find(val)==IndexHash.end()){
            return false;
        }
        int last = setu.back();
        IndexHash[last]=IndexHash[val];  //change the key(index) of last to old_key(index) of val in IndexHash(map)
        setu[IndexHash[val]]=last; ////change value at index_of_val to 'last' in setu
        setu.pop_back();
        IndexHash.erase(val);
        return true;
    }
    
    int getRandom() {
        return setu[rand()%setu.size()];
    }
};

int main(){
    RandomizedSet* randomizedSet = new RandomizedSet();
    randomizedSet->insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    randomizedSet->remove(2); // Returns false as 2 does not exist in the set.
    randomizedSet->insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
    randomizedSet->getRandom(); // getRandom() should return either 1 or 2 randomly.
    randomizedSet->remove(1); // Removes 1 from the set, returns true. Set now contains [2].
    randomizedSet->insert(2); // 2 was already in the set, so return false.
    randomizedSet->getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
}