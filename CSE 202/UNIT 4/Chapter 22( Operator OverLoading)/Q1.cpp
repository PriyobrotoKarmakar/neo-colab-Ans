#include<iostream>
using namespace std;

class Coordinates{
    public:
    int x,y;
    Coordinates(int x,int y){
        this->x = x;
        this->y = y;
    }
};

ostream& operator<<(ostream& COUT,Coordinates& Co){
    COUT<<Co.x<<" "<<Co.y<<endl;
    return COUT;
}

void operator++(Coordinates& Co){
    Co.x+=1;
    Co.y+=1;
}

int main(){
    int x,y;
    cin>>x>>y;
    Coordinates Co(x,y);
    cout<<Co;
    ++Co;
    cout<<Co;
    return 0;
}
