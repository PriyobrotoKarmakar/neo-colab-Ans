// You are using GCC
#include<iostream>
#include<cctype>
#include<stdexcept>
#include<string>
using namespace std;
class InvalidEmailException: public exception{
    public:
    string mass;
        InvalidEmailException(const string& st):mass(st){};
        
        const char* what() const noexcept override{
            return mass.c_str();
        }
};
void validEmail(string& email){
    int atPos = email.find('@');
    int dotPos = email.find('.');
        if(!isalpha(email[0]))
            throw InvalidEmailException("Exception Caught...\n");
            
        if(atPos==string::npos || dotPos==string::npos)
            throw InvalidEmailException("Exception Caught...\n");
            
            
        if(atPos>dotPos || (dotPos-atPos)<1)
            throw InvalidEmailException("Exception Caught...\n");
            
        
        if(atPos<1)
            throw InvalidEmailException("Exception Caught...\n");
            
            
        if(dotPos==email.length()-1)
            throw InvalidEmailException("Exception Caught...\n");
            
            
        cout<<"Email Id is Valid";
    
}
int main(){
    string email;
    getline(cin,email);
    try{
        validEmail(email);
    }
    catch(const InvalidEmailException& e){
        cout<<e.what()<<"Invalid Email Id!!!";
    }
    return 0;
}