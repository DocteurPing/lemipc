/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** close_and_clean
*/

#include "lemipc.h"

void close_and_clean(lemipc_t *lemipc)
{
	shmctl(lemipc->shm_id, IPC_RMID, NULL);
	free(lemipc);
}