#include <iostream>
#include <unordered_set>
#include <vector>
#include <memory>


int main(){
    std::vector<int>  inVec{1,2,3,4,5,1,8,16,4,19,19};
    
    auto getUnique =[](const std::vector<int>& vec)
    {
        std::unordered_multiset<int> set(vec.begin(), vec.end());
        auto result = std::make_unique<std::vector<int>>();
        for(auto i: set){
            if(set.count(i) == 1)
            result->push_back(i);
        }
        return result;
    };
    
    auto getVec = getUnique(inVec);
    for(auto i: *getVec){
        std::cout << i << " ";
    }
}