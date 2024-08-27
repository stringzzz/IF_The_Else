/*
    IF: The Else (Main) Interactive fiction game written in C
    Copyright (C) 2024 stringzzz, Ghostwarez Co.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/*
	IF: The Else (Interactive Fiction Game)
	Full version (Main)
	Start date: 08-02-2024
	Complete date: 08-26-2024
	By stringzzz, Ghostwarez Co.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "ifte_consts_and_functions.h"
#include "ifte_room_functions5.h"

int main() {
	srand(time(NULL));

	//Initial setup for new game
	int current_location = CELL;
	int coins = 0;
	bool actions[MAX_ACTIONS];
	for (int i = 0; i < MAX_ACTIONS; i++) {
		actions[i] = 0;
	}
	actions[RED_ORB_LEFT] = 1;
	actions[BLUE_ORB_MIDDLE] = 1;
	actions[GREEN_ORB_RIGHT] = 1;
	actions[LEFT_PEDESTAL_SET] = 1;
	actions[MIDDLE_PEDESTAL_SET] = 1;
	actions[RIGHT_PEDESTAL_SET] = 1;
	actions[PORTRAIT1_ACTIVE] = 1;
	actions[TEMPLE_ENTRANCE_CENTER] = 1;
	actions[TEMPLE_PUZZLE1_BLOCK4] = 1;
	actions[TEMPLE_PUZZLE2_LEFT4] = 1;
	actions[TEMPLE_PUZZLE2_MIDDLE2] = 1;
	actions[TEMPLE_PUZZLE2_RIGHT3] = 1;
	
	//Array of pointers to room functions
	bool (*locations[MAX_LOCATIONS])(char*, int*, bool*, int*);
	setupLocations(locations);
	
	char name[32];
	printf("Enter thy name: ");
	scanf("%[^\n]%*c", name);
	int option1;
	printf("Enter 0 to load game, or any other number to start a new game: ");
	scanf(" %i", &option1);
	//Load save file
	if (option1 == 0) {
		loadGame(name, &current_location, actions, &coins);
		
		//Have to reset final puzzle everytime file is loaded
		//Else it would have been a nightmare of constants for all of them
		actions[ELSE_GET_RED_ORB] = 0;
		actions[ELSE_GET_ORANGE_ORB] = 0;
		actions[ELSE_GET_YELLOW_ORB] = 0;
		actions[ELSE_GET_GREEN_ORB] = 0;
		actions[ELSE_GET_BLUE_ORB] = 0;
		actions[ELSE_GET_INDIGO_ORB] = 0;
		actions[ELSE_GET_VIOLET_ORB] = 0;
		
		printf("Game save for %s successfully loaded.\n\n", name);
	}
	
	
	bool quitGame = 0;
	while(!quitGame) {
		if (!(*locations[current_location])(name, &current_location, actions, &coins)) {
			quitGame = 1;
		}	
	}
	
	return 0;
}
