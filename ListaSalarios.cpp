#include "ListaSalarios.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

void ListaSalarios::entradaDeDados() {
    // Implementação da entrada de dados para salários
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

void ListaSalarios::mostraMediana() {
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

void ListaSalarios::mostraMenor() {
    if (!lista.empty()) {
        sort(lista.begin(), lista.end());
        cout << "Menor salário: " << lista[0] << endl;
    }
}

void ListaSalarios::mostraMaior() {
    if (!lista.empty()) {
        sort(lista.begin(), lista.end());
        cout << "Maior salário: " << lista[lista.size() - 1] << endl;
    }
}

// Método estatístico para calcular a média dos salários
float ListaSalarios::calculaMedia() {
    if (!lista.empty()) {
        float soma = accumulate(lista.begin(), lista.end(), 0.0f);
        return soma / lista.size();
    }
    return 0.0f; // Retorna 0 se a lista estiver vazia
}

// Método estatístico para calcular a variação dos salários
float ListaSalarios::calculaVariancia() {
    if (lista.size() < 2) {
        return 0.0f; 

    float media = calculaMedia();
    float somaDiferencasQuadradas = 0.0f;

    for (float salario : lista) {
        float diferenca = salario - media;
        somaDiferencasQuadradas += diferenca * diferenca;
    }

    return somaDiferencasQuadradas / (lista.size() - 1);
}

// Método estatístico para calcular o desvio padrão dos salários
float ListaSalarios::calculaDesvioPadrao() {
    return sqrt(calculaVariancia());
}
