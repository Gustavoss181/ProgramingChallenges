#include <string>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int kSimilarityBFS(string s1, string s2){
        if(s1 == s2) return 0;

        queue<pair<string,int>> bfsQueue;
        bfsQueue.push({s1,0});

        unordered_set<string> visited;
        visited.insert(s1);
        while(!bfsQueue.empty()){
            auto [current, swaps] = bfsQueue.front();
            bfsQueue.pop();
            int i = 0;
            while (i < current.size() && current[i] == s2[i]) ++i;

            for (int j=i+1; j < current.size(); ++j) {
                if (current[j] == s2[i] && current[j] != s2[j]) {
                    swap(current[i], current[j]);
                    
                    // Se `current` após a troca for igual a `s2`, retornamos as trocas + 1
                    if (current == s2) return swaps + 1;

                    // Se o novo estado não foi visitado, adiciona à fila para expandir
                    if (visited.find(current) == visited.end()) {
                        visited.insert(current);
                        bfsQueue.push({current, swaps + 1});
                    }
                    
                    // Desfazer a troca para explorar outras possibilidades
                    swap(current[i], current[j]);
                }
            }
        }

        return -1;
    }
    int kSimilarityGuloso(string s1, string s2){
        int i=0;
        int nSwaps=0;
        while(s1 != s2){
            if(s1[i] != s2[i]){
                int swapIdx=-1;
                for(int j=i+1; j<s1.size(); j++){
                    if(s1[j] == s2[i] and s1[j] != s2[j]){
                        swapIdx = j;
                        if(s1[i] == s2[j]) break;
                    }
                }
                if(swapIdx != -1){
                    swap(s1[i], s1[swapIdx]);
                    nSwaps++;
                }
            }
            i++;
        }
        return nSwaps;
    }
    int kSimilarity(string s1, string s2, int strSize=1, int nSwaps=0) {
        if(strSize == s1.size()){
            cout << s1 << endl;
            return s1 == s2 ? nSwaps : s1.size();
        }
        string aux = s1;
        int min = kSimilarity(s1, s2, strSize+1, nSwaps);
        for(int i=0; i<strSize; i++){
            swap(s1[i], s1[strSize]);
            int minSwaps = kSimilarity(s1, s2, strSize+1, nSwaps+1);
            if(min > minSwaps){
                min = minSwaps;
                aux = s1;
            }
            swap(s1[i], s1[strSize]);
        }
        return min;
    }
};

int main(int argc, char const *argv[]){
    cout << Solution().kSimilarityBFS("abc", "bca") << endl;

    return 0;
}
