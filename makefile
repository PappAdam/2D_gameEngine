all: main.c src/engine/camera.c src/engine/engine.c src/engine/gameObj.c src/engine/hitbox.c src/engine/mouse.c src/engine/renderer.c src/runtime.c
	gcc main.c src/engine/camera.c src/engine/engine.c src/engine/gameObj.c src/engine/hitbox.c src/engine/mouse.c src/engine/renderer.c src/runtime.c -w -lSDL2 -lSDL2_image 
	./a.out