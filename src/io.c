#include "../include/io.h"
#include "../include/tty.h"

void shutdown()
{
    outw(0xB004, 0x2000);
    outw(0x604, 0x2000);
    outw(0x4004, 0x3400);
}

void reboot()
{
    uint8_t temp;

    asm volatile("cli")
    do
    {
        temp = input_bytes(KBRD_INTRFC);
        if (check_flag(temp, KBRD_BIT_KDATA) != 0)
            input_bytes(KBRD_IO);
    } while (check_flag(temp, KBRD_BIT_UDATA) != 0);

    output_bytes(KBRD_INTRFC, KBRD_RESET);
loop:
    asm volatile("hlt");
    goto loop;
}

uint8_t input_bytes(uint16_t port)
{
    uint8_t ret;
    __asm__ __volatile__("inb %1, %0"
                         : "= a"(ret)
                         : "Nd"(port));
    return ret;
}

void output_bytes(uint16_t port, uint8_t val)
{
    __asm__ __volatile__("outb %0, %1"
                         :
                         : "a"(val), "Nd"(port));
}

uint8_t inw(uint16_t port)
{
    uint8_t ret;
    __asm__ __volatile__("in %1, %0"
                         : "= a"(ret)
                         : "d"(port));
    return ret;
}

void outw(uint16_t port, uint16_t data)
{
    __asm__ __volatile__("out %0, %1"
                         :
                         : "a"(data), "d"(port));
}

uint8_t scan(void)
{
    unsigned char brk;
    static uint8_t key = 0;
    uint8_t read_char = input_bytes(0x60);
    brk = read_char & 0x80;
    read_char = read_char & 0x7f;
    if (brk)
    {
        return key = 0;
    }
    else if (read_char != key)
    {
        return key = read_char;
    }
    else
    {
        return 0;
    }
}

void move_cursor(int row, int col)
{
    unsigned short pos = (row * VGA_WIDTH) + col;
    output_bytes(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    output_bytes(FB_DATA_PORT, (unsigned char)(pos & 0xFF));
    output_bytes(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    output_bytes(FB_DATA_PORT, (unsigned char)((pos >> 8) & 0xFF));
}

void print_prompt(void)
{
	terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
    printf("\nlouiml.com@mirix");
	terminal_set_colors(COLOR_WHITE, COLOR_BLACK);
    printf("$ ");
    move_cursor(get_terminal_row(), get_terminal_col());
}
void print_prompt_in_documents(void)
{
	terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
    printf("\nlouiml.com@mirix");
	terminal_set_colors(COLOR_WHITE, COLOR_BLACK);
    printf("~");
	terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
    printf("/Documents/");
	terminal_set_colors(COLOR_WHITE, COLOR_BLACK);
    printf("$ ");
    move_cursor(get_terminal_row(), get_terminal_col());
}
void print_prompt_in_wgetdownloads(void)
{
    terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
    printf("\nlouiml.com@mirix");
	terminal_set_colors(COLOR_WHITE, COLOR_BLACK);
    printf("~");
	terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
    printf("/DgetDownloads/");
	terminal_set_colors(COLOR_WHITE, COLOR_BLACK);
    printf("$ ");
    move_cursor(get_terminal_row(), get_terminal_col());
}
void print_prompt_in_commandsline(void)
{
    terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
    printf("\nlouiml.com@mirix");
	terminal_set_colors(COLOR_WHITE, COLOR_BLACK);
    printf("~");
	terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
    printf("/Commands-line/");
	terminal_set_colors(COLOR_WHITE, COLOR_BLACK);
    printf("$ ");
    move_cursor(get_terminal_row(), get_terminal_col());
}