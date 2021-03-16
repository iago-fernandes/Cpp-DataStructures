#include <iostream>

using namespace std;

#define SIZE 3

struct Module{
    int value;
};

struct Stack{
    Module Data[SIZE];
    int top;
};

void addItem(Stack&);
void removeItem(Stack&);
bool fullStack(int);
bool emptyStack(int);
void stackStatus(Stack);

int main()
{
    Stack my_stack;
    my_stack.top = -1;
    int menu_command;

    while(true){
        cout << "\n\n[1] Add item\n[2] Remove item\n[3] Stack Status\n[0] Exit\n";
        cout << "\nOption: ";
        cin >> menu_command;
        if(menu_command == 1) addItem(my_stack);
        else if (menu_command == 2) removeItem(my_stack);
        else if (menu_command == 3) stackStatus(my_stack);
        else if (menu_command == 0) return 0;
    }
    return 0;
}

void removeItem(Stack &myStack){
    if(emptyStack(myStack.top)){
        cout << "\nEmpty Stack !";
    }
    else{
        Module aux;
        aux = myStack.Data[myStack.top--];
        cout << aux.value << "\n Removed !";
    }
}

void stackStatus(Stack myStack){
    cout << "\nTop index: " << myStack.top;
    cout << "\nFree spaces: " << (SIZE - myStack.top) - 1;

}

bool emptyStack(int top){
    if(top == -1) return true;
    return false;
}

bool fullStack(int top){
    if(top == SIZE-1) return true;
    return false;
}

void addItem(Stack &my_stack){
    if(fullStack(my_stack.top)){
        cout << "\nFull Stack ! You have to remove an element first !";
    }
    else{
        Module aux;
        cout << "\nValue: ";
        cin >> aux.value;
        my_stack.Data[++my_stack.top] = aux;
        cout << "\nData Created !\n";
    }
}
