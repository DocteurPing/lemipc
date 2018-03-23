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
	lemipc_t *lemipc;
	map_t *my_map = malloc(sizeof(map_t));

	if (parse_params(ac, av) == 84)
		return (84);
	lemipc = fill_main_struct_shm(av[1]);
	if (lemipc == NULL)
		return (84);
	lemipc->sem_id = fill_main_struct_sem(lemipc->key);
	if (lemipc->is_first) {
		init_map(my_map);
		if (my_map == NULL)
			return (84);
		memcpy(lemipc->addr, my_map, sizeof(map_t));
	}
	lemipc = init_player(lemipc, av[2]);
	game_loop(lemipc);
	return (0);
}