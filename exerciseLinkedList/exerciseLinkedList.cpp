#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int rollNumber;
    string name;
    Node* next;
};

class CircularLinkedList {
private:
    Node* LAST;

public:
    CircularLinkedList() {
        LAST = NULL;
    }

    void addNode();
    bool search(int rollno, Node** Ramdani, Node** Rama);
    bool listEmpty();
    bool delNode();
    void traverse();
};

void CircularLinkedList::addNode() { 
    Node* newNode = new Node();
    cout << "\nEnter roll number : ";
    cin >> newNode->rollNumber;
    cout << "Enter name: ";
    cin >> newNode->name;

    if (listEmpty()) { //beginning of the list
        newNode->next = newNode;
        LAST = newNode;
    } 
    else { //between two nodes or end of the list
        Node* Rama = LAST->next;
        Node* Ramdani = NULL;

        while (Rama != LAST && Rama->rollNumber < newNode->rollNumber) {
            Ramdani = Rama;
            Rama = Rama->next;
        }

        if (Rama == LAST && Rama->rollNumber < newNode->rollNumber) { //List terakhir
            newNode->next = Rama->next;
            Rama->next = newNode;
            LAST = newNode;
        }
        else { //between two nodes
            newNode->next = Rama;
            if (Ramdani == NULL) //beginning of the list
                LAST->next = newNode;
            else
                Ramdani->next = newNode;
        }
    }
    cout << "Record added successfully." << endl;

}

bool CircularLinkedList::search(int rollno, Node** Ramdani, Node** Rama) {
    *Ramdani = LAST->next;
    *Rama = LAST->next;

    while (*Rama != LAST) {
        if (rollno == (*Rama)->rollNumber) {
            return true;
        }
        *Ramdani = *Rama;
        *Rama = (*Rama)->next;
    }
    while (*Rama != LAST->next);

    return false;
}

bool CircularLinkedList::listEmpty() {
    return LAST == NULL;
}

bool CircularLinkedList::delNode() { 
    if (listEmpty()) {
        cout << "List empty No records to delete" << endl;
        return false;
    }

    int rollno;
    cout << "Enter the roll number to delete: " << endl;
    cin >> rollno;

    Node* Ramdani;
    Node* Rama;

    if (search(rollno, &Ramdani, &Rama)) {
        if (LAST->next == LAST) { // only one node in the list
            delete  LAST;
            LAST = NULL;
        }
        else if (Rama == LAST) { // End of the list
            LAST = Ramdani;
            Ramdani->next = Rama->next;
            delete Rama;
        }
        else if (Ramdani== LAST) { // Beginning of the list
            LAST->next = Rama->next;
            delete Rama;
        }
        else { // Between two nodes
            Ramdani->next = Rama->next;
            delete Rama;
        }

        cout << "Record with roll number " << rollno << " deleted successfully." << endl;
        return true;
    }
    else {
        cout << "Record with roll number " << rollno << " not found." << endl;
        return false;
    }
}

void CircularLinkedList::traverse() {
    if (listEmpty()) {
        cout << "\nList is empty\n";
    }
    else {
        cout << "\nRecords in the list are:\n";
        Node* RamaNode = LAST->next;
        while (RamaNode != LAST) {
            cout << RamaNode->rollNumber << "   " << RamaNode->name << endl;
            RamaNode = RamaNode->next;
            RamaNode = RamaNode->next;
        }
    }
   
}

int main() {
    CircularLinkedList obj;
    while (true) {
        try {
            cout << "\nMenu" << endl;
            cout << "1. Add a record to the list" << endl;
            cout << "2. Delete a record from the list" << endl;
            cout << "3. View all the records in the list" << endl;
            cout << "4. Exit" << endl;
            cout << "\nEnter your choice (1-5): ";

            char ch;
            cin >> ch;

            switch (ch) {
            case '1': {

            }
            case '2': {

            }
            case '3': {
                obj.traverse();
                break;
            }

            case '4': {
                return 0;
            }
            default: {
                cout << "Invalid option" << endl;
                break;
            }
            }
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}