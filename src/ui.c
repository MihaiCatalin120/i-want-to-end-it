#include "config.h"
#include "raylib.h"

void DrawEndRoundBox(const char mainText[], const char secondaryText[],
                     int mainFontSize, int secondaryFontSize,
                     Color mainTextColor) {
  int mainTextWidth = MeasureText(mainText, mainFontSize);
  int secondaryTextWidth = MeasureText(secondaryText, secondaryFontSize);
  DrawRectangle(WINDOW_WIDTH / 2 - mainTextWidth / 2 - 20,
                WINDOW_HEIGHT / 2 - mainFontSize / 2 - 20, mainTextWidth + 40,
                mainFontSize + secondaryFontSize + 40 + 10, BLACK);
  DrawText(mainText, WINDOW_WIDTH / 2 - mainTextWidth / 2,
           WINDOW_HEIGHT / 2 - mainFontSize / 2, mainFontSize, mainTextColor);
  DrawText(secondaryText, WINDOW_WIDTH / 2 - secondaryTextWidth / 2,
           WINDOW_HEIGHT / 2 - secondaryFontSize / 2 + mainFontSize / 2 + 10,
           secondaryFontSize, WHITE);
}
