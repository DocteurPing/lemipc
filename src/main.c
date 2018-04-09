/*
** EPITECH PROJECT, 2018
** lemIPC
** File description:
** main
*/

#include "lemipc.h"

void init_map(map_t *my_map)
{
	int x = 0;
	int y = 0;

	for (; y < MAP_SIZE; y++) {
		x = 0;
		for (; x < MAP_SIZE; x++) {
			my_map->map[y][x].pid = 0;
			my_map->map[y][x].team_nbr = 0;
		}
	}
	my_map->nbr_player = 0;
}

int main(int ac, char **av)
{
	lemipc_t lemipc;

	if (parse_params(ac, av) == 84)
		return (84);
	lemipc = fill_main_struct_shm(av[1]);
	lemipc.sem_id = fill_main_struct_sem(lemipc.key);
	if (lemipc.is_first)
		init_map((map_t *)lemipc.addr);
	lemipc = init_player(lemipc, av[2]);
	game_loop(lemipc);
	return (0);
}