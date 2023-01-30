#include <iostream>
#include "grafo.h"
using namespace std;

int main()
{
    //Matriz de adjacencia a ser colocada no grafo
    vector<vector<int>> ma = {{0,10,0,5,0},{0,0,1,2,0},{0,0,0,0,4},{0,3,9,0,2},{7,0,6,0,0}};
    //Instanciando o objeto grafo
    grafo g;
    //Montando o grafo
    g.montarGrafo(ma,0);
    //Realizando o algoritmo de Dijkstra em cima do grafo montado
    g.dijkstra();
    //Mostrando o grafo
    g.mostrarGrafo();
    return 0;
}
