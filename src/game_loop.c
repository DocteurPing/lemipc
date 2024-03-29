/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** game_loop
*/

#include "lemipc.h"

static void send_stop(int signal)
{
	(void)signal;
}

void game_loop(lemipc_t lemipc)
{
	msg_t my_msg;

	signal(SIGINT, send_stop);
	bzero(&my_msg, sizeof(my_msg));
	while (!check_start((map_t *)lemipc.addr))
		sleep(1);
	while (is_alive(lemipc) && !check_end((map_t *)lemipc.addr)) {
		if (lemipc.is_first)
			display_map(*(map_t *)lemipc.addr);
		lemipc = move_ia(lemipc);
		sleep(1);
	}
	clean_position(lemipc);
	while (lemipc.is_first && !check_end((map_t *)lemipc.addr))
		continue_display(lemipc);
	close_and_clean(lemipc);
}