#include "trap.h"

#define GPIO_BASE     0x10002000L
#define GPIO_LED      (GPIO_BASE + 0x0L)
#define GPIO_SW       (GPIO_BASE + 0x4L)
#define GPIO_SEG      (GPIO_BASE + 0x8L)
#define GPIO_RESERVE  (GPIO_BASE + 0xCL)

void unlock() {
  while (inw(GPIO_SW) != 0xffff) continue;
}

void streamlight_helper() {
  uint16_t led = inw(GPIO_LED);
  outw(GPIO_LED, (led << 1) | ((led & 0x8000) >> 15));
}

void streamlight() {
  outw(GPIO_LED, 1);
  while (true) streamlight_helper();
}

int main() {
  unlock();
  outl(GPIO_SEG, 0x1234ABCD);
  streamlight();
  return 0;
}
