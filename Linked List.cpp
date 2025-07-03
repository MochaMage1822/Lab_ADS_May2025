#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


void addNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void displayList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void deleteNode(int value) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // Not found

    if (prev == NULL) {
        head = temp->next; // Delete head
    } else {
        prev->next = temp->next;
    }

    delete temp;
}

int main() {
    addNode(1);
    addNode(2);
    addNode(3);
    cout << "List: ";
    displayList();

    deleteNode(2);
    cout << "After deleting 2: ";
    displayList();

    return 0;
}
