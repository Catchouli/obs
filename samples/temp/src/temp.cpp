#include <iostream>
#include <typeinfo>
#include <sstream>
#include <functional>
#include <typeinfo>
#include <memory>
#include <vector>

#include <obs/Signal.h>
#include <obs/Observer.h>
#include <obs/Connection.h>

struct Test
    : public obs::Observer
{
    void test(int i)
    {
        printf("member function test %d\n", i);
    }
};

int main(int argc, char** argv)
{

    Test test;

    obs::Signal<int> sig;

    sig.connect(&test, &Test::test);

    sig.emit(5);
    sig.emit(5235);
    sig.emit(53262);
    sig.emit(623769);

    system("pause");
    return 0;
}