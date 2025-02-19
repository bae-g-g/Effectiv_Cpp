
#include <iostream>

class myclass{

private:
    int int_val;
    int* int_ptr;

public:
    //생성자
    myclass(int input1,int input2){
        this ->int_val = input1;
        this -> int_ptr = new int(input2);
    }

    //소멸자
    ~myclass(){

        // delete this -> int_ptr;

    /*
    얕은복사때문에 문제가 생김
    myclass copy = original;
    위 코드가 얕은복사를 진행함

    즉,
    copy.int_val = original.int_val
    copy.int_ptr = original.int_ptr

    이러한 형태로 복사를 하는데
    int_val은 전달해주는 값이 상수임으로
    어떠한 값이 복사되어도 상관이없지만
    ptr의 경우 new에 의해 생성된 힙영역의 메모리주소를
    복사하여 전달한다.
    
    origianl.int_ptr =  0xec3c50 이것이라면
    copy.int_ptr =    0xec3c50으로 복사하게된다.

    copy와 original이라는 객체는 서로 다른 메모리에 저장된
    다른 객체이지만
    int_ptr이 저장하고 있는 주소 그리고  가르키는 값은 공유되는 결과를 가지게 된다.
    *(copy.int_ptr) = 1 과 같은 형식으로 그 값으 바꾸게 된다면
    original에 저장된 값 또한 1으로 바뀐다.
    물론
    
    copy.int_ptr이 저장한 주소자체를 바꿔 버리면 더이상 문제는 발생하지 않는다.

    결국 동일한 메모리 주소를 유지하다  두 객체 모두 소멸자를 호출할 때
    첫 번째로 소멸자를 호출한 경우 힙에 할당받았던 메모리를 삭제 할 수 있지만,
    두 번째로 소멸자를 호출하는 객체는 이미 int_ptr이 가르키고 있던 메모리가 해제되었기 때문에
    해제할 것이 없는 메모리를 해제하려고 시도하여 에러가 발생하게 된다.


    */
        
        
    }


    void get_ptr_adress(){
        std::cout << this -> int_ptr<<std::endl;
    }

};



int main(){
    
    int* ptr = new int(3);
    int* pptr = ptr;
    std::cout<<ptr<<std::endl;
    std::cout<<pptr<<std::endl;
    std::cout<<*pptr<<std::endl;
    std::cout<<*ptr<<std::endl;
    std::cout<<"-----------------"<<std::endl;

    delete ptr;
    std::cout<<pptr<<std::endl;
    std::cout<<ptr<<std::endl;
    std::cout<<*pptr<<std::endl;
    std::cout<<*ptr<<std::endl;
    std::cout<<"-----------------"<<std::endl;
    
    /*
    
    힙 영역에 메모리를 할당하고 그 주소를 저장한
    포잍너를 통해서 
    메모리가 해제된 후에도 동일한 값이 저장되어 있는지를
    확인해 보는 코드. - 메모리가 해제되면 이전에 그 주소번지에
    저장했던 데이터를 그대로 유지한다는 보장은 없다.
    
    */




    
    {  // 소멸자 작동을 확인하기 위해 내부 스코프를 하나 만듬

        myclass original(1,2);
        original.get_ptr_adress();
        myclass copy = original;
        copy.get_ptr_adress();

    }

    std::cout<<"소멸자 정상작동"<<std::endl; 

}