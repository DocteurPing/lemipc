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
	#include <sys/sem.h>
	#include <sys/msg.h>
	#include <time.h>
	#include <unistd.h>
	#include <math.h>
	#include <signal.h>

	#define MAP_SIZE 20

	extern int msg_id;

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
		int sem_id;
		pos_t pos;
		void *addr;
	}		lemipc_t;

	typedef struct	team_player_s {
		int team;
		int nbr;
	}		team_player_t;

	typedef struct	msg_s {
		long mtype;
		char mtext[10];
	}		msg_t;

	bool is_alive(lemipc_t);
	lemipc_t move_player(lemipc_t, int, int);
	int parse_params(int, char **);
	void print_usage(void);
	lemipc_t fill_main_struct_shm(char *);
	int fill_main_struct_sem(int);
	int fill_main_struct_msg(int);
	void display_map(map_t);
	void game_loop(lemipc_t);
	lemipc_t init_player(lemipc_t, char *);
	void get_access_memory(int);
	void left_memory_access(int);
	lemipc_t move_left(lemipc_t);
	lemipc_t move_right(lemipc_t);
	lemipc_t move_top(lemipc_t);
	lemipc_t move_down(lemipc_t);
	lemipc_t move_ia(lemipc_t);
	void close_and_clean(lemipc_t);
	void clean_position(lemipc_t);
	team_player_t *get_tab_player(map_t *);
	bool check_end(map_t *);
	bool check_start(map_t *);
	void continue_display(lemipc_t);

#endif /* !LEMIPC_H_ */
