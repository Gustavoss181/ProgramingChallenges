#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c : s){
            switch (c){
            case '{':
                stk.push('}');
                break;
            case '[':
                stk.push(']');
                break;
            case '(':
                stk.push(')');
                break;
            case '}':
            case ']':
            case ')':
                if(stk.empty() or stk.top() != c){
                    return false;
                }
                else{
                    stk.pop();
                }
                break;

            default:
                break;
            }
        }
        if(stk.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(int argc, char const *argv[]){
    
    if(Solution().isValid("[]")){
        printf("True\n");
    }
    else{
        printf("False\n");
    }

    return 0;
}
