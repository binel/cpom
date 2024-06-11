#include <stdio.h>
#include <time.h>
#include <raylib.h>

#define TIMER_SECONDS 1500

void GetTimeString(char* str, double seconds) {
	int secs = (int) seconds;
	int secondsDisp = secs % 60;
	int minutesDisp = (secs - secondsDisp) / 60;
	sprintf(str, "%02d:%02d", minutesDisp, secondsDisp);
}

void DrawRestart() {
	DrawCircle(30, 250, 10, WHITE);
}

bool IsRestartClicked() {
	if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		return false;
	}
	
	Vector2 position = GetMousePosition();
	
	return position.x > 15 && position.x < 45 && position.y > 240 && position.y < 270;
}

int main() {
	bool started = false;

	time_t start, current;
	double elapsed;

	InitWindow(250, 300, "cpom");
	
	SetTargetFPS(60);
	int frames = 0;
	char timeStr[20];
	
	double circlePerSecond = 100.0 / ((double)TIMER_SECONDS);
	
	while(!WindowShouldClose()) {
		BeginDrawing();
		
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) & !started) {
			started = true;
			time(&start);
		}
		
		if (IsRestartClicked()) {
			time(&start);
		}
		
		if (!started) {
			DrawText("Click to start", 15, 125, 32, WHITE);
		}
		else {
			if (elapsed < TIMER_SECONDS)
			{
				time(&current);		
			}
			else {
				started = false;
			}
	
			elapsed = difftime(current, start);
		
			ClearBackground(BLACK);
			DrawCircleLines(125, 125, 100, WHITE);
			
			
			DrawCircle(125, 125, circlePerSecond * elapsed, WHITE);
			GetTimeString(timeStr, elapsed);
			DrawText(timeStr, 90, 250, 32, WHITE);		
			
			DrawRestart();	
		}

		
		EndDrawing();
	}
	
	CloseWindow();
	
	return 0;
}