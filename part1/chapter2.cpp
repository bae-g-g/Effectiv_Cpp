/*
53p~
" #define을 쓰려거든 const, enum, inline을 떠올리자"

- #define을 통해서 매크로를 정의하게 되면 전처리 단계에서 상수처리가 되기 때문에
  실제 컴파일단계에서 소스코드에는 상수값으로 나타난다.
  컴파일러의 기호 테이블에도 포함되지 않고 디버깅시에도 매크로 사용의 여부를 구분하기 힘들다.
  <- 내가 작성하지 않은 코드를 디버깅할경우 문제사항이 더욱 악화 될 수 있다.

- 매크로값이 리터럴 값으로 저장되는데 이 때, 매크로에 해당하는 값이 정확히 정확히 한부분의 메모리에
  저장되지 않고 여러 메모리에 그 값이 쓰일 수 있다. - 코드가 길고 복잡해지면 낭비 될 수 있음음
  *리터럴 - 변수를 사용하지 않고 즉시 메모리에서 치환되는,소스코드에서 직접 써놓은 값들
  이전에 문자열을 사용한  코드에서 문자열이 데이터섹션(읽기 전용 섹션)에 저장되었던것을 확인했다.
  (로컬이 아닌 const로 선언한 변수 또한 데이터섹션에 저장됨)

*/


#include <iostream>

/* const pointer사용 
int main(){

int a = 10;
const int* ptr = &a; // 포인터를 통해 핸들링하는 값을 const로 사용 - 가르키는 값에 대한 const 
// *ptr = 20; = 포인터가 가르키는 주소의 메모리값 변경불가.
// ≒ const int a; int *ptr = &a;

int b = 10;
int* const ptr = &b; // 포인터를 통해 가르키는 주소를 const로 사용 - 가르키는 주소에 대한 const
// ptr = &a; 포인터가 가르키는 주소 변경 불가.

}
*/


/*string
int main(){

    const std :: string a("string!"); //  명시적인 초기화 = 생성자의 인자를 직접 할당
    std:: string b = "string!"; //  암시적 초기화 - 임시값을 생성하고 복사하는 형태로 할당
    //a.append("add"); string을 변경하는 형태의 메서드는 사용이 불가능함

    std::cout << a<<std::endl;
    std::cout << b<<std::endl;

}
*/

/* 클래스의 상수변수 맴버

클래스의 맴버로써써 상수를 정의 할 수 있다.
이 때 상수는 각 인스턴스가 가지는 개별적인 맴버변수가 아닌
해당 클래스가 공통으로 값,주소를 공유한다.

class my_class{
    private:
    static const int val = 100; //이것은 클래스에서 정의일뿐 실제로 메모리에 할당 된 값이 아니다.
    int arr[ val ];
    
    public:
    my_class(){

    }
    ~my_class(){

    }

    static const int* get_val_adress(){
        return &val;
    }

};
const int my_class::val; // 실질적으로 여기서 할당을 해줘야한다. 클래스의 정으로 인스턴스가 생성되는게 아니기때문.

int main(){
    my_class a;
    my_class b;
    my_class c;
    my_class d;
    std::cout << &a << " " << &b << " " << &c << " " << &d << " "<<std::endl; 
    std:: cout << a.get_val_adress()<<" " << b.get_val_adress()<<" "<< c.get_val_adress()<<" "<< d.get_val_adress();   

}

*/

/* 아래와 같은 방법으로 정의를 할 수 도 있다.
class my_calss{

private: 
static const int val;
public:

static const int* get_val_address(){
    return &a;
}

};

const int my_calss::val = 10;

int main(){
    my_calss a;
    std:: cout << a.get_val_address(); 
}
*/

/* 클래스에 enum을 통하여 매크로와 같이 사용이 가능 
class my_pixel{
    private:
    enum{
        red = 0,
        green = 1,
        blue = 2,
        size = 3
    };
    int pixel_arr[size];

    public:
    my_pixel(int r,int g,int b){
        this -> pixel_arr[red] = r;
        this -> pixel_arr[green] = g;
        this -> pixel_arr[blue] = b;
    }    
    void change_red(int r){
        this -> pixel_arr[red] = r;
    }
    void change_green(int g){
        this -> pixel_arr[green] = g;
    }
    void change_blue(int b){
        this -> pixel_arr[blue] = b;
    }
    int get_red(){
        return this->pixel_arr[red];
    }
    int get_green(){
        return this->pixel_arr[green];
    }
    int get_blue(){
        return this->pixel_arr[blue];
    }

};


int main(){
my_pixel a(200,120,0);

a.change_blue(220);

std::cout << a.get_red()<<std::endl;
std::cout << a.get_green()<<std::endl;
std::cout << a.get_blue()<<std::endl;

}
*/

/*
매크로함수 사용대신 inline 함수를 사용하자
#define ADD(a,b) (a)+(b)

templeat <typename T>
inline T add(T a,T b){ 
    return a+b;
}
// inline함수는 말 그대로 코드진행중 함수를 만나면 jump를 통해서 함수가 정의된 부분으로 이동( 또는 스택에 현재 상태를 저장하고
   함수를 실행하는 등)의 행동대신 함수를 그대로 현재 진행중인 코드에 넣는다는 개념
   -함수의 기능을 반복적으로 사용하지만 그 기능이 단순하여 jump를 하는것에 오버헤드가 더 크다고 판단되는 경우, 캐싱에
   유리하다고 느끼는 경우 사용하면 된다. 

int main(){

    std::cout<<ADD(4,3);
    std::cout<<add(4,3);
}

*/