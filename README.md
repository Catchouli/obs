<h2>obs</h2>

Simple observer pattern library for C++. This project provides the features of the well known sigslot library, but with C++11 variadic templates.

This library is header-only and free of dependencies. Just grab the include files from obs/include, or from the release page.

Example usage:

```c++
#include <cstdio>
#include <obs/obs.h>

struct Test
    : public obs::Observer
{
    void test(int i)
    {
        printf("member function test %d\n", i);
    }

    void test2(int i)
    {
        printf("member function test 2 %d\n", i * 2);
    }
};

int main(int argc, char** argv)
{
    Test test, test2;

    obs::Signal<int> sig;

    sig.connect(&test, &Test::test);
    sig.connect(&test2, &Test::test);
    sig.connect(&test, &Test::test2);

    // 3 calls
    sig.emit(5);
    
    // 2 calls
    sig.disconnect(&test2);
    sig.emit(10);
    
    // 0 calls
    sig.disconnectAll();
    sig.emit(15);

    system("pause");
    return 0;
}
```

The template arguments to Signal are the arguments of the slot function. Only observer functions with the prototype void(args...) can be registered, providing type safety.

Connections are broken automatically when either observer or signal goes out of scope or is otherwise destructed, and can also be disconnected manually by calling Signal::disconnect or Signal::disconnectAll.
