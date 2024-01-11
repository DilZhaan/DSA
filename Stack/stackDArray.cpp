#include <iostream>
using namespace std;

template <class T>
class DynamicArray{
    private:
        T* arr;
        int _initialSize;
        int count;
        int dynamicSize;
    public:
        DynamicArray( int Size){
            arr = new T[Size];
            _initialSize = Size;
            count = 0;
            dynamicSize = Size;
        }

        void addValue(T data){
            
            if ( count == dynamicSize ){
                dynamicSize = dynamicSize * 2;
                T* temp = arr;
                arr = new T[dynamicSize];
                for (int i = 0; i < count; i++){
                    arr[i] = temp[i];
                }
                delete[] temp;
            }

            arr[count++] = data;
        }

        T getValue(){
            return arr[count-1];
        }

        void delValue(){
            arr[count--] = T();

            if ( count == dynamicSize / 2 &&  _initialSize <= dynamicSize / 2 ){
                dynamicSize = _initialSize / 2;
                T* temp = arr;
                arr = new T[dynamicSize];
                for (int i = 0; i < count; i++){
                    arr[i] = temp[i];
                }
                delete[] temp;
            }
        }

        int len(T* var){
            return sizeof(var)/sizeof(T);
        }

        ~DynamicArray(){
            delete[] arr;
        }
};

template <class T>
class stack{
    private:
        DynamicArray<T>* _data;
        int _length;
    public:
        stack(int Size){
            _data = new DynamicArray<T>(Size);
            _length = 0;
        }
        
        void push(T Data){
            _data->addValue(Data);
            _length++;
        }
        
        T pop(){
            T popedValue = _data->getValue();
            _data->delValue();
            _length--;
            return popedValue;
        }
        
        bool empty(){
            if (_length == 0){
                return true;
            }
            return false;
        }

        T head(){
            return _data->getValue();
        }
        int length(){
            return _length;
        }
        ~stack(){
            delete[] _data;
        }
};

int main(){
    stack<int> Stack(2);

    Stack.push(5);
    Stack.push(15);
    Stack.push(25);
    Stack.push(35);
    Stack.push(45);
    Stack.push(55);
    Stack.push(65);

    cout << " is stack empty :" << Stack.empty() << endl;

    cout << "Before POP (Head)  : " << Stack.head() << endl;
    cout << "Before POP (legth) :" << Stack.length() << endl;
    
    cout << "Poped : " << Stack.pop() << endl;

    cout << "After POP (legth) :" << Stack.length() << endl;
    cout << "After POP (Head)  : " << Stack.head() << endl;


    return 0;
}