/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** msg
*/

#include "lemipc.h"

pos_t	rcv_msg(int id, int team_nbr)
{
	msg_t	msg;
	pos_t	to_return;

	to_return.x = -1;
	to_return.y = -1;
	msg.mtype = team_nbr;
	msgrcv(id, &msg, sizeof(msg.mtext), team_nbr, IPC_NOWAIT);
	if (errno == ENOMSG)
		return (to_return);
	to_return.x = msg.mtext[0];
	to_return.y = msg.mtext[1];
	return (to_return);
}