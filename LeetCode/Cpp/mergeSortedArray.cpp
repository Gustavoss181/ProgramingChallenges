#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;

        int size = m+n;
        vector<int> result(size);

        int i=0,j=0,k=0;
        while(i < m and j < n){
            if(nums1[i] < nums2[j]){
                result[k++] = nums1[i++];
            }
            else{
                result[k++] = nums2[j++];
            }
        }
        while(i < m){
            result[k++] = nums1[i++];
        }
        while(j < n){
            result[k++] = nums2[j++];
        }
        for(k=0; k<size; ++k){
            nums1[k] = result[k];
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
