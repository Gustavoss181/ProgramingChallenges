#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        string s = "";
        while(true){
            if(strs[0].size() == i){
                return s;
            }
            char c = strs[0][i];
            for(size_t j=1; j<strs.size(); j++){
                if(strs[j].size() == i){
                    return s;
                }
                if(strs[j][i] != c){
                    return s;
                }
            }
            s += c;
            i++;
        }
        return s;
    }
};

int main(int argc, char const *argv[]){
    vector<string> v;
    v.push_back("dog");
    v.push_back("racecar");
    v.push_back("car");

    cout << Solution().longestCommonPrefix(v) << endl;

    return 0;
}
