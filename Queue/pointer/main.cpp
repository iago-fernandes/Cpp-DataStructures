#include <iostream>

using namespace std;

struct info{
    int id;
    info *lig;
};

typedef info *Queue;

struct line{
    info *Beg;
    int qnt;
    info *End;
};

void addQueue(line&);
void beginQueue(line&);
void first(int);
void last(int);
void length(int);
void removeElement(line&);
bool emptyQueue(line&);

int main(){

    int menu_command;
    line Line;
    beginQueue(Line);

    while(true){
        cout << "\n[1] Add to queue\n[2] First element \n[3] Last element \n[4] Line length\n[5] Remove element\n[0] Exit\n\nOption: ";
        cin >> menu_command;
        if (menu_command == 0) return 0;
        else if(menu_command == 1) addQueue(Line);
        else if (menu_command == 2) first(Line.Beg->id);
        else if (menu_command == 3) last(Line.End->id);
        else if (menu_command == 4) length(Line.qnt);
        else if (menu_command == 5) removeElement(Line);
        else cout << "\nInvalid Option.\n";
    }
    return 0;
}

bool emptyQueue(line& Line){
    if(Line.Beg == NULL)
        return true;
    return false;
}

void removeElement(line& Line){
    if(emptyQueue(Line)){
        cout << "\nEmpty Queue\n";
    }
    else{
        Queue aux = new info;
        aux = Line.Beg;
        Line.Beg = Line.Beg->lig;
        cout << aux->id << " Removed !";
    }
    Line.qnt--;
}

void length(int qnt){
    cout << "\nLine length: " << qnt << endl;
}

void first(int Beg){
    cout << "\nFirst on Line: " << Beg << endl;
}

void last(int End){
    cout << "\nLast on line: " << End << endl;
}

void beginQueue(line& Line){
    Line.qnt = 0;
    Line.Beg = NULL;
    Line.End = NULL;
}

void addQueue(line& Line){
    int element_info;
    cout << "\nElement info: ";
    cin >> element_info;
    Queue new_element = new info;
    new_element->id = element_info;
    new_element->lig = NULL;
    if(Line.qnt == 0){
        Line.Beg = Line.End = new_element;
    }
    else{
        Line.End->lig = new_element;
        Line.End = new_element;
    }
    Line.qnt++;
}
