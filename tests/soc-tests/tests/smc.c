#include "trap.h"

void test1(void) {
  asm volatile("li a0, 0;"
               "li a1, 0x10000000;" // change UART_TX to the correct address
               "li t1, 0x41;"    // 0x41 = 'A'
               "la a2, again1;"
               "li t2, 0x00008067;" // 0x00008067 = ret
               "again1:"
               "sb t1, (a1);"
               "sw t2, (a2);"
               "fence.i;"
               "j again1;");
}

void test2(void) {
  asm volatile("li a0, 0;"
               "li a1, 0x10000000;" // change UART_TX to the correct address
               "la a2, again2;"
               "li t2, 0x04230313;" // addi t1, t1, 0x42 = 'B'
               "addi t1, x0, 0;"
               "sw t2, (a2);"
               "fence.i;"
               "again2:"
               "addi t1, t1, 0x41;"    // 0x41 = 'A'
               "sb t1, (a1);"
               "ret;"
               "j again2;");
}

int main() {
  test1();
  test2();
  return 0;
}
