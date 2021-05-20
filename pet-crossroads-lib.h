#include <ctype.h>
#include <stdbool.h>
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
void displayPriceList(int* turnipPrice,
                      int* turnips,
                      int* week,
                      int* sundayTurnipPrice,
                      int* generateSundayTurnipPrice,
                      DayOfWeek dayOfWeek);
bool chooseBuyOrNot(int* turnipPrice,
                    int* turnips,
                    int* week,
                    int* sundayTurnipPrice,
                    int* generateSundayTurnipPrice,
                    DayOfWeek dayOfWeek);
void displayTurnipPrice(int turnipPrice);
void displayWelcomeScreen(void);
void displayDay(const DayOfWeek dayOfWeek, const int week);
void displayResources(const int bells, const int turnips);
void displayStatus(const DayOfWeek dayOfWeek,
                   const int week,
                   const int bells,
                   const int turnips,
                   const int turnipPrice);
void game(void);

// Each week buying price would randomly be different from 90 - 110 bells
int generateRandInt(const int lower, const int upper) {
  return (rand() % (upper - lower + 1)) + lower;
}

int generateSundayTurnipPrice() {
  return generateRandInt(SUNDAY_TURNIP_MIN_PRICE, SUNDAY_TURNIP_MAX_PRICE);
}

WeeklyPriceTrend generateRandTrend(void) {
  return (WeeklyPriceTrend)generateRandInt((int)AWESOME, (int)BAD);
}

void displayTurnipPrice(int turnipPrice) {
  printf("Daisy Mae is Selling Turnips for %d bells\n", turnipPrice);
}

void displayPriceList(int* turnipPrice,
                      int* turnips,
                      int* week,
                      int* sundayTurnipPrice,
                      int* generateSundayTurnipPrice,
                      DayOfWeek dayOfWeek) {
  int i;
  turnipPrice = *sundayTurnipPrice;
  turnips = STARTING_NUM_TURNIPS;
  int weekNum = *week;

  for (dayOfWeek = MONDAY; dayOfWeek <= SATURDAY; dayOfWeek++) {
    printf("\nWeek %d Day %d\n", weekNum, dayOfWeek);
    printf("Current Turnip Stack(s): %d\n",
           turnips);  // HOW MUCH STACKS PLAYER BUYS
    printf("Sunday Price: %d\n", turnipPrice);
    generateSundayTurnipPrice =
        (rand() % (SUNDAY_TURNIP_MAX_PRICE - SUNDAY_TURNIP_MIN_PRICE + 1) +
         SUNDAY_TURNIP_MIN_PRICE);
    generateRandInt(SUNDAY_TURNIP_MIN_PRICE, SUNDAY_TURNIP_MAX_PRICE);
    printf("Store Price: %d\n",
           generateSundayTurnipPrice);  // RANDOM STORE PRICE
  }
  printf("\n%d Turnips have gone bad!\n", turnips);
}

bool chooseBuyOrNot(int* turnipPrice,
                    int* turnips,
                    int* week,
                    int* sundayTurnipPrice,
                    int* generateSundayTurnipPrice,
                    DayOfWeek dayOfWeek) {
  char choice;

  turnipPrice = sundayTurnipPrice;

  printf("Would you like to buy Turnips? [Y/N] ");
  scanf(" %c", &choice);
  getchar();

  if (toupper(choice) == 'Y') {
    // ASK USER HOW MANY TO BUY
  } else {
    displayPriceList(&turnipPrice, &turnips, &week, &sundayTurnipPrice,
                     &generateSundayTurnipPrice, &dayOfWeek);
  }
}

// int turnipsToBuy() {
//
// }

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
  printf("\n***** Day %d (Sunday), Week %d of %d *****\n", dayOfWeek, week,
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
  displayTurnipPrice(turnipPrice);
  displayResources(bells, turnips);
}

void game(void) {
  int bells, turnips, turnipPrice, sundayTurnipPrice, week;
  WeeklyPriceTrend weeklyPriceTrend;
  DayOfWeek dayOfWeek;

  initializeGame(&bells, &turnips, &turnipPrice, &sundayTurnipPrice, &week,
                 &weeklyPriceTrend, &dayOfWeek);

  for (week = 1; week <= MAX_WEEK; week++) {
    displayStatus(dayOfWeek, week, bells, turnips, turnipPrice);
    turnipPrice =
        generateRandInt(SUNDAY_TURNIP_MIN_PRICE, SUNDAY_TURNIP_MAX_PRICE);
    chooseBuyOrNot(turnipPrice, turnips, week, sundayTurnipPrice,
                   generateSundayTurnipPrice, dayOfWeek);
  }
}
