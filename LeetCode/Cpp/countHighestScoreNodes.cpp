#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
private:
    int dfs(int node, vector<vector<int>>& filhos, vector<int>& nFilhos, long long& maior, int& count, int n) {
        int size = 1;  // Inclui o próprio nó
        long long score = 1;

        // Calcula o tamanho das subárvores dos filhos e multiplica o score
        for (int filho : filhos[node]) {
            int subtreeSize = dfs(filho, filhos, nFilhos, maior, count, n);
            size += subtreeSize;
            score *= subtreeSize;
        }

        // Calcula a pontuação para a parte fora da subárvore do nó atual
        if (node != 0) {  // Somente para nós que não são a raiz
            score *= (n - size);
        }

        // Atualiza o maior score e conta
        if (score > maior) {
            maior = score;
            count = 1;
        } else if (score == maior) {
            ++count;
        }

        nFilhos[node] = size;  // Armazena o tamanho da subárvore do nó
        return size;
    }

public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> filhos(n);  // Lista de adjacência para filhos
        for (int i = 1; i < n; ++i) {
            filhos[parents[i]].push_back(i);
        }

        vector<int> nFilhos(n, 0);  // Tamanhos das subárvores
        long long maior = -1;
        int count = 0;
        dfs(0, filhos, nFilhos, maior, count, n);  // Inicia a DFS a partir do nó raiz

        return count;
    }
};

int main(){
    vector<int> parents = {-1,2,0,2,0};

    cout << Solution().countHighestScoreNodes(parents) << endl;

    return 0;
}
