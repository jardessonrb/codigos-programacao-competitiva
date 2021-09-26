#include <bits/stdc++.h>


using namespace std;

bool stop = false;

int main(int argc, char const *argv[]){
    while(stop == false){
        queue<int> cards;
        vector<int> descarted;
        int N;

        cin>>N;
        if(N == 0) 
        {
            stop = true; 
            break;
        }

        for (int i = 1; i <= N; i++)
        {
            cards.push(i);
        }
        int i = 1;
        while((int)cards.size() != 1)
        {
            if(i % 2 == 1)
            {
                descarted.push_back(cards.front());
                cards.pop();
            }else{
                cards.push(cards.front());
                cards.pop();
            }

            i++;
        }
        int pause = (int)descarted.size() - 1;
        cout<<"Discarded cards: ";
        for (int i = 0; i < pause; i++)
        {
            cout<<descarted[i]<<", ";
        }
        cout<<descarted[pause];
        cout<<endl;
        cout<<"Remaining card: "<<cards.front()<<endl;
        
    }

    return 0;
}