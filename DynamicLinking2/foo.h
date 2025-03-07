#pragma once
class Bar;

class Foo {
public:
  void SetBar(Bar *b);
  Bar* GetBar();

private:
  Bar *bar = nullptr;
};
