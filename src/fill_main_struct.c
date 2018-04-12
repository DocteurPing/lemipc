/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** check_start
*/

#include "lemipc.h"

lemipc_t fill_main_struct_shm(char *pathname)
{
	lemipc_t lemipc;

	lemipc.key = ftok(pathname, 0);
	lemipc.shm_id = shmget(lemipc.key, sizeof(map_t), SHM_R | SHM_W);
	if (lemipc.shm_id == -1) {
		lemipc.shm_id = shmget(lemipc.key, sizeof(map_t),
			IPC_CREAT | SHM_R | SHM_W);
		if ((lemipc.addr = shmat(lemipc.shm_id, NULL,
			SHM_R | SHM_W)) == NULL)
			perror("shmat");
		lemipc.is_first = true;
		return (lemipc);
	}
	lemipc.is_first = false;
	lemipc.addr = shmat(lemipc.shm_id, NULL, SHM_R | SHM_W);
	if (lemipc.addr == NULL)
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
		#ifdef DEBUG
		printf("Created sem %d\n", sem_id);
		#endif
		semctl(sem_id, 0, SETVAL, 1);
		return (sem_id);
	}
	#ifdef DEBUG
	printf("Using sem %d\n", sem_id);
	#endif
	return (sem_id);
}

int	fill_main_struct_msg(int key)
{
	int msg_id = msgget(key, SHM_R | SHM_W);

	if (msg_id == -1) {
		msg_id = msgget(key, IPC_CREAT | SHM_R | SHM_W);
		if (msg_id == -1)
			perror("msgget");
		#ifdef DEBUG
		printf("Created msg %d\n", msg_id);
		#endif
	}
	#ifdef DEBUG
	printf("Using msg %d\n", msg_id);
	#endif
	return (msg_id);
}