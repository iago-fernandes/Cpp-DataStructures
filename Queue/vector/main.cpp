#include <iostream>

using namespace std;

#define SIZE 10

struct Node {
  int Value;
};

struct Queue {
   Node Data[SIZE];
   int size;
   int first;
   int last;
};


bool addElement (Queue&);
bool queueStatus (Queue);
bool removeElement(Queue&);

int main (){

    Queue Q;
    Q.last = -1;
    Q.first = 0;
    Q.size = 0;

    int menu_command;

    while(true){
        cout << "\n\n[1] Add Element \n[2] Remove Element \n[3] Show Queue \n[0] Exit" << endl;
        cout << "\nOption: ";
        cin >> menu_command;

        if (menu_command == 1) addElement(Q);
        else if (menu_command == 2) removeElement(Q);
        else if (menu_command == 3) queueStatus(Q);
        else if (menu_command == 0) return false;
        else {cout << "invalid option !"; return true;}
    };
 return 0;
}

bool addElement (Queue& Q) {
    Node aux;

    cout << "\nElement value: ";
    cin >> aux.Value;

    if (Q.size == SIZE){
        cout << "\nFull Queue, remove element first";
        return false;
    }
        
    Q.size++;
    Q.last = (Q.last + 1) % SIZE;
    Q.Data[Q.last] = aux;
    return true;
}

bool queueStatus (Queue Q){

    if (Q.size == 0){
        cout << "Empty Queue !";
        return false;
    } 

    for (int i = 0; i < Q.size; i++){
            cout << " -> ";
            cout << Q.Data[i].Value;
        }
    return true;
}


bool removeElement(Queue& Q){
    if (Q.size == 0){
        cout << "\nCan't remove, no elements on Queue.";
        return false;
    }

    int aux = Q.Data[Q.first].Value;
    for (int i=0; i < (Q.size - 1); i++){
        Q.Data[i].Value = Q.Data[i+1].Value;
    }
    cout << "\n" << aux << " out of line.";
    Q.size--;
    return true;
}