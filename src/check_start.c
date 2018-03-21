/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** check_start
*/

#include "lemipc.h"

bool check_start(lemipc_t *lemipc, char *pathname)
{
	lemipc = malloc(sizeof(lemipc_t));
	lemipc->key = ftok(pathname, 0);
	lemipc->shm_id = shmget(lemipc->key, sizeof(map_t) + 1000, SHM_R | SHM_W);
	if (lemipc->shm_id == -1) {
		lemipc->shm_id = shmget(lemipc->key, sizeof(map_t) + 1000,
			IPC_CREAT | SHM_R | SHM_W);
		lemipc->addr = shmat(lemipc->shm_id, NULL, SHM_R | SHM_W);
		lemipc->is_first = true;
		#ifdef DEBUG
			fprintf(stderr, "Created segment %d\n", lemipc->shm_id);
		#endif
		return (true);
	}
	#ifdef DEBUG
		fprintf(stderr, "Using segment %d\n", lemipc->shm_id);
	#endif
	lemipc->is_first = false;
	lemipc->addr = shmat(lemipc->shm_id, NULL, SHM_R | SHM_W);
	return (false);
}