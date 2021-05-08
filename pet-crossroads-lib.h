#include <stdio.h>
#include <stdlib.h>

#include "constants.h"

void displayWelcomeScreen(void) {
  puts(
      "***** Welcome to Pet Crossroads: Making Money off the Stalk Market "
      "*****\n");

  // TODO: Add flavo text, or maybe a paragraph describing the game
  puts("Press ENTER to start.");
  getchar();
  system("clear");
}

void displayDay(void) {
  printf("***** Day 1 (Sunday), Week 1 of %d *****\n", MAX_WEEK);
}

void displayResources(void) {
  puts("5000 Bell(s)\t\t0 Turnip(s)\n");
}

void displayCurrentTurnipPrice(void) {
  puts("Current Turnip Price (per Turnip): 100 bells");
}

void displayStatus(void) {
  displayDay();
  displayResources();
  displayCurrentTurnipPrice();
}

void game(void) {
  displayStatus();
}
