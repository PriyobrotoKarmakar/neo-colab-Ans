// You are using GCC
#include<iostream>
using namespace std;
class Count{
public:
  int* arr;
  int size;
  int positive = 0;
  int negative = 0;
  int zero  = 0;
  Count(int s){
      size = s;
      arr = new int[size];
  }
  void makeArray(){
      for(int i=0;i<size;i++){
          cin>>arr[i];
      }
  }
  void count(){
      for(int i=0;i<size;i++){
          if(arr[i]>0)positive++;
          else if(arr[i]<0)negative++;
          else zero++;
      }
  }
  ~Count(){
      delete[] arr;
  }
  
};
int main(){
    int size;
    cin>>size;
    Count C(size);
    C.makeArray();
    C.count();
    cout<<"Positive count: "<<C.positive<<endl;
    cout<<"Negative count: "<<C.negative<<endl;
    cout<<"Zero count: "<<C.zero<<endl;
    
    
    return 0;
}