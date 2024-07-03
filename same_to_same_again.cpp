#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int val;
        Node* next;
        Node* prev;
};
class myStack {
    public:
        Node* head = NULL;
        void push(int val){
            Node* tmp = new Node();
            tmp->val = val;
            tmp->next = head;
            tmp->prev = NULL;
            if (head != NULL){
                head->prev = tmp;
            }
            head = tmp;
        }
        int pop() {
            if (head == NULL) {
                return -1;
            }
            Node* tmp = head;
            int val = tmp->val;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete(tmp);
            return val;
        }
};
class myQueue {
    public:
        Node* head = NULL;
        Node* tail = NULL;
        void enQueue(int val) {
            Node* tmp = new Node();
            tmp->val = val;
            tmp->next = NULL;
            tmp->prev = tail;
            if (tail != NULL) {
                tail->next = tmp;
            }
            tail = tmp;
            if (head == NULL) {
                head = tail;
            }
        }
        int reQueue() {
            if (head == NULL) {
                return -1;
            }
            Node* tmp = head;
            int val = tmp->val;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL; 
            }
            delete(tmp);
            return val; 
        }
};
