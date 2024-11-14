#include <stdlib.h>
#include <iostream>
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int vet[n+1];
        vet[0] = 0;
        vet[1] = 1;
        vet[2] = 2;
        for(int i=3; i<=n; ++i){
            vet[i] = vet[i-1] + vet[i-2];
        }
        return vet[n];
    }
};

int main(int argc, char const *argv[]){
    int n = atoi(argv[1]);
    std::cout << Solution().climbStairs(n) << std::endl;

    return 0;
}
