/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 11:30:10 by home              #+#    #+#             */
/*   Updated: 2021/03/06 15:02:02 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	process_user_input(t_game_state *game_state)
{
	SDL_Event		e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			game_state->active = false;
			break ;
		}
		else if (e.type == SDL_MOUSEMOTION)
			SDL_GetMouseState(&(game_state->mouse_x), &(game_state->mouse_y));
		else if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&(game_state->select_x), &(game_state->select_y));
			printf("here\n");
		}
	}
}
