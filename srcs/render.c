/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 01:12:57 by home              #+#    #+#             */
/*   Updated: 2021/03/06 14:58:51 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_hover_tile(t_game_state *game_state, SDLX_Display *display)
{
	SDL_Rect	rect;

	rect.x = (game_state->mouse_x / 64) * 64;
	rect.y = (game_state->mouse_y / 64) * 64;
	rect.h = 64;
	rect.w = 64;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[HOVER]), &rect);
}

void	draw_grid(t_game_state *game_state, SDLX_Display *display)
{
	int	i;

	i = 0;
	SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	while (i < 3)
	{
		SDL_RenderDrawLine(display->renderer, i * 64, 0, i * 64, WIN_HEIGHT);
		SDL_RenderDrawLine(display->renderer, 0, i * 64, WIN_WIDTH, i * 64);
		i++;
	}
	SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	(void)game_state;
}

void	draw_game_state(t_game_state *game_state, SDLX_Display *display)
{
	int			i;
	int			text_type;
	SDL_Rect	rect;
	SDL_Rect	src_rect;

	i = 0;
	rect.h = 64;
	rect.w = 64;
	while (i < 9)
	{
		if (game_state->map[i] != NONE)
		{
			text_type = game_state->map[i];
			get_loc(i, &(rect.x), &(rect.y));
			src_rect = game_state->src_rect[text_type];
			SDL_RenderCopy(display->renderer, game_state->texture, &src_rect, &rect);
		}
		i++;
	}
}
