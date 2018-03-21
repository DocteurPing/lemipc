/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** check_start
*/

#include "lemipc.h"

lemipc_t *fill_main_struct_shm(char *pathname)
{
	lemipc_t *lemipc = malloc(sizeof(lemipc_t));

	lemipc->key = ftok(pathname, 0);
	lemipc->shm_id = shmget(lemipc->key, sizeof(map_t), SHM_R | SHM_W);
	if (lemipc->shm_id == -1) {
		lemipc->shm_id = shmget(lemipc->key, sizeof(map_t),
			IPC_CREAT | SHM_R | SHM_W);
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

int	fill_main_struct_sem(int key)
{
	int sem_id = semget(key, 1, SHM_R | SHM_W);

	if (sem_id == -1) {
		sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
		if (sem_id == -1)
			perror("semget");
		printf("Created sem %d\n", sem_id);
		semctl(sem_id, 0, SETVAL, 1);
		return (sem_id);
	}
	printf("Using sem %d\n", sem_id);
	return (sem_id);
}