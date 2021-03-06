/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 03:05:42 by home              #+#    #+#             */
/*   Updated: 2020/06/20 18:48:29 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct	s_display
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}				t_display;

typedef struct	s_game_context
{
	bool		active;
	bool		playing;

	SDL_Texture	*texture;
	SDL_Rect	*src_rect;

	bool		AI_switch;
	char		AI_turn;

	int			turn;
	char		map[9];

	int			mouse_x;
	int			mouse_y;

	int			select_x;
	int			select_y;
}				t_game_state;

#endif
