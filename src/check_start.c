/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** check_start
*/

#include "lemipc.h"

bool check_start(lemipc_t *lemipc, char *pathname)
{
	lemipc = malloc(sizeof(lemipc));
	lemipc->key = ftok(pathname, 0);
	lemipc->shm_id = shmget(lemipc->key, sizeof(map_t), SHM_R | SHM_W);
	if (lemipc->shm_id == -1) {
		lemipc->shm_id = shmget(lemipc->key, sizeof(map_t),
			IPC_CREAT | SHM_R | SHM_W);
		lemipc->addr = shmat(lemipc->shm_id, NULL, SHM_R | SHM_W);
		#ifdef DEBUG
			fprintf(stderr, "Created segment %d\n", lemipc->shm_id);
		#endif
		return (true);
	}
	#ifdef DEBUG
		fprintf(stderr, "Using segment %d\n", lemipc->shm_id);
	#endif
	lemipc->addr = shmat(lemipc->shm_id, NULL, SHM_R | SHM_W);
	return (false);
}