#include <bits/stdc++.h>

#define beg_end(vect) vect.begin(), vect.end()
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

bool isPar(int i){
    return ((i % 2) == 0);
}

// string *split(string str, char separator, string spliters[]){
//     stringstream strstream(str);
//     string part;
//     int i = 0;

//     while(getline(strstream, part, separator)) {
//         spliters[i++] = part;
//     }

//     return spliters;
// }

struct Pessoa {

    string nome;
    string cor;
    char tamanho;

    Pessoa(string n, string c, char t) : nome(n), cor(c), tamanho(t){}

    bool operator < (const Pessoa &p) const
    {
        if(strcmp(p.cor.c_str(), cor.c_str()) > 0) return true;

        if(strcmp(p.cor.c_str(), cor.c_str()) == 0 && p.tamanho < tamanho) return true;

        if(strcmp(p.cor.c_str(), cor.c_str()) == 0 && p.tamanho == tamanho && strcmp(p.nome.c_str(), nome.c_str()) > 0) return true;
        
        return false;
    }

};


int main() {
    optimize;

    int opc;

    while(true){
        vector<Pessoa> pessoas;
        scanf("%d", &opc);

        if(opc == 0) break;


        int max = (opc * 2);

        string nome, cor;
        char tamanho;
        bool isNome = true;
        for (int i = 0; i < max; i++)
        {
            if(isNome){
                // getline(cin, nome);
                // cin >> nome;
                scanf("%s", &nome);
                isNome = false;
            }else {
                string line;
                // getline(cin, line);
                // cin >> cor >> tamanho;
                scanf("%s %c", &cor, &tamanho);
                isNome = true;

                // bool isCor = true;
                // for (int i = 0; i < line.length(); i++)
                // {
                //     if(line[i] == ' ') isCor = false;

                //     if(isCor){
                //         cor += line[i];
                //     }else {
                //         tamanho = line[i];
                //     }
                // }
                
                Pessoa pessoa(nome, cor, tamanho);
                pessoas.push_back(pessoa);

                nome = "";
                cor = "";
            }

        }

        sort(beg_end(pessoas));

        for(auto p : pessoas){
            cout << p.cor << " " << p.tamanho << " " << p.nome << endl;
        }

        cout << endl;
    }

    return 0;
}