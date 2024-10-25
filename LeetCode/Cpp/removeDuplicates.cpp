#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int i=1;
        for(int j=1; j<nums.size(); j++){
            if(nums[j-1] != nums[j]){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main(int argc, char const *argv[]){
    vector<int> nums;
    
    cout << Solution().removeDuplicates(nums) << endl;
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
