#include<bits/stdc++.h>

using namespace std;

class Person{
public:
    int age;
    Person(int age){
        this->age = age;
    }
};

bool operator==(Person & p1, Person& p2){
    return p1.age==p2.age;
}

int main(){
    int a1, a2, a3;
    cin>>a1>>a2>>a3;
    Person p1(a1), p2(a2), p3(a3);

    if(p1==p2){
        cout<<"Person 1 is the same age as Person 2."<<endl;
    }else{
        cout<<"Person 1 is not the same age as Person 2."<<endl;
    }

    if(p1==p3){
        cout<<"Person 1 is the same age as Person 3."<<endl;
    }else{
        cout<<"Person 1 is not the same age as Person 3."<<endl;
    }

    return 0;
}