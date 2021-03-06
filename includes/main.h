/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 03:57:35 by home              #+#    #+#             */
/*   Updated: 2021/03/06 14:59:57 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

# include <stdio.h>
# include <SDL_image.h>
# include "SDLX.h"

# include "structs.h"
# include "texture_id.h"
# include "min_max.h"

SDL_Rect	*carve_tictactoe_texture(void);

void		AI_initialize(t_game_state *game_state);
void		AI_select_turn(t_game_state *game_state);

void		draw_hover_tile(t_game_state *game_state, SDLX_Display *display);
void		draw_grid(t_game_state *game_state, SDLX_Display *display);
void		draw_game_state(t_game_state *game_state, SDLX_Display *display);

void		process_user_input(t_game_state *game_state);
void		update_game(t_game_state *game_state);

bool		win_state(char *game_state);

void		reset_selection(t_game_state *game_state);

int			screen_to_board(int x, int y);
void		get_loc(int i, int *x, int *y);

#endif
