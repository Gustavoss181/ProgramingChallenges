#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int endSize = a.size() > b.size() ? a.size()+1 : b.size()+1;

        string result = "";
        for(int i=0; i<endSize; i++){
            result += "0";
        }

        auto ita = a.crbegin(), itb = b.crbegin();
        auto itresult = result.rbegin();
        char carry = '0';

        while(ita != a.crend() and itb != b.crend()){
            if(*ita == '1' and *itb == '1' and carry == '1'){
                *itresult = '1';

            }
            else if((*ita == '1' and *itb == '1') or (*ita == '1' and carry == '1') or (*itb == '1' and carry == '1')){
                *itresult = '0';
                carry = '1';
            }
            else if(*ita == '1' or *itb == '1' or carry == '1'){
                *itresult = '1';
                carry = '0';
            }
            else{
                *itresult = '0';
                carry = '0';
            }
            ita++;
            itb++;
            itresult++;
        }

        while(ita != a.crend()){
            if(*ita == '1' and carry == '1'){
                *itresult = '0';
            }
            else if(*ita == '1' or carry == '1'){
                *itresult = '1';
                carry = '0';
            }
            else{
                *itresult = '0';
            }
            ita++;
            itresult++;
        }

        while(itb != b.crend()){
            if(*itb == '1' and carry == '1'){
                *itresult = '0';
            }
            else if(*itb == '1' or carry == '1'){
                *itresult = '1';
                carry = '0';
            }
            else{
                *itresult = '0';
            }
            itb++;
            itresult++;
        }

        if(carry == '1'){
            *itresult = '1';
        }
        else{
            result = result.substr(1, endSize-1);
        }

        return result;
    }

    string addBinaryChatGPT(string a, string b){
        int endSize = max(a.size(), b.size()) + 1;
        string result(endSize, '0');  // Inicializa `result` diretamente com zeros
        
        auto ita = a.crbegin(), itb = b.crbegin();
        auto itresult = result.rbegin();
        int carry = 0;

        // Itera enquanto houver elementos em `a` ou `b` ou carry é 1
        while (ita != a.crend() || itb != b.crend() || carry) {
            int sum = carry;
            if (ita != a.crend()) sum += (*ita++ - '0');  // Converte char '1' ou '0' para int 1 ou 0
            if (itb != b.crend()) sum += (*itb++ - '0');

            *itresult++ = (sum % 2) + '0';  // Define bit atual
            carry = sum / 2;  // Atualiza carry
        }

        // Remove possível zero à esquerda se carry não foi necessário
        if (result[0] == '0') {
            result = result.substr(1);
        }

        return result;
    }
};

int main(int argc, char const *argv[]){

    cout << Solution().addBinaryChatGPT("10010100", "110011") << endl;

    return 0;
}
