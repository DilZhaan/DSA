#include <iostream>
using namespace std;

template <class T>
class Node{
    private:
        T data;
        Node<T>* next;
    public:
        Node(){
            data = T();
            next = nullptr;
        }
        Node(T Data){
            data = Data;
            next = nullptr;
        }
        void setNext(Node<T>* Next){
            next = Next;
        }
        T getData(){
            return data;
        }

        Node<T>* getNext(){
            return next;
        }
};

template <class T>
class Queue{
    private:
        Node<T>* start;
        Node<T>* end;
    public:
        int length;
        Queue(){
            start = nullptr;
            end = nullptr;
            length = 0;
        }
        void enqueue(T data){
            Node<T>* x = new Node<T>(data);
            if (!start){
                start = x;
                end = start;
            }
            else{
                end->setNext(x);
                end = x;
            }
            length++;
        }
        T dequeue(){
            if (!start){
                cout << " Queue is already empty!" << endl;
                return T();
            }

            Node<T>* tmp = start;
            start = start->getNext();
            T data = tmp->getData();
            delete tmp;
            length--;
            return data;
        }
};

int main(){

    Queue<int> q;

    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);

    cout << "length is ---------------------: " << q.length << endl;
    cout << "dequed data :" << q.dequeue() << endl;

    cout << "length is ---------------------: " << q.length << endl;
    cout << "dequed data :" << q.dequeue() << endl;

    cout << "length is ---------------------: " << q.length << endl;
    cout << "dequed data :" << q.dequeue() << endl;

    cout << "length is ---------------------: " << q.length << endl;
    cout << "dequed data :" << q.dequeue() << endl;

    cout << "length is ---------------------: " << q.length << endl;
    cout << "dequed data :" << q.dequeue() << endl;

    cout << "length is ---------------------: " << q.length << endl;
    cout << "dequed data :" << q.dequeue() << endl;

    cout << "length is ---------------------: " << q.length << endl;
    cout << "dequed data :" << q.dequeue() << endl;

    return 0;
}