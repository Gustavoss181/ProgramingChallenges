#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        while(i >= 0){
            digits[i]++;
            if(digits[i] <= 9){
                break;
            }
            digits[i]%=10;
            i--;
        }
        if(i == -1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main(int argc, char const *argv[]){
    
    vector<int> digits = {9,9,9,9};

    Solution().plusOne(digits);

    for(int digit : digits)
        cout << digit;
    cout << endl;

    return 0;
}
