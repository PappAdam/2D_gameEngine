all: main.c src/camera.c src/engine.c src/gameObj.c src/hitbox.c src/mouse.c src/renderer.c src/runtime.c
	gcc main.c src/camera.c src/engine.c src/gameObj.c src/hitbox.c src/mouse.c src/renderer.c src/runtime.c -w -lSDL2 -lSDL2_image 
	./a.out