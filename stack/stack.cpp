/*
Cerința
Să se scrie un program care gestionează o stivă de numere întregi. Inițial stiva este vidă. Programul va citi de la tastatură o listă de operații, care pot fi:

push X – adaugă valoarea întreagă X pe stivă;
pop – elimină elementul din vârful stivei;
top – afișează elementul din vârful stivei.
Programul va realiza asupra stivei operațiile citite, în ordine. Afișările se fac pe ecran, câte o valoare pe linie.

Date de intrare
Programul citește de la tastatură un număr n, apoi cele n operații,

Date de ieșire
Programul va afișa pe ecran numere rezultat ale operațiilor top, câte unul pe o linie.

Restricții și precizări
stiva nu va conține la un moment dat mai mult de 1000 elemente
elementele stivei vor fi cuprinse între -1.000.000 și 1.000.000
dacă la un moment dat se aplică operația pop și stiva nu conține niciun element, operația nu are efect
dacă la un moment dat se aplică operația top și stiva nu conține niciun element, operația nu are efect (nu se afișează nimic)
Exemplu:
Intrare

12
push 5
push 4
top 
push 7 
push -5
pop
top
pop
top
push 11
top
pop
Ieșire

4
7
4
11
Încărcare soluție
*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main()
{
    int n;
    cin >> n;
    Node* top = nullptr; // Pointer to the top of the stack

    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;

        if (operation == "push") {
            int value;
            cin >> value;
            Node* newNode = new Node{value, top};
            top = newNode;
        } else if (operation == "pop") {
            if (top != nullptr) {
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        } else if (operation == "top") {
            if (top != nullptr) {
                cout << top->data << endl;
            }
        }
    }

    // Clean up the stack
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    // No need to return anything, as the program ends here
    // and the stack is cleaned up.
    // However, if you want to return a value, you can return 0.
}