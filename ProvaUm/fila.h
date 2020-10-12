#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

template <typename Tipo>
struct Fila {
    Tipo *elementos;
    unsigned tamanho;
    int fim, inic,qtde;

    Fila(unsigned tam){
        tamanho=tam;
        elementos= new Tipo[tamanho];
        fim= -1;// valor inicial
        inic = 0;
        qtde=0 ;
    }
~ Fila(){
    delete []elementos;}// libera o espaco alocado pelo ponteiro

    void insere( Tipo x){
    fim++;
    if(fim== tamanho){
        fim=0;// quando chegou ao ultimo numero correspondente ao tamanho o proximo a ser inserido vai ocupar o 0, como se fosse circular.
    }

    elementos[fim]=x;
    qtde++;
    }

    Tipo remover(){

    Tipo temp = elementos[inic];
    inic++;
    if (inic==tamanho){
        inic=0;}
        qtde--;
        return temp;}

    Tipo primeiro(){
    return elementos[inic];}

    bool filavazia(){
    return qtde==0;
    }
    bool filacheia(){
    return qtde==tamanho;}
};

#endif // FILA_H_INCLUDED
