#ifndef _IO_H
#define _IO_H 1

#include "stdint.h"
#include "tty.h"
#define FB_COMMAND_PORT 0x3d4
#define FB_DATA_PORT 0x3d5
#define FB_HIGH_BYTE_COMMAND 0x0e
#define FB_LOW_BYTE_COMMAND 0x0f
#define KBRD_INTRFC 0x64
#define KBRD_BIT_KDATA 0
#define KBRD_BIT_UDATA 1

#define KBRD_IO 0x60
#define KBRD_RESET 0xFE

#define bit(n) (1 << (n))
#define check_flag(flags, n) ((flags)&bit(n))

void reboot();
void shutdown();
uint8_t input_bytes(uint16_t port);
void output_bytes(uint16_t port, uint8_t val);
uint8_t inw(uint16_t port);
void outw(uint16_t port, uint16_t data);
uint8_t scan(void);
void move_cursor(int row, int col);
void move_cursor2(char c, enum vga_color char_color);
void print_prompt(void);
void print_prompt_in_documents(void);
void print_prompt_in_wgetdownloads(void);
void print_prompt_in_commandsline(void);
#endif