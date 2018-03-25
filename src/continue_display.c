/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** continue_display
*/

#include "lemipc.h"

void continue_display(lemipc_t *lemipc)
{
	if (lemipc->is_first && lemipc->ncurses) {
			clear();
			display_map_ncurses(*(map_t *)lemipc->addr);
			refresh();
		}
		else if (lemipc->is_first)
			display_map(*(map_t *)lemipc->addr);
		sleep(1);
}