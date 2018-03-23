/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** game_loop
*/

#include "lemipc.h"

char *map_to_str(map_t map)
{
	char *str = malloc(sizeof(char) * (MAP_SIZE + 1) * MAP_SIZE);
	int x = 0;
	int y = 0;

	for (; y < MAP_SIZE; y++) {
		x = 0;
		for (; x < MAP_SIZE; x++) {
			str[x + (y * (MAP_SIZE + 1))] =
				map.map[y][x].team_nbr + 48;
		}
		str[x + (y * (MAP_SIZE + 1))] = '\n';
	}
	str[x + (y * (MAP_SIZE + 1)) + 1] = '\0';
	printf("%s\n", str);
	return (str);
}

void init_all_color(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_GREEN, COLOR_GREEN);
	init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(5, COLOR_RED, COLOR_RED);
	init_pair(6, COLOR_CYAN, COLOR_CYAN);
}

void game_loop(lemipc_t *lemipc)
{
	WINDOW *mainwin;

	if (lemipc->is_first) {
		mainwin = initscr();
		noecho();
		init_all_color();
	}
	while (1) {
		if (lemipc->is_first) {
			clear();
			display_map(*(map_t *)lemipc->addr);
			refresh();
		}
		sleep(1);
	}
	if (lemipc->is_first) {
		delwin(mainwin);
		endwin();
		refresh();
	}
}