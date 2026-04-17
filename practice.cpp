#include<iostream>
using namespace std;

class BaseClass{
    public:
    int val;

    void operator + (BaseClass &obj){
        int val1 = this->val;
        int val2 = obj.val;

        cout << val1 - val2;
    }
};

int main(){

  BaseClass obj1,obj2;

  obj1.val = 5;
  obj2.val = 3;

obj1 + obj2;



    return 0;
}