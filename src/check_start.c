/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** check_start
*/

#include "lemipc.h"

lemipc_t *check_start(char *pathname)
{
	lemipc_t *lemipc = malloc(sizeof(lemipc_t));

	lemipc->key = ftok(pathname, 0);
	lemipc->shm_id = shmget(lemipc->key, sizeof(map_t), SHM_R | SHM_W);
	if (lemipc->shm_id == -1) {
		if ((lemipc->shm_id = shmget(lemipc->key, sizeof(map_t),
			IPC_CREAT | SHM_R | SHM_W)) == -1)
			perror("shmget");
		if ((lemipc->addr = shmat(lemipc->shm_id, NULL,
			SHM_R | SHM_W)) == NULL)
			perror("shmat");
		lemipc->is_first = true;
		fprintf(stderr, "Created segment %d\n", lemipc->shm_id);
		return (lemipc);
	}
	fprintf(stderr, "Using segment %d\n", lemipc->shm_id);
	lemipc->is_first = false;
	lemipc->addr = shmat(lemipc->shm_id, NULL, SHM_R | SHM_W);
	if (lemipc->addr == NULL)
		perror("shmat");
	return (lemipc);
}