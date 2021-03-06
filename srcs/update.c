/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 02:29:27 by home              #+#    #+#             */
/*   Updated: 2021/03/06 13:20:10 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	reset_selection(t_game_state *game_state)
{
	game_state->select_x = -1;
	game_state->select_y = -1;
}

bool	valid_move(t_game_state *game_state)
{
	bool	result;

	result = false;
	if (game_state->select_x == -1 || game_state->select_y == -1)
		return (false);

	if (game_state->map[screen_to_board(game_state->select_x, game_state->select_y)] == '\0')
		result = true;
	return (result);
}

void	update_game(t_game_state *game_state)
{
	if (game_state->AI_switch == true && game_state->turn % 2 == game_state->AI_turn)
		AI_select_turn(game_state);

	if (valid_move(game_state) == true)
	{
		if (game_state->turn % 2 == O_TURN)
			game_state->map[screen_to_board(game_state->select_x, game_state->select_y)] = O_TEX;
		else if (game_state->turn % 2 == X_TURN)
			game_state->map[screen_to_board(game_state->select_x, game_state->select_y)] = X_TEX;
		game_state->turn++;

		if (win_state(game_state->map) == true)
			game_state->active = false;
	}

	reset_selection(game_state);
}

