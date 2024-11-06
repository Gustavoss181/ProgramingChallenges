#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};

        for(int num : nums) ++count[num];

        vector<int>::iterator it = nums.begin();
        for(int i=0; i<3; ++i){
            for(int j=0; j<count[i]; ++j){
                *it = i;
                ++it;
            }
        }
    }
};

int main(int argc, char const *argv[]){
    vector<int> nums = {2,0,2,1,1,0};

    Solution().sortColors(nums);
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
