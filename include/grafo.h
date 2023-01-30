#ifndef GRAFO_H
#define GRAFO_H
#include "vertice.h"
#include <queue>
#include <vector>
using namespace std;
class grafo
{
    public:
        grafo();
        virtual ~grafo();
        //getters and setters
        vector<vector<int>> getMA(){return this->mAdjacencia;}
        void setMA(vector<vector<int>> nMA){this->mAdjacencia = nMA;}
        vector<vertice> getV(){return this->v;}
        void setV(vector<vertice> nV){this->v = nV;}
        //Método para montar o grafo
        void montarGrafo(vector<vector<int>> ma, int origem);
        void calcularMenorCaminho(int p);
        void dijkstra();
        void mostrarGrafo();

    protected:
        vector<bool> vProcessados; //vetor para verificar se o vertice em uma posição do vector ja foi processado
        vector<vector<int>> mAdjacencia;
        vector<vertice> v;//vetor para armazenar os vertices pertencentes ao grafo
    private:
};
grafo::grafo()
{
    //ctor
}

grafo::~grafo()
{
    //dtor
}
void grafo::montarGrafo(vector<vector<int>> ma, int origem){
    this->mAdjacencia = ma;
    for (unsigned int i = 0; i<ma.size();i++){
        vertice aux;
        aux.setNum(i);
        for (unsigned int i2 = 0; i2<ma.size();i2++){
            if (ma[i][i2]!= 0){//se esta posição na matriz for diferente de zero, significa que o vertice i é vizinho do vertice i2
                aux.setVizinho(i2);
            }
        }
        this->vProcessados.push_back(false);
        if (i == origem){
            aux.setDistancia(0);
        }
        this->v.push_back(aux);
    }
}
void grafo::calcularMenorCaminho(int p){
    this->vProcessados[p]=true;
    vector<int> vizinhos = v[p].getVizinhos();
    for (int i = 0; i<vizinhos.size();i++){
        int dt = v[p].getDistancia()+mAdjacencia[p][vizinhos[i]];//distancia total do vértice com o possivel antencessor
        if (dt<v[vizinhos[i]].getDistancia()){
            this->v[vizinhos[i]].setDistancia(dt);
            this->v[vizinhos[i]].setAntecessor(p);
        }
    }
    dijkstra();
}
void grafo::dijkstra(){
    int menor = 999;//variavel para obter o menor valor de distancia
    int mVertice = -1;// variavel para obter o vértice com o menor valor de distância
    for (int i = 0; i<v.size();i++){
        if (vProcessados[i]==false && v[i].getDistancia() < menor){
            menor = v[i].getDistancia();
            mVertice= i;
        }
    }
    if (mVertice != -1){//verificação para saber se todos os vértices foram processados
        calcularMenorCaminho(mVertice);
    }
}
void grafo::mostrarGrafo(){
    for (int i = 0; i< v.size();i++){
        cout<<"Vértice numero: "<<i<<endl;
        cout<<"Tamanho: "<<v[i].getDistancia()<<endl;
        if (v[i].getAntecessor() != -1){
            cout<<"Antecessor: "<<v[i].getAntecessor()<<endl;
        }else{
            cout<<"Antecessor: não possui"<<endl;
        }
        cout<<"//////////////"<<endl;
    }

}
#endif // GRAFO_H
