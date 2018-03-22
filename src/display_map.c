/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** display_map
*/

#include "lemipc.h"

void display_inside_map(map_t map)
{
	int x = 0;
	int y = 0;

	for (; y < MAP_SIZE; y++) {
		x = 0;
		printw("|");
		for (; x < MAP_SIZE; x++) {
			if (map.map[y][x].team_nbr == 0)
				printw(" ");
			else {
				attron(COLOR_PAIR(map.map[y][x].team_nbr));
				printw(" ");
				attroff(COLOR_PAIR(map.map[y][x].team_nbr));
			}
		}
		printw("|\n");
	}
}

void display_map(map_t map)
{
	int x = 0;

	for (x = 0; x < MAP_SIZE + 2; x++)
		printw("-");
	printw("\n");
	display_inside_map(map);
	for (x = 0; x < MAP_SIZE + 2; x++)
		printw("-");
	printw("\n");
}