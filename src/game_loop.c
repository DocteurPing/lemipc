/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** game_loop
*/

#include "lemipc.h"

int msg_id;

static void send_stop(int signal)
{
	msg_t my_msg;

	(void)signal;
	#ifdef DEBUG
	printf("SEND STOP\nmsg_id = %d\n", msg_id);
	#endif
	bzero(&my_msg, sizeof(my_msg));
	my_msg.mtype = 1;
	sprintf(my_msg.mtext, "end");
	msgsnd(msg_id, &my_msg, sizeof(my_msg), 0);
	msgctl(msg_id, IPC_RMID, NULL);
}

void game_loop(lemipc_t lemipc)
{
	msg_t my_msg;

	signal(SIGINT, send_stop);
	bzero(&my_msg, sizeof(my_msg));
	msgrcv(msg_id, &my_msg, sizeof(my_msg), 1, 0);
	while (!check_start((map_t *)lemipc.addr))
		sleep(1);
	while (is_alive(lemipc) && !check_end((map_t *)lemipc.addr) && my_msg.mtype != 1) {
		msgrcv(msg_id, &my_msg, sizeof(my_msg), 1, 0);
		printf("recieved message %ld : %s\n", my_msg.mtype, my_msg.mtext);
		if (lemipc.is_first)
			display_map(*(map_t *)lemipc.addr);
		lemipc = move_ia(lemipc);
		sleep(1);
	}
	clean_position(lemipc);
	while (lemipc.is_first && !check_end((map_t *)lemipc.addr))
		continue_display(lemipc);
	close_and_clean(lemipc);
}