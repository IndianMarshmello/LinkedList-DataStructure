#include <iostream>
#include <string>

struct Node {
    int val;
    Node *next;
    Node *prev;
};

class LinkedList {
    private:
        Node* head;
        int ListLength;
    public:
        LinkedList();
        LinkedList(const LinkedList& other);
        LinkedList& operator=(const LinkedList& other);
        ~LinkedList();

        // inserters
        void insertAtEnd(int value);
        void insertAtPosition(int pos, int value);

        // deleters
        void deleteNode(int value);

        // print the list
        void traverseList() const;
};

LinkedList::LinkedList() {
    head = nullptr;
    ListLength = 0;
}

LinkedList::LinkedList(const LinkedList& other) {
    if (other.head == nullptr) {
        this->head = nullptr;
        return;
    }

    Node* newNode = new Node;
    newNode->val = other.head->val;
    this->head = newNode;

    Node* curr = this->head;
    Node* otherCurr = other.head;

    while (otherCurr->next != nullptr) {
        Node* newNode = new Node;
        newNode->val = otherCurr->next->val;
        curr->next = newNode;
        curr->next->prev = curr;
        curr = curr->next;
        otherCurr = otherCurr->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other) return *this;

    while(head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    if (other.head == nullptr) {
        head = nullptr;
        return *this;
    }

    head = new Node;
    head->val = other.head->val;
    
    Node* currThis = head;
    Node* currOther = other.head->next;

    while (currOther != nullptr) {
        Node* newNode = new Node;
        newNode->val = currOther->val;
        currThis->next = newNode;

        currThis = currThis->next;
        currOther = currOther->next;
    }

    return *this;
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->val = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        ListLength++;
        return;
    }

    Node* curr = head;
    
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next=newNode;
    newNode->prev = curr;

    ListLength++;

    return;
}

void LinkedList::insertAtPosition(int pos, int value) {
    Node* newNode = new Node;
    newNode->val = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        ListLength++;
    }

    Node* curr = head;

    for (int i = 0; i < pos-1; i++) {
        curr = curr->next;
    }

    Node* temp = curr->prev;
    newNode->prev = curr->prev;
    newNode->next = curr;
    
    curr->prev = newNode;
    temp->next = newNode;

    ListLength++;

    return;
}

void LinkedList::deleteNode(int value) {
    if (head == nullptr) return;

    Node* prev = nullptr;
    Node* curr = head;

    if (head->val == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    while(curr != nullptr && curr->val != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) return;

    prev->next = curr->next;
    prev->next->prev = prev;
    delete curr;

    ListLength--;
    
    return;
}

void LinkedList::traverseList() const {
    Node* curr = head;
    while(curr != nullptr) {
        std::cout << curr->val <<std::endl;
        curr = curr->next;
    }
}