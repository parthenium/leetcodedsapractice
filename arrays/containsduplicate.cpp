#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class duplicates{
public:
    /* first approach through sorting (expected) */
    // bool HasDuplicates(vector<int> &nums){
    //     sort(nums.begin(), nums.end());
    //     for(int i = 0; i < nums.size(); i++){
    //         if (nums[i] == nums[i+1]){
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    /* second approach through unordered map (better) */
    bool HasDuplicates(vector<int> &nums){
        unordered_map <int,int> count;
        for(int k = 0; k < nums.size(); k++){
            count[nums[k]]++;
            if (count[nums[k]] > 1){
                return true;
            }
        }
        return false;
    }

};

int main(){
    int size;
    cout<<"Enter the size of you array: ";
    cin>>size ;
    
    vector<int> nums;
    int num;
    cout<<"Enter elements of the array: "<<endl;
    for(int i = 0; i < size; i++){
        cout<<"Enter element "<<i + 1<<": ";
        cin>>num;
        nums.push_back(num);
    }
    for(int j = 0; j < nums.size(); j++){
        cout<<nums[j]<<" ";
    }

    bool result;
    duplicates dup1;
    result = dup1.HasDuplicates(nums);
    if (result == true){
        cout<<"\nduplicates exist";
    }
    else{
        cout<<"\nno duplicates";
    }

    return 0;
}

