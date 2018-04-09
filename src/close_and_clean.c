/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** close_and_clean
*/

#include "lemipc.h"

void clean_position(lemipc_t lemipc)
{
	#ifdef DEBUG
		fprintf(stderr, "cleaning position...");
	#endif
	get_access_memory(lemipc.sem_id);
	((map_t *)lemipc.addr)->nbr_player--;
	((map_t *)lemipc.addr)->map[lemipc.pos.y][lemipc.pos.x].team_nbr = 0;
	((map_t *)lemipc.addr)->map[lemipc.pos.y][lemipc.pos.x].pid = 0;
	left_memory_access(lemipc.sem_id);
}

void close_and_clean(lemipc_t lemipc)
{
	#ifdef DEBUG
		fprintf(stderr, "cleaning all...");
	#endif
	if (((map_t *)lemipc.addr)->nbr_player == 1) {
		shmctl(lemipc.shm_id, 0, IPC_RMID);
		semctl(lemipc.sem_id, 0, IPC_RMID);
	}
}