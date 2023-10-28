#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric> 


using namespace std;
/*
A função compara é uma função estática que compara duas datas do tipo Data
-1 se a primeira data d1 for menor do que a segunda data d2.
 1 se a primeira data d1 for maior do que a segunda data d2.
 0 se as duas datas forem iguais.

*/

class Data {
    int dia, mes, ano;
public:
    // Função estática para comparar duas datas
    static int compara(const Data& d1, const Data& d2) {
        if (d1.ano < d2.ano) {
            return -1;
        }
        else if (d1.ano > d2.ano) {
            return 1;
        }
        else {
            if (d1.mes < d2.mes) {
                return -1;
            }
            else if (d1.mes > d2.mes) {
                return 1;
            }
            else {
                if (d1.dia < d2.dia) {
                    return -1;
                }
                else if (d1.dia > d2.dia) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
    }

    // Construtor da classe Data
    Data(int _dia, int _mes, int _ano) : dia(_dia), mes(_mes), ano(_ano) {}

    // Converte a data em uma string formatada
    string toString() {
        return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
    }
};

class Lista {
public:
    // Métodos virtuais puros que as subclasses devem implementar
    virtual void entradaDeDados     () = 0;
    virtual void mostraMediana      () = 0;
    virtual void mostraMenor        () = 0;
    virtual void mostraMaior        () = 0;
};

class ListaNomes : public Lista {
    vector<string> lista;
public:
    // Pede ao usuário para inserir nomes na lista
    void entradaDeDados() {
        int numNomes;
        cout << "Quantos nomes deseja inserir? ";
        cin >> numNomes;

        for (int i = 0; i < numNomes; i++) {
            string nome;
            cout << "Insira o nome " << (i + 1) << ": ";
            cin.ignore();
            getline(cin, nome);
            lista.push_back(nome);
        }
    }

    // Mostra a mediana dos nomes (ordena a lista)
    void mostraMediana() {
        if (lista.empty()) {
            cout << "A lista de nomes está vazia." << endl;
        }
        else {
            sort(lista.begin(), lista.end());
            int size = lista.size();
            cout << "Mediana: " << lista[size / 2] << endl;
        }
    }

    // Mostra o menor nome (ordena a lista)
    void mostraMenor() {
        if (!lista.empty()) {
            sort(lista.begin(), lista.end());
            cout << "Menor nome: " << lista[0] << endl;
        }
    }

    // Mostra o maior nome (ordena a lista)
    void mostraMaior() {
        if (!lista.empty()) {
            sort(lista.begin(), lista.end());
            cout << "Maior nome: " << lista[lista.size() - 1] << endl;
        }
    }
};

class ListaDatas : public Lista {
    vector<Data> lista;
public:
    // Pede ao usuário para inserir datas na lista
    void entradaDeDados() {
        int numDatas;
        cout << "Quantas datas deseja inserir? ";
        cin >> numDatas;

        for (int i = 0; i < numDatas; i++) {
            int dia, mes, ano;
            cout << "Insira a data " << (i + 1) << " (dia mês ano): ";
            cin >> dia >> mes >> ano;
            Data data(dia, mes, ano);
            lista.push_back(data);
        }
    }

    // Mostra a mediana das datas (ordena a lista usando a função de comparação)
    void mostraMediana() {
        if (lista.empty()) {
            cout << "A lista de datas está vazia." << endl;
        }
        else {
            sort(lista.begin(), lista.end(), Data::compara);
            int size = lista.size();
            if (size % 2 == 0) {
                // Mediana para um número par de elementos, mostra a data mais antiga
                cout << "Mediana: " << lista[size / 2 - 1].toString() << endl;
            }
            else {
                cout << "Mediana: " << lista[size / 2].toString() << endl;
            }
        }
    }

    // Mostra a primeira data cronológica (ordena a lista)
    void mostraMenor() {
        if (!lista.empty()) {
            sort(lista.begin(), lista.end(), Data::compara);
            cout << "Primeira data cronológica: " << lista[0].toString() << endl;
        }
    }

    // Mostra a última data cronológica (ordena a lista)
    void mostraMaior() {
        if (!lista.empty()) {
            sort(lista.begin(), lista.end(), Data::compara);
            cout << "Última data cronológica: " << lista[lista.size() - 1].toString() << endl;
        }
    }
};

/*
    Renata Chaves de Oliveira Moreno
    
    Ordena a lista de salários em ordem crescente
    Se o número de salários é par, calcula a médiana como a média dos dois valores centrais
    Se o número de salários é ímpar, a mediana é o valor do meio
    Ordena a lista de salários em ordem crescente
    O menor salário é o primeiro elemento da lista ordenada
    Ordena a lista de salários em ordem crescente
    O maior salário é o último elemento da lista ordenada

    */

class ListaSalarios : public Lista {
    vector<float> lista;
public:
    // Pede ao usuário para inserir salários na lista
    void entradaDeDados() {
        int numSalarios;
        cout << "Quantos salários deseja inserir? ";
        cin >> numSalarios;

        for (int i = 0; i < numSalarios; i++) {
            float salario;
            cout << "Insira o salário " << (i + 1) << ": ";
            cin >> salario;
            lista.push_back(salario);
        }
    }

    
   // Mostra a mediana dos salários (ordena a lista)
    void mostraMediana() {
        if (lista.empty()) {
            cout << "A lista de salários está vazia." << endl;
        }
        else {
            sort(lista.begin(), lista.end());
            int size = lista.size();
            if (size % 2 == 0) {
                
                float median = (lista[size / 2] + lista[size / 2 - 1]) / 2;
                cout << "Mediana: " << median << endl;
            }
            else {
                cout << "Mediana: " << lista[size / 2] << endl;
            }
        }
    }

    void mostraMenor() {
        if (!lista.empty()) {
            sort(lista.begin(), lista.end());
            cout << "Menor salário: " << lista[0] << endl;
        }
    }

    void mostraMaior() {
        if (!lista.empty()) {
            sort(lista.begin(), lista.end());
            cout << "Maior salário: " << lista[lista.size() - 1] << endl;
        }
    }
};

class ListaIdades : public Lista {
    vector<int> lista;
public:
    void entradaDeDados() {
        int numIdades;
        cout << "Quantas idades deseja inserir? ";
        cin >> numIdades;

        for (int i = 0; i < numIdades; i++) {
            int idade;
            cout << "Insira a idade " << (i + 1) << ": ";
            cin >> idade;
            lista.push_back(idade);
        }
    }

    void mostraMediana() {
        if (lista.empty()) {
            cout << "A lista de idades está vazia." << endl;
        }
        else {
            sort(lista.begin(), lista.end());
            int size = lista.size();
            if (size % 2 == 0) {
                
                int median = (lista[size / 2] + lista[size / 2 - 1]) / 2;
                cout << "Mediana: " << median << endl;
            }
            else {
                cout << "Mediana: " << lista[size / 2] << endl;
            }
        }
    }

    void mostraMenor() {
        if (!lista.empty()) {
            sort(lista.begin(), lista.end());
            cout << "Menor idade: " << lista[0] << endl;
        }
    }

    void mostraMaior() {
        if (!lista.empty()) {
            sort(lista.begin(), lista.end());
            cout << "Maior idade: " << lista[lista.size() - 1] << endl;
        }
    }
};

int main() {
    vector<Lista*> listaDeListas;

    ListaNomes listaNomes;
    listaNomes.entradaDeDados();
    listaDeListas.push_back(&listaNomes);

    ListaDatas listaDatas;
    listaDatas.entradaDeDados();
    listaDeListas.push_back(&listaDatas);

    ListaSalarios listaSalarios;
    listaSalarios.entradaDeDados();
    listaDeListas.push_back(&listaSalarios);

    ListaIdades listaIdades;
    listaIdades.entradaDeDados();
    listaDeListas.push_back(&listaIdades);

    for (Lista* l : listaDeListas) {
        l->mostraMediana();
        l->mostraMenor();
        l->mostraMaior();
    }

    return 0;
}