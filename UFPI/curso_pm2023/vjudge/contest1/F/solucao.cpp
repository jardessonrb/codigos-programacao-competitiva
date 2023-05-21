#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

struct Tarefa {
    int init;
    int end;

    Tarefa(int x, int y) : init(x), end(y){}

    bool operator < (const Tarefa &task) const
    {
        return end >= task.end;
    }
};

int main(int argc, char const *argv[]){
    optimize;

    int T, N; 

    cin >> T;

    while (T--)
    {
        cin >> N;

        // vector<Tarefa> tasks;
        priority_queue<Tarefa> tasks;

        for (int i = 0; i < N; i++)
        {
            int init, end;

            cin >> init >> end;

            tasks.push({init, end});
        }

        // sort(ALL(tasks));

        // while (!tasks.empty())
        // {
        //     cout << tasks.top().init << " - " << tasks.top().end << endl;
        //     tasks.pop();
        // }
        

        int ans = 1;

        if(tasks.size() <= 1){
            cout << ans << endl;
        }else {
            Tarefa atual = tasks.top();
            tasks.pop();

            while (!tasks.empty())
            {
                Tarefa current = tasks.top();
                if(current.init >= atual.end){
                    atual = current;
                    ans++;
                }

                tasks.pop();
            }
            
            // for (int i = 1; i < N; i++)
            // {
            //     if(tasks[i].init >= atual.end){
            //         ans++;

            //         atual = tasks[i];
            //     }
            // }

            cout << ans  << endl;
        }
        
    }
    

    return 0;
}