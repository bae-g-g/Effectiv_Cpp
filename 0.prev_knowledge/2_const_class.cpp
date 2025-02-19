#include <iostream>


class non_const_class{

    private:

    int my_value;

    public:

    non_const_class(int val)
    : my_value(val){}

    int get_value(){
        return this -> my_value;
    }

    void print_value(){
        std::cout<< this -> my_value << std::endl;
    
    }


    void empty_method(){
    } 

};

class const_class{

    private:
    int my_value;

    public:
    const_class(int val)
    : my_value(val){}
    
    int get_value() const{

        return this ->my_value;
    }

    void print_value() const{
        
        std::cout << this -> my_value << std::endl;
    }


};

int main(){

std::cout <<"------ A --------"<<std::endl;
non_const_class A(30);
int temp = A.get_value();
std::cout<<"temp  =  "<< temp<<std::endl;
A.print_value();

std::cout <<"------ B --------"<<std::endl;
non_const_class B(A);
temp = 0;
temp = B.get_value();
std::cout<<"temp  =  "<< temp<<std::endl;
B.print_value();


const non_const_class C(A);
// C.empty_method();
// temp = C.get_value();
// C.print_value();
/*
메서드가가 객체의 맴버에 어떠한 영향을 주지 않더라도
const로 선언되지 않은 모든 메서드는 메모리를 변경 할 가능성이 있다고 판단하여
접근자체를 막는다. 이것은 코드의 형식과는 무관함.
*/




std::cout <<"------ X --------"<<std::endl;
const_class X(20);
temp = 0;
temp = X.get_value();
std::cout<<"temp  =  "<< temp<<std::endl;
X.print_value();


std::cout <<"------ Y --------"<<std::endl;
const_class Y(X);
temp = 0;
temp = Y.get_value();
std::cout<<"temp  =  "<< temp<<std::endl;
Y.print_value();


std::cout <<"------ Z --------"<<std::endl;
const const_class Z(X);
temp = 0;
temp = Z.get_value();
std::cout<<"temp  =  "<< temp<<std::endl;
Z.print_value();



}