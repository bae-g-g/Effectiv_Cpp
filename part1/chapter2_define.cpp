#include <iostream>
/*
53p

- #define을 통해서 매크로를 정의하게 되면 전처리 단계에서 상수처리가 되기 때문에
  실제 컴파일단계에서 소스코드에는 상수값으로 나타난다.
  컴파일러의 기호 테이블에도 포함되지 않고 디버깅시에도 매크로 사용의 여부를 구분하기 힘들다.
  <- 내가 작성하지 않은 코드를 디버깅할경우 문제사항이 더욱 악화 될 수 있다.

- 매크로값이 리터럴 값으로 저장되는데 이 때, 매크로에 해당하는 값이 정확히 정확히 한부분의 메모리에
  저장되지 않고 여러 메모리에 그 값이 쓰일 수 있다. - 코드가 길고 복잡해지면 낭비 될 수 있음음
  *리터럴 - 변수를 사용하지 않고 즉시 메모리에서 치환되는,소스코드에서 직접 써놓은 값들
  이전에 문자열을 사용한  코드에서 문자열이 데이터섹션(읽기 전용 섹션)에 저장되었던것을 확인했다.
  (로컬이 아닌 const로 선언한 변수 또한 데이터섹션에 저장됨)

즉, #define과 같은 역할을 하면서 위의 문제가 생기지 않도록 하는 const,inline, enum을 사용 해 보자.

*/

#define define_PI 3.14
const float const_PI = 3.14;
/*

*/

#define deifne_name "bkg"
const char* const const_name = "bkg";

/*
포인터의 경우에는 가르키는 대상과 동시에 본인이 가르키는 주소 모두 const로 선언해줘야한다.
const std::string const_name("bkg"); 문자열을 사용하려는경우는 string을 사용하는것이 더 유용할 것.
*/

class myclass{
private:
  
/*

    클래스의 맴버를 상수로 정의하는 경우 
    const int val = 1;
    이런 식의 정의는 객체 내에서만 유효한 상수 정의이다.
    모든 객체에서 동일한 상수객체를 사용하려면
    전역변수로 지정하는 static을 사용한다.

    밑에 작성된 코드를 통해 맴버변수의 주소를 명시하지 않은 경우 #define처럼 해당 코드의 부분이 상수값으로 대체된다.

*/
    static const int b=10; 
public:
    
    void print_adrress(){
        std::cout<<&b<<std::endl; // 메모리 할당을 강제하는 코드를 작성한 경우에만 출력가능.
    }
};

const int myclass:: b; // 이러한 형태로 메모리 할당을 강제 하는 경우 위의 설명과는 반대로
// const 형태로 사용이 된다.





int main(){

const int val= 10;

std::cout<<&val<<std::endl;

myclass a1;
myclass a2;

a1.print_adrress();
a2.print_adrress(); // 클래스의 맴버 변수를 상수로 선언하였기 때문에
// 다른 객체라도 동일한 상수 변수를 사용한다.

enum { aaa = 10}; // enum의 경우는 #define과 유사한 컴파일단계의 처리를 지원하지만
// define과 다르게 각 실행마다 메모리를 선언하여, 메모리를 낭비하는 일이 없다. 


}