#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* getIntersectionNode(Node* list1, Node* list2) {
    while (list2) {
        Node* temp = list1;
        while (temp) {
            if (temp == list2)
                return list2;
            temp = temp->next;
        }
        list2 = list2->next;
    }
    return nullptr;
}