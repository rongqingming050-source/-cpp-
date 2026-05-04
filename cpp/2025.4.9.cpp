#include <iostream>
#define nullptr NULL
class Node {
public:
    int data;
    Node* next;

 Node(int data) : data(data), next(nullptr) {}; 
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        deleteList();
    }

    void createList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAtPosition(int data, int position) {
        if (position == 0) {
            insertAtBeginning(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << "Position out of bounds" << std::endl;
            delete newNode;
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void deleteElement(int key) {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->data != key) {
            previous = current;
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << "Element not found" << std::endl;
        } else {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
        }
    }

    bool findElement(int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool updateElement(int key, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "None" << std::endl;
    }

    void deleteList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void mergeList(LinkedList& otherList) {
        if (head == nullptr) {
            head = otherList.head;
            otherList.head = nullptr;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = otherList.head;
            otherList.head = nullptr;
        }
    }

    LinkedList splitList(int position) {
        if (position == 0) {
            LinkedList newlist;
            newlist.head = head->next;
            head->next = nullptr;
            return newlist;
        }
        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) {
            std::cout << "Position out of bounds" << std::endl;
            return LinkedList();
        }
        LinkedList newlist;
        newlist.head = current->next;
        current->next = nullptr;
        return newlist;
    }
};

int main() {
    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.printList();  // 1 -> 2 -> 3 -> None
    ll.insertAtPosition(4, 1);
    ll.printList();  // 1 -> 4 -> 2 -> 3 -> None
    ll.deleteElement(4);
    ll.printList();  // 1 -> 2 -> 3 -> None
    std::cout << std::boolalpha << ll.findElement(2) << std::endl;  // True
    ll.updateElement(2, 20);
    ll.printList();  // 1 -> 20 -> 3 -> None
    ll.deleteList();
    ll.printList();  // None

    LinkedList ll2;
    ll2.insertAtEnd(4);
    ll2.insertAtEnd(5);
    ll.mergeList(ll2);
    ll.printList();  // 1 -> 20 -> 3 -> 4 -> 5 -> None

    LinkedList ll3 = ll.splitList(2);
    ll.printList();  // 1 -> 20 -> None
    ll3.printList();  // 3 -> 4 -> 5 -> None

    return 0;
}
