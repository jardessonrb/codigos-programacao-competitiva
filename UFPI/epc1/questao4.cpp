#include <bits/stdc++.h>


using namespace std;

int pesos[] = {2, 3, 4, 1}, totalPesos = 0;
double notas[5], media = 0, notaExame;

string mensagem(double mediaP){
    if(mediaP >= 7){
        return "Aluno aprovado.";
    }else if(mediaP < 5){
        return "Aluno reprovado.";
    }
}

int main(){

    for(int i = 0; i < 4; i++){
        double x;
        cin >> x;
        media += (x + pesos[i]);
        totalPesos += pesos[i];
    }

    media = media / totalPesos;

    
    if(media >= 5 && media <= 6.9){
        cin >> notaExame;
        cout << "Media: "<< media <<endl;
        cout << "Nota do exame: " << notaExame <<endl;
        double mfinal = (media + notaExame) / 2;
        cout << mensagem(mfinal) << endl;
        cout << "Media final: " << mfinal <<endl;
    }
    else{
        cout << "Media: "<< media <<endl;
        cout << mensagem(media) << endl;     
    }

    return 0;
}