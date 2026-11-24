
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -I include -lraylib -lm -Wl,-rpath=/usr/local/lib
NAME = test
SRC = src/game.c src/map.c src/player.c src/raycaster.c src/hud.c
OBJ = $(SRC:.c=.o)

# --- Configuration Web (Emscripten) ---
# Vérifiez que ce chemin pointe bien vers le dossier src de raylib compilé pour le web
RAYLIB_WEB_PATH = $(HOME)/raylib/src
WEB_NAME = index.html

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Nouvelle règle pour compiler la version Web
web:
	emcc -o $(WEB_NAME) $(SRC) -Os -Wall -Wextra -Werror \
		-Iinclude \
		-I$(RAYLIB_WEB_PATH) \
		$(RAYLIB_WEB_PATH)/libraylib.web.a \
		-s USE_GLFW=3 \
		-s ASYNCIFY \
		-DPLATFORM_WEB

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) index.html index.js index.wasm index.data

re: fclean all

.PHONY: all web clean fclean re

