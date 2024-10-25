#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }
        int i=0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main(int argc, char const *argv[]){
    vector<int> nums = {3,3,2,2,4,3,1};
    
    cout << Solution().removeElement(nums, 3) << endl;
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}