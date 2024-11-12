// You are using GCC
#include<iostream>
using namespace std;
class A{
  public:
    virtual void print() = 0;
    virtual ~A(){};
    
};
class B: public A{
    public:
        int num;
        B(int val):num(val){};
        
        void print(){
            int cube = num*num*num;
            int square = num*num;
            
            if((num&1)==1){
                cout<<cube-square;
            }else{
                cout<<cube+square;
            }
        }
};
int main(){
    int num;
    cin>>num;
    B obj(num);
    obj.print();
    return 0;
}