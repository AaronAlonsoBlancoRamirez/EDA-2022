#include <iostream>
#include <random>
using namespace std;
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>



const int elementos = 10000;
const int dimension = 10;

void llenado(int dist[][dimension]) {


    int number;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 100);


    //de acuerdo a la dimension se creara una matriz
    // de tamaño elementos*dimension y almacenara los datos
    //aleatorios




    //insercion de datos aleatorios 
    for (int i = 0; i < elementos; ++i) {
        for (int j = 0; j < dimension; j++) {

            number = distribution(generator);

            dist[i][j] = number;

        }
    }
}

void print(int m[][dimension]) {
    for (int i = 0; i < elementos; i++) {
        for (int j = 0; j < dimension; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void distancia_euclidiana(int arr[][dimension]) {

    float sumatoria = 0, resta;
    int distancia;

    //SACA LAS DISTANCIAS DEL NUMERO DE ELEMENTOS SEGUN EL TAMAÑO DE DIMENSION  
    for (int i = 1; i < elementos; ++i)
    {
        for (int j = 0; j < dimension; j++) {

            resta = arr[i][j] - arr[0][j];
            distancia = pow(resta, 2);
            sumatoria = sumatoria + distancia;




        }
        sumatoria = sqrt(sumatoria);
        // cout<<"elemento: "<<i<<" distancia: "<<sumatoria<<endl;
        sumatoria = 0;
        
    }
}



int main() {


    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    int arr[elementos][dimension];
    llenado(arr);
    //print(arr);
    distancia_euclidiana(arr);



    end = std::chrono::high_resolution_clock::now();
    int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); // duration is holding the elapsed time

    cout << duration;


}
