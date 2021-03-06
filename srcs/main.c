/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2021/03/06 15:02:48 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <emscripten.h>

void	game_context_initialize(t_game_state *game_state, SDLX_Display *display)
{
	game_state->active = true;
	game_state->playing = true;
	game_state->texture = IMG_LoadTexture(display->renderer, "resources/tictactoe_texture.png");

	if (game_state->texture == NULL)
		printf("Nothing found\n");

	bzero(game_state->map, sizeof(game_state->map));

	game_state->src_rect = carve_tictactoe_texture();

	game_state->AI_switch = false;
	game_state->AI_turn = NONE;

	reset_selection(game_state);

	game_state->turn = 0;
}

void	main_loop(void *v_cxt)
{
	t_game_state		*cxt;
	SDLX_Display		*display;

	cxt = v_cxt;
	display = SDLX_GetDisplay();
	process_user_input(cxt);

	update_game(cxt);

	draw_game_state(cxt, display);
	draw_grid(cxt, display);
	draw_hover_tile(cxt, display);

	// 	draw_win_state();
	// if (game_state.playing = false)

	SDL_RenderPresent(display->renderer);
	SDL_RenderClear(display->renderer);
}

int	main(void)
{
	SDLX_Display		*display;
	t_game_state		cxt;

	display = SDLX_GetDisplay();
	game_context_initialize(&cxt, display);
	AI_initialize(&cxt);
	emscripten_set_main_loop_arg(main_loop, (void *)&(cxt), 80, SDL_TRUE);

	printf("Thank you for playing.\n");
	return (0);
}
