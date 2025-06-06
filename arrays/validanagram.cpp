#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class IsAnagram{
public:
    bool CheckForAnagram(string s, string t){
        if (s.length() != t.length()){
            return false;
        }

        vector<int> count(26,0);
        for(int i = 0; i < s.length(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int j = 0; j < count.size(); j++){
            if (count[j] != 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s;
    string t;
    cout<<"Enter first word: ";
    cin>>s;
    cout<<"Enter second word: ";
    cin>>t;

    IsAnagram an1;
    bool result = an1.CheckForAnagram(s,t);
    if (result == true){
        cout<<"the two strings are anagrams";
    }
    else{
        cout<<"not anagrams";
    }

    return 0;
}