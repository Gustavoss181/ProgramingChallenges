#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end=s.size()-1;
        while(s[end] == ' '){
            end--;
        }
        int begin = end;
        while(s[begin] != ' ' and begin >= 0){
            begin--;
        }
        return end - begin;
    }
};

int main(int argc, char const *argv[]){
    
    cout << Solution().lengthOfLastWord("a") << endl;

    return 0;
}
