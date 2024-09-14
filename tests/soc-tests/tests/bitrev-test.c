#include "trap.h"

#define SPI_BASE 0x10001000L
#define SPI_RX (SPI_BASE + 0x0)
#define SPI_TX (SPI_BASE + 0x0)
#define SPI_CTRL (SPI_BASE + 0x10)
#define SPI_DIVIDER (SPI_BASE + 0x14)
#define SPI_SS (SPI_BASE + 0x18)

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

int main() {
  char send_data = 0b10101010;
  char expected_receive_data = 0b01010101;
  S_SPI_CTRL spi_ctrl = {.val = 0};
  spi_ctrl.ass = 1;
  spi_ctrl.ie = 0;
  spi_ctrl.lsb = 1;
  spi_ctrl.tx_neg = 0;
  spi_ctrl.rx_neg = 0;
  spi_ctrl.go_bsy = 0;
  spi_ctrl.char_len = 0x10;
  outb(SPI_DIVIDER, 0b00000001);
  outl(SPI_CTRL, spi_ctrl.val);
  outb(SPI_SS, 0b10000000);
  outb(SPI_TX, send_data);
  spi_ctrl.go_bsy = 1;
  outl(SPI_CTRL, spi_ctrl.val);
  while (((S_SPI_CTRL)inl(SPI_CTRL)).go_bsy)
    continue;
  char receive_data = inw(SPI_RX) >> 8;
  check(expected_receive_data == receive_data);
  return 0;
}
