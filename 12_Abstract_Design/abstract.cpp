#include "bird.h"
#include<iostream>


using namespace std;

void BirdDoesSomething(Bird * &bird){
    bird->eat();
    bird->sleep();
}

int main(){

    Bird *sparrow = new Sparrow();
    BirdDoesSomething(sparrow);

    Bird *eagle = new Eagle();
    BirdDoesSomething(eagle);

    delete sparrow;
    delete eagle;


    return 0;
}