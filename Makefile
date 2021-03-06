NAME = index.html

FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/
LIBRARIES = -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS="['png']"
SKELE_HTML = --shell-file srcs/skeleton.html

PRELOAD_FILES =			\
	resources/			\

PRELOAD = --preload-file $(PRELOAD_FILES)

SRC_DIR = srcs/

# List of all the source files.
SDLX_NAMES =	\
	SDLX_init	\

SRC_NAMES = \
	$(addprefix SDLX/, $(SDLX_NAMES))	\
	ai_routine \
	carve_texture \
	game_input \
	main \
	render \
	update \
	utils \
	win_state \

SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_NAMES)))

all: $(NAME)

$(NAME):
	emcc $(FLAGS) $(INCLUDES) $(PRELOAD) $(LIBRARIES) $(SRCS) -o $(NAME)

fclean:
	rm -rf $(NAME)

# Ensure that when git add is done the repo is cleaned out.
save: fclean
	git add .
	git commit -m "$(MSG)"
	git push

re: fclean all
