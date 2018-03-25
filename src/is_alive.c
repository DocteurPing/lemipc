/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** is alive
*/

#include "lemipc.h"

int check_others(lemipc_t *lemipc, int team_nbr)
{
	int count = 0;
	map_t *tmp = (map_t *)lemipc->addr;
	int y = lemipc->pos.y;
	int x = lemipc->pos.x;

	for (int i = y > 0 ? -1 : 0; i <= 1; i++) {
		for (int j = x > 0 ? -1 : 0; j <= 1; j++) {
			if (j + x < MAP_SIZE && i + y < MAP_SIZE) {
				int cteam = tmp->map[y + i][x + j].team_nbr;
				if (cteam == team_nbr) {
					count += 1;
				}
			}
		}
	}
	return count;
}

bool is_alive(lemipc_t *lemipc)
{
	map_t *tmp = (map_t *)lemipc->addr;
	int y = lemipc->pos.y;
	int x = lemipc->pos.x;
	int tn = tmp->map[y][x].team_nbr;

	for (int i = y > 0 ? -1 : 0; i <= 1; i++) {
		for (int j = x > 0 ? -1 : 0; j <= 1; j++) {
			if (j + x < MAP_SIZE && i + y < MAP_SIZE) {
				int eteam = tmp->map[y + i][x + j].team_nbr;
				if (eteam != 0 && eteam != tn) {
					int count = check_others(lemipc, eteam);
					if (count > 1) {
						return false;
					}
					count = 0;
				}
			}
		}
	}
	return true;
}