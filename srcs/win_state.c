/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 03:18:34 by home              #+#    #+#             */
/*   Updated: 2021/03/06 13:20:01 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	horizontal_check(char *map)
{
	int	row1;
	int	row2;
	int	row3;

	row1 = 0;
	row2 = 3;
	row3 = 6;
	if (map[row1 + 0] != NONE && map[row1 + 0] == map [row2 + 0] && map[row2 + 0] == map[row3 + 0])
		return (true);
	if (map[row1 + 1] != NONE && map[row1 + 1] == map [row2 + 1] && map[row2 + 1] == map[row3 + 1])
		return (true);
	if (map[row1 + 2] != NONE && map[row1 + 2] == map [row2 + 2] && map[row2 + 2] == map[row3 + 2])
		return (true);
	return (false);
}

bool	vertical_check(char *map)
{
	int	col1;
	int	col2;
	int	col3;

	col1 = 0;
	col2 = 1;
	col3 = 2;
	if (map[col1 + 0] != NONE && map[col1 + 0] == map [col2 + 0] && map[col2 + 0] == map[col3 + 0])
		return (true);
	if (map[col1 + 3] != NONE && map[col1 + 3] == map [col2 + 3] && map[col2 + 3] == map[col3 + 3])
		return (true);
	if (map[col1 + 6] != NONE && map[col1 + 6] == map [col2 + 6] && map[col2 + 6] == map[col3 + 6])
		return (true);
	return (false);
}

bool	diagonal_check(char *map)
{
	if (map[0 + 0 * 3] != NONE && map[0 + 0 * 3] == map [1 + 1 * 3] && map[1 + 1 * 3] == map[2 + 2 * 3])
		return (true);
	if (map[2 + 0 * 3] != NONE && map[2 + 0 * 3] == map [1 + 1 * 3] && map[1 + 1 * 3] == map[0 + 2 * 3])
		return (true);
	return (false);
}

bool	win_state(char *game_state)
{
	bool	result;

	result = false;
	if (horizontal_check(game_state) == true)
		result = true;
	else if (vertical_check(game_state) == true)
		result = true;
	else if (diagonal_check(game_state) == true)
		result = true;
	return (result);
}
