#include <iostream>
#include "string.h"

template <typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;

public:
    Base() : value1(), value2() {}

    Base(T1 v1, T2 v2) : value1(v1), value2(v2) {}

    void setValue1(T1 v1) { value1 = v1; }
    T1 getValue1() const { return value1; }

    void setValue2(T2 v2) { value2 = v2; }
    T2 getValue2() const { return value2; }

    virtual void print() const {
        std::cout << "Base:\n";
        std::cout << "  Value1: " << value1 << "\n";
        std::cout << "  Value2: " << value2 << "\n";
    }

    virtual ~Base() {
        std::cout << "Base destructor called.\n";
    }
};

template <typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;

public:
    Child() : Base<T1, T2>(), value3(), value4() {}

    Child(T1 v1, T2 v2, T3 v3, T4 v4)
        : Base<T1, T2>(v1, v2), value3(v3), value4(v4) {}

    void setValue3(T3 v3) { value3 = v3; }
    T3 getValue3() const { return value3; }

    void setValue4(T4 v4) { value4 = v4; }
    T4 getValue4() const { return value4; }

    void print() const override {
        Base<T1, T2>::print();
        std::cout << "Child:\n";
        std::cout << "  Value3: " << value3 << "\n";
        std::cout << "  Value4: " << value4 << "\n";
    }

    ~Child() {
        std::cout << "Child destructor called.\n";
    }
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;

public:
    Child2() : Child<T1, T2, T3, T4>(), value5(), value6() {}

    Child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6)
        : Child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {}

    void setValue5(T5 v5) { value5 = v5; }
    T5 getValue5() const { return value5; }

    void setValue6(T6 v6) { value6 = v6; }
    T6 getValue6() const { return value6; }

    void print() const override {
        Child<T1, T2, T3, T4>::print();
        std::cout << "Child2:\n";
        std::cout << "  Value5: " << value5 << "\n";
        std::cout << "  Value6: " << value6 << "\n";
    }

    ~Child2() {
        std::cout << "Child2 destructor called.\n";
    }
};

int main() {
    std::cout << "Base Class\n";
    Base<int, double> baseObj(10, 20.5);
    baseObj.print();

    std::cout << "\nChild Class\n";
    Child<int, double, String<>, char> childObj(10, 20.5, String<>("Hello"), 'A');
    childObj.print();

    std::cout << "\nChild2 Class\n";
    Child2<int, double, String<>, char, bool, String<>> child2Obj(10, 20.5, String<>("Hello"), 'A', true, String<>("World"));
    child2Obj.print();

    return 0;
}
