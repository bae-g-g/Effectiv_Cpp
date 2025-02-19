#include <iostream>
#include <cmath>

/*
표현식을 런타임이 아닌 컴파일 단계에서 처리하도록하는 명령어
constexpr함수의 파라미터가 상수, 컴파일타임에 정해지는 변수같은
경우 함수또한 컴파일 단계에서 정해진다.

그게 아닌 런타임때 정해지는 값을 포함하는 경우
일반적인 함수처럼 런타임에 호출되어 실행된다.

두 가지 경우중 어떻게 사용 될 지는 명시적으로 사용하기 위해
constexpr을 통해서 값이 할당되는 변수 또한 constexpr 입력해주면
그 변수는 컴파일때 작동하는 경우만 그 값을 정상적으로 할당받고,
컴파일 단계에서 할당이 불가능한 경우 컴파일이 불가능하다.


그러면 굳이 constexpr을 사용 할 필요가 있을까?
미리 값을 구한 후에 변수로 선언해도 상관없지 않은거 아닌가?
-> 이것은 확장성과 가독성 그리고 코드를 통한 커뮤니케이션의 이점이 있음.

*/

constexpr int static_val = 10;

constexpr int constexpr_fn(int input){

    return input * static_val;

}

double my_fn(int input){ //main에서 여러번의 호출이 있는동안 
    //constexpr_fn(2)는 함수호출없이 고정된 값으로 런타임때는 교체된다고 생각 할 수 있다.
    // =
    // return input*20;
    return input* constexpr_fn(2) ;
}

int main(){
    
    int runtime_value = 9999;
    const int const_val = 999;
    constexpr int constexpr_val = constexpr_fn(2);// constexpr_val값은 컴파일단계에서 결정된다.
    
    
    // double &ref = constexpr_val;
    //double *ptr = &constexpr_val;     
    const int &ref = constexpr_val; //const변수와 consterxpr로 선언된 변수를 참조하기 위해선 const 레퍼런스로 선언해야함
    int const *ptr1 = &constexpr_val;
    

    std::cout <<"전체 주소값" <<std::endl;
    std::cout <<"&runtime_val                = " <<&runtime_value <<std::endl;
    std::cout <<"&const_val                  = " <<&const_val <<std::endl;
    std::cout <<"&constexpr_val              = " <<&constexpr_val <<std::endl;
    std::cout<<"\n";
    std::cout<<"\n";
 
    std::cout <<"-----------const_val-----------------"<<std::endl;
    

    std::cout <<"const_val            주소값 = "  << &const_val<<std::endl;
    std::cout <<"runtime_val - 1      주소값 = "  << (&runtime_value -1) <<std::endl;
    std::cout <<"const val            할당값 = "  << const_val <<std::endl;
    std::cout <<"*(&runtime_value -1) 할당값 = "  << *(&runtime_value -1) <<std::endl;
    *(&runtime_value -1) = 1000;
    std::cout<<"======*(&runtime_value -1)====== = 1000; " <<std::endl;
    std::cout <<"const val            할당값 = "  << const_val <<std::endl;
    std::cout <<"*(&runtime_value -1) 할당값 = "  << *(&runtime_value -1) <<std::endl;
    std::cout<<"\n";
    std::cout<<"\n";
    
    
    
    std::cout <<"-----------constexpr_val-----------------"<<std::endl;
    std::cout <<"constexpr_val            주소값 = "  << &constexpr_val<<std::endl;
    std::cout <<"runtime_val - 2          주소값 = "  << (&runtime_value -2) <<std::endl;
    std::cout <<"constexpr val            할당값 = "  << constexpr_val <<std::endl;
    std::cout <<"*(&runtime_value -2)     할당값 = "  << *(&runtime_value -2) <<std::endl;
    *(&runtime_value -2) = 1000;
    std::cout<<"====== *(&runtime_value -2) = 1000; ======" <<std::endl;    
    std::cout <<"constexpr val            할당값 = "  << constexpr_val <<std::endl;
    std::cout <<"*(&runtime_value -2)     할당값 = "  << *(&runtime_value -2) <<std::endl;
    std::cout<<"\n";
    std::cout<<"\n";

    /*
    const_val, constexpr_val
    메모리 자체는 실제로 수정되었지만
    const,constexpr은 컴파일단계에서 이미 그 값을 쓰도록 약속되어 있는 값이기 때문에 
    컴파일 단계에서 처리한 그 값을 그대로 출력한다.
    */


    std::cout <<"-----------cin_const_val-----------------"<<std::endl;
    int cin_val;
    std::cin >> cin_val;
    const int cin_const_val = cin_val;
    
    int arr1[const_val];//가능
    // int arr2[cin_const_val];// 컴파일때 정해지는 상수가 아님
    // int arr3[cin_val]; //상수가 아님

    // constexpr int cin_constexpr_val = cin_val; // 런타임에 결정되는 변수로는 constexpr 변수를를 할당 불가능; 
    std::cout<<"&cin_const_val           주소값 = "  << &cin_const_val<<std::endl;
    std::cout<<"runtime_val - 4          주소값 = "  << (&runtime_value -4) <<std::endl;
    std::cout<<"cin_const_val            할당값 = "  << cin_const_val<<std::endl;
    std::cout<<"runtime_val - 4          할당값 = "  << *(&runtime_value -4)<<std::endl;
    std::cout<<"====== *(&runtime_value -4) = 1000; ======" <<std::endl;  
    *(&runtime_value -4) = 1000;
    std::cout<<"cin_const_val            할당값 = "  << cin_const_val<<std::endl;
    std::cout<<"runtime_val - 4          할당값 = "  << *(&runtime_value -4)<<std::endl;
    
    

    // cin_const_val = 20; // cin_const_val 자체는 변경이 불가능
    // *(constexpr_val -2) = 1000; // const로 선언된 변수는 주소연산을 통한 값 또한 변경 불가

    /*
    const의 값이 컴파일 단계에서 결정 될 수 없는,
    위와 같이 런타임때 값이 결정되는 경우에
    실제 주소값에 접근하여 그 값을 변경하면
    const로 지정된 값이라 할 지라도 그 값이
    변경된다.
    
    이 예시는 아키텍쳐,운영체제,컴파일러에따라 바뀔 수 있다

    */




}