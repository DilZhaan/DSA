#include <iostream>
#include <string>
using namespace std;

class myCLass{
    private:
        int x;
    public:
        myCLass(){
            x=0;
        }
        myCLass(const myCLass& obj){
            x = obj.x;
            cout << "Copied " << &obj << " to " << this <<endl;
        }
        int getter(string msg){
            cout << msg << " Value is " << x <<  "\t\t" << this << endl;
        }
        void setter(int data){
            x = data;
        }
};

int main(){
    myCLass c1;
    c1.setter(5);
    c1.getter("C1");

    myCLass C2;
    C2.setter(10);
    C2.getter("C2");

    myCLass C3 = C2;
    C3.getter("C3");

    myCLass& C4 = C3;
    C4.setter(20);
    C4.getter("C4");

    myCLass* C5 = &C3;
    C5->setter(25);
    C5->getter("C5");



    cout << endl << endl;

    c1.getter("C1");
    C2.getter("C2");
    C3.getter("C3");
    C4.getter("C4");
    C5->getter("C5");
}