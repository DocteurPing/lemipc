/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** check_end
*/

#include "lemipc.h"

bool check_end(map_t *map)
{
	team_player_t *tmp = get_tab_player(map);
	int i = 0;
	int check = 0;

	for (; tmp[i].team != -1; i++) {
		if (tmp[i].nbr > 1)
			check++;
	}
	if (check > 1)
		return (false);
	return (true);
}