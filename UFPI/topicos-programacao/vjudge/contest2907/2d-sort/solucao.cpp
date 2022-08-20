#include <bits/stdc++.h>

using namespace std;
struct Ponto {
    int x, y;
    Ponto(int x = 0, int y = 0): x(x), y(y){}

    bool operator < (const auto &a){
        return !(x > a.x || (x == a.x && y < a.y));
    }
};

int main(int argc, char const *argv[])
{
    int T,N;
    scanf("%d", &T);
    vector<Ponto> pontos; 
    while(T > 0){
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            pontos.push_back({x, y});
        }
        sort(pontos.begin(), pontos.end());
        for (int i = 0; i < pontos.size(); i++)
        {
            printf("%d %d \n", pontos[i].x, pontos[i].y);
        }
        T--;
        pontos.erase(pontos.begin(), pontos.end());
    }   
    return 0;
}
