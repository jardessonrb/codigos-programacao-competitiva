#include <bits/stdc++.h>
using namespace std;

int colecao[45][45];

char matrix [45][45];

vector<string> palavras;
int l, c, ans = 0;


void verifica (string palavra, int l, int c)
{
    
    int tam = palavra.size();   

    map <char, int> freqP;
    for (char it : palavra){
        freqP[it]++;
    }
    
    // Horizontal
    for (int k = 0; k < tam; k++){
        map <char, int> freqA;
        freqA[matrix[l][c+k]]++;

        for (char x = 'A'; x <= 'Z'; x++){
            if (freqA[x] != freqP[x]){
                break;
            }
            if (x == 'Z') {
                for (int y = 0; y < tam; y++){
                    colecao[l][c+y]++;
                }
            }
        }
    }

    // Vestical
    for (int k = 0; k < tam; k++){
        map <char, int> freqA;
        freqA[matrix[l+k][c]]++;

        for (char x = 'A'; x <= 'Z'; x++){
            if (freqA[x] != freqP[x]){
                break;
            }
            if (x == 'Z') {
                for (int y = 0; y < tam; y++){
                    colecao[l+y][c]++;
            }
        }
    }

    // inclicada
    for (int k = 0; k < tam; k++){
        map <char, int> freqA;
        freqA[matrix[l+k][c+k]]++;

        for (char x = 'A'; x <= 'Z'; x++){
            if (freqA[x] != freqP[x]){
                break;
            }
            if (x == 'Z') {
                for (int y = 0; y < tam; y++){
                    colecao[l+y][c+y]++;
                }
            }
        }
    }                                 
}


int main (int argc, char const *argv[]) {

    // zera a colecao
    for (int i = 0; i < 45; i++){
        for (int j = 0; j< 45; j++){ 
            colecao[i][j]=0;
        }
    }
    

    cin >> l >> c;

    for (int i = 1; i <= l; i++){
        for (int j = 1; j < c; j++){
            cin >> matrix[i][j];
        }
    }

    int k;
    string aux;
    cin >> k;

    for (int i = 0; i < k; i++){
        cin >> aux;
        palavras.push_back(aux);
    }

    for (int i = 1; i <= l; i++){
        for (int j = 1; j < c; j++){
            for (int y = 0; y < k; y++) {
                verifica((string)palavras[i], c, l);
            }    
        }
    }
    
    for (int i = 0; i < 45; i++){
        for (int j = 0; j< 45; j++){
            if (colecao[i][j] > 1) ans++;
        }
    }

    for (int i = 0; i < 45; i++){
        for (int j = 0; j< 45; j++){
            cout << colecao[i][j] << " ";
        }
        cout << endl;
    }

    cout << ans << endl;


    return 0;
}