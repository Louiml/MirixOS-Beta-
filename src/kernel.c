#include "../include/version.h"
#include "../include/tty.h"
#include "../include/io.h"
#include "../include/kbd.h"
#include "../include/string.h"
#include "../include/time.h"
#include "../include/math_shell.h"
#include "../include/parsing.h"
#include "../include/bool.h"
#include "../include/sha224.h"
#include "../include/sha256.h"
#include "../include/utils.h"
#include "../include/easter.h"
#include "../include/thread.h"
#include "../include/memory.h"
#include "../include/stdio.h"
#define DEBUG false
#define BUFFER_SIZE 1024
uint8_t numlock = true;
uint8_t capslock = false;
uint8_t scrolllock = false;
uint8_t shift = false;
char current_version[7];
int main(void)
{
	char buffer[BUFFER_SIZE];
	char *string;
	char *buff;
	uint8_t byte;
	terminal_initialize(default_font_color, COLOR_BLACK);
	terminal_set_colors(COLOR_CYAN, COLOR_BLACK);
	sprintf(current_version, "%u.%u.%u", V1, V2, V3 + 1);
	print_logo();
	terminal_set_colors(COLOR_LIGHT_CYAN, COLOR_BLACK);
	about(current_version);
	terminal_set_colors(COLOR_LIGHT_BROWN, COLOR_BLACK);
	printf("\n\tType \"help\" for a list of commands.\n\n");
	terminal_set_colors(default_font_color, COLOR_BLACK);
	heap_init();
#if DEBUG
	int *a = (int *)kmalloc(sizeof(int));
	void *b = kmalloc(5000);
	void *c = kmalloc(50000);
	*a = 1;
	printf("\na: %d", *a);
	printf("\na: %p", (void *)a);
	printf("\nb: %p", (void *)b);
	printf("\nc: %p", (void *)c);
	int *b = (int *)kmalloc(0x1000);
	int *c = (int *)kmalloc(sizeof(int));
	printf("\nb: %x", b);
	printf("\nc: %x", c);
	kfree(b);
	int *d = (int *)kmalloc(0x1000);
	printf("\nd: %x", d);
	kfree(d);
	kfree(c);
	kfree(a);
	kfree(b);
	kfree(c);
#endif
	strcpy(&buffer[strlen(buffer)], "");
	print_prompt();
	while (true)
	{
		while (byte = scan())
		{
			if (byte == ENTER)
			{
				strcpy(buffer, tolower(buffer));

				if (strlen(buffer) > 0 && strcmp(buffer, "exit") == 0)
				{
					shutdown();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "matrix") == 0)
				{
					terminal_set_colors(COLOR_DARK_GREY, COLOR_BLACK);
					printf("\nusage: matrix -s");
					printf("\nusage: matrix [COMMAND]");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "matrix help") == 0)
				{
					printf("\n\n\tAdministrator kernel commands:\n");
					printf("\n\tVlinux          - \tMirix with linux kernel");
					printf("\n\tbin             - \tThe packages manager");
					printf("\n\tbackground      - \tRandom CLI print matrix BG without back to N");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "matrix vlinux") == 0)
				{
					terminal_set_colors(COLOR_RED, COLOR_BLACK);
					printf("\nYo you can't because it's my rules");
					printf("\nAnd my kernel is better!! #onlymirix");
					print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "matrix bin") == 0)
				{
					terminal_set_colors(COLOR_RED, COLOR_BLACK);
					printf("\nIsn't working like this");
					printf("\nYou need to put: \"install\" or \"remove\" [package]");
					printf("\nhttps://bin-cli.mirix.com");
					printf("\nOoh right you open it because no browser right...");
					print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "matrix bin install") == 0)
				{
					terminal_set_colors(COLOR_BROWN, COLOR_BLACK);
					printf("\nYou need to put a name");
					printf("\nLike: \"matrix bin install [package]\"");
					print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "matrix bin remove") == 0)
				{
					terminal_set_colors(COLOR_BROWN, COLOR_BLACK);
					printf("\nYou need to put a name");
					printf("\nLike: \"matrix bin install [package]\"");
					printf("\nYou're want to see your list just do \"--list\"");
					print_prompt();
					memset(buffer, 0, BUFFER_SIZE);
					strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "anime?") == 0)
				{
					printf("\n\t\t\t\t\t\tYes sir!\n");
					terminal_set_colors(COLOR_LIGHT_BROWN, COLOR_BLACK);
					anime();
					terminal_set_colors(default_font_color, COLOR_BLACK);
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "home-screen") == 0)
				{
					terminal_set_colors(COLOR_CYAN, COLOR_BLACK);
					print_logo();
					terminal_set_colors(COLOR_LIGHT_CYAN, COLOR_BLACK);
					about("0.0.6");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strstr(buffer, "sha256(") != NULL)
				{
					char *parser;
					char string[64];
					parser = strstr(buffer, "sha256(");
					parser += strlen("sha256(");
					parse_string(string, parser, ')');
					sha256(string);
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strstr(buffer, "sha224(") != NULL)
				{
					char *parser;
					char string[64];
					parser = strstr(buffer, "sha224(");
					parser += strlen("sha224(");
					parse_string(string, parser, ')');
					sha224(string);
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strstr(buffer, "echo \"") != NULL){
					char *parser;
					char string[64];
					parser = strstr(buffer, "echo \"");
					parser += strlen("echo \"");
					parse_string(string, parser, '"');
					printf("\n");
					printf(string);
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "echo") == 0){
					terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
					printf("\n");
					printf("You're need to add a string like: echo \"example\"");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strstr(buffer, "printf(") != NULL){
					char *parser;
					char string[64];
					parser = strstr(buffer, "printf(");
					parser += strlen("printf(");
					parse_string(string, parser, ')');
					printf("\n");
					printf(string);
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strstr(buffer, "printf()") != NULL){
					terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
					printf("\n");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "printf") == 0){
					terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
					printf("\n");
					printf("You're need to add a string like: printf(example)");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "ip") == 0){
					printf("0.0.1.1");
				}
				else if (math_func(buffer))
				{
					math_shell(buffer);
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "math") == 0)
				{
					printf("\n\n\tMathematical functions:\n");
					printf("\n\t rand()             - \tpseudo random number generator");
					printf("\n\t srand()            - \tpseudo random number generator seed");
					printf("\n\t fact(x)            - \treturns factorial of x");
					printf("\n\t abs(x)             - \treturns absolute value of x");
					printf("\n\t sqrt(x)            - \treturns square root of x");
					printf("\n\t pow(x,y)           - \treturns the y power of x");
					printf("\n\t exp(x)             - \treturns the natural exponential of x");
					printf("\n\t ln(x)              - \treturns the natural logarithm of x");
					printf("\n\t log10(x)           - \treturns the logarithm of x base 10");
					printf("\n\t log(x,y)           - \treturns the logarithm of x base y");
					printf("\n\t sin(x)             - \treturns sine of x");
					printf("\n\t cos(x)             - \treturns cosine of x");
					printf("\n\t tan(x)             - \treturns tangent of x");
					printf("\n\t asin(x)            - \treturns arcsine of x");
					printf("\n\t acos(x)            - \treturns arccosine of x");
					printf("\n\t atan(x)            - \treturns arctangent of x");
					printf("\n\t sinh(x)            - \treturns hyperbolic sine of x");
					printf("\n\t cosh(x)            - \treturns hyperbolic cosine of x");
					printf("\n\t tanh(x)            - \treturns hyperbolic tangent of x");
					printf("\n\t asinh(x)           - \treturns inverse hyperbolic sine of x");
					printf("\n\t acosh(x)           - \treturns inverse hyperbolic cosine of x");
					printf("\n\t atanh(x)           - \treturns inverse hyperbolic tangent of x");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "crypto") == 0)
				{
					printf("\n\nCryptography utilities:\n");
					printf("\n\t sha224(string)     - \tSHA-224 hashing");
					printf("\n\t sha256(string)     - \tSHA-256 hashing");
					printf("\n");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "help") == 0)
				{
					printf("\n\n\tBasic kernel commands:\n");
					printf("\n\t about              - \tabout MirixOS");
					printf("\n\t math               - \tlists all mathematical functions");
					printf("\n\t crypto             - \tlists all cryptography utilities");
					printf("\n\t clear              - \tclears the screen");
					printf("\n\t fontcolor          - \tchange default font color");
					printf("\n\t datetime           - \tdisplays current date and time");
					printf("\n\t date               - \tdisplays current date");
					printf("\n\t clock              - \tdisplays clock");
					printf("\n\t reboot             - \treboots system");
					printf("\n\t echo               - \tprint something in the terminal");
					printf("\n\t shutdown           - \tsends shutdown signal");
					printf("\n");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "about") == 0)
				{
					about(current_version);
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "fontcolor") == 0)
				{
					default_font_color = change_font_color();
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "clear") == 0)
				{
					terminal_initialize(default_font_color, COLOR_BLACK);
					strcpy(&buffer[strlen(buffer)], "");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "datetime") == 0)
				{
					printf("\nCurrent datetime: ");
					datetime();
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "date") == 0)
				{
					printf("\nCurrent date: ");
					date();
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "clock") == 0)
				{
					printf("\nCurrent clock: ");
					clock();
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "wget-file system-pack.wget") == 0)
				{
					printf("\n1.23\% (cd WgetDownloads");
					printf("\n4.62\% (mkdir \"usr\")");
					printf("\n4.82\% (mkdir \"bin\")");
					printf("\n7.13\% (mkdir \"boot\")");
					printf("\n11.46\% (mkdir \"cdrom\")");
					printf("\n16.28\% (mkdir \"dev\")");
                    printf("\n23.19\% (mkdir \"etc\")");
					printf("\n31.73\% (mkdir \"lib\")");
					printf("\n72\% (servering)");
					printf("\n97.44\% (wget-O0-001100000001 End)");
					printf("\n100\% (The End)");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strstr(buffer, "wget-file") != NULL)
				{
					terminal_set_colors(COLOR_RED, COLOR_BLACK);
					printf("\n[SystemAMI] Error-3591\ncan't open file");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "ls") == 0)
				{
					terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
					printf("\nDocuments            - \tinformation files");
					printf("\nWgetDownloads        - \twget files area");
					printf("\ncommands-line        - \tall the files of the command lines");
					printf("\nSYSemAMI.wget        - \t*Unknown*");
					printf("\nsystem-pack.wget     - \tRun: wget-file system-pack.wget");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "cd documents") == 0)
				{
					printf("\nfor reast to home\nType \"cd ..\"");
					char c = normalmap[byte];
				    char *s;
				    s = ctos(s, c);
				    printf("%s", s);
			    	buffer[strlen(buffer) - 12] = '\0';
					print_prompt_in_documents();
						while (true)
						{
							while (byte = scan())
							{
								if (byte == ENTER)
								{
									strcpy(buffer, tolower(buffer));
									if (strlen(buffer) > 0 && strcmp(buffer, "ls") == 0)
									{
									    terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
									    printf("\nMytext.txt            - \t*Unknown*");
                				        print_prompt_in_documents();
						    		    memset(buffer, 0, BUFFER_SIZE);
							    	    strcpy(&buffer[strlen(buffer)], "");
									}
									else if (strlen(buffer) > 0 && strcmp(buffer, "cd ..") == 0)
									{
									    main();
					           		}
										else if (strlen(buffer) == 0)
										{
											print_prompt_in_documents();
											memset(buffer, 0, BUFFER_SIZE);
											strcpy(&buffer[strlen(buffer)], "");
											}
											else
											{
												printf("\n'%s' is not a recognized command. ", buffer);
												print_prompt_in_documents();
												memset(buffer, 0, BUFFER_SIZE);
												strcpy(&buffer[strlen(buffer)], "");
											}
												break;
												    }
												else if ((byte == BACKSPACE) && (strlen(buffer) == 0))
												{

												}
												else if (byte == BACKSPACE)
												{
													char c = normalmap[byte];
													char *s;
													s = ctos(s, c);
													printf("%s", s);
													buffer[strlen(buffer) - 1] = '\0';
													    }
														else
														{
									char c1 = togglecode[byte];
									char c2 = shiftcode[byte];
									char c;
									if (c1 == CAPSLOCK)
														    {
									    if (!capslock)
									{
									capslock = true;
									terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
									printf("\n[SystemAMI] ");
									terminal_set_colors(COLOR_RED, COLOR_BLACK);
									printf("capslock = true");
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
									else
									{
									capslock = false;
									terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
									printf("\n[SystemAMI] ");
									terminal_set_colors(COLOR_RED, COLOR_BLACK);
									printf("capslock = false");
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
									}
									if (capslock)
									{
									    c = capslockmap[byte];
									}
									else if (shift)
									{
										c = shiftmap[byte];
										shift = false;
									}
									else
									{
										c = normalmap[byte];
									}
									char *s;
									s = ctos(s, c);
									printf("%s", s);
									strcpy(&buffer[strlen(buffer)], s);
									if (byte == 0x2A || byte == 0x36)
									{
										shift = true;
									}
								}
							move_cursor(get_terminal_row(), get_terminal_col());
						}
					}
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "cd wgetdownloads") == 0)
				{
					printf("\nfor reast to home\nType \"cd ..\"");
					char c = normalmap[byte];
				    char *s;
				    s = ctos(s, c);
				    printf("%s", s);
			    	buffer[strlen(buffer) - 16] = '\0';
					print_prompt_in_wgetdownloads();
						while (true)
						{
							while (byte = scan())
							{
								if (byte == ENTER)
								{
									strcpy(buffer, tolower(buffer));
									if (strlen(buffer) > 0 && strcmp(buffer, "ls") == 0)
									{
									    terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
									    printf("\nG++.wget            - \t*Unknown*");
									    printf("\nGCC.wget            - \t*Unknown*");
									    printf("\nDiscord.wget        - \t*Unknown*");
									    printf("\nDesktop.wget        - \tofficial file");
									    printf("\nbfc.wget            - \thttps://github.com/funmmer/bfc");
									    printf("\nfirefox.wget        - \t12.4.6");
                				        print_prompt_in_wgetdownloads();
						    		    memset(buffer, 0, BUFFER_SIZE);
							    	    strcpy(&buffer[strlen(buffer)], "");
									}
									else if (strlen(buffer) > 0 && strcmp(buffer, "cd ..") == 0)
									{
									    main();
					           		}
										else if (strlen(buffer) == 0)
										{
											print_prompt_in_wgetdownloads();
											memset(buffer, 0, BUFFER_SIZE);
											strcpy(&buffer[strlen(buffer)], "");
											}
											else
											{
												printf("\n'%s' is not a recognized command. ", buffer);
												print_prompt_in_wgetdownloads();
												memset(buffer, 0, BUFFER_SIZE);
												strcpy(&buffer[strlen(buffer)], "");
											}
												break;
												    }
												else if ((byte == BACKSPACE) && (strlen(buffer) == 0))
												{

												}
												else if (byte == BACKSPACE)
												{
													char c = normalmap[byte];
													char *s;
													s = ctos(s, c);
													printf("%s", s);
													buffer[strlen(buffer) - 1] = '\0';
													    }
														else
														{
									char c1 = togglecode[byte];
									char c2 = shiftcode[byte];
									char c;
									if (c1 == CAPSLOCK)
														    {
									    if (!capslock)
									{
									capslock = true;
									terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
									printf("\n[SystemAMI] ");
									terminal_set_colors(COLOR_RED, COLOR_BLACK);
									printf("capslock = true");
									print_prompt_in_wgetdownloads();
									}
									else
									{
									capslock = false;
									terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
									printf("\n[SystemAMI] ");
									terminal_set_colors(COLOR_RED, COLOR_BLACK);
									printf("capslock = false");
									print_prompt_in_wgetdownloads();
									}
									}
									if (capslock)
									{
									    c = capslockmap[byte];
									}
									else if (shift)
									{
										c = shiftmap[byte];
										shift = false;
									}
									else
									{
										c = normalmap[byte];
									}
									char *s;
									s = ctos(s, c);
									printf("%s", s);
									strcpy(&buffer[strlen(buffer)], s);
									if (byte == 0x2A || byte == 0x36)
									{
										shift = true;
									}
								}
							move_cursor(get_terminal_row(), get_terminal_col());
						}
					}
				}
                else if (strlen(buffer) > 0 && strcmp(buffer, "cd commands-line") == 0)
				{
					printf("\nfor reast to home\nType \"cd ..\"");
					char c = normalmap[byte];
				    char *s;
				    s = ctos(s, c);
				    printf("%s", s);
			    	buffer[strlen(buffer) - 16] = '\0';
					print_prompt_in_commandsline();
						while (true)
						{
							while (byte = scan())
							{
								if (byte == ENTER)
								{
									strcpy(buffer, tolower(buffer));
									if (strlen(buffer) > 0 && strcmp(buffer, "ls") == 0)
									{
									    terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
									    printf("\nexit            - \tOfficial CLI");
									    printf("\nmatrix          - \tOfficial CLI");
									    printf("\nanime?          - \tUnofficial CLI");
									    printf("\nhome-screen     - \tOfficial CLI");
									    printf("\nsha256          - \tOfficial CLI");
									    printf("\nsha224          - \tOfficial CLI");
									    printf("\necho            - \tOfficial CLI");
									    printf("\nprintf          - \tOfficial CLI");
									    printf("\nmath            - \tOfficial CLI");
									    printf("\ncrypto          - \tOfficial CLI");
									    printf("\nhelp            - \tOfficial CLI");
									    printf("\nabout           - \tOfficial CLI");
									    printf("\nfontcolor       - \tUnofficial CLI");
									    printf("\nclear           - \tOfficial CLI");
									    printf("\ndatetime        - \tOfficial CLI");
									    printf("\ndate            - \tOfficial CLI");
									    printf("\nclock           - \tUnofficial CLI");
									    printf("\nls              - \tOfficial CLI");
									    printf("\ncd              - \tOfficial CLI");
                				        print_prompt_in_commandsline();
						    		    memset(buffer, 0, BUFFER_SIZE);
							    	    strcpy(&buffer[strlen(buffer)], "");
									}
									else if (strlen(buffer) > 0 && strcmp(buffer, "cd ..") == 0)
									{
									    main();
					           		}
										else if (strlen(buffer) == 0)
										{
											print_prompt_in_commandsline();
											memset(buffer, 0, BUFFER_SIZE);
											strcpy(&buffer[strlen(buffer)], "");
											}
											else
											{
												printf("\n'%s' is not a recognized command. ", buffer);
												print_prompt_in_commandsline();
												memset(buffer, 0, BUFFER_SIZE);
												strcpy(&buffer[strlen(buffer)], "");
											}
												break;
												    }
												else if ((byte == BACKSPACE) && (strlen(buffer) == 0))
												{

												}
												else if (byte == BACKSPACE)
												{
													char c = normalmap[byte];
													char *s;
													s = ctos(s, c);
													printf("%s", s);
													buffer[strlen(buffer) - 1] = '\0';
													    }
														else
														{
									char c1 = togglecode[byte];
									char c2 = shiftcode[byte];
									char c;
									if (c1 == CAPSLOCK)
														    {
									    if (!capslock)
									{
									capslock = true;
									terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
									printf("\n[SystemAMI] ");
									terminal_set_colors(COLOR_RED, COLOR_BLACK);
									printf("capslock = true");
									print_prompt_in_commandsline();
									}
									else
									{
									capslock = false;
									terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
									printf("\n[SystemAMI] ");
									terminal_set_colors(COLOR_RED, COLOR_BLACK);
									printf("capslock = false");
									print_prompt_in_commandsline();
									}
									}
									if (capslock)
									{
									    c = capslockmap[byte];
									}
									else if (shift)
									{
										c = shiftmap[byte];
										shift = false;
									}
									else
									{
										c = normalmap[byte];
									}
									char *s;
									s = ctos(s, c);
									printf("%s", s);
									strcpy(&buffer[strlen(buffer)], s);
									if (byte == 0x2A || byte == 0x36)
									{
										shift = true;
									}
								}
							move_cursor(get_terminal_row(), get_terminal_col());
						}
					}
				}
				else if (strlen(buffer) > 0 && strstr(buffer, "cd") != NULL)
				{
					terminal_set_colors(COLOR_DARK_GREY, COLOR_BLACK);
					printf("\nTry 'cd [location]'\ndo 'ls' for look how many files you have");
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "reboot") == 0)
				{
					reboot();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "shutdown") == 0)
				{
					shutdown();
				}
				else if (strlen(buffer) == 0)
				{
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				else
				{
					printf("\n'%s' is not a recognized command. ", buffer);
                    print_prompt();
				    memset(buffer, 0, BUFFER_SIZE);
				    strcpy(&buffer[strlen(buffer)], "");
				}
				break;
			}
			else if ((byte == BACKSPACE) && (strlen(buffer) == 0))
			{
			}
			else if (byte == BACKSPACE)
			{
				char c = normalmap[byte];
				char *s;
				s = ctos(s, c);
				printf("%s", s);
				buffer[strlen(buffer) - 1] = '\0';
			}
			else if ((byte == KEY_DEL) && (strlen(buffer) == 0))
			{
			}
			else if (byte == KEY_DEL)
			{
				char c = normalmap[byte];
				char *s;
				s = ctos(s, c);
				printf("%s", s);
				buffer[strlen(buffer) - 1] = '\0';
			}
			else
			{
				char c1 = togglecode[byte];
				char c2 = shiftcode[byte];
				char c;
				if (c1 == CAPSLOCK)
				{
					if (!capslock)
					{
						capslock = true;
						terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
						printf("\n[SystemAMI] ");
						terminal_set_colors(COLOR_RED, COLOR_BLACK);
						printf("capslock = true");
						terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
                        printf("\nlouiml.com@mirix");
                   	    terminal_set_colors(COLOR_WHITE, COLOR_BLACK);
                        printf("$ ");
                        move_cursor(get_terminal_row(), get_terminal_col());
					}
					else
					{
						capslock = false;
						terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
						printf("\n[SystemAMI] ");
						terminal_set_colors(COLOR_RED, COLOR_BLACK);
						printf("capslock = false");
						terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
                        printf("\nlouiml.com@mirix");
                   	    terminal_set_colors(COLOR_WHITE, COLOR_BLACK);
                        printf("$ ");
                        move_cursor(get_terminal_row(), get_terminal_col());
					}
				}
				if (capslock)
				{
					c = capslockmap[byte];
				}
				else if (shift)
				{
					c = shiftmap[byte];
					shift = false;
				}
				else
				{
					c = normalmap[byte];
				}
				char *s;
				s = ctos(s, c);
				printf("%s", s);
				strcpy(&buffer[strlen(buffer)], s);
				if (byte == 0x2A || byte == 0x36)
				{
					shift = true;
				}
			}
			move_cursor(get_terminal_row(), get_terminal_col());
		}
	}
	return 0;
}
