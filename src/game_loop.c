/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** game_loop
*/

#include "lemipc.h"

void game_loop(lemipc_t *lemipc)
{
	while (1) {
		if (lemipc->is_first)
			display_map(*(map_t *)lemipc->addr);
		sleep(1);
	}
}