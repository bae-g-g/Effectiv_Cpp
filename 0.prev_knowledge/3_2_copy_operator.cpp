#include <iostream>

uintptr_t adress(void* address){

    return reinterpret_cast<uintptr_t>(address); 
}

class OperatorClass{

private:
public:
    int  int_val;
    int* int_ptr;



    OperatorClass(int input1, int input2){
        this -> int_val = input1;
        this -> int_ptr = new int(input2);
    }


    OperatorClass& operator=(const OperatorClass& other){
        delete this->int_ptr;
        this -> int_ptr = new int( *(other.int_ptr) );
        return *this;
    }

    void get_value(){
        std::cout << "  int_val value      =  " << this ->int_val<<std::endl;
        std::cout << "  int_ptr value      =  " << adress( this ->int_ptr )<<std::endl;
        std::cout << " *(int_ptr) value    =  " << *(this ->int_ptr)<<std::endl;
    
    }
    void get_adress(){

        std::cout << "  int_val value      =  " << adress( &(this ->int_val) ) <<std::endl;
        std::cout << "  int_ptr value      =  " << adress( &(this ->int_ptr) )<<std::endl;        
    }

    void change_value(int input){
        *(this ->int_ptr) = input;
    }

};


void myfn(OperatorClass arg){

arg.change_value(0);

}

int main(){

OperatorClass A(1,2);
std::cout << "------------OperatorClass A(1,2);------------"<<std::endl;



std::cout<<"------A value-----"<<std::endl;
A.get_value();
std::cout<<"------A adress-----"<<std::endl;
A.get_adress();
std::cout<<std::endl;


OperatorClass B(3,4);
std::cout<<"------B value-----"<<std::endl;
B.get_value();
std::cout<<"------B adress-----"<<std::endl;
B.get_adress();
std::cout<<std::endl;

OperatorClass C(A);
std::cout<<"------C value-----"<<std::endl;
C.get_value();
std::cout<<"------C adress-----"<<std::endl;
C.get_adress();

std::cout << "-----change value----"<<std::endl;
C.change_value(999);
std::cout<<"------A value-----"<<std::endl;
A.get_value();
std::cout<<"------C value-----"<<std::endl;
C.get_value();


/*
OperatorClass C(A);코드를 통해서 (대입연산자나나, 복사 생성자 등을 사용하지 않음)
객체 C는  A를 얕은 복사를 수행하였다.
int_val
int_ptr에 할당된 값이 동일함을 확인 할 수 있다.
즉 int_val는 할당된 값이 상수이고 그대로 사용되어 문제가 생기지 않지만
int_ptr은 A와 C가 동시에 공유하게 되는 상황이 생긴다.
A.int_ptr의 변경은 곧
C.int_ptr의 변경이다.

A.int_ptr의 메모리 해제는 곧
C.int_ptr의 메모리 해제이다. <- 이것이 소멸자 호출 값 변경등에서 문제를 일으킬 가능성이 있다.
--> change value의 예시를 확인.




물론 각 변수의 메모리 주소는 객체에 맞추어 생성됨으로 상이하다.

*/

OperatorClass X(100,200);
OperatorClass Y(300,400);

std::cout<<"------X value-----"<<std::endl;
X.get_value();
std::cout<<"------Y value-----"<<std::endl;
Y.get_value();
X=Y;
std::cout<<"------X = Y-----"<<std::endl;

std::cout<<"------X value-----"<<std::endl;
X.get_value();
std::cout<<"------Y value-----"<<std::endl;
Y.get_value();

std::cout<<"------change value-----"<<std::endl;
X.change_value(500);
std::cout<<"------X value-----"<<std::endl;
X.get_value();
std::cout<<"------Y value-----"<<std::endl;
Y.get_value();
/*


대입 연사자를 통해 깊은복사를 구현한 결과이다.
X의 맴버인 int_ptr이 힙에 할당 받은 메모리 주소와
Y의 int_ptr이 힙에 할당받은 힙의 메모리 주소는 상이하다.

*/


std::cout<<"------function-----"<<std::endl;

OperatorClass parm(1000,2000);
myfn(parm);
parm.get_value();
/*
함수의 인수를 얕은복사를 하는 문제는
복사생성자를 통해 해결이 가능하다.
*/

}