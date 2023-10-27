
#pragma once

#include <vector>
#include "Lista.h"

/*
Renata Chaves de Oliveira Moreno
Responsável por:

- Implementar os métodos estatísticos para os dados do tipo Salário.
- Implementar o método listarNPrimeirosElementos(int N) na classe de Listas de Salários.

*/

class ListaSalarios : public Lista {
    vector<float> lista;

public:
    void entradaDeDados() override;
    void mostraMediana() override;
    void mostraMenor() override;
    void mostraMaior() override;
};
