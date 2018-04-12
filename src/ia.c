/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** ia
*/

#include "lemipc.h"

pos_t	find_enemy(pos_t my_pos, size_t nbr_team, map_t *map)
{
	int distance = 1000;
	int curr_dist;
	pos_t to_return;

	for (int y = 0; y < MAP_SIZE; y++) {
		for (int x = 0; x < MAP_SIZE; x++) {
			if (map->map[y][x].team_nbr != nbr_team &&
				map->map[y][x].team_nbr != 0) {
				curr_dist = sqrt(pow(x - my_pos.x, 2) +
					pow(y - my_pos.y, 2));
				if (curr_dist < distance) {
					distance = curr_dist;
					to_return.x = x;
					to_return.y = y;
				}
			}
		}
	}
	return (to_return);
}

pos_t get_pos_from_msg(char *str)
{
	pos_t pos;

	pos.x = str[0];
	pos.y = str[1];
	return (pos);
}

pos_t get_pos(lemipc_t lemipc)
{
	pos_t pos;
	msg_t my_msg;
	size_t team_nbr =
	((map_t *)lemipc.addr)->map[lemipc.pos.y][lemipc.pos.x].team_nbr;

	/* get_access_memory(lemipc.sem_id);
	left_memory_access(lemipc.sem_id); */
	bzero(&my_msg, sizeof(my_msg));
	pos = rcv_msg(lemipc.msg_id, team_nbr);
	if (pos.x >= 0) {
		pos = find_enemy(lemipc.pos, team_nbr, ((map_t *)lemipc.addr));
		my_msg.mtype = team_nbr;
		my_msg.mtext[0] = pos.x;
		my_msg.mtext[1] = pos.y;
		msgsnd(lemipc.msg_id, &my_msg, sizeof(my_msg), 0);
	}
	else {
		printf("recieve msg\n");
		pos = get_pos_from_msg(my_msg.mtext);
	}
	return (pos);
}

lemipc_t move_ia(lemipc_t lemipc)
{
	int random_nbr = rand() % 4;
	pos_t pos;

	pos = get_pos(lemipc);
	if (pos.x < lemipc.pos.x && random_nbr == 0)
		return (lemipc = move_left(lemipc));
	if (pos.x > lemipc.pos.x && random_nbr == 1)
		return (lemipc = move_right(lemipc));
	if (pos.y < lemipc.pos.y && random_nbr == 2)
		return (lemipc = move_top(lemipc));
	if (pos.y > lemipc.pos.y && random_nbr == 3)
		return (lemipc = move_down(lemipc));
	return (move_ia(lemipc));
}