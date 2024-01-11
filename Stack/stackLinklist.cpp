#include <iostream>
using namespace std;

template <class T>
class Node{
    private:
        T data;
        Node<T>* next;
        Node<T>* prev;
    public:
        Node(){
            data = T();
            next = nullptr;
            prev = nullptr;
        }
        Node(T Data){
            data = Data;
            next = nullptr;
            prev = nullptr;
        }

        void setNext(Node<int>* Next){
            next = Next;
        }

        void setPrev(Node<int>* Prev){
            prev = Prev;
        }

        T getData(){
            if(!data){
                return T();
            }
            return data;
        }
        
        Node<T>* getNext(){
            return next;
        }
        Node<T>* getPrev(){
            return prev;
        }
        

};

template <class T>
class stack{
    private:
        Node<T>* start;
        Node<T>* end;
        int length;
    public:
        stack(){
            start = nullptr;
            end = nullptr;
            length = 0;
        }

        void push(T data){
            Node<T>* x = new Node<T> (data);
            if (start == nullptr){
                start = x;
                end = start;
            }
            else{
                end->setNext(x);
                x->setPrev(end);
                end = x;           
            }
            length++;
        }

        T pop(){
            if(!length){
                cout << "Empty Stack!!" << endl;
                return T();
            }

            T popedValue = end->getData();

            Node<T>* tmp = end;
            end = end->getPrev();
            delete tmp;
            length--;
            return popedValue;
        }

        T head(){
            if(!length){
                cout << "Empty Stack!!" << endl;
                return T();
            }
            return end->getData();
        }
        bool empty(){
            return (!length)? true : false;
        }
        int len(){
            return length;
        }
};

int main(){
    stack<int> Stack;

    Stack.push(5);
    Stack.push(15);
    Stack.push(25);
    Stack.push(35);
    Stack.push(15);
    Stack.push(25);
    Stack.push(35);

    cout << " is stack empty :" << Stack.empty() << endl;

    cout << "Before POP (Head)  : " << Stack.head() << endl;
    cout << "Before POP (legth) :" << Stack.len() << endl;
    
    cout << "Poped : " << Stack.pop() << endl;

    cout << "After POP (legth) :" << Stack.len() << endl;
    cout << "After POP (Head)  : " << Stack.head() << endl;


    return 0;
}