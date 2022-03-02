#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <functional>

class comeHereClass
{

public:
    const static int somedummyconst;
};

const int comeHereClass::somedummyconst = 5;

class abc
{
private:
    friend class someNewChildClass;
    int somevar;
    int _x;
    comeHereClass _cla;

public:
    int get__x() const
    {
        return _x;
    }
    void set__x(int value)
    {
        _x = value;
    }

public:
    void print() const
    {
        std::cout << "hello" << std::endl;
    };

public:
    abc() = default;

public:
    abc(int a) : _x(a)
    {
        std::cout << get__x() << std::endl;
        std::cout << "fuck vscode" << std::endl;
    };

    abc(const abc &old)
    {}

    abc &operator=(abc old)
    {
        return *this;
    }

    template <typename T>
    void func(T purum)
    {
    }

    // template <typename... T> not a fact, that works like this
    // void funcWithAllParams(T... params)
    // {
    //     auto hey = ...params;
    // }

    // abc(const abc &old) = delete;

    // abc& operator=(abc old) = delete;
};

class someNewChildClass : public abc
{
public:
    using abc::abc; // when someNewChildClass newclass; abc() is being called;
    void set__x(int value)
    {
        _x = value;
    }

public:
    int asdf() const
    {

        std::cout << somevar;
        return _x;
    }
};

void s(std::unique_ptr<abc> &ab);

// int main(int argc, char const *argv[])
// {
//     int some = 5;
//     int my = 10;

//     const abc a{5};

//     a.print();

//     std::unique_ptr<abc> ab = std::make_unique<abc>(5);
//     std::shared_ptr<abc> shared = std::make_shared<abc>(5);

//     auto copy = shared;

//     s(ab);

//     int h = comeHereClass::somedummyconst;

//     std::cout << h + 1 << std::endl;

//     std::function<void(int)> asdfsd = [](int somevar)
//     {
//         std::cout << somevar << std::endl;
//     };

//     int c(5);
//     int g{5};

//     asdfsd(c);

//     abc first;
//     abc second = first;
//     abc third;

//     third = first;

//     return 0;
// }

int main()
{
    using std::cout;
    using std::endl;
    using std::string;

    string somestr = "adsfas f";
    //move semantic
    string secondstr = std::move(somestr); // somestr = null from that moment

    cout << somestr << endl;
    cout << secondstr << endl;

    someNewChildClass someNewChildClass;

    someNewChildClass.asdf();

    return 0;
}

void s(std::unique_ptr<abc> &ab)
{
    ab = std::make_unique<abc>(8);
}
