/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** game_loop
*/

#include "lemipc.h"

static void init_all_color(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_GREEN, COLOR_GREEN);
	init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(5, COLOR_RED, COLOR_RED);
	init_pair(6, COLOR_CYAN, COLOR_CYAN);
}

static WINDOW *setup(void)
{
	WINDOW *mainwin;

	mainwin = initscr();
	noecho();
	init_all_color();
	return (mainwin);
}

static void end(WINDOW *mainwin)
{
	delwin(mainwin);
	endwin();
	refresh();
}

void game_loop(lemipc_t *lemipc)
{
	WINDOW *mainwin;

	if (lemipc->is_first)
		mainwin = setup();
	while (is_alive(lemipc)) {
		if (lemipc->is_first) {
			clear();
			display_map(*(map_t *)lemipc->addr);
			refresh();
		}
		sleep(1);
	}
	if (lemipc->is_first)
		end(mainwin);
	if (((map_t *)lemipc->addr)->nbr_player == 1)
		close_and_clean(lemipc);
}