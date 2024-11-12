// You are using GCC
#include<iostream>
using namespace std;
class Furniture{
  public:  
    virtual int material(){
        return 0;
    }
};
class Chair : public Furniture{
    public:
        int material(){
            return 500;
        }
};
class Table : public Furniture{
    public:
        int material(){
            return 1000;
        }
};
int main(){
    Furniture* furniture;
    int choice;
    cin>>choice;
    if(choice==1){
        furniture = new Chair();
    }else if(choice==2){
        furniture = new Table();
    }else{
        cout<<"Invalid Choice"<<endl;
        return 0;
    }
    int quantity;
    cin>>quantity;
    int totalCost = quantity*furniture->material();
    cout<<"The total cost: "<<totalCost<<endl;
    return 0;
}