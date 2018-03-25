/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** player action
*/

#include "lemipc.h"

lemipc_t *move_player(lemipc_t *lemipc, int x, int y)
{
	map_t *tmp = (map_t *)lemipc->addr;
	int posy = lemipc->pos.y;
	int posx = lemipc->pos.x;
	if ((posx + x) >= MAP_SIZE || (posy + y) >= MAP_SIZE
	|| (posx + x) < 0 || (posy + y) < 0) {
		return lemipc;
	}
	if (tmp->map[posy + y][posx + x].team_nbr == 0) {
		get_access_memory(lemipc->sem_id);
		tmp->map[posy + y][posx + x].team_nbr =
			tmp->map[posy][posx].team_nbr;
		tmp->map[posy + y][posx + x].pid = tmp->map[posy][posx].pid;
		tmp->map[posy][posx].team_nbr = 0;
		tmp->map[posy][posx].pid = 0;
		lemipc->pos.x = posx + x;
		lemipc->pos.y = posy + y;
		left_memory_access(lemipc->sem_id);
	}
	return lemipc;
}

lemipc_t *move_left(lemipc_t *lemipc)
{
	pos_t tmp = lemipc->pos;

	lemipc = move_player(lemipc, -1, 0);
	if (lemipc->pos.x == tmp.x && lemipc->pos.y == tmp.y)
		lemipc = move_player(lemipc, 0, 1);
	if (lemipc->pos.x == tmp.x && lemipc->pos.y == tmp.y)
		lemipc = move_player(lemipc, 0, -1);
	return lemipc;
}

lemipc_t *move_right(lemipc_t *lemipc)
{
	pos_t tmp = lemipc->pos;

	lemipc = move_player(lemipc, 1, 0);
	if (lemipc->pos.x == tmp.x && lemipc->pos.y == tmp.y)
		lemipc = move_player(lemipc, 0, 1);
	if (lemipc->pos.x == tmp.x && lemipc->pos.y == tmp.y)
		lemipc = move_player(lemipc, 0, -1);
	return lemipc;
}

lemipc_t *move_top(lemipc_t *lemipc)
{
	pos_t tmp = lemipc->pos;

	lemipc = move_player(lemipc, 0, -1);
	if (lemipc->pos.x == tmp.x && lemipc->pos.y == tmp.y)
		lemipc = move_player(lemipc, 1, 0);
	if (lemipc->pos.x == tmp.x && lemipc->pos.y == tmp.y)
		lemipc = move_player(lemipc, -1, 0);
	return lemipc;
}

lemipc_t *move_down(lemipc_t *lemipc)
{
	pos_t tmp = lemipc->pos;

	lemipc = move_player(lemipc, 0, 1);
	if (lemipc->pos.x == tmp.x && lemipc->pos.y == tmp.y)
		lemipc = move_player(lemipc, 1, 0);
	if (lemipc->pos.x == tmp.x && lemipc->pos.y == tmp.y)
		lemipc = move_player(lemipc, -1, 0);
	return lemipc;
}