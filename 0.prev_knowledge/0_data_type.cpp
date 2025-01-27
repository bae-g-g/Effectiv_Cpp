#include <iostream>
#include <typeinfo>
#include <vector>

#define print(x) std::cout<<(x)<<std::endl;

auto fn(auto z){ // 파라미터를 auto로 사용가능한건 c++ 20 버전부터 - 대부분 템플릿을 사용용
    return z*2;
}

int main(){
    
    print(sizeof(int));
    print(sizeof(long long));
    print(sizeof(size_t)); // 64bit 프로세스를 사용중이여서 (1ward) 64bit
    print(sizeof(bool));
    print(sizeof(char));
    print(sizeof(void*));
    
 
    print("----------------");

    std::string g = "abc";
    print(sizeof(g)); // string type은 class로 정의됨 - string 클래스의 맴버 변수는 - char*T data , size_t size , size_t capacity로 8*3의 메모리가 필요함
    print(typeid(g).name());

    char *h = "abc";
    print(sizeof(h));  // char형 포인터
    print(typeid(h).name());

    char i[] = "abcd";
    print(sizeof(i)); // char형 배열
    print(typeid(i).name());

    std::vector<int> j;
    print(sizeof(j)); // string과 마찬가지로 유사한 맴버변수를 가지고 있음
    print(typeid(j).name());

    print(sizeof("abc")); //  출력값은 27번줄과 유사하지만 변수 i와 "abc"의 리터럴이 저장되는 위치는 stack영역과 코드 세그먼트 부분으로 확실한 차이가 있음
    print(typeid("abc").name());

    print("-----auto--------");
    auto a = 10;
   print(typeid(a).name()); // 정수는 기본적으로 int
    

    auto b = 0.5;
    print(typeid(b).name()); // 소수는 double

    auto c = 'a';
    print(typeid(c).name()); // 문자는 char
 

    auto d = "a"; // char형 포인터
    print(sizeof(d)); 
    print(typeid(d).name()); // PKc = P = pointer , K = const , c = char

    auto e = &a; // pointer
    print(sizeof(e));
    print(typeid(e).name());


    auto f = a; // reference
    print(sizeof(f));
    print(typeid(f).name());
    
    decltype(a) dt;
    print(typeid(dt).name()); // decltype
    
    print("----- auto 반환형 , auto 파라미터 함수 -----");
    print(fn(0.1)); //
    print(typeid(fn(0.1)).name());
    print(fn(1));
    print(typeid(fn(1)).name());

}
