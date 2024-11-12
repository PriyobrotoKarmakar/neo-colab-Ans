// You are using GCC
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class Icecream{
  public:
    virtual float Quantity() = 0;
    virtual ~Icecream(){};
    
};
class SphereIcecream:public Icecream{
   private:
     float radius;
    public:
        SphereIcecream(float r):radius(r){}
        
        float Quantity(){
            return (4.0/3.0) * M_PI * pow(radius,3);
        }
};
class ConeIcecream:public Icecream{
   private:
     float radius,height;
    public:
        ConeIcecream(float r,float h):radius(r),height(h){}
        
        float Quantity(){
            return (1.0/3.0) * M_PI * pow(radius,2) * height;
        }
};
int main(){
    Icecream* icecream;
    
    int choice;
    cin>>choice;
    if(choice==1){
        float r;
        cin>>r;
        icecream = new SphereIcecream(r);
    }else if(choice == 2){
        float r,h;
        cin>>r>>h;
        icecream  = new ConeIcecream(r,h);
    }else{
        cout<<"Invalid choice"<<endl;
        return 0;
    }
    cout<<fixed<<setprecision(2)<<icecream->Quantity();
    return 0;
}