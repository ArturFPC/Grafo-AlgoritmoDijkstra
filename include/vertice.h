#ifndef VERTICE_H
#define VERTICE_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class vertice
{
    public:
        vertice();
        virtual ~vertice();
        int getAntecessor(){return this->antecessor;}
        void setAntecessor(int nAntecessor);
        int getNum(){return this->num;}
        void setNum(int nNum);
        int getDistancia(){return this->distancia;}
        void setDistancia(int nDistancia);
        vector<int> getVizinhos(){return this->vizinhos;}
        void setVizinhos(vector<int> nVizinhos){this->vizinhos = nVizinhos;}//setter para setar todos vizinhos de uma vez
        void setVizinho(int num);
    protected:
        int antecessor;//numero do antecessor
        int num;//numero para pegar a posição do vertice na matriz de adjacencia
        int distancia;
        vector<int> vizinhos;//vetor para armazenar o número dos vizinhos do vértice
    private:
};
vertice::vertice()
{
    //construtor settando todos os antecessores com -1, número como 0, e distancia como 999(representa infinito)
    this->antecessor = -1;
    this->num = 0;
    this->distancia = 999;
}

vertice::~vertice()
{
    //dtor
}

void vertice::setAntecessor(int nAntecessor){
    this->antecessor = nAntecessor;
}
void vertice::setNum(int nNum){
    this->num=nNum;
}
void vertice::setDistancia(int nDistancia){
    this->distancia=nDistancia;
}
void vertice::setVizinho(int num){
    this->vizinhos.push_back(num);
}
#endif // VERTICE_H
