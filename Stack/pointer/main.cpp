#include <iostream>

using namespace std;

struct Node{
    int elementID;
    Node *lig;
};

typedef Node *Stack;


void addElement(Stack&);
void returnTop(Stack);
void removeElement(Stack&);
void showStack(Stack);

int main(){

    Node *top = new Node;
    top = NULL;

    int menu_command;

    while(true){
        cout << "\n[1] Add Element \n[2] Return Top \n[3] Remove Element\n[4] Show Stack\n[0] Exit" << endl;
        cout << "\nOption: ";
        cin >> menu_command;

        if (menu_command == 0) return false;
        else if (menu_command == 1) addElement(top); 
        else if (menu_command == 2) returnTop(top);
        else if (menu_command == 3) removeElement(top);
        else if (menu_command == 4) showStack(top);
        else cout << "Invalid Command !";
    };

    delete top;

    return 0;

}

void addElement(Stack &top){
    int elementID;

    cout << "\nElement ID: "; 
    cin >> elementID;
    
    Node *aux = new Node;
    aux->elementID = elementID;
    aux->lig = top;
    top = aux;
    cout << "\nElement " << elementID << " on stack !" << endl;

    delete aux;

}

void removeElement(Stack &top){
    top = top->lig;
}

void returnTop(Stack top){
    cout << "\nTop Element on Stack: " << top->elementID <<endl;
}

void showStack(Stack top){
    while(top != NULL){
        cout << "->";
        cout << top->elementID;
        top = top->lig;
    };
}