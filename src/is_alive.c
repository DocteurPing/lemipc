/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** is alive
*/

#include "lemipc.h"

bool is_alive(lemipc_t *lemipc)
{
	map_t *tmp = (map_t *)lemipc->addr;
	int count = 0;
	int y = lemipc->pos.y;
	int x = lemipc->pos.x;
	team_nbr = tmp->map[y + i][x + j].team_nbr;

	for (int i = -1; i <= 1; i ++) {
		for (int j = -1; j <= 1; j ++) {
			if (tmp->map[y + i][x + j].team_nbr != 0
				&& tmp->map[y + i][x + j].team_nbr != team_nbr) {
				count += 1;
			}
		}
	}
	if (count > 1)
		return false;
	return true;
}