#include "trap.h"

void sram_test(void) {
  void* sram_start = (void*)0x0f000000;
  void* sram_end   = (void*)0x0f002000;
  uint8_t *p1 = sram_start;
  while (p1 != sram_end) {
    *p1 = (uintptr_t)p1 & 0xff;
    p1++;
  }
  p1 = sram_start;
  while (p1 != sram_end) {
    check(*p1 == ((uintptr_t)p1 & 0xff));
    p1++;
  }

  uint16_t *p2 = sram_start;
  while (p2 != sram_end) {
    *p2 = (uintptr_t)p2 & 0xffff;
    p2++;
  }
  p2 = sram_start;
  while (p2 != sram_end) {
    check(*p2 == ((uintptr_t)p2 & 0xffff));
    p2++;
  }

  uint32_t *p3 = sram_start;
  while (p3 != sram_end) {
    *p3 = (uintptr_t)p3 & 0xffffffff;
    p3++;
  }
  p3 = sram_start;
  while (p3 != sram_end) {
    check(*p3 == ((uintptr_t)p3 & 0xffffffff));
    p3++;
  }

  uint64_t *p4 = sram_start;
  while (p4 != sram_end) {
    *p4 = (uint64_t)(uintptr_t)p3 & 0xffffffffffffffff;
    p4++;
  }
  p4 = sram_start;
  while (p4 != sram_end) {
    check(*p4 == ((uint64_t)(uintptr_t)p3 & 0xffffffffffffffff));
    p4++;
  }
}

void psram_test(void) {
  void* psram_start = (void*)0x80000000;
  void* psram_end   = (void*)0x80400000;
  uint8_t *p1 = psram_start;
  while (p1 != psram_end) {
    *p1 = (uintptr_t)p1 & 0xff;
    p1++;
  }
  p1 = psram_start;
  while (p1 != psram_end) {
    check(*p1 == ((uintptr_t)p1 & 0xff));
    p1++;
  }

  uint16_t *p2 = psram_start;
  while (p2 != psram_end) {
    *p2 = (uintptr_t)p2 & 0xffff;
    p2++;
  }
  p2 = psram_start;
  while (p2 != psram_end) {
    check(*p2 == ((uintptr_t)p2 & 0xffff));
    p2++;
  }

  uint32_t *p3 = psram_start;
  while (p3 != psram_end) {
    *p3 = (uintptr_t)p3 & 0xffffffff;
    p3++;
  }
  p3 = psram_start;
  while (p3 != psram_end) {
    check(*p3 == ((uintptr_t)p3 & 0xffffffff));
    p3++;
  }

  uint64_t *p4 = psram_start;
  while (p4 != psram_end) {
    *p4 = (uint64_t)(uintptr_t)p3 & 0xffffffffffffffff;
    p4++;
  }
  p4 = psram_start;
  while (p4 != psram_end) {
    check(*p4 == ((uint64_t)(uintptr_t)p3 & 0xffffffffffffffff));
    p4++;
  }
}

void sdram_test(void) {
  void* sdram_start = (void*)0xA0000000;
  void* sdram_end   = (void*)0xA8000000;
  uint8_t *p1 = sdram_start;
  while (p1 != sdram_end) {
    *p1 = (uintptr_t)p1 & 0xff;
    p1++;
  }
  p1 = sdram_start;
  while (p1 != sdram_end) {
    check(*p1 == ((uintptr_t)p1 & 0xff));
    p1++;
  }

  uint16_t *p2 = sdram_start;
  while (p2 != sdram_end) {
    *p2 = (uintptr_t)p2 & 0xffff;
    p2++;
  }
  p2 = sdram_start;
  while (p2 != sdram_end) {
    check(*p2 == ((uintptr_t)p2 & 0xffff));
    p2++;
  }

  uint32_t *p3 = sdram_start;
  while (p3 != sdram_end) {
    *p3 = (uintptr_t)p3 & 0xffffffff;
    p3++;
  }
  p3 = sdram_start;
  while (p3 != sdram_end) {
    check(*p3 == ((uintptr_t)p3 & 0xffffffff));
    p3++;
  }

  uint64_t *p4 = sdram_start;
  while (p4 != sdram_end) {
    *p4 = (uint64_t)(uintptr_t)p3 & 0xffffffffffffffff;
    p4++;
  }
  p4 = sdram_start;
  while (p4 != sdram_end) {
    check(*p4 == ((uint64_t)(uintptr_t)p3 & 0xffffffffffffffff));
    p4++;
  }
}

void chip_link_mem_test(void) {
  void* chip_link_mem_start = (void*)0xc0000000;
  void* chip_link_mem_end   = (void*)0xc0001000;
  uint8_t *p1 = chip_link_mem_start;
  while (p1 != chip_link_mem_end) {
    *p1 = (uintptr_t)p1 & 0xff;
    p1++;
  }
  p1 = chip_link_mem_start;
  while (p1 != chip_link_mem_end) {
    check(*p1 == ((uintptr_t)p1 & 0xff));
    p1++;
  }

  uint16_t *p2 = chip_link_mem_start;
  while (p2 != chip_link_mem_end) {
    *p2 = (uintptr_t)p2 & 0xffff;
    p2++;
  }
  p2 = chip_link_mem_start;
  while (p2 != chip_link_mem_end) {
    check(*p2 == ((uintptr_t)p2 & 0xffff));
    p2++;
  }

  uint32_t *p3 = chip_link_mem_start;
  while (p3 != chip_link_mem_end) {
    *p3 = (uintptr_t)p3 & 0xffffffff;
    p3++;
  }
  p3 = chip_link_mem_start;
  while (p3 != chip_link_mem_end) {
    check(*p3 == ((uintptr_t)p3 & 0xffffffff));
    p3++;
  }

  uint64_t *p4 = chip_link_mem_start;
  while (p4 != chip_link_mem_end) {
    *p4 = (uint64_t)(uintptr_t)p3 & 0xffffffffffffffff;
    p4++;
  }
  p4 = chip_link_mem_start;
  while (p4 != chip_link_mem_end) {
    check(*p4 == ((uint64_t)(uintptr_t)p3 & 0xffffffffffffffff));
    p4++;
  }
}

int main() {
  chip_link_mem_test();
  return 0;
}
