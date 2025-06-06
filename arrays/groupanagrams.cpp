#include<iostream>
#include<bits\stdc++.h>
using namespace std;

class IsAnagramofGroup{
public:
    vector<vector<string>> groupAngrams(vector<string> &strs){
        unordered_map <string, vector<string>> findmatches;
        for (const auto& s : strs){      //const is used just for safety                                          */
            vector<int> count(26,0);     //so no modification to string s is made in loop
            for (char c : s){            
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < count.size(); i++){
                key += "," + to_string(count[i]);
            }
            findmatches[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : findmatches){
            result.push_back(pair.second);
        }
        return result;
    }
};

int main(){
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    IsAnagramofGroup obj1;
    vector<vector<string>> res = obj1.groupAngrams(strs);
    for(auto& group : res){
        for(auto& str : group){
            cout<<str<<" ";
        }
        cout<<endl;
    }

    return 0;
}