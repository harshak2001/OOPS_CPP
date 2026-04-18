#if !defined(BIRD_H)
#define BIRD_H
#include<iostream>
using namespace std;

class Bird{
    public:
        virtual void eat() = 0; //pure virtual function
        virtual void sleep() = 0; //pure virtual function

        //Classes that inherits this class has to 
        //implement pure virtual functions
        
};

class Sparrow : public Bird{
    private:
        void eat(){
            cout<<"Sparrow is eating"<<endl;
        }

        void sleep(){
            cout<<"Sparrow is sleeping"<<endl;
        }

};
class Eagle : public Bird{
    private:
        void eat(){
            cout<<"Eagle is eating"<<endl;
        }

        void sleep(){
            cout<<"Eagle is sleeping"<<endl;
        }

};
class Pigeon : public Bird{
    private:
        void eat(){
            cout<<"Pigeon is eating"<<endl;
        }

        void sleep(){
            cout<<"Pigeon is sleeping"<<endl;
        }

};



#endif // BIRD_H
