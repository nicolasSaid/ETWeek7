#include <stdio.h>
#include <iostream>

using namespace std;

class LinkedList{
    private:
        class Node{
            public:
                int val;
                Node* next;
                Node(){
                    next = nullptr;
                }
                Node(int val){
                    next = nullptr;
                    this->val = val;
                }
        };
    public:
        Node* head;
        Node* tail;
        LinkedList(){
            head = nullptr;
            tail = nullptr;
        }

        //What is the time complexity of print in big O notation? O(N)
        void print(){
            Node* temp = head;
            while(temp != nullptr){
                cout<<temp->val<<" -> ";
                temp = temp->next;
            }
            cout<<endl;
        }

        /* What is the time complexity of find? What would it be in an array representation? O(N) (for a sorted array, O(log(n)) using binary search)*/
        bool find(int val){
            Node* temp = head;
            while(!temp){
                if(temp->val == val){
                    return true;
                }
            }
            return false;
        }

        /* this function removes a value from a list, assuming it is unique*/
        /* What is the time complexity of find? What would it be in an array representation? O(N) for both*/
        bool removeVal(int val){
            if(head && head->val == val){
                Node* del = head;
                head = head->next;
                if(!head){
                    tail = nullptr;
                }
                delete del;
                return true;
            }
            Node* temp = head;
            while(!(temp->next)){
                if(temp->next->val == val){
                    Node* del = head;
                    temp->next = temp->next->next;
                    if(!(temp->next)){
                        tail = temp;
                    }
                    delete del;
                    return true;
                }
            }
            return false;
        }

        //What is the time complexity of insert in big O notation? O(1), O(N) for arrays
        void insertToHead(int val){
            Node* newHead = new Node(val);
            newHead->next = head;
            head = newHead;
            if(!tail){
                tail = head;
            }
        }

        //What is the time complexity of remove in big O notation? O(1), O(N) for arrays
        int removeFromHead(){
            if(!head){
                return -1;
            }

            Node* toDel = head;
            head = head->next;
            if(!head){
                tail = nullptr;
            }
            int val = toDel->val;
            delete toDel;
            return val;
        }

        //O(1), O(N) for dynamic arrays
        void insertToTail(int val){
            if(!head){
                head = tail = new Node(val);
                return;
            }
            tail -> next = new Node(val);
            tail = tail -> next;
        }

        //O(N), O(1) for arrays
        int removeFromTail(){
            if(!head){
                return -1;
            }

            Node* temp = head;
            Node* toDel = tail;
            int ret = tail->val;
            while(temp != nullptr){
                if(temp -> next == tail){
                    temp->next = nullptr;
                    tail = temp;
                }
                temp = temp->next;
            }
            delete toDel;
            return ret;
        }

        void enqueue(int val){
            insertToTail(val);
        }

        int dequeue(){
            return removeFromHead();
        }

        void push(int val){
            insertToHead(val);
        }

        int pop(){
            return removeFromHead();
        }
};

int main(){
    LinkedList x;
    x.push(5);
    x.push(6);
    x.push(7);
    x.print();
    for(int i = 0; i <= 3; i++){
        cout<<x.pop()<<" -> ";
    }
    cout<<endl;
    x.print();
}