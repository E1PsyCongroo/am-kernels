#include "trap.h"

#define PS2_BASE 0x10011000L
#define PS2_KEY (PS2_BASE + 0x0)
#define PS2_SIZE 8
#define PS2_END (PS2_BASE + PS2_SIZE)

int main() {
  while (1) {
    uint32_t key = inb(PS2_KEY);
    if (key) {
      printf("receive key: %#2x\n", key);
    }
  }
  return 0;
}
