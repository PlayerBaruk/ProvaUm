#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

template <typename Tipo>
struct Pilha{
    Tipo *elementos;
    unsigned maximo; //tamanho da pilha
    int topo;
    Pilha(unsigned tam){
        maximo = tam;
        topo = -1;
        elementos = new Tipo[maximo];
    }

    ~Pilha(){
        delete []elementos;
    }

    void empilha(Tipo x){
        topo++;
        elementos[topo]=x;
    }

    Tipo desempilha(){
        Tipo temp = elementos[topo];
        topo--;
        return temp;
    }

    Tipo elementodotopo(){
        return elementos[topo];
    }

    bool pilhacheia(){
        return topo == maximo-1;
    }

    bool pilhavazia(){
        return topo == -1;
    }

    bool qtdedeelementos(){
        return topo+1;
    }



};




#endif // PILHA_H_INCLUDED
