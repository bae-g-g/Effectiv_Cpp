#include <iostream>


// 함수 오버로딩
void fn(int a){
    std::cout << "int type" << std::endl;
}

void fn(double a){
    std::cout << "double type"<<std::endl;
}

void fn(char a){
    std::cout << "char type"<<std::endl;
}


int main(){
std::cout << "---function overloading---"<< std::endl;
fn(1);
fn(1.1);
fn('c');

std::cout<< "------------"<<std::endl;

}