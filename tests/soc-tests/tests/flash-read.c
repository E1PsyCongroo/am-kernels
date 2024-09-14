#include "trap.h"
#include <stdint.h>

#define SPI_BASE 0x10001000L
#define SPI_RX0 (SPI_BASE + 0x0)
#define SPI_RX1 (SPI_BASE + 0x4)
#define SPI_TX0 (SPI_BASE + 0x0)
#define SPI_TX1 (SPI_BASE + 0x4)
#define SPI_CTRL (SPI_BASE + 0x10)
#define SPI_DIVIDER (SPI_BASE + 0x14)
#define SPI_SS (SPI_BASE + 0x18)

#define FLASH_BASE 0x30000000L

typedef union {
  uint32_t val;
  struct {
    uint32_t char_len : 7;
    uint32_t : 1;
    uint32_t go_bsy : 1;
    uint32_t rx_neg : 1;
    uint32_t tx_neg : 1;
    uint32_t lsb : 1;
    uint32_t ie : 1;
    uint32_t ass : 1;
    uint32_t : 18;
  };
} S_SPI_CTRL;

uint32_t swap32(uint32_t val) {
  return ((val << 24) & 0xff000000) | ((val << 8) & 0x00ff0000) |
         ((val >> 8) & 0x0000ff00) | ((val >> 24) & 0x000000ff);
}

uint32_t flash_read(uint32_t addr) {
  uint32_t send_data = 0x03000000 | (addr & 0xffffff);
  S_SPI_CTRL spi_ctrl = {.val = 0};
  spi_ctrl.ass = 1;
  spi_ctrl.ie = 0;
  spi_ctrl.lsb = 0;
  spi_ctrl.tx_neg = 1;
  spi_ctrl.rx_neg = 0;
  spi_ctrl.go_bsy = 1;
  spi_ctrl.char_len = 0x40;
  outl(SPI_TX1, send_data);
  outb(SPI_DIVIDER, 0b00000001);
  outb(SPI_SS, 0x1);
  outl(SPI_CTRL, spi_ctrl.val);
  while (((S_SPI_CTRL)inl(SPI_CTRL)).go_bsy)
    continue;
  return swap32(inl(SPI_RX0));
}

static const uint32_t img [] = {
  0x100007b7,  // lui	a5,0x10000
  0x04100713,  // li	a4,65
  0x00e78023,  // sb	a4,0(a5) # 10000000
  0x00a00713,  // li	a4,10
  0x00e78023,  // sb	a4,0(a5)
  0x00000513,  // li	a0,0
  0x00100073,  // ebreak (used as npc_trap)
};

int main() {
  uint32_t *inst = malloc(7 * sizeof(uint32_t));
  for (int i = 0; i < 7; i ++) {
    // inst[i] = flash_read(i * 4);
    inst[i] = inl(FLASH_BASE + i * 4);
    check(inst[i] == img[i]);
  }
  ((void(*)())(void*)inst)();
  return 0;
}
