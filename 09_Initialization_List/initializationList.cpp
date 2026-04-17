#include<iostream>
using namespace std;

class BaseClass{

    private:
        int x;
        const int y;
        int z;

    public : 

        // With normal CTOR
        // BaseClass(const int _x,const int _y,const int _z = 10){
        //     this->x = _x;
        //     this->y = _y; // Error expression must be a modifiable lvalue
        //     this->z = _z;
        // }

        // With initialization_list
        BaseClass(int _x,int _y,int _z = 10) : x(_x),y(_y),z(_z){
            cout<<"All values set"<<endl;
        }

        void print(){
            cout<<endl;

            cout << "x = " << this->x<<endl;
            
            cout << "y = " << this->y<<endl;
            
            cout << "z = " << this->z<<endl;
        }

};


int main(){

    BaseClass b(12,22,33);
    b.print();

    return 0;
}