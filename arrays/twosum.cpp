#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class twoSum{
public:
    //brute force
    // vector<int> findTwoSumElems(vector<int>& nums, int target){
    //     for(int i = 0; i < nums.size(); i++){
    //         for(int j = i + 1; j < nums.size(); j++){
    //             if (nums[i] + nums[j] == target){
    //                 return {i,j};
    //             }
    //         }
    //     }
    //     return {};
    // }


    //best approach
    vector<int> findTwoSumElems(vector<int>& nums, int target){
        unordered_map<int,int> findElems;
        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (findElems.find(diff) != findElems.end()){
                return {findElems[diff],i};
            }
            findElems.insert({nums[i],i});
        }
        return {};
    }
};

int main(){
    vector<int> nums = {2,4,5,6};
    int target = 11;
    twoSum obj1;
    vector<int> result = obj1.findTwoSumElems(nums,target);
    for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }

    return 0;
}