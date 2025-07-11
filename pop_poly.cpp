// Procedure Oriented Polymorphism

#include <iostream>
#include <cmath>

struct Circle {
    double radius{0.0};
};

void Circle_setRadius(Circle & obj, double & val, int & status) {
    if(val < 0) {
        status = 1;
        return 0;
    }
    
    obj.radius = val;
    status = 0;
}

void Circle_getArea(Circle & obj, double & val, int & status) {
    val = std::atan2(0, -1) * std::pow(obj.radius, 2.0);
    status = 0;
}

void Circle_getPerimeter(Circle & obj, double & val, int & status) {
    val = 2.0 * std::atan2(0, -1) * obj.radius;
    status = 0;
}

struct Rectangle {
    double length{0.0};
    double breadth{0.0};
};

void Rectangle_setLength(Rectangle & obj, double & val, int status) {
    if(val < 0) {
        status = 1;
        return 0;
    }
    
    obj.length = val;
    status = 0;
}

void Rectangle_setBreadth(Rectangle & obj, double & val, int status) {
    if(val < 0) {
        status = 1;
        return 0;
    }
    
    obj.breadth = val;
    status = 0;
}

void Rectangle_getArea(Rectangle & obj, double & val, int status) {
    if(val < 0) {
        status = 1;
        return 0;
    }
    
    val = obj.length * obj.breadth;
    status = 0;
}

void Rectangle_getPerimeter(Rectangle & obj, double & val, int status) {
    if(val < 0) {
        status = 1;
        return 0;
    }
    
    val = 2.0 * (obj.length + obj.breadth);
    status = 0;
}

struct Shape {
    enum {
        CIRCLE,
        RECTANGLE
    } type;
    
    Circle circle{};
    Rectangle rectangle{};
};

void Shape_createCircle(Shape & obj, const double & radius, int & status) {
    Circle_setRadius(obj.circle, radius, status);
    
    if(status) return;
    
    obj.type = CIRCLE;
    status = 0;
}

void Shape_createRectangle(Shape & obj, const double & length, const double & breadth, int & status) {
    Rectangle_setLength(obj.rectangle, length, status);
    
    if(status) return;
    
    Rectangle_setBreadth(obj.rectangle, breadth, status);
    
    if(status) return;
    
    obj.type = RECTANGLE;
    status = 0;
}

void Shape_getPerimeter(Shape & obj, double & val, status) {
    switch(obj.type) {
    case CIRCLE:
        Circle_getPerimeter(obj.circle, val, status);
        break;
    case RECTANGLE:
        Rectangle_getReactangle(obj.rectangle, val, status);
        break;
    }
}

void Shape_getArea(Shape & obj, double & val, status) {
    switch(obj.type) {
    case CIRCLE:
        Circle_getArea(obj.circle, val, status);
        break;
    case RECTANGLE:
        Rectangle_getArea(obj.rectangle, val, status);
        break;
    }
}
