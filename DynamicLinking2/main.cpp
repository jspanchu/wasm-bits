#include "foo.h"
#include "bar.h"

int main(int argc, char** argv)
{
    Foo* foo = new Foo();
    Bar* bar = new Bar();
    foo->SetBar(bar);
    foo->GetBar()->sayHello("World");
    return 0;
}
