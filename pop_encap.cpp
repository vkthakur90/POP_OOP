//Procedure Oriented Encapsulation

#include <iostream>

struct MyData {
    double num1{0.0};
    double num2{0.0};
};

void MyData_setNumber1(MyData & data, const double & val, int & status) noexcept {
    if(val < 0) {
        status = 1;
        return;
    }
    
    data.num1 = val;
    status = 0;
}

void MyData_setNumber2(MyData & data, const double & val, int & status) noexcept {
    if(val < 0) {
        status = 1;
        return;
    }
    
    data.num2 = val;
    status = 0;
}

void MyData_getNumber1(const MyData & data, double & val, int & status) noexcept {
    val = data.num1;
    status = 0;
}

void MyData_getNumber2(const MyData & data, double & val, int & status) noexcept {
    val = data.num2;
    status = 0;
}

int main() {
    MyData data;
    double num1, num2;
    int status;
    
    MyData_setNumber1(data, -10.0, status);
    
    if(status != 0) {
        std::cerr << "Invalid num1 entered" << '\n';
        return 0;
    }
    
    MyData_setNumber2(data, 20.0, status);
    
    if(status != 0) {
        std::cerr << "Invalid num2 entered" << '\n';
        return 0;
    }
    
    MyData_getNumber1(data, num1, status);
    MyData_getNumber2(data, num2, status);
    
    std::cout << num1 << " " << num2 << "\n";
    return 0;
}