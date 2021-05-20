#include "pet-crossroads-lib.h"

int generateRandInt(const int lower, const int upper);
int generateSundayTurnipPrice(void);
WeeklyPriceTrend generateRandTrend(void);
void initializeGame(int* bells,
                    int* turnips,
                    int* turnipPrice,
                    int* sundayTurnipPrice,
                    int* week,
                    WeeklyPriceTrend* weeklyPriceTrend,
                    DayOfWeek* dayOfWeek);
void displayTurnipPrice(int turnipPrice);
void displayWelcomeScreen(void);
void displayDay(const DayOfWeek dayOfWeek, const int week);
void displayResources(const int bells, const int turnips);
void game(void);

int main() {
  displayWelcomeScreen();
  game();

  return 0;
}
