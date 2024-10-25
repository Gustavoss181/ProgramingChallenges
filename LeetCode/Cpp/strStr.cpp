#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size() or haystack.size() == 0 or needle.size() == 0){
            return -1;
        }
        int maxSearch = haystack.size() - needle.size() + 1;
        for(int i=0; i<maxSearch; i++){
            if(haystack[i] == needle[0]){
                int j=1;
                for(; j<needle.size(); j++){
                    if(haystack[i+j] != needle[j]){
                        break;
                    }
                }
                if(j == needle.size()){
                    return i;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[]){
    
    cout << Solution().strStr("haystack", "haystack") << endl;

    return 0;
}
