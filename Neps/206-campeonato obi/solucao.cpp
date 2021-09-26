#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()


using namespace std;

map<int, string> fases;
queue<int> jogadores;

int main(int argc, char const * argv[]){
    fases[1] = "oitavas";
    fases[2] = "quartas";
    fases[3] = "semifinal";
    fases[4] = "final";

    int x;
    for (int i = 0; i < 16; i++)
    {
        cin>>x;
        jogadores.push(x);
    }

    int fase = 0, front, back, ult;
    bool fim = true;


    while(fim)
    {
        int lim = (jogadores.size() / 2);
        fase++;
        for (int i = 0; i < lim; i++)
        {
            front = jogadores.front();
            jogadores.pop();
            back = jogadores.front();
            jogadores.pop();

            if(max(front, back) == 9 && min(front, back) == 1){
                fim = false;
                break;
            }

            if(front == 1 || front == 9)
            {
                jogadores.push(front);

            }else if(back == 1 || back == 9)
            {
                jogadores.push(back);
            }else
            {
                jogadores.push(back);
            }
            
        }
        
    }    

        
    cout<<fases[fase]<<endl;
    return 0;
}
