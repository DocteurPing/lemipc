/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** get_tab_player
*/

#include "lemipc.h"

team_player_t	*check_in(team_player_t *tmp, int nbr)
{
	int i = 0;

	for (; tmp[i].team != -1; i++) {
		if (tmp[i].team == nbr) {
			tmp[i].nbr++;
			return (tmp);
		}
	}
	tmp[i].team = nbr;
	tmp[i].nbr = 1;
	return (tmp);
}

team_player_t *get_tab_player(map_t *map)
{
	team_player_t *tmp = malloc(sizeof(team_player_t) * 100);
	int x = 0;
	int y = 0;

	for (; x < 100; x++) {
		tmp[x].team = -1;
		tmp[x].nbr = -1;
	}
	for (; y < MAP_SIZE; y++) {
		x = 0;
		for (; x < MAP_SIZE; x++) {
			if (map->map[y][x].team_nbr != 0)
				tmp = check_in(tmp, map->map[y][x].team_nbr);
		}
	}
	return (tmp);
}