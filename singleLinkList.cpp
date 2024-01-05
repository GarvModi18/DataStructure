#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node() : data(0), next(nullptr) {}
};

Node* start = nullptr;
Node* rear = nullptr;

void insertAtStart() {
    int value;
    cout << "Enter value to insert at the beginning: ";
    cin >> value;

    Node* newNode = new Node();
    newNode->data = value;

    if (start == nullptr) {
        start = rear = newNode;
    } else {
        newNode->next = start;
        start = newNode;
    }
}

void insertAtEnd() {
    int value;
    cout << "Enter value to insert at the end: ";
    cin >> value;

    Node* newNode = new Node();
    newNode->data = value;

    if (start == nullptr) {
        start = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void insertAtIndex() {
    int value, index;
    cout << "Enter value to insert: ";
    cin >> value;

    cout << "Enter index to insert at: ";
    cin >> index;

    if (index == 0) {
        insertAtStart();
    } else {
        Node* newNode = new Node();
        newNode->data = value;

        Node* current = start;
        for (int i = 0; i < index - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            cout << "Invalid index." << endl;
        }
    }
}

void deleteAtStart() {
    if (start == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node* temp = start;
    start = start->next;
    delete temp;
}

void deleteAtEnd() {
    if (start == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    if (start->next == nullptr) {
        delete start;
        start = rear = nullptr;
        return;
    }

    Node* current = start;
    while (current->next != rear) {
        current = current->next;
    }

    delete rear;
    rear = current;
    rear->next = nullptr;
}

void deleteAtIndex() {
    int index;
    cout << "Enter index to delete: ";
    cin >> index;

    if (index == 0) {
        deleteAtStart();
    } else {
        Node* current = start;
        for (int i = 0; i < index - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current != nullptr && current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            cout << "Invalid index." << endl;
        }
    }
}

void search() {
    int value;
    cout << "Enter value to search: ";
    cin >> value;

    Node* current = start;
    int index = 0;
    while (current != nullptr) {
        if (current->data == value) {
            cout << "Value found at index " << index << endl;
            return;
        }
        current = current->next;
        ++index;
    }
    cout << "Value not found in the list." << endl;
}

void display() {
    Node* current = start;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void createList() {
    int value;
    cout << "Enter values to create the linked list (-1 to stop):\n";
    cin >> value;

    while (value!=-1) {

        Node *newnode=new Node();        
        newnode->data=value;
        newnode->next=NULL;
        if(start==NULL){
            start=rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
        }
        cout << "Enter values to create the linked list (-1 to stop):\n";
        cin >> value;
        
    }
}

void displayMenu() {
    cout << "\nMENU:\n";
    cout << "1. Insert at the beginning\n";
    cout << "2. Insert at the end\n";
    cout << "3. Insert at a specific index\n";
    cout << "4. Delete at the beginning\n";
    cout << "5. Delete at the end\n";
    cout << "6. Delete at a specific index\n";
    cout << "7. Search for a value\n";
    cout << "8. Display the list\n";
    cout << "9. Exit\n";
}

int main() {
    createList();  // Call createList to initialize the linked list

    int choice;
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertAtStart();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtIndex();
                break;
            case 4:
                deleteAtStart();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                deleteAtIndex();
                break;
            case 7:
                search();
                break;
            case 8:
                cout << "Linked list: ";
                display();
                break;
            case 9:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
