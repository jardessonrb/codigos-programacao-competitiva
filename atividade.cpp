#include <bits/stdc++.h>

using namespace std;

struct Student{
    string name;
    float grades[3];
    float average;
};

Student students[48];


void showStudents(int limit){
    for (int i = 0; i < 3; i++)
    {
        cout << "Aluno: "<< students[i].nome << endl;        
    }
}

void registerStudents(int limit){
    int index = 0;
    while(limit--){
        cout << "Digite o nome do aluno: " <<endl;
        cin>> students[index].nome;
        for (int i = 0; i < limit; i++)
        {
            cout << "Digite nota"<< i+1<< ": " << endl;
            cin>>students[index].notas[i];
        }

        index++;
        
    }

    showStudents(limit);
}

int main(){
    int limit;
    cout << "Quantos alunos na sala ?: " << endl;
    cin>>limit;
    registerStudents(limit);

    return 0;
}