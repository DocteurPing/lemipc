/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** include
*/

#ifndef LEMIPC_H_
	#define LEMIPC_H_

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>
	#include <sys/ipc.h>
	#include <sys/types.h>
	#include <sys/shm.h>

	typedef struct	lemipc_s {
		bool is_first;
		key_t key;
		int shm_id;
		void *addr;
	}		lemipc_t;

	int parse_params(int, char **);
	void print_usage(void);

#endif /* !LEMIPC_H_ */
