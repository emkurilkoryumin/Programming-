#include <iostream>
#include <cmath>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Dot {
public:
    virtual void plot() const = 0;
    virtual void move_dot(double x, double y) = 0;
    virtual void rotate_dot(double angle, double cx, double cy) = 0;
    virtual ~Dot() {}
};

class ConcreteDot : public Dot {
private:
    double x;
    double y;
public:
    ConcreteDot(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}
    double get_x() const { return x; }
    double get_y() const { return y; }
    void plot() const {
        std::cout << "(" << x << ", " << y << ")";
    }
    void move_dot(double xNew, double yNew) {
        x += xNew;
        y += yNew;
    }
    void rotate_dot(double angle, double cx, double cy) {
        double radians = angle * M_PI / 180.0;
        double newX = cos(radians) * (x - cx) - sin(radians) * (y - cy) + cx;
        double newY = sin(radians) * (x - cx) + cos(radians) * (y - cy) + cy;
        x = newX;
        y = newY;
    }
};

class Quad : public Dot {
private:
    std::vector<ConcreteDot*> corners;
public:
    Quad(ConcreteDot* tl, double length) {
        double x = tl->get_x();
        double y = tl->get_y();
        corners.push_back(new ConcreteDot(x, y));  // Top left corner
        corners.push_back(new ConcreteDot(x + length, y)); // Top right corner
        corners.push_back(new ConcreteDot(x + length, y - length)); // Bottom right corner
        corners.push_back(new ConcreteDot(x, y - length)); // Bottom left corner
    }
    void plot() const {
        std::cout << "Quad with corners: ";
        for (const auto& corner : corners) {
            corner->plot();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    void move_dot(double x, double y) {
        for (auto& corner : corners) {
            corner->move_dot(x, y);
        }
    }
    void rotate_dot(double angle, double cx, double cy) {
        for (auto& corner : corners) {
            corner->rotate_dot(angle, cx, cy);
        }
    }
};

class Rhomb : public Quad {
public:
    Rhomb(ConcreteDot* tl, double length) : Quad(tl, length) {}
};

class Parallel : public Dot {
private:
    ConcreteDot* top_left;
    ConcreteDot* top_right;
    ConcreteDot* bottom_left;
    ConcreteDot* bottom_right;
public:
    Parallel(ConcreteDot* tl, ConcreteDot* tr, ConcreteDot* bl, ConcreteDot* br)
        : top_left(tl), top_right(tr), bottom_left(bl), bottom_right(br) {}
    void plot() const {
        std::cout << "Parallel with corners: ";
        top_left->plot();
        std::cout << " ";
        top_right->plot();
        std::cout << " ";
        bottom_right->plot();
        std::cout << " ";
        bottom_left->plot();
        std::cout << std::endl;
    }
    void move_dot(double x, double y) {
        top_left->move_dot(x, y);
        top_right->move_dot(x, y);
        bottom_left->move_dot(x, y);
        bottom_right->move_dot(x, y);
    }
    void rotate_dot(double angle, double cx, double cy) {
        top_left->rotate_dot(angle, cx, cy);
        top_right->rotate_dot(angle, cx, cy);
        bottom_left->rotate_dot(angle, cx, cy);
        bottom_right->rotate_dot(angle, cx, cy);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    ConcreteDot* p1 = new ConcreteDot(1, 1);

    // Checking Quad
    Quad* quad = new Quad(p1, 4);
    std::cout << "Quad:" << std::endl;
    quad->plot();
    quad->move_dot(0, 0);
    quad->plot();
    quad->rotate_dot(90, p1->get_x(), p1->get_y()); // Passing the center of rotation (x, y)
    quad->plot();
    std::cout << std::endl;

    // Checking Rhomb
    Rhomb* rhomb = new Rhomb(p1, 4);
    std::cout << "Rhomb:" << std::endl;
    rhomb->plot();
    rhomb->move_dot(2, 2);
    rhomb->plot();
    rhomb->rotate_dot(45, p1->get_x(), p1->get_y()); // Passing the center of rotation (x, y)
    rhomb->plot();
    std::cout << std::endl;


        // Checking Parallel
        ConcreteDot* p11 = new ConcreteDot(2, 3);
    ConcreteDot* p2 = new ConcreteDot(6, 3);
    ConcreteDot* p3 = new ConcreteDot(1, 1);
    ConcreteDot* p4 = new ConcreteDot(5, 1);
    Parallel* parallel = new Parallel(p11, p2, p3, p4);
    std::cout << "Parallel:" << std::endl;
    parallel->plot();
    parallel->move_dot(0, 0);
    parallel->plot();
    parallel->rotate_dot(90, p11->get_x(), p11->get_y()); // Passing the center of rotation (x, y)
    parallel->plot();
    std::cout << std::endl;

    // Memory Cleanup
    delete p1;
    delete quad;
    delete rhomb;
    delete parallel;

    return 0;
}