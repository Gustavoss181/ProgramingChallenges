#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;

        int i = 0;
        // Ignora espaços iniciais
        while (i < s.size() && s[i] == ' ') ++i;

        // Checa sinal
        bool negative = false;
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            negative = (s[i] == '-');
            ++i;
        }

        int n = 0;
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Checa overflow
            if (n > (INT32_MAX - digit) / 10) {
                return negative ? INT32_MIN : INT32_MAX;
            }

            n = n * 10 + digit;
            ++i;
        }

        return negative ? -n : n;
    }
};

int main(int argc, char const *argv[]){
    
    cout << Solution().myAtoi("-91283472332") << endl;

    return 0;
}
