#include<iostream>
using namespace std;

class BaseClass{

    private:
        int x;
        int y;
        int z;

    public : 

        BaseClass(const int _x,const int _y,const int _z = 10){
            // _x = 30; // ANyone can modify here if we didnt use const
            this->x = _x;
            this->y = _y;
            this->z = _z;
        }

        void setX(const int _x){
            this->x = _x;
        }

        int getX() const{
            return this->x ;
        }

        void printValueOfX() const {
            cout<<"Value of x is "<<getX()<<endl;
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

    b.setX(20);
    b.printValueOfX();
    return 0;
}