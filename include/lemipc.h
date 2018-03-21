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

	#define MAP_SIZE 50

	typedef struct	pos_s {
		int x;
		int y;
	}		pos_t;

	typedef struct	player_s {
		size_t team_nbr;
		pid_t pid;
	}		player_t;

	typedef struct map_s {
		size_t nbr_player;
		player_t map[MAP_SIZE][MAP_SIZE];
	}		map_t;

	typedef struct	lemipc_s {
		bool is_first;
		key_t key;
		int shm_id;
		void *addr;
	}		lemipc_t;

	int parse_params(int, char **);
	void print_usage(void);
	bool check_start(lemipc_t *, char *);

#endif /* !LEMIPC_H_ */
