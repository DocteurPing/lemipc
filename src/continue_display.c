/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** continue_display
*/

#include "lemipc.h"

void continue_display(lemipc_t lemipc)
{
	display_map(*(map_t *)lemipc.addr);
	sleep(1);
}