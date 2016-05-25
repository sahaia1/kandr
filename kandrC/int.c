#include <stdio.h>
#include <assert.h>

int foo(int a) {
  assert(a+100 > a);
  printf("%d %d\n",a+100,a);
  return a;
}

int main() {
  foo(100);
  foo(0x7fffffff);
}