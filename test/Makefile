SRCS	= ../get_next_line.c ../get_next_line_utils.c
B_SRCS	= ../get_next_line_bonus.c ../get_next_line_utils_bonus.c

INCLUDE	= ../
#test src dir
TSD		= src
T_SRCS	+= $(TSD)/ft_strcat.c $(TSD)/create_user_file.c
T_SRCS	+= $(TSD)/file_cmp.c
FM_T_SRCS = $(T_SRCS) $(SRCS) $(TSD)/file_check.c
FB_T_SRCS = $(T_SRCS) $(B_SRCS) $(TSD)/file_check_bonus.c
PB_T_SRCS = $(TSD)/print_terminal_bonus.c $(B_SRCS)
PM_T_SRCS = $(TSD)/print_terminal.c $(SRCS)
SM_T_SRCS = $(TSD)/stdin_check.c $(SRCS)
SMR_T_SRCS = $(T_SRCS) $(TSD)/stdin_redirect_check.c $(SRCS)

FILE	= file/take_me_to_your_heart.txt
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=
CRUN	= && ./a.out
CRUNR	= && ./a.out < $(FILE)
LEAKS_CHECK = leaks --quiet --atExit -- ./a.out

all:	fm fb smr
	

# print Mandatory
pm:
	$(CC) $(CFLAGS)32 -I $(INCLUDE) $(PM_T_SRCS) $(CRUN)
pml:	pm
	$(LEAKS_CHECK)
# print Bonus
pb:
	$(CC) $(CFLAGS)32 -I $(INCLUDE) $(PB_T_SRCS) $(CRUN)
pbl:	pb
	$(LEAKS_CHECK)

# create file then compair
fm:
	$(CC) $(CFLAGS)32 -I $(INCLUDE) $(FM_T_SRCS) $(CRUN)
fml:	fm
	$(LEAKS_CHECK)
# create file then compair bonus
fb:
	$(CC) $(CFLAGS)32 -I $(INCLUDE) $(FB_T_SRCS) $(CRUN)
fbl:	fb
	$(LEAKS_CHECK)

#stdin
sm:
	$(CC) $(CFLAGS)32 -I $(INCLUDE) $(SM_T_SRCS) $(CRUN)
#stdin redirect
smr:
	$(CC) $(CFLAGS)32 -I $(INCLUDE) $(SMR_T_SRCS) $(CRUNR)
smrl: smr
	$(LEAKS_CHECK) < $(FILE)

clean:
	rm -f user/*.txt a.out

re: clean all
