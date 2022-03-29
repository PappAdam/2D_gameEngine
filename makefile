files = main.c src/engine/camera.c src/engine/engine.c src/engine/gameObj.c src/engine/hitbox.c src/runtime.c

all: $(files)
	gcc $(files) -w -lSDL2 -lSDL2_image 
	./a.out