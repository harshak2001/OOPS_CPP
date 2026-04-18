#include<iostream>
using namespace std;

class BaseClass{
    public:
        int x;
        int *y;

    BaseClass(const int _x,const int _y) : x(_x), y(new int(_y)) {}

    //Default dumb copy ctor provided by compiler  // SHALLOW COPY
    // BaseClass(const BaseClass &obj){
    //     this->x = obj.x;
    //     this->y = obj.y;
    // }

    // Smart COPY CTOR // DEEP COPY
    BaseClass(const BaseClass &obj){
        this->x = obj.x;
        this->y = new int(*(obj.y));  //deep copy
    }

    void print(){

        cout<<endl;
        cout << "Value of x = "<< this->x << endl;
        cout << "Address of y = " << this->y <<endl;
        cout << "Value of y = " << *(this->y) <<endl;

        cout<<endl;
    }

    ~BaseClass(){
        delete this->y;
    }
};

int main(){

    BaseClass *b1 = new BaseClass(20,50);

    // BaseClass b2(b1);
    BaseClass b2 = *(b1);

    cout<<"Printing Values of b1"<<endl;
    *(b1->y) = 100;
    b1->print();

    // delete b1; 

    cout<<"Printing Values of b2"<<endl;
    b2.print();

    return 0;
}