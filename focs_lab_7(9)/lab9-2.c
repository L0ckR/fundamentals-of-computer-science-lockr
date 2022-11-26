#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef unsigned int uint;

struct Point {
    double x, y;
};

struct Vector {
    double lx, ly;
};

typedef struct {
    double k, b;
} Line;

struct Triangle {
    struct Point a1, a2, a3; // a2a3 parallel to x-axis
};


struct Point plus(struct Point p, struct Vector v) {
    struct Point res = {p.x + v.lx, p.y + v.ly};
    return res;
}

struct Vector reverse_x_vector(struct Vector v){
    struct Vector res = {v.lx*(-1), v.ly};
    return res;
}

struct Vector reverse_y_vector(struct Vector v){
    struct Vector res = {v.lx, v.ly*(-1)};
    return res;
}


bool upper(Line ln, struct Point p){
    return (p.y >= p.x * ln.k + ln.b ? true : false);
}

bool below(Line ln, struct Point p){
    return (p.y <= p.x * ln.k + ln.b ? true : false);
}

struct Triangle triangle1( struct Point o, uint length) {
    struct Triangle triangle;
    struct Vector v1 = {0, length};
    struct Vector v2 = {length*(pow(3, 0.5)*0.5), 0.5*length};
    v2 = reverse_y_vector(v2);
    triangle.a1 = plus(o, v1);
    triangle.a2 = plus(o, reverse_x_vector(v2));
    triangle.a3 = plus(o, v2);
    return triangle;
}

struct Triangle triangle2( struct Point o, uint length) {
    struct Triangle triangle;
    struct Vector v1 = {0, length};
    v1 = reverse_y_vector(v1);
    struct Vector v2 = {length*(pow(3, 0.5)*0.5), 0.5*length};
    triangle.a1 = plus(o, v1);
    triangle.a2 = plus(o, reverse_x_vector(v2));
    triangle.a3 = plus(o, v2);
    
    return triangle;
}


bool check_in_triangle1(struct Point p, struct Triangle Triangle){
    struct Point A = Triangle.a1;
    struct Point B = Triangle.a2;
    struct Point C = Triangle.a3;

    Line AB = {.k = (A.y - B.y) / (A.x - B.x), .b = B.y - AB.k * B.x};
    Line BC = {.k = (B.y - C.y) / (B.x - C.x), .b = C.y - BC.k * C.x};
    Line AC = {.k = (C.y - A.y) / (C.x - A.x), .b = A.y - AC.k * A.x};

    return(below(AB, p) == true && below(AC, p) == true && upper(BC, p) == true ? true : false);
}

bool check_in_triangle2(struct Point p, struct Triangle Triangle){
    struct Point A = Triangle.a1;
    struct Point B = Triangle.a2;
    struct Point C = Triangle.a3;

    Line AB = {.k = (A.y - B.y) / (A.x - B.x), .b = B.y - AB.k * B.x};
    Line BC = {.k = (B.y - C.y) / (B.x - C.x), .b = C.y - BC.k * C.x};
    Line AC = {.k = (C.y - A.y) / (C.x - A.x), .b = A.y - AC.k * A.x};

    return(upper(AB, p) == true && upper(AC, p) == true && below(BC, p) == true ? true : false);
}



int main()
{
    double x, y;
    uint l;
    printf("enter x y of center\n");
    scanf("%lf %lf", &x, &y);
    struct Point o = {x, y};
    printf("enter length\n");
    scanf("%u", &l);
    printf("enter x y of POINT\n");
    scanf("%lf %lf", &x, &y);
    struct Point POINT = {x, y};
    if (check_in_triangle1(POINT, triangle1(o, l))||check_in_triangle2(POINT, triangle2(o,l))){
        printf("YES");
    }
    return 0;
}