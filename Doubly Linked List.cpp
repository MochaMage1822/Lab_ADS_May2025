#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

DNode* head = NULL;


void addNode(int value) {
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        DNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}


void displayList() {
    DNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void deleteNode(int value) {
    DNode* temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) return; // Not found

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // Delete head
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int main() {
    addNode(10);
    addNode(20);
    addNode(30);
    cout << "List: ";
    displayList();

    deleteNode(20);
    cout << "After deleting 20: ";
    displayList();

    return 0;
}
