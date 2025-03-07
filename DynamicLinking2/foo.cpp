#include "foo.h"
#include "bar.h"

void Foo::SetBar(Bar *b) { this->bar = b; }

Bar* Foo::GetBar() { return this->bar; }
