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

        //What is the time complexity of print in big O notation? What would it be in an array representation?
        void print(){
            Node* temp = /* what should we set the temp variable to so that we can iterate through the list? */
            while(/* what condition can we write to make the while loop go through the list without going out of bounds? */){
                cout<<temp->val<<" -> ";
                temp = temp->next;
            }
            cout<<endl;
        }

        /* What is the time complexity of find? What would it be in an array representation? */
        bool find(int val){
            Node* temp = head;
            while(!temp){
                if(temp->val == val){
                    return true;
                }
            }
            return false;
        }

        /* What is the time complexity of removeVal? What would it be in an array representation? */
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

        //What is the time complexity of insert to head in big O notation? What would it be in an array representation?
        void insertToHead(int val){
            Node* newHead = new Node(val);
            /* what do we have to change before setting the head equal to newHead? */
            head = newHead;
            if(!tail){ /* what does the condition below check?*/
                tail = head;
            }
        }

        //What is the time complexity of remove from head in big O notation? What would it be in an array representation?
        int removeFromHead(){
            if(/* what edge case should we check before performing a remove? */){
                return -1;
            }

            Node* toDel = head;
            head = head->next;
            if(!head){
                tail = nullptr;
            }
            /* what would happen if we swap the order of the two lines of code below? */
            int val = toDel->val;
            delete toDel;

            return val;
        }

        //What is the time complexity of insert to tail in big O notation? What would it be in an array representation?
        void insertToTail(int val){
            if(!head){
                head = tail = new Node(val);
                return;
            }
            tail -> next = new Node(val);
            tail = tail -> next;
        }

        //What is the time complexity of remove from tail in big O notation? What would it be in an array representation?
        int removeFromTail(){
            if(!head){
                return -1;
            }

            Node* temp = head;
            Node* toDel = tail;
            int ret = tail->val;
            /* How do we actually remove the tail node? (Hint: change the next pointer of the node before tail) */
            delete toDel;
            return ret;
        }

        /* Which pointers do we need to use for a queue? what about a stack? */

        /* for the for functions, pick one of the four functions above to call for a proper implementation */
        /* hint: enqueue = add to queue, dequeue = remove from queue */
        /* hint: push = add to stack, pop = remove from stack */
        void enqueue(int val){
            /* what function call would go here? */
            /* what is the time complexity? */
        }

        int dequeue(){
            /* what function call would go here? */
            /* what is the time complexity? */
        }

        void push(int val){
            /* what function call would go here? */
            /* what is the time complexity? */
        }

        int pop(){
            /* what function call would go here? */
            /* what is the time complexity? */
        }

        /* what other ways can we implement a queue and a stack? */
        /* what would the time complexity be for those? */
};

int main(){
    LinkedList x;
    x.insertToHead(5);
    x.insertToHead(6);
    x.insertToHead(7);
    x.print();
    for(int i = 0; i <= 3; i++){
        cout<<x.removeFromHead()<<" -> ";
    }
    cout<<endl;
    x.print();
}
