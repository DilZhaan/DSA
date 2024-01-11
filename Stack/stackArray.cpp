#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
class stack{
    
    private:
    
        T* _data;
        int _head;
        int _size;
        int _length;
    
    public:
        
        stack(int Size){
            _head = -1;
            _size = Size;
            _data = new T[Size];
            _length = 0;
        }
        
        void push(T Data){
            if (_head == _size-1 ){
                cout << "stack already fulled" << endl;
                return;
            }
            _data[++_head] = Data;
            _length++;
        }
        
        T pop(){
            if (_head == -1){
                cout << "stack is empty" << endl;
                return T();
            }
            _length--;
            return _data[_head--];
        }
        
        bool empty(){
            if (_size == 0){
                return true;
            }
            return false;
        }

        T head(){
            if (_head == -1){
                cout << "stack is empty" << endl;
                return T();
            }
            return _data[_head];
        }

        int length(){
            return _length;
        }

        ~stack(){
            delete[] _data;
        }
};

int main(){
    stack<int> Stack(5);

    Stack.push(5);
    Stack.push(15);
    Stack.push(25);
    Stack.push(35);
    Stack.push(15);
    Stack.push(25);
    Stack.push(35);

    cout << " is stack empty :" << Stack.empty() << endl;

    cout << "Before POP (Head)  : " << Stack.head() << endl;
    cout << "Before POP (legth) :" << Stack.length() << endl;
    
    cout << "Poped : " << Stack.pop() << endl;

    cout << "After POP (legth) :" << Stack.length() << endl;
    cout << "After POP (Head)  : " << Stack.head() << endl;


    return 0;
}