/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:46:23 by home              #+#    #+#             */
/*   Updated: 2021/03/06 15:19:11 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <time.h>

void	AI_initialize(t_game_state *game_state)
{
	int	num1;
	int	num2;

	srand(time(NULL));
	game_state->AI_switch = true;

	num1 = rand();
	num2 = rand();
	if (num1 > num2)
	{
		printf("You are player O!\n");
		game_state->AI_turn = X_TURN;
	}
	else
	{
		printf("You are player X!\n");
		game_state->AI_turn = O_TURN;
	}
}

int	make_choice_list(int *dest, char *board)
{
	int	i;
	int	at;

	i = 0;
	at = 0;
	while (i < 9)
	{
		if (board[i] == NONE)
		{
			dest[at] = i;
			at++;
		}
		i++;
	}
	return (at);
}

void	do_action(int choice, char *board, int turn, char player_type)
{
	char	player;
	char	opponent;

	if (player_type == X_TURN)
	{
		player = X_TEX;
		opponent = O_TEX;
	}
	else
	{
		player = O_TEX;
		opponent = X_TEX;
	}

	if (turn % 2 == OUR_TURN)
		board[choice] = player;
	else
		board[choice] = opponent;
}

void	undo_action(int choice, char *board, int turn, char player)
{
	board[choice] = NONE;
	(void)turn;
	(void)player;
}

int	min_max_starting_limit(int turn)
{
	int	result;

	if (turn % 2 == OUR_TURN)
		result = MAXIMIZING_LOWER_LIMIT;
	else
		result = MINIMIZING_UPPER_LIMIT;
	return (result);
}

int	min_max(t_game_state *board, int depth, int *choice_dest)
{
	int	i;
	int	result;
	int	current_desirability;
	int	total_choices;
	int	choice_list[9];


	if (win_state(board->map) == true && ((depth - 1) % 2) == OUR_TURN)
		return (1);
	else if (win_state(board->map) == true)
		return (-1);

	total_choices = make_choice_list(choice_list, board->map);
	if (depth >= MAX_DEPTH + 3 || total_choices == 0)
		return (UNDECIDABLE_DESIRABILITY);

	i = 0;
	result = min_max_starting_limit(depth);
	while (i < total_choices)
	{
		do_action(choice_list[i], board->map, depth, board->AI_turn);

		current_desirability = min_max(board, depth + 1, choice_dest);

		if (current_desirability > result && depth == 0) // This needs to be done first, before result is updated.
			*choice_dest = choice_list[i];

		if (depth % 2 == OUR_TURN && current_desirability > result)
			result = current_desirability;
		else if (depth % 2 != OUR_TURN && current_desirability < result)
			result = current_desirability;

		undo_action(choice_list[i], board->map, depth, board->AI_turn);
		i++;
	}
	return (result);
}

void	AI_select_turn(t_game_state *game_state)
{
	int	x;
	int	y;

	int	i;
	i = 0;

	min_max(game_state, 0, &i);

	x = (i % 3) * 64;
	y = (i / 3) * 64;

	game_state->select_x = x;
	game_state->select_y = y;
}