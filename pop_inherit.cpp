//Procedure Oriented Ineritance

#include <iostream>

// Base class

struct Base {
    double num1;
    double num2;
};

void Base_init(Base & obj, int & status) noexcept {
    obj.num1 = 0.0;
    obj.num2 = 0.0;
    status = 0;
}

void Base_setNumber1(Base & obj, const double & val, int & status) noexcept {
    if(val < 0) {
        status = 1;
        return;
    }
    
    obj.num1 = val;
    status = 0;
}

void Base_setNumber2(Base & obj, const double & val, int & status) noexcept {
    if(val < 0) {
        status = 1;
        return;
    }
    
    obj.num2 = val;
    status = 0;
}

void Base_getNumber1(const Base & obj, double & val, int & status) noexcept {
    val = obj.num1;
    status = 0;
}

void Base_getNumber2(const Base & obj, double & val, int & status) noexcept {
    val = obj.num2;
    status = 0;
}

// Derived class 

struct Derived {
    Base super;
    double num3;
};

void Derived_init(Derived & obj, int & status) noexcept {
    Base_init(obj.super, status);
    obj.num3 = 0.0;
    status = 0;
}

void Derived_setNumber3(Derived & obj, const double & val, int & status) noexcept {
    if(val < 0) {
        status = 1;
        return;
    }
    
    obj.num3 = val;
    status = 0;
}

void Derived_getNumber3(const Derived & obj, double & val, int & status) noexcept {
    val = obj.num3;
    status = 0;
}

// Main Function 

int main() {
    Derived obj{};
    
    double num1, num2, num3;
    int status;
    
    Derived_init(obj, status);
    
    if(status != 0) return 1;
    
    Base_setNumber1(obj.super, 10.0, status);
    
    if(status != 0) return 1;
    
    Base_setNumber2(obj.super, 20.0, status);
    
    if(status != 0) return 1;
    
    Derived_setNumber3(obj, 30.0, status);
    
    if(status != 0) return 1;
    
    Base_getNumber1(obj.super, num1, status);
    
    if(status != 0) return 1;
    
    Base_getNumber2(obj.super, num2, status);
    
    if(status != 0) return 1;
    
    Derived_getNumber3(obj, num3, status);
    
    if(status != 0) return 1;
    
    std::cout << num1 << ' ' << num2 << ' ' << num3 << "\n";
    
    return 0;
}