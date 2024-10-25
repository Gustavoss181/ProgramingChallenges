#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()){
            return 0;
        }
        if(target < nums[0]){
            return 0;
        }
        if(target > nums[nums.size()-1]){
            return nums.size();
        }
        int l=0, r=nums.size();
        int m=(r+l)/2;
        while(l < r){
            if(target == nums[m]){
                return m;
            }
            else if(target < nums[m]){
                r = m;
            }
            else{
                l = m+1;
            }
            m = (r+l)/2;
        }

        return m;
    }
};

int main(int argc, char const *argv[]){
    vector<int> nums = {1,3};

    cout << Solution().searchInsert(nums, 3) << endl;

    return 0;
}
