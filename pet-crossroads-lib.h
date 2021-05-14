#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constants.h"
#include "types.h"

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

int generateRandInt(const int lower, const int upper) {
  return (rand() % (upper - lower + 1)) + lower;
}

int generateSundayTurnipPrice() {
  return generateRandInt(SUNDAY_TURNIP_MIN_PRICE, SUNDAY_TURNIP_MAX_PRICE);
}

WeeklyPriceTrend generateRandTrend(void) {
  return (WeeklyPriceTrend)generateRandInt((int)AWESOME, (int)BAD);
}

void initializeGame(int* bells,
                    int* turnips,
                    int* turnipPrice,
                    int* sundayTurnipPrice,
                    int* week,
                    WeeklyPriceTrend* weeklyPriceTrend,
                    DayOfWeek* dayOfWeek) {
  srand(time(NULL));
  *bells = STARTING_NUM_BELLS;
  *turnips = STARTING_NUM_TURNIPS;
  *sundayTurnipPrice = generateSundayTurnipPrice();
  *turnipPrice = *sundayTurnipPrice;
  *week = 1;
  *weeklyPriceTrend = generateRandTrend();
  *dayOfWeek = SUNDAY;
}

void displayTurnipPrice(int turnipPrice) {
  printf("Current Turnip Price (per Turnip): %d bells\n", turnipPrice);
}

void displayWelcomeScreen(void) {
  system("clear");
  puts(
      "***** Welcome to Pet Crossroads: Making Money off the Stalk Market "
      "*****\n");

  // TODO: Add flavo text, or maybe a paragraph describing the game
  puts("Press ENTER to start.");
  getchar();
  system("clear");
}

void displayDay(const DayOfWeek dayOfWeek, const int week) {
  printf("***** Day %d (Sunday), Week %d of %d *****\n", dayOfWeek, week,
         MAX_WEEK);
}

void displayResources(const int bells, const int turnips) {
  printf("%d Bell(s)\t\t%d Turnip(s)\n\n", bells, turnips);
}

void displayStatus(const DayOfWeek dayOfWeek,
                   const int week,
                   const int bells,
                   const int turnips,
                   const int turnipPrice) {
  displayDay(dayOfWeek, week);
  displayResources(bells, turnips);
  displayTurnipPrice(turnipPrice);
}

void game(void) {
  int bells, turnips, turnipPrice, sundayTurnipPrice, week;
  WeeklyPriceTrend weeklyPriceTrend;
  DayOfWeek dayOfWeek;

  initializeGame(&bells, &turnips, &turnipPrice, &sundayTurnipPrice, &week,
                 &weeklyPriceTrend, &dayOfWeek);
  displayStatus(dayOfWeek, week, bells, turnips, turnipPrice);
}
