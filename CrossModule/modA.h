#pragma once
class Bar;

class Foo {
public:
  void SetBar(Bar *b);

private:
  Bar *bar = nullptr;
};
