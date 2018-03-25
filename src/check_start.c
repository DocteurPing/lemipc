/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** check_start
*/

#include "lemipc.h"

bool check_start(map_t *map)
{
	team_player_t *tmp = get_tab_player(map);
	int i = 0;
	int check = 0;

	for (; tmp[i].team != -1; i++) {
		#ifdef DEBUG
			printf("team found: %d | nbr: %d\n",
				tmp[i].team, tmp[i].nbr);
		#endif
		if (tmp[i].nbr > 1)
			check++;
	}
	if (check > 1)
		return (true);
	return (false);
}