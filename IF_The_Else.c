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
	Complete date: 08-27-2024
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

	//Initial setup
	char name[32];
	int current_location = CELL;
	int coins = 0;
	bool actions[MAX_ACTIONS];

	
	//Array of pointers to room functions
	bool (*locations[MAX_LOCATIONS])(char*, int*, bool*, int*);
	setupLocations(locations);
	
	//Load save file, or create new save
	loadGameOrNew(name, &current_location, actions, &coins);
	
	//Game loop
	bool quitGame = 0;
	while(!quitGame) {
		if (!(*locations[current_location])(name, &current_location, actions, &coins)) {
			quitGame = 1;
		}	
	}
	
	return 0;
}
