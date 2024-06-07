#include <stdio.h>

#include <raylib.h>

int main() {
	InitWindow(250, 250, "cpom");
	
	SetTargetFPS(60);
	int frames = 0;
	
	while(!WindowShouldClose()) {
		frames++;
		frames = frames % 2000;
		BeginDrawing();
		
		ClearBackground(BLACK);
		DrawCircleLines(125, 125, 100, WHITE);
		
		DrawCircle(125, 125, 0.05 * frames, WHITE);
		
		EndDrawing();
	}
	
	CloseWindow();
	
	return 0;
}