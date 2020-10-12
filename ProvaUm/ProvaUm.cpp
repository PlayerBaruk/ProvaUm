#include <iostream>
#include "fila.h"
#include "pilha.h"
#include <string>
#include <tchar.h>

int main()
{
    _tsetlocale(LC_ALL, _T("portuguese"));
    unsigned tamanho = 13; // limite de numeros
    Pilha<int> p(tamanho); // criar pilha
    Fila<int> FilaCrescente(tamanho); //ordem da exibição
    string matricula;
    do
    {
        std::cout << "Insira o número de matrícula com 13 digitos: ";
        getline(cin, matricula);
        if (matricula.size() != tamanho)
            std::cout << "O numero de matrícula digitado não contém 13 digitos\n";
    }
    while (matricula.size() != tamanho);
    std::cout << "\nNúmero de matrícula: \n" << matricula;
    std::cout << "\nInserindo os digitos do numero de matrícula na pilha...\n";
    std::cout << "\nPilha: [";
    for (int i = 0; i < tamanho; i++)
    {
        unsigned k = matricula[i] - 48;
        p.empilha(k);
        if (i != tamanho - 1)
        {
            std::cout << p.elements[i] << " ";
        }
        else if (i == tamanho - 1)
        {
            std::cout << p.elements[i] << "]";
        }
    }
    for (int j = 0; j < tamanho - 1; j++)
    {
        for (int i = 0; i < tamanho - 1; i++)
        {
            if (p.elements[i] < p.elements[i + 1])
            {
                unsigned aux = p.elements[i + 1];
                p.elements[i + 1] = p.elements[i];
                p.elements[i] = aux;
            }
        }
    }
    std::cout << "\nExibindo em ordem crescente...";
    std::cout << "\nFila: [";
    for (int i = 0; i < tamanho; i++)
    {
        FilaCrescente.insere(p.desempilha());
        if (i != tamanho - 1)
        {
            std::cout << FilaCrescente.elementos[i] << " ";
        }
        else if (i == tamanho - 1)
        {
            std::cout << FilaCrescente.elementos[i] << "]";
        }
    }
    for (int i = 0; i < tamanho; i++)
    {
        unsigned k = matricula[i] - 48;
        p.empilha(k);
    }
    for (int j = 0; j < tamanho - 1; j++)
    {
        for (int i = 0; i < tamanho - 1; i++)
        {
            if (p.elements[i] > p.elements[i + 1])
            {
                unsigned aux = p.elements[i + 1];
                p.elements[i + 1] = p.elements[i];
                p.elements[i] = aux;
            }
        }
    }
    return 0;
}