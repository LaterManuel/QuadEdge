#include <iostream>
#include <vector>
using namespace std;
struct point{
    int latitud, longitud;
    point(int latitud, int longitud): latitud(latitud), longitud(longitud){}
    void print_point(){
        cout<<"Latitud: "<<latitud<<endl;
        cout<<"Longitud: "<<longitud<<endl;
    }

};
struct edge{
    int distancia;
    point origen, destino;
    edge()
};
struct node{
    bool isLeaf;
    edge* arista;
    node* next;
    node(){
        isLeaf = false;
        next = nullptr;
    }
    node(edge* arista): arista(arista){
        isLeaf = true;
        next = nullptr;
    }
};

struct quadtree{
    int minLat, maxLat, minLong, maxLong;
    node* root;
    vector <edge*> aristas;
    vector <quadtree*> children;
    quadtree(){
        minLat = 0;
        maxLat = 0;
        minLong = 0;
        maxLong = 0;
        root = new node();

    }
    void insert(edge* arista){
        if(!root->isLeaf){
            root->isLeaf=true;
            aristas.push_back(arista);
        }
        else{
            if(aristas.size()==4){
                cout<<"Error, no se puede insertar mas aristas"<<endl;
                //
            }
            else{
                aristas.push_back(arista);
                cout<< "Dato insertado: ";arista->print_edge();
            }
        }

    }
};;

int main() {
    quadtree quadtest;
    edge arista1(1,2,3);
    edge arista2(4,5,6);
    edge arista3(7,8,9);
    edge arista4(10,11,12);
    // Insertar aristas
    quadtest.insert(&arista1);
    quadtest.insert(&arista2);
    quadtest.insert(&arista3);
    quadtest.insert(&arista4);
    quadtest.insert(&arista1);
}