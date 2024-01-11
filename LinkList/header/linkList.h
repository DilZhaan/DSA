#ifndef linkList_h
#define linkList_h
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
            data = nullptr;
            next = nullptr;
            prev = nullptr;
        }
        Node(T Data){
            data = Data;
            next = nullptr;
            prev = nullptr;
        }
        Node<T>* getNext(){
            return next;
        }
        Node<T>* getPrev(){
            return prev;
        }
        void setNext(Node<T>* Next){
            next = Next;
        }
        void setPrev(Node<T>* Prev){
            prev = Prev;
        }
        T getData(){
            return data;
        }
};

template <class T>
class linkList{
    private:
        Node<T>* start;
        Node<T>* end;

        void deleteOperation(Node<T>* ptr){
            Node<T>* rightNeighbour = ptr->getNext();
            Node<T>* leftNeighbour = ptr->getPrev();


            if(rightNeighbour && leftNeighbour){
                leftNeighbour->setNext(rightNeighbour); 
                rightNeighbour->setPrev(leftNeighbour);
            }
            else if (leftNeighbour){
                leftNeighbour->setNext(nullptr);
                end = leftNeighbour;
            }
            else if (rightNeighbour){
                start = rightNeighbour;
                start->setPrev(nullptr);
            }
            delete ptr;
            length--;
        }
    public:
        int length;

        linkList(){
            start = nullptr;
            end = nullptr;
            length = 0;
        }
        void insert(T Data){
            Node<T>* obj = new Node<T> (Data);
            if(start == nullptr && end == nullptr){
                start = obj;
                end = start;
            }else{
                obj->setPrev(end);
                end->setNext(obj);
                end = obj;
            }
            length++;
        }
        void drop(){
            Node<T>* temp = end;
            end = end->getPrev();
            end->setNext(nullptr);
            delete temp;
            length--;
        }

        void remove(T value){
            Node<T>* ptr = end;
            bool isFound = false;
            while(ptr != nullptr && !isFound){
                if(value != ptr->getData()){
                    ptr = ptr->getPrev();
                    continue;
                }
                isFound = true;
                deleteOperation(ptr);
                break;
            }
            if(!isFound)
                cout << "Removing Value is not exist!" << endl;
        }

        void removeByID(int index){
            if(index < 0 || index >= length){
                cout << "INVALID INDEX!!" << endl;;
                return;
            }
            Node<T>* ptr = start;
            for(int i = 0; i != index; i++){
                ptr = ptr->getNext();
            }
            deleteOperation(ptr);
        }

        T search(int index){
            if(index < 0 || index >= length){
                cout << "INVALID INDEX!!" << endl;;
                return T();
            }
            Node<T>* ptr = start;
            for(int i = 0; i != index; i++){
                ptr = ptr->getNext();
            }

            return ptr->getData();
        }

        void print(){
            Node<T>* ptr = start;
            int count = 1;
            while(ptr != nullptr){
                cout << ptr->getData();
                if(count != length) cout << "-->";
                ptr = ptr->getNext();
                count++;
            }
            cout << endl;
        }

        void printRev(){
            Node<T>* ptr = end;
            int count = 1;
            while(ptr != nullptr){
                cout << ptr->getData();
                if(count != length) cout << "<--";
                ptr = ptr->getPrev();
                count++;
            }
            cout << endl;
        }


};

#endif