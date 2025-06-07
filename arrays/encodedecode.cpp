#include<iostream>
#include<string>
#include<vector>
using namespace std;

class EncodeDecodeString{
public:
    
    string encode(vector<string>& strs){
        string encoded;
        for(const auto& s : strs){
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s){
        vector<string> decoded;
        int i = 0;
        while (i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            decoded.push_back(s.substr(i,length));
            i = j;
        }
        return decoded;
    }

    
};

int main(){
    vector<string> strs = {"neet","code","loves","you"};
    EncodeDecodeString obj1;
    string encodedresult = obj1.encode(strs);
    cout<<encodedresult<<endl;
    vector<string> decodedresult = obj1.decode(encodedresult);
    for(string s : decodedresult){
        cout<<s<<" ";
    }
    
    return 0;
}