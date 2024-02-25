#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

node *head = NULL;
node *rear = NULL;

void insertAtFirst();
void insertAtLast();
void insertAtIndex(int index);

void removeAtFirst();
void removeAtLast();
void removeAtIndex(int index);

void insert() {
    int index;
    int choice;
    cout << "\n1.At First\n2.At Last\n3.At Index\nEnter Choice\n";
    cin >> choice;

    switch (choice) {
        case 1:
            insertAtFirst();
            break;
        case 2:
            insertAtLast();
            break;
        case 3:
            cout << "Enter index on which you want to insert\n";
            cin >> index;
            insertAtIndex(index);
            break;
        default:
            cout << "Invalid Choice\n";
    }
}

void insertAtFirst() {
    node* newnode = new node();
    cout << "Enter data to insert\n";
    cin >> newnode->data;

    if (head == NULL) {
        head = rear = newnode;
        rear->next = head;
    } else {
        newnode->next = head;
        head = newnode;
        rear->next = head;
    }
}

void insertAtLast() {
    node* newnode = new node();
    cout << "Enter data to insert\n";
    cin >> newnode->data;

    if (rear == NULL) {
        head = rear = newnode;
        rear->next = head;
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = head;
    }
}

void insertAtIndex(int index) {
    node* newnode = new node();
    cout << "Enter data to insert\n";
    cin >> newnode->data;

    if (head == NULL && index == 0) {
        head = rear = newnode;
        rear->next = head;
    } else {
        node* temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;

        if (index == 0) {
            head = newnode;
            rear->next = head;
        }
    }
}

void remove() {
    int choice;
    cout << "\n1.At First\n2.At Last\n3.At Index\nEnter Choice\n";
    cin >> choice;

    switch (choice) {
        case 1:
            removeAtFirst();
            break;
        case 2:
            removeAtLast();
            break;
        case 3:
            int index;
            cout << "Enter index from which you want to remove\n";
            cin >> index;
            removeAtIndex(index);
            break;
        default:
            cout << "Invalid Choice\n";
    }
}

void removeAtFirst() {
    if (head == NULL) {
        cout << "List is empty. Cannot remove from an empty list.\n";
        return;
    }

    node* temp = head;
    head = head->next;

    if (head == NULL) {
        rear = NULL;
    } else {
        rear->next = head;
    }

    free(temp);
}

void removeAtLast() {
    if (rear == NULL) {
        cout << "List is empty. Cannot remove from an empty list.\n";
        return;
    }

    if (head == rear) {
        free(head);
        head = rear = NULL;
    } else {
        node* temp = head;
        while (temp->next != rear) {
            temp = temp->next;
        }
        temp->next = head;
        free(rear);
        rear = temp;
    }
}

void removeAtIndex(int index) {
    if (head == NULL) {
        cout << "List is empty. Cannot remove from an empty list.\n";
        return;
    }

    if (index == 0) {
        removeAtFirst();
    } else {
        node* temp = head;
        node* prev = NULL;

        for (int i = 0; i < index && temp->next != head; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == head) {
            cout << "Invalid index. Index out of bounds.\n";
            return;
        }

        prev->next = temp->next;

        if (temp == rear) {
            rear = prev;
        }

        free(temp);
    }
}

void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    int choice;

    do {
        cout << "\n1.Insert\n2.Remove\n3.Display\n4.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                remove();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }
    } while (choice != 4);

    return 0;
}
