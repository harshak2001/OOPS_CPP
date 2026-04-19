#include <iostream>
using namespace std;


class BaseClass{
    private:
        int x;
    protected:
        int y;
    public:
        BaseClass(const int _x,const int _y){
            this->x = _x;
            this->y = _y;
        }

        void setX(const int _x){
            this->x = _x;
        }
        int getX() const {
            return this->x;
        }

        friend class ChildClass;
        friend void printBaseClassValues(const BaseClass &obj);
};

class ChildClass{
    public:
    void printBaseClassValues(const BaseClass &obj) const {
        cout<<"Printing Values in Friend class"<<endl;
        cout << obj.x<<endl;
        cout << obj.y <<endl;
    }

     void memberFunction(const BaseClass &obj) const {
        cout<<"Printing Values in Friend Member function"<<endl;
        cout << obj.x<<endl;
        cout << obj.y <<endl;
    }
};

void printBaseClassValues(const BaseClass &obj){
    cout<<"Printing Values in Globa; Friend function"<<endl;
    cout << obj.x<<endl;
    cout << obj.y <<endl;
}

int main(){
    BaseClass b(10,20);
    b.setX(2);

    ChildClass c;
    c.printBaseClassValues(b);

    printBaseClassValues(b);

    return 0;
}