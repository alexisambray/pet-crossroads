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
void displayPriceList(int turnipPrice,
                      int* week,
                      const int* sundayTurnipPrice,
                      const int* generateSundayTurnipPrice,
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

void displayPriceList(int turnipPrice,
                      int* week,
                      const int* sundayTurnipPrice,
                      const int* generateSundayTurnipPrice,
                      DayOfWeek dayOfWeek) {
  turnipPrice = *sundayTurnipPrice;
  week = 1;

  for (dayOfWeek = 1; dayOfWeek < 8; dayOfWeek++) {
    printf("\nWeek #%d Day %d\n", week, dayOfWeek);
    printf("Current Turnip Stack(s): \n");  // HOW MUCH STACKS PLAYER BUYS
    printf("Sunday Price: %d\n", turnipPrice);
    generateSundayTurnipPrice =
        (rand() % (SUNDAY_TURNIP_MAX_PRICE - SUNDAY_TURNIP_MIN_PRICE + 1) +
         SUNDAY_TURNIP_MIN_PRICE);
    printf("Store Price: %d\n",
           generateSundayTurnipPrice);  // RANDOM STORE PRICE
  }
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
  displayTurnipPrice(turnipPrice);
  displayResources(bells, turnips);
}

void game(void) {
  int bells, turnips, turnipPrice, sundayTurnipPrice, week;
  WeeklyPriceTrend weeklyPriceTrend;
  DayOfWeek dayOfWeek;

  initializeGame(&bells, &turnips, &turnipPrice, &sundayTurnipPrice, &week,
                 &weeklyPriceTrend, &dayOfWeek);
  displayStatus(dayOfWeek, week, bells, turnips, turnipPrice);
  displayPriceList(&turnipPrice, &week, &sundayTurnipPrice,
                   &generateSundayTurnipPrice, &dayOfWeek);
}
