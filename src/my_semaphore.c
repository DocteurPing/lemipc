/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** my_semaphore
*/

#include "lemipc.h"

void	get_access_memory(int id)
{
	struct sembuf	sops;

	sops.sem_num = 0;
	sops.sem_flg = 0;
	sops.sem_op = -1;
	semop(id, &sops, 1);
}

void	left_memory_access(int id)
{
	struct sembuf	sops;

	if (semctl(id, 0, GETVAL) == 1)
		return ;
	sops.sem_num = 0;
	sops.sem_flg = 0;
	sops.sem_op = 1;
	semop(id, &sops, 1);
}