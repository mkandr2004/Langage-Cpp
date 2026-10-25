#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target){
    for (size_t i = 0 ; i < nums.size() ; ++i){

        for (size_t j = i + 1 ; j < nums.size(); ++j){

            if((nums[j] + nums[i]) == target){
                return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
    return {};
}

vector<int> twoSumOptimal(const vector<int>& nums, int target){
    unordered_map<int,int> temp;

    for (size_t i = 0 ; i < nums.size() ; ++i){

        int value = target - nums[i];

        if(temp.find(value) != temp.end() ){
            return {temp[value], static_cast<int>(i)};
        }

        temp[nums[i]] = static_cast<int>(i);
    }

    return {};
}

int main(){

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);

    if(indicesBruteForce.empty()){
        cout << "Brute Force: No solution" << endl;
    }
    else{
        cout << "Brute Force Solution: ["
            << indicesBruteForce[0]
            << ", "
            << indicesBruteForce[1]
            << "]"
            << endl;
    }
    

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    if(indicesOptimal.empty()){
        cout << "Optimal: No solution" << endl;
    }
    else{
        cout << "Optimal Solution: ["
            << indicesOptimal[0]
            << ", "
            << indicesOptimal[1]
            << "]"
            << endl;
    }

    return 0;
}
