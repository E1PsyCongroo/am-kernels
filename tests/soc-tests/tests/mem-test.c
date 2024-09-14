#include "trap.h"

int main() {
  uint8_t *p1 = heap.start;
  for (int i = 0; i < 64; i++) {
    *p1 = (uintptr_t)p1 & 0xff;
    p1++;
  }
  p1 = heap.start;
  for (int i = 0; i < 64; i++) {
    check(*p1 == ((uintptr_t)p1 & 0xff));
    p1++;
  }

  uint16_t *p2 = heap.start;
  for (int i = 0; i < 64; i++) {
    *p2 = (uintptr_t)p2 & 0xffff;
    p2++;
  }
  p2 = heap.start;
  for (int i = 0; i < 64; i++) {
    check(*p2 == ((uintptr_t)p2 & 0xffff));
    p2++;
  }

  uint32_t *p3 = heap.start;
  for (int i = 0; i < 64; i++) {
    *p3 = (uintptr_t)p3 & 0xffffffff;
    p3++;
  }
  p3 = heap.start;
  for (int i = 0; i < 64; i++) {
    check(*p3 == ((uintptr_t)p3 & 0xffffffff));
    p3++;
  }

  uint64_t *p4 = heap.start;
  for (int i = 0; i < 64; i++) {
    *p4 = (uint64_t)(uintptr_t)p3 & 0xffffffffffffffff;
    p4++;
  }
  p4 = heap.start;
  for (int i = 0; i < 64; i++) {
    check(*p4 == ((uint64_t)(uintptr_t)p3 & 0xffffffffffffffff));
    p4++;
  }
  return 0;
}
