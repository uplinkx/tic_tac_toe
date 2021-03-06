/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carve_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 00:53:51 by home              #+#    #+#             */
/*   Updated: 2021/03/06 13:18:09 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

SDL_Rect	*carve_tictactoe_texture()
{
	int			col;
	int			row;
	SDL_Rect	*result;

	row = 0;
	result = malloc(sizeof(*result) * (4 * 2));
	while (row < 2)
	{
		col = 0;
		while (col < 4)
		{
			result[row * 4 + col].h = 16;
			result[row * 4 + col].w = 16;
			result[row * 4 + col].x = (col * 16);
			result[row * 4 + col].y = (row * 16);
			col++;
		}
		row++;
	}

	return (result);
}
