#include <stdio.h>
#include <time.h>
#include <raylib.h>

void GetTimeString(char* str, double seconds)
{
	int secs = (int) seconds;
	int secondsDisp = secs % 60;
	int minutesDisp = (secs - secondsDisp) / 60;
	sprintf(str, "%02d:%02d", minutesDisp, secondsDisp);
}

int main() {
	bool started = false;

	time_t start, current;
	double elapsed;

	InitWindow(250, 300, "cpom");
	
	SetTargetFPS(60);
	int frames = 0;
	char timeStr[20];
	
	double circlePerSecond = 100.0 / (25.0 * 60.0);
	
	while(!WindowShouldClose()) {
		BeginDrawing();
		
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			started = true;
			time(&start);
		}
		
		if (!started) {
			DrawText("Click to start", 15, 125, 32, WHITE);
		}
		else {
			if (elapsed < 25 * 60)
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
		}

		
		EndDrawing();
	}
	
	CloseWindow();
	
	return 0;
}