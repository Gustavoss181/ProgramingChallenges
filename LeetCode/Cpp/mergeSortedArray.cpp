#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size;
        if(n > 0 or m > 0)
            size = nums1[m-1] > nums2[n-1] ? nums1[m-1]+1 : nums2[n-1]+1;
        else if(n == 0)
            size = nums1[m-1]+1;
        else
            size = nums2[n-1]+1;

        vector<int> count(size + 1, 0);
        for(int i=0; i<m; i++){
            count[nums1[i]]++;
        }
        for(int num : nums2){
            count[num]++;
        }
        int it = 0;
        for(int i=0; i<size; i++){
            if(count[i] == 0) continue;
            nums1[it] = i;
            count[i]--;
            it++;
            i--;
        }
    }
};

int main(int argc, char const *argv[]){
    vector<int> nums1 = {1,4,6,7,9,0,0,0,0,0,0};
    vector<int> nums2 = {2,3,5,6,7,9};

    Solution().merge(nums1, 5, nums2, 6);

    for(int num : nums1)
        cout << num << " ";
    cout << endl;
    
    return 0;
}
