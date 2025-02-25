#include <iostream>
//복사 생성자



class NoCopyConstructor{

private:
    int int_val;
    int* int_ptr;

public:

    NoCopyConstructor(int input1,int input2){
        int_val = input1;
        int_ptr = new int(input2);
    }
    // ~NoCopyConstructor(){
    //     delete int_ptr;
    // } //이전과 동일한 이유로(이중 해제문제) 오류 발생

    void print_address(){
        std::cout << "-------adress-------"<<std::endl;
        std::cout << "int_val      = "<<&int_val<<std::endl;
        std::cout << "int_ptr     = "<<&int_ptr<<std::endl;

    }
    void print_value(){
        std::cout << "-------value-------"<<std::endl;
        std::cout << "int_val      = "<<int_val<<std::endl;
        std::cout << "*int_ptr     = "<<*int_ptr<<std::endl;
        std::cout << "int_ptr      = "<<int_ptr<<std::endl;
    }

};



class CopyConstructor{

    private:
    int int_val;
    int* int_ptr;

public:

    CopyConstructor(int input1,int input2){
        int_val = input1;
        int_ptr = new int(input2);
    }

    CopyConstructor(CopyConstructor& other){
        this -> int_val = other.int_val;
        int_ptr = new int( *(other.int_ptr) );
    }

    ~CopyConstructor(){
        delete int_ptr;
    }

    void print_address(){
        std::cout << "-------adress-------"<<std::endl;
        std::cout << "int_val      = "<<&int_val<<std::endl;
        std::cout << "int_ptr     = "<<&int_ptr<<std::endl;

    }
    void print_value(){
        std::cout << "-------value-------"<<std::endl;
        std::cout << "int_val      = "<<int_val<<std::endl;
        std::cout << "*int_ptr     = "<<*int_ptr<<std::endl;
        std::cout << "int_ptr      = "<<int_ptr<<std::endl;
    }



};

void fn(NoCopyConstructor par ){

    std::cout << "-------   par   -------"<<std::endl;
    par.print_value();

};

void fn(CopyConstructor par ){

    std::cout << "-------   par   -------"<<std::endl;
    par.print_value();

};

int main(){

NoCopyConstructor A(1,2);
NoCopyConstructor B(A);

std::cout << "-------    A    -------"<<std::endl;
A.print_value();
std::cout << "-------    B    -------"<<std::endl;
B.print_value();

CopyConstructor C(3,4);
CopyConstructor D(C);

std::cout << "-------    C    -------"<<std::endl;
C.print_value();
std::cout << "-------    D    -------"<<std::endl;
D.print_value();

/*
복사생성자로 생성되지 않은 B는 A의 int_ptr이 가르키는 메모리와 동일한 곳을 가르킨다.
반면, 복사생성자를 통해서 생성된 D는 C의 int_ptr을 가르키는 메모리가 다르다.

*/

std::cout << "-------   A-fn    -------"<<std::endl;
fn(A);
std::cout << "-------    A    -------"<<std::endl;
A.print_value();

std::cout << "-------   C-fn    -------"<<std::endl;
fn(C);
std::cout << "-------    C    -------"<<std::endl;
C.print_value();

/*
함수(call by value)형태로 아규먼트를 넘겨받을때 위와 똑같이
객체의 값을 복사하여 파라미터로 사용하는데 이때 얕은복사를 시행한다.
복사 생성자가 존재한다면, 객체의 값을 복사 할 때 복사 생성자의 정의에 따라
파라미터를 생성하게 된다. 
*/


}