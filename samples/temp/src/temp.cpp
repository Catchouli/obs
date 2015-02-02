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
    Test test;
    Test test2;

    obs::Signal<int> sig;

    sig.connect(&test, &Test::test);
    sig.connect(&test2, &Test::test);
    sig.connect(&test, &Test::test2);

    sig.emit(5);

    system("pause");
    return 0;
}