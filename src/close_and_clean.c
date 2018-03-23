/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** close_and_clean
*/

#include "lemipc.h"

void close_and_clean(lemipc_t *lemipc)
{
	#ifdef DEBUG
		fprintf(stderr, "cleaning all...");
	#endif
	shmctl(lemipc->shm_id, 0, IPC_RMID);
	semctl(lemipc->sem_id, 0, IPC_RMID);
	free(lemipc);
}