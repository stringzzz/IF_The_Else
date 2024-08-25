/*
    IF: The Else (ifte_room_functions4.h Header File) Interactive fiction game written in C
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
	Full version (Room Functions Header)
	Start date: 08-02-2024
	Complete date: 08-24-2024
	By stringzzz, Ghostwarez Co.
*/

#ifndef ifte_room_functions

void printInvalid() {
	char invalid_messages[10][128] = {
		"You cannot do that here!",
		"Not happening here...",
		"This is not possible here.",
		"That action cannot be done here!",
		"Sorry, won't work here.",
		"Doesn't work, at least not here.",
		"That won't work.",
		"You try, but it doesn't do anything here.",
		"Not possible here.",
		"It might work, but not right here."
	};
	printf("%s\n\n", invalid_messages[rand() % 10]);
}

bool room_CELL(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[INTRO]) {	
		printf("You wake up to find yourself in a murky cell, confused as to how you got there.\n\n");
		actions[INTRO] = 1;
	}
	printf("You see a CHAMBER POT, and a raggedy BLANKET, NORTH is the cell DOOR.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}
	

	if (strcmp(chosen_action, "check blanket") == 0 || strcmp(chosen_action, "examine blanket") == 0 || strcmp(chosen_action, "look at blanket") == 0 || strcmp(chosen_action, "investigate blanket") == 0 || strcmp(chosen_action, "view blanket") == 0) {
		if (!actions[GET_KEY]) {
			printf("You lift the blanket to find a key, which you grab!\n\n");
			actions[GET_KEY] = 1;
		} else {
			printf("There is nothing under the blanket now that you have the key.\n\n");
		}
	} else if (strcmp(chosen_action, "use chamber pot") == 0 || strcmp(chosen_action, "utilize chamber pot") == 0 || strcmp(chosen_action, "employ chamber pot") == 0 || strcmp(chosen_action, "wield chamber pot") == 0 || strcmp(chosen_action, "try chamber pot") == 0 || strcmp(chosen_action, "attempt chamber pot") == 0) {
		printf("You relieve yourself in the chamber pot, much better!\n\n");
	} else if (strcmp(chosen_action, "get chamber pot") == 0 || strcmp(chosen_action, "pick up chamber pot") == 0 || strcmp(chosen_action, "grab chamber pot") == 0 || strcmp(chosen_action, "take chamber pot") == 0 || strcmp(chosen_action, "acquire chamber pot") == 0 || strcmp(chosen_action, "obtain chamber pot") == 0) {
		printf("You think about getting the chamber pot, until you are hit with a terribly foul smell.\n\n");
	} else if (strcmp(chosen_action, "get blanket") == 0 || strcmp(chosen_action, "pick up blanket") == 0 || strcmp(chosen_action, "grab blanket") == 0 || strcmp(chosen_action, "take blanket") == 0 || strcmp(chosen_action, "acquire blanket") == 0 || strcmp(chosen_action, "obtain blanket") == 0) {
		printf("You don't need the blanket, the cell isn't cold.\n\n");
	}else if (strcmp(chosen_action, "unlock door") == 0) {
		if (actions[GET_KEY]) {
			printf("You used the key to unlock the door, and it worked!\n\n");
			actions[UNLOCK_CELL] = 1;
		} else {
			printf("You have no key...\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (actions[UNLOCK_CELL]) {
			printf("You exit the cell.\n\n");
			*current_location = OUTSIDE_CELL;
		} else {
			printf("You shake the cell door, but it is locked tight!\n\n");
		}
	} else {
		printInvalid();
	}

	return 1;
}

bool room_OUTSIDE_CELL(char name[], int *current_location, bool actions[], int *coins) {
	printf("Outside of the cell you see a CABINET, there is a lit CANDLE attached to the wall bathing the room in a dim light, SOUTH is the cell, EAST is a corridor.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}
	
	if (strcmp(chosen_action, "open cabinet") == 0) {
		if (!actions[BATS_OUT]) {
			printf("You open the cabinet and a bunch of bats fly out! You quickly close it.\n\n");
			actions[BATS_OUT] = 1;
		} else {
			if (!actions[MICE_OUT]) {
				printf("You open the cabinet and a swarm of mice come pouring out! You quickly close it.\n\n");
				actions[MICE_OUT] = 1;
			} else {
				if (!actions[GET_TORCH]) {
					printf("You open the cabinet and find a torch, which you grab, then close the cabinet.\n\n");
					actions[GET_TORCH] = 1;
				} else {
					printf("You open the cabinet and find nothing, so you close it.\n\n");
				}
			}
		}
	} else if (strcmp(chosen_action, "use candle") == 0 || strcmp(chosen_action, "utilize candle") == 0 || strcmp(chosen_action, "employ candle") == 0 || strcmp(chosen_action, "wield candle") == 0 || strcmp(chosen_action, "try candle") == 0 || strcmp(chosen_action, "attempt candle") == 0) {
		if (actions[GET_TORCH] && !actions[LIT_TORCH]) {
			printf("You light the torch with the candle.\n\n");
			actions[LIT_TORCH] = 1;
		} else {
			if (!actions[LIT_TORCH]) {
				printf("You have nothing to use the candle with.\n\n");
			} else {
				printf("The torch is already lit.\n\n");
			}
		}
	} else if (strcmp(chosen_action, "get candle") == 0 || strcmp(chosen_action, "pick up candle") == 0 || strcmp(chosen_action, "grab candle") == 0 || strcmp(chosen_action, "take candle") == 0 || strcmp(chosen_action, "acquire candle") == 0 || strcmp(chosen_action, "obtain candle") == 0) {
		printf("The candle is firmly attached to the wall.\n\n");
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go back into the cell.\n\n");
		*current_location = CELL;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		if (actions[LIT_TORCH]) {
			printf("Your torch now lights the way through the corridor, so you walk through it.\n\n");
			*current_location = TREASURE_ROOM;
		} else {
			printf("The corridor is too dark to see anything, you dare not enter it.\n\n");
		}
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TREASURE_ROOM(char name[], int *current_location, bool actions[], int *coins) {
	printf("You make it through the corridor, and come across a pile of treasure with a large CHEST sitting on top! WEST is back to the room outside the cell.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}
	
	if (strcmp(chosen_action, "open chest") == 0) {
		printf("The rusty hinges of the chest creak as you slowly open it. You peer inside to find... a dark void?\nYou are consumed by the darkness as it pulls you in, transporting you elsewhere...\n\n");
		*current_location = FOREST1;	
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go back to outside the cell.\n\n");
		*current_location = OUTSIDE_CELL;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_FOREST1(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[FOREST_INTRO]) {	
		printf("You fall into the darkness, falling...\nYou land with surprising gentleness, and the darkness mysteriously drifts away, leaving you in a forest.\n\n");
		actions[FOREST_INTRO] = 1;
	}
	printf("You see a BUSH, and some VINES hanging off of a tree. NORTH, EAST, and SOUTH have clearings between the dense trees.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}
	
	if (strcmp(chosen_action, "check bush") == 0 || strcmp(chosen_action, "examine bush") == 0 || strcmp(chosen_action, "look at bush") == 0 || strcmp(chosen_action, "investigate bush") == 0 || strcmp(chosen_action, "view bush") == 0) {
		if (!actions[BUSH1]) {
			printf("You check the bush and some birds fly out of it.\n\n");
			actions[BUSH1] = 1;
		} else {
			printf("There's nothing in the bush.\n\n");
		}
	} else if (strcmp(chosen_action, "pull vines") == 0 || strcmp(chosen_action, "tug vines") == 0 || strcmp(chosen_action, "yank vines") == 0) {
		printf("You pull on the longest vine, only to find out it's a snake!\nAfter biting you, you drift off into unconsciousness as the snake devours you.\nGAME OVER\n\n");
		return 0;
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go north through the clearing.\n\n");
		*current_location = FOREST2;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You head south through the openings of the trees.\n\n");
		*current_location = FOREST3;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You travel east into another open area.\n\n");
		*current_location = FOREST5;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_FOREST2(char name[], int *current_location, bool actions[], int *coins) {
	printf("You enter the clearing in the north.\n");
	if (!actions[GET_LONG_STICK]) {
		printf("You see a LONG STICK on the ground.\n");
	}
	if (!actions[GET_PURPLE_MUSHROOM]) {
		printf("There is a deeply PURPLE MUSHROOM that stands out.\n");
	}
	printf("The only exit is SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}
	
	if (strcmp(chosen_action, "get long stick") == 0 || strcmp(chosen_action, "pick up long stick") == 0 || strcmp(chosen_action, "grab long stick") == 0 || strcmp(chosen_action, "take long stick") == 0 || strcmp(chosen_action, "acquire long stick") == 0 || strcmp(chosen_action, "obtain long stick") == 0) {
		if (!actions[GET_LONG_STICK]) {
			printf("You pick up the long stick.\n\n");
			actions[GET_LONG_STICK] = 1;
		} else {
			printf("You already have the long stick!\n\n");
		}
	} else if (strcmp(chosen_action, "get purple mushroom") == 0 || strcmp(chosen_action, "pick up purple mushroom") == 0 || strcmp(chosen_action, "grab purple mushroom") == 0 || strcmp(chosen_action, "take purple mushroom") == 0 || strcmp(chosen_action, "acquire purple mushroom") == 0 || strcmp(chosen_action, "obtain purple mushroom") == 0) {
		if (!actions[GET_PURPLE_MUSHROOM]) {
			printf("You pick up the purple mushroom, it has a distinctly toxic odor.\n\n");
			actions[GET_PURPLE_MUSHROOM] = 1;
		} else {
			printf("You've already obtained the purple mushroom!\n\n");
		}

	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You head south back to the first clearing.\n\n");
		*current_location = FOREST1;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_FOREST3(char name[], int *current_location, bool actions[], int *coins) {
	printf("You enter the clearing south of your origin.\n");
	if (!actions[GET_STICK]) {
		printf("You see a STICK among the grass.\n");
	}
	if (!actions[GET_RED_MUSHROOM]) {
		printf("There is a crimson RED MUSHROOM growing from the ground.\n");
	}
	printf("The only exits are NORTH and EAST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}
	
	if (strcmp(chosen_action, "get stick") == 0 || strcmp(chosen_action, "pick up stick") == 0 || strcmp(chosen_action, "grab stick") == 0 || strcmp(chosen_action, "take stick") == 0 || strcmp(chosen_action, "acquire stick") == 0 || strcmp(chosen_action, "obtain stick") == 0) {
		if (!actions[GET_STICK]) {
			printf("You pick up the stick from the grass.\n\n");
			actions[GET_STICK] = 1;
		} else {
			printf("You already got the stick!\n\n");
		}
	} else if (strcmp(chosen_action, "get red mushroom") == 0 || strcmp(chosen_action, "pick up red mushroom") == 0 || strcmp(chosen_action, "grab red mushroom") == 0 || strcmp(chosen_action, "take red mushroom") == 0 || strcmp(chosen_action, "acquire red mushroom") == 0 || strcmp(chosen_action, "obtain red mushroom") == 0) {
		if (!actions[GET_RED_MUSHROOM]) {
			printf("You pocket the red mushroom, it has quite the savory scent to it.\n\n");
			actions[GET_RED_MUSHROOM] = 1;
		} else {
			printf("You have the red mushroom already!\n\n");
		}

	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You head north back to the first clearing.\n\n");
		*current_location = FOREST1;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You step through the trees to the east.\n\n");
		*current_location = FOREST4;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_FOREST4(char name[], int *current_location, bool actions[], int *coins) {
	printf("You enter the clearing diagonal to your origin.\nThe only exits are NORTH and WEST.\nIn the center is a pit of quicksand!\n\n");
	if (!actions[GET_AMULET]) {
		printf("You see an emerald AMULET floating on the quicksand.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "get amulet") == 0 || strcmp(chosen_action, "pick up amulet") == 0 || strcmp(chosen_action, "grab amulet") == 0 || strcmp(chosen_action, "take amulet") == 0 || strcmp(chosen_action, "acquire amulet") == 0 || strcmp(chosen_action, "obtain amulet") == 0) {
		if (!actions[GET_AMULET]) {
			printf("You want to get the amulet, but you can't reach.\n\n");
		} else {
			printf("You have the amulet already!\n\n");
		}
	} else if (strcmp(chosen_action, "use stick") == 0 || strcmp(chosen_action, "utilize stick") == 0 || strcmp(chosen_action, "employ stick") == 0 || strcmp(chosen_action, "wield stick") == 0 || strcmp(chosen_action, "try stick") == 0 || strcmp(chosen_action, "attempt stick") == 0) {
		if (actions[GET_STICK]) {
			printf("You reach out with the stick, it's a stretch.\nYou accidentally stumble forward while leaning and fall into the quicksand.\nYou hear laughter as you sink into the quicksand...\nGAME OVER\n\n");
			return 0;
		} else {
			printf("You don't have a stick!\n\n");
		}

	} else if (strcmp(chosen_action, "use long stick") == 0 || strcmp(chosen_action, "utilize long stick") == 0 || strcmp(chosen_action, "employ long stick") == 0 || strcmp(chosen_action, "wield long stick") == 0 || strcmp(chosen_action, "try long stick") == 0 || strcmp(chosen_action, "attempt long stick") == 0) {
		if (actions[GET_LONG_STICK] && !actions[GET_AMULET]) {
			printf("You try to get the amulet with the long stick, it looks like you can reach.\nYou got the amulet!\nThe long stick fell into the quicksand.\n\n");
			actions[GET_AMULET] = 1;
		} else if (actions[GET_LONG_STICK] && actions[GET_AMULET]) {
			printf("You already lost the long stick!\n\n");
		} else {
			printf("You don't have a long stick! (Laughter is heard amongst the trees)\n\n");
		}	

	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You head north.\n\n");
		*current_location = FOREST5;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You climb around the trees headed west.\n\n");
		*current_location = FOREST3;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_FOREST5(char name[], int *current_location, bool actions[], int *coins) {
	printf("You enter the clearing east of your origin.\nYou see a statue with emerald eyes wearing a ridiculous smile.\nThere is a BUSH in the corner.\nThe paths out are WEST, SOUTH.\n\n");
	if (actions[USE_AMULET]) {
		printf("The eyes of the statue glow green, with an opening through the trees now in the EAST.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use amulet") == 0 || strcmp(chosen_action, "utilize amulet") == 0 || strcmp(chosen_action, "employ amulet") == 0 || strcmp(chosen_action, "wield amulet") == 0 || strcmp(chosen_action, "try amulet") == 0 || strcmp(chosen_action, "attempt amulet") == 0) {
		if (actions[GET_AMULET] && !actions[USE_AMULET]) {
			printf("You place the amulet around the neck of the statue.\nIt's eyes begin glowing green, and suddenly the trees to the EAST move apart, creating an opening!\n\n");
			actions[USE_AMULET] = 1;
		} else if (actions[GET_AMULET] && actions[USE_AMULET]) {
			printf("The amulet is already on the statue!\n\n");
		} else {
			printf("You don't have anything like that!\n\n");
		}	

	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head west back to the first clearing.\n\n");
		*current_location = FOREST1;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You head southward.\n\n");
		*current_location = FOREST4;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		if (actions[USE_AMULET]) {
			printf("You step through the trees to the east.\n\n");
			*current_location = FOREST6;
		} else {
			printf("Trees are blocking your path to the east...\n\n");
		}
	} else if (strcmp(chosen_action, "check bush") == 0 || strcmp(chosen_action, "examine bush") == 0 || strcmp(chosen_action, "look at bush") == 0 || strcmp(chosen_action, "investigate bush") == 0 || strcmp(chosen_action, "view bush") == 0) {
		if (!actions[BUSH2]) {
			printf("You check the bush and a giant beetle crawls out from it, going up a tree.\n\n");
			actions[BUSH2] = 1;
		} else {
			printf("There's nothing in this bush.\n\n");
		}
	} else {
		printInvalid();
	}

	return 1;
}

bool room_FOREST6(char name[], int *current_location, bool actions[], int *coins) {
	printf("You enter another clearing.\nThe paths out are WEST and EAST.\n\n");
	if (!actions[FED_CREATURE]) {
		printf("A strange creature resembling a giant squirrel is staring at you.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "give red mushroom") == 0 || strcmp(chosen_action, "present red mushroom") == 0 || strcmp(chosen_action, "provide red mushroom") == 0) {
		if (actions[GET_RED_MUSHROOM] && !actions[FED_CREATURE]) {
			printf("You hand the red mushroom to the creature.\nIt happily eats it, then scurries away.\n\n");
			actions[FED_CREATURE] = 1;
		} else if (actions[GET_RED_MUSHROOM] && actions[FED_CREATURE]) {
			printf("The creature already ate the mushroom and left.\n\n");
		} else {
			printf("You don't have that!\n\n");
		}	

	} else if (strcmp(chosen_action, "give purple mushroom") == 0 || strcmp(chosen_action, "present purple mushroom") == 0 || strcmp(chosen_action, "provide purple mushroom") == 0) {
		if (actions[GET_PURPLE_MUSHROOM] && !actions[FED_CREATURE]) {
			printf("You hand the purple mushroom to the creature.\nIt happily eats it, then starts shaking.\nIt turns into a massive behemoth of a creature, charging at you!\nIt tears you to shreds as if you were paper!\nGAME OVER\n\n");
			return 0;
		} else if (actions[GET_PURPLE_MUSHROOM] && actions[FED_CREATURE]) {
			printf("The creature is already gone...\n\n");
		} else {
			printf("You don't have that!\n\n");
		}	

	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west closer to your origin.\n\n");
		*current_location = FOREST5;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		if (actions[FED_CREATURE]) {
			printf("You step through the trees to the east, leaving the forest.\n\n");
			*current_location = OUTSIDE_HUT;
		} else {
			printf("The creature blocks your path, and points at its mouth.\nIts eyes look desperate, and you notice how skinny it appears.\n\n");
		}
	} else {
		printInvalid();
	}

	return 1;
}

bool room_OUTSIDE_HUT(char name[], int *current_location, bool actions[], int *coins) {
	printf("Outside the forest to the WEST,\nyou see a small hut to the EAST with smoke billowing out from the chimney,\nsurrounded on all sides by a steep cliff.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}
	
	if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west back into the forest.\n\n");
		*current_location = FOREST6;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go east into the hut.\n\n");
		*current_location = WITCH_HUT;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_WITCH_HUT(char name[], int *current_location, bool actions[], int *coins) {
	printf("In the hut you see a WITCH stirring a bubbling cauldron, next to a black CAT. The exit from the hut is WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "talk to witch") == 0 || strcmp(chosen_action, "speak to witch") == 0 || strcmp(chosen_action, "chat with witch") == 0 || strcmp(chosen_action, "talk with witch") == 0 || strcmp(chosen_action, "converse with witch") == 0) {
		if (!actions[GIVE_PURPLE_MUSHROOM]) {
			printf("WITCH: 'I need something pungent...'\n\n");
		}
		if (!actions[GIVE_STICK]) {
			printf("WITCH: 'I could use something brown and sticky...'\n\n");
		}
		if (actions[GIVE_PURPLE_MUSHROOM] && actions[GIVE_STICK]) {
			printf("WITCH: 'I brewed up a PURPLE POTION, would you like to drink it? *cackles*'\n\n");
		}
	} else if (strcmp(chosen_action, "talk to cat") == 0 || strcmp(chosen_action, "speak to cat") == 0 || strcmp(chosen_action, "chat with cat") == 0 || strcmp(chosen_action, "talk with cat") == 0 || strcmp(chosen_action, "converse with cat") == 0) {
		printf("You try talking to the cat, but it just stares back at you.\n\n");
	} else if (strcmp(chosen_action, "give purple mushroom") == 0 || strcmp(chosen_action, "present purple mushroom") == 0 || strcmp(chosen_action, "provide purple mushroom") == 0) {
		if (actions[GET_PURPLE_MUSHROOM] && !actions[GIVE_PURPLE_MUSHROOM]) {
			printf("You hand the witch the purple mushroom, she drops it into the cauldron.\n\n");
			actions[GIVE_PURPLE_MUSHROOM] = 1;
		} else if (actions[GET_PURPLE_MUSHROOM] && actions[GIVE_PURPLE_MUSHROOM]) {
			printf("You already gave the witch the purple mushroom!\n\n");
		} else if (!actions[GET_PURPLE_MUSHROOM]) {
			printf("You don't have a purple mushroom!\n\n");
		}	

	} else if (strcmp(chosen_action, "give stick") == 0 || strcmp(chosen_action, "present stick") == 0 || strcmp(chosen_action, "provide stick") == 0) {
		if (actions[GET_STICK] && !actions[GIVE_STICK]) {
			printf("You give the witch the stick, she tosses it in the cauldron.\n\n");
			actions[GIVE_STICK] = 1;
		} else if (actions[GET_STICK] && actions[GIVE_STICK]) {
			printf("The witch already has the stick!\n\n");
		} else if (!actions[GET_STICK]) {
			printf("You aren't carrying a stick!\n\n");
		}	

	} else if (strcmp(chosen_action, "drink purple potion") == 0 || strcmp(chosen_action, "swallow purple potion") == 0 || strcmp(chosen_action, "gulp down purple potion") == 0 || strcmp(chosen_action, "consume purple potion") == 0 || strcmp(chosen_action, "down purple potion") == 0) {
		if (actions[GIVE_PURPLE_MUSHROOM] && actions[GIVE_STICK]) {
			printf("You drink the purple potion. Suddenly everything around you appears to be growing...\nNo... You are shrinking!\n\n");
			*current_location = SHRUNK_HUT;
		} else {
			printf("The potion isn't ready yet.\n\n");
		}	

	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west outside the hut.\n\n");
		*current_location = OUTSIDE_HUT;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_SHRUNK_HUT(char name[], int *current_location, bool actions[], int *coins) {
	printf("Now tiny, you see a cat to the NORTH, and a mouse hole to the EAST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go north towards the cat.\n\n");
		*current_location = SHRUNK_CAT;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go east into the mouse hole.\n\n");
		*current_location = SHRUNK_MOUSE;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_SHRUNK_CAT(char name[], int *current_location, bool actions[], int *coins) {
	printf("The cat speaks to you: 'Cats have nine lives, but you don't. A wise person saves often...'.\nSOUTH is where you came from.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south back from where you came.\n\n");
		*current_location = SHRUNK_HUT;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_SHRUNK_MOUSE(char name[], int *current_location, bool actions[], int *coins) {
	printf("You see a mouse sitting at a table eating a piece of cheese. WEST is the exit, EAST is the entrance to a hole.\n\n");
	if (!actions[MOUSE_SPOKE]) {
		printf("The mouse spoke: 'The burrow there leads to a labrynth filled with strange magic. You may find yourself going in circles.\nJust remember: Grass burns until it's doused with water...'\n\n");
		actions[MOUSE_SPOKE] = 1;
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You leave the mouse hole.\n\n");
		*current_location = SHRUNK_HUT;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go into the hole at the east, and find yourself falling!\nYou land in a dimly lit room.\n\n");
		*current_location = LAB1;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_LAB1(char name[], int *current_location, bool actions[], int *coins) {
	printf("Looking around, you see three candles hanging from the ceiling.\nThere are doorways NORTH, EAST, WEST, and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}
	
	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go north through a doorway.\n\n");
		*current_location = LAB2;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go east through a doorway.\n\n");
		*current_location = LAB5;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south through a doorway.\n\n");
		*current_location = LAB1;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_LAB2(char name[], int *current_location, bool actions[], int *coins) {
	printf("Looking around, you see four candles hanging from the ceiling.\nThere are doorways NORTH, EAST, WEST, and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go north through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go east through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west through a doorway.\n\n");
		*current_location = LAB3;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south through a doorway.\n\n");
		*current_location = LAB1;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_LAB3(char name[], int *current_location, bool actions[], int *coins) {
	printf("Looking around, you see five candles hanging from the ceiling.\nThere are doorways NORTH, EAST, WEST, and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go north through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go east through a doorway.\n\n");
		*current_location = LAB2;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south through a doorway.\n\n");
		*current_location = LAB4;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_LAB4(char name[], int *current_location, bool actions[], int *coins) {
	printf("Looking around, you see six candles hanging from the ceiling.\nThere are doorways NORTH, EAST, WEST, and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go north through a doorway.\n\n");
		*current_location = LAB3;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go east through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west through a doorway.\n\n");
		*current_location = LAB8;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south through a doorway.\n\n");
		*current_location = LAB1;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_LAB5(char name[], int *current_location, bool actions[], int *coins) {
	printf("Looking around, you see four candles hanging from the ceiling.\nThere are doorways NORTH, EAST, WEST, and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}
	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go north through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go east through a doorway.\n\n");
		*current_location = LAB6;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south through a doorway.\n\n");
		*current_location = LAB1;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_LAB6(char name[], int *current_location, bool actions[], int *coins) {
	printf("Looking around, you see five candles hanging from the ceiling.\nThere are doorways NORTH, EAST, WEST, and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go north through a doorway.\n\n");
		*current_location = LAB7;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go east through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west through a doorway.\n\n");
		*current_location = LAB5;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south through a doorway.\n\n");
		*current_location = LAB1;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_LAB7(char name[], int *current_location, bool actions[], int *coins) {
	printf("Looking around, you see six candles hanging from the ceiling.\nThere are three pedestals in the center of the room, and a LEVER on one of the walls.\nThere are doorways NORTH, EAST, WEST, and SOUTH.\n\n");
	if (!actions[LEFT_PEDESTAL_SET]) {
		printf("The pedestal on the LEFT is empty.\n");
	} else {
		if (actions[RED_ORB_LEFT]) {
			printf("The RED ORB is on the LEFT pedestal.\n");
		} else if (actions[BLUE_ORB_LEFT]) {
			printf("The BLUE ORB is on the LEFT pedestal.\n");
		} else if (actions[GREEN_ORB_LEFT]) {
			printf("The GREEN ORB is on the LEFT pedestal.\n");
		}
	}
	if (!actions[MIDDLE_PEDESTAL_SET]) {
		printf("The pedestal on the MIDDLE is empty.\n");
	} else {
		if (actions[RED_ORB_MIDDLE]) {
			printf("The RED ORB is on the MIDDLE pedestal.\n");
		} else if (actions[BLUE_ORB_MIDDLE]) {
			printf("The BLUE ORB is on the MIDDLE pedestal.\n");
		} else if (actions[GREEN_ORB_MIDDLE]) {
			printf("The GREEN ORB is on the MIDDLE pedestal.\n");
		}
	}
	if (!actions[RIGHT_PEDESTAL_SET]) {
		printf("The pedestal on the RIGHT is empty.\n");
	} else {
		if (actions[RED_ORB_RIGHT]) {
			printf("The RED ORB is on the RIGHT pedestal.\n");
		} else if (actions[BLUE_ORB_RIGHT]) {
			printf("The BLUE ORB is on the RIGHT pedestal.\n");
		} else if (actions[GREEN_ORB_RIGHT]) {
			printf("The GREEN ORB is on the RIGHT pedestal.\n");
		}
	}
	printf("\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}
	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go north through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go east through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south through a doorway.\n\n");
		*current_location = LAB6;
	} else if (strcmp(chosen_action, "set red orb left") == 0 || strcmp(chosen_action, "place red orb left") == 0 || strcmp(chosen_action, "put red orb left") == 0) {
		if (actions[GET_RED_ORB] && !actions[LEFT_PEDESTAL_SET]) {
			printf("You place the red orb on the left pedestal.\n\n");
			actions[GET_RED_ORB] = 0;
			actions[RED_ORB_LEFT] = 1;
			actions[LEFT_PEDESTAL_SET] = 1;
		} else if (actions[GET_RED_ORB] && actions[LEFT_PEDESTAL_SET]) {
			printf("There is already an orb on the left pedestal!\n\n");
		} else if (!actions[GET_RED_ORB]) {
			printf("You don't have the red orb!\n\n");
		}
	} else if (strcmp(chosen_action, "set blue orb left") == 0 || strcmp(chosen_action, "place blue orb left") == 0 || strcmp(chosen_action, "put blue orb left") == 0) {
		if (actions[GET_BLUE_ORB] && !actions[LEFT_PEDESTAL_SET]) {
			printf("You place the blue orb on the left pedestal.\n\n");
			actions[GET_BLUE_ORB] = 0;
			actions[BLUE_ORB_LEFT] = 1;
			actions[LEFT_PEDESTAL_SET] = 1;
		} else if (actions[GET_BLUE_ORB] && actions[LEFT_PEDESTAL_SET]) {
			printf("There is already an orb on the left pedestal!\n\n");
		} else if (!actions[GET_BLUE_ORB]) {
			printf("You don't have the blue orb!\n\n");
		}
	} else if (strcmp(chosen_action, "set green orb left") == 0 || strcmp(chosen_action, "place green orb left") == 0 || strcmp(chosen_action, "put green orb left") == 0) {
		if (actions[GET_GREEN_ORB] && !actions[LEFT_PEDESTAL_SET]) {
			printf("You place the green orb on the left pedestal.\n\n");
			actions[GET_GREEN_ORB] = 0;
			actions[GREEN_ORB_LEFT] = 1;
			actions[LEFT_PEDESTAL_SET] = 1;
		} else if (actions[GET_GREEN_ORB] && actions[LEFT_PEDESTAL_SET]) {
			printf("There is already an orb on the left pedestal!\n\n");
		} else if (!actions[GET_GREEN_ORB]) {
			printf("You don't have the green orb!\n\n");
		}
	} else if (strcmp(chosen_action, "set red orb middle") == 0 || strcmp(chosen_action, "place red orb middle") == 0 || strcmp(chosen_action, "put red orb middle") == 0) {
		if (actions[GET_RED_ORB] && !actions[MIDDLE_PEDESTAL_SET]) {
			printf("You place the red orb on the middle pedestal.\n\n");
			actions[GET_RED_ORB] = 0;
			actions[RED_ORB_MIDDLE] = 1;
			actions[MIDDLE_PEDESTAL_SET] = 1;
		} else if (actions[GET_RED_ORB] && actions[MIDDLE_PEDESTAL_SET]) {
			printf("There is already an orb on the middle pedestal!\n\n");
		} else if (!actions[GET_RED_ORB]) {
			printf("You don't have the red orb!\n\n");
		}
	} else if (strcmp(chosen_action, "set blue orb middle") == 0 || strcmp(chosen_action, "place blue orb middle") == 0 || strcmp(chosen_action, "put blue orb middle") == 0) {
		if (actions[GET_BLUE_ORB] && !actions[MIDDLE_PEDESTAL_SET]) {
			printf("You place the blue orb on the middle pedestal.\n\n");
			actions[GET_BLUE_ORB] = 0;
			actions[BLUE_ORB_MIDDLE] = 1;
			actions[MIDDLE_PEDESTAL_SET] = 1;
		} else if (actions[GET_BLUE_ORB] && actions[MIDDLE_PEDESTAL_SET]) {
			printf("There is already an orb on the middle pedestal!\n\n");
		} else if (!actions[GET_BLUE_ORB]) {
			printf("You don't have the blue orb!\n\n");
		}
	} else if (strcmp(chosen_action, "set green orb middle") == 0 || strcmp(chosen_action, "place green orb middle") == 0 || strcmp(chosen_action, "put green orb middle") == 0) {
		if (actions[GET_GREEN_ORB] && !actions[MIDDLE_PEDESTAL_SET]) {
			printf("You place the green orb on the middle pedestal.\n\n");
			actions[GET_GREEN_ORB] = 0;
			actions[GREEN_ORB_MIDDLE] = 1;
			actions[MIDDLE_PEDESTAL_SET] = 1;
		} else if (actions[GET_GREEN_ORB] && actions[MIDDLE_PEDESTAL_SET]) {
			printf("There is already an orb on the middle pedestal!\n\n");
		} else if (!actions[GET_GREEN_ORB]) {
			printf("You don't have the green orb!\n\n");
		}
	} else if (strcmp(chosen_action, "set red orb right") == 0 || strcmp(chosen_action, "place red orb right") == 0 || strcmp(chosen_action, "put red orb right") == 0) {
		if (actions[GET_RED_ORB] && !actions[RIGHT_PEDESTAL_SET]) {
			printf("You place the red orb on the right pedestal.\n\n");
			actions[GET_RED_ORB] = 0;
			actions[RED_ORB_RIGHT] = 1;
			actions[RIGHT_PEDESTAL_SET] = 1;
		} else if (actions[GET_RED_ORB] && actions[RIGHT_PEDESTAL_SET]) {
			printf("There is already an orb on the right pedestal!\n\n");
		} else if (!actions[GET_RED_ORB]) {
			printf("You don't have the red orb!\n\n");
		}
	} else if (strcmp(chosen_action, "set blue orb right") == 0 || strcmp(chosen_action, "place blue orb right") == 0 || strcmp(chosen_action, "put blue orb right") == 0) {
		if (actions[GET_BLUE_ORB] && !actions[RIGHT_PEDESTAL_SET]) {
			printf("You place the blue orb on the right pedestal.\n\n");
			actions[GET_BLUE_ORB] = 0;
			actions[BLUE_ORB_RIGHT] = 1;
			actions[RIGHT_PEDESTAL_SET] = 1;
		} else if (actions[GET_BLUE_ORB] && actions[RIGHT_PEDESTAL_SET]) {
			printf("There is already an orb on the right pedestal!\n\n");
		} else if (!actions[GET_BLUE_ORB]) {
			printf("You don't have the blue orb!\n\n");
		}
	} else if (strcmp(chosen_action, "set green orb right") == 0 || strcmp(chosen_action, "place green orb right") == 0 || strcmp(chosen_action, "put green orb right") == 0) {
		if (actions[GET_GREEN_ORB] && !actions[RIGHT_PEDESTAL_SET]) {
			printf("You place the green orb on the right pedestal.\n\n");
			actions[GET_GREEN_ORB] = 0;
			actions[GREEN_ORB_RIGHT] = 1;
			actions[RIGHT_PEDESTAL_SET] = 1;
		} else if (actions[GET_GREEN_ORB] && actions[RIGHT_PEDESTAL_SET]) {
			printf("There is already an orb on the right pedestal!\n\n");
		} else if (!actions[GET_GREEN_ORB]) {
			printf("You don't have the green orb!\n\n");
		}
	} else if (strcmp(chosen_action, "get red orb") == 0 || strcmp(chosen_action, "pick up red orb") == 0 || strcmp(chosen_action, "grab red orb") == 0 || strcmp(chosen_action, "take red orb") == 0 || strcmp(chosen_action, "acquire red orb") == 0 || strcmp(chosen_action, "obtain red orb") == 0) {
		if (!actions[GET_RED_ORB] && !actions[ORB_PUZZLE_SOLVED]) {
			printf("You pick up the red orb.\n\n");
			actions[GET_RED_ORB] = 1;
			if (actions[RED_ORB_LEFT]) {
				actions[RED_ORB_LEFT] = 0;
				actions[LEFT_PEDESTAL_SET] = 0;
			} else if (actions[RED_ORB_MIDDLE]) {
				actions[RED_ORB_MIDDLE] = 0;
				actions[MIDDLE_PEDESTAL_SET] = 0;
			} else if (actions[RED_ORB_RIGHT]) {
				actions[RED_ORB_RIGHT] = 0;
				actions[RIGHT_PEDESTAL_SET] = 0;
			}
		} else if (!actions[GET_RED_ORB] && actions[ORB_PUZZLE_SOLVED]) {
			printf("You don't need the red orb anymore.\n\n");
		} else if (actions[GET_RED_ORB]) {
			printf("You already have the red orb!\n\n");
		}
	} else if (strcmp(chosen_action, "get blue orb") == 0 || strcmp(chosen_action, "pick up blue orb") == 0 || strcmp(chosen_action, "grab blue orb") == 0 || strcmp(chosen_action, "take blue orb") == 0 || strcmp(chosen_action, "acquire blue orb") == 0 || strcmp(chosen_action, "obtain blue orb") == 0) {
		if (!actions[GET_BLUE_ORB] && !actions[ORB_PUZZLE_SOLVED]) {
			printf("You pick up the blue orb.\n\n");
			actions[GET_BLUE_ORB] = 1;
			if (actions[BLUE_ORB_LEFT]) {
				actions[BLUE_ORB_LEFT] = 0;
				actions[LEFT_PEDESTAL_SET] = 0;
			} else if (actions[BLUE_ORB_MIDDLE]) {
				actions[BLUE_ORB_MIDDLE] = 0;
				actions[MIDDLE_PEDESTAL_SET] = 0;
			} else if (actions[BLUE_ORB_RIGHT]) {
				actions[BLUE_ORB_RIGHT] = 0;
				actions[RIGHT_PEDESTAL_SET] = 0;
			}
		} else if (!actions[GET_BLUE_ORB] && actions[ORB_PUZZLE_SOLVED]) {
			printf("You don't need the blue orb anymore.\n\n");
		} else if (actions[GET_BLUE_ORB]) {
			printf("You already have the blue orb!\n\n");
		}
	} else if (strcmp(chosen_action, "get green orb") == 0 || strcmp(chosen_action, "pick up green orb") == 0 || strcmp(chosen_action, "grab green orb") == 0 || strcmp(chosen_action, "take green orb") == 0 || strcmp(chosen_action, "acquire green orb") == 0 || strcmp(chosen_action, "obtain green orb") == 0) {
		if (!actions[GET_GREEN_ORB] && !actions[ORB_PUZZLE_SOLVED]) {
			printf("You pick up the green orb.\n\n");
			actions[GET_GREEN_ORB] = 1;
			if (actions[GREEN_ORB_LEFT]) {
				actions[GREEN_ORB_LEFT] = 0;
				actions[LEFT_PEDESTAL_SET] = 0;
			} else if (actions[GREEN_ORB_MIDDLE]) {
				actions[GREEN_ORB_MIDDLE] = 0;
				actions[MIDDLE_PEDESTAL_SET] = 0;
			} else if (actions[GREEN_ORB_RIGHT]) {
				actions[GREEN_ORB_RIGHT] = 0;
				actions[RIGHT_PEDESTAL_SET] = 0;
			}
		} else if (!actions[GET_GREEN_ORB] && actions[ORB_PUZZLE_SOLVED]) {
			printf("You don't need the green orb anymore.\n\n");
		} else if (actions[GET_GREEN_ORB]) {
			printf("You already have the green orb!\n\n");
		}
	} else if (strcmp(chosen_action, "pull lever") == 0 || strcmp(chosen_action, "tug lever") == 0 || strcmp(chosen_action, "yank lever") == 0) {
		if (actions[GREEN_ORB_LEFT] && actions[RED_ORB_MIDDLE] && actions[BLUE_ORB_RIGHT] && !actions[ORB_PUZZLE_SOLVED]) {
			printf("You pull the lever...\nThe orbs glow, and you hear a loud metallic grinding noise in the distance!\n\n");
			actions[ORB_PUZZLE_SOLVED] = 1;
		} else if (actions[GREEN_ORB_LEFT] && actions[RED_ORB_MIDDLE] && actions[BLUE_ORB_RIGHT] && actions[ORB_PUZZLE_SOLVED]) {
			printf("The lever is already pulled!\n\n");
		} else {
			printf("You pull the lever... The doors out of the room slam shut with iron gates!\nSpikes come out of the ceiling, and it begins slowly moving downward, with no escape!\nGAME OVER\n\n");
			return 0;
		}
	} else {
		printInvalid();
	}

	return 1;
}

bool room_LAB8(char name[], int *current_location, bool actions[], int *coins) {
	printf("Looking around, you see seven candles hanging from the ceiling.\nThere are doorways NORTH, EAST, WEST, and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go north through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go east through a doorway.\n\n");
		*current_location = LAB4;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south through a doorway.\n\n");
		*current_location = LAB9;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_LAB9(char name[], int *current_location, bool actions[], int *coins) {
	printf("Looking around, you see eight candles hanging from the ceiling.\nThere are doorways NORTH, EAST, WEST, and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go north through a doorway.\n\n");
		*current_location = LAB8;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go east through a doorway.\n\n");
		*current_location = LAB1;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		if (actions[ORB_PUZZLE_SOLVED]) {
			printf("You go west through the newly opened doorway.\n\n");
			*current_location = CAVERN1;
		} else {
			printf("The doorway is blocked by an iron gate, it won't budge.\n\n");
		}	
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south through a doorway.\n\n");
		*current_location = LAB1;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CAVERN1(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[CAVERN_INTRO]) {
		printf("The door back to the cavern slams shut behind you!\n");
		actions[CAVERN_INTRO] = 1;
	}
	printf("You appear to be in some kind of cavern, stalactites hang from the ceiling.\nThere are exits from the room NORTH, EAST, and WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use ice wand") == 0 || strcmp(chosen_action, "utilize ice wand") == 0 || strcmp(chosen_action, "employ ice wand") == 0 || strcmp(chosen_action, "wield ice wand") == 0 || strcmp(chosen_action, "try ice wand") == 0 || strcmp(chosen_action, "attempt ice wand") == 0) {
		if (!actions[USE_ICE_WAND_LAVA] && actions[GET_ICE_WAND]) {
			printf("You wave the ice wand towards the corridor of lava, and a stream of icy wind shoots out from it.\nThe lava cools to the point where it completely solidifies.\n\n");
			actions[USE_ICE_WAND_LAVA] = 1;
		} else if (!actions[USE_ICE_WAND_LAVA] && !actions[GET_ICE_WAND]) {
			printf("You don't have an ice wand!\n\n");
		} else {
			printf("The lava is already solid, nothing else to freeze here.\n\n");
		}
	} else if (strcmp(chosen_action, "use bomb") == 0 || strcmp(chosen_action, "utilize bomb") == 0 || strcmp(chosen_action, "employ bomb") == 0 || strcmp(chosen_action, "wield bomb") == 0 || strcmp(chosen_action, "try bomb") == 0 || strcmp(chosen_action, "attempt bomb") == 0) {
		if (actions[GET_BOMB]) {
			printf("It doesn't seem like a good place to use that.\n\n");
		} else {
			printf("You don't have a bomb!\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (!actions[USE_ICE_WAND_LAVA]) {
			printf("You head north, but are stopped by a corridor of lava.\nThere appears to be no way through here.\n\n");
		} else {
			printf("You cross the now cooled lava into another room.\n\n");
			*current_location = CAVERN11;
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go east through a corridor, ducking under some stalactites.\n\n");
		*current_location = CAVERN2;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("Moving around several large rocks on the ground, you head west.\n\n");
		*current_location = CAVERN7;	
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CAVERN2(char name[], int *current_location, bool actions[], int *coins) {
	printf("There isn't much here, just some STALAGMITES and... A giant MUSHROOM?\nThere are exits from the room NORTH, EAST, and WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use ice wand") == 0 || strcmp(chosen_action, "utilize ice wand") == 0 || strcmp(chosen_action, "employ ice wand") == 0 || strcmp(chosen_action, "wield ice wand") == 0 || strcmp(chosen_action, "try ice wand") == 0 || strcmp(chosen_action, "attempt ice wand") == 0) {
		if (!actions[GET_ICE_WAND]) {
			printf("You don't have an ice wand!\n\n");
		} else {
			printf("There doesn't seem to be anything useful to use that on here...\n\n");
		}
	} else if (strcmp(chosen_action, "use bomb") == 0 || strcmp(chosen_action, "utilize bomb") == 0 || strcmp(chosen_action, "employ bomb") == 0 || strcmp(chosen_action, "wield bomb") == 0 || strcmp(chosen_action, "try bomb") == 0 || strcmp(chosen_action, "attempt bomb") == 0) {
		if (actions[GET_BOMB]) {
			printf("It doesn't seem like a good place to use that.\n\n");
		} else {
			printf("You don't have a bomb!\n\n");
		}
	} else if (strcmp(chosen_action, "check stalagmites") == 0 || strcmp(chosen_action, "examine stalagmites") == 0 || strcmp(chosen_action, "look at stalagmites") == 0 || strcmp(chosen_action, "investigate stalagmites") == 0 || strcmp(chosen_action, "view stalagmites") == 0) {
		printf("These must have taken a long time to form.\n\n");
	} else if (strcmp(chosen_action, "check mushroom") == 0 || strcmp(chosen_action, "examine mushroom") == 0 || strcmp(chosen_action, "look at mushroom") == 0 || strcmp(chosen_action, "investigate mushroom") == 0 || strcmp(chosen_action, "view mushroom") == 0) {
		printf("No doubt about it, it's a giant mushroom...\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You step over several rocks into another area to the north.\n\n");
		*current_location = CAVERN5;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You head eastward.\n\n");
		*current_location = CAVERN3;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head west to the entrance of the cavern.\n\n");
		*current_location = CAVERN1;	
	} else {
		printInvalid();
	}

	return 1;
}

bool hideAndSeek() {
	bool win = 0;
	int debug = 0;
	while(!win) {
		int choice;
		int spot = (rand() % 5) + 1;
		printf("\nThe creature moved from behind each rock as a fast blur, you can't tell where it stopped at!\n\
Enter 1-5 to choose a hiding spot: ");
		
		scanf("%d", &choice);
		if (choice < 1 || choice > 5) {
			printf("Invalid choice, must be 1-5!\n");
		} else if (choice == spot) {
			printf("CREATURE: You found me!\n");
			return 1;
		} else {
			printf("CREATURE: Hah, wrong, try again!\n");
		}
	}
}

bool room_CAVERN3(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[CHECKED_MUSHROOM1]) {
		printf("Around you are various-sized rocks, including five large ones, and yet another giant MUSHROOM.\nThere are exits EAST and WEST.\n\n");
	} else {
		printf("There are many rocks, including five large ones, and the strange mushroom CREATURE.\nThere are exits EAST and WEST.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use ice wand") == 0 || strcmp(chosen_action, "utilize ice wand") == 0 || strcmp(chosen_action, "employ ice wand") == 0 || strcmp(chosen_action, "wield ice wand") == 0 || strcmp(chosen_action, "try ice wand") == 0 || strcmp(chosen_action, "attempt ice wand") == 0) {
		if (!actions[GET_ICE_WAND]) {
			printf("You don't have an ice wand!\n\n");
		} else {
			printf("There doesn't seem to be anything useful to use that on here...\n\n");
		}
	} else if (strcmp(chosen_action, "use bomb") == 0 || strcmp(chosen_action, "utilize bomb") == 0 || strcmp(chosen_action, "employ bomb") == 0 || strcmp(chosen_action, "wield bomb") == 0 || strcmp(chosen_action, "try bomb") == 0 || strcmp(chosen_action, "attempt bomb") == 0) {
		if (actions[GET_BOMB]) {
			printf("It doesn't seem like a good place to use that.\n\n");
		} else {
			printf("You don't have a bomb!\n\n");
		}
	} else if (strcmp(chosen_action, "check mushroom") == 0 || strcmp(chosen_action, "examine mushroom") == 0 || strcmp(chosen_action, "look at mushroom") == 0 || strcmp(chosen_action, "investigate mushroom") == 0 || strcmp(chosen_action, "view mushroom") == 0) {
		if (!actions[CHECKED_MUSHROOM1]) {
			printf("It appears to be a giant mushroom, but wait... it's some kind of strange creature!\n\n");
			actions[CHECKED_MUSHROOM1] = 1;
		} else if (!actions[GET_RUBY]) {
			printf("The mushroom creature appears to be restless.\n\n");
		} else if (actions[GET_RUBY]) {
			printf("The mushroom creature appears to be at peace.\n\n");
		}
	} else if (strcmp(chosen_action, "talk to creature") == 0 || strcmp(chosen_action, "speak to creature") == 0 || strcmp(chosen_action, "chat with creature") == 0 || strcmp(chosen_action, "talk with creature") == 0 || strcmp(chosen_action, "converse with creature") == 0) {
		if (actions[CHECKED_MUSHROOM1]) {
			if (!actions[GET_RUBY]) {
				printf("CREATURE: Do you want to play a game? I'll give you this ruby if you win!\n\n");
			} else {
				printf("CREATURE: Do you want to play a game? I have nothing else to give you, but it would be fun!\n\n");
			}
			printf("Play a game with the creature? (y/n): ");
			char yn[4];
			scanf("%[^\n]%*c", yn);
			if (strcmp(yn, "y") == 0) {
				hideAndSeek();
				if (!actions[GET_RUBY]) {
					printf("CREATURE: As promised, here's the ruby!\nThe creature hands you a ruby.\n\n");
					actions[GET_RUBY] = 1;
				} else {
					printf("CREATURE: Hah, that was fun!\n\n");
				}	
			}
		} else {
			printf("You see no creature to talk too...\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You head eastward.\n\n");
		*current_location = CAVERN4;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head west.\n\n");
		*current_location = CAVERN2;	
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CAVERN4(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[USE_ICE_WAND_LAKE]) {
		printf("You see a small lake, across it appears to be something glinting...\nIt's some kind of KEY?\nThe only exit is to the WEST.\n\n");
	} else if (!actions[GET_KEY_CAVERN]) {
		printf("You see a small, frozen lake, across it appears to be something glinting...\nIt's some kind of KEY?\nThe only exit is to the WEST.\n\n");
	} else if (actions[GET_KEY_CAVERN]) {
		printf("You see a small, frozen lake, nothing else to note here... For a second, you thought you saw a giant eye staring up from the frozen lake, you got chills...\nThe only exit is to the WEST.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use ice wand") == 0 || strcmp(chosen_action, "utilize ice wand") == 0 || strcmp(chosen_action, "employ ice wand") == 0 || strcmp(chosen_action, "wield ice wand") == 0 || strcmp(chosen_action, "try ice wand") == 0 || strcmp(chosen_action, "attempt ice wand") == 0) {
		if (!actions[USE_ICE_WAND_LAKE] && actions[GET_ICE_WAND]) {
			printf("You wave the ice wand towards the lake.\nIt quickly freezes over after a blast of icy air hits it.\n\n");
			actions[USE_ICE_WAND_LAKE] = 1;
		} else if (!actions[USE_ICE_WAND_LAKE] && !actions[GET_ICE_WAND]) {
			printf("You don't have an ice wand!\n\n");
		} else if (actions[USE_ICE_WAND_LAKE]) {
			printf("You already froze the lake with the ice wand!\n\n");
		}
	} else if (strcmp(chosen_action, "get key") == 0 || strcmp(chosen_action, "pick up key") == 0 || strcmp(chosen_action, "grab key") == 0 || strcmp(chosen_action, "take key") == 0 || strcmp(chosen_action, "acquire key") == 0 || strcmp(chosen_action, "obtain key") == 0) {
		if (!actions[USE_ICE_WAND_LAKE]) {
			printf("You enter the lake to swim across and get the key.\nHalfway across, you feel something closing around your legs!\nYou see several tentacles rise up from the lake and wrap around you, pulling you deep into the water.\nIn a panic, you let out your breath and water fills your lungs.\nThe last thing you see is a giant eye staring at you.\nGAME OVER\n\n");
			return 0;
		} else if (actions[USE_ICE_WAND_LAKE] && !actions[GET_KEY_CAVERN]) {
			printf("You carefully cross the now frozen lake and retrieve the key.\n\n");
			actions[GET_KEY_CAVERN] = 1;
		} else if (actions[USE_ICE_WAND_LAKE] && actions[GET_KEY_CAVERN]) {
			printf("You already got the key from here!\n\n");
		}
	} else if (strcmp(chosen_action, "use bomb") == 0 || strcmp(chosen_action, "utilize bomb") == 0 || strcmp(chosen_action, "employ bomb") == 0 || strcmp(chosen_action, "wield bomb") == 0 || strcmp(chosen_action, "try bomb") == 0 || strcmp(chosen_action, "attempt bomb") == 0) {
		if (actions[GET_BOMB]) {
			printf("There doesn't seem to be any point to using that here.\n\n");
		} else {
			printf("You don't have a bomb!\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head back west.\n\n");
		*current_location = CAVERN3;	
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CAVERN5(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[CHECKED_MUSHROOM2]) {
		printf("Nothing stands out in this room except for a giant MUSHROOM. It almost feels like it's staring at you?\nThere are exits from the room EAST and SOUTH.\n\n");
	} else if (!actions[GET_ICE_WAND]) {
		printf("The mushroom CREATURE is looking like it wants to talk to you.\nThere are exits from the room EAST and SOUTH.\n\n");
	} else {
		printf("The mushroom CREATURE looks satisfied.\nThere are exits from the room EAST and SOUTH.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use ice wand") == 0 || strcmp(chosen_action, "utilize ice wand") == 0 || strcmp(chosen_action, "employ ice wand") == 0 || strcmp(chosen_action, "wield ice wand") == 0 || strcmp(chosen_action, "try ice wand") == 0 || strcmp(chosen_action, "attempt ice wand") == 0) {
		if (!actions[GET_ICE_WAND]) {
			printf("You don't have an ice wand!\n\n");
		} else {
			printf("There doesn't seem to be anything useful to use that on here...\n\n");
		}
	} else if (strcmp(chosen_action, "use bomb") == 0 || strcmp(chosen_action, "utilize bomb") == 0 || strcmp(chosen_action, "employ bomb") == 0 || strcmp(chosen_action, "wield bomb") == 0 || strcmp(chosen_action, "try bomb") == 0 || strcmp(chosen_action, "attempt bomb") == 0) {
		if (actions[GET_BOMB]) {
			printf("It doesn't seem like a good place to use that.\n\n");
		} else {
			printf("You don't have a bomb!\n\n");
		}
	} else if (strcmp(chosen_action, "check mushroom") == 0 || strcmp(chosen_action, "examine mushroom") == 0 || strcmp(chosen_action, "look at mushroom") == 0 || strcmp(chosen_action, "investigate mushroom") == 0 || strcmp(chosen_action, "view mushroom") == 0) {
		if (!actions[CHECKED_MUSHROOM2]) {
			printf("It appears to be a giant mushroom, but wait... it's actually a creature of some sorts!\n\n");
			actions[CHECKED_MUSHROOM2] = 1;
		} else {
			printf("The mushroom creature is just standing there.\n\n");
		}
	} else if (strcmp(chosen_action, "talk to creature") == 0 || strcmp(chosen_action, "speak to creature") == 0 || strcmp(chosen_action, "chat with creature") == 0 || strcmp(chosen_action, "talk with creature") == 0 || strcmp(chosen_action, "converse with creature") == 0) {
		if (actions[CHECKED_MUSHROOM2]) {
			if (!actions[GET_ICE_WAND]) {
				printf("CREATURE: I'll give you something good if you trade for it.\n");
				if (!actions[GIVE_RUBY]) {
					printf("CREATURE: I need a RUBY.\n");
				} 
				if (!actions[GIVE_SAPPHIRE]) {
					printf("CREATURE: A SAPPHIRE would be really nice.\n");
				}
				if (!actions[GIVE_EMERALD]) {
					printf("CREATURE: An EMERALD would be great.\n");
				}
				if (actions[GIVE_RUBY] && actions[GIVE_SAPPHIRE] && actions[GIVE_EMERALD]) {
					printf("CREATURE: That's exactly everything I wanted, thank you!\nHere is an ice wand, it can cool down or even freeze things!\nJust keep in mind it is kind of fragile.\nThe creature hands you the ice wand!\n\n");
					actions[GET_ICE_WAND] = 1;
				}
			} else {
				printf("CREATURE: Thanks again, enjoy that ice wand!\n\n");
			}
		} else {
			printf("You see no creature to talk to...\n\n");
		}
	} else if (strcmp(chosen_action, "give ruby") == 0 || strcmp(chosen_action, "present ruby") == 0 || strcmp(chosen_action, "provide ruby") == 0) {
		if (!actions[GIVE_RUBY] && actions[GET_RUBY]) {
			printf("You hand the creature the ruby.\n\n");
			actions[GIVE_RUBY] = 1;
		} else if (!actions[GIVE_RUBY] && !actions[GET_RUBY]) {
			printf("You don't have a ruby!\n\n");
		} else if (actions[GIVE_RUBY]) {
			printf("You already gave the creature the ruby!\n\n");
		}
	} else if (strcmp(chosen_action, "give sapphire") == 0 || strcmp(chosen_action, "present sapphire") == 0 || strcmp(chosen_action, "provide sapphire") == 0) {
		if (!actions[GIVE_SAPPHIRE] && actions[GET_SAPPHIRE]) {
			printf("You give the creature the sapphire.\n\n");
			actions[GIVE_SAPPHIRE] = 1;
		} else if (!actions[GIVE_SAPPHIRE] && !actions[GET_SAPPHIRE]) {
			printf("You don't have that!\n\n");
		} else if (actions[GIVE_SAPPHIRE]) {
			printf("You already handed the creature the sapphire!\n\n");
		}
	} else if (strcmp(chosen_action, "give emerald") == 0 || strcmp(chosen_action, "present emerald") == 0 || strcmp(chosen_action, "provide emerald") == 0) {
		if (!actions[GIVE_EMERALD] && actions[GET_EMERALD]) {
			printf("You pass the creature the emerald.\n\n");
			actions[GIVE_EMERALD] = 1;
		} else if (!actions[GIVE_EMERALD] && !actions[GET_EMERALD]) {
			printf("You don't have an emerald on you!\n\n");
		} else if (actions[GIVE_EMERALD]) {
			printf("The creature already has your emerald!\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go eastward into another area.\n\n");
		*current_location = CAVERN6;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You travel south.\n\n");
		*current_location = CAVERN2;	
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CAVERN6(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[SEEN_FLINT]) {
		printf("When walking into the area, you accidentally kick a rock that shoots out sparks.\nYou conclude that it must be a FLINT rock.\nThe only open direction is WEST.\n\n");
		actions[SEEN_FLINT] = 1;
	} else if (actions[SEEN_FLINT] && !actions[GET_FLINT]) {
		printf("Nothing stands out in this area other than the FLINT rock.\nThe only open direction is WEST.\n\n");
	} else if (actions[GET_FLINT] && !actions[USE_BOMB]) {
		printf("There is really nothing to note in this area.\nThe only open direction is WEST.\n\n");
	} else if (actions[USE_BOMB]) {
		printf("There is really nothing to note in this area.\nWhoever designed this cave must have gotten lazy. :3\nThe only open direction is WEST.\n\n");
	} 
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use ice wand") == 0 || strcmp(chosen_action, "utilize ice wand") == 0 || strcmp(chosen_action, "employ ice wand") == 0 || strcmp(chosen_action, "wield ice wand") == 0 || strcmp(chosen_action, "try ice wand") == 0 || strcmp(chosen_action, "attempt ice wand") == 0) {
		if (!actions[GET_ICE_WAND]) {
			printf("You don't have an ice wand!\n\n");
		} else {
			printf("There doesn't seem to be anything useful to use that on here...\n\n");
		}
	} else if (strcmp(chosen_action, "use bomb") == 0 || strcmp(chosen_action, "utilize bomb") == 0 || strcmp(chosen_action, "employ bomb") == 0 || strcmp(chosen_action, "wield bomb") == 0 || strcmp(chosen_action, "try bomb") == 0 || strcmp(chosen_action, "attempt bomb") == 0) {
		if (actions[GET_BOMB]) {
			printf("It doesn't seem like a good place to use that.\n\n");
		} else {
			printf("You don't have a bomb!\n\n");
		}
	} else if (strcmp(chosen_action, "get flint") == 0 || strcmp(chosen_action, "pick up flint") == 0 || strcmp(chosen_action, "grab flint") == 0 || strcmp(chosen_action, "take flint") == 0 || strcmp(chosen_action, "acquire flint") == 0 || strcmp(chosen_action, "obtain flint") == 0) {
		if (!actions[GET_FLINT]) {
			printf("You pick up the flint rock and put it in your pocket.\n\n");
			actions[GET_FLINT] = 1;
		} else {
			printf("You already picked up the flint rock!\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head west out of this area.\n\n");
		*current_location = CAVERN5;	
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CAVERN7(char name[], int *current_location, bool actions[], int *coins) {
	printf("There are many large MUSHROOMS in this room.\nThere are ways leading out of this room to the NORTH, EAST, WEST, and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use ice wand") == 0 || strcmp(chosen_action, "utilize ice wand") == 0 || strcmp(chosen_action, "employ ice wand") == 0 || strcmp(chosen_action, "wield ice wand") == 0 || strcmp(chosen_action, "try ice wand") == 0 || strcmp(chosen_action, "attempt ice wand") == 0) {
		if (!actions[GET_ICE_WAND]) {
			printf("You don't have an ice wand!\n\n");
		} else {
			printf("There doesn't seem to be anything useful to use that on here...\n\n");
		}
	} else if (strcmp(chosen_action, "use bomb") == 0 || strcmp(chosen_action, "utilize bomb") == 0 || strcmp(chosen_action, "employ bomb") == 0 || strcmp(chosen_action, "wield bomb") == 0 || strcmp(chosen_action, "try bomb") == 0 || strcmp(chosen_action, "attempt bomb") == 0) {
		if (actions[GET_BOMB]) {
			printf("It doesn't seem like a good place to use that.\n\n");
		} else {
			printf("You don't have a bomb!\n\n");
		}
	} else if (strcmp(chosen_action, "check mushrooms") == 0 || strcmp(chosen_action, "examine mushrooms") == 0 || strcmp(chosen_action, "look at mushrooms") == 0 || strcmp(chosen_action, "investigate mushrooms") == 0 || strcmp(chosen_action, "view mushrooms") == 0) {
		printf("The mushrooms seem pretty ordinary, just very big, and there are enough in here that it is hard to get around.\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You head north out of the room.\n\n");
		*current_location = CAVERN8;	
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You head back east.\n\n");
		*current_location = CAVERN1;	
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head westward.\n\n");
		*current_location = CAVERN10;	
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You head south into another room of the cavern.\n\n");
		*current_location = CAVERN9;	
	} else {
		printInvalid();
	}

	return 1;
}

bool tenStoneGame() {
	printf("First you bet 1-3 stones, then I'll try to guess your bet.\nIf I'm right, I get the bet, else I lose the bet.\nThen, we switch turns.\nWe keep switching until someone runs out of stones.\nGot it?\n\n");
	int player1 = 10, player2 = 10;
	int bet, choice;
	while(player1 != 0 && player2 != 0) {
		printf("Player: %i\tCREATURE: %i\n\n", player1, player2);
		bet = 0;
		while(bet < 1 || bet > 3) {
			printf("Enter a bet (1-3): ");
			scanf(" %d", &bet);
			if (bet < 1 || bet > 3) {
				printf("Invalid bet, must be 1 to 3!\n");
			}
		}
		choice = (rand() % 3) + 1;
		printf("Creature chose %i.\n", choice);
		if (bet == choice) {
			printf("Creature was correct!\n\n");
			player1 -= (choice <= player1 ? choice : player1);
			player2 += (choice <= player1 ? choice : player1);
			if (player1 == 0) {
				printf("Player loses!\n");
				return 0;
			} 
		} else {
			printf("Creature was wrong!\n\n");
			player1 += (bet <= player2 ? bet : player2);
			player2 -= (bet <= player2 ? bet : player2);
			if (player2 == 0) {
				printf("Creature loses!\n");
				return 1;
			} 
		}
		
		printf("Player: %i\tCREATURE: %i\n\n", player1, player2);
		choice = 0;
		bet = (rand() % 3) + 1;
		while(choice < 1 || choice > 3) {
			printf("Enter a guess (1-3): ");
			scanf(" %d", &choice);
			if (choice < 1 || choice > 3) {
				printf("Invalid guess, must be 1 to 3!\n");
			}
		}
		printf("Creature chose %i.\n", bet);
		if (bet == choice) {
			printf("Player was correct!\n\n");
			player1 += (choice <= player2 ? choice : player2);
			player2 -= (choice <= player2 ? choice : player2);
			if (player2 == 0) {
				printf("Creature loses!\n");
				return 1;
			} 
		} else {
			printf("Player was wrong!\n\n");
			player1 -= (bet <= player1 ? bet : player1);
			player2 += (bet <= player1 ? bet : player1);
			if (player1 == 0) {
				printf("Player loses!\n");
				return 0;
			} 
		}
	}
}

bool room_CAVERN8(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[CHECKED_MUSHROOM3]) {
		printf("There is a MUSHROOM here, along with several small, rounded stones around it.\nThe only exit out of here is SOUTH.\n\n");
	} else if (!actions[GET_SAPPHIRE]) {
		printf("The CREATURE is playing with the round stones, it looks bored.\nThe only exit out of here is SOUTH.\n\n");
	} else if (actions[GET_SAPPHIRE]) {
		printf("The CREATURE is playing with the round stones, it appears to be happy.\nThe only exit out of here is SOUTH.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use ice wand") == 0 || strcmp(chosen_action, "utilize ice wand") == 0 || strcmp(chosen_action, "employ ice wand") == 0 || strcmp(chosen_action, "wield ice wand") == 0 || strcmp(chosen_action, "try ice wand") == 0 || strcmp(chosen_action, "attempt ice wand") == 0) {
		if (!actions[GET_ICE_WAND]) {
			printf("You don't have an ice wand!\n\n");
		} else {
			printf("There doesn't seem to be anything useful to use that on here...\n\n");
		}
	} else if (strcmp(chosen_action, "use bomb") == 0 || strcmp(chosen_action, "utilize bomb") == 0 || strcmp(chosen_action, "employ bomb") == 0 || strcmp(chosen_action, "wield bomb") == 0 || strcmp(chosen_action, "try bomb") == 0 || strcmp(chosen_action, "attempt bomb") == 0) {
		if (actions[GET_BOMB]) {
			printf("It doesn't seem like a good place to use that.\n\n");
		} else {
			printf("You don't have a bomb!\n\n");
		}
	} else if (strcmp(chosen_action, "check mushroom") == 0 || strcmp(chosen_action, "examine mushroom") == 0 || strcmp(chosen_action, "look at mushroom") == 0 || strcmp(chosen_action, "investigate mushroom") == 0 || strcmp(chosen_action, "view mushroom") == 0) {
		if (!actions[CHECKED_MUSHROOM3]) {
			printf("The mushroom moved when you examined it, it's a creature!\n\n");
			actions[CHECKED_MUSHROOM3] = 1;
		} else if (!actions[GET_SAPPHIRE]) {
			printf("The mushroom creature appears to be bored.\n\n");
		} else if (actions[GET_SAPPHIRE]) {
			printf("The mushroom creature appears to look quite content.\n\n");
		}
	} else if (strcmp(chosen_action, "talk to creature") == 0 || strcmp(chosen_action, "speak to creature") == 0 || strcmp(chosen_action, "chat with creature") == 0 || strcmp(chosen_action, "talk with creature") == 0 || strcmp(chosen_action, "converse with creature") == 0) {
		if (actions[CHECKED_MUSHROOM3]) {
			if (!actions[GET_SAPPHIRE]) {
				printf("CREATURE: Do you want to play a game? Win and I'll give you this sapphire!\n\n");
			} else {
				printf("CREATURE: Do you want to play a game? I've got nothing else to give, but I would enjoy it!\n\n");
			}
			printf("Play a game with the creature? (y/n): ");
			char yn[4];
			scanf("%[^\n]%*c", yn);
			if (strcmp(yn, "y") == 0) {
				bool result = tenStoneGame();
				if (result) {
					if (!actions[GET_SAPPHIRE]) {
						printf("CREATURE: Good job, this sapphire is for you!\nThe creature gives you the sapphire.\n\n");
						actions[GET_SAPPHIRE] = 1;
					} else {
						printf("CREATURE: Hah, thanks for playing again!\n\n");
					}
				} else {
					printf("CREATURE: Hah, better luck next time!\n");
				}	
			}
		} else {
			printf("You see no creature to talk to...\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You head southward.\n\n");
		*current_location = CAVERN7;	
	} else {
		printInvalid();
	}

	return 1;
}

void displayGame(bool man[], char word[], bool letters[]) {
	printf(" |=======|\n");
	printf(" |       |\n");
	printf(" |       %c\n", man[0]?'O':' ');
	printf(" |      %c%c%c\n", man[1]?'/':' ', man[2]?'|':' ', man[3]?'\\':' ');
	printf(" |      %c %c\n", man[4]?'/':' ', man[5]?'\\':' ');
	printf("_|_\n");
	for (int i = 0; i < strlen(word); i++) {
		if (letters[i]) {
			printf(" %c ", word[i]);
		} else {
			printf(" _ ");
		}
	}
	puts("\n");
}

bool hangman() {
	char words[][32] = { 
			"think", "limbo", "parade", "welcome", "friend", "coolio", "river", "deliver", "nosebleed", "forest", 
			"fishing", "trust", "hummingbird", "flamingo", "blueberry", "sandwich", "bacon", "yogurt", "mailbox", "interest", 
			"painting", "spoken", "brain", "train", "graffiti", "zombie", "vampire", "werewolf", "astronaut", "rocket", 
			"deluxe", "friday", "programming", "momentum", "poster", "biscuit", "pancakes", "flurry", "blizzard", "wizard", 
			"pinball", "jukebox", "drumset", "guitar", "energy", "coffee", "bookshelf", "library", "motion", "potion", 
			"reaper", "spirit", "architect", "injection", "weightlift", "positive", "negative", "silver", "automobile", "banana", 
			"candlestick", "lighting", "toasted", "roasted", "performance", "shoelaces", "fingernail", "orange", "security", "highway", 
			"assassin", "chemical", "periodic", "accident", "tension", "section", "feather", "competition", "hacker", "computer", 
			"system", "learning", "structure", "password", "classroom", "happiness", "fearless", "blessed", "remaining", "headache", 
			"snowflake", "summary", "meadow", "prarie", "hedgehog", "grilled", "machine", "carnival", "virtual", "mechanical", 
			"artificial", "assembler", "midnight", "afternoon", "daylight", "gargoyle", "intelligence", "treasure", "measure", "bedroom", 
			"backpack", "teapot", "arsenal", "katana", "lighthouse", "internal", "pumpkin", "vegetable", "astronomy", "telescope", 
			"crossword", "difference", "charcoal", "earthquake", "snowstorm", "barbecue", "behemoth", "amusement", "television", "medicine", 
			"notebook", "scientist", "battlefield", "microphone", "monsoon", "tsunami", "lightning", "electrified", "bullseye", "chocolate", 
			"motorcycle", "bicycle", "graveyard", "cemetary", "haunted", "cardboard", "account", "wallpaper", "entryway", "sharpener", 
			"server", "service", "expensive", "roller", "stability", "forewarn", "bookworm", "caterpillar", "centipede", "dresser", 
			"drawers", "bookmarker", "secret", "whisper", "whiskers", "department", "compartment", "chandelier", "construction", "airplane", 
			"microwave", "animation", "worship", "champion", "baseball", "football", "explorer", "miniature", "xylophone", "meditation", 
			"information", "disease", "sacrifice", "spherical", "delightful", "magician", "troublesome", "fanatical", "ultrasound", "infrared", 
			"enlightened", "eyelashes", "raccoon", "autograph", "introduction", "cryptology", "avalanche", "mathematics", "journalist", "physicist", 
			"sapphire", "emerald", "reptile", "mammal", "cheetah", "capital", "keyboard", "adventure", "delusional", "traditional", 
			"integration", "symbolism", "sunshine", "mirrored", "milkshake", "waterfall", "waterway", "virology", "forestry", "mentioning", 
			"engineering", "aardvark", "elephant", "whirlpool", "motionless", "scented", "ventriloquist", "gardening", "racetrack", "hilarious", 
			"multiply", "division", "origami", "directional", "mysterious", "temperature", "correction", "possibility", "probability", "absolute", 
			"maximum", "minimum", "stationary", "cinema", "limelight", "pawprint", "controller", "seedling", "chimney", "rooftop"
	 };
	 
	bool man[] = { 0, 0, 0, 0, 0, 0 };
	int incorrect_guesses = 0;
	char word[32];
	strcpy(word, words[rand() % TOTAL_WORDS]);
	bool *letters = malloc(strlen(word) * sizeof(bool));
	for (int i = 0; i < strlen(word); i++) {
		letters[i] = 0;
	} 
	
	bool game_over = 0;
	bool game_won = 0;
	while(!game_over) {
		displayGame(man, word, letters);
		int user_choice;
		printf("Enter 1 or 2 to make a choice\n1: Guess a letter\n2: Guess the word\nChoice: ");
		scanf(" %i", &user_choice);
		
		bool already_guessed = 0;
		switch(user_choice) {
			case(1):
				char letter;
				printf("Input the letter to guess: ");
				scanf(" %c", &letter);
				bool guessed_correctly = 0;
				for (int i = 0; i < strlen(word); i++) {
					if (word[i] == letter) {
						if (letters[i]) {
							already_guessed = 1;
							break;
						} else {
							letters[i] = 1;
							guessed_correctly = 1;
						}
					}
				}
				if (guessed_correctly) {
					printf("\nYou guessed correctly, good job!\n");
					int letters_found = 0;
					for (int i = 0; i < strlen(word); i++) {
						if (letters[i]) {
							letters_found++;
						}
					}
					if (strlen(word) == letters_found) {
						printf("\nYou got the word, good job!\n");
						game_won = 1;
						game_over = 1;
					}
				} else {
					printf("\nYou guessed incorrectly, oh no!\n");
					incorrect_guesses++;
					man[incorrect_guesses - 1] = 1;
					if (incorrect_guesses == 6) {
						game_over = 1;
					}
				}
				if (already_guessed) {
					printf("\nYou already guessed that letter!\n");
					break;
				}
				break;
			case(2):
				char guessed_word[32];
				printf("Input the word to guess: ");
				scanf(" %[^\n]%*c", guessed_word);
				if (strcmp(word, guessed_word) == 0) {
					printf("\nYou got the word, good job!\n");
					game_won = 1;
					game_over = 1;
				} else {
					printf("\nSorry, incorrect guess!\n");
					incorrect_guesses++;
					man[incorrect_guesses - 1] = 1;
					if (incorrect_guesses == 6) {
						game_over = 1;
					}
				}
				
				break;
			default:
				puts("\nInvalid choice!\n");
		}
	
	}
	
	for (int i = 0; i < strlen(word); i++) {
		letters[i] = 1;
	}
	displayGame(man, word, letters);
	free(letters);
	if (game_won) {
		printf("You won, congratulations!\n");
		return 1;
	} else {
		printf("You lose! (X_X)\n");
		return 0;
	}
}

bool room_CAVERN9(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[CHECKED_MUSHROOM4]) {
		printf("You notice a flat wall with some crudely drawn figures, along with a MUSHROOM next to a pile of chalky rocks.\nThe only exit out of here is NORTH.\n\n");
	} else if (!actions[GET_EMERALD]) {
		printf("The CREATURE is drawing on the wall with the chalk-like rocks, looking bored.\nThe only exit out of here is NORTH.\n\n");
	} else if (actions[GET_EMERALD]) {
		printf("The CREATURE looks content, drawing on the wall what appears to be... A crudely drawn version of you?\nThe only exit out of here is NORTH.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use ice wand") == 0 || strcmp(chosen_action, "utilize ice wand") == 0 || strcmp(chosen_action, "employ ice wand") == 0 || strcmp(chosen_action, "wield ice wand") == 0 || strcmp(chosen_action, "try ice wand") == 0 || strcmp(chosen_action, "attempt ice wand") == 0) {
		if (!actions[GET_ICE_WAND]) {
			printf("You don't have an ice wand!\n\n");
		} else {
			printf("There doesn't seem to be anything useful to use that on here...\n\n");
		}
	} else if (strcmp(chosen_action, "use bomb") == 0 || strcmp(chosen_action, "utilize bomb") == 0 || strcmp(chosen_action, "employ bomb") == 0 || strcmp(chosen_action, "wield bomb") == 0 || strcmp(chosen_action, "try bomb") == 0 || strcmp(chosen_action, "attempt bomb") == 0) {
		if (actions[GET_BOMB]) {
			printf("It doesn't seem like a good place to use that.\n\n");
		} else {
			printf("You don't have a bomb!\n\n");
		}
	} else if (strcmp(chosen_action, "check mushroom") == 0 || strcmp(chosen_action, "examine mushroom") == 0 || strcmp(chosen_action, "look at mushroom") == 0 || strcmp(chosen_action, "investigate mushroom") == 0 || strcmp(chosen_action, "view mushroom") == 0) {
		if (!actions[CHECKED_MUSHROOM4]) {
			printf("You inspect the mushroom... It's a creature! It picks up one of the chalky rocks and starts drawing on the wall with it!\n\n");
			actions[CHECKED_MUSHROOM4] = 1;
		} else {
			printf("The mushroom creature looks like it wants to play.\n\n");
		}
	} else if (strcmp(chosen_action, "talk to creature") == 0 || strcmp(chosen_action, "speak to creature") == 0 || strcmp(chosen_action, "chat with creature") == 0 || strcmp(chosen_action, "talk with creature") == 0 || strcmp(chosen_action, "converse with creature") == 0) {
		if ( actions[CHECKED_MUSHROOM4]) {
			if (!actions[GET_EMERALD]) {
				printf("CREATURE: Do you want to play a fun game with me? I'll give you this precious emerald if you can win!\n\n");
			} else {
				printf("CREATURE: Do you want to play a fun game with me? I've got nothing else to give, but I bet it would just be fun!\n\n");
			}
			printf("Play a game with the creature? (y/n): ");
			char yn[4];
			scanf("%[^\n]%*c", yn);
			if (strcmp(yn, "y") == 0) {
				bool result = hangman();
				if (result) {
					if (!actions[GET_EMERALD]) {
						printf("CREATURE: Oh wow, you won! This is your prize!\nThe creature passes an emerald to you.\n\n");
						actions[GET_EMERALD] = 1;
					} else {
						printf("CREATURE: Hah, you won again! Thank you for playing with me!\n\n");
					}
				} else {
					printf("CREATURE: Haha, it's okay, you can try again any time!\n");
				}	
			}
		} else {
			printf("You see no creature to talk to...\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You head northward.\n\n");
		*current_location = CAVERN7;	
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CAVERN10(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[GET_BOMB]) {
		printf("There are some LARGE MUSHROOMS and SMALL MUSHROOMS in this room.\nThere is also a CHEST in the middle of it all.\nTThe only direction out of here is EAST.\n\n");
	} else {
		printf("There are some LARGE MUSHROOMS and SMALL MUSHROOMS in this room.\nThere is also an empty CHEST.\nTThe only direction out of here is EAST.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use ice wand") == 0 || strcmp(chosen_action, "utilize ice wand") == 0 || strcmp(chosen_action, "employ ice wand") == 0 || strcmp(chosen_action, "wield ice wand") == 0 || strcmp(chosen_action, "try ice wand") == 0 || strcmp(chosen_action, "attempt ice wand") == 0) {
		if (!actions[GET_ICE_WAND]) {
			printf("You don't have an ice wand!\n\n");
		} else {
			printf("There doesn't seem to be anything useful to use that on here...\n\n");
		}
	} else if (strcmp(chosen_action, "use bomb") == 0 || strcmp(chosen_action, "utilize bomb") == 0 || strcmp(chosen_action, "employ bomb") == 0 || strcmp(chosen_action, "wield bomb") == 0 || strcmp(chosen_action, "try bomb") == 0 || strcmp(chosen_action, "attempt bomb") == 0) {
		if (actions[GET_BOMB]) {
			printf("It doesn't seem like a good place to use that.\n\n");
		} else {
			printf("You don't have a bomb!\n\n");
		}
	} else if (strcmp(chosen_action, "check large mushrooms") == 0 || strcmp(chosen_action, "examine large mushrooms") == 0 || strcmp(chosen_action, "look at large mushrooms") == 0 || strcmp(chosen_action, "investigate large mushrooms") == 0 || strcmp(chosen_action, "view large mushrooms") == 0) {
		printf("These large mushrooms almost seem to be protecting the small ones.\n\n");
	} else if (strcmp(chosen_action, "check small mushrooms") == 0 || strcmp(chosen_action, "examine small mushrooms") == 0 || strcmp(chosen_action, "look at small mushrooms") == 0 || strcmp(chosen_action, "investigate small mushrooms") == 0 || strcmp(chosen_action, "view small mushrooms") == 0) {
		printf("You swear you saw some of the large mushrooms move when you leaned in to examine the small ones.\nYou must be imagining things.\n\n");
	} else if (strcmp(chosen_action, "open chest") == 0) {
		if (!actions[GET_BOMB]) {
			printf("You try to open the chest, but it's locked.\n\n");
		} else {
			printf("You already opened the chest, it's empty now!\n\n");
		}
	} else if (strcmp(chosen_action, "unlock chest") == 0) {
		if (!actions[GET_BOMB] && actions[GET_KEY_CAVERN]) {
			printf("You unlock the chest, and find a bomb inside!\nYou grab it.\n\n");
			actions[GET_BOMB] = 1;
		} else if (!actions[GET_BOMB] && !actions[GET_KEY_CAVERN]) {
			printf("You want to unlock the chest, but you don't have the key!\n\n");
		} else if (actions[GET_BOMB]) {
			printf("You already unlocked the chest and got the contents!\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You head back east.\n\n");
		*current_location = CAVERN7;	
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CAVERN11(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[USE_BOMB]) {
		printf("There are several large boulders in this area.\nIt seems there is some light pouring through these large rocks to the north.\nThe exit only lies to the SOUTH across the solidified lava.\n\n");
	} else {
		printf("With the boulders now blown to pieces, the exits are to the NORTH and SOUTH.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use ice wand") == 0 || strcmp(chosen_action, "utilize ice wand") == 0 || strcmp(chosen_action, "employ ice wand") == 0 || strcmp(chosen_action, "wield ice wand") == 0 || strcmp(chosen_action, "try ice wand") == 0 || strcmp(chosen_action, "attempt ice wand") == 0) {
		if (!actions[GET_ICE_WAND]) {
			printf("You don't have an ice wand!\n\n");
		} else {
			printf("There doesn't seem to be anything useful to use that on here...\n\n");
		}
	} else if (strcmp(chosen_action, "use bomb") == 0 || strcmp(chosen_action, "utilize bomb") == 0 || strcmp(chosen_action, "employ bomb") == 0 || strcmp(chosen_action, "wield bomb") == 0 || strcmp(chosen_action, "try bomb") == 0 || strcmp(chosen_action, "attempt bomb") == 0) {
		if (!actions[USE_BOMB] && actions[GET_BOMB] && actions[GET_FLINT]) {
			printf("You use your flint to light the bomb, place it near the boulders, and run for cover.\nThe bomb explodes, blasting the boulders to pieces.\nWhat that creature said about the ice wand being fragile was true, as the shock of the blast broke it to fragments!\n\n");
			actions[USE_BOMB] = 1;
			actions[GET_ICE_WAND] = 0;
		} else if (actions[GET_BOMB] && !actions[GET_FLINT]) {
			printf("You have a bomb, but nothing to light it with!\n\n");
		} else if (!actions[GET_BOMB]) {
			printf("You don't have a bomb!\n\n");
		} else if (actions[USE_BOMB]) {
			printf("You already used the bomb to destroy the boulders!\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (!actions[USE_BOMB]) {
			printf("There may be an exit out of here to the north, but large boulders block your way.\n\n");
		} else {
			printf("You head out of the cavern, out to what finally appears to be outside!\nAs you leave, large boulders fall behind you, blocking your way back into the cavern!\n\n");
			*current_location = OUTSIDE_MANSION;
		}	
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You head south back into the original room of the cavern.\n\n");
		*current_location = CAVERN1;	
	} else {
		printInvalid();
	}

	return 1;
}

bool room_OUTSIDE_MANSION(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[ALL_BOOKS_PLACED]) {
		printf("There is a rundown looking mansion to the NORTH. Something feels ominous about it...\n\n");
	} else {
		printf("There is a rundown looking mansion to the NORTH. You don't recall seeing it earlier, but there is a TOMBSTONE here.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check tombstone") == 0 || strcmp(chosen_action, "examine tombstone") == 0 || strcmp(chosen_action, "look at tombstone") == 0 || strcmp(chosen_action, "investigate tombstone") == 0 || strcmp(chosen_action, "view tombstone") == 0) {
		if (actions[ALL_BOOKS_PLACED]) {
			printf("The tombstone reads 'R.I.P.'...\nWait, what?! It says 'R.I.P. %s :3'!\n\n", name);
		} else {
			printf("There is no tombstone here...\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go north into the mansion.\n\n");
		*current_location = MANSION1;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("Boulders block the way back into the cavern, you can't go back.\n\n");
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION1(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[GET_GREEN_BOOK]) {
		printf("There are two potted plants here, a LEFT PLANT and a RIGHT PLANT. There are doors to the NORTH, EAST, WEST, and SOUTH.\n\n");
	} else {
		printf("There are two potted plants here, a LEFT PLANT that has been uprooted, and a RIGHT PLANT. There are doors to the NORTH, EAST, WEST, and SOUTH.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check left plant") == 0 || strcmp(chosen_action, "examine left plant") == 0 || strcmp(chosen_action, "look at left plant") == 0 || strcmp(chosen_action, "investigate left plant") == 0 || strcmp(chosen_action, "view left plant") == 0) {
		if (!actions[GET_GREEN_BOOK]) {
			printf("It looks like it may have been recently replanted, there is soil around the pot.\n\n");
		} else {
			printf("The plant looks like a mess after you pulled it out of its pot.\n\n");
		}
	} else if (strcmp(chosen_action, "check right plant") == 0 || strcmp(chosen_action, "examine right plant") == 0 || strcmp(chosen_action, "look at right plant") == 0 || strcmp(chosen_action, "investigate right plant") == 0 || strcmp(chosen_action, "view right plant") == 0) {
		printf("There doesn't appear to be anything unusual about this plant or the pot it is in.\n\n");
	} else if (strcmp(chosen_action, "pull left plant") == 0 || strcmp(chosen_action, "tug left plant") == 0 || strcmp(chosen_action, "yank left plant") == 0) {
		if (!actions[GET_GREEN_BOOK]) {
			printf("You pull the plant out of its pot.\nUnderneath it amongst the soil is a green book!\nYou take the green book.\n\n");
			actions[GET_GREEN_BOOK] = 1;
		} else {
			printf("You already pulled the plant out of its pot!\n\n");
		}
	} else if (strcmp(chosen_action, "pull right plant") == 0 || strcmp(chosen_action, "tug right plant") == 0 || strcmp(chosen_action, "yank right plant") == 0) {
		printf("You grab onto the right plant to pull it out...\nBut, it suddenly changes shape into a rabid, drooling monster of a plant!\nYou try to run away, but it lashes out and bites onto you.\nAs it devours you, you feel the burn of acid digesting your body as your life fades away.\nGAME OVER\n\n");
		return 0;
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go through the north door.\n\n");
		*current_location = MANSION13;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go eastward through the door.\n\n");
		*current_location = MANSION2;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You open the west door and go through.\n\n");
		*current_location = MANSION7;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You leave the mansion.\n\n");
		*current_location = OUTSIDE_MANSION;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION2(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[SEEN_GHOST1]) {
		printf("You walk into the room and see someone busy at their desk pouring through several books.\nYou start walking towards them to speak to them, when they suddenly vanish with their books!\nThere are doors leading out of this room to the NORTH, EAST, and WEST.\n\n");
		actions[SEEN_GHOST1] = 1;
	} else {
		printf("There is an empty DESK in this room.\nThere are doors leading out of this room to the NORTH, EAST, and WEST.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check desk") == 0 || strcmp(chosen_action, "examine desk") == 0 || strcmp(chosen_action, "look at desk") == 0 || strcmp(chosen_action, "investigate desk") == 0 || strcmp(chosen_action, "view desk") == 0) {
		printf("You look all around the desk but see nothing that stands out about it.\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go through the north door.\n\n");
		*current_location = MANSION4;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go through the door to the east.\n\n");
		*current_location = MANSION3;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head west through a door back to the first room.\n\n");
		*current_location = MANSION1;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION3(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[GET_BLUE_BOOK]) {
		printf("There is a BLUE BOOK with a bear on the cover sitting on a table.\n");
	} else if (actions[GET_BLUE_BOOK] && !actions[PLACE_STUFFED_BEAR]) {
		printf("There is an empty table in the middle of the room.\n");
	} else if (actions[GET_BLUE_BOOK] && actions[PLACE_STUFFED_BEAR]) {
		printf("There is a stuffed bear sitting in the middle of a table.\n");
	}
	if (!actions[CHECK_PORTRAIT1] && actions[PORTRAIT1_ACTIVE]) {
		printf("In the corner of the room, there is a PORTRAIT of a girl holding a stuffed bear.\nIt almost feels like she's staring at you...\n");
	} else {
		printf("In the corner of the room, there is an empty PORTRAIT in an intricately carved frame.\n");
	}	
	printf("The only exit is to the WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "get blue book") == 0 || strcmp(chosen_action, "pick up blue book") == 0 || strcmp(chosen_action, "grab blue book") == 0 || strcmp(chosen_action, "take blue book") == 0 || strcmp(chosen_action, "acquire blue book") == 0 || strcmp(chosen_action, "obtain blue book") == 0) {
		if (!actions[GET_BLUE_BOOK]) {
			printf("You take the blue book from the table.\nYou hear the voice of a girl:\n'I won't let you take my bear, unless you want to join me forever...'\nYou hear laughter that makes your hair stand on end.\n\n");
			actions[GET_BLUE_BOOK] = 1;
		} else {
			printf("You already got the blue book!\n\n");
		}
	} else if (strcmp(chosen_action, "place blue book") == 0 || strcmp(chosen_action, "set blue book") == 0 || strcmp(chosen_action, "put blue book") == 0) {
		if (!actions[PLACE_STUFFED_BEAR] && actions[GET_BLUE_BOOK]) {
			printf("You place the blue book back on the table.\nYou hear a girls's voice: 'Ah, that's no fun!'\n\n");
			actions[GET_BLUE_BOOK] = 0;
		} else if (actions[PLACE_STUFFED_BEAR] && actions[GET_BLUE_BOOK]) {
			printf("There is no need to put that there now...\n\n");
		} else if (!actions[GET_BLUE_BOOK]) {
			printf("You don't have the blue book!\n\n");
		}
	} else if (strcmp(chosen_action, "place stuffed bear") == 0 || strcmp(chosen_action, "set stuffed bear") == 0 || strcmp(chosen_action, "put stuffed bear") == 0) {
		if (!actions[PLACE_STUFFED_BEAR] && actions[GET_STUFFED_BEAR]) {
			printf("You place the stuffed bear on the table.\nYou hear a girls's voice: 'Beary, you came back to me!'\n\n");
			actions[PLACE_STUFFED_BEAR] = 1;
		} else if (!actions[PLACE_STUFFED_BEAR] && !actions[GET_STUFFED_BEAR]) {
			printf("You don't have a stuffed bear!\n\n");
		} else if (actions[PLACE_STUFFED_BEAR]) {
			printf("You already placed the stuffed bear on the table!\n\n");
		}
	} else if (strcmp(chosen_action, "check portrait") == 0 || strcmp(chosen_action, "examine portrait") == 0 || strcmp(chosen_action, "look at portrait") == 0 || strcmp(chosen_action, "investigate portrait") == 0 || strcmp(chosen_action, "view portrait") == 0) {
		if (!actions[CHECK_PORTRAIT1] && actions[PORTRAIT1_ACTIVE]) {
			printf("You start to inspect the portrait of the girl, when it suddenly fades away!\nYou hear some bone-chilling laughter!\nThere is just an empty black canvas where the painting was.\n\n");
			actions[CHECK_PORTRAIT1] = 1;
			actions[PORTRAIT2_ACTIVE] = 1; 
		} else {
			printf("The portrait is just black.\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		if (actions[GET_BLUE_BOOK] && !actions[PLACE_STUFFED_BEAR]) {
			printf("You go through the door, only to be swallowed by darkness!\nYou hear a voice say: 'Since I don't have my beary, I can play with you forever instead!'\nFollowed by the laughter of a young girl that sounded quite sinister.\nGAME OVER\n\n");
			return 0;
		} else {
			printf("You go west through the only exit.\n\n");
			*current_location = MANSION2;
		}
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION4(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[CHECK_PORTRAIT3] && actions[PORTRAIT3_ACTIVE]) {
		printf("On the left of the room, there is a PORTRAIT of a man holding a book.\nSomething about it just creeps you out...\n");
	} else {
		printf("On the left of the room, there is an empty PORTRAIT in quite the fancy frame.\n");
	}	
	printf("The room is covered in dust and cobwebs.\nThe only exits are to the EAST and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check portrait") == 0 || strcmp(chosen_action, "examine portrait") == 0 || strcmp(chosen_action, "look at portrait") == 0 || strcmp(chosen_action, "investigate portrait") == 0 || strcmp(chosen_action, "view portrait") == 0) {
		if (!actions[CHECK_PORTRAIT3] && actions[PORTRAIT3_ACTIVE]) {
			printf("You examine the painting, but then it suddenly fades away!\nYou hear real deep laughter!\nThere is just an empty black canvas there now.\n\n");
			actions[CHECK_PORTRAIT3] = 1;
			actions[PORTRAIT4_ACTIVE] = 1; 
		} else {
			printf("The portrait is just black.\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go through the door to the east.\n\n");
		*current_location = MANSION5;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You head south through a door.\n\n");
		*current_location = MANSION2;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION5(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[CHECK_PORTRAIT5] && actions[PORTRAIT5_ACTIVE]) {
		printf("There is a PORTRAIT of a family of four.\nIt almost feels like their eyes follow your movements...\nThe only exit is to the WEST, though there are small footprints in the dust leading up to the EAST wall.\n\n");
	} else if (!actions[CHECK_PORTRAIT5] && !actions[PORTRAIT5_ACTIVE]) {
		printf("There is an empty, black PORTRAIT on the EAST wall with a heavily ornate frame around it.\nThe only exit is to the WEST, though there are small footprints in the dust leading up to the EAST wall.\n\n");
	} else {
		printf("There is a door to the WEST, and an opening to the EAST.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check portrait") == 0 || strcmp(chosen_action, "examine portrait") == 0 || strcmp(chosen_action, "look at portrait") == 0 || strcmp(chosen_action, "investigate portrait") == 0 || strcmp(chosen_action, "view portrait") == 0) {
		if (!actions[CHECK_PORTRAIT5] && actions[PORTRAIT5_ACTIVE]) {
			printf("You view the painting up close when all of a sudden it fades away to black!\nYou hear a group of laughter, then the entire portrait disappears!\nThere is an opening there now, it appears to lead into another room.\n\n");
			actions[CHECK_PORTRAIT5] = 1;
		} else {
			printf("The portrait isn't there anymore.\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go back through the door to the west.\n\n");
		*current_location = MANSION4;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		if (!actions[CHECK_PORTRAIT5]) {
			printf("There is no way to go in the east!\n\n");
		} else {
			printf("You go through the opening to the east.\n\n");
			*current_location = MANSION6;
		}
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION6(char name[], int *current_location, bool actions[], int *coins) {
	printf("You enter what appears to be a kids room, with toys scattered about everywhere.\n");
	if (!actions[GET_STUFFED_BEAR]) {
		printf("You notice a STUFFED BEAR sitting on a small chair.\n");
	}
	if (!actions[GET_BLACK_BOOK]) {
		printf("There is a BLACK BOOK on top of some shelves.\n");
	}
	printf("The only way out of here is to the WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "get stuffed bear") == 0 || strcmp(chosen_action, "pick up stuffed bear") == 0 || strcmp(chosen_action, "grab stuffed bear") == 0 || strcmp(chosen_action, "take stuffed bear") == 0 || strcmp(chosen_action, "acquire stuffed bear") == 0 || strcmp(chosen_action, "obtain stuffed bear") == 0) {
		if (!actions[GET_STUFFED_BEAR]) {
			printf("You grab the stuffed bear from the chair.\n\n");
			actions[GET_STUFFED_BEAR] = 1;
		} else {
			printf("You already grabbed the stuffed bear!\n\n");
		}
	} else if (strcmp(chosen_action, "get black book") == 0 || strcmp(chosen_action, "pick up black book") == 0 || strcmp(chosen_action, "grab black book") == 0 || strcmp(chosen_action, "take black book") == 0 || strcmp(chosen_action, "acquire black book") == 0 || strcmp(chosen_action, "obtain black book") == 0) {
		if (!actions[GET_BLACK_BOOK]) {
			printf("You get the black book from the top of the shelves.\n\n");
			actions[GET_BLACK_BOOK] = 1;
		} else {
			printf("You got the black book already!\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You leave the room out the only exit.\n\n");
		*current_location = MANSION5;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION7(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[CHECK_PORTRAIT2] && actions[PORTRAIT2_ACTIVE]) {
		printf("In one corner of the room, there is a PORTRAIT of a boy sitting at a piano.\nYou can almost swear you hear the piano, maybe from somewhere else...\n");
	} else {
		printf("In one corner of the room, there is an empty PORTRAIT surrounded by a detailed frame.\n");
	}	
	printf("The room is covered in dust and cobwebs.\nThe exits from the room are to the NORTH and EAST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check portrait") == 0 || strcmp(chosen_action, "examine portrait") == 0 || strcmp(chosen_action, "look at portrait") == 0 || strcmp(chosen_action, "investigate portrait") == 0 || strcmp(chosen_action, "view portrait") == 0) {
		if (!actions[CHECK_PORTRAIT2] && actions[PORTRAIT2_ACTIVE]) {
			printf("You step up to the portrait, only to see it disappear suddenly!\nYou hear what sounds like someone slamming the keys of a piano, then disturbing laughter!\nThere is just an empty black canvas there now.\n\n");
			actions[CHECK_PORTRAIT2] = 1;
			actions[PORTRAIT3_ACTIVE] = 1; 
		} else {
			printf("The portrait is just black.\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go through the door to the north.\n\n");
		*current_location = MANSION8;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You open the east door and step through.\n\n");
		*current_location = MANSION1;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION8(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[DESK_MOVED]) {
		printf("A DESK sits against one wall of the room.\n");
	} else {
		printf("The DESK is out of the way, revealing a HOLE in the wall.\n");
	}
	printf("The ways out of this room are to the WEST and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check desk") == 0 || strcmp(chosen_action, "examine desk") == 0 || strcmp(chosen_action, "look at desk") == 0 || strcmp(chosen_action, "investigate desk") == 0 || strcmp(chosen_action, "view desk") == 0) {
		printf("You examine the desk.\nThere is something scratched onto it's surface, reading 'I'M WATCHING YOU', creepy.\nThere appears to be gashes on the floor right next to it.\n\n");
	} else if (strcmp(chosen_action, "move desk") == 0 || strcmp(chosen_action, "push desk") == 0 || strcmp(chosen_action, "shove desk") == 0) {
		if (!actions[DESK_MOVED]) {
			printf("You push on the desk, moving it out of the way.\n\n");
			actions[DESK_MOVED] = 1;
		} else {
			printf("You already moved the desk out of the way!\n\n");
		}
	} else if (strcmp(chosen_action, "check hole") == 0 || strcmp(chosen_action, "examine hole") == 0 || strcmp(chosen_action, "look at hole") == 0 || strcmp(chosen_action, "investigate hole") == 0 || strcmp(chosen_action, "view hole") == 0) {
		if (!actions[GET_RED_BOOK]) {
			printf("You look in the hole, and find a red book.\nYou pick it up out of there.\n\n");
			actions[GET_RED_BOOK] = 1;
		} else {
			printf("You check the hole, but there is nothing else in there.\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west into another room.\n\n");
		*current_location = MANSION9;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go into the next room.\n\n");
		*current_location = MANSION7;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION9(char name[], int *current_location, bool actions[], int *coins) {
	printf("There is a FIREPLACE in this room, along with some exquisite, old FURNITURE.\nThere are also some loose FLOORBOARDS in one corner of the room.\nDoors lie to the EAST and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check fireplace") == 0 || strcmp(chosen_action, "examine fireplace") == 0 || strcmp(chosen_action, "look at fireplace") == 0 || strcmp(chosen_action, "investigate fireplace") == 0 || strcmp(chosen_action, "view fireplace") == 0) {
		printf("The fireplace looks like it hasn't been lit for a very long time, there are cobwebs in it.\n\n");
	} else if (strcmp(chosen_action, "check furniture") == 0 || strcmp(chosen_action, "examine furniture") == 0 || strcmp(chosen_action, "look at furniture") == 0 || strcmp(chosen_action, "investigate furniture") == 0 || strcmp(chosen_action, "view furniture") == 0) {
		printf("The furniture looks very high quality, though covered in dust.\nYou don't find anything amongst it, though.\n\n");
	} else if (strcmp(chosen_action, "check floorboards") == 0 || strcmp(chosen_action, "examine floorboards") == 0 || strcmp(chosen_action, "look at floorboards") == 0 || strcmp(chosen_action, "investigate floorboards") == 0 || strcmp(chosen_action, "view floorboards") == 0) {
		printf("You try to pry up the floorboards, but they won't budge.\n\n");
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You leave the room to the east.\n\n");
		*current_location = MANSION8;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go through the door to the south.\n\n");
		*current_location = MANSION10;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION10(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[SEEN_GHOST2]) {
		printf("A woman holding an umbrella almost seems to glide across the room.\nShe disappears behind some CURTAINS.\n");
		actions[SEEN_GHOST2] = 1;
	}
	printf("The CURTAINS over a window appear to be shaking.\nThere is a door to the NORTH, and stairs leading down to the SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check curtains") == 0 || strcmp(chosen_action, "examine curtains") == 0 || strcmp(chosen_action, "look at curtains") == 0 || strcmp(chosen_action, "investigate curtains") == 0 || strcmp(chosen_action, "view curtains") == 0) {
		printf("You pull back the curtains, only to find nothing!\nThere is just a window that you can't see out of due to all the overgrown plants outside it.\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go back north.\n\n");
		*current_location = MANSION9;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south down a flight of stairs, hearing what sounds like music.\n\n");
		*current_location = MANSION11;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION11(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[CHECK_PORTRAIT4] && actions[PORTRAIT4_ACTIVE]) {
		printf("In this room is a PORTRAIT of a woman holding an umbrella.\nYou must be imagining things, but it seems to move every time you look away from it!\n");
	} else {
		printf("In this room, there is an empty PORTRAIT in a golden frame.\n");
	}	
	printf("Cobwebs hang from the ceiling.\nThere is also a PIANO in the center of the room.\nNORTH is back upstairs, while EAST leads down further stairs.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check portrait") == 0 || strcmp(chosen_action, "examine portrait") == 0 || strcmp(chosen_action, "look at portrait") == 0 || strcmp(chosen_action, "investigate portrait") == 0 || strcmp(chosen_action, "view portrait") == 0) {
		if (!actions[CHECK_PORTRAIT4] && actions[PORTRAIT4_ACTIVE]) {
			printf("You examine the portrait and find nothing odd.\nYou start to turn around, but upon hearing a cackle of laughter, you turn back around to find the painting gone!\nThere is just an empty black canvas there now.\n\n");
			actions[CHECK_PORTRAIT4] = 1;
			actions[PORTRAIT5_ACTIVE] = 1; 
		} else {
			printf("The portrait is just black.\n\n");
		}
	} else if (strcmp(chosen_action, "check piano") == 0 || strcmp(chosen_action, "examine piano") == 0 || strcmp(chosen_action, "look at piano") == 0 || strcmp(chosen_action, "investigate piano") == 0 || strcmp(chosen_action, "view piano") == 0) {
		printf("You take a closer look at the piano, when it suddenly starts to play seemingly on its own!\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go back up the stairs to the north.\n\n");
		*current_location = MANSION10;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go down more stairs to the east.\n\n");
		*current_location = MANSION12;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION12(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[LIT_CANDLES]) {
		printf("The room is almost completely dark.\nAll you can see are some unlit CANDLES on the wall on either side of the entrance.\n");
	} else if (!actions[GET_WHITE_BOOK]) {
		printf("There is water dripping from parts of the ceiling in this room.\nThere are lit candles on either side of the entrance.\nA lot of the furniture looks trashed from water damage.\nThere is a WHITE BOOK sitting open on a side table next to a musty sofa.\n");
	} else {
		printf("There is water dripping from parts of the ceiling in this room.\nA lot of the furniture looks trashed from water damage.\nThere is a musty sofa.\nThe whole room smells of mildew.\n");
	}
	printf("The only way out of here is back up the stairs to the WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "light candles") == 0) {
		if (!actions[LIT_CANDLES]) {
			printf("You want to light the candles, but with what?\n\n");
		} else {
			printf("The candles are already lit!\n\n");
		}
	} else if (strcmp(chosen_action, "light candles with flint") == 0) {
		if (!actions[LIT_CANDLES]) {
			printf("You use the flint to light the candles.\nUpon igniting the last one, the flint crumbled apart.\nRest in pieces, trusty flint rock...\n\n");
			actions[LIT_CANDLES] = 1;
		} else {
			printf("You already got the candles going!\n\n");
		}
	} else if (strcmp(chosen_action, "get white book") == 0 || strcmp(chosen_action, "pick up white book") == 0 || strcmp(chosen_action, "grab white book") == 0 || strcmp(chosen_action, "take white book") == 0 || strcmp(chosen_action, "acquire white book") == 0 || strcmp(chosen_action, "obtain white book") == 0) {
		if (!actions[GET_WHITE_BOOK] && actions[LIT_CANDLES]) {
			printf("You take the white book.\n\n");
			actions[GET_WHITE_BOOK] = 1;
		} else if (!actions[GET_WHITE_BOOK] && !actions[LIT_CANDLES]) {
			printf("You don't know if anything is in this room, it's too dark!\n\n");
		} else if (actions[GET_WHITE_BOOK]) {
			printf("You got the white book already!\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head back up the stairs out of this room.\n\n");
		*current_location = MANSION11;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_MANSION13(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[ALL_BOOKS_PLACED]) {
		printf("The room is packed with shelves full of books.\nYou notice there is a set of shelves in the middle that appears to be organized by color.\nThere are some books that seem to be missing there.\n");
		if (!actions[PLACE_RED_BOOK]) {
			printf("A RED BOOK appears to be missing from the top shelf.\n");
		}
		if (!actions[PLACE_BLUE_BOOK]) {
			printf("The BLUE BOOK shelf has an empty spot.\n");
		}
		if (!actions[PLACE_GREEN_BOOK]) {
			printf("There seems to be one GREEN BOOK missing from the third shelf.\n");
		}
		if (!actions[PLACE_BLACK_BOOK]) {
			printf("The fourth shelf looks like it needs one more BLACK BOOK.\n");
		}
		if (!actions[PLACE_WHITE_BOOK]) {
			printf("There might be a book missing on the bottom shelf, a WHITE BOOK.\n");
		}
	} else {
		printf("The room is packed with shelves full of books.\nNow that the middle bookshelf is gone, you only see a lavender POTION sitting on a lone table in a tiny room.\n");
	}
	printf("To the SOUTH is the way back to the first room of the mansion.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "place red book") == 0 || strcmp(chosen_action, "set red book") == 0 || strcmp(chosen_action, "put red book") == 0) {
		if (!actions[PLACE_RED_BOOK] && actions[GET_RED_BOOK]) {
			printf("You put the red book in its respective place.\n\n");
			actions[PLACE_RED_BOOK] = 1;
		} else if (!actions[PLACE_RED_BOOK] && !actions[GET_RED_BOOK]) {
			printf("You don't have a red book!\n\n");
		} else if (actions[PLACE_RED_BOOK]) {
			printf("You already placed the red book!\n\n");
		}
	} else if (strcmp(chosen_action, "place blue book") == 0 || strcmp(chosen_action, "set blue book") == 0 || strcmp(chosen_action, "put blue book") == 0) {
		if (!actions[PLACE_BLUE_BOOK] && actions[GET_BLUE_BOOK]) {
			printf("You put the blue book in the empty spot.\n\n");
			actions[PLACE_BLUE_BOOK] = 1;
		} else if (!actions[PLACE_BLUE_BOOK] && !actions[GET_BLUE_BOOK]) {
			printf("You don't have a blue book!\n\n");
		} else if (actions[PLACE_BLUE_BOOK]) {
			printf("You already placed the blue book!\n\n");
		}
	} else if (strcmp(chosen_action, "place green book") == 0 || strcmp(chosen_action, "set green book") == 0 || strcmp(chosen_action, "put green book") == 0) {
		if (!actions[PLACE_GREEN_BOOK] && actions[GET_GREEN_BOOK]) {
			printf("You placed the green book on the third shelf.\n\n");
			actions[PLACE_GREEN_BOOK] = 1;
		} else if (!actions[PLACE_GREEN_BOOK] && !actions[GET_GREEN_BOOK]) {
			printf("You don't have a green book!\n\n");
		} else if (actions[PLACE_GREEN_BOOK]) {
			printf("You already placed the green book!\n\n");
		}
	} else if (strcmp(chosen_action, "place black book") == 0 || strcmp(chosen_action, "set black book") == 0 || strcmp(chosen_action, "put black book") == 0) {
		if (!actions[PLACE_BLACK_BOOK] && actions[GET_BLACK_BOOK]) {
			printf("You fit the black book neatly into its spot.\n\n");
			actions[PLACE_BLACK_BOOK] = 1;
		} else if (!actions[PLACE_BLACK_BOOK] && !actions[GET_BLACK_BOOK]) {
			printf("You don't have a black book!\n\n");
		} else if (actions[PLACE_BLACK_BOOK]) {
			printf("You already placed the black book!\n\n");
		}
	} else if (strcmp(chosen_action, "place white book") == 0 || strcmp(chosen_action, "set white book") == 0 || strcmp(chosen_action, "put white book") == 0) {
		if (!actions[PLACE_WHITE_BOOK] && actions[GET_WHITE_BOOK]) {
			printf("You take the white book and put it into the bottom shelf.\n\n");
			actions[PLACE_WHITE_BOOK] = 1;
		} else if (!actions[PLACE_WHITE_BOOK] && !actions[GET_WHITE_BOOK]) {
			printf("You don't have a white book!\n\n");
		} else if (actions[PLACE_WHITE_BOOK]) {
			printf("You already placed the white book!\n\n");
		}
	} else if (strcmp(chosen_action, "drink potion") == 0 || strcmp(chosen_action, "swallow potion") == 0 || strcmp(chosen_action, "gulp down potion") == 0 || strcmp(chosen_action, "consume potion") == 0 || strcmp(chosen_action, "down potion") == 0) {
		if (!actions[ALL_BOOKS_PLACED]) {
			printf("There isn't any potion to drink!\n\n");
		} else {
			printf("You grab the potion and uncap it.\nIt smells sweet, so you gulp it down easily.\nYou begin to grow!\nThe tiny room with the table can no longer contain you as you grow.\nFirst the room, then the rest of the mansion smashes apart as you grow back to your original size.\nLooking down, the mansion now looks like a tattered doll house.\n\n");
			*current_location = GROWN1;
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You head back to the first room of the mansion.\n\n");
		*current_location = MANSION1;
	} else {
		printInvalid();
	}
	if (!actions[ALL_BOOKS_PLACED] && actions[PLACE_RED_BOOK] && actions[PLACE_BLUE_BOOK] && actions[PLACE_GREEN_BOOK] && actions[PLACE_BLACK_BOOK] && actions[PLACE_WHITE_BOOK]) {
		printf("You finish placing all the books on the shelves.\nMuch to your surprise the bookshelf in its entirety fades away!\nThere is a tiny room on the other side!\n\n");
		actions[ALL_BOOKS_PLACED] = 1;
	}

	return 1;
}

bool room_GROWN1(char name[], int *current_location, bool actions[], int *coins) {
	printf("There is a castle off in the distance to the NORTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You head north towards the castle.\n\n");
		*current_location = CASTLE1;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE1(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[MURDER_SOLVED]) {
		printf("You come up to the castle. There are vines growing up its sides, but the rest looks well-maintained.\nThe entrance is to the NORTH.\n\n");
	} else {
		printf("You come up to the castle. There are vines growing up its sides, but the rest looks well-maintained.\nThere are tombstones out here with freshly dug graves.\nOne reads 'R.I.P. Prince Albert', the other 'R.I.P. Alfonz the Alchemist'.\nThe entrance is to the NORTH.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You open the front door to the castle and enter.\n\n");
		*current_location = CASTLE2;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("There is no point in heading back.\n\n");
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE2(char name[], int *current_location, bool actions[], int *coins) {
	printf("GUARDS are on either side of the door on the inside of the castle.\nThere is a set of CANDLESTICKS on the wall, illuminating the room.\nThere are stairs leading downward to the NORTH, and doorways to the EAST and WEST.\nThe exit is to the SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "talk to guards") == 0 || strcmp(chosen_action, "speak to guards") == 0 || strcmp(chosen_action, "chat with guards") == 0 || strcmp(chosen_action, "talk with guards") == 0 || strcmp(chosen_action, "converse with guards") == 0) {
		if (!actions[PRINCE_MURDERED]) {
			printf("GUARDS: If you have business with the King, make it quick, he's very busy!\n\n");
		} else if (actions[PRINCE_MURDERED] && !actions[GET_VIAL]) {
			printf("GUARDS: Nobody is allowed to leave, that's the King's orders!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("GUARDS: If you have any evidence that may prove your innocence, you should present it to the King.\n\n");
		} else if (actions[GIVE_VIAL] && !actions[SEEN_JESTER1]) {
			printf("GUARDS: Alfonz the alchemist will be able to determine the poison, make yourself useful in the meantime.\n\n");
		} else if (actions[SEEN_JESTER1] && !actions[ALCHEMIST_MURDERED]) {
			printf("GUARDS: Nobody has passed through here except you, your still a suspect!\n\n");
		} else if (actions[ALCHEMIST_MURDERED] && !actions[OPEN_PASSAGEWAY]) {
			printf("GUARDS: Now Alfonz too? Try anything suspicious and we will have to lock you up!\n\n");
		} else if (actions[OPEN_PASSAGEWAY] && !actions[SEEN_PASSAGEWAY]) {
			printf("GUARDS: A hidden passage? Where does it lead?\n\n");
		} else if (actions[SEEN_PASSAGEWAY] && !actions[GET_BELL]) {
			printf("GUARDS: In all our years of service in this castle, we had no idea such a place was hidden in it...\n\n");
		} else if (actions[GET_BELL] && !actions[SEEN_JESTER2]) {
			printf("GUARDS: You found a bell? What of it?\n\n");
		} else if (actions[SEEN_JESTER2] && !actions[GIVE_BELL]) {
			printf("GUARDS: Sounds suspicious, better bring it up to the King.\n\n");
		} else if (actions[GIVE_BELL] && !actions[HEARD_CONVERSATION]) {
			printf("GUARDS: You may be cleared of being a suspect, but nobody is to leave the castle until this situation is fully resolved.\n\n");
		} else if (actions[HEARD_CONVERSATION] && !actions[MURDER_SOLVED]) {
			printf("GUARDS: You must be lying, the Princess would never betray her own family!\n\n");
		} else if (actions[MURDER_SOLVED]) {
			printf("GUARDS: We're speechless over this turn of events.\nAs the King ordered, you may now leave the castle at will.\n\n");
		}
	} else if (strcmp(chosen_action, "give vial") == 0 || strcmp(chosen_action, "present vial") == 0 || strcmp(chosen_action, "provide vial") == 0) {
		if (!actions[GET_VIAL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("GUARDS: You should take that to the King.\n\n");	
		} else if (actions[GIVE_VIAL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "give bell") == 0 || strcmp(chosen_action, "present bell") == 0 || strcmp(chosen_action, "provide bell") == 0) {
		if (!actions[GET_BELL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_BELL] && !actions[GIVE_BELL]) {
			printf("GUARDS: What do you expect us to do with that?\n\n");	
		} else if (actions[GIVE_BELL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "check candlesticks") == 0 || strcmp(chosen_action, "examine candlesticks") == 0 || strcmp(chosen_action, "look at candlesticks") == 0 || strcmp(chosen_action, "investigate candlesticks") == 0 || strcmp(chosen_action, "view candlesticks") == 0) {
		printf("You examine the candlesticks, but notice nothing of importance about them.\n\n");
	} else if (strcmp(chosen_action, "pull candlesticks") == 0 || strcmp(chosen_action, "tug candlesticks") == 0 || strcmp(chosen_action, "yank candlesticks") == 0) {
		printf("You pull on the candlesticks, but they don't budge.\nThe guards give you a concerned look.\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go down the stairs to the north.\n\n");
		*current_location = CASTLE6;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go through the doorway to the east.\n\n");
		*current_location = CASTLE3;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head east through a doorway.\n\n");
		*current_location = CASTLE7;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		if (!actions[PRINCE_MURDERED] || actions[MURDER_SOLVED]) {
			printf("You exit the castle.\n\n");
			*current_location = CASTLE1;
		} else {
			printf("GUARDS: Halt! Nobody is to leave the castle, that is the King's orders!\n\n");
		}
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE3(char name[], int *current_location, bool actions[], int *coins) {
	printf("There are three PAINTINGs on the southern wall, a LEFT, MIDDLE, and RIGHT.\nThe room is lit up by CANDLESTICKS on the wall.\nDoorways are to the NORTH, EAST, and WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check paintings") == 0 || strcmp(chosen_action, "examine paintings") == 0 || strcmp(chosen_action, "look at paintings") == 0 || strcmp(chosen_action, "investigate paintings") == 0 || strcmp(chosen_action, "view paintings") == 0) {
		printf("There are three paintings, which one?\n\n");
	} else if (strcmp(chosen_action, "check left painting") == 0 || strcmp(chosen_action, "examine left painting") == 0 || strcmp(chosen_action, "look at left painting") == 0 || strcmp(chosen_action, "investigate left painting") == 0 || strcmp(chosen_action, "view left painting") == 0) {
		printf("It is a painting of the Prince when he was much younger.\n\n");
	} else if (strcmp(chosen_action, "check middle painting") == 0 || strcmp(chosen_action, "examine middle painting") == 0 || strcmp(chosen_action, "look at middle painting") == 0 || strcmp(chosen_action, "investigate middle painting") == 0 || strcmp(chosen_action, "view middle painting") == 0) {
		printf("It's a portait of the whole Royal Family.\n\n");
	} else if (strcmp(chosen_action, "check right painting") == 0 || strcmp(chosen_action, "examine right painting") == 0 || strcmp(chosen_action, "look at right painting") == 0 || strcmp(chosen_action, "investigate right painting") == 0 || strcmp(chosen_action, "view right painting") == 0) {
		printf("The painting is of the Princess when she was a kid, she's seen playing with a large dollhouse..\n\n");
	} else if (strcmp(chosen_action, "check candlesticks") == 0 || strcmp(chosen_action, "examine candlesticks") == 0 || strcmp(chosen_action, "look at candlesticks") == 0 || strcmp(chosen_action, "investigate candlesticks") == 0 || strcmp(chosen_action, "view candlesticks") == 0) {
		printf("Nothing out of place, the candlesticks light up the room in a soft glow.\n\n");
	} else if (strcmp(chosen_action, "pull candlesticks") == 0 || strcmp(chosen_action, "tug candlesticks") == 0 || strcmp(chosen_action, "yank candlesticks") == 0) {
		printf("You pull on the candlesticks, but they are firmly attached to the wall.\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You hear chatter as you walk into the room to the north.\n\n");
		*current_location = CASTLE4;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		if (!actions[SEEN_PASSAGEWAY]) {
			printf("You head east, but quickly turn back.\nYou were driven away by a terrible odor, that must be the privy.\n\n");
		} else {
			printf("You walk into the privy.\n\n");
			*current_location = CASTLE5;
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head back to the first room of the castle.\n\n");
		*current_location = CASTLE2;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE4(char name[], int *current_location, bool actions[], int *coins) {
	if (actions[GIVE_VIAL] && !actions[SEEN_JESTER1]) {
		printf("You see the Jester returning to the throne room with a guard as escort.\n");
		actions[SEEN_JESTER1] = 1;
	}
	if (!actions[PRINCE_MURDERED]) {
		printf("The throne room is highly decorated with ornate rugs and furniture.\nThe KING, QUEEN, PRINCE, PRINCESS, and JESTER are all eating at a table while the GUARD and SERVANT stands near them on call.\n");
	} else if (!actions[GIVE_BELL] && !actions[MURDER_SOLVED]) {
		printf("The throne room is highly decorated with ornate rugs and furniture.\nThe KING, QUEEN, and PRINCESS are sitting on their respective thrones.\nThe JESTER, GUARD, and SERVANT are standing there on either side of the thrones.\n");
	} else if (actions[GIVE_BELL] && !actions[MURDER_SOLVED]) {
		printf("The throne room is highly decorated with ornate rugs and furniture.\nThe KING and QUEEN are sitting on their respective thrones.\nThe GUARD and SERVANT are standing there on either side of the thrones.\n");
	} else if (actions[MURDER_SOLVED]) {
		printf("The throne room is highly decorated with ornate rugs and furniture.\nThe KING and QUEEN are sitting on their respective thrones.\nThe GUARD is standing to the right of the thrones.\n");
	}
	printf("The exit is to the SOUTH, there is also a finely carved wooden door to the EAST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "talk to prince") == 0 || strcmp(chosen_action, "speak to prince") == 0 || strcmp(chosen_action, "chat with prince") == 0 || strcmp(chosen_action, "talk with prince") == 0 || strcmp(chosen_action, "converse with prince") == 0) {
		if (!actions[PRINCE_MURDERED]) {
			printf("PRINCE: Meat is the best dinner there is!\nOh, the north door, yes, the King will likely grant you permission to leave through there.\n\n");
		} else {
			printf("The prince is dead!\n\n");
		}
	} else if (strcmp(chosen_action, "talk to king") == 0 || strcmp(chosen_action, "speak to king") == 0 || strcmp(chosen_action, "chat with king") == 0 || strcmp(chosen_action, "talk with king") == 0 || strcmp(chosen_action, "converse with king") == 0) {
		if (!actions[PRINCE_MURDERED]) {
			//Activate scene prince murdered
			printf("KING: Yes, I can give you permission to...\nSuddenly the Prince slumps over face first onto his dinner plate!\nKING: Everyone cease eating at once, the meat is tainted!\nEveryone is in a panic, as the guard determines that the Prince is in fact, dead.\nKING: Nobody is to leave the castle until we find who did this!\nKING: Everyone is a suspect, no exceptions!\n\n");
			actions[PRINCE_MURDERED] = 1;
		} else if (actions[PRINCE_MURDERED] && !actions[GET_VIAL]) {
			printf("KING: You arrived here just when this happens.\nIf you want your name cleared, I suggest you find out the real culprit.\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("KING: You found something? Give it to me!\n\n");
		} else if (actions[SEEN_JESTER1] && !actions[ALCHEMIST_MURDERED]) {
			printf("KING: I'm sure Alfonz will figure this all out, he comes from long generation of alchemists that have served this family.\n\n");
		} else if (actions[ALCHEMIST_MURDERED] && !actions[OPEN_PASSAGEWAY]) {
			printf("KING: What?! What do you mean Alfonz was murdered as well?!\n\n");
		} else if (actions[OPEN_PASSAGEWAY] && !actions[SEEN_PASSAGEWAY]) {
			printf("KING: You say there is a passage hidden in the alchemist's study?\nWhere does it lead to?\n\n");
		} else if (actions[SEEN_PASSAGEWAY] && !actions[GET_BELL]) {
			printf("KING: The passage leads to the privy?\nAnyone could have snuck through there and did this, I need more solid proof.\n\n");
		} else if (actions[GET_BELL] && !actions[SEEN_JESTER2]) {
			printf("KING: You found something in the passage? What is it?\n\n");
		} else if (actions[SEEN_JESTER2] && !actions[GIVE_BELL]) {
			printf("KING: What is this you say? Give this to me at once!\n\n");
		} else if (actions[GIVE_BELL] && !actions[HEARD_CONVERSATION]) {
			printf("KING: The Jester was a trusted individual, I can't believe he would do such a thing.\nWe still need something more to go on to prove the Prince's murder, and the Jester won't admit anything.\n\n");
		} else if (actions[HEARD_CONVERSATION] && !actions[MURDER_SOLVED]) {
			//Doesn't believe, but servant admits to everything
			printf("KING: You say my daughter is the one behind all this?! Bah! Such lies!\nThe servant looks nervous, but she speaks up.\nSERVANT: It is true, my lord... I was paid to eliminate not only the Prince, but you and the Queen as well.\nI panicked and dumped the whole vial onto the Prince's dinner, there was no going back.\nKING: I still don't believe any of this!\nSERVANT: It is the truth, here is the bag of gold coins that was given to me as payment!\nThe servant takes out the bag and shows it to the King.\nKING: ... Very well... Guard, seize the Princess and the servant and throw them in the dungeon!\n\n");
			actions[MURDER_SOLVED] = 1;
		} else if (actions[MURDER_SOLVED]) {
			printf("KING: I don't think this day could possibly get any worse.\nYour name is now cleared, and I give you permission to leave the castle at any time.\nIf that is all, please leave me be, I still need time to process all of this.\n\n");
		}
	} else if (strcmp(chosen_action, "talk to queen") == 0 || strcmp(chosen_action, "speak to queen") == 0 || strcmp(chosen_action, "chat with queen") == 0 || strcmp(chosen_action, "talk with queen") == 0 || strcmp(chosen_action, "converse with queen") == 0) {
		if (!actions[PRINCE_MURDERED]) {
			printf("QUEEN: If you need to leave to the north, you must get the King's permission.\n\n");
		} else if (actions[PRINCE_MURDERED] && !actions[GET_VIAL]) {
			printf("QUEEN: You are currently the prime suspect, but the King is giving you a chance to prove your innocence!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("QUEEN: If you have some proof, show it to the King.\n\n");
		} else if (actions[SEEN_JESTER1] && !actions[ALCHEMIST_MURDERED]) {
			printf("QUEEN: It may be a wise choice to talk to others while you wait for Alfonz's verdict.\n\n");
		} else if (actions[ALCHEMIST_MURDERED] && !actions[OPEN_PASSAGEWAY]) {
			printf("QUEEN: Alfonz is dead now too?! The murderer must have thought they may be found out by him!\n\n");
		} else if (actions[OPEN_PASSAGEWAY] && !actions[SEEN_PASSAGEWAY]) {
			printf("QUEEN: I've heard of such a passageway in this castle, but always though it was just a rumor.\n\n");
		} else if (actions[SEEN_PASSAGEWAY] && !actions[GET_BELL]) {
			printf("QUEEN: It goes all the way from the study to the privy? Did you find anything there?\n\n");
		} else if (actions[GET_BELL] && !actions[SEEN_JESTER2]) {
			printf("QUEEN: It may be nothing, but you should show it to the King anyway.\n\n");
		} else if (actions[SEEN_JESTER2] && !actions[GIVE_BELL]) {
			printf("QUEEN: Show it to the King at once!\n\n");
		} else if (actions[GIVE_BELL] && !actions[HEARD_CONVERSATION]) {
			printf("QUEEN: I never would have guessed it would be him, he was always so light-hearted and humorous!\n\n");
		} else if (actions[HEARD_CONVERSATION] && !actions[MURDER_SOLVED]) {
			printf("QUEEN: Lies! My own daughter would never be involved with such a scheme!\n\n");
		} else if (actions[MURDER_SOLVED]) {
			printf("QUEEN: Where did we go wrong? Did we not provide enough for her?\nThis is too much right now...\n\n");
		}
	} else if (strcmp(chosen_action, "talk to princess") == 0 || strcmp(chosen_action, "speak to princess") == 0 || strcmp(chosen_action, "chat with princess") == 0 || strcmp(chosen_action, "talk with princess") == 0 || strcmp(chosen_action, "converse with princess") == 0) {
		if (!actions[PRINCE_MURDERED]) {
			printf("The princess is busy laughing at the Jester's jokes, she ignores you.\n\n");
		} else if (actions[PRINCE_MURDERED] && !actions[GET_VIAL]) {
			printf("PRINCESS: I just lost my brother, and you are highly suspect!\nWhat business do you even have here?\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("PRINCESS: You found something? As if anyone should believe your innocence!\n\n");
		} else if (actions[SEEN_JESTER1] && !actions[ALCHEMIST_MURDERED]) {
			printf("PRINCESS: You should really consider the situation you are in, I don't trust you for a second!\n\n");
		} else if (actions[ALCHEMIST_MURDERED] && !actions[OPEN_PASSAGEWAY]) {
			printf("PRINCESS: Alfonz murdered?! This wasn't... It must have been you!\n\n");
		} else if (actions[OPEN_PASSAGEWAY] && !actions[SEEN_PASSAGEWAY]) {
			printf("PRINCESS: I have never heard of such a thing in this castle.\n\n");
		} else if (actions[SEEN_PASSAGEWAY] && !actions[GET_BELL]) {
			printf("PRINCESS: You're telling me this? That just means you could have definitely done all of this!\n\n");
		} else if (actions[GET_BELL] && !actions[SEEN_JESTER2]) {
			printf("PRINCESS: The proof you claim is laughable, what of it?\n\n");
		} else if (actions[SEEN_JESTER2] && !actions[GIVE_BELL]) {
			printf("PRINCESS: I can't believe that... You liar!\n\n");
		} else if (actions[GIVE_BELL]) {
			printf("The Princess isn't here!\n\n");
		}
	} else if (strcmp(chosen_action, "talk to jester") == 0 || strcmp(chosen_action, "speak to jester") == 0 || strcmp(chosen_action, "chat with jester") == 0 || strcmp(chosen_action, "talk with jester") == 0 || strcmp(chosen_action, "converse with jester") == 0) {
		if (!actions[PRINCE_MURDERED]) {
			printf("JESTER: You need permission to leave the door? Is it your mission to reach the shore? Haha!\n\n");
		} else if (actions[PRINCE_MURDERED] && !actions[GET_VIAL]) {
			printf("JESTER: The Prince was my friend, is this really the end?\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("JESTER: You say you found something to prove your innocence, in a sense? Haha!\n\n");
		} else if (actions[SEEN_JESTER1] && !actions[ALCHEMIST_MURDERED]) {
			printf("JESTER: I came from the privy and feel relief, but the person before me must have had some bad beef! Haha!\n\n");
		} else if (actions[ALCHEMIST_MURDERED] && !actions[OPEN_PASSAGEWAY]) {
			printf("JESTER: ... Is nobody safe here? It seems we all have something to fear!\n\n");
		} else if (actions[OPEN_PASSAGEWAY] && !actions[SEEN_PASSAGEWAY]) {
			printf("JESTER: ... A passageway, you say? If I may, there's no way! Haha!\n\n");
		} else if (actions[SEEN_PASSAGEWAY] && !actions[GET_BELL]) {
			printf("JESTER: ... It leads to the privy? That smells if you ask me! Haha...\n\n");
		} else if (actions[GET_BELL] && !actions[SEEN_JESTER2]) {
			printf("JESTER: Do tell... You found a bell? What lies are you trying to sell? Haha...\n\n");
		} else if (actions[SEEN_JESTER2] && !actions[GIVE_BELL]) {
			printf("JESTER: ...\n\n");
		} else if (actions[GIVE_BELL]) {
			printf("The Jester isn't here!\n\n");
		}
	} else if (strcmp(chosen_action, "talk to guard") == 0 || strcmp(chosen_action, "speak to guard") == 0 || strcmp(chosen_action, "chat with guard") == 0 || strcmp(chosen_action, "talk with guard") == 0 || strcmp(chosen_action, "converse with guard") == 0) {
		if (!actions[PRINCE_MURDERED]) {
			printf("GUARD: You'll have to ask the King if you want to leave to the north.\n\n");
		} else if (actions[PRINCE_MURDERED] && !actions[GET_VIAL]) {
			printf("GUARD: You may go around the castle, but you may not leave!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("GUARD: That seems to be significant, you should give it to the King.\n\n");
		} else if (actions[SEEN_JESTER1] && !actions[ALCHEMIST_MURDERED]) {
			printf("GUARD: That privy needs better ventilation, I couldn't stomach going in there.\n\n");
		} else if (actions[ALCHEMIST_MURDERED] && !actions[OPEN_PASSAGEWAY]) {
			printf("GUARD: Alfonz dead?! The only person to leave this room was the Jester, but I escorted him to the privy myself!\n\n");
		} else if (actions[OPEN_PASSAGEWAY] && !actions[SEEN_PASSAGEWAY]) {
			printf("GUARD: I thought that was just an old rumor, but I guess there is something there.\nWhere does it go?\n\n");
		} else if (actions[SEEN_PASSAGEWAY] && !actions[GET_BELL]) {
			printf("GUARD: Did you see anything that stands out in there?\n\n");
		} else if (actions[GET_BELL] && !actions[SEEN_JESTER2]) {
			printf("GUARD: I'm not sure of the meaning of this...\n\n");
		} else if (actions[SEEN_JESTER2] && !actions[GIVE_BELL]) {
			printf("GUARD: I see... Speak to the King at once!\n\n");
		} else if (actions[GIVE_BELL] && !actions[HEARD_CONVERSATION]) {
			printf("GUARD: I feel ashamed... I escorted him to the privy, but didn't enter due to the horrible odor.\nHad I stronger nerves, Alfonz might still be alive...\n\n");
		} else if (actions[HEARD_CONVERSATION] && !actions[MURDER_SOLVED]) {
			printf("GUARD: There is no way, your ears must have been playing tricks on you!\n\n");
		} else if (actions[MURDER_SOLVED]) {
			printf("GUARD: In all of my years serving this family, I never would have thought such an unspeakable tragedy would occur...\n\n");
		}
	} else if (strcmp(chosen_action, "talk to servant") == 0 || strcmp(chosen_action, "speak to servant") == 0 || strcmp(chosen_action, "chat with servant") == 0 || strcmp(chosen_action, "talk with servant") == 0 || strcmp(chosen_action, "converse with servant") == 0) {
		if (actions[MURDER_SOLVED]) {
			printf("The servant isn't here anymore...\n\n");
		} else {
			printf("Servant: ...\n\n");
		}
	} else if (strcmp(chosen_action, "give vial") == 0 || strcmp(chosen_action, "present vial") == 0 || strcmp(chosen_action, "provide vial") == 0) {
		if (!actions[GET_VIAL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("GIVE VIAL TO whom?\n\n");	
		} else if (actions[GIVE_VIAL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "give vial to king") == 0 || strcmp(chosen_action, "present vial to king") == 0 || strcmp(chosen_action, "provide vial to king") == 0) {
		if (!actions[GET_VIAL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("KING: I see... Take this to Alfonz the alchemist at once, he may be able to determine the poison!\n\n");	
		} else if (actions[GIVE_VIAL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "give vial to queen") == 0 || strcmp(chosen_action, "present vial to queen") == 0 || strcmp(chosen_action, "provide vial to queen") == 0) {
		if (!actions[GET_VIAL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("QUEEN: What's this? The alchemist may be able to do something with this.\n\n");	
		} else if (actions[GIVE_VIAL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "give vial to princess") == 0 || strcmp(chosen_action, "present vial to princess") == 0 || strcmp(chosen_action, "provide vial to princess") == 0) {
		if (!actions[GET_VIAL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("PRINCESS: Where did you find that?! I mean, it looks important...\n\n");	
		} else if (actions[GIVE_VIAL]) {
			printf("You don't have that anymore!\n\n");
		}
	} else if (strcmp(chosen_action, "give vial to jester") == 0 || strcmp(chosen_action, "present vial to jester") == 0 || strcmp(chosen_action, "provide vial to jester") == 0) {
		if (!actions[GET_VIAL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("JESTER: If I lived inside such a vial, my imagination would still be free, haha!\n\n");	
		} else if (actions[GIVE_VIAL]) {
			printf("You don't have that anymore!\n\n");
		}
	} else if (strcmp(chosen_action, "give vial to guard") == 0 || strcmp(chosen_action, "present vial to guard") == 0 || strcmp(chosen_action, "provide vial to guard") == 0) {
		if (!actions[GET_VIAL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("GUARD: This looks like something to show the King or Queen...\n\n");	
		} else if (actions[GIVE_VIAL]) {
			printf("You don't have that anymore!\n\n");
		}
	} else if (strcmp(chosen_action, "give vial to servant") == 0 || strcmp(chosen_action, "present vial to servant") == 0 || strcmp(chosen_action, "provide vial to servant") == 0) {
		if (!actions[GET_VIAL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("SERVANT: ...\n\n");	
		} else if (actions[GIVE_VIAL]) {
			printf("You don't have that anymore!\n\n");
		}
	} else if (strcmp(chosen_action, "give bell") == 0 || strcmp(chosen_action, "present bell") == 0 || strcmp(chosen_action, "provide bell") == 0) {
		if (!actions[GET_BELL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_BELL] && !actions[GIVE_BELL]) {
			printf("GIVE BELL TO whom?\n\n");	
		} else if (actions[GIVE_BELL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "give bell to king") == 0 || strcmp(chosen_action, "present bell to king") == 0 || strcmp(chosen_action, "provide bell to king") == 0) {
		if (!actions[GET_BELL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && !actions[SEEN_JESTER2]) {
			printf("KING: A bell? What of it?\n\n");	
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && actions[SEEN_JESTER2]) {
			printf("KING: You found this in that passageway, and the Jester is missing a bell on his hat?!\nGuard, seize the Jester at once and throw him in the dungeon!\nThe guard grabs the Jester and pulls him out of the room.\nThe guard returns a little while later and confirms the Jester's imprisonment.\nThe Princess leaves the throne room in a hurry.\n\n");
			actions[GIVE_BELL] = 1;	
		} else if (actions[GIVE_BELL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "give bell to queen") == 0 || strcmp(chosen_action, "present bell to queen") == 0 || strcmp(chosen_action, "provide bell to queen") == 0) {
		if (!actions[GET_BELL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && !actions[SEEN_JESTER2]) {
			printf("QUEEN: I don't know what you expect me to do with that?\n\n");	
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && actions[SEEN_JESTER2]) {
			printf("QUEEN: Show this to the King, quickly!\n\n");	
		} else if (actions[GIVE_BELL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "give bell to princess") == 0 || strcmp(chosen_action, "present bell to princess") == 0 || strcmp(chosen_action, "provide bell to princess") == 0) {
		if (!actions[GET_BELL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && !actions[SEEN_JESTER2]) {
			printf("PRINCESS: What is the meaning of this?\n\n");	
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && actions[SEEN_JESTER2]) {
			printf("PRINCESS: That could have come from anyone!\n\n");	
		} else if (actions[GIVE_BELL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "give bell to jester") == 0 || strcmp(chosen_action, "present bell to jester") == 0 || strcmp(chosen_action, "provide bell to jester") == 0) {
		if (!actions[GET_BELL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && !actions[SEEN_JESTER2]) {
			printf("JESTER: Well, well, it is a bell, can't you tell? Haha...\n\n");	
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && actions[SEEN_JESTER2]) {
			printf("JESTER: I don't know what you are talking about, it doesn't ring any bells, haha!\n\n");	
		} else if (actions[GIVE_BELL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "give bell to guard") == 0 || strcmp(chosen_action, "present bell to guard") == 0 || strcmp(chosen_action, "provide bell to guard") == 0) {
		if (!actions[GET_BELL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && !actions[SEEN_JESTER2]) {
			printf("GUARD: This doesn't look significant...\n\n");	
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && actions[SEEN_JESTER2]) {
			printf("GUARD: The King needs to see this, at once!\n\n");	
		} else if (actions[GIVE_BELL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "give bell to servant") == 0 || strcmp(chosen_action, "present bell to servant") == 0 || strcmp(chosen_action, "provide bell to servant") == 0) {
		if (!actions[GET_BELL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && !actions[SEEN_JESTER2]) {
			printf("SERVANT: ... (She looks kind of surprised)\n\n");	
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && actions[SEEN_JESTER2]) {
			printf("SERVANT: ... (She almost looks relieved)\n\n");	
		} else if (actions[GIVE_BELL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "check king") == 0 || strcmp(chosen_action, "examine king") == 0 || strcmp(chosen_action, "look at king") == 0 || strcmp(chosen_action, "investigate king") == 0 || strcmp(chosen_action, "view king") == 0) {
		printf("The King is wearing exquisite clothes, with a tall, gold crown.\n\n");
	} else if (strcmp(chosen_action, "check queen") == 0 || strcmp(chosen_action, "examine queen") == 0 || strcmp(chosen_action, "look at queen") == 0 || strcmp(chosen_action, "investigate queen") == 0 || strcmp(chosen_action, "view queen") == 0) {
		printf("The Queen is dressed in elegant clothing, along with a tall, silver crown adorned with jewels.\n\n");
	} else if (strcmp(chosen_action, "check princess") == 0 || strcmp(chosen_action, "examine princess") == 0 || strcmp(chosen_action, "look at princess") == 0 || strcmp(chosen_action, "investigate princess") == 0 || strcmp(chosen_action, "view princess") == 0) {
		if (!actions[GIVE_BELL]) {
			printf("The Princess is wearing a pink dress, with a small silver crown.\n\n");
		} else {
			printf("The Princess isn't here!\n\n");
		}
	} else if (strcmp(chosen_action, "check prince") == 0 || strcmp(chosen_action, "examine prince") == 0 || strcmp(chosen_action, "look at prince") == 0 || strcmp(chosen_action, "investigate prince") == 0 || strcmp(chosen_action, "view prince") == 0) {
		if (!actions[PRINCE_MURDERED]) {
			printf("The Prince sits at the table devouring the meat on his plate, he has a small gold crown atop his head.\n\n");
		} else {
			printf("The Prince is no longer with us!\n\n");
		}
	} else if (strcmp(chosen_action, "check guard") == 0 || strcmp(chosen_action, "examine guard") == 0 || strcmp(chosen_action, "look at guard") == 0 || strcmp(chosen_action, "investigate guard") == 0 || strcmp(chosen_action, "view guard") == 0) {
		printf("The guard is standing by with a watchful eye, especially focusing on you.\n\n");
	} else if (strcmp(chosen_action, "check jester") == 0 || strcmp(chosen_action, "examine jester") == 0 || strcmp(chosen_action, "look at jester") == 0 || strcmp(chosen_action, "investigate jester") == 0 || strcmp(chosen_action, "view jester") == 0) {
		if (!actions[SEEN_JESTER1]) {
			printf("The Jester is wearing a kind of ridiculous colored outfit, topped with a hat that has four points with bells on the end of them.\n\n");
		} else if (actions[SEEN_JESTER1] && !actions[GET_BELL]) {
			printf("The Jester is wearing a kind of ridiculous colored outfit, topped with a hat that has four points with bells on the end of them.\nWait, one of the bells is missing?\n\n");
		} else if (actions[GET_BELL] && !actions[GIVE_BELL]) {
			printf("The Jester is wearing a kind of ridiculous colored outfit, topped with a hat that has four points with bells on the end of them.\nWait, one of the bells is missing?\nOne of the bells is missing!\n\n");
			actions[SEEN_JESTER2] = 1;
		} else {
			printf("The Jester is no longer here...\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("GUARD: Halt! That door leads to the bedrooms, only the royal family and guards are permitted to enter!\n\n");
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You leave the throne room.\n\n");
		*current_location = CASTLE3;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE5(char name[], int *current_location, bool actions[], int *coins) {
	printf("You are in the privy.\nThere is a CANDLESTICK on the northern wall.\nThe only exit appears to be to the WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check candlestick") == 0 || strcmp(chosen_action, "examine candlestick") == 0 || strcmp(chosen_action, "look at candlestick") == 0 || strcmp(chosen_action, "investigate candlestick") == 0 || strcmp(chosen_action, "view candlestick") == 0) {
		printf("You examine the candlestick, but at a glance there doesn't appear to be anything abnormal about it.\n\n");
	} else if (strcmp(chosen_action, "pull candlestick") == 0 || strcmp(chosen_action, "tug candlestick") == 0 || strcmp(chosen_action, "yank candlestick") == 0) {
		printf("You walk up to the candlestick and pull on it.\nThe wall and floor suddenly, slowly swivels around with the sound of grinding stones!\n\n");
		*current_location = CASTLE13;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You leave the privy.\n\n");
		*current_location = CASTLE3;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE6(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[GIVE_BELL]) {
		printf("You see four cells in a dimly lit room, only one is occupied, by a DRUNK that seems to be singing a song.\nThere are a couple of BARRELS here, along with a CRATE with a loose top.\nThere are CANDLESTICKS along the walls.\n");
	} else if (actions[GIVE_BELL] && !actions[MURDER_SOLVED]) {
		printf("You see four cells in a dimly lit room, one is occupied by a DRUNK that seems to be singing a song.\nThe JESTER is in another cell, and the PRINCESS is here having a CONVERSATION with him.\nThere are a couple of BARRELS here, along with a CRATE with a loose top.\nThere are CANDLESTICKS along the walls.\n");
	} else if (actions[MURDER_SOLVED]) {
		printf("You see four cells in a dimly lit room, one is occupied by a DRUNK that seems to be singing a song.\nThe JESTER, PRINCESS, and the SERVANT are all here in separate cells.\nThere are a couple of BARRELS here, along with a CRATE with a loose top.\nThere are CANDLESTICKS along the walls.\n");
	}
	printf("The only exit is to the SOUTH, back up the stairs.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check crate") == 0 || strcmp(chosen_action, "examine crate") == 0 || strcmp(chosen_action, "look at crate") == 0 || strcmp(chosen_action, "investigate crate") == 0 || strcmp(chosen_action, "view crate") == 0) {
		printf("You open the top of the crate and peer in.\nThere is nothing in there.\n\n");
	} else if (strcmp(chosen_action, "check barrels") == 0 || strcmp(chosen_action, "examine barrels") == 0 || strcmp(chosen_action, "look at barrels") == 0 || strcmp(chosen_action, "investigate barrels") == 0 || strcmp(chosen_action, "view barrels") == 0) {
		if (!actions[PRINCE_MURDERED]) {
			printf("You look inside the barrels, but find nothing.\n\n");
		} else if (actions[PRINCE_MURDERED] && !actions[GET_VIAL]) {
			printf("You look inside the barrels.\nYou find a vial with a small amount of liquid inside it, in one of the barrels.\nYou take the vial.\n\n");
			actions[GET_VIAL] = 1;
		} else if (actions[GET_VIAL]) {
			printf("The barrels are empty.\n\n");
		}
	} else if (strcmp(chosen_action, "check candlesticks") == 0 || strcmp(chosen_action, "examine candlesticks") == 0 || strcmp(chosen_action, "look at candlesticks") == 0 || strcmp(chosen_action, "investigate candlesticks") == 0 || strcmp(chosen_action, "view candlesticks") == 0) {
		printf("Nothing seems out of the ordinary with the candlesticks.\n\n");
	} else if (strcmp(chosen_action, "pull candlesticks") == 0 || strcmp(chosen_action, "tug candlesticks") == 0 || strcmp(chosen_action, "yank candlesticks") == 0) {
		printf("You try to pull the candlesticks, but they won't budge.\n\n");
	} else if (strcmp(chosen_action, "listen to conversation") == 0) {
		if (!actions[GIVE_BELL]) {
			printf("There isn't a conversation going here...\n\n");
		} else if (actions[GIVE_BELL] && !actions[MURDER_SOLVED]) {
			printf("PRINCESS: How could you do such a thing? Please tell me this is a mistake, were you framed?\nJESTER: I didn't do this my lass, please give me a pass! Haha!\nPRINCESS: This isn't the time to be joking! I will find a way to prove your innocence!\n\n");
		} else if (actions[MURDER_SOLVED]) {
			printf("The Jester and Princess are arguing back and forth.\n\n");
		}
	} else if (strcmp(chosen_action, "talk to drunk") == 0 || strcmp(chosen_action, "speak to drunk") == 0 || strcmp(chosen_action, "chat with drunk") == 0 || strcmp(chosen_action, "talk with drunk") == 0 || strcmp(chosen_action, "converse with drunk") == 0) {
		static int ale_count = 99;
		if (ale_count == 0) {
			printf("Wait... Where was I again? We are currently in the depths of stringzzz's imagination? :3\nNo... Wait... Oh yeah, I remember!\n");
			ale_count = 99;
		}
		printf("%d bottles of ale on the wall, %d bottles of ale!\nTake one down, pass it around, %d bottles of ale on the wall!\n\n", ale_count, ale_count, ale_count - 1);
		--ale_count;
	} else if (strcmp(chosen_action, "talk to jester") == 0 || strcmp(chosen_action, "speak to jester") == 0 || strcmp(chosen_action, "chat with jester") == 0 || strcmp(chosen_action, "talk with jester") == 0 || strcmp(chosen_action, "converse with jester") == 0) {
		if (!actions[GIVE_BELL]) {
			printf("The Jester isn't in here!\n\n");
		} else if (actions[GIVE_BELL] && !actions[MURDER_SOLVED]) {
			printf("JESTER: You must have been the one to steal my bell, it's nothing but lies you tell! Haha!\n\n");
		} else if (actions[MURDER_SOLVED]) {
			printf("JESTER: Our whole plot was foiled, the plans only became spoiled! Haha...\nPRINCESS: Shut up, shut up! Between you and that damn drunk in here, SHUT UP!\n\n");
		}
	} else if (strcmp(chosen_action, "talk to princess") == 0 || strcmp(chosen_action, "speak to princess") == 0 || strcmp(chosen_action, "chat with princess") == 0 || strcmp(chosen_action, "talk with princess") == 0 || strcmp(chosen_action, "converse with princess") == 0) {
		if (!actions[GIVE_BELL]) {
			printf("The Princess isn't in here!\n\n");
		} else if (actions[GIVE_BELL] && !actions[MURDER_SOLVED]) {
			printf("PRINCESS: Can't you see I'm busy talking here!\n\n");
		} else if (actions[MURDER_SOLVED]) {
			printf("PRINCESS: Curse you! You ruined everything! I could have become the highest authority in this land!\n\n");
		}
	} else if (strcmp(chosen_action, "talk to servant") == 0 || strcmp(chosen_action, "speak to servant") == 0 || strcmp(chosen_action, "chat with servant") == 0 || strcmp(chosen_action, "talk with servant") == 0 || strcmp(chosen_action, "converse with servant") == 0) {
		if (!actions[MURDER_SOLVED]) {
			printf("The Servant isn't in here!\n\n");
		} else if (actions[MURDER_SOLVED]) {
			printf("SERVANT: I fell into temptation. I just wanted a better life.\nI deserve whatever fate brings to me now for my crime...\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south back up the stairs.\n\n");
		*current_location = CASTLE2;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE7(char name[], int *current_location, bool actions[], int *coins) {
	printf("An expensive looking RUG covers almost the entire floor here.\nThere is one PAINTING on the wall, and multiple CANDLESTICKS around the walls.\nThere are doorways NORTH, EAST, and WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check painting") == 0 || strcmp(chosen_action, "examine painting") == 0 || strcmp(chosen_action, "look at painting") == 0 || strcmp(chosen_action, "investigate painting") == 0 || strcmp(chosen_action, "view painting") == 0) {
		printf("The painting is of some kind of old ruins, possibly a temple?\nIt looks quite old and weathered.\n\n");
	} else if (strcmp(chosen_action, "check candlesticks") == 0 || strcmp(chosen_action, "examine candlesticks") == 0 || strcmp(chosen_action, "look at candlesticks") == 0 || strcmp(chosen_action, "investigate candlesticks") == 0 || strcmp(chosen_action, "view candlesticks") == 0) {
		printf("The candlesticks appear normal.\n\n");
	} else if (strcmp(chosen_action, "pull candlesticks") == 0 || strcmp(chosen_action, "tug candlesticks") == 0 || strcmp(chosen_action, "yank candlesticks") == 0) {
		printf("You go around and pull on each candlestick, though it ends up being a pointless effort.\n\n");
	} else if (strcmp(chosen_action, "check rug") == 0 || strcmp(chosen_action, "examine rug") == 0 || strcmp(chosen_action, "look at rug") == 0 || strcmp(chosen_action, "investigate rug") == 0 || strcmp(chosen_action, "view rug") == 0) {
		printf("You lift up the rug and find a pile of dust underneath.\nSomeone must have gotten lazy while sweeping!\n\n");
	}  else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You head north through a doorway.\n\n");
		*current_location = CASTLE8;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go back east to the first room of the castle.\n\n");
		*current_location = CASTLE2;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You enter a room to the west.\n\n");
		*current_location = CASTLE10;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE8(char name[], int *current_location, bool actions[], int *coins) {
	printf("A GUARD stands in one corner of the room. There are CANDLESTICKS on each wall.\nThere is a fairly large door to the NORTH, a regular-sized door to the WEST, and a doorway to the SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "talk to guard") == 0 || strcmp(chosen_action, "speak to guard") == 0 || strcmp(chosen_action, "chat with guard") == 0 || strcmp(chosen_action, "talk with guard") == 0 || strcmp(chosen_action, "converse with guard") == 0) {
		if (!actions[PRINCE_MURDERED]) {
			printf("GUARD: You may only leave through this north door with the King's permission.\n\n");
		} else if (actions[PRINCE_MURDERED] && !actions[GET_VIAL]) {
			printf("GUARD: Nobody is to leave this castle, those are direct orders from the King!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("GUARD: Alfonz the alchemist? His study is through that door next to me.\n\n");
		} else if (actions[GIVE_VIAL] && !actions[SEEN_JESTER1]) {
			printf("GUARD: I am sure Alfonz will find the truth of these matters.\nI will stand guard here with a watchful eye in the meantime.\n\n");
		} else if (actions[SEEN_JESTER1] && !actions[ALCHEMIST_MURDERED]) {
			printf("GUARD: I don't know if he has found anything yet, go ahead and check with him if you wish.\n\n");
		} else if (actions[ALCHEMIST_MURDERED] && !actions[OPEN_PASSAGEWAY]) {
			printf("GUARD: I don't understand this at all!\nI saw nobody go into his study except you, but I watched you in the room?!\nSomething doesn't add up here!\n\n");
		} else if (actions[OPEN_PASSAGEWAY] && !actions[SEEN_PASSAGEWAY]) {
			printf("GUARD: A passageway? Now this does make more sense... Where does it go to?\n\n");
		} else if (actions[SEEN_PASSAGEWAY] && !actions[GET_BELL]) {
			printf("GUARD: It goes to the privy? I had no idea such a thing was even part of this castle.\nWho could have known it was there?\n\n");
		} else if (actions[GET_BELL] && !actions[SEEN_JESTER2]) {
			printf("GUARD: Whether or not you think it is important, you should show it to the King anyway to hopefully prove your innocence.\n\n");
		} else if (actions[SEEN_JESTER2] && !actions[GIVE_BELL]) {
			printf("GUARD: What?! Why are you here, show the king at once!\n\n");
		} else if (actions[GIVE_BELL] && !actions[HEARD_CONVERSATION]) {
			printf("GUARD: I would have never thought the Jester was capable of such a thing!\n\n");
		} else if (actions[HEARD_CONVERSATION] && !actions[MURDER_SOLVED]) {
			printf("GUARD: I don't believe this, and so I'm sure the King won't as well!\n\n");
		} else if (actions[MURDER_SOLVED]) {
			printf("GUARD: Well, you proved your innocence.\nI only wish this whole thing had been some nightmare, but I won't wake up.\nThere use to be some ruins to the northeast of here, but they sunk into the ocean centuries ago.\nThat is only an old legend though, nobody alive today had actually seen it.\n\n");
		}
	} else if (strcmp(chosen_action, "give vial") == 0 || strcmp(chosen_action, "present vial") == 0 || strcmp(chosen_action, "provide vial") == 0) {
		if (!actions[GET_VIAL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("GUARD: This looks like something to take to Alfonz, he's through that doorway there.\n\n");	
		} else if (actions[GIVE_VIAL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "give bell") == 0 || strcmp(chosen_action, "present bell") == 0 || strcmp(chosen_action, "provide bell") == 0) {
		if (!actions[GET_BELL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && !actions[SEEN_JESTER2]) {
			printf("GUARD: I'm not seeing the signifigance of this?\n\n");	
		} else if (actions[GET_BELL] && !actions[GIVE_BELL] && actions[SEEN_JESTER2]) {
			printf("GUARD: I don't need this, but you need to show it to the King!\n\n");	
		} else if (actions[GIVE_BELL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "check candlesticks") == 0 || strcmp(chosen_action, "examine candlesticks") == 0 || strcmp(chosen_action, "look at candlesticks") == 0 || strcmp(chosen_action, "investigate candlesticks") == 0 || strcmp(chosen_action, "view candlesticks") == 0) {
		printf("The candlesticks appear to be just that, candlesticks.\n\n");
	} else if (strcmp(chosen_action, "pull candlesticks") == 0 || strcmp(chosen_action, "tug candlesticks") == 0 || strcmp(chosen_action, "yank candlesticks") == 0) {
		printf("You go around and pull on each candlestick, though it amounts to nothing.\nThe guard stares at you with a raised eyebrow.\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (!actions[PRINCE_MURDERED]) {
			printf("GUARD: Halt! You may only use this door with the King's permission!\n\n");
		} else if (!actions[MURDER_SOLVED]) {
			printf("GUARD: Halt! Nobody can leave the castle until we resolve this whole situation, those are the King's orders!\n\n");
		} else {
			printf("You leave the castle through the large door to the north.\n\n");
			*current_location = OUTSIDE_CASTLE;
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You open the door and enter the room to the west.\n\n");
		*current_location = CASTLE9;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go through the doorway to the south.\n\n");
		*current_location = CASTLE7;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE9(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[GIVE_VIAL]) {
		printf("An ALCHEMIST sits at his desk pouring through multiple books.\nThere are books scattered everywhere, along with various flasks and other glass equipment.\nThere is a CANDLESTICK on the wall behind the desk.\n");
	} else if (actions[GIVE_VIAL] && !actions[SEEN_JESTER1]) {
		printf("The ALCHEMIST sits at his desk mixing chemicals and muttering to himself.\nThere are books scattered everywhere, along with various flasks and other glass equipment.\nThere is a CANDLESTICK on the wall behind the desk.\n");	
	} else if (actions[SEEN_JESTER1] && !actions[ALCHEMIST_MURDERED]) {
		printf("The ALCHEMIST sits at his desk... Wait? He's slumped over his desk with a knife sticking out of his back!\nThere are books scattered everywhere, along with various flasks and other glass equipment.\nThere is a CANDLESTICK on the wall behind the desk.\n");	
		actions[ALCHEMIST_MURDERED] = 1;
	} else if (actions[ALCHEMIST_MURDERED] && !actions[MURDER_SOLVED]) {
		printf("The ALCHEMIST is still there with the knife sticking out of his back.\nThere are books scattered everywhere, along with various flasks and other glass equipment.\nThere is a CANDLESTICK on the wall behind the desk.\n");	
	} else if (actions[MURDER_SOLVED]) {
		printf("What was once the Alchemist's study is now just a room with an empty desk.\nSomeone must have paid their respects to him, as all the books are now neatly organized on a shelf.\nThere is a CANDLESTICK on the wall behind the desk.\n");	
	}
	if (!actions[OPEN_PASSAGEWAY]) {
		printf("The only exit is to the EAST through a door.\n\n");	
	} else {
		printf("There is an open passage to the NORTH, and an exit through a door to the EAST.\n\n");	
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "talk to alchemist") == 0 || strcmp(chosen_action, "speak to alchemist") == 0 || strcmp(chosen_action, "chat with alchemist") == 0 || strcmp(chosen_action, "talk with alchemist") == 0 || strcmp(chosen_action, "converse with alchemist") == 0) {
		if (!actions[PRINCE_MURDERED]) {
			printf("ALCHEMIST: I'm researching the philosopher's stone...\n\n");
		} else if (actions[PRINCE_MURDERED] && !actions[GET_VIAL]) {
			printf("ALCHEMIST: This is terrible, there's not enough to go on.\nI need something more to be able to test...\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("ALCHEMIST: You have a vial with traces of liquid?! Give it to me!\n\n");
		} else if (actions[GIVE_VIAL] && !actions[SEEN_JESTER1]) {
			printf("ALCHEMIST: I'm still running tests, I haven't identified the poison yet.\nCome back later...\n\n");
		} else if (actions[ALCHEMIST_MURDERED] && !actions[MURDER_SOLVED]) {
			printf("You would talk to the Alchemist, but he's quite dead...\n\n");
		} else if (actions[MURDER_SOLVED]) {
			printf("He is no longer here...\n\n");
		}
	} else if (strcmp(chosen_action, "give vial") == 0 || strcmp(chosen_action, "present vial") == 0 || strcmp(chosen_action, "provide vial") == 0) {
		if (!actions[GET_VIAL]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_VIAL] && !actions[GIVE_VIAL]) {
			printf("ALCHEMIST: This may very well be what we need to open up the truth of this mystery! Give it here!\nThe Alchemist takes the vial from you.\n\n");
			actions[GIVE_VIAL] = 1;	
		} else if (actions[GIVE_VIAL]) {
			printf("You don't have that anymore!\n\n");
		} 
	} else if (strcmp(chosen_action, "check candlestick") == 0 || strcmp(chosen_action, "examine candlestick") == 0 || strcmp(chosen_action, "look at candlestick") == 0 || strcmp(chosen_action, "investigate candlestick") == 0 || strcmp(chosen_action, "view candlestick") == 0) {
		printf("It doesn't appear to be anything more than a normal candlestick.\n\n");
	} else if (strcmp(chosen_action, "pull candlestick") == 0 || strcmp(chosen_action, "tug candlestick") == 0 || strcmp(chosen_action, "yank candlestick") == 0) {
		if (!actions[GIVE_VIAL]) {
			printf("ALCHEMIST: Stop! I need that candlelight right now!\n\n");
		} else if (actions[GIVE_VIAL] && !actions[SEEN_JESTER1]) {
			printf("ALCHEMIST: What are you doing? Don't mess with that candle!\n\n");	
		} else if (actions[ALCHEMIST_MURDERED] && !actions[OPEN_PASSAGEWAY]) {
			printf("You pull on the candlestick...\nWoah! The wall slides open with the grinding sound of stones rubbing against each other and mechanical gears turning!\n\n");
			actions[OPEN_PASSAGEWAY] = 1;	
		} else if (actions[OPEN_PASSAGEWAY]) {
			printf("You already pulled on it and opened a passageway...\n\n");	
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (actions[OPEN_PASSAGEWAY]) {
			printf("You enter the dim passageway.\n\n");
			*current_location = CASTLE11;
		} else {
			printf("You would go north, but it's just a wall there!\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You leave the room through the door to the east.\n\n");
		*current_location = CASTLE8;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE10(char name[], int *current_location, bool actions[], int *coins) {
	printf("This appears to be the armory. There are several suits of ARMOR.\nSPEARS and SWORDS line the walls.\nThe exit is to the EAST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check armor") == 0 || strcmp(chosen_action, "examine armor") == 0 || strcmp(chosen_action, "look at armor") == 0 || strcmp(chosen_action, "investigate armor") == 0 || strcmp(chosen_action, "view armor") == 0) {
		printf("The armor appears to be quite well-polished.\n\n");
	} else if (strcmp(chosen_action, "check spears") == 0 || strcmp(chosen_action, "examine spears") == 0 || strcmp(chosen_action, "look at spears") == 0 || strcmp(chosen_action, "investigate spears") == 0 || strcmp(chosen_action, "view spears") == 0) {
		printf("The spears are either never used, or they are regularly sharpened to a razor's edge.\n\n");
	} else if (strcmp(chosen_action, "check swords") == 0 || strcmp(chosen_action, "examine swords") == 0 || strcmp(chosen_action, "look at swords") == 0 || strcmp(chosen_action, "investigate swords") == 0 || strcmp(chosen_action, "view swords") == 0) {
		printf("The swords are so ornate and covered in jewels, that they seem to be more for show than combat.\n\n");
	} else if (strcmp(chosen_action, "get armor") == 0 || strcmp(chosen_action, "pick up armor") == 0 || strcmp(chosen_action, "grab armor") == 0 || strcmp(chosen_action, "take armor") == 0 || strcmp(chosen_action, "acquire armor") == 0 || strcmp(chosen_action, "obtain armor") == 0) {
		printf("Taking the armor doesn't seem like a good idea, though it might fit you well.\n\n");
	} else if (strcmp(chosen_action, "get spears") == 0 || strcmp(chosen_action, "pick up spears") == 0 || strcmp(chosen_action, "grab spears") == 0 || strcmp(chosen_action, "take spears") == 0 || strcmp(chosen_action, "acquire spears") == 0 || strcmp(chosen_action, "obtain spears") == 0) {
		printf("You would take them, but it seems like a foolish idea, so you don't.\n\n");
	} else if (strcmp(chosen_action, "get swords") == 0 || strcmp(chosen_action, "pick up swords") == 0 || strcmp(chosen_action, "grab swords") == 0 || strcmp(chosen_action, "take swords") == 0 || strcmp(chosen_action, "acquire swords") == 0 || strcmp(chosen_action, "obtain swords") == 0) {
		printf("This seems like a very bad idea, you decide not to take them.\n\n");
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You leave east from the armory.\n\n");
		*current_location = CASTLE7;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE11(char name[], int *current_location, bool actions[], int *coins) {
	printf("All you see in this room is a lone CANDLE in the corner.\nThe exit is back SOUTH, the passageway continues down some stairs to the EAST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check candle") == 0 || strcmp(chosen_action, "examine candle") == 0 || strcmp(chosen_action, "look at candle") == 0 || strcmp(chosen_action, "investigate candle") == 0 || strcmp(chosen_action, "view candle") == 0) {
		printf("The only way this could be lit still is if someone was recently in here.\n\n");
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go downstairs further into the passage.\n\n");
		*current_location = CASTLE12;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go back towards the Alchemist's study.\n\n");
		*current_location = CASTLE9;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE12(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[GET_BELL]) {
		printf("There is a dimly lit CANDLESTICK on the northern wall.\nYou notice a small SHINY THING on the ground.\nOn the southern wall, there is a large CRACK.\nThe EAST and WEST go upstairs.\n\n");
	} else {
		printf("There is a dimly lit CANDLESTICK on the northern wall.\nOn the southern wall, there is a large CRACK.\nThe EAST and WEST go upstairs.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check candlestick") == 0 || strcmp(chosen_action, "examine candlestick") == 0 || strcmp(chosen_action, "look at candlestick") == 0 || strcmp(chosen_action, "investigate candlestick") == 0 || strcmp(chosen_action, "view candlestick") == 0) {
		printf("Nothing out of place with this candlestick.\n\n");
	} else if (strcmp(chosen_action, "pull candlestick") == 0 || strcmp(chosen_action, "tug candlestick") == 0 || strcmp(chosen_action, "yank candlestick") == 0) {
		printf("Nothing happens after trying to pull this particular candlestick, it doesn't move.\n\n");
	} else if (strcmp(chosen_action, "check shiny thing") == 0 || strcmp(chosen_action, "examine shiny thing") == 0 || strcmp(chosen_action, "look at shiny thing") == 0 || strcmp(chosen_action, "investigate shiny thing") == 0 || strcmp(chosen_action, "view shiny thing") == 0) {
		if (!actions[GET_BELL]) {
			printf("It appears to be some kind of small bell?\n\n");
		} else {
			printf("You already picked that up!\n\n");
		}
	} else if (strcmp(chosen_action, "get shiny thing") == 0 || strcmp(chosen_action, "pick up shiny thing") == 0 || strcmp(chosen_action, "grab shiny thing") == 0 || strcmp(chosen_action, "take shiny thing") == 0 || strcmp(chosen_action, "acquire shiny thing") == 0 || strcmp(chosen_action, "obtain shiny thing") == 0) {
		if (!actions[GET_BELL]) {
			printf("You reach down to pick up the shiny thing, it looks like a bell.\nYou place it in your pocket.\n\n");
			actions[GET_BELL] = 1;
		} else {
			printf("You already picked that up!\n\n");
		}
	} else if (strcmp(chosen_action, "check crack") == 0 || strcmp(chosen_action, "examine crack") == 0 || strcmp(chosen_action, "look at crack") == 0 || strcmp(chosen_action, "investigate crack") == 0 || strcmp(chosen_action, "view crack") == 0) {
		if (!actions[GIVE_BELL]) {
			printf("You hear someone in another room drunkenly singing.\n\n");
		} else if (actions[GIVE_BELL] && !actions[HEARD_CONVERSATION]) {
			printf("You put your ear up to the crack in the wall.\nYou hear someone's singing tapering off, it sounds like they pass out.\nYou hear what seems to be the Princess and Jester talking...\nPRINCESS: You ruined the whole plan! First you put trust in her instead of doing it yourself!\nThen you went and murdered Alfonz! We could have ruled this kingdom together! What were you thinking?!\nJESTER: How would I have had access to the food? And I panicked with Alfonz, I thought he would blow the whole thing wide open!\nPRINCESS: We still have a chance... We can blame that strange visitor that came here for all of it!\n\n");
			actions[HEARD_CONVERSATION] = 1;
		} else {
			printf("All you hear is someone singing with drunk enthusiasm.\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You head upstairs to the east.\n\n");
		*current_location = CASTLE13;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go upstairs to the west.\n\n");
		*current_location = CASTLE11;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_CASTLE13(char name[], int *current_location, bool actions[], int *coins) {
	printf("You are at a dead end. There is a CANDLESTICK on the southern wall.\nThe only exit is WEST, downstairs.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check candlestick") == 0 || strcmp(chosen_action, "examine candlestick") == 0 || strcmp(chosen_action, "look at candlestick") == 0 || strcmp(chosen_action, "investigate candlestick") == 0 || strcmp(chosen_action, "view candlestick") == 0) {
		printf("Another candlestick that appears to just be a candlestick...\n\n");
	} else if (strcmp(chosen_action, "pull candlestick") == 0 || strcmp(chosen_action, "tug candlestick") == 0 || strcmp(chosen_action, "yank candlestick") == 0) {
		printf("You pull on the candlestick, it actually pulls! You hear a grinding noise as the wall and floor rotates around!\n\n");
		if (!actions[SEEN_PASSAGEWAY]) {
			actions[SEEN_PASSAGEWAY] = 1;
		}
		*current_location = CASTLE5;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head downstairs to the west.\n\n");
		*current_location = CASTLE12;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_OUTSIDE_CASTLE(char name[], int *current_location, bool actions[], int *coins) {
	printf("Outside of the castle you see a large, steep mountain to the north.\nIn the distance to the EAST, you see what appears to be an ocean.\nTo the WEST you see a small town of some sorts.\nSOUTH is back into the castle.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You head east towards the ocean.\n\n");
		*current_location = BEACH;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west into the town.\n\n");
		*current_location = TOWN;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go back into the castle.\n\n");
		*current_location = CASTLE8;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_BEACH(char name[], int *current_location, bool actions[], int *coins) {
	printf("You find yourself standing on a beach. There is someone who seems to be some kind of WIZARD standing there.\nThe ocean lies to the NORTH. WEST is back outside of the castle.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check wizard") == 0 || strcmp(chosen_action, "examine wizard") == 0 || strcmp(chosen_action, "look at wizard") == 0 || strcmp(chosen_action, "investigate wizard") == 0 || strcmp(chosen_action, "view wizard") == 0) {
		printf("The wizard is wearing a pointed, blue hat. He has a long, gray beard, and a dark blue robe.\n\n");
	} else if (strcmp(chosen_action, "talk to wizard") == 0 || strcmp(chosen_action, "speak to wizard") == 0 || strcmp(chosen_action, "chat with wizard") == 0 || strcmp(chosen_action, "talk with wizard") == 0 || strcmp(chosen_action, "converse with wizard") == 0) {
		if (!actions[GET_SPELL_BOOK]) {
			printf("WIZARD: I had to pawn my SPELL BOOK in the town for extra coins.\nThere doesn't seem to be any way for me to get it back now, and I'm useless without it.\nIf you can get it back for me, I can cast a spell that would allow you to breathe underwater and repel any aquatic predators.\n\n");
		} else if (actions[GET_SPELL_BOOK] && !actions[GIVE_SPELL_BOOK]) {
			printf("WIZARD: You got the SPELL BOOK? GIVE it to me!\n\n");
		} else if (actions[GIVE_SPELL_BOOK]) {
			printf("WIZARD: That spell won't last forever, I suggest you get going where you want to go with it.\n\n");
		}
	} else if (strcmp(chosen_action, "give spell book") == 0 || strcmp(chosen_action, "present spell book") == 0 || strcmp(chosen_action, "provide spell book") == 0) {
		if (!actions[GET_SPELL_BOOK]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_SPELL_BOOK] && !actions[GIVE_SPELL_BOOK]) {
			printf("WIZARD: Thank you! As promised...\nThe wizard opens the spell book and begins chanting something you can't understand while waving his hand around.\nYou feel something changing in your body as he finishes chanting.\nWIZARD: You can now breathe underwater with no problem, and no creatures in the ocean will even notice you.\nThis is a temporary change, so you should try to hurry with what you want to do.\n\n");
			actions[GIVE_SPELL_BOOK] = 1;
		} else if (actions[GIVE_SPELL_BOOK]) {
			printf("You don't have that anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (actions[GIVE_SPELL_BOOK]) {
			if (!actions[SEEN_SHARKS]) {
				printf("You dive into the ocean and head into its depths, towards what appears to be some old ruins.\nYour heart skips a beat as a group of sharks passes by you.\nThey seem to totally ignore you, but this doesn't totally ease your fears.\n\n");
				actions[SEEN_SHARKS] = 1;
			} else {
				printf("You dive into the ocean and head into its depths, towards what appears to be some old ruins.\n\n");
			}
			*current_location = TEMPLE1;
		} else {
			printf("You dive into the ocean.\nYou don't know how long you can hold your breath, but you head towards some old, sunken ruins anyway.\nAs your breath is running out, you attempt to go back up to the surface.\nYou attempt, but a group of sharks take notice in you!\nThey come to you faster than you can swim away, and a feeding frenzy ensues as they tear you apart!\nGAME OVER\n\n");
			return 0;
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west back to outside of the castle.\n\n");
		*current_location = OUTSIDE_CASTLE;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TOWN(char name[], int *current_location, bool actions[], int *coins) {
	printf("You find yourself in a small town. You see a MERCHANT carrying containers of different plants.\nTo the NORTH is a small shop with the name 'Jill's Deals'.\nEAST is back to outside the castle, WEST is to some kind of field.\nThere is a place to the SOUTH with the name 'The Wobbly Path'. It must be a tavern.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check merchant") == 0 || strcmp(chosen_action, "examine merchant") == 0 || strcmp(chosen_action, "look at merchant") == 0 || strcmp(chosen_action, "investigate merchant") == 0 || strcmp(chosen_action, "view merchant") == 0) {
		printf("The merchant is carrying baskets and containers of plants, he must deal solely in these kinds of produce.\n\n");
	} else if (strcmp(chosen_action, "talk to merchant") == 0 || strcmp(chosen_action, "speak to merchant") == 0 || strcmp(chosen_action, "chat with merchant") == 0 || strcmp(chosen_action, "talk with merchant") == 0 || strcmp(chosen_action, "converse with merchant") == 0) {
		if (!actions[GET_HERB]) {
			printf("MERCHANT: If you find any rare herbs somewhere, I will buy them for 7 coins!\n\n");
		} else {
			printf("MERCHANT: That's a rare HERB you have! GIVE it to me and I will give you 7 coins on the spot!\n\n");
		}
	} else if (strcmp(chosen_action, "give herb") == 0 || strcmp(chosen_action, "present herb") == 0 || strcmp(chosen_action, "provide herb") == 0) {
		if (!actions[GET_HERB]) {
			printf("You don't have that!\n\n");
		} else {
			printf("MERCHANT: Excellent, here are 7 coins as promised!\nThe merchant hands you 7 coins in return for the herb.\n\n");
			actions[GET_HERB] = 0;
			*coins += 7;
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go into the shop.\n\n");
		*current_location = SHOP;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You head back towards the outside of the castle.\n\n");
		*current_location = OUTSIDE_CASTLE;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go into the field to the west.\n\n");
		*current_location = FIELD;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You open the door into the tavern and go inside.\n\n");
		*current_location = TAVERN;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_SHOP(char name[], int *current_location, bool actions[], int *coins) {
	printf("There are many different items in this shop, some are to be expected, while some seem pretty odd.\nNone of the items really catch your interest, though.\nThere is a SHOPKEEPER standing in front of the counter.\nThe only exit is to the SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check shopkeeper") == 0 || strcmp(chosen_action, "examine shopkeeper") == 0 || strcmp(chosen_action, "look at shopkeeper") == 0 || strcmp(chosen_action, "investigate shopkeeper") == 0 || strcmp(chosen_action, "view shopkeeper") == 0) {
		printf("She appears to be eagerly awaiting you to make a purchase here.\n\n");
	} else if (strcmp(chosen_action, "talk to shopkeeper") == 0 || strcmp(chosen_action, "speak to shopkeeper") == 0 || strcmp(chosen_action, "chat with shopkeeper") == 0 || strcmp(chosen_action, "talk with shopkeeper") == 0 || strcmp(chosen_action, "converse with shopkeeper") == 0) {
		if (!actions[GET_SPELL_BOOK]) {
			printf("SHOPKEEPER: A SPELL BOOK? Yes, I do have that. If you want to BUY it, it will cost you 25 coins.\n\n");
		} else {
			printf("SHOPKEEPER: Enjoy your purchase, come back soon if you see anything else that interests you here.\n\n");
		}
	} else if (strcmp(chosen_action, "buy spell book") == 0 || strcmp(chosen_action, "purchase spell book") == 0 || strcmp(chosen_action, "pay for spell book") == 0) {
		if (!actions[GET_SPELL_BOOK] && *coins >= 25) {
			printf("SHOPKEEPER: Okay, 25 coins it is! Thank you!\nThe shopkeeper hands you the spell book in return for 25 coins.\n\n");
			actions[GET_SPELL_BOOK] = 1;
			*coins -= 25;
		} else if (!actions[GET_SPELL_BOOK] && *coins < 25) {
			printf("SHOPKEEPER: I won't sell that book for anything lower than 25 coins, and you only appear to have %i coins...\n\n", *coins);
		} else if (actions[GET_SPELL_BOOK]) {
			printf("SHOPKEEPER: I already sold you that book, don't you remember?\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You leave the shop.\n\n");
		*current_location = TOWN;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_FIELD(char name[], int *current_location, bool actions[], int *coins) {
	printf("There are several large TREES in this field, along with many piles of LEAVES scattered around.\nThe town is back to the EAST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check trees") == 0 || strcmp(chosen_action, "examine trees") == 0 || strcmp(chosen_action, "look at trees") == 0 || strcmp(chosen_action, "investigate trees") == 0 || strcmp(chosen_action, "view trees") == 0) {
		printf("These trees must have been here a long time, they are pretty big.\nThere is something old carved onto one of them: 'I will rule this land one day!', next to a crudely carved face with a pointy hat...\n\n");
	} else if (strcmp(chosen_action, "check leaves") == 0 || strcmp(chosen_action, "examine leaves") == 0 || strcmp(chosen_action, "look at leaves") == 0 || strcmp(chosen_action, "investigate leaves") == 0 || strcmp(chosen_action, "view leaves") == 0) {
		if (!actions[GET_HERB] && *coins == 0) {
			printf("You search through all the piles of leaves.\nYou find an interesting looking herb, so you decide to take it.\n\n");
			actions[GET_HERB] = 1;
		} else {
			printf("You search through all the piles of leaves.\nAfter searching through them thoroughly, you find nothing of interest.\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go back into the town.\n\n");
		*current_location = TOWN;
	} else {
		printInvalid();
	}

	return 1;
}

void threesDiceGame(int *coins) {
	int values[] = { 0, 1, 2, 0, 4, 5, 6 };
	char dice[][6] = { "[ . ]", "[ : ]", "[. :]", "[: :]", "[:.:]", "[:::]" };
	
	int player_score = 0, proll_a = 1, proll_b = 1, bet = -1;
	int com_score = 0, croll_a = 1, croll_b = 1;
	bool keep_both = 0;
	bool player_first = rand() % 2;
	
	while(coins != 0) {
		bet = -1;
		while(bet < 1 || bet > *coins) {
			printf("Coins: %d\nEnter your bet (Bet 0 to quit): ", *coins);
			scanf(" %d", &bet);
			if (bet == 0) {
				printf("Quitting game...\n\n");
				return;
			} else if (bet < 1) {
				printf("You can't bet negative...\n");
			} else if (bet > *coins) {
				printf("That bet is more than the amount of coins you have!\n");
			}
		}
		
		bool player_went = 0, com_went = 0;
		while(!player_went || !com_went) {
			if ((player_first && !player_went) || (!player_first && com_went)) {
				printf("Player's turn.\n");
				proll_a = rand() % 6 + 1;
				proll_b = rand() % 6 + 1;
				player_score = values[proll_a] + values[proll_b];
				if (player_score == 12) {
					player_score = 0;
				}
				printf("Player rolled: %s %s\nPlayer Score: %i\n", dice[proll_a - 1], dice[proll_b - 1], player_score);
				char player_choice[4] = "z";
				bool invalid = 1;
				while(((strcmp(player_choice, "a") != 0) && (strcmp(player_choice, "b") != 0) && (strcmp(player_choice, "c") != 0)) || invalid) {
					printf("Enter 'a' or 'b' to re-roll (or 'c' to keep both if both the same): ");
					scanf(" %[^\n]%*c", player_choice);
					if ((strcmp(player_choice, "c") == 0) && (proll_a != proll_b)) {
						printf("Can't keep both, they aren't the same!\n");
						continue;
					}
					invalid = 0;
				}
				if (strcmp(player_choice, "a") == 0) {
					proll_a = rand() % 6 + 1;
					player_score = values[proll_a] + values[proll_b];
					if (player_score == 12) {
						player_score = 0;
					}
					printf("Player re-rolled a for: %s %s\nPlayer Score: %i\n\n", dice[proll_a - 1], dice[proll_b - 1], player_score);
				} else if (strcmp(player_choice, "b") == 0) {
					proll_b = rand() % 6 + 1;
					player_score = values[proll_a] + values[proll_b];
					if (player_score == 12) {
						player_score = 0;
					}
					printf("Player re-rolled b for: %s %s\nPlayer Score: %i\n\n", dice[proll_a - 1], dice[proll_b - 1], player_score);
				} else if (strcmp(player_choice, "c") == 0) {
					printf("Player kept both for: %s %s\nPlayer Score: %i\n\n", dice[proll_a - 1], dice[proll_b - 1], player_score);
				}
				
				player_went = 1;
			} else if (player_first && !com_went) {
				
				printf("Gambler's turn.\n");
				croll_a = rand() % 6 + 1;
				croll_b = rand() % 6 + 1;
				com_score = values[croll_a] + values[croll_b];
				if (com_score == 12) {
					com_score = 0;
				}
				printf("Gambler rolled: %s %s\nGambler Score: %i\n", dice[croll_a - 1], dice[croll_b - 1], com_score);
				
				if ((croll_a == croll_b) && (com_score < player_score)) {
					printf("Gambler kept both for: %s %s\nGambler Score: %i\n", dice[croll_a - 1], dice[croll_b - 1], com_score);
				} else if (((croll_b == 6) && (player_score < values[croll_a])) || (values[croll_a] > values[croll_b])) {
					croll_a = rand() % 6 + 1;
					com_score = values[croll_a] + values[croll_b];
					if (com_score == 12) {
						com_score = 0;
					}
					printf("Gambler re-rolled a for: %s %s\nGambler Score: %i\n\n", dice[croll_a - 1], dice[croll_b - 1], com_score);
				} else if ((croll_a == 6) && (player_score < values[croll_b])) {
					printf("Gambler kept both for: %s %s\nGambler Score: %i\n\n", dice[croll_a - 1], dice[croll_b - 1], com_score);
				} else {
					croll_b = rand() % 6 + 1;
					com_score = values[croll_a] + values[croll_b];
					if (com_score == 12) {
						com_score = 0;
					}
					printf("Gambler re-rolled b for: %s %s\nGambler Score: %i\n\n", dice[croll_a - 1], dice[croll_b - 1], com_score);
				}
				
				com_went = 1;
			} else if (!player_first && !com_went) {
				printf("Gambler's turn.\n");
				croll_a = rand() % 6 + 1;
				croll_b = rand() % 6 + 1;
				com_score = values[croll_a] + values[croll_b];
				if (com_score == 12) {
					com_score = 0;
				}
				printf("Gambler rolled: %s %s\nGambler Score: %i\n", dice[croll_a - 1], dice[croll_b - 1], com_score);
				
				if ((croll_a == croll_b) && com_score <= 3) {
					printf("Gambler kept both for: %s %s\nGambler Score: %i\n\n", dice[croll_a - 1], dice[croll_b - 1], com_score);
				} else if (((croll_b == 6) && (croll_a >= 4)) || (values[croll_a] > values[croll_b])) {
					croll_a = rand() % 6 + 1;
					com_score = values[croll_a] + values[croll_b];
					if (com_score == 12) {
						com_score = 0;
					}
					printf("Gambler re-rolled a for: %s %s\nGambler Score: %i\n\n", dice[croll_a - 1], dice[croll_b - 1], com_score);
				} else {
					croll_b = rand() % 6 + 1;
					com_score = values[croll_a] + values[croll_b];
					if (com_score == 12) {
						com_score = 0;
					}
					printf("Gambler re-rolled b for: %s %s\nGambler Score: %i\n\n", dice[croll_a - 1], dice[croll_b - 1], com_score);
				}
				
				com_went = 1;
			}
		}
		
		if (player_score < com_score) {
			printf("Player wins!\n##########\n");
			*coins += bet;
		} else if (player_score > com_score) {
			printf("Player loses!\n##########\n");
			*coins -= bet;
			if (*coins == 0) {
				printf("Player is out of coins!\n\n");
				return;
			}
		} else {
			printf("Tie game!\n##########\n");
		}
		
		if (player_first) {
			player_first = 0;
		} else {
			player_first = 1;
		}
	}	
}

bool room_TAVERN(char name[], int *current_location, bool actions[], int *coins) {
	printf("Inside of the tavern are many people drinking and talking to each other merrily.\nIn one corner, there is a seemingly lonely OLD MAN.\nThere is also a GAMBLER playing a dice game at a table.\nNORTH is the exit back into town.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check old man") == 0 || strcmp(chosen_action, "examine old man") == 0 || strcmp(chosen_action, "look at old man") == 0 || strcmp(chosen_action, "investigate old man") == 0 || strcmp(chosen_action, "view old man") == 0) {
		printf("He appears to be itching to tell a story.\n\n");
	} else if (strcmp(chosen_action, "check gambler") == 0 || strcmp(chosen_action, "examine gambler") == 0 || strcmp(chosen_action, "look at gambler") == 0 || strcmp(chosen_action, "investigate gambler") == 0 || strcmp(chosen_action, "view gambler") == 0) {
		printf("The gambler keeps laughing to himself as his pile of coins grows larger.\n\n");
	} else if (strcmp(chosen_action, "talk to old man") == 0 || strcmp(chosen_action, "speak to old man") == 0 || strcmp(chosen_action, "chat with old man") == 0 || strcmp(chosen_action, "talk with old man") == 0 || strcmp(chosen_action, "converse with old man") == 0) {
		printf("OLD MAN: There was once a civilization near here, long, long ago.\nThese people ended up finding the answer...\nThey walked the path of light, but embraced the darkness when it would come.\nThis balance allowed their kingdom to prosper.\nUntil... One day a monk grew sick of the peace, he felt it was too bland, and he became greedy for more.\nHe fell into the darkness, and ended up swallowing up the rest of the civilization with him.\nTheir temple ended up sinking into the ocean along with them.\nOr so, that's how the legend goes...\n\n");
	} else if (strcmp(chosen_action, "talk to gambler") == 0 || strcmp(chosen_action, "speak to gambler") == 0 || strcmp(chosen_action, "chat with gambler") == 0 || strcmp(chosen_action, "talk with gambler") == 0 || strcmp(chosen_action, "converse with gambler") == 0) {
		printf("GAMBLER: Do you want to play a game of dice? (y/n): ");
		char yn[4];
		scanf("%[^\n]%*c", yn);
		if (strcmp(yn, "y") == 0) {
			if (*coins > 0) {
				printf("GAMBLER: Do you want to hear the rules of the game? (y/n): ");
				char yn2[4];
				scanf("%[^\n]%*c", yn2);
				if (strcmp(yn2, "y") == 0) {
					printf("All rolls are worth their normal respective values, except threes are always worth 0, and double sixes are also worth 0.\nYou start by rolling both dice, then you have a choice:\nRe-roll the 1st one 'a', or 2nd 'b'\nAlso, if both rolls are the same, you may choose to keep both by entering 'c'.\nThen, it is the other player's turn.\nThe score is the sum of both of your dice, and the lowest score wins.\n\n");
				}
				threesDiceGame(coins);	
			} else {
				printf("GAMBLER: I don't play these games for nothing, come back when you actually have some coins to play with!\n\n");
			}
		} else {
			printf("GAMBLER: Okay, maybe another time.\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("\n\n");
		*current_location = TOWN;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE1(char name[], int *current_location, bool actions[], int *coins) {
	printf("The are three doors, to the NORTH, EAST, and WEST, SOUTH is back to the shore.\nThere are symbols on each door, and two symbols on each side of the middle door.\nThere is a stone BLOCK in the middle of this area.\n");
	if (actions[PLACE_CIRCLE_STONE]) {
		printf("The symbol that looks like ':|' in a circle to the left of the NORTH door is glowing blue.\n");
	}
	if (actions[PLACE_SQUARE_STONE]) {
		printf("The symbol that looks like '/|' in a square to the right of the NORTH door is glowing blue.\n");
	}
	if (actions[TEMPLE_ENTRANCE_CENTER]) {
		printf("The stone BLOCK is in the center, surrounded by symbols matching the ones on the doors.\nAll three doors are closed.\n");
	} else if (actions[TEMPLE_ENTRANCE_NORTH]) {
		if (actions[PLACE_CIRCLE_STONE] && actions[PLACE_CIRCLE_STONE]) {
			printf("The stone BLOCK is towards the NORTH, surrounded by symbols matching the ones on the doors.\nThe NORTH door is open.\n");
		} else {
			printf("The stone BLOCK is towards the NORTH, surrounded by symbols matching the ones on the doors.\nAll three doors are closed.\n");
		}
	} else if (actions[TEMPLE_ENTRANCE_EAST]) {
		printf("The stone BLOCK is towards the EAST, surrounded by symbols matching the ones on the doors.\nThe EAST door is open.\n");
	} else if (actions[TEMPLE_ENTRANCE_WEST]) {
		printf("The stone BLOCK is towards the WEST, surrounded by symbols matching the ones on the doors.\nThe WEST door is open.\n");
	} 
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "move block") == 0 || strcmp(chosen_action, "push block") == 0 || strcmp(chosen_action, "shove block") == 0) {
		printf("MOVE BLOCK in which direction?\n\n");
	} else if (strcmp(chosen_action, "move block north") == 0 || strcmp(chosen_action, "push block north") == 0 || strcmp(chosen_action, "shove block north") == 0) {
		if (actions[TEMPLE_ENTRANCE_CENTER]) {
			printf("You push the block towards the north.\n\n");
			actions[TEMPLE_ENTRANCE_CENTER] = 0;
			actions[TEMPLE_ENTRANCE_NORTH] = 1;
		} else {
			printf("The block won't move any farther in that direction!\n\n");
		}
	} else if (strcmp(chosen_action, "move block east") == 0 || strcmp(chosen_action, "push block east") == 0 || strcmp(chosen_action, "shove block east") == 0) {
		if (actions[TEMPLE_ENTRANCE_CENTER]) {
			printf("You push the block towards the east.\n\n");
			actions[TEMPLE_ENTRANCE_CENTER] = 0;
			actions[TEMPLE_ENTRANCE_EAST] = 1;
		} else if (actions[TEMPLE_ENTRANCE_WEST]) {
			printf("You push the block towards the east.\n\n");
			actions[TEMPLE_ENTRANCE_WEST] = 0;
			actions[TEMPLE_ENTRANCE_CENTER] = 1;
		} else {
			printf("The block won't move any farther in that direction!\n\n");
		}
	} else if (strcmp(chosen_action, "move block west") == 0 || strcmp(chosen_action, "push block west") == 0 || strcmp(chosen_action, "shove block west") == 0) {
		if (actions[TEMPLE_ENTRANCE_CENTER]) {
			printf("You push the block towards the west.\n\n");
			actions[TEMPLE_ENTRANCE_CENTER] = 0;
			actions[TEMPLE_ENTRANCE_WEST] = 1;
		} else if (actions[TEMPLE_ENTRANCE_EAST]) {
			printf("You push the block towards the west.\n\n");
			actions[TEMPLE_ENTRANCE_EAST] = 0;
			actions[TEMPLE_ENTRANCE_CENTER] = 1;
		} else {
			printf("The block won't move any farther in that direction!\n\n");
		}
	} else if (strcmp(chosen_action, "move block south") == 0 || strcmp(chosen_action, "push block south") == 0 || strcmp(chosen_action, "shove block south") == 0) {
		if (actions[TEMPLE_ENTRANCE_NORTH]) {
			printf("You push the block towards the south.\n\n");
			actions[TEMPLE_ENTRANCE_NORTH] = 0;
			actions[TEMPLE_ENTRANCE_CENTER] = 1;
		} else {
			printf("The block won't move any farther in that direction!\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (actions[TEMPLE_ENTRANCE_NORTH] && actions[PLACE_CIRCLE_STONE] && actions[PLACE_CIRCLE_STONE]) {
			printf("You go north into the temple.\n\n");
			*current_location = TEMPLE10;
		} else {
			printf("The north door is shut tight, it won't move.\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		if (actions[TEMPLE_ENTRANCE_EAST]) {
			printf("You go east into part of the temple.\n\n");
			*current_location = TEMPLE3;
		} else {
			printf("The east door is closed, it won't budge.\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		if (actions[TEMPLE_ENTRANCE_WEST]) {
			printf("You go east into part of the temple.\n\n");
			*current_location = TEMPLE2;
		} else {
			printf("The east door is closed, it won't budge.\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You swim back up to the shore.\n\n");
		*current_location = BEACH;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE2(char name[], int *current_location, bool actions[], int *coins) {
	static int moves[4] = { 1, 1, 1, 1 };
	static int num_moves = 0;
	int correct_moves[4] = { 3, 0, 1, 2 };
	
	printf("There is a grid of nine tiles on the floor here.\n");
	if (!actions[TEMPLE_PUZZLE1_SOLVED]) {
		printf("The grid on the floor with the BLOCK '#' looks like this:\n %c | %c | %c\n-------------\n %c | %c | %c\n-------------\n %c | %c | %c\n\n", 
		actions[TEMPLE_PUZZLE1_BLOCK0] ? '#' : ' ',
		actions[TEMPLE_PUZZLE1_BLOCK1] ? '#' : ' ',
		actions[TEMPLE_PUZZLE1_BLOCK2] ? '#' : ' ',
		actions[TEMPLE_PUZZLE1_BLOCK3] ? '#' : ' ',
		actions[TEMPLE_PUZZLE1_BLOCK4] ? '#' : ' ',
		actions[TEMPLE_PUZZLE1_BLOCK5] ? '#' : ' ',
		actions[TEMPLE_PUZZLE1_BLOCK6] ? '#' : ' ',
		actions[TEMPLE_PUZZLE1_BLOCK7] ? '#' : ' ',
		actions[TEMPLE_PUZZLE1_BLOCK8] ? '#' : ' '); 
		
		printf("The door to the west is closed, the only exit is to the EAST.\n\n");  
	} else {
		printf("The block has sunk into the grid.\nThere are open doorways to the EAST and WEST.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "move block") == 0 || strcmp(chosen_action, "push block") == 0 || strcmp(chosen_action, "shove block") == 0) {
		printf("MOVE BLOCK in which direction?\n\n");
	} else if (strcmp(chosen_action, "move block north") == 0 || strcmp(chosen_action, "push block north") == 0 || strcmp(chosen_action, "shove block north") == 0) {
		if (!actions[TEMPLE_PUZZLE1_SOLVED]) {
			if (actions[TEMPLE_PUZZLE1_BLOCK3]) {
				printf("You move the block towards the north.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK3] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK0] = 1;
				moves[num_moves] = 0;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK4]) {
				printf("You move the block towards the north.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK4] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK1] = 1;
				moves[num_moves] = 1;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK5]) {
				printf("You move the block towards the north.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK5] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK2] = 1;
				moves[num_moves] = 2;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK6]) {
				printf("You move the block towards the north.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK6] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK3] = 1;
				moves[num_moves] = 3;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK7]) {
				printf("You move the block towards the north.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK7] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK4] = 1;
				moves[num_moves] = 4;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK8]) {
				printf("You move the block towards the north.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK8] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK5] = 1;
				moves[num_moves] = 5;
				num_moves++;
			} else {
				printf("The block won't go any further in that direction...\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move block east") == 0 || strcmp(chosen_action, "push block east") == 0 || strcmp(chosen_action, "shove block east") == 0) {
		if (!actions[TEMPLE_PUZZLE1_SOLVED]) {
			if (actions[TEMPLE_PUZZLE1_BLOCK1]) {
				printf("You move the block towards the east.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK1] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK2] = 1;
				moves[num_moves] = 2;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK4]) {
				printf("You move the block towards the east.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK4] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK5] = 1;
				moves[num_moves] = 5;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK7]) {
				printf("You move the block towards the east.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK7] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK8] = 1;
				moves[num_moves] = 8;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK0]) {
				printf("You move the block towards the east.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK0] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK1] = 1;
				moves[num_moves] = 1;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK3]) {
				printf("You move the block towards the east.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK3] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK4] = 1;
				moves[num_moves] = 4;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK6]) {
				printf("You move the block towards the east.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK6] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK7] = 1;
				moves[num_moves] = 7;
				num_moves++;
			} else {
				printf("The block won't go any further in that direction...\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move block west") == 0 || strcmp(chosen_action, "push block west") == 0 || strcmp(chosen_action, "shove block west") == 0) {
		if (!actions[TEMPLE_PUZZLE1_SOLVED]) {
			if (actions[TEMPLE_PUZZLE1_BLOCK1]) {
				printf("You move the block towards the west.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK1] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK0] = 1;
				moves[num_moves] = 0;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK4]) {
				printf("You move the block towards the west.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK4] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK3] = 1;
				moves[num_moves] = 3;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK7]) {
				printf("You move the block towards the west.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK7] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK6] = 1;
				moves[num_moves] = 6;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK2]) {
				printf("You move the block towards the west.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK2] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK1] = 1;
				moves[num_moves] = 1;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK5]) {
				printf("You move the block towards the west.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK5] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK4] = 1;
				moves[num_moves] = 4;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK8]) {
				printf("You move the block towards the west.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK8] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK7] = 1;
				moves[num_moves] = 7;
				num_moves++;
			} else {
				printf("The block won't go any further in that direction...\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move block south") == 0 || strcmp(chosen_action, "push block south") == 0 || strcmp(chosen_action, "shove block south") == 0) {
		if (!actions[TEMPLE_PUZZLE1_SOLVED]) {
			if (actions[TEMPLE_PUZZLE1_BLOCK3]) {
				printf("You move the block towards the south.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK3] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK6] = 1;
				moves[num_moves] = 6;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK4]) {
				printf("You move the block towards the south.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK4] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK7] = 1;
				moves[num_moves] = 7;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK5]) {
				printf("You move the block towards the south.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK5] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK8] = 1;
				moves[num_moves] = 8;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK0]) {
				printf("You move the block towards the south.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK0] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK3] = 1;
				moves[num_moves] = 3;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK1]) {
				printf("You move the block towards the south.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK1] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK4] = 1;
				moves[num_moves] = 4;
				num_moves++;
			} else if (actions[TEMPLE_PUZZLE1_BLOCK2]) {
				printf("You move the block towards the south.\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK2] = 0;
				actions[TEMPLE_PUZZLE1_BLOCK5] = 1;
				moves[num_moves] = 5;
				num_moves++;
			} else {
				printf("The block won't go any further in that direction...\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You exit the room to the east.\n\n");
		*current_location = TEMPLE1;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		if (!actions[TEMPLE_PUZZLE1_SOLVED]) {
			printf("The door to the west is closed completely...\n\n");
		} else {
			printf("You enter another room to the west.\n\n");
			*current_location = TEMPLE4;
		}
	} else {
		printInvalid();
	}
	
	if (!actions[TEMPLE_PUZZLE1_SOLVED] && num_moves == 4) {
		bool puzzle_matches = 1;
		for (int i = 0; i < 4; i++) {
			if (moves[i] != correct_moves[i]) {
				puzzle_matches = 0;
				printf("The stone block moves on its own back to the center of the grid!\n\n");
				actions[TEMPLE_PUZZLE1_BLOCK4] = 1;
				if (actions[TEMPLE_PUZZLE1_BLOCK0]) {
					actions[TEMPLE_PUZZLE1_BLOCK0] = 0;
				} else if (actions[TEMPLE_PUZZLE1_BLOCK1]) {
					actions[TEMPLE_PUZZLE1_BLOCK1] = 0;
				} else if (actions[TEMPLE_PUZZLE1_BLOCK2]) {
					actions[TEMPLE_PUZZLE1_BLOCK2] = 0;
				} else if (actions[TEMPLE_PUZZLE1_BLOCK3]) {
					actions[TEMPLE_PUZZLE1_BLOCK3] = 0;
				} else if (actions[TEMPLE_PUZZLE1_BLOCK5]) {
					actions[TEMPLE_PUZZLE1_BLOCK5] = 0;
				} else if (actions[TEMPLE_PUZZLE1_BLOCK6]) {
					actions[TEMPLE_PUZZLE1_BLOCK6] = 0;
				} else if (actions[TEMPLE_PUZZLE1_BLOCK7]) {
					actions[TEMPLE_PUZZLE1_BLOCK7] = 0;
				} else if (actions[TEMPLE_PUZZLE1_BLOCK8]) {
					actions[TEMPLE_PUZZLE1_BLOCK8] = 0;
				}
				num_moves = 0;
				break;
			}
		}
		if (puzzle_matches) {
			printf("The stone block suddenly sinks into the grid!\nThe door to the west slowly grinds open.\n\n"); 
			actions[TEMPLE_PUZZLE1_SOLVED] = 1;
		}
	}
	
	return 1;
}

bool room_TEMPLE3(char name[], int *current_location, bool actions[], int *coins) {
	printf("Looking around the empty stone room, the only thing to really note are some SYMBOLS inscribed on the wall.\nThere are open doorways to the EAST and WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check symbols") == 0 || strcmp(chosen_action, "examine symbols") == 0 || strcmp(chosen_action, "look at symbols") == 0 || strcmp(chosen_action, "investigate symbols") == 0 || strcmp(chosen_action, "view symbols") == 0) {
		printf("The symbols on the wall look like this: <^>_\nIt looks like the end has crumbled apart over time...\n\n");
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You head through the doorway to the east.\n\n");
		*current_location = TEMPLE5;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go west back outside this part of the temple.\n\n");
		*current_location = TEMPLE1;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE4(char name[], int *current_location, bool actions[], int *coins) {
	printf("In this room, the only thing noticeable are some SYMBOLS carved into the wall.\nThere are open doorways to the NORTH, EAST, and WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check symbols") == 0 || strcmp(chosen_action, "examine symbols") == 0 || strcmp(chosen_action, "look at symbols") == 0 || strcmp(chosen_action, "investigate symbols") == 0 || strcmp(chosen_action, "view symbols") == 0) {
		printf("The carved symbols appear like this:\n o |                 |   \n-------           -------\n   |                 | o \nIt appears the middle part is missing, there is a chunk taken from the wall there?\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You head north.\n\n");
		*current_location = TEMPLE7;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You head back east.\n\n");
		*current_location = TEMPLE2;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go towards the west.\n\n");
		*current_location = TEMPLE6;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE5(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
		printf("There are BLOCKs around the ground, on multiple grids, a LEFT BLOCK, MIDDLE BLOCK, and a RIGHT BLOCK.\n\n");
		printf("The grids and BLOCKs '#' on the ground appear like this:\n %c | %c    %c | %c    %c | %c \n-------  -------  -------\n %c | %c    %c | %c    %c | %c \n\n",
		actions[TEMPLE_PUZZLE2_LEFT1] ? '#' : ' ',
		actions[TEMPLE_PUZZLE2_LEFT2] ? '#' : ' ',
		actions[TEMPLE_PUZZLE2_MIDDLE1] ? '#' : ' ',
		actions[TEMPLE_PUZZLE2_MIDDLE2] ? '#' : ' ',
		actions[TEMPLE_PUZZLE2_RIGHT1] ? '#' : ' ',
		actions[TEMPLE_PUZZLE2_RIGHT2] ? '#' : ' ',
		actions[TEMPLE_PUZZLE2_LEFT3] ? '#' : ' ',
		actions[TEMPLE_PUZZLE2_LEFT4] ? '#' : ' ',
		actions[TEMPLE_PUZZLE2_MIDDLE3] ? '#' : ' ',
		actions[TEMPLE_PUZZLE2_MIDDLE4] ? '#' : ' ',
		actions[TEMPLE_PUZZLE2_RIGHT3] ? '#' : ' ',
		actions[TEMPLE_PUZZLE2_RIGHT4] ? '#' : ' ');
		printf("The doors to the north and east are closed. The only exit currently is to the WEST.\n\n");
	} else {
		printf("There some grids on the ground, and open doorways to the NORTH, EAST, and WEST.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "move left block") == 0 || strcmp(chosen_action, "push left block") == 0 || strcmp(chosen_action, "shove left block") == 0) {
		printf("MOVE LEFT BLOCK in which direction?\n\n");
	} else if (strcmp(chosen_action, "move middle block") == 0 || strcmp(chosen_action, "push middle block") == 0 || strcmp(chosen_action, "shove middle block") == 0) {
		printf("MOVE MIDDLE BLOCK in which direction?\n\n");
	} else if (strcmp(chosen_action, "move right block") == 0 || strcmp(chosen_action, "push right block") == 0 || strcmp(chosen_action, "shove right block") == 0) {
		printf("MOVE RIGHT BLOCK in which direction?\n\n");
	} else if (strcmp(chosen_action, "move left block north") == 0 || strcmp(chosen_action, "push left block north") == 0 || strcmp(chosen_action, "shove left block north") == 0) {
		if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
			if (actions[TEMPLE_PUZZLE2_LEFT3]) {
				printf("You move the left block to the north.\n\n");
				actions[TEMPLE_PUZZLE2_LEFT3] = 0;
				actions[TEMPLE_PUZZLE2_LEFT1] = 1;
			} else if (actions[TEMPLE_PUZZLE2_LEFT4]) {
				printf("You move the left block to the north.\n\n");
				actions[TEMPLE_PUZZLE2_LEFT4] = 0;
				actions[TEMPLE_PUZZLE2_LEFT2] = 1;
			} else {
				printf("The left block won't go any further north!\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move left block east") == 0 || strcmp(chosen_action, "push left block east") == 0 || strcmp(chosen_action, "shove left block east") == 0) {
		if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
			if (actions[TEMPLE_PUZZLE2_LEFT1]) {
				printf("You move the left block to the east.\n\n");
				actions[TEMPLE_PUZZLE2_LEFT1] = 0;
				actions[TEMPLE_PUZZLE2_LEFT2] = 1;
			} else if (actions[TEMPLE_PUZZLE2_LEFT3]) {
				printf("You move the left block to the east.\n\n");
				actions[TEMPLE_PUZZLE2_LEFT3] = 0;
				actions[TEMPLE_PUZZLE2_LEFT4] = 1;
			} else {
				printf("The left block won't go any further east!\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move left block west") == 0 || strcmp(chosen_action, "push left block west") == 0 || strcmp(chosen_action, "shove left block west") == 0) {
		if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
			if (actions[TEMPLE_PUZZLE2_LEFT2]) {
				printf("You move the left block to the west.\n\n");
				actions[TEMPLE_PUZZLE2_LEFT2] = 0;
				actions[TEMPLE_PUZZLE2_LEFT1] = 1;
			} else if (actions[TEMPLE_PUZZLE2_LEFT4]) {
				printf("You move the left block to the west.\n\n");
				actions[TEMPLE_PUZZLE2_LEFT4] = 0;
				actions[TEMPLE_PUZZLE2_LEFT3] = 1;
			} else {
				printf("The left block won't go any further west!\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move left block south") == 0 || strcmp(chosen_action, "push left block south") == 0 || strcmp(chosen_action, "shove left block south") == 0) {
		if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
			if (actions[TEMPLE_PUZZLE2_LEFT1]) {
				printf("You move the left block to the south.\n\n");
				actions[TEMPLE_PUZZLE2_LEFT1] = 0;
				actions[TEMPLE_PUZZLE2_LEFT3] = 1;
			} else if (actions[TEMPLE_PUZZLE2_LEFT2]) {
				printf("You move the left block to the south.\n\n");
				actions[TEMPLE_PUZZLE2_LEFT2] = 0;
				actions[TEMPLE_PUZZLE2_LEFT4] = 1;
			} else {
				printf("The left block won't go any further south!\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move middle block north") == 0 || strcmp(chosen_action, "push middle block north") == 0 || strcmp(chosen_action, "shove middle block north") == 0) {
		if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
			if (actions[TEMPLE_PUZZLE2_MIDDLE3]) {
				printf("You move the middle block to the north.\n\n");
				actions[TEMPLE_PUZZLE2_MIDDLE3] = 0;
				actions[TEMPLE_PUZZLE2_MIDDLE1] = 1;
			} else if (actions[TEMPLE_PUZZLE2_MIDDLE4]) {
				printf("You move the middle block to the north.\n\n");
				actions[TEMPLE_PUZZLE2_MIDDLE4] = 0;
				actions[TEMPLE_PUZZLE2_MIDDLE2] = 1;
			} else {
				printf("The middle block won't go any further north!\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move middle block east") == 0 || strcmp(chosen_action, "push middle block east") == 0 || strcmp(chosen_action, "shove middle block east") == 0) {
		if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
			if (actions[TEMPLE_PUZZLE2_MIDDLE1]) {
				printf("You move the middle block to the east.\n\n");
				actions[TEMPLE_PUZZLE2_MIDDLE1] = 0;
				actions[TEMPLE_PUZZLE2_MIDDLE2] = 1;
			} else if (actions[TEMPLE_PUZZLE2_MIDDLE3]) {
				printf("You move the middle block to the east.\n\n");
				actions[TEMPLE_PUZZLE2_MIDDLE3] = 0;
				actions[TEMPLE_PUZZLE2_MIDDLE4] = 1;
			} else {
				printf("The middle block won't go any further east!\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move middle block west") == 0 || strcmp(chosen_action, "push middle block west") == 0 || strcmp(chosen_action, "shove middle block west") == 0) {
		if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
			if (actions[TEMPLE_PUZZLE2_MIDDLE2]) {
				printf("You move the middle block to the west.\n\n");
				actions[TEMPLE_PUZZLE2_MIDDLE2] = 0;
				actions[TEMPLE_PUZZLE2_MIDDLE1] = 1;
			} else if (actions[TEMPLE_PUZZLE2_MIDDLE4]) {
				printf("You move the middle block to the west.\n\n");
				actions[TEMPLE_PUZZLE2_MIDDLE4] = 0;
				actions[TEMPLE_PUZZLE2_MIDDLE3] = 1;
			} else {
				printf("The middle block won't go any further west!\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move middle block south") == 0 || strcmp(chosen_action, "push middle block south") == 0 || strcmp(chosen_action, "shove middle block south") == 0) {
		if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
			if (actions[TEMPLE_PUZZLE2_MIDDLE1]) {
				printf("You move the middle block to the south.\n\n");
				actions[TEMPLE_PUZZLE2_MIDDLE1] = 0;
				actions[TEMPLE_PUZZLE2_MIDDLE3] = 1;
			} else if (actions[TEMPLE_PUZZLE2_MIDDLE2]) {
				printf("You move the middle block to the south.\n\n");
				actions[TEMPLE_PUZZLE2_MIDDLE2] = 0;
				actions[TEMPLE_PUZZLE2_MIDDLE4] = 1;
			} else {
				printf("The middle block won't go any further south!\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move right block north") == 0 || strcmp(chosen_action, "push right block north") == 0 || strcmp(chosen_action, "shove right block north") == 0) {
		if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
			if (actions[TEMPLE_PUZZLE2_RIGHT3]) {
				printf("You move the right block to the north.\n\n");
				actions[TEMPLE_PUZZLE2_RIGHT3] = 0;
				actions[TEMPLE_PUZZLE2_RIGHT1] = 1;
			} else if (actions[TEMPLE_PUZZLE2_RIGHT4]) {
				printf("You move the right block to the north.\n\n");
				actions[TEMPLE_PUZZLE2_RIGHT4] = 0;
				actions[TEMPLE_PUZZLE2_RIGHT2] = 1;
			} else {
				printf("The right block won't go any further north!\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move right block east") == 0 || strcmp(chosen_action, "push right block east") == 0 || strcmp(chosen_action, "shove right block east") == 0) {
		if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
			if (actions[TEMPLE_PUZZLE2_RIGHT1]) {
				printf("You move the right block to the east.\n\n");
				actions[TEMPLE_PUZZLE2_RIGHT1] = 0;
				actions[TEMPLE_PUZZLE2_RIGHT2] = 1;
			} else if (actions[TEMPLE_PUZZLE2_RIGHT3]) {
				printf("You move the right block to the east.\n\n");
				actions[TEMPLE_PUZZLE2_RIGHT3] = 0;
				actions[TEMPLE_PUZZLE2_RIGHT4] = 1;
			} else {
				printf("The right block won't go any further east!\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move right block west") == 0 || strcmp(chosen_action, "push right block west") == 0 || strcmp(chosen_action, "shove right block west") == 0) {
		if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
			if (actions[TEMPLE_PUZZLE2_RIGHT2]) {
				printf("You move the right block to the west.\n\n");
				actions[TEMPLE_PUZZLE2_RIGHT2] = 0;
				actions[TEMPLE_PUZZLE2_RIGHT1] = 1;
			} else if (actions[TEMPLE_PUZZLE2_RIGHT4]) {
				printf("You move the right block to the west.\n\n");
				actions[TEMPLE_PUZZLE2_RIGHT4] = 0;
				actions[TEMPLE_PUZZLE2_RIGHT3] = 1;
			} else {
				printf("The right block won't go any further west!\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "move right block south") == 0 || strcmp(chosen_action, "push right block south") == 0 || strcmp(chosen_action, "shove right block south") == 0) {
		if (!actions[TEMPLE_PUZZLE2_SOLVED]) {
			if (actions[TEMPLE_PUZZLE2_RIGHT1]) {
				printf("You move the right block to the south.\n\n");
				actions[TEMPLE_PUZZLE2_RIGHT1] = 0;
				actions[TEMPLE_PUZZLE2_RIGHT3] = 1;
			} else if (actions[TEMPLE_PUZZLE2_RIGHT2]) {
				printf("You move the right block to the south.\n\n");
				actions[TEMPLE_PUZZLE2_RIGHT2] = 0;
				actions[TEMPLE_PUZZLE2_RIGHT4] = 1;
			} else {
				printf("The right block won't go any further south!\n\n");
			}
		} else {
			printf("The block isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (actions[TEMPLE_PUZZLE2_SOLVED]) {
			printf("You head north into another room.\n\n");
			*current_location = TEMPLE9;
		} else {
			printf("The door to the north is shut tight.\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		if (actions[TEMPLE_PUZZLE2_SOLVED]) {
			printf("You head east into another room.\n\n");
			*current_location = TEMPLE8;
		} else {
			printf("The east door is shut and won't budge an inch.\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go towards the west.\n\n");
		*current_location = TEMPLE3;
	} else {
		printInvalid();
	}
	
	if (!actions[TEMPLE_PUZZLE2_SOLVED] && actions[TEMPLE_PUZZLE2_LEFT1] && actions[TEMPLE_PUZZLE2_MIDDLE3] && actions[TEMPLE_PUZZLE2_RIGHT4]) {
		printf("The stone blocks start sinking into the ground!\nThe doors to the NORTH and EAST slide open with the sound of grinding stones.\n\n");
		actions[TEMPLE_PUZZLE2_SOLVED] = 1;
	}
	
	return 1;
}

bool room_TEMPLE6(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[GET_SQUARE_STONE]) {
		printf("The room is full of ornate, stone carvings. There is a SQUARE STONE with the symbol '/|' on it embedded in a column.\n");
	} else {
		printf("The room is full of ornate, stone carvings. There is an empty square-shaped hole in a column where a stone used to be.\n");
	}
	printf("The only exit is to the EAST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check square stone") == 0 || strcmp(chosen_action, "examine square stone") == 0 || strcmp(chosen_action, "look at square stone") == 0 || strcmp(chosen_action, "investigate square stone") == 0 || strcmp(chosen_action, "view square stone") == 0) {
		if (!actions[GET_SQUARE_STONE]) {
			printf("The stone appears to be kind of loose in the column, possibly removeable?\n\n");
		} else {
			printf("The square stone isn't there anymore!\n\n");
		}
	} else if (strcmp(chosen_action, "get square stone") == 0 || strcmp(chosen_action, "pick up square stone") == 0 || strcmp(chosen_action, "grab square stone") == 0 || strcmp(chosen_action, "take square stone") == 0 || strcmp(chosen_action, "acquire square stone") == 0 || strcmp(chosen_action, "obtain square stone") == 0) {
		if (!actions[GET_SQUARE_STONE]) {
			printf("You grab the square stone from the column.\n\n");
			actions[GET_SQUARE_STONE] = 1;
		} else {
			printf("You already took the square stone!\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You head east out a doorway.\n\n");
		*current_location = TEMPLE4;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE7(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[PLACE_CIRCLE_STONE]) {
		printf("Besides all the stone carvings, you notice a column with a circle-shaped hole in it.\n");
	} else {
		printf("The circle-shaped stone sits in a column, the ':|' is glowing an eerie blue color.\n");
	}
	printf("The only exit is to the SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "place circle stone") == 0 || strcmp(chosen_action, "set circle stone") == 0 || strcmp(chosen_action, "put circle stone") == 0) {
		if (!actions[GET_CIRCLE_STONE]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_CIRCLE_STONE] && !actions[PLACE_CIRCLE_STONE]) {
			printf("You place the circle stone in the circle-shaped hole. It begins glowing blue!\n\n");
			actions[PLACE_CIRCLE_STONE] = 1;
		} else if (actions[PLACE_CIRCLE_STONE]) {
			printf("You already placed the circle stone in the column!\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go southward.\n\n");
		*current_location = TEMPLE4;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE8(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[GET_CIRCLE_STONE]) {
		printf("The room is covered in fancy, stone carvings. There is a CIRCLE STONE with the symbol ':|' on it embedded in a column.\n");
	} else {
		printf("The room is covered in fancy, stone carvings. There is a circle-shaped hole where a stone used to be in the column.\n");
	}
	printf("The only exit is to the WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check circle stone") == 0 || strcmp(chosen_action, "examine circle stone") == 0 || strcmp(chosen_action, "look at circle stone") == 0 || strcmp(chosen_action, "investigate circle stone") == 0 || strcmp(chosen_action, "view circle stone") == 0) {
		if (!actions[GET_SQUARE_STONE]) {
			printf("The stone might be able to be removed?\n\n");
		} else {
			printf("There is no circle stone there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "get circle stone") == 0 || strcmp(chosen_action, "pick up circle stone") == 0 || strcmp(chosen_action, "grab circle stone") == 0 || strcmp(chosen_action, "take circle stone") == 0 || strcmp(chosen_action, "acquire circle stone") == 0 || strcmp(chosen_action, "obtain circle stone") == 0) {
		if (!actions[GET_CIRCLE_STONE]) {
			printf("The circle stone easily comes out of the column, so you take it.\n\n");
			actions[GET_CIRCLE_STONE] = 1;
		} else {
			printf("You already got the circle stone!\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go eastward past a doorway.\n\n");
		*current_location = TEMPLE5;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE9(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[PLACE_SQUARE_STONE]) {
		printf("Amongst all the intricately carved details of the stones in this room, there is a column with an empty square-shaped indent.\n");
	} else {
		printf("The square-shaped stone now sits in a column, strangely glowing a pale, blue-ish color.\n");
	}
	printf("The only exit is to the SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "place square stone") == 0 || strcmp(chosen_action, "set square stone") == 0 || strcmp(chosen_action, "put square stone") == 0) {
		if (!actions[GET_SQUARE_STONE]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_SQUARE_STONE] && !actions[PLACE_SQUARE_STONE]) {
			printf("You put the square-shaped stone in the square hole. A blue light comes from it now!\n\n");
			actions[PLACE_SQUARE_STONE] = 1;
		} else if (actions[PLACE_SQUARE_STONE]) {
			printf("You already put the square stone in the column!\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go southward.\n\n");
		*current_location = TEMPLE5;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE10(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[TEMPLE_WATER_DRAINED]) {
		printf("You enter the main part of the temple.\nThe door behind you slams shut, and you start to struggle to breathe!\nThe spell must be wearing off!\nYou struggle for a breath, wondering what you possibly could have done differently, as the room fades to blackness.\nGAME OVER...\n??? You can breathe again!\nYou now notice that all the water has drained out of the place, you must have overlooked this as you were struggling for air.\n");
		actions[TEMPLE_WATER_DRAINED] = 1;
	}
	printf("There are three doors, LEFT, MIDDLE, and RIGHT.\nThere are also four raised TILEs on the ground, LEFT, MIDDLE, RIGHT, and one in the CORNER.\n");
	if (!actions[TEMPLE_PUZZLE3_DOOR_A]) {
		printf("The LEFT door is closed.\n");
	} else {
		printf("The LEFT door is open.\n");
	}
	if (!actions[TEMPLE_PUZZLE3_DOOR_B]) {
		printf("The MIDDLE door is closed.\n");
	} else {
		printf("The MIDDLE door is open.\n");
	}
	if (!actions[TEMPLE_PUZZLE3_DOOR_C]) {
		printf("The RIGHT door is closed.\n");
	} else {
		printf("The RIGHT door is open.\n");
	}
	printf("The door behind you is now closed.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "push left tile") == 0 || strcmp(chosen_action, "press left tile") == 0 || strcmp(chosen_action, "depress left tile") == 0) {
		printf("You step on the left tile, it presses down until you step off of it.\n");
		if (!actions[TEMPLE_PUZZLE3_DOOR_A] && !actions[TEMPLE_PUZZLE3_DOOR_C]) {
			printf("You hear the sound of grinding stones.\n\n");
			actions[TEMPLE_PUZZLE3_DOOR_A] = 1;
			actions[TEMPLE_PUZZLE3_DOOR_C] = 1;
		} else if (actions[TEMPLE_PUZZLE3_DOOR_A] && actions[TEMPLE_PUZZLE3_DOOR_C]) {
			printf("You hear the sound of grinding stones.\n\n");
			actions[TEMPLE_PUZZLE3_DOOR_A] = 0;
			actions[TEMPLE_PUZZLE3_DOOR_C] = 0;
		} else {
			printf("Nothing happens...\n\n");
		}
	} else if (strcmp(chosen_action, "push middle tile") == 0 || strcmp(chosen_action, "press middle tile") == 0 || strcmp(chosen_action, "depress middle tile") == 0) {
		printf("You step on the middle tile, it presses down until you step off of it.\n");
		if (!actions[TEMPLE_PUZZLE3_DOOR_B]) {
			printf("You hear the sound of grinding stones.\n\n");
			actions[TEMPLE_PUZZLE3_DOOR_B] = 1;
		} else if (actions[TEMPLE_PUZZLE3_DOOR_B]) {
			bool movement = 0;
			if (actions[TEMPLE_PUZZLE3_DOOR_A]) {
				actions[TEMPLE_PUZZLE3_DOOR_A] = 0;
				movement = 1;			
			}
			if (actions[TEMPLE_PUZZLE3_DOOR_C]) {
				actions[TEMPLE_PUZZLE3_DOOR_C] = 0;
				movement = 1;			
			}
			if (movement) {
				printf("You hear the sound of grinding stones.\n\n");
			} else {
				printf("Nothing happens...\n\n");
			}
		} else {
			printf("Nothing happens...\n\n");
		}
	} else if (strcmp(chosen_action, "push right tile") == 0 || strcmp(chosen_action, "press right tile") == 0 || strcmp(chosen_action, "depress right tile") == 0) {
		printf("You step on the right tile, it presses down until you step off of it.\n");
		if (!actions[TEMPLE_PUZZLE3_DOOR_A]) {
			actions[TEMPLE_PUZZLE3_DOOR_A] = 1;
		} else if (actions[TEMPLE_PUZZLE3_DOOR_A]) {
			actions[TEMPLE_PUZZLE3_DOOR_A] = 0;
		}
		printf("You hear the sound of grinding stones.\n\n");
	} else if (strcmp(chosen_action, "push corner tile") == 0 || strcmp(chosen_action, "press corner tile") == 0 || strcmp(chosen_action, "depress corner tile") == 0) {
		printf("You step on the corner tile, it presses down until you step off of it.\n");
		bool movement = 0;
		if (actions[TEMPLE_PUZZLE3_DOOR_A]) {
			actions[TEMPLE_PUZZLE3_DOOR_A] = 0;
			movement = 1;			
		}
		if (actions[TEMPLE_PUZZLE3_DOOR_B]) {
			actions[TEMPLE_PUZZLE3_DOOR_B] = 0;
			movement = 1;			
		}
		if (actions[TEMPLE_PUZZLE3_DOOR_C]) {
			actions[TEMPLE_PUZZLE3_DOOR_C] = 0;
			movement = 1;			
		}
		if (actions[TEMPLE_PUZZLE3_DOOR_D]) {
			actions[TEMPLE_PUZZLE3_DOOR_D] = 0;
			movement = 1;			
		}
		if (movement) {
			printf("You hear the sound of grinding stones.\n\n");
		} else {
			printf("Nothing happens...\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You want to go north, but you have the choice to GO LEFT, MIDDLE, or RIGHT.\n\n");
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You try to go back through the original entrance, but the door won't move in the slightest.\n\n");
	} else if (strcmp(chosen_action, "go left") == 0 || strcmp(chosen_action, "head left") == 0 || strcmp(chosen_action, "walk left") == 0 || strcmp(chosen_action, "travel left") == 0 || strcmp(chosen_action, "move left") == 0 || strcmp(chosen_action, "proceed left") == 0 || strcmp(chosen_action, "advance left") == 0 || strcmp(chosen_action, "leave left") == 0) {
		if (actions[TEMPLE_PUZZLE3_DOOR_A]) {
			printf("You go through the doorway to the left.\n\n");
			*current_location = TEMPLE11;		
		} else {
			printf("The door to the left is closed!\n\n");
		}
	} else if (strcmp(chosen_action, "go middle") == 0 || strcmp(chosen_action, "head middle") == 0 || strcmp(chosen_action, "walk middle") == 0 || strcmp(chosen_action, "travel middle") == 0 || strcmp(chosen_action, "move middle") == 0 || strcmp(chosen_action, "proceed middle") == 0 || strcmp(chosen_action, "advance middle") == 0 || strcmp(chosen_action, "leave middle") == 0) {
		if (actions[TEMPLE_PUZZLE3_DOOR_B]) {
			printf("You go through the doorway in the middle.\n\n");
			*current_location = TEMPLE13;		
		} else {
			printf("The door in the middle is closed!\n\n");
		}
	} else if (strcmp(chosen_action, "go right") == 0 || strcmp(chosen_action, "head right") == 0 || strcmp(chosen_action, "walk right") == 0 || strcmp(chosen_action, "travel right") == 0 || strcmp(chosen_action, "move right") == 0 || strcmp(chosen_action, "proceed right") == 0 || strcmp(chosen_action, "advance right") == 0 || strcmp(chosen_action, "leave right") == 0) {
		if (actions[TEMPLE_PUZZLE3_DOOR_C]) {
			printf("You go through the doorway on the right.\n\n");
			*current_location = TEMPLE12;		
		} else {
			printf("The door on the right is closed!\n\n");
		}
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE11(char name[], int *current_location, bool actions[], int *coins) {
	printf("The only thing to note in this room is a raised TILE in the center.\nThe only exit is to the SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "push tile") == 0 || strcmp(chosen_action, "press tile") == 0 || strcmp(chosen_action, "depress tile") == 0) {
		printf("You step on the tile, it presses down until you step off of it.\n");
		bool movement = 0;
		if (actions[TEMPLE_PUZZLE3_DOOR_D]) {
			actions[TEMPLE_PUZZLE3_DOOR_D] = 0;
			movement = 1;
		} else if (!actions[TEMPLE_PUZZLE3_DOOR_D] && actions[TEMPLE_PUZZLE3_DOOR_B]) {
			actions[TEMPLE_PUZZLE3_DOOR_B] = 0;
			movement = 1;
		}
		if (movement) {
			printf("You hear the sound of grinding stones.\n\n");
		} else {
			printf("Nothing happens...\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go back south.\n\n");
		*current_location = TEMPLE10;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE12(char name[], int *current_location, bool actions[], int *coins) {
	printf("All there is here is a raised TILE in the middle of the room.\nThe only exit is to the SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "push tile") == 0 || strcmp(chosen_action, "press tile") == 0 || strcmp(chosen_action, "depress tile") == 0) {
		printf("You step on the tile, it presses down until you step off of it.\n");
		bool movement = 0;
		if (actions[TEMPLE_PUZZLE3_DOOR_A]) {
			actions[TEMPLE_PUZZLE3_DOOR_A] = 0;
			movement = 1;
		} else if (!actions[TEMPLE_PUZZLE3_DOOR_A] && !actions[TEMPLE_PUZZLE3_DOOR_D]) {
			actions[TEMPLE_PUZZLE3_DOOR_D] = 1;
			movement = 1;
		}
		if (movement) {
			printf("You hear the sound of grinding stones.\n\n");
		} else {
			printf("Nothing happens...\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go back south.\n\n");
		*current_location = TEMPLE10;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE13(char name[], int *current_location, bool actions[], int *coins) {
	printf("All there is here is a raised TILE in the middle of the room.\n");
	if (!actions[TEMPLE_PUZZLE3_DOOR_D]) {
		printf("The only exit is to the SOUTH.\n\n");
	} else {
		printf("There are open doors to the NORTH and SOUTH.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "push tile") == 0 || strcmp(chosen_action, "press tile") == 0 || strcmp(chosen_action, "depress tile") == 0) {
		printf("You step on the tile, it presses down until you step off of it.\n");
		bool movement = 0;
		if (!actions[TEMPLE_PUZZLE3_DOOR_A]) {
			actions[TEMPLE_PUZZLE3_DOOR_A] = 1;
			movement = 1;
		}
		if (actions[TEMPLE_PUZZLE3_DOOR_C]) {
			actions[TEMPLE_PUZZLE3_DOOR_C] = 0;
			movement = 1;
		}
		if (movement) {
			printf("You hear the sound of grinding stones.\n\n");
		} else {
			printf("Nothing happens...\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (!actions[TEMPLE_PUZZLE3_DOOR_D]) {
			printf("The door to the north is closed!\n\n");
		} else {
			printf("You go through the doorway to the north.\n\n");
			*current_location = TEMPLE14;
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go back south.\n\n");
		*current_location = TEMPLE10;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE14(char name[], int *current_location, bool actions[], int *coins) {
	printf("There are many strange carvings in stone all around the room, along with a statue with wild looking eyes with its tongue sticking out.\nThere are doors leading NORTH, EAST, WEST, and SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You head north.\n\n");
		*current_location = TEMPLE15;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go through the eastern doorway.\n\n");
		*current_location = TEMPLE17;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You enter the door to the west.\n\n");
		*current_location = TEMPLE16;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You head southward, to where you came from.\n\n");
		*current_location = TEMPLE13;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE15(char name[], int *current_location, bool actions[], int *coins) {
	static int buttons_pressed[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	static int num_pressed = 0;
	int correct_pressed[12] = { 1, 2, 2, 3, 1, 2, 2, 3, 1, 2, 2, 3 };
	bool pressed = 0;
	
	printf("In this room are three TILEs, LEFT, MIDDLE, and RIGHT.\nFrom left to right are these symbols on the tiles: '#', '%%', and '$'\n");
	if (actions[TEMPLE_PUZZLE4_SOLVED] && !actions[GET_BLUE_GEM]) {
		printf("There is a stone statue that's part of a column with its hands held out in front of it, it is holding a BLUE GEM.\n");
	} else {
		printf("There is a stone statue that's part of a column with its hands held out in front of it, its hands are empty.\n");
	}
	printf("The exit is to the SOUTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "push left tile") == 0 || strcmp(chosen_action, "press left tile") == 0 || strcmp(chosen_action, "depress left tile") == 0) {
		if (!actions[TEMPLE_PUZZLE4_SOLVED]) {
			printf("You step on the left tile with the symbol '#' on it, it presses down until you step off of it.\n");
			buttons_pressed[num_pressed] = 1;
			num_pressed++;
			pressed = 1;
		} else {
			printf("You don't need to do that anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "push middle tile") == 0 || strcmp(chosen_action, "press middle tile") == 0 || strcmp(chosen_action, "depress middle tile") == 0) {
		if (!actions[TEMPLE_PUZZLE4_SOLVED]) {
			printf("You step on the middle tile with the symbol '%%' on it, it presses down until you step off of it.\n");
			buttons_pressed[num_pressed] = 2;
			num_pressed++;
			pressed = 1;
		} else {
			printf("You don't need to do that anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "push right tile") == 0 || strcmp(chosen_action, "press right tile") == 0 || strcmp(chosen_action, "depress right tile") == 0) {
		if (!actions[TEMPLE_PUZZLE4_SOLVED]) {
			printf("You step on the right tile with the symbol '$' on it, it presses down until you step off of it.\n");
			buttons_pressed[num_pressed] = 3;
			num_pressed++;
			pressed = 1;
		} else {
			printf("You don't need to do that anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "get blue gem") == 0 || strcmp(chosen_action, "pick up blue gem") == 0 || strcmp(chosen_action, "grab blue gem") == 0 || strcmp(chosen_action, "take blue gem") == 0 || strcmp(chosen_action, "acquire blue gem") == 0 || strcmp(chosen_action, "obtain blue gem") == 0) {
		if (!actions[TEMPLE_PUZZLE4_SOLVED]) {
			printf("You don't see anything like that here...\n\n");
		} else if (actions[TEMPLE_PUZZLE4_SOLVED] && !actions[GET_BLUE_GEM]) {
			printf("You grab the blue gem from the statue's hands.\n\n");
			actions[GET_BLUE_GEM] = 1;
		} else if (actions[GET_BLUE_GEM]) {
			printf("You already got the blue gem!\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You leave the room to the south.\n\n");
		*current_location = TEMPLE14;
	} else {
		printInvalid();
	}
	
	if (!actions[TEMPLE_PUZZLE4_SOLVED] && pressed) {
		for (int i = 0; i < num_pressed; i++) {
			if (buttons_pressed[i] != correct_pressed[i]) {
				printf("The door from the room quickly grinds shut, and the room starts filling up with water!\nYou wish the spell was still working, but alas, it is not.\nYou wonder about the mystery of these three tiles, and that's the last thing on your mind as you suffocate and drown in the water.\nGAME OVER\n\n");
				return 0;
			}
		}
		if (num_pressed == 12) {
			printf("You hear the grinding of stones as the column rotates around with the statue.\nOn the other side was another statue, appearing to be holding something shiny in it's outstretched hands.\n\n");
			actions[TEMPLE_PUZZLE4_SOLVED] = 1;
		}
	}

	return 1;
}

bool room_TEMPLE16(char name[], int *current_location, bool actions[], int *coins) {
	printf("The room is full of half-carved STATUES, this must be some kind of storage room for them.\nThe only other detail to note is a pattern of SYMBOLS carved onto one wall.\nEAST is out of this room.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check statues") == 0 || strcmp(chosen_action, "examine statues") == 0 || strcmp(chosen_action, "look at statues") == 0 || strcmp(chosen_action, "investigate statues") == 0 || strcmp(chosen_action, "view statues") == 0) {
		printf("All of these small statues look unfinished.\n\n");
	} else if (strcmp(chosen_action, "check symbols") == 0 || strcmp(chosen_action, "examine symbols") == 0 || strcmp(chosen_action, "look at symbols") == 0 || strcmp(chosen_action, "investigate symbols") == 0 || strcmp(chosen_action, "view symbols") == 0) {
		printf("The symbols look like this:\n\\\\//\\/\\\\\\/\\\\\\/\\\\\\\\//\\//\\\\\\//\\\\\\/\\\\//\\//\\\\\\//\\/\\\\\\\\//\\//\\\\\\//\\/\\/\\\\//\\\\/\\\\\\//\\\\\\\\\\\\//\\///\\\\///\\\\/\\\\//\\//\\\\/\\\\\\//\\\\\\//\\///\\\\//\\/\\/\\\\//\\\\/\\\\\\//\\\\\\\\\\\\//\\//\\\\/\\\\\\\\//\\\\//\\//\\\\/\\\\\\//\\\\\\//\\//\\\\/\\\\\\//\\\\\\//\\//\\\\/\\\\\\\\/\\\\\\//\\\\/\\\\\\//\\\\\\/\\\\//\\\\/\\\\\\//\\\\\\\\\\\\//\\\\/\\\\/\\\\\\/\\\\\\\\//\\///\\\\//\\\\//\\\\//\\///\\\\//\\/\\\\\\\\//\\///\\\\//\\\\/\\\\\\//\\//\\\\\\///\\\\/\\\\//\\//\\\\/\\\\\\/\\/\\\\//\\//\\\\\\//\\///\\\\//\\///\\/\\\\\\\\\\/\\\\//\\///\\/\\\\\\\\\\/\\\\//\\///\\/\\\\\\\\\\/\\\\//\\\\/\\\\\\//\\\\\\\\\\\\//\\\\//\\/\\\\\\\\\\/\\\\//\\\\//\\\\//\\\\//\n\n");
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You leave the room.\n\n");
		*current_location = TEMPLE14;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE17(char name[], int *current_location, bool actions[], int *coins) {
	printf("There is WRITING carved into the wall here.\n");
	if (!actions[PLACE_BLUE_GEM]) {
		printf("To the north is a statue holding its hands outward.\n");
	} else {
		printf("To the NORTH is a statue with a large, gaping mouth.\nIt looks like the mouth may actually be a doorway.\n");
	}
	printf("The exit out of this room is to the WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "place blue gem") == 0 || strcmp(chosen_action, "set blue gem") == 0 || strcmp(chosen_action, "put blue gem") == 0) {
		if (!actions[GET_BLUE_GEM]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_BLUE_GEM] && !actions[PLACE_BLUE_GEM]) {
			printf("You place the blue gem in the hands of the statue.\nThe statue starts rotating around!\nIt turns around revealing another large statue, with a big open mouth.\n\n");
			actions[PLACE_BLUE_GEM] = 1;
		} else if (actions[PLACE_BLUE_GEM]) {
			printf("You already placed the blue gem!\n\n");
		}
	} else if (strcmp(chosen_action, "check writing") == 0 || strcmp(chosen_action, "examine writing") == 0 || strcmp(chosen_action, "look at writing") == 0 || strcmp(chosen_action, "investigate writing") == 0 || strcmp(chosen_action, "view writing") == 0) {
		printf("The writing is a series of symbols, some have been damaged or faded over a long time.\nWhat you can still see reads: #%%%%$#_%%___%%_\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (actions[PLACE_BLUE_GEM]) {
			printf("You enter the mouth of the statue and go into the other room.\n\n");
			*current_location = TEMPLE18;
		} else {
			printf("You see no way to go in that direction...\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You leave the room.\n\n");
		*current_location = TEMPLE14;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_TEMPLE18(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[PUSH_LEFT_STATUE] && !actions[PUSH_RIGHT_STATUE]) {
		printf("There is a strange, circular stone ring at the back of the room, with many symbols carved into it.\n");
	} else {
		printf("The circular stone to the NORTH has a glowing, blue wall of light inside of it.\n");
	}
	printf("There are six statues in the room, three on the left, and three on the right.\n");
	if (!actions[PUSH_LEFT_STATUE]) {
		printf("The middle LEFT STATUE is sticking out from the wall a bit.\n");
	}
	if (!actions[PUSH_RIGHT_STATUE]) {
		printf("The middle RIGHT STATUE is partly away from the wall.\n");
	}
	printf("SOUTH is back through the doorway in the statue.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "move left statue") == 0 || strcmp(chosen_action, "push left statue") == 0 || strcmp(chosen_action, "shove left statue") == 0) {
		if (!actions[PUSH_LEFT_STATUE]) {
			printf("You push the left statue against the wall. It's heavy, but it moves.\n\n");
			actions[PUSH_LEFT_STATUE] = 1;
		} else {
			printf("You already moved the statue...\n\n");
		}
	} else if (strcmp(chosen_action, "move right statue") == 0 || strcmp(chosen_action, "push right statue") == 0 || strcmp(chosen_action, "shove right statue") == 0) {
		if (!actions[PUSH_RIGHT_STATUE]) {
			printf("You shove the right statue towards the wall. It takes a lot, but it does move.\n\n");
			actions[PUSH_RIGHT_STATUE] = 1;
		} else {
			printf("You already moved this statue...\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (actions[PUSH_LEFT_STATUE] && actions[PUSH_RIGHT_STATUE]) {
			printf("You have no idea where it goes, but you enter the blue light...\n\n");
			*current_location = FACILITY1;
		} else {
			printf("You see nowhere you could go to the north...\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south back through the statue's mouth.\n\n");
		*current_location = TEMPLE17;
	} else {
		printInvalid();
	}

	return 1;
}

bool room_FACILITY1(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[FACILITY_INTRO]) {
		printf("The pale, blue light surrounding you fades away.\nYou find yourself in a very different place, that somehow feels strangely and vaguely familiar.\n");
		actions[FACILITY_INTRO] = 1;
	}
	printf("You are in some kind of laboratory.\nThere is a COMPUTER at a desk, next to it is a FOLDER.\nThe desk has a DRAWER and a CABINET.\nThere are doors to the NORTH and EAST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check computer") == 0 || strcmp(chosen_action, "examine computer") == 0 || strcmp(chosen_action, "look at computer") == 0 || strcmp(chosen_action, "investigate computer") == 0 || strcmp(chosen_action, "view computer") == 0) {
		printf("On the computer's screen is some kind of game, where the player is in a cell with a blanket and a chamber pot...\n\n");
	} else if (strcmp(chosen_action, "check folder") == 0 || strcmp(chosen_action, "examine folder") == 0 || strcmp(chosen_action, "look at folder") == 0 || strcmp(chosen_action, "investigate folder") == 0 || strcmp(chosen_action, "view folder") == 0) {
		printf("At the top of the document, it reads: 'EPSILON FACILITY REPORT #4'\nThere is a lot of technical jargon in these documents, but part of it stands out to you:\nThere have been countless reports of people vanishing into clouds of darkness all over the world. Given what we witnessed happen to Subject E, this can't possibly be a coincidence. I believe we may very well have opened Pandora's box, and it seems there is no way to close it. I've also been forgetting so many things, possibly due to my own exposure to The Else. Now I've resorted to leaving notes for myself, and using whatever I can to remind myself. I feel like my mind is scattered everywhere.\nScribbled on one page of the document says: 'e=r'\n\n");
	} else if (strcmp(chosen_action, "check drawer") == 0 || strcmp(chosen_action, "examine drawer") == 0 || strcmp(chosen_action, "look at drawer") == 0 || strcmp(chosen_action, "investigate drawer") == 0 || strcmp(chosen_action, "view drawer") == 0) {
		printf("There are mostly just typical office supplies in this drawer, though you notice a scrap of paper that only says: 'b=n'\n\n");
	} else if (strcmp(chosen_action, "check cabinet") == 0 || strcmp(chosen_action, "examine cabinet") == 0 || strcmp(chosen_action, "look at cabinet") == 0 || strcmp(chosen_action, "investigate cabinet") == 0 || strcmp(chosen_action, "view cabinet") == 0) {
		printf("You almost expect to find bats or mice in here, but instead there are just a bunch of neatly organized electronic devices.\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go through the door to the north.\n\n");
		*current_location = FACILITY2;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		if (actions[GET_KEY_CARD_A]) {
			printf("You use the key card to open the door and go through it.\n\n");
			*current_location = FACILITY7;
		} else {
			printf("The door is locked. Next to the lock there is a device that looks like it can scan something, it has the letter 'A' on it.\n\n");
		}
	} else {
		printInvalid();
	}

	return 1;
}

bool room_FACILITY2(char name[], int *current_location, bool actions[], int *coins) {
	printf("You're in another office room. There is a SAFE sitting on one desk.\nAlso, there is a messy stack of PAPERS on another desk, and a half-full TRASH CAN next to the desks.\nDoors can be found to the EAST and SOUTH.\n\n"); 
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "open safe") == 0) {
		if (!actions[GET_KEY_CARD_A]) {
			int pin;
			printf("Enter the 4-digit pin: ");
			scanf(" %d", &pin);
			if (pin == 1227) {
				printf("The safe clicked open! Inside is a card labeled 'A', so you take it.\n\n");
				actions[GET_KEY_CARD_A] = 1;
			} else {
				printf("The pin didn't work...\n\n");
			}
		} else {
			printf("You already opened the safe!\n\n");
		}
	} else if (strcmp(chosen_action, "check safe") == 0 || strcmp(chosen_action, "examine safe") == 0 || strcmp(chosen_action, "look at safe") == 0 || strcmp(chosen_action, "investigate safe") == 0 || strcmp(chosen_action, "view safe") == 0) {
		if (!actions[GET_KEY_CARD_A]) {
			printf("The safe is locked, it has buttons for the digits 1-9, and appears to have room for 4 digits on its display screen.\n\n");
		} else {
			printf("The safe sits there with its door open, there is nothing else inside of it.\n\n");
		}
	} else if (strcmp(chosen_action, "check papers") == 0 || strcmp(chosen_action, "examine papers") == 0 || strcmp(chosen_action, "look at papers") == 0 || strcmp(chosen_action, "investigate papers") == 0 || strcmp(chosen_action, "view papers") == 0) {
		printf("You go through the stack of papers. It looks like a lot of stuff you don't understand, but you do notice a note on one corner that reads: 'c=f'\n\n");
	} else if (strcmp(chosen_action, "check trash can") == 0 || strcmp(chosen_action, "examine trash can") == 0 || strcmp(chosen_action, "look at trash can") == 0 || strcmp(chosen_action, "investigate trash can") == 0 || strcmp(chosen_action, "view trash can") == 0) {
		printf("Unsurprisingly, there is nothing but trash in there.\n\n");
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go through a door to the east.\n\n");
		*current_location = FACILITY3;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You head south to the room you started in.\n\n");
		*current_location = FACILITY1;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_FACILITY3(char name[], int *current_location, bool actions[], int *coins) {
	printf("In this room, you notice a door to the NORTH surrounded by WINDOWS, with large MACHINES on either side of the door.\nThere is a CLOCK on the wall, along with a WHITEBOARD with a BULLETIN BOARD on one half.\nThe other door is to the WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check windows") == 0 || strcmp(chosen_action, "examine windows") == 0 || strcmp(chosen_action, "look at windows") == 0 || strcmp(chosen_action, "investigate windows") == 0 || strcmp(chosen_action, "view windows") == 0) {
		printf("You peer into the windows and see a strange device aimed at a chair that has wrist and ankle straps on it.\nYou get chills, as this room seems familiar to you.\n\n");
	} else if (strcmp(chosen_action, "check machines") == 0 || strcmp(chosen_action, "examine machines") == 0 || strcmp(chosen_action, "look at machines") == 0 || strcmp(chosen_action, "investigate machines") == 0 || strcmp(chosen_action, "view machines") == 0) {
		printf("You find a folder on top of the machines, so you open it.\nAt the top of the document, it reads: 'EPSILON FACILITY REPORT #3'\nYou don't understand most of what you are reading, but this part stands out:\nWe have absolutely nothing to explain the circumstances of what just happened with Subject E. Inside of their room, we had checked in on them as scheduled. Ten minutes later, we had checked them again, but they were gone! We played back the camera footage, and witnessed them disappear in what could only be described as a 'cloud of darkness'. We've run so many tests since then, went over our numbers, but none of it explains what happened. We've truly gone past the point of no return with this experiment, I only wish we had some real answers.\n\n");
	} else if (strcmp(chosen_action, "check clock") == 0 || strcmp(chosen_action, "examine clock") == 0 || strcmp(chosen_action, "look at clock") == 0 || strcmp(chosen_action, "investigate clock") == 0 || strcmp(chosen_action, "view clock") == 0) {
		printf("The clock is broken, the time on it reads '12:27', but its hands are not moving at all.\n\n");
	} else if (strcmp(chosen_action, "check whiteboard") == 0 || strcmp(chosen_action, "examine whiteboard") == 0 || strcmp(chosen_action, "look at whiteboard") == 0 || strcmp(chosen_action, "investigate whiteboard") == 0 || strcmp(chosen_action, "view whiteboard") == 0) {
		printf("There are very complex equations and formulas scribbled all over the whiteboard.\n\n");
	} else if (strcmp(chosen_action, "check bulletin board") == 0 || strcmp(chosen_action, "examine bulletin board") == 0 || strcmp(chosen_action, "look at bulletin board") == 0 || strcmp(chosen_action, "investigate bulletin board") == 0 || strcmp(chosen_action, "view bulletin board") == 0) {
		printf("There are several papers pinned to the bulletin board.\nYou notice on one of them there is a small note that says: 'g=a'\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (actions[GET_KEY_CARD_A]) {
			printf("You use the key card to open the door and go through it.\n\n");
			*current_location = FACILITY4;
		} else {
			printf("The door is locked. Next to the lock there is a device that looks like it can scan something, it has the letter 'A' on it.\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go westward through the door.\n\n");
		*current_location = FACILITY2;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_FACILITY4(char name[], int *current_location, bool actions[], int *coins) {
	printf("In this room is a large DEVICE which seems to be aimed directly at a CHAIR with straps on the arms and legs.\nIn the EAST, SOUTH, and WEST directions are doors.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check device") == 0 || strcmp(chosen_action, "examine device") == 0 || strcmp(chosen_action, "look at device") == 0 || strcmp(chosen_action, "investigate device") == 0 || strcmp(chosen_action, "view device") == 0) {
		printf("There is a glass lens on the tip of this pointed device, possibly a microscope or maybe a laser of some kind?\n\n");
	} else if (strcmp(chosen_action, "check chair") == 0 || strcmp(chosen_action, "examine chair") == 0 || strcmp(chosen_action, "look at chair") == 0 || strcmp(chosen_action, "investigate chair") == 0 || strcmp(chosen_action, "view chair") == 0) {
		printf("For some reason the very sight of this chair fills you with dread.\n\n");
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You head east through another door.\n\n");
		*current_location = FACILITY5;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You use the key card to open the door and go through it.\n\n");
		*current_location = FACILITY3;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You open the westward door and step through it.\n\n");
		*current_location = FACILITY6;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_FACILITY5(char name[], int *current_location, bool actions[], int *coins) {
	if (actions[PLACE_STONE_PIECES]) {
		printf("There is some WRITING on the wall here. Was that there before?\n");
	}
	printf("This room looks spotless, like it had been deeply cleaned and then left that way.\nThere is only a bed, a toilet, a table, and a metal seat next to the table.\nUp in one corner of the room is a small camera.\nYou see nothing of interest, only that you definitely get the feeling like you've been here before.\nThe only exit is to the WEST.\n\n");
	
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go back through the way you came.\n\n");
		*current_location = FACILITY4;
	} else if (strcmp(chosen_action, "check writing") == 0 || strcmp(chosen_action, "examine writing") == 0 || strcmp(chosen_action, "look at writing") == 0 || strcmp(chosen_action, "investigate writing") == 0 || strcmp(chosen_action, "view writing") == 0) {
		if (actions[PLACE_STONE_PIECES]) {
			printf("The writing on the wall says: 'The imagination knows no confinement. -stringzzz :3'\n\n");
		} else {
			printf("There's nothing like that here...\n\n");
		}
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_FACILITY6(char name[], int *current_location, bool actions[], int *coins) {
	printf("This looks like a storage room. There is a half-open BOX of documents on one shelf.\nOn a small desk is another FOLDER next to some pens.\nThe only exit out of here is to the EAST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check box") == 0 || strcmp(chosen_action, "examine box") == 0 || strcmp(chosen_action, "look at box") == 0 || strcmp(chosen_action, "investigate box") == 0 || strcmp(chosen_action, "view box") == 0) {
		printf("You go through the box of papers, the only thing you find that seems worth noting was something written in black marker over one of the papers.\nIt reads: 'h=t'.\n\n");
	} else if (strcmp(chosen_action, "check folder") == 0 || strcmp(chosen_action, "examine folder") == 0 || strcmp(chosen_action, "look at folder") == 0 || strcmp(chosen_action, "investigate folder") == 0 || strcmp(chosen_action, "view folder") == 0) {
		printf("You find a folder on top of the machines, so you open it.\nAt the top of the document, it reads: 'EPSILON FACILITY REPORT #1'\nYou don't understand most of what you are reading, but this part stands out:\nSubject E, Name: %s\nAfter we have discovered a new wavelength of light not found anywhere on the spectrum, we have dubbed it 'The Else'. Subject E has volunteered by their own free will to experience regular exposure to The Else. After all, they already work for us, so any question of ethics is irrelevant. This report is written right before beginning the exposure, afterwards we will have much data to pour through.\n\n", name);
		if (!actions[GET_KEY_CARD_B]) {
			printf("You found a key card labeled 'B' amongst the documents, so you take it.\nWhile you don't fully remember this place and working here yourself, there are almost fragments of memories from here, for lack of better words. 'Is all of this even real? Am I real?' You wonder to yourself...\n\n");
			actions[GET_KEY_CARD_B] = 1;
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You leave the room through its only exit.\n\n");
		*current_location = FACILITY4;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_FACILITY7(char name[], int *current_location, bool actions[], int *coins) {
	printf("There is only a table with PAPERS spread all over it. The table has some DRAWERS beneath it.\nDoors lie to the EAST and WEST.");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check papers") == 0 || strcmp(chosen_action, "examine papers") == 0 || strcmp(chosen_action, "look at papers") == 0 || strcmp(chosen_action, "investigate papers") == 0 || strcmp(chosen_action, "view papers") == 0) {
		printf("The papers appear to be legal documents involving the funding of this facility.\nThere seems to be a lot of funding from large companies.\n\n");
	} else if (strcmp(chosen_action, "check drawers") == 0 || strcmp(chosen_action, "examine drawers") == 0 || strcmp(chosen_action, "look at drawers") == 0 || strcmp(chosen_action, "investigate drawers") == 0 || strcmp(chosen_action, "view drawers") == 0) {
		printf("There really isn't much to note in these drawers, only a torn piece of paper catches your eye, it says on it: 'a=i'.\n\n");
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		if (actions[GET_KEY_CARD_B]) {
			printf("You use the key card to open the door and go through it.\n\n");
			*current_location = FACILITY8;
		} else {
			printf("The door is locked. Next to the lock there is a device that looks like it can scan something, it has the letter 'B' on it.\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You use the key card to open the door and go through it.\n\n");
		*current_location = FACILITY1;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_FACILITY8(char name[], int *current_location, bool actions[], int *coins) {
	printf("Next to the NORTH door in this room sits a large COMPUTER.\nSitting on top of it is an official-looking FOLDER.\nThe only other door is to the WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check computer") == 0 || strcmp(chosen_action, "examine computer") == 0 || strcmp(chosen_action, "look at computer") == 0 || strcmp(chosen_action, "investigate computer") == 0 || strcmp(chosen_action, "view computer") == 0) {
		if (!actions[PASSWORD_CLEARED]) {
			printf("On the computer's screen it looks like some kind of password prompt.\n\n");
		} else {
			printf("The computer screen says 'ACCESS GRANTED'.\n\n");
		}
	} else if (strcmp(chosen_action, "check folder") == 0 || strcmp(chosen_action, "examine folder") == 0 || strcmp(chosen_action, "look at folder") == 0 || strcmp(chosen_action, "investigate folder") == 0 || strcmp(chosen_action, "view folder") == 0) {
		printf("You take the folder from the top of the computer and read through it.\nAt the top of the document, it is labeled: 'EPSILON FACILITY REPORT #2'\nYou don't really know what all the technical terms in it are about, but you do see one part that makes sense:\nSubject E has begun having episodes of amnesia. They keep forgetting who they are, where they are, and why they are involved in all of this. I really want to pull the plug on this experiment before it gets worse and %s loses their mind entirely. I want to, but the director is urging us to move forward before we end up losing the funding from all of our investors. I am trying to convince myself that all of this is within ethics given Subject E's consensual agreement to all of this, but if they can't even remember who they are, how is that still valid?\nA small piece of paper is also in the folder that reads: 'pass: abcdefghadb'.\n\n", name);
	} else if (strcmp(chosen_action, "use computer") == 0 || strcmp(chosen_action, "utilize computer") == 0 || strcmp(chosen_action, "employ computer") == 0 || strcmp(chosen_action, "wield computer") == 0 || strcmp(chosen_action, "try computer") == 0 || strcmp(chosen_action, "attempt computer") == 0) {
		if (!actions[PASSWORD_CLEARED]) {
			printf("The screen on the computer reads:\nENTER THE PASSWORD TO UNLOCK THE DOOR: ");
			char password[64];
			scanf("%[^\n]%*c", password);
			lowercase(password);
			if (strcmp(password, "information") == 0) {
				printf("ACCESS GRANTED\n\n");
				actions[PASSWORD_CLEARED] = 1;
			} else {
				printf("INVALID PASSWORD.\n\n");
			}
		} else {
			printf("You don't need to use that anymore.\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (actions[PASSWORD_CLEARED]) {
			printf("You open the north door and step through.\n\n");
			*current_location = FACILITY9;
		} else {
			printf("That door is locked!\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You use the key card to open the door and go through it.\n\n");
		*current_location = FACILITY7;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_FACILITY9(char name[], int *current_location, bool actions[], int *coins) {
	printf("You are in a lobby room, with chairs lined up against the walls.\nThere is a counter with a desk and a computer behind it.\nThe door to the EAST seems to lead outside of the facility, while the door to the SOUTH goes back from where you came.\nA computer terminal sits next to the SOUTH door.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You step outside of the facility.\n\n");
		*current_location = CITY1;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go back south through a door..\n\n");
		*current_location = FACILITY8;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_CITY1(char name[], int *current_location, bool actions[], int *coins) {
	printf("You are in a city. Everything looks run down, there are plants growing in places where they normally wouldn't be.\n");
	if (!actions[GET_STONE_PIECE1]) {
		printf("A strange CREATURE resembling a giant squirrel is staring at you, its holding some kind of stone fragment.\nIt looks like it wants something?\n");
	}
	printf("The streets here continue in the NORTH and EAST.\nThere is a strange, out of place looking temple to the SOUTH.\nThe facility is back to the WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "give red mushroom") == 0 || strcmp(chosen_action, "present red mushroom") == 0 || strcmp(chosen_action, "provide red mushroom") == 0) {
		if (actions[GET_RED_MUSHROOM2] && !actions[GET_STONE_PIECE1]) {
			printf("You hand the red mushroom to the creature.\nIt happily eats it, then suddenly disappears in a cloud of darkness!\nIt dropped the stone fragment, so you pick it up.\n\n");
			actions[GET_STONE_PIECE1] = 1;
		} else if (actions[GET_RED_MUSHROOM2] && actions[GET_STONE_PIECE1]) {
			printf("The creature has already disappeared...\n\n");
		} else {
			printf("You don't have that!\n\n");
		}	
	} else if (strcmp(chosen_action, "check creature") == 0 || strcmp(chosen_action, "examine creature") == 0 || strcmp(chosen_action, "look at creature") == 0 || strcmp(chosen_action, "investigate creature") == 0 || strcmp(chosen_action, "view creature") == 0) {
		if (!actions[GET_STONE_PIECE1]) {
			printf("The creature is staring at you like it expects something.\n\n");
		} else {
			printf("The creature is no longer there...\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You travel on the street to the north.\n\n");
		*current_location = CITY6;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You head eastward on the street.\n\n");
		*current_location = CITY3;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go south into the unusual-looking temple.\n\n");
		*current_location = CITY2;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go back into the facility.\n\n");
		*current_location = FACILITY9;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_CITY2(char name[], int *current_location, bool actions[], int *coins) {
	printf("You are in a temple, not sure why its even here.\nThere are mysterious symbols carved into stone all around.\nIt almost appears this whole place was carved out of one massive stone, you see no seams anywhere.\n");
	if (actions[PLACE_STONE_PIECES]) {
		printf("There is a cloud of darkness to the SOUTH.\n");
	} else {
		printf("There is an altar with an empty triangle-shaped indent on top of it.\n");
	}
	printf("The only exit is to the NORTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "place stone piece") == 0 || strcmp(chosen_action, "set stone piece") == 0 || strcmp(chosen_action, "put stone piece") == 0) {
		if (!actions[GET_STONE_PIECE1] && !actions[GET_STONE_PIECE2] && !actions[GET_STONE_PIECE3] && !actions[GET_STONE_PIECE4] && !actions[GET_STONE_PIECE5]) {
			printf("You don't have anything like that...\n\n");
		} else if (actions[GET_STONE_PIECE1] && actions[GET_STONE_PIECE2] && actions[GET_STONE_PIECE3] && actions[GET_STONE_PIECE4] && actions[GET_STONE_PIECE5]) {
			printf("It seems easier to PLACE STONE PIECES all at once...\n\n");
		} else {
			printf("You start to place what you have, but realize you are missing some pieces.\nBetter to wait until you have all of them.\n\n");
		}
	} else if (strcmp(chosen_action, "place stone pieces") == 0 || strcmp(chosen_action, "set stone pieces") == 0 || strcmp(chosen_action, "put stone pieces") == 0) {
		if (!actions[GET_STONE_PIECE1] && !actions[GET_STONE_PIECE2] && !actions[GET_STONE_PIECE3] && !actions[GET_STONE_PIECE4] && !actions[GET_STONE_PIECE5]) {
			printf("You don't have anything like that...\n\n");
		} else if (actions[GET_STONE_PIECE1] && actions[GET_STONE_PIECE2] && actions[GET_STONE_PIECE3] && actions[GET_STONE_PIECE4] && actions[GET_STONE_PIECE5]) {
			printf("You arrange all of the stone pieces in the triangle shape on top of the altar.\nThey start glowing, as they fuse together into one.\nThe altar begins sinking into the ground, as a cloud of darkness erupts from where it sunk into.\n\n");
			actions[PLACE_STONE_PIECES] = 1;
		} else {
			printf("You start to place what you have, but realize you are missing some pieces.\nBetter to wait until you have all of them.\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You leave the temple out the exit.\n\n");
		*current_location = CITY1;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		if (actions[PLACE_STONE_PIECES]) {
			printf("You go into the cloud of darkness.\n\n");
			*current_location = THE_ELSE1;
		} else {
			printf("There is nothing to the south except that altar...\n\n");
		}
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_CITY3(char name[], int *current_location, bool actions[], int *coins) {
	printf("There is a cluster of CARS crashed into each other here.\nYou see some GRAFFITI on the wall of a street corner.\nThe street continues to the NORTH, SOUTH, and WEST.\nThere is an alleyway to the EAST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check cars") == 0 || strcmp(chosen_action, "examine cars") == 0 || strcmp(chosen_action, "look at cars") == 0 || strcmp(chosen_action, "investigate cars") == 0 || strcmp(chosen_action, "view cars") == 0) {
		printf("You search the cars but find nothing of importance.\n\n");
	} else if (strcmp(chosen_action, "check graffiti") == 0 || strcmp(chosen_action, "examine graffiti") == 0 || strcmp(chosen_action, "look at graffiti") == 0 || strcmp(chosen_action, "investigate graffiti") == 0 || strcmp(chosen_action, "view graffiti") == 0) {
		printf("The graffiti is some face that looks like this: \\/(>_<)\\/\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You continue down the street to the north.\n\n");
		*current_location = CITY8;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go into the alleyway to the east.\n\n");
		*current_location = CITY5;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go down the street to the south.\n\n");
		*current_location = CITY4;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head back west.\n\n");
		*current_location = CITY1;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_CITY4(char name[], int *current_location, bool actions[], int *coins) {
	printf("It's a dead end here.\nThere is a pile of TRASH in a corner.\nYou see some GRAFFITI on a wall.\nThe only exit out of here is to the NORTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check trash") == 0 || strcmp(chosen_action, "examine trash") == 0 || strcmp(chosen_action, "look at trash") == 0 || strcmp(chosen_action, "investigate trash") == 0 || strcmp(chosen_action, "view trash") == 0) {
		if (!actions[GET_CROWBAR]) {
			printf("You search through the trash, buried amongst it all is a crowbar.\nDeciding it may be useful, you take it.\n\n");
			actions[GET_CROWBAR] = 1;
		} else {
			printf("You dig through all the trash, but find nothing useful.\n\n");
		}
	} else if (strcmp(chosen_action, "check graffiti") == 0 || strcmp(chosen_action, "examine graffiti") == 0 || strcmp(chosen_action, "look at graffiti") == 0 || strcmp(chosen_action, "investigate graffiti") == 0 || strcmp(chosen_action, "view graffiti") == 0) {
		printf("The graffiti is some kind of face, it appears like this: _/(@_@)\\_\n\n");
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You leave this place by going back north.\n\n");
		*current_location = CITY3;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_CITY5(char name[], int *current_location, bool actions[], int *coins) {
	printf("You are in an alleyway, it's dark around here.\n");
	if (!actions[GET_STONE_PIECE4]) {
		printf("There is the JESTER just standing here?\nHe has a piece of stone in his hand.\n");
	}
	printf("The alleyway appears to exit to the NORTH and WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "talk to jester") == 0 || strcmp(chosen_action, "speak to jester") == 0 || strcmp(chosen_action, "chat with jester") == 0 || strcmp(chosen_action, "talk with jester") == 0 || strcmp(chosen_action, "converse with jester") == 0) {
		if (!actions[GET_STONE_PIECE4]) {
			printf("JESTER: Well, well, it is a bell, can't you tell? Haha...\nThe Jester becomes engulfed in darkness, and him and the darkness just disappears...\nHe left behind the stone fragment, so you pick it up.\n\n");
			actions[GET_STONE_PIECE4] = 1;
		} else {
			printf("The Jester isn't here anymore...\n\n");
		}	
	} else if (strcmp(chosen_action, "check jester") == 0 || strcmp(chosen_action, "examine jester") == 0 || strcmp(chosen_action, "look at jester") == 0 || strcmp(chosen_action, "investigate jester") == 0 || strcmp(chosen_action, "view jester") == 0) {
		if (!actions[GET_STONE_PIECE4]) {
			printf("He looks very out of place here, with his four-pointed hat that only has three bells and his weirdly-colored suit.\n\n");
		} else {
			printf("The Jester isn't here...\n\n");
		}	
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You leave the alleyway to the north.\n\n");
		*current_location = CITY9;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You exit the alleyway in the westward direction.\n\n");
		*current_location = CITY3;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_CITY6(char name[], int *current_location, bool actions[], int *coins) {
	printf("There are plants growing out of cracks in the street.\nSeveral small wild animals are milling about the area.\nThe street continues on the the EAST and SOUTH.\nTo the WEST is an abandoned-looking bar.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "use crowbar") == 0 || strcmp(chosen_action, "utilize crowbar") == 0 || strcmp(chosen_action, "employ crowbar") == 0 || strcmp(chosen_action, "wield crowbar") == 0 || strcmp(chosen_action, "try crowbar") == 0 || strcmp(chosen_action, "attempt crowbar") == 0) {
		if (!actions[GET_CROWBAR]) {
			printf("You don't have that!\n\n");
		} else if (actions[GET_CROWBAR] && !actions[USE_CROWBAR1]) {
			printf("You pry the boards off of the door to the bar.\n\n");
			actions[USE_CROWBAR1] = 1;
		} else if (actions[USE_CROWBAR1]) {
			printf("You already used that here...\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go eastward down the street.\n\n");
		*current_location = CITY8;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You head back to where you started at.\n\n");
		*current_location = CITY1;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		if (actions[USE_CROWBAR1]) {
			printf("You enter the run down bar.\n\n");
			*current_location = CITY7;
		} else {
			printf("You want to go in there, but the door is all boarded up, they won't pry off by hand.\n\n");
		}
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_CITY7(char name[], int *current_location, bool actions[], int *coins) {
	printf("You enter the bar. It's full of cobwebs, must have been abandoned for quite a while.\n");
	if (!actions[GET_STONE_PIECE5]) {
		printf("There is an OLD MAN sitting at one of the tables.\n");
	}
	if (!actions[GET_STICK2]) {
		printf("You see a STICK on the ground.\n");
	}
	printf("The only exit from the bar is to the EAST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check old man") == 0 || strcmp(chosen_action, "examine old man") == 0 || strcmp(chosen_action, "look at old man") == 0 || strcmp(chosen_action, "investigate old man") == 0 || strcmp(chosen_action, "view old man") == 0) {
		if (!actions[GET_STONE_PIECE5]) {
			printf("He looks all alone here. You notice he has a piece of stone in his hand.\n\n");
		} else {
			printf("He isn't there anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "check stick") == 0 || strcmp(chosen_action, "examine stick") == 0 || strcmp(chosen_action, "look at stick") == 0 || strcmp(chosen_action, "investigate stick") == 0 || strcmp(chosen_action, "view stick") == 0) {
		if (!actions[GET_STICK2]) {
			printf("It doesn't look like it really belongs in here...\n\n");
		} else {
			printf("You already got the stick...\n\n");
		}
	} else if (strcmp(chosen_action, "talk to old man") == 0 || strcmp(chosen_action, "speak to old man") == 0 || strcmp(chosen_action, "chat with old man") == 0 || strcmp(chosen_action, "talk with old man") == 0 || strcmp(chosen_action, "converse with old man") == 0) {
		if (!actions[GET_STONE_PIECE5]) {
			printf("OLD MAN: ... Or so, that's how the legend goes...\nHe vanishes in a puffy cloud of darkness, leaving behind only a piece of stone.\nYou take the stone piece.\n\n");
			actions[GET_STONE_PIECE5] = 1;
		} else {
			printf("You wish you could talk to him again, but he is no longer around...\n\n");
		}
	} else if (strcmp(chosen_action, "get stick") == 0 || strcmp(chosen_action, "pick up stick") == 0 || strcmp(chosen_action, "grab stick") == 0 || strcmp(chosen_action, "take stick") == 0 || strcmp(chosen_action, "acquire stick") == 0 || strcmp(chosen_action, "obtain stick") == 0) {
		if (!actions[GET_STICK2]) {
			printf("You pick up the stick.\n\n");
			actions[GET_STICK2] = 1;
		} else {
			printf("You already got the stick!\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You leave the bar out of the door.\n\n");
		*current_location = CITY6;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_CITY8(char name[], int *current_location, bool actions[], int *coins) {
	printf("The streetlights are on here, but keep flickering.\nA group of moths are bouncing around the lights.\nThere is a black cat wandering around, trying to catch the moths when they fly low enough.\n");
	if (!actions[GET_STONE_PIECE2]) {
		printf("The WITCH is here, standing in front of a cauldron?\n");
	}
	printf("The street stretches onward to the EAST, SOUTH, and WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check witch") == 0 || strcmp(chosen_action, "examine witch") == 0 || strcmp(chosen_action, "look at witch") == 0 || strcmp(chosen_action, "investigate witch") == 0 || strcmp(chosen_action, "view witch") == 0) {
		if (!actions[GET_STONE_PIECE2]) {
			printf("She is stirring her cauldron with one hand, while clutching a stone shard in the other hand.\n\n");
		} else {
			printf("The Witch is no longer here...\n\n");
		}
	} else if (strcmp(chosen_action, "talk to witch") == 0 || strcmp(chosen_action, "speak to witch") == 0 || strcmp(chosen_action, "chat with witch") == 0 || strcmp(chosen_action, "talk with witch") == 0 || strcmp(chosen_action, "converse with witch") == 0) {
		if (!actions[GET_STONE_PIECE2]) {
			printf("WITCH: I could use something brown and sticky...\n\n");
		} else {
			printf("The Witch isn't here anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "give stick") == 0 || strcmp(chosen_action, "present stick") == 0 || strcmp(chosen_action, "provide stick") == 0) {
		if (actions[GET_STICK2] && !actions[GET_STONE_PIECE2]) {
			printf("You give the witch the stick, she tosses it in the cauldron.\nWITCH: I brewed up a PURPLE POTION, would you like to drink it? *cackles*\nDarkness erupts from the ground, swallowing her up, then it disappears with her.\nYou pick up the piece of stone that she left behind.\n\n");
			actions[GET_STONE_PIECE2] = 1;
		} else if (actions[GET_STICK2] && actions[GET_STONE_PIECE2]) {
			printf("You don't have that to give, and the Witch isn't here anymore either...\n\n");
		} else if (!actions[GET_STICK2]) {
			printf("You don't have that...\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You travel eastward.\n\n");
		*current_location = CITY9;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You travel through the streets to the south.\n\n");
		*current_location = CITY3;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You head westward.\n\n");
		*current_location = CITY6;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_CITY9(char name[], int *current_location, bool actions[], int *coins) {
	printf("On this corner of the streets are several run down buildings.\nThere are BUSHES growing out of the cracked sidewalks.\n");
	if (!actions[USE_CROWBAR2]) {
		printf("There is a MANHOLE in the middle of the street.\n");
	} else {
		printf("The MANHOLE cover is off to the side, it appears to go DOWN with a ladder.\n");
	}
	printf("The street goes on to the WEST, SOUTH leads into an alleyway.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check bushes") == 0 || strcmp(chosen_action, "examine bushes") == 0 || strcmp(chosen_action, "look at bushes") == 0 || strcmp(chosen_action, "investigate bushes") == 0 || strcmp(chosen_action, "view bushes") == 0) {
		if (!actions[GET_RED_MUSHROOM2]) {
			printf("You search through the bushes and find nothing...\nWait, there's a red mushroom here? You decide to take it.\n\n");
			actions[GET_RED_MUSHROOM2] = 1;
		} else {
			printf("You search through the bushes around here and find nothing but some bugs crawling about.\n\n");
		}
	} else if (strcmp(chosen_action, "open manhole") == 0) {
		if (!actions[GET_CROWBAR]) {
			printf("You try to pry the top off, but you can't get a grip with your bare hands.\n\n");
		} else if (actions[GET_CROWBAR] && !actions[USE_CROWBAR2]) {
			printf("You wedge the crowbar into part of the manhole cover, and pry it open.\n\n");
			actions[USE_CROWBAR2] = 1;
		} else if (actions[USE_CROWBAR2]) {
			printf("You already opened it...\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You leave the area to the south.\n\n");
		*current_location = CITY5;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go westward across the streets.\n\n");
		*current_location = CITY8;
	} else if (strcmp(chosen_action, "go down") == 0 || strcmp(chosen_action, "head down") == 0 || strcmp(chosen_action, "walk down") == 0 || strcmp(chosen_action, "travel down") == 0 || strcmp(chosen_action, "move down") == 0 || strcmp(chosen_action, "proceed down") == 0 || strcmp(chosen_action, "advance down") == 0 || strcmp(chosen_action, "leave down") == 0) {
		if (actions[USE_CROWBAR2]) {
			printf("You climb through the manhole down the ladder.\n\n");
			*current_location = CITY10;
		} else {
			printf("There is nowhere to go down here...\n\n");
		}
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_CITY10(char name[], int *current_location, bool actions[], int *coins) {
	printf("It is very dark in here. It looks like there are some tunnels going in different directions, but they appear too small for you to even fit into.\nThere is some GRAFFITI you can faintly see on one of the walls.\n");
	if (!actions[GET_STONE_PIECE3]) {
		printf("There is a mushroom CREATURE down here drawing something on the ground, looking kind of bored.\n");
	}
	printf("The only way out of here is back UP the ladder.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check graffiti") == 0 || strcmp(chosen_action, "examine graffiti") == 0 || strcmp(chosen_action, "look at graffiti") == 0 || strcmp(chosen_action, "investigate graffiti") == 0 || strcmp(chosen_action, "view graffiti") == 0) { 
		printf("It's hard to see in this dim of light, but it looks like the graffiti on the wall says: 'We're all mad here!'\n\n");
	} else if (strcmp(chosen_action, "check creature") == 0 || strcmp(chosen_action, "examine creature") == 0 || strcmp(chosen_action, "look at creature") == 0 || strcmp(chosen_action, "investigate creature") == 0 || strcmp(chosen_action, "view creature") == 0) { 
		if (!actions[GET_STONE_PIECE3]) {
			printf("The creature looks pretty bored.\n\n");
		} else {
			printf("The mushroom creature is no longer here...\n\n");
		}
	} else if (strcmp(chosen_action, "talk to creature") == 0 || strcmp(chosen_action, "speak to creature") == 0 || strcmp(chosen_action, "chat with creature") == 0 || strcmp(chosen_action, "talk with creature") == 0 || strcmp(chosen_action, "converse with creature") == 0) { 
		if (!actions[GET_STONE_PIECE3]) {
			printf("CREATURE: Do you want to play a fun game with me? I'll give you this piece of stone if you can win!\n\n");
			printf("Play a game with the creature? (y/n): ");
			char yn[4];
			scanf("%[^\n]%*c", yn);
			if (strcmp(yn, "y") == 0) {
				bool result = hangman();
				if (result) {
					printf("CREATURE: Oh wow, you won! This is your prize!\nThe creature hands you a peice of stone, then disappears in a plume of darkness...\n\n");
					actions[GET_STONE_PIECE3] = 1;
				} else {
					printf("CREATURE: Haha, it's okay, you can try again any time!\n");
				}	
			}
		} else {
			printf("The mushroom creature is no longer here...\n\n");
		}
	} else if (strcmp(chosen_action, "go up") == 0 || strcmp(chosen_action, "head up") == 0 || strcmp(chosen_action, "walk up") == 0 || strcmp(chosen_action, "travel up") == 0 || strcmp(chosen_action, "move up") == 0 || strcmp(chosen_action, "proceed up") == 0 || strcmp(chosen_action, "advance up") == 0 || strcmp(chosen_action, "leave up") == 0) {
		printf("You climb back up the ladder.\n\n");
		*current_location = CITY9;
	} else {
		printInvalid();
	}
	
	return 1;
}

void printReverseInvalid() {
	char invalid_messages[10][128] = {
		"!ereh taht od tonnac uoY",
		"...ereh gnineppah toN",
		".ereh elbissop ton si sihT",
		"!ereh enod eb tonnac noitca tahT",
		".ereh krow t'now ,yrroS",
		".ereh ton tsael ta ,krow t'nseoD",
		".krow t'now tahT",
		".ereh gnihtyna od t'nseod ti tub ,yrt uoY",
		".ereh elbissop toN",
		".ereh thgir ton tub ,krow thgim tI"
	};
	printf("%s\n\n", invalid_messages[rand() % 10]);
}

bool room_THE_ELSE1(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[THE_ELSE_INTRO]) {
		printf("As the darkness fades away, you have no clue where you are.\n");
		actions[THE_ELSE_INTRO] = 1;
	}
	if (!actions[FLIPPED]) {
		printf("The room is blindingly white. There is a strange, puffy looking CREATURE standing in the corner.\nThere are STAIRS that seem to lead into the ceiling?\nThe only exit is EAST.\n\n");
	} else if (actions[FLIPPED]) {
		printf(".TSAE si tixe ylno ehT\n?gniliec eht otni dael ot mees taht SRIATS era erehT\n.gniliec eht fo renroc eht ni nwod edispu gnidnats ERUTAERC gnikool yffup ,egnarts a si erehT .etihw ylgnidnilb si moor ehT\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (!actions[FLIPPED]) {
		if (strcmp(chosen_action, "check creature") == 0 || strcmp(chosen_action, "examine creature") == 0 || strcmp(chosen_action, "look at creature") == 0 || strcmp(chosen_action, "investigate creature") == 0 || strcmp(chosen_action, "view creature") == 0) {
			printf("The creature kind of reminds you of a marshmallow.\nIt has vertical black and white stripes all over its body.\n\n");
		} else if (strcmp(chosen_action, "talk to creature") == 0 || strcmp(chosen_action, "speak to creature") == 0 || strcmp(chosen_action, "chat with creature") == 0 || strcmp(chosen_action, "talk with creature") == 0 || strcmp(chosen_action, "converse with creature") == 0) {
			printf("Gnynwoygetugotoeb\nrgotouth,crinhu o\nesu rrh sh n ittx\ne! tk rht iaansh!\ntIwo woerymtnkie \nifa yaureoaid d  \n\n");
		} else if (strcmp(chosen_action, "go up stairs") == 0 || strcmp(chosen_action, "head up stairs") == 0 || strcmp(chosen_action, "walk up stairs") == 0 || strcmp(chosen_action, "travel up stairs") == 0 || strcmp(chosen_action, "move up stairs") == 0 || strcmp(chosen_action, "proceed up stairs") == 0 || strcmp(chosen_action, "advance up stairs") == 0 || strcmp(chosen_action, "leave up stairs") == 0) {
			printf("You climb up the stairs, but it only leads into a dead end at the ceiling.\nWhat is the point of these stairs?\n\n");
		} else if (strcmp(chosen_action, "go down stairs") == 0 || strcmp(chosen_action, "head down stairs") == 0 || strcmp(chosen_action, "walk down stairs") == 0 || strcmp(chosen_action, "travel down stairs") == 0 || strcmp(chosen_action, "move down stairs") == 0 || strcmp(chosen_action, "proceed down stairs") == 0 || strcmp(chosen_action, "advance down stairs") == 0 || strcmp(chosen_action, "leave down stairs") == 0) {
			printf("Strangely enough, you walk down the stairs. You end up on the ceiling?\nNo, you are on the floor, but everything looks flipped?\n\n");
			actions[FLIPPED] = 1;
		} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
			printf("You travel east through the doorway.\n\n");
			*current_location = THE_ELSE2;
		} else {
			printInvalid();
		}
	} else if (actions[FLIPPED]) {
		if (strcmp(chosen_action, "sriats pu og") == 0 || strcmp(chosen_action, "sriats pu daeh") == 0 || strcmp(chosen_action, "sriats pu levart") == 0 || strcmp(chosen_action, "sriats pu klaw") == 0) {
			printf("?sriats eseht fo tniop eht si tahW\n.gniliec eht ta dne daed a otni sdael ylno ti tub ,sriats eht pu bmilc uoY\n\n");
		} else if (strcmp(chosen_action, "sriats nwod og") == 0 || strcmp(chosen_action, "sriats nwod daeh") == 0 || strcmp(chosen_action, "sriats nwod levart") == 0 || strcmp(chosen_action, "sriats nwod klaw") == 0) {
			printf("?deppilf skool gnihtyreve tub ,roolf eht no era uoy ,oN\n?gniliec eht no pu dne uoY .sriats eht nwod klaw uoy ,hguone ylegnartS\n\n");
			actions[FLIPPED] = 0;
		} else if (strcmp(chosen_action, "tsae og") == 0 || strcmp(chosen_action, "tsae daeh") == 0 || strcmp(chosen_action, "tsae levart") == 0 || strcmp(chosen_action, "tsae klaw") == 0) {
			printf(".yawrood eht hguorht tsae levart uoY\n\n");
			*current_location = THE_ELSE2;
		} else {
			printReverseInvalid();
		}
	}
	
	return 1;
}

bool room_THE_ELSE2(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[FLIPPED]) {
		printf("You enter another white room.\nYou notice a shadowy figure standing on the ceiling that looks just like you.\nThere is a stone BLOCK on both the floor and the ceiling.\nThe one on the floor is black, the other is white.\n");
		if (!actions[BLOCK_MOVED]) {
			printf("The BLOCK is in the center of the room, the only exit out of here is to the WEST.\n\n");
		} else {
			printf("The BLOCK has been moved out of the way, there are stairs leading DOWN from where the BLOCK was.\nThe only other exit is WEST.\n\n");
		}
	} else if (actions[FLIPPED]) {
		printf(".kcalb si rehto eht ,etihw si roolf eht no eno ehT\n.gniliec eht dna roolf eht htob no KCOLB enots a si erehT\n.uoy ekil tsuj skool taht gniliec eht no gnidnats erugif ywodahs a eciton uoY\n.moor etihw rehtona retne uoY\n\n");
		if (!actions[BLOCK_MOVED]) {
			printf(".TSEW eht ot si ereh fo tuo tixe ylno eht ,moor eht fo retnec eht ni si KCOLB ehT\n\n");
		} else {
			printf(".TSEW si ereh morf tixe ylno ehT\n.saw KCOLB eht erehw htaenrednu gniliec eht no sriats era ereht ,yaw eht fo tuo devom neeb sah KCOLB ehT\n\n");
		}
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (!actions[FLIPPED]) {
		if (strcmp(chosen_action, "move block") == 0 || strcmp(chosen_action, "push block") == 0 || strcmp(chosen_action, "shove block") == 0) {
			printf("You push on the block, but it doesn't move at all.\nYou noticed that the shadowy figure pushed on the block on the ceiling, but it too didn't move.\n\n");
		} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
			printf("You head back to the first room.\n\n");
			*current_location = THE_ELSE1;
		} else if (strcmp(chosen_action, "go down") == 0 || strcmp(chosen_action, "head down") == 0 || strcmp(chosen_action, "walk down") == 0 || strcmp(chosen_action, "travel down") == 0 || strcmp(chosen_action, "move down") == 0 || strcmp(chosen_action, "proceed down") == 0 || strcmp(chosen_action, "advance down") == 0 || strcmp(chosen_action, "leave down") == 0) {
			if (actions[BLOCK_MOVED]) {
				printf("You head down the spiral staircase. it goes win\n                                               d\n                     i n g  i n t o  t h e      i\n                    l a  . . . m o o r t   n     n\n                       r i              x e    g\n                          p s , d n            \n                                   u  o  r  a\n\n");
				*current_location = THE_ELSE3;
			} else {
				printf("There is nowhere to go down here...\n\n");
			}
		} else {
			printInvalid();
		}
	} else if (actions[FLIPPED]) {
		if (strcmp(chosen_action, "kcolb evom") == 0 || strcmp(chosen_action, "kcolb hsup") == 0 || strcmp(chosen_action, "kcolb evohs") == 0) {
			if (!actions[BLOCK_MOVED]) {
				printf(".PU gnidael sriats gnilaever ,devom osla ti ,gniliec eht no kcolb eht no dehsup erugif ywodahs eht taht deciton uoY\n.esae htiw yaw eht fo tuo sevom ti ,kcolb eht no hsup uoY\n\n");
				actions[BLOCK_MOVED] = 1;
			} else {
				printf(".kcolb eht devom ydaerla uoY\n\n");
			}
		} else if (strcmp(chosen_action, "tsew og") == 0 || strcmp(chosen_action, "tsew daeh") == 0 || strcmp(chosen_action, "tsew levart") == 0 || strcmp(chosen_action, "tsew klaw") == 0) {
			printf(".moor tsrif eht ot kcab daeh uoY\n\n");
			*current_location = THE_ELSE1;
		} else {
			printReverseInvalid();
		}
	}
	
	return 1;
}

bool room_THE_ELSE3(char name[], int *current_location, bool actions[], int *coins) {
	printf("The only thing to note in this room is that same puffy CREATURE from before.\nThere are stairs to the EAST, the exit is back UP the spiral staircase.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check creature") == 0 || strcmp(chosen_action, "examine creature") == 0 || strcmp(chosen_action, "look at creature") == 0 || strcmp(chosen_action, "investigate creature") == 0 || strcmp(chosen_action, "view creature") == 0) {
			printf("The creature kind of reminds you of a marshmallow.\nIt has vertical black and white stripes all over its body.\n\n");
	} else if (strcmp(chosen_action, "talk to creature") == 0 || strcmp(chosen_action, "speak to creature") == 0 || strcmp(chosen_action, "chat with creature") == 0 || strcmp(chosen_action, "talk with creature") == 0 || strcmp(chosen_action, "converse with creature") == 0) {
			printf("CREATURE: Sometimes you need a different approach to things...\n\n");
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You start climbing up the stairs.\n\n");
		*current_location = THE_ELSE4;
	} else if (strcmp(chosen_action, "go up") == 0 || strcmp(chosen_action, "head up") == 0 || strcmp(chosen_action, "walk up") == 0 || strcmp(chosen_action, "travel up") == 0 || strcmp(chosen_action, "move up") == 0 || strcmp(chosen_action, "proceed up") == 0 || strcmp(chosen_action, "advance up") == 0 || strcmp(chosen_action, "leave up") == 0) {
		printf("You climb back up the spiral staircase.\n\n");
		*current_location = THE_ELSE2;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_THE_ELSE4(char name[], int *current_location, bool actions[], int *coins) {
	printf("You are in the middle of a staircase.\nThe STAIRS go UP into another room, and DOWN back where you came.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go up stairs") == 0 || strcmp(chosen_action, "head up stairs") == 0 || strcmp(chosen_action, "walk up stairs") == 0 || strcmp(chosen_action, "travel up stairs") == 0 || strcmp(chosen_action, "move up stairs") == 0 || strcmp(chosen_action, "proceed up stairs") == 0 || strcmp(chosen_action, "advance up stairs") == 0 || strcmp(chosen_action, "leave up stairs") == 0) {
		printf("You climb up the stairs, only to find yourself seemingly where you started?\n\n");
	} else if (strcmp(chosen_action, "go down stairs") == 0 || strcmp(chosen_action, "head down stairs") == 0 || strcmp(chosen_action, "walk down stairs") == 0 || strcmp(chosen_action, "travel down stairs") == 0 || strcmp(chosen_action, "move down stairs") == 0 || strcmp(chosen_action, "proceed down stairs") == 0 || strcmp(chosen_action, "advance down stairs") == 0 || strcmp(chosen_action, "leave down stairs") == 0) {
		printf("You climb down the stairs, back into the previous room.\n\n");
		*current_location = THE_ELSE3;
	} else if (strcmp(chosen_action, "go up stairs backwards") == 0 || strcmp(chosen_action, "head up stairs backwards") == 0 || strcmp(chosen_action, "walk up stairs backwards") == 0 || strcmp(chosen_action, "travel up stairs backwards") == 0 || strcmp(chosen_action, "move up stairs backwards") == 0 || strcmp(chosen_action, "proceed up stairs backwards") == 0 || strcmp(chosen_action, "advance up stairs backwards") == 0 || strcmp(chosen_action, "leave up stairs backwards") == 0) {
		printf("It seems silly, but you walk up the stairs backwards.\nSomehow you actually end up in the next room!\n\n");
		*current_location = THE_ELSE5;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_THE_ELSE5(char name[], int *current_location, bool actions[], int *coins) {
	printf("In this room, you feel strangely... Papery?\nYou look down and realize your body is as flat as a piece of paper!\nThe exits are to the EAST and WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "turn sideways") == 0) {
		printf("You rotate your body 45 degrees.\n\n");
		actions[SIDEWAYS] = 1;
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		if (actions[SIDEWAYS]) {
			printf("A gust of wind blows towards you, but you manage to get by it and enter the next room.\nYour body turns back to normal, and the door behind you slams shut.\n\n");
			*current_location = THE_ELSE6;
		} else {
			printf("A gust of wind blows towards you, it catches you and you fly back to the other end of the room.\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go back down the stairs, your body turns back to normal when you do.\n\n");
		*current_location = THE_ELSE4;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_THE_ELSE6(char name[], int *current_location, bool actions[], int *coins) {
	printf("With the door behind you shut, the only exit from here is to the NORTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		int death = rand() % 3;
		if (death == 0) {
			printf("You head NORTH.\nThe last thing you see is the doorway to the NORTH, as the ground collapses!\nYou fall into what seems to be a giant blender, as your body is shredded to bits.\nGAME OVER\n");
		} else if (death == 1) {
			printf("You head NORTH.\nSuddenly the ceiling meets the floor as they slam together, crushing you!\nThe last thing you saw was the doorway to the NORTH.\nGAME OVER\n");		
		} else if (death == 2) {
			printf("You head NORTH.\nYou step into a puddle...\nYour leg begins melting into the puddle, as your whole body gets pulled in, dissolving you!\nThe last thing you see is the doorway to the NORTH.\nGAME OVER\n");		
		}
		while(1) {
			char next[32];
			scanf("%[^\n]%*c", next);
			if (strcmp(next, "go north") == 0) {
				break;
			}
		}
		printf("You don't know how, but you drift towards the doorway to the north.\nYou head into the next room, seemingly unscathed.\nWas it all in your head?\n\n");
		*current_location = THE_ELSE7;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_THE_ELSE7(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[DOOR_SHUT1]) {
		printf("The door slams shut behind you.\n");
		actions[DOOR_SHUT1] = 1;
	}
	if (!actions[EYES_CLOSED]) {
		printf("You can't see anything in this room, it's as if your eyes are closed, but you know they aren't?\n\n");
	} else {
		printf("You see a SYMBOL raised out from the wall like a button that looks like this '<o>'.\n");
		if (!actions[SYMBOL_PUSHED]) {
			printf("There is a door to the NORTH, but it is shut tight.\n\n");
		} else {
			printf("There is an open door to the NORTH.\n\n");
		}
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "open eyes") == 0) {
		if (!actions[EYES_CLOSED]) {
			printf("Your eyes are already open!\n\n");
		} else {
			printf("You open your eyes.\n\n");
			actions[EYES_CLOSED] = 0;
		}
	} else if (strcmp(chosen_action, "close eyes") == 0) {
		if (actions[EYES_CLOSED]) {
			printf("Your eyes are already closed!\n\n");
		} else {
			printf("You close your eyes.\n\n");
			actions[EYES_CLOSED] = 1;
		}
	} else if (strcmp(chosen_action, "push symbol") == 0 || strcmp(chosen_action, "press symbol") == 0 || strcmp(chosen_action, "depress symbol") == 0) {
		if (actions[EYES_CLOSED]) {
			if (!actions[SYMBOL_PUSHED]) {
				printf("You push the symbol on the wall, and the door to the NORTH opens.\n\n");
				actions[SYMBOL_PUSHED] = 1;
			} else {
				printf("You already pushed the symbol!\n\n");
			}
		} else {
			printf("You can't see anything like that!\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (actions[EYES_CLOSED]) {
			if (!actions[SYMBOL_PUSHED]) {
				printf("The door to the NORTH is shut tight.\n\n");
			} else {
				printf("You go through the door, as you open your eyes.\n\n");
				*current_location = THE_ELSE8;
			}
		} else {
			printf("You can't see anything!\n\n");
		}
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_THE_ELSE8(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[QUESTION_ANSWERED]) {
		printf("VOICE: ANSWER MY QUESTION!\n\n");
	} else {
		printf("There are doorways to the NORTH and SOUTH.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "talk to voice") == 0 || strcmp(chosen_action, "speak to voice") == 0 || strcmp(chosen_action, "chat with voice") == 0 || strcmp(chosen_action, "talk with voice") == 0 || strcmp(chosen_action, "converse with voice") == 0) {
		if (!actions[QUESTION_ANSWERED]) {
			printf("VOICE: WHAT COMES RIGHT BEFORE THIS SEQUENCE?! 809 811 821 823?? ");
			int answer = 0;
			scanf("%d", &answer);
			if (answer == 797) {
				printf("VOICE: THAT IS CORRECT, CORRECT CORRECT!!!\n\n");
				actions[QUESTION_ANSWERED] = 1;
			} else {
				printf("VOICE: THAT IS WRONG, WRONG WRONG WRONG!!!!\n\n");
			}
		} else {
			printf("VOICE: YOU MAY GO NOW!!!\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		if (!actions[QUESTION_ANSWERED]) {
			printf("The door is shut...\n\n");
		} else {
			printf("You leave the room through the doorway.\n\n");
			*current_location = THE_ELSE9;
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) { 
		printf("You head back south.\n\n");
		*current_location = THE_ELSE7;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_THE_ELSE9(char name[], int *current_location, bool actions[], int *coins) {
	printf("There is WRITING on the wall in this room.\nOddly enough, there is also a COMPUTER terminal next to a door.\n");
	if (!actions[PASSWORD_CLEARED2]) {
		printf("The only exit is to the SOUTH, the door to the WEST is shut.\n\n");
	} else {
		printf("There are open doors to the SOUTH and WEST.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check writing") == 0 || strcmp(chosen_action, "examine writing") == 0 || strcmp(chosen_action, "look at writing") == 0 || strcmp(chosen_action, "investigate writing") == 0 || strcmp(chosen_action, "view writing") == 0) {
		printf("The writing on the wall says: caef fdgh fghhie ah egab caei\n\n");
	} else if (strcmp(chosen_action, "use computer") == 0 || strcmp(chosen_action, "utilize computer") == 0 || strcmp(chosen_action, "employ computer") == 0 || strcmp(chosen_action, "wield computer") == 0 || strcmp(chosen_action, "try computer") == 0 || strcmp(chosen_action, "attempt computer") == 0) {
		if (!actions[PASSWORD_CLEARED2]) {
			printf("The screen on the computer reads:\nENTER THE PASSWORD TO UNLOCK THE DOOR: ");
			char password[80];
			scanf("%[^\n]%*c", password);
			lowercase(password);
			if (strcmp(password, "firm moat matter it rain fire") == 0) {
				printf("ACCESS GRANTED\n\n");
				actions[PASSWORD_CLEARED2] = 1;
			} else {
				printf("INVALID PASSWORD.\n\n");
			}
		} else {
			printf("You don't need to use that anymore.\n\n");
		}
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		if (actions[PASSWORD_CLEARED2]) {
			printf("You go through the door to the west, and it closes behind you.\n\n");
			*current_location = THE_ELSE10;
		} else {
			printf("The door to the west is shut...\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go back south.\n\n");
		*current_location = THE_ELSE8;
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_THE_ELSE10(char name[], int *current_location, bool actions[], int *coins) {
	printf("There are four BUTTONs here, labeled A, B, C, and RESET.\n");
	if (actions[BUTTON_A_LIT]) {
		printf("The A BUTTON is lit up.\n");
	} else {
		printf("The A BUTTON is unlit.\n");
	}
	if (actions[BUTTON_B_LIT]) {
		printf("The B BUTTON is lit up.\n");
	} else {
		printf("The B BUTTON is unlit.\n");
	}
	if (actions[BUTTON_C_LIT]) {
		printf("The C BUTTON is lit up.\n");
	} else {
		printf("The C BUTTON is unlit.\n");
	}
	printf("There are doorways SOUTH and WEST.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "press reset button") == 0) {
		if (!actions[BUTTON_PUZZLE1_SOLVED]) {
			printf("You press the RESET BUTTON.\n\n");
			actions[BUTTON_A_LIT] = 0;
			actions[BUTTON_B_LIT] = 0;
			actions[BUTTON_C_LIT] = 0;
			actions[BUTTON_D_LIT] = 0;
			actions[BUTTON_E_LIT] = 0;
			actions[BUTTON_F_LIT] = 0;
			actions[BUTTON_G_LIT] = 0;
			actions[BUTTON_H_LIT] = 0;
			actions[BUTTON_I_LIT] = 0;
		} else {
			printf("You don't need to do that anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "press a button") == 0) {
		if (!actions[BUTTON_PUZZLE1_SOLVED]) {
			printf("You press the A BUTTON.\n\n");
			if (!actions[BUTTON_A_LIT]) {
				actions[BUTTON_D_LIT] ^= 1;
				actions[BUTTON_F_LIT] ^= 1;
			} else if (actions[BUTTON_A_LIT]) {
				actions[BUTTON_B_LIT] ^= 1;
				actions[BUTTON_A_LIT] ^= 1;
			}
		} else {
			printf("You don't need to do that anymore...\n\n");
		}	
	} else if (strcmp(chosen_action, "press b button") == 0) {
		if (!actions[BUTTON_PUZZLE1_SOLVED]) {
			printf("You press the B BUTTON.\n\n");
			if (!actions[BUTTON_B_LIT]) {
				actions[BUTTON_E_LIT] ^= 1;
				actions[BUTTON_F_LIT] ^= 1;
			} else if (actions[BUTTON_B_LIT]) {
				actions[BUTTON_B_LIT] ^= 1;
				actions[BUTTON_A_LIT] ^= 1;
			}
		} else {
			printf("You don't need to do that anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "press c button") == 0) {
		if (!actions[BUTTON_PUZZLE1_SOLVED]) {
			printf("You press the C BUTTON.\n\n");
			if (!actions[BUTTON_C_LIT]) {
				actions[BUTTON_C_LIT] ^= 1;
				actions[BUTTON_H_LIT] ^= 1;
			} else if (actions[BUTTON_C_LIT]) {
				actions[BUTTON_E_LIT] ^= 1;
			}
		} else {
			printf("You don't need to do that anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		printf("You go into another room to the south.\n\n");
		*current_location = THE_ELSE11;
	} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
		printf("You go westward into another room.\n\n");
		*current_location = THE_ELSE12;
	} else {
		printInvalid();
	}
	
	if (!actions[BUTTON_PUZZLE1_SOLVED] && actions[BUTTON_A_LIT] && actions[BUTTON_B_LIT] && actions[BUTTON_C_LIT] && actions[BUTTON_D_LIT] && actions[BUTTON_E_LIT] && actions[BUTTON_F_LIT] && actions[BUTTON_G_LIT] && actions[BUTTON_H_LIT] && actions[BUTTON_I_LIT]) {
		printf("You hear the sound of a door opening up in another room near here.\n\n");
		actions[BUTTON_PUZZLE1_SOLVED] = 1;
	}
	
	return 1;
}

bool room_THE_ELSE11(char name[], int *current_location, bool actions[], int *coins) {
	printf("There are three BUTTONs here, labeled D, E, and F.\n");
	if (actions[BUTTON_D_LIT]) {
		printf("The D BUTTON is lit up.\n");
	} else {
		printf("The D BUTTON is unlit.\n");
	}
	if (actions[BUTTON_E_LIT]) {
		printf("The E BUTTON is lit up.\n");
	} else {
		printf("The E BUTTON is unlit.\n");
	}
	if (actions[BUTTON_F_LIT]) {
		printf("The F BUTTON is lit up.\n");
	} else {
		printf("The F BUTTON is unlit.\n");
	}
	printf("The only door here is to the NORTH.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "press d button") == 0) {
		if (!actions[BUTTON_PUZZLE1_SOLVED]) {
			printf("You press the D BUTTON.\n\n");
			if (!actions[BUTTON_D_LIT]) {
				actions[BUTTON_D_LIT] ^= 1;
				actions[BUTTON_F_LIT] ^= 1;
			} else if (actions[BUTTON_D_LIT]) {
				actions[BUTTON_A_LIT] ^= 1;
				actions[BUTTON_C_LIT] ^= 1;
			}
		} else {
			printf("You don't need to do that anymore...\n\n");
		}	
	} else if (strcmp(chosen_action, "press e button") == 0) {
		if (!actions[BUTTON_PUZZLE1_SOLVED]) {
			printf("You press the E BUTTON.\n\n");
			if (!actions[BUTTON_E_LIT]) {
				actions[BUTTON_C_LIT] ^= 1;
				actions[BUTTON_F_LIT] ^= 1;
			} else if (actions[BUTTON_E_LIT]) {
				actions[BUTTON_E_LIT] ^= 1;
				actions[BUTTON_H_LIT] ^= 1;
			}
		} else {
			printf("You don't need to do that anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "press f button") == 0) {
		if (!actions[BUTTON_PUZZLE1_SOLVED]) {
			printf("You press the F BUTTON.\n\n");
			if (!actions[BUTTON_F_LIT]) {
				actions[BUTTON_G_LIT] ^= 1;
				actions[BUTTON_C_LIT] ^= 1;
			} else if (actions[BUTTON_F_LIT]) {
				actions[BUTTON_F_LIT] ^= 1;
			}
		} else {
			printf("You don't need to do that anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "go north") == 0 || strcmp(chosen_action, "head north") == 0 || strcmp(chosen_action, "walk north") == 0 || strcmp(chosen_action, "travel north") == 0 || strcmp(chosen_action, "move north") == 0 || strcmp(chosen_action, "proceed north") == 0 || strcmp(chosen_action, "advance north") == 0 || strcmp(chosen_action, "leave north") == 0) {
		printf("You go back north.\n\n");
		*current_location = THE_ELSE10;
	} else {
		printInvalid();
	}
	
	if (!actions[BUTTON_PUZZLE1_SOLVED] && actions[BUTTON_A_LIT] && actions[BUTTON_B_LIT] && actions[BUTTON_C_LIT] && actions[BUTTON_D_LIT] && actions[BUTTON_E_LIT] && actions[BUTTON_F_LIT] && actions[BUTTON_G_LIT] && actions[BUTTON_H_LIT] && actions[BUTTON_I_LIT]) {
		printf("You hear the sound of a door opening up in another room near here.\n\n");
		actions[BUTTON_PUZZLE1_SOLVED] = 1;
	}
	
	return 1;
}

bool room_THE_ELSE12(char name[], int *current_location, bool actions[], int *coins) {
	printf("There are three BUTTONs here, labeled G, H, and I.\n");
	if (actions[BUTTON_G_LIT]) {
		printf("The G BUTTON is lit up.\n");
	} else {
		printf("The G BUTTON is unlit.\n");
	}
	if (actions[BUTTON_H_LIT]) {
		printf("The H BUTTON is lit up.\n");
	} else {
		printf("The H BUTTON is unlit.\n");
	}
	if (actions[BUTTON_I_LIT]) {
		printf("The I BUTTON is lit up.\n");
	} else {
		printf("The I BUTTON is unlit.\n");
	}
	printf("There is a door to the EAST.\n");
	if (!actions[BUTTON_PUZZLE1_SOLVED]) {
		printf("SOUTH is another door, but it is completely shut.\n\n");
	} else {
		printf("SOUTH is another open door.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "press g button") == 0) {
		if (!actions[BUTTON_PUZZLE1_SOLVED]) {
			printf("You press the G BUTTON.\n\n");
			if (!actions[BUTTON_G_LIT]) {
				actions[BUTTON_E_LIT] ^= 1;
				actions[BUTTON_G_LIT] ^= 1;
			} else if (actions[BUTTON_G_LIT]) {
				actions[BUTTON_A_LIT] ^= 1;
			}
		} else {
			printf("You don't need to do that anymore...\n\n");
		}	
	} else if (strcmp(chosen_action, "press h button") == 0) {
		if (!actions[BUTTON_PUZZLE1_SOLVED]) {
			printf("You press the H BUTTON.\n\n");
			if (!actions[BUTTON_H_LIT]) {
				actions[BUTTON_A_LIT] ^= 1;
				actions[BUTTON_B_LIT] ^= 1;
			} else if (actions[BUTTON_H_LIT]) {
				actions[BUTTON_A_LIT] ^= 1;
				actions[BUTTON_B_LIT] ^= 1;
			}
		} else {
			printf("You don't need to do that anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "press i button") == 0) {
		if (!actions[BUTTON_PUZZLE1_SOLVED]) {
			printf("You press the I BUTTON.\n\n");
			if (!actions[BUTTON_I_LIT]) {
				actions[BUTTON_I_LIT] ^= 1;
			} else if (actions[BUTTON_I_LIT]) {
				actions[BUTTON_I_LIT] ^= 1;
				actions[BUTTON_G_LIT] ^= 1;
				actions[BUTTON_H_LIT] ^= 1;
			}
		} else {
			printf("You don't need to do that anymore...\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		printf("You go back east.\n\n");
		*current_location = THE_ELSE10;
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		if (actions[BUTTON_PUZZLE1_SOLVED]) {
			printf("You go back east.\n\n");
			*current_location = THE_ELSE13;
		} else {
			printf("You try to get the door open, but nothing will get it to move.\n\n");
		}
	} else {
		printInvalid();
	}
	
	if (!actions[BUTTON_PUZZLE1_SOLVED] && actions[BUTTON_A_LIT] && actions[BUTTON_B_LIT] && actions[BUTTON_C_LIT] && actions[BUTTON_D_LIT] && actions[BUTTON_E_LIT] && actions[BUTTON_F_LIT] && actions[BUTTON_G_LIT] && actions[BUTTON_H_LIT] && actions[BUTTON_I_LIT]) {
		printf("You hear the sound of the SOUTH door opening up in here.\n\n");
		actions[BUTTON_PUZZLE1_SOLVED] = 1;
	}
	
	return 1;
}

bool room_THE_ELSE13(char name[], int *current_location, bool actions[], int *coins) {
	if (!actions[FLIPPED]) {
		printf("This room has five BUTTONs. There is a LEFT and RIGHT BUTTON on both the floor and the ceiling.\nIn a corner on the floor is a BUTTON labeled 'RESET'.\nThere are STAIRS that seem much like the ones from the first room of this place.\n");
		if (actions[BUTTON_CEIL_LEFT_LIT]) {
			printf("The left button on the ceiling is lit.\n");
		} else {
			printf("The left button on the ceiling is unlit.\n");
		}
		if (actions[BUTTON_CEIL_RIGHT_LIT]) {
			printf("The right button on the ceiling is lit.\n");
		} else {
			printf("The right button on the ceiling is unlit.\n");
		}
		if (actions[BUTTON_FLOOR_LEFT_LIT]) {
			printf("The left button on the floor is lit.\n");
		} else {
			printf("The left button on the floor is unlit.\n");
		}
		if (actions[BUTTON_FLOOR_RIGHT_LIT]) {
			printf("The right button on the floor is lit.\n");
		} else {
			printf("The right button on the floor is unlit.\n");
		}
		if (!actions[BUTTON_PUZZLE2_SOLVED]) {
			printf("Aside from the closed door from where you came, there is another closed door to the WEST.\n\n");
		} else {
			printf("The only exit is to the WEST.\n\n");
		}
	} else if (actions[FLIPPED]) {
		printf(".ecalp siht fo moor tsrif eht morf seno eht ekil hcum mees taht SRIATS era erehT\n.'TESER' delebal NOTTUB a si gniliec eht no renroc a nI\n.gniliec eht dna roolf eht htob no NOTTUB THGIR dna TFEL a si erehT\n.sNOTTUB evif sah moor sihT\n");
		if (actions[BUTTON_CEIL_LEFT_LIT]) {
			printf(".til si roolf eht no nottub tfel ehT\n");
		} else {
			printf(".tilnu si roolf eht no nottub tfel ehT\n");
		}
		if (actions[BUTTON_CEIL_RIGHT_LIT]) {
			printf(".til si roolf eht no nottub thgir ehT\n");
		} else {
			printf(".tilnu si roolf eht no nottub thgir ehT\n");
		}
		if (actions[BUTTON_FLOOR_LEFT_LIT]) {
			printf(".til si gniliec eht no nottub tfel ehT\n");
		} else {
			printf(".tilnu si gniliec eht no nottub tfel ehT\n");
		}
		if (actions[BUTTON_FLOOR_RIGHT_LIT]) {
			printf(".til si gniliec eht no nottub thgir ehT\n");
		} else {
			printf(".tilnu si gniliec eht no nottub thgir ehT\n");
		}
		if (!actions[BUTTON_PUZZLE2_SOLVED]) {
			printf(".TSEW eht ot rood desolc rehtona si ereht ,emac uoy erehw morf rood desolc eht morf edisA\n\n");
		} else {
			printf(".TSEW eht ot si tixe ylno ehT\n\n");
		}
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (!actions[FLIPPED]) {
		if (strcmp(chosen_action, "press left button") == 0) {
			if (!actions[BUTTON_PUZZLE2_SOLVED]) {
				printf("You press the button on the left.\n\n");
				if (!actions[BUTTON_FLOOR_LEFT_LIT]) {
					actions[BUTTON_CEIL_RIGHT_LIT] ^= 1;
					actions[BUTTON_FLOOR_RIGHT_LIT] ^= 1;
				} else if (actions[BUTTON_FLOOR_LEFT_LIT]) {
					actions[BUTTON_CEIL_LEFT_LIT] ^= 1;
					actions[BUTTON_FLOOR_LEFT_LIT] ^= 1;
				}
			} else {
				printf("You don't need to do that anymore...\n\n");
			}
		} else if (strcmp(chosen_action, "press right button") == 0) {
			if (!actions[BUTTON_PUZZLE2_SOLVED]) {
				printf("You press the button on the right.\n\n");
				if (!actions[BUTTON_FLOOR_RIGHT_LIT]) {
					actions[BUTTON_CEIL_LEFT_LIT] ^= 1;
					actions[BUTTON_FLOOR_RIGHT_LIT] ^= 1;
				} else if (actions[BUTTON_FLOOR_RIGHT_LIT]) {
					actions[BUTTON_FLOOR_RIGHT_LIT] ^= 1;
				}
			} else {
				printf("You don't need to do that anymore...\n\n");
			}
		} else if (strcmp(chosen_action, "press reset button") == 0) {
			if (!actions[BUTTON_PUZZLE2_SOLVED]) {
				printf("You press the button on the right.\n\n");
				actions[BUTTON_CEIL_LEFT_LIT] = 0;
				actions[BUTTON_CEIL_RIGHT_LIT] = 0;
				actions[BUTTON_FLOOR_LEFT_LIT] = 0;
				actions[BUTTON_FLOOR_RIGHT_LIT] = 0;
			} else {
				printf("You don't need to do that anymore...\n\n");
			}
		} else if (strcmp(chosen_action, "go up stairs") == 0 || strcmp(chosen_action, "head up stairs") == 0 || strcmp(chosen_action, "walk up stairs") == 0 || strcmp(chosen_action, "travel up stairs") == 0 || strcmp(chosen_action, "move up stairs") == 0 || strcmp(chosen_action, "proceed up stairs") == 0 || strcmp(chosen_action, "advance up stairs") == 0 || strcmp(chosen_action, "leave up stairs") == 0) {
			printf("You climb up the stairs, but it only leads into a dead end at the ceiling.\nWhat is the point of these stairs?\n\n");
		} else if (strcmp(chosen_action, "go down stairs") == 0 || strcmp(chosen_action, "head down stairs") == 0 || strcmp(chosen_action, "walk down stairs") == 0 || strcmp(chosen_action, "travel down stairs") == 0 || strcmp(chosen_action, "move down stairs") == 0 || strcmp(chosen_action, "proceed down stairs") == 0 || strcmp(chosen_action, "advance down stairs") == 0 || strcmp(chosen_action, "leave down stairs") == 0) {
			printf("Strangely enough, you walk down the stairs. You end up on the ceiling?\nNo, you are on the floor, but everything looks flipped?\n\n");
			actions[FLIPPED] = 1;
		} else if (strcmp(chosen_action, "go west") == 0 || strcmp(chosen_action, "head west") == 0 || strcmp(chosen_action, "walk west") == 0 || strcmp(chosen_action, "travel west") == 0 || strcmp(chosen_action, "move west") == 0 || strcmp(chosen_action, "proceed west") == 0 || strcmp(chosen_action, "advance west") == 0 || strcmp(chosen_action, "leave west") == 0) {
			printf("You travel west through the doorway, once again it shuts behind you.\n\n");
			*current_location = THE_ELSE14;
		} else {
			printInvalid();
		}
	} else if (actions[FLIPPED]) {
		if (strcmp(chosen_action, "nottub tfel sserp") == 0) {
			if (!actions[BUTTON_PUZZLE2_SOLVED]) {
				printf(".tfel eht no nottub eht sserp uoY\n\n");
				if (!actions[BUTTON_CEIL_LEFT_LIT]) {
					actions[BUTTON_FLOOR_LEFT_LIT] ^= 1;
					actions[BUTTON_FLOOR_RIGHT_LIT] ^= 1;
				} else if (actions[BUTTON_CEIL_LEFT_LIT]) {
					actions[BUTTON_CEIL_RIGHT_LIT] ^= 1;
					actions[BUTTON_FLOOR_LEFT_LIT] ^= 1;
				}
			} else {
				printf("...eromyna taht od ot deen t'nod uoY\n\n");
			}
		} else if (strcmp(chosen_action, "nottub thgir sserp") == 0) {
			if (!actions[BUTTON_PUZZLE2_SOLVED]) {
				printf(".thgir eht no nottub eht sserp uoYn\n");
				if (!actions[BUTTON_CEIL_RIGHT_LIT]) {
					actions[BUTTON_FLOOR_LEFT_LIT] ^= 1;
					actions[BUTTON_FLOOR_RIGHT_LIT] ^= 1;
				} else if (actions[BUTTON_CEIL_RIGHT_LIT]) {
					actions[BUTTON_CEIL_RIGHT_LIT] ^= 1;
					actions[BUTTON_CEIL_LEFT_LIT] ^= 1;
				}
			} else {
				printf("...eromyna taht od ot deen t'nod uoY\n\n");
			}
		} else if (strcmp(chosen_action, "sriats pu og") == 0 || strcmp(chosen_action, "sriats pu daeh") == 0 || strcmp(chosen_action, "sriats pu levart") == 0 || strcmp(chosen_action, "sriats pu klaw") == 0) {
			printf("?sriats eseht fo tniop eht si tahW\n.gniliec eht ta dne daed a otni sdael ylno ti tub ,sriats eht pu bmilc uoY\n\n");
		} else if (strcmp(chosen_action, "sriats nwod og") == 0 || strcmp(chosen_action, "sriats nwod daeh") == 0 || strcmp(chosen_action, "sriats nwod levart") == 0 || strcmp(chosen_action, "sriats nwod klaw") == 0) {
			printf("?deppilf skool gnihtyreve tub ,roolf eht no era uoy ,oN\n?gniliec eht no pu dne uoY .sriats eht nwod klaw uoy ,hguone ylegnartS\n\n");
			actions[FLIPPED] = 0;
		} else {
			printReverseInvalid();
		}
	}
	
	if (!actions[BUTTON_PUZZLE2_SOLVED] && actions[BUTTON_CEIL_LEFT_LIT] && actions[BUTTON_CEIL_RIGHT_LIT] && actions[BUTTON_FLOOR_LEFT_LIT] && actions[BUTTON_FLOOR_RIGHT_LIT]) {
		if (!actions[FLIPPED]) {
			printf("You hear the door to the WEST slide open.\n\n");
		} else {
			printf(".nepo edils TSEW eht ot rood eht raeh uoY\n\n");
		}
		actions[BUTTON_PUZZLE2_SOLVED] = 1;
	}
	
	return 1;
}

bool room_THE_ELSE14(char name[], int *current_location, bool actions[], int *coins) {
	printf("There is WRITING on the wall in this room.\nThere is once again that same puffy CREATURE from earlier in here, standing next to the door to the SOUTH.\n");
	if (!actions[CRYPTO_PUZZLE_SOLVED]) {
		printf("The door to the SOUTH is shut tight.\n\n");
	} else {
		printf("The door to the SOUTH is open.\n\n");
	}
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "check writing") == 0 || strcmp(chosen_action, "examine writing") == 0 || strcmp(chosen_action, "look at writing") == 0 || strcmp(chosen_action, "investigate writing") == 0 || strcmp(chosen_action, "view writing") == 0) {
		printf("The writing looks like this:\njgs ylf ysjy zfu jgs vkkf pxysy. uzw jlpfy jk fxmgj, jgsf rzno jk uzw, xf z yssvxfmiw sfuisyy nwnis. jgs tzyyhkpu xy zpngxjsnjlps. nzf hs sqsp npszjs, kp kfiw rlxiu hxjg hgzj xy jgsps?\n\n");
	} else if (strcmp(chosen_action, "check creature") == 0 || strcmp(chosen_action, "examine creature") == 0 || strcmp(chosen_action, "look at creature") == 0 || strcmp(chosen_action, "investigate creature") == 0 || strcmp(chosen_action, "view creature") == 0) {
		printf("The creature kind of reminds you of a marshmallow.\nIt has vertical black and white stripes all over its body.\n\n");
	} else if (strcmp(chosen_action, "talk to creature") == 0 || strcmp(chosen_action, "speak to creature") == 0 || strcmp(chosen_action, "chat with creature") == 0 || strcmp(chosen_action, "talk with creature") == 0 || strcmp(chosen_action, "converse with creature") == 0) {
		if (!actions[CRYPTO_PUZZLE_SOLVED]) {
			printf("CREATURE: What is the password? Answer: ");
			char pass[64];
			scanf("%[^\n]%*c", pass);
			lowercase(pass);
			if (strcmp(pass, "architecture") == 0) {
				printf("CREATURE: That's right, good job!\nYou see the door next to the creature slide open.\n\n");
				actions[CRYPTO_PUZZLE_SOLVED] = 1;
			} else {
				printf("CREATURE: Sorry, that's incorrect...\n\n"); //FLAG
			}
		} else {
			printf("CREATURE: Take a deep breath, you're almost there!\n\n");
		}
	} else if (strcmp(chosen_action, "go south") == 0 || strcmp(chosen_action, "head south") == 0 || strcmp(chosen_action, "walk south") == 0 || strcmp(chosen_action, "travel south") == 0 || strcmp(chosen_action, "move south") == 0 || strcmp(chosen_action, "proceed south") == 0 || strcmp(chosen_action, "advance south") == 0 || strcmp(chosen_action, "leave south") == 0) {
		if (!actions[CRYPTO_PUZZLE_SOLVED]) {
			printf("The door to the SOUTH won't open.\nThe CREATURE looks like it wants to ask you something...\n\n");
		} else {
			printf("You pass through the SOUTH door, it slides shut as soon as you are inside.\n\n");
			*current_location = THE_ELSE15;
		}
	} else {
		printInvalid();
	}
	
	return 1;
}

bool room_THE_ELSE15(char name[], int *current_location, bool actions[], int *coins) {
	int correct[] = { 0, GREEN, ORANGE, VIOLET, BLUE, INDIGO, YELLOW, RED };
	char orbs[][24] = { "is empty", "has the RED ORB",  "has the ORANGE ORB",  "has the YELLOW ORB",  "has the GREEN ORB",  "has the BLUE ORB",  "has the INDIGO ORB",  "has the VIOLET ORB" };
	static int pedestals[] = { 0, RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET };
	
	printf("In this room is the squirrel-like CREATURE, the WITCH, the MUSHROOM CREATURE, the JESTER, and the OLD MAN.\nThere are seven pedestals in the center.\n");
	if (!actions[FINAL_PUZZLE_SOLVED]) {
		printf("There is a door to the EAST, but it is closed.\n\n");
	} else {
		printf("The door to the EAST is open.\n\n");
	}
	printf("The FIRST pedestal %s, The SECOND pedestal %s, The THIRD pedestal %s, The FOURTH pedestal %s, The FIFTH pedestal %s, The SIXTH pedestal %s, and The SEVENTH pedestal %s.\n\n", orbs[pedestals[FIRST]], orbs[pedestals[SECOND]], orbs[pedestals[THIRD]], orbs[pedestals[FOURTH]], orbs[pedestals[FIFTH]], orbs[pedestals[SIXTH]], orbs[pedestals[SEVENTH]]); 
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "talk to creature") == 0 || strcmp(chosen_action, "speak to creature") == 0 || strcmp(chosen_action, "chat with creature") == 0 || strcmp(chosen_action, "talk with creature") == 0 || strcmp(chosen_action, "converse with creature") == 0) {
		printf("CREATURE: The seedling sprouts at dawn...\n\n");
	} else if (strcmp(chosen_action, "talk to witch") == 0 || strcmp(chosen_action, "speak to witch") == 0 || strcmp(chosen_action, "chat with witch") == 0 || strcmp(chosen_action, "talk with witch") == 0 || strcmp(chosen_action, "converse with witch") == 0) {
		printf("WITCH: Does the ocean surround all, or does all surround the ocean?\n\n");
	} else if (strcmp(chosen_action, "talk to mushroom creature") == 0 || strcmp(chosen_action, "speak to mushroom creature") == 0 || strcmp(chosen_action, "chat with mushroom creature") == 0 || strcmp(chosen_action, "talk with mushroom creature") == 0 || strcmp(chosen_action, "converse with mushroom creature") == 0) {
		printf("MUSHROOM CREATURE: The candle burns at midnight...\n\n");
	} else if (strcmp(chosen_action, "talk to jester") == 0 || strcmp(chosen_action, "speak to jester") == 0 || strcmp(chosen_action, "chat with jester") == 0 || strcmp(chosen_action, "talk with jester") == 0 || strcmp(chosen_action, "converse with jester") == 0) {
		printf("JESTER: Gold is found after the river ends...\n\n");
	} else if (strcmp(chosen_action, "talk to old man") == 0 || strcmp(chosen_action, "speak to old man") == 0 || strcmp(chosen_action, "chat with old man") == 0 || strcmp(chosen_action, "talk with old man") == 0 || strcmp(chosen_action, "converse with old man") == 0) {
		printf("OLD MAN: The fruit grows from the sprout...\n\n");
	} else if (strcmp(chosen_action, "get red orb") == 0 || strcmp(chosen_action, "pick up red orb") == 0 || strcmp(chosen_action, "grab red orb") == 0 || strcmp(chosen_action, "take red orb") == 0 || strcmp(chosen_action, "acquire red orb") == 0 || strcmp(chosen_action, "obtain red orb") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (!actions[ELSE_GET_RED_ORB]) {
				printf("You take the red orb from a pedestal.\n\n");
				for (int i = 1; i < 8; i++) {
					if (pedestals[i] == RED) {
						pedestals[i] = EMPTY;
						actions[ELSE_GET_RED_ORB] = 1;
						break;
					}
				}
			} else {
				printf("You already have the red orb!\n\n");
			}
		} else {
			printf("There's no need for that now...\n\n");
		}
	} else if (strcmp(chosen_action, "get orange orb") == 0 || strcmp(chosen_action, "pick up orange orb") == 0 || strcmp(chosen_action, "grab orange orb") == 0 || strcmp(chosen_action, "take orange orb") == 0 || strcmp(chosen_action, "acquire orange orb") == 0 || strcmp(chosen_action, "obtain orange orb") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (!actions[ELSE_GET_ORANGE_ORB]) {
				printf("You take the orange orb from a pedestal.\n\n");
				for (int i = 1; i < 8; i++) {
					if (pedestals[i] == ORANGE) {
						pedestals[i] = EMPTY;
						actions[ELSE_GET_ORANGE_ORB] = 1;
						break;
					}
				}
			} else {
				printf("You already have the orange orb!\n\n");
			}
		} else {
			printf("There's no need for that now...\n\n");
		}
	} else if (strcmp(chosen_action, "get yellow orb") == 0 || strcmp(chosen_action, "pick up yellow orb") == 0 || strcmp(chosen_action, "grab yellow orb") == 0 || strcmp(chosen_action, "take yellow orb") == 0 || strcmp(chosen_action, "acquire yellow orb") == 0 || strcmp(chosen_action, "obtain yellow orb") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (!actions[ELSE_GET_YELLOW_ORB]) {
				printf("You take the yellow orb from a pedestal.\n\n");
				for (int i = 1; i < 8; i++) {
					if (pedestals[i] == YELLOW) {
						pedestals[i] = EMPTY;
						actions[ELSE_GET_YELLOW_ORB] = 1;
						break;
					}
				}
			} else {
				printf("You already have the yellow orb!\n\n");
			}
		} else {
			printf("There's no need for that now...\n\n");
		}
	} else if (strcmp(chosen_action, "get green orb") == 0 || strcmp(chosen_action, "pick up green orb") == 0 || strcmp(chosen_action, "grab green orb") == 0 || strcmp(chosen_action, "take green orb") == 0 || strcmp(chosen_action, "acquire green orb") == 0 || strcmp(chosen_action, "obtain green orb") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (!actions[ELSE_GET_GREEN_ORB]) {
				printf("You take the green orb from a pedestal.\n\n");
				for (int i = 1; i < 8; i++) {
					if (pedestals[i] == GREEN) {
						pedestals[i] = EMPTY;
						actions[ELSE_GET_GREEN_ORB] = 1;
						break;
					}
				}
			} else {
				printf("You already have the green orb!\n\n");
			}
		} else {
			printf("There's no need for that now...\n\n");
		}
	} else if (strcmp(chosen_action, "get blue orb") == 0 || strcmp(chosen_action, "pick up blue orb") == 0 || strcmp(chosen_action, "grab blue orb") == 0 || strcmp(chosen_action, "take blue orb") == 0 || strcmp(chosen_action, "acquire blue orb") == 0 || strcmp(chosen_action, "obtain blue orb") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (!actions[ELSE_GET_BLUE_ORB]) {
				printf("You take the blue orb from a pedestal.\n\n");
				for (int i = 1; i < 8; i++) {
					if (pedestals[i] == BLUE) {
						pedestals[i] = EMPTY;
						actions[ELSE_GET_BLUE_ORB] = 1;
						break;
					}
				}
			} else {
				printf("You already have the blue orb!\n\n");
			}
		} else {
			printf("There's no need for that now...\n\n");
		}
	} else if (strcmp(chosen_action, "get indigo orb") == 0 || strcmp(chosen_action, "pick up indigo orb") == 0 || strcmp(chosen_action, "grab indigo orb") == 0 || strcmp(chosen_action, "take indigo orb") == 0 || strcmp(chosen_action, "acquire indigo orb") == 0 || strcmp(chosen_action, "obtain indigo orb") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (!actions[ELSE_GET_INDIGO_ORB]) {
				printf("You take the indigo orb from a pedestal.\n\n");
				for (int i = 1; i < 8; i++) {
					if (pedestals[i] == INDIGO) {
						pedestals[i] = EMPTY;
						actions[ELSE_GET_INDIGO_ORB] = 1;
						break;
					}
				}
			} else {
				printf("You already have the indigo orb!\n\n");
			}
		} else {
			printf("There's no need for that now...\n\n");
		}
	} else if (strcmp(chosen_action, "get violet orb") == 0 || strcmp(chosen_action, "pick up violet orb") == 0 || strcmp(chosen_action, "grab violet orb") == 0 || strcmp(chosen_action, "take violet orb") == 0 || strcmp(chosen_action, "acquire violet orb") == 0 || strcmp(chosen_action, "obtain violet orb") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (!actions[ELSE_GET_VIOLET_ORB]) {
				printf("You take the violet orb from a pedestal.\n\n");
				for (int i = 1; i < 8; i++) {
					if (pedestals[i] == VIOLET) {
						pedestals[i] = EMPTY;
						actions[ELSE_GET_VIOLET_ORB] = 1;
						break;
					}
				}
			} else {
				printf("You already have the violet orb!\n\n");
			}
		} else {
			printf("There's no need for that now...\n\n");
		}
	} else if (strcmp(chosen_action, "place red orb first") == 0 || strcmp(chosen_action, "set red orb first") == 0 || strcmp(chosen_action, "put red orb first") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIRST] == EMPTY) {
				if (actions[ELSE_GET_RED_ORB]) {
					printf("You place the RED ORB on the FIRST pedestal.\n\n");
					actions[ELSE_GET_RED_ORB] = 0;
					pedestals[FIRST] = RED;
				} else {
					printf("You don't have the RED ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place red orb second") == 0 || strcmp(chosen_action, "set red orb second") == 0 || strcmp(chosen_action, "put red orb second") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SECOND] == EMPTY) {
				if (actions[ELSE_GET_RED_ORB]) {
					printf("You place the RED ORB on the SECOND pedestal.\n\n");
					actions[ELSE_GET_RED_ORB] = 0;
					pedestals[SECOND] = RED;
				} else {
					printf("You don't have the RED ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place red orb third") == 0 || strcmp(chosen_action, "set red orb third") == 0 || strcmp(chosen_action, "put red orb third") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[THIRD] == EMPTY) {
				if (actions[ELSE_GET_RED_ORB]) {
					printf("You place the RED ORB on the THIRD pedestal.\n\n");
					actions[ELSE_GET_RED_ORB] = 0;
					pedestals[THIRD] = RED;
				} else {
					printf("You don't have the RED ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place red orb fourth") == 0 || strcmp(chosen_action, "set red orb fourth") == 0 || strcmp(chosen_action, "put red orb fourth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FOURTH] == EMPTY) {
				if (actions[ELSE_GET_RED_ORB]) {
					printf("You place the RED ORB on the FOURTH pedestal.\n\n");
					actions[ELSE_GET_RED_ORB] = 0;
					pedestals[FOURTH] = RED;
				} else {
					printf("You don't have the RED ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place red orb fifth") == 0 || strcmp(chosen_action, "set red orb fifth") == 0 || strcmp(chosen_action, "put red orb fifth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIFTH] == EMPTY) {
				if (actions[ELSE_GET_RED_ORB]) {
					printf("You place the RED ORB on the FIFTH pedestal.\n\n");
					actions[ELSE_GET_RED_ORB] = 0;
					pedestals[FIFTH] = RED;
				} else {
					printf("You don't have the RED ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place red orb sixth") == 0 || strcmp(chosen_action, "set red orb sixth") == 0 || strcmp(chosen_action, "put red orb sixth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SIXTH] == EMPTY) {
				if (actions[ELSE_GET_RED_ORB]) {
					printf("You place the RED ORB on the SIXTH pedestal.\n\n");
					actions[ELSE_GET_RED_ORB] = 0;
					pedestals[SIXTH] = RED;
				} else {
					printf("You don't have the RED ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place red orb seventh") == 0 || strcmp(chosen_action, "set red orb seventh") == 0 || strcmp(chosen_action, "put red orb seventh") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SEVENTH] == EMPTY) {
				if (actions[ELSE_GET_RED_ORB]) {
					printf("You place the RED ORB on the SEVENTH pedestal.\n\n");
					actions[ELSE_GET_RED_ORB] = 0;
					pedestals[SEVENTH] = RED;
				} else {
					printf("You don't have the RED ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place orange orb first") == 0 || strcmp(chosen_action, "set orange orb first") == 0 || strcmp(chosen_action, "put orange orb first") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIRST] == EMPTY) {
				if (actions[ELSE_GET_ORANGE_ORB]) {
					printf("You place the ORANGE ORB on the FIRST pedestal.\n\n");
					actions[ELSE_GET_ORANGE_ORB] = 0;
					pedestals[FIRST] = ORANGE;
				} else {
					printf("You don't have the ORANGE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place orange orb second") == 0 || strcmp(chosen_action, "set orange orb second") == 0 || strcmp(chosen_action, "put orange orb second") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SECOND] == EMPTY) {
				if (actions[ELSE_GET_ORANGE_ORB]) {
					printf("You place the ORANGE ORB on the SECOND pedestal.\n\n");
					actions[ELSE_GET_ORANGE_ORB] = 0;
					pedestals[SECOND] = ORANGE;
				} else {
					printf("You don't have the ORANGE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place orange orb third") == 0 || strcmp(chosen_action, "set orange orb third") == 0 || strcmp(chosen_action, "put orange orb third") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[THIRD] == EMPTY) {
				if (actions[ELSE_GET_ORANGE_ORB]) {
					printf("You place the ORANGE ORB on the THIRD pedestal.\n\n");
					actions[ELSE_GET_ORANGE_ORB] = 0;
					pedestals[THIRD] = ORANGE;
				} else {
					printf("You don't have the ORANGE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place orange orb fourth") == 0 || strcmp(chosen_action, "set orange orb fourth") == 0 || strcmp(chosen_action, "put orange orb fourth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FOURTH] == EMPTY) {
				if (actions[ELSE_GET_ORANGE_ORB]) {
					printf("You place the ORANGE ORB on the FOURTH pedestal.\n\n");
					actions[ELSE_GET_ORANGE_ORB] = 0;
					pedestals[FOURTH] = ORANGE;
				} else {
					printf("You don't have the ORANGE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place orange orb fifth") == 0 || strcmp(chosen_action, "set orange orb fifth") == 0 || strcmp(chosen_action, "put orange orb fifth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIFTH] == EMPTY) {
				if (actions[ELSE_GET_ORANGE_ORB]) {
					printf("You place the ORANGE ORB on the FIFTH pedestal.\n\n");
					actions[ELSE_GET_ORANGE_ORB] = 0;
					pedestals[FIFTH] = ORANGE;
				} else {
					printf("You don't have the ORANGE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place orange orb sixth") == 0 || strcmp(chosen_action, "set orange orb sixth") == 0 || strcmp(chosen_action, "put orange orb sixth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SIXTH] == EMPTY) {
				if (actions[ELSE_GET_ORANGE_ORB]) {
					printf("You place the ORANGE ORB on the SIXTH pedestal.\n\n");
					actions[ELSE_GET_ORANGE_ORB] = 0;
					pedestals[SIXTH] = ORANGE;
				} else {
					printf("You don't have the ORANGE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place orange orb seventh") == 0 || strcmp(chosen_action, "set orange orb seventh") == 0 || strcmp(chosen_action, "put orange orb seventh") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SEVENTH] == EMPTY) {
				if (actions[ELSE_GET_ORANGE_ORB]) {
					printf("You place the ORANGE ORB on the SEVENTH pedestal.\n\n");
					actions[ELSE_GET_ORANGE_ORB] = 0;
					pedestals[SEVENTH] = ORANGE;
				} else {
					printf("You don't have the ORANGE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place yellow orb first") == 0 || strcmp(chosen_action, "set yellow orb first") == 0 || strcmp(chosen_action, "put yellow orb first") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIRST] == EMPTY) {
				if (actions[ELSE_GET_YELLOW_ORB]) {
					printf("You place the YELLOW ORB on the FIRST pedestal.\n\n");
					actions[ELSE_GET_YELLOW_ORB] = 0;
					pedestals[FIRST] = YELLOW;
				} else {
					printf("You don't have the YELLOW ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place yellow orb second") == 0 || strcmp(chosen_action, "set yellow orb second") == 0 || strcmp(chosen_action, "put yellow orb second") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SECOND] == EMPTY) {
				if (actions[ELSE_GET_YELLOW_ORB]) {
					printf("You place the YELLOW ORB on the SECOND pedestal.\n\n");
					actions[ELSE_GET_YELLOW_ORB] = 0;
					pedestals[SECOND] = YELLOW;
				} else {
					printf("You don't have the YELLOW ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place yellow orb third") == 0 || strcmp(chosen_action, "set yellow orb third") == 0 || strcmp(chosen_action, "put yellow orb third") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[THIRD] == EMPTY) {
				if (actions[ELSE_GET_YELLOW_ORB]) {
					printf("You place the YELLOW ORB on the THIRD pedestal.\n\n");
					actions[ELSE_GET_YELLOW_ORB] = 0;
					pedestals[THIRD] = YELLOW;
				} else {
					printf("You don't have the YELLOW ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place yellow orb fourth") == 0 || strcmp(chosen_action, "set yellow orb fourth") == 0 || strcmp(chosen_action, "put yellow orb fourth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FOURTH] == EMPTY) {
				if (actions[ELSE_GET_YELLOW_ORB]) {
					printf("You place the YELLOW ORB on the FOURTH pedestal.\n\n");
					actions[ELSE_GET_YELLOW_ORB] = 0;
					pedestals[FOURTH] = YELLOW;
				} else {
					printf("You don't have the YELLOW ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place yellow orb fifth") == 0 || strcmp(chosen_action, "set yellow orb fifth") == 0 || strcmp(chosen_action, "put yellow orb fifth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIFTH] == EMPTY) {
				if (actions[ELSE_GET_YELLOW_ORB]) {
					printf("You place the YELLOW ORB on the FIFTH pedestal.\n\n");
					actions[ELSE_GET_YELLOW_ORB] = 0;
					pedestals[FIFTH] = YELLOW;
				} else {
					printf("You don't have the YELLOW ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place yellow orb sixth") == 0 || strcmp(chosen_action, "set yellow orb sixth") == 0 || strcmp(chosen_action, "put yellow orb sixth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SIXTH] == EMPTY) {
				if (actions[ELSE_GET_YELLOW_ORB]) {
					printf("You place the YELLOW ORB on the SIXTH pedestal.\n\n");
					actions[ELSE_GET_YELLOW_ORB] = 0;
					pedestals[SIXTH] = YELLOW;
				} else {
					printf("You don't have the YELLOW ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place yellow orb seventh") == 0 || strcmp(chosen_action, "set yellow orb seventh") == 0 || strcmp(chosen_action, "put yellow orb seventh") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SEVENTH] == EMPTY) {
				if (actions[ELSE_GET_YELLOW_ORB]) {
					printf("You place the YELLOW ORB on the SEVENTH pedestal.\n\n");
					actions[ELSE_GET_YELLOW_ORB] = 0;
					pedestals[SEVENTH] = YELLOW;
				} else {
					printf("You don't have the YELLOW ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place green orb first") == 0 || strcmp(chosen_action, "set green orb first") == 0 || strcmp(chosen_action, "put green orb first") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIRST] == EMPTY) {
				if (actions[ELSE_GET_GREEN_ORB]) {
					printf("You place the GREEN ORB on the FIRST pedestal.\n\n");
					actions[ELSE_GET_GREEN_ORB] = 0;
					pedestals[FIRST] = GREEN;
				} else {
					printf("You don't have the GREEN ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place green orb second") == 0 || strcmp(chosen_action, "set green orb second") == 0 || strcmp(chosen_action, "put green orb second") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SECOND] == EMPTY) {
				if (actions[ELSE_GET_GREEN_ORB]) {
					printf("You place the GREEN ORB on the SECOND pedestal.\n\n");
					actions[ELSE_GET_GREEN_ORB] = 0;
					pedestals[SECOND] = GREEN;
				} else {
					printf("You don't have the GREEN ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place green orb third") == 0 || strcmp(chosen_action, "set green orb third") == 0 || strcmp(chosen_action, "put green orb third") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[THIRD] == EMPTY) {
				if (actions[ELSE_GET_GREEN_ORB]) {
					printf("You place the GREEN ORB on the THIRD pedestal.\n\n");
					actions[ELSE_GET_GREEN_ORB] = 0;
					pedestals[THIRD] = GREEN;
				} else {
					printf("You don't have the GREEN ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place green orb fourth") == 0 || strcmp(chosen_action, "set green orb fourth") == 0 || strcmp(chosen_action, "put green orb fourth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FOURTH] == EMPTY) {
				if (actions[ELSE_GET_GREEN_ORB]) {
					printf("You place the GREEN ORB on the FOURTH pedestal.\n\n");
					actions[ELSE_GET_GREEN_ORB] = 0;
					pedestals[FOURTH] = GREEN;
				} else {
					printf("You don't have the GREEN ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place green orb fifth") == 0 || strcmp(chosen_action, "set green orb fifth") == 0 || strcmp(chosen_action, "put green orb fifth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIFTH] == EMPTY) {
				if (actions[ELSE_GET_GREEN_ORB]) {
					printf("You place the GREEN ORB on the FIFTH pedestal.\n\n");
					actions[ELSE_GET_GREEN_ORB] = 0;
					pedestals[FIFTH] = GREEN;
				} else {
					printf("You don't have the GREEN ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place green orb sixth") == 0 || strcmp(chosen_action, "set green orb sixth") == 0 || strcmp(chosen_action, "put green orb sixth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SIXTH] == EMPTY) {
				if (actions[ELSE_GET_GREEN_ORB]) {
					printf("You place the GREEN ORB on the SIXTH pedestal.\n\n");
					actions[ELSE_GET_GREEN_ORB] = 0;
					pedestals[SIXTH] = GREEN;
				} else {
					printf("You don't have the GREEN ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place green orb seventh") == 0 || strcmp(chosen_action, "set green orb seventh") == 0 || strcmp(chosen_action, "put green orb seventh") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SEVENTH] == EMPTY) {
				if (actions[ELSE_GET_GREEN_ORB]) {
					printf("You place the GREEN ORB on the SEVENTH pedestal.\n\n");
					actions[ELSE_GET_GREEN_ORB] = 0;
					pedestals[SEVENTH] = GREEN;
				} else {
					printf("You don't have the GREEN ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place blue orb first") == 0 || strcmp(chosen_action, "set blue orb first") == 0 || strcmp(chosen_action, "put blue orb first") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIRST] == EMPTY) {
				if (actions[ELSE_GET_BLUE_ORB]) {
					printf("You place the BLUE ORB on the FIRST pedestal.\n\n");
					actions[ELSE_GET_BLUE_ORB] = 0;
					pedestals[FIRST] = BLUE;
				} else {
					printf("You don't have the BLUE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place blue orb second") == 0 || strcmp(chosen_action, "set blue orb second") == 0 || strcmp(chosen_action, "put blue orb second") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SECOND] == EMPTY) {
				if (actions[ELSE_GET_BLUE_ORB]) {
					printf("You place the BLUE ORB on the SECOND pedestal.\n\n");
					actions[ELSE_GET_BLUE_ORB] = 0;
					pedestals[SECOND] = BLUE;
				} else {
					printf("You don't have the BLUE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place blue orb third") == 0 || strcmp(chosen_action, "set blue orb third") == 0 || strcmp(chosen_action, "put blue orb third") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[THIRD] == EMPTY) {
				if (actions[ELSE_GET_BLUE_ORB]) {
					printf("You place the BLUE ORB on the THIRD pedestal.\n\n");
					actions[ELSE_GET_BLUE_ORB] = 0;
					pedestals[THIRD] = BLUE;
				} else {
					printf("You don't have the BLUE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place blue orb fourth") == 0 || strcmp(chosen_action, "set blue orb fourth") == 0 || strcmp(chosen_action, "put blue orb fourth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FOURTH] == EMPTY) {
				if (actions[ELSE_GET_BLUE_ORB]) {
					printf("You place the BLUE ORB on the FOURTH pedestal.\n\n");
					actions[ELSE_GET_BLUE_ORB] = 0;
					pedestals[FOURTH] = BLUE;
				} else {
					printf("You don't have the BLUE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place blue orb fifth") == 0 || strcmp(chosen_action, "set blue orb fifth") == 0 || strcmp(chosen_action, "put blue orb fifth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIFTH] == EMPTY) {
				if (actions[ELSE_GET_BLUE_ORB]) {
					printf("You place the BLUE ORB on the FIFTH pedestal.\n\n");
					actions[ELSE_GET_BLUE_ORB] = 0;
					pedestals[FIFTH] = BLUE;
				} else {
					printf("You don't have the BLUE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place blue orb sixth") == 0 || strcmp(chosen_action, "set blue orb sixth") == 0 || strcmp(chosen_action, "put blue orb sixth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SIXTH] == EMPTY) {
				if (actions[ELSE_GET_BLUE_ORB]) {
					printf("You place the BLUE ORB on the SIXTH pedestal.\n\n");
					actions[ELSE_GET_BLUE_ORB] = 0;
					pedestals[SIXTH] = BLUE;
				} else {
					printf("You don't have the BLUE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place blue orb seventh") == 0 || strcmp(chosen_action, "set blue orb seventh") == 0 || strcmp(chosen_action, "put blue orb seventh") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SEVENTH] == EMPTY) {
				if (actions[ELSE_GET_BLUE_ORB]) {
					printf("You place the BLUE ORB on the SEVENTH pedestal.\n\n");
					actions[ELSE_GET_BLUE_ORB] = 0;
					pedestals[SEVENTH] = BLUE;
				} else {
					printf("You don't have the BLUE ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place indigo orb first") == 0 || strcmp(chosen_action, "set indigo orb first") == 0 || strcmp(chosen_action, "put indigo orb first") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIRST] == EMPTY) {
				if (actions[ELSE_GET_INDIGO_ORB]) {
					printf("You place the INDIGO ORB on the FIRST pedestal.\n\n");
					actions[ELSE_GET_INDIGO_ORB] = 0;
					pedestals[FIRST] = INDIGO;
				} else {
					printf("You don't have the INDIGO ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place indigo orb second") == 0 || strcmp(chosen_action, "set indigo orb second") == 0 || strcmp(chosen_action, "put indigo orb second") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SECOND] == EMPTY) {
				if (actions[ELSE_GET_INDIGO_ORB]) {
					printf("You place the INDIGO ORB on the SECOND pedestal.\n\n");
					actions[ELSE_GET_INDIGO_ORB] = 0;
					pedestals[SECOND] = INDIGO;
				} else {
					printf("You don't have the INDIGO ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place indigo orb third") == 0 || strcmp(chosen_action, "set indigo orb third") == 0 || strcmp(chosen_action, "put indigo orb third") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[THIRD] == EMPTY) {
				if (actions[ELSE_GET_INDIGO_ORB]) {
					printf("You place the INDIGO ORB on the THIRD pedestal.\n\n");
					actions[ELSE_GET_INDIGO_ORB] = 0;
					pedestals[THIRD] = INDIGO;
				} else {
					printf("You don't have the INDIGO ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place indigo orb fourth") == 0 || strcmp(chosen_action, "set indigo orb fourth") == 0 || strcmp(chosen_action, "put indigo orb fourth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FOURTH] == EMPTY) {
				if (actions[ELSE_GET_INDIGO_ORB]) {
					printf("You place the INDIGO ORB on the FOURTH pedestal.\n\n");
					actions[ELSE_GET_INDIGO_ORB] = 0;
					pedestals[FOURTH] = INDIGO;
				} else {
					printf("You don't have the INDIGO ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place indigo orb fifth") == 0 || strcmp(chosen_action, "set indigo orb fifth") == 0 || strcmp(chosen_action, "put indigo orb fifth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIFTH] == EMPTY) {
				if (actions[ELSE_GET_INDIGO_ORB]) {
					printf("You place the INDIGO ORB on the FIFTH pedestal.\n\n");
					actions[ELSE_GET_INDIGO_ORB] = 0;
					pedestals[FIFTH] = INDIGO;
				} else {
					printf("You don't have the INDIGO ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place indigo orb sixth") == 0 || strcmp(chosen_action, "set indigo orb sixth") == 0 || strcmp(chosen_action, "put indigo orb sixth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SIXTH] == EMPTY) {
				if (actions[ELSE_GET_INDIGO_ORB]) {
					printf("You place the INDIGO ORB on the SIXTH pedestal.\n\n");
					actions[ELSE_GET_INDIGO_ORB] = 0;
					pedestals[SIXTH] = INDIGO;
				} else {
					printf("You don't have the INDIGO ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place indigo orb seventh") == 0 || strcmp(chosen_action, "set indigo orb seventh") == 0 || strcmp(chosen_action, "put indigo orb seventh") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SEVENTH] == EMPTY) {
				if (actions[ELSE_GET_INDIGO_ORB]) {
					printf("You place the INDIGO ORB on the SEVENTH pedestal.\n\n");
					actions[ELSE_GET_INDIGO_ORB] = 0;
					pedestals[SEVENTH] = INDIGO;
				} else {
					printf("You don't have the INDIGO ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place violet orb first") == 0 || strcmp(chosen_action, "set violet orb first") == 0 || strcmp(chosen_action, "put violet orb first") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIRST] == EMPTY) {
				if (actions[ELSE_GET_VIOLET_ORB]) {
					printf("You place the VIOLET ORB on the FIRST pedestal.\n\n");
					actions[ELSE_GET_VIOLET_ORB] = 0;
					pedestals[FIRST] = VIOLET;
				} else {
					printf("You don't have the VIOLET ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place violet orb second") == 0 || strcmp(chosen_action, "set violet orb second") == 0 || strcmp(chosen_action, "put violet orb second") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SECOND] == EMPTY) {
				if (actions[ELSE_GET_VIOLET_ORB]) {
					printf("You place the VIOLET ORB on the SECOND pedestal.\n\n");
					actions[ELSE_GET_VIOLET_ORB] = 0;
					pedestals[SECOND] = VIOLET;
				} else {
					printf("You don't have the VIOLET ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place violet orb third") == 0 || strcmp(chosen_action, "set violet orb third") == 0 || strcmp(chosen_action, "put violet orb third") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[THIRD] == EMPTY) {
				if (actions[ELSE_GET_VIOLET_ORB]) {
					printf("You place the VIOLET ORB on the THIRD pedestal.\n\n");
					actions[ELSE_GET_VIOLET_ORB] = 0;
					pedestals[THIRD] = VIOLET;
				} else {
					printf("You don't have the VIOLET ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place violet orb fourth") == 0 || strcmp(chosen_action, "set violet orb fourth") == 0 || strcmp(chosen_action, "put violet orb fourth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FOURTH] == EMPTY) {
				if (actions[ELSE_GET_VIOLET_ORB]) {
					printf("You place the VIOLET ORB on the FOURTH pedestal.\n\n");
					actions[ELSE_GET_VIOLET_ORB] = 0;
					pedestals[FOURTH] = VIOLET;
				} else {
					printf("You don't have the VIOLET ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place violet orb fifth") == 0 || strcmp(chosen_action, "set violet orb fifth") == 0 || strcmp(chosen_action, "put violet orb fifth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[FIFTH] == EMPTY) {
				if (actions[ELSE_GET_VIOLET_ORB]) {
					printf("You place the VIOLET ORB on the FIFTH pedestal.\n\n");
					actions[ELSE_GET_VIOLET_ORB] = 0;
					pedestals[FIFTH] = VIOLET;
				} else {
					printf("You don't have the VIOLET ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place violet orb sixth") == 0 || strcmp(chosen_action, "set violet orb sixth") == 0 || strcmp(chosen_action, "put violet orb sixth") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SIXTH] == EMPTY) {
				if (actions[ELSE_GET_VIOLET_ORB]) {
					printf("You place the VIOLET ORB on the SIXTH pedestal.\n\n");
					actions[ELSE_GET_VIOLET_ORB] = 0;
					pedestals[SIXTH] = VIOLET;
				} else {
					printf("You don't have the VIOLET ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "place violet orb seventh") == 0 || strcmp(chosen_action, "set violet orb seventh") == 0 || strcmp(chosen_action, "put violet orb seventh") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			if (pedestals[SEVENTH] == EMPTY) {
				if (actions[ELSE_GET_VIOLET_ORB]) {
					printf("You place the VIOLET ORB on the SEVENTH pedestal.\n\n");
					actions[ELSE_GET_VIOLET_ORB] = 0;
					pedestals[SEVENTH] = VIOLET;
				} else {
					printf("You don't have the VIOLET ORB!\n\n");
				}
			} else {
				printf("There is already an orb on that pedestal...\n\n");
			}
		} else {
			printf("You don't have any orbs...\n\n");
		}
	} else if (strcmp(chosen_action, "go east") == 0 || strcmp(chosen_action, "head east") == 0 || strcmp(chosen_action, "walk east") == 0 || strcmp(chosen_action, "travel east") == 0 || strcmp(chosen_action, "move east") == 0 || strcmp(chosen_action, "proceed east") == 0 || strcmp(chosen_action, "advance east") == 0 || strcmp(chosen_action, "leave east") == 0) {
		if (!actions[FINAL_PUZZLE_SOLVED]) {
			printf("You can't get that door open right now.\n\n");
		} else {
			printf("You pass through the eastern door, it silently closes behind you.\n\n");
			*current_location = THE_ELSE16;
		}
	} else {
		printInvalid();
	}
	
	if (!actions[FINAL_PUZZLE_SOLVED]) {
		bool all_correct = 1;
		for (int i = 1; i < 8; i++) {
			if (pedestals[i] != correct[i]) {
				all_correct = 0;
				break;
			}
		}
		if (all_correct) {
			printf("You did it! The door slowly grinds open, and a wonderful feeling seems to seep out of it into you!\n\n");
			actions[FINAL_PUZZLE_SOLVED] = 1;
		}
	}
	
	return 1;
}

bool room_THE_ELSE16(char name[], int *current_location, bool actions[], int *coins) {
	printf("There is absolutely nothing in this room, the only exit is TO THE LIGHT.\nJust seeing its radiant glow fills you with immense joy.\n\n");
	
	char chosen_action[64];
	int check = getChoiceAndSave(chosen_action, name, *current_location, actions, *coins);
	if (check == -1) {
		return 0;
	} else if (check == 0) {
		return 1;
	}

	if (strcmp(chosen_action, "go to the light") == 0 || strcmp(chosen_action, "head to the light") == 0 || strcmp(chosen_action, "walk to the light") == 0 || strcmp(chosen_action, "travel to the light") == 0 || strcmp(chosen_action, "move to the light") == 0 || strcmp(chosen_action, "proceed to the light") == 0 || strcmp(chosen_action, "advance to the light") == 0 || strcmp(chosen_action, "leave to the light") == 0) {
		printf("You walk into the light, feeling a great feeling of completeness.\nIt feels like bliss, but not ignorant bliss, it comes with clarity.\nYou reflect on how far you've come, the people you've met along the way.\nMaybe this is the end, maybe it is a new beginning?\n\nYou find yourself in front of a computer, reading text on a screen.\n\nEnter an action...\n\n");
		return 0;
	} else {
		printInvalid();
	}
	
	return 1;
}

void setupLocations(bool (*locations[MAX_LOCATIONS])(char*, int*, bool*, int*)) {
	//Setup up array of pointers to functions
	//Cleans up main better
	
	//Intro
	locations[CELL] = room_CELL;
	locations[OUTSIDE_CELL] = room_OUTSIDE_CELL;
	locations[TREASURE_ROOM] = room_TREASURE_ROOM;
	
	//Forest
	locations[FOREST1] = room_FOREST1;
	locations[FOREST2] = room_FOREST2;
	locations[FOREST3] = room_FOREST3;
	locations[FOREST4] = room_FOREST4;
	locations[FOREST5] = room_FOREST5;
	locations[FOREST6] = room_FOREST6;
	locations[OUTSIDE_HUT] = room_OUTSIDE_HUT;
	locations[WITCH_HUT] = room_WITCH_HUT;
	locations[SHRUNK_HUT] = room_SHRUNK_HUT;
	locations[SHRUNK_CAT] = room_SHRUNK_CAT;
	locations[SHRUNK_MOUSE] = room_SHRUNK_MOUSE;
	
	//Labrynth
	locations[LAB1] = room_LAB1;
	locations[LAB2] = room_LAB2;
	locations[LAB3] = room_LAB3;
	locations[LAB4] = room_LAB4;
	locations[LAB5] = room_LAB5;
	locations[LAB6] = room_LAB6;
	locations[LAB7] = room_LAB7;
	locations[LAB8] = room_LAB8;
	locations[LAB9] = room_LAB9;
	
	//Cavern
	locations[CAVERN1] = room_CAVERN1;
	locations[CAVERN2] = room_CAVERN2;
	locations[CAVERN3] = room_CAVERN3;
	locations[CAVERN4] = room_CAVERN4;
	locations[CAVERN5] = room_CAVERN5;
	locations[CAVERN6] = room_CAVERN6;
	locations[CAVERN7] = room_CAVERN7;
	locations[CAVERN8] = room_CAVERN8;
	locations[CAVERN9] = room_CAVERN9;
	locations[CAVERN10] = room_CAVERN10;
	locations[CAVERN11] = room_CAVERN11;
	
	//Mansion
	locations[OUTSIDE_MANSION] = room_OUTSIDE_MANSION;
	locations[MANSION1] = room_MANSION1;
	locations[MANSION2] = room_MANSION2;
	locations[MANSION3] = room_MANSION3;
	locations[MANSION4] = room_MANSION4;
	locations[MANSION5] = room_MANSION5;
	locations[MANSION6] = room_MANSION6;
	locations[MANSION7] = room_MANSION7;
	locations[MANSION8] = room_MANSION8;
	locations[MANSION9] = room_MANSION9;	
	locations[MANSION10] = room_MANSION10;
	locations[MANSION11] = room_MANSION11;
	locations[MANSION12] = room_MANSION12;
	locations[MANSION13] = room_MANSION13;
	
	//Castle
	locations[GROWN1] = room_GROWN1;
	locations[CASTLE1] = room_CASTLE1;
	locations[CASTLE2] = room_CASTLE2;
	locations[CASTLE3] = room_CASTLE3;
	locations[CASTLE4] = room_CASTLE4;
	locations[CASTLE5] = room_CASTLE5;
	locations[CASTLE6] = room_CASTLE6;
	locations[CASTLE7] = room_CASTLE7;
	locations[CASTLE8] = room_CASTLE8;
	locations[CASTLE9] = room_CASTLE9;
	locations[CASTLE10] = room_CASTLE10;
	locations[CASTLE11] = room_CASTLE11;
	locations[CASTLE12] = room_CASTLE12;
	locations[CASTLE13] = room_CASTLE13;
	
	//Ruins
	locations[OUTSIDE_CASTLE] = room_OUTSIDE_CASTLE;
	locations[BEACH] = room_BEACH;
	locations[TOWN] = room_TOWN;
	locations[SHOP] = room_SHOP;
	locations[FIELD] = room_FIELD;
	locations[TAVERN] = room_TAVERN;
	locations[TEMPLE1] = room_TEMPLE1;
	locations[TEMPLE2] = room_TEMPLE2;
	locations[TEMPLE3] = room_TEMPLE3;
	locations[TEMPLE4] = room_TEMPLE4;
	locations[TEMPLE5] = room_TEMPLE5;
	locations[TEMPLE6] = room_TEMPLE6;
	locations[TEMPLE7] = room_TEMPLE7;
	locations[TEMPLE8] = room_TEMPLE8;
	locations[TEMPLE9] = room_TEMPLE9;
	locations[TEMPLE10] = room_TEMPLE10;
	locations[TEMPLE11] = room_TEMPLE11;
	locations[TEMPLE12] = room_TEMPLE12;
	locations[TEMPLE13] = room_TEMPLE13;
	locations[TEMPLE14] = room_TEMPLE14;
	locations[TEMPLE15] = room_TEMPLE15;
	locations[TEMPLE16] = room_TEMPLE16;
	locations[TEMPLE17] = room_TEMPLE17;
	locations[TEMPLE18] = room_TEMPLE18;
	
	//Epsilon facility
	locations[FACILITY1] = room_FACILITY1;
	locations[FACILITY2] = room_FACILITY2;
	locations[FACILITY3] = room_FACILITY3;
	locations[FACILITY4] = room_FACILITY4;
	locations[FACILITY5] = room_FACILITY5;
	locations[FACILITY6] = room_FACILITY6;
	locations[FACILITY7] = room_FACILITY7;
	locations[FACILITY8] = room_FACILITY8;
	locations[FACILITY9] = room_FACILITY9;
	
	//City
	locations[CITY1] = room_CITY1;
	locations[CITY2] = room_CITY2;
	locations[CITY3] = room_CITY3;
	locations[CITY4] = room_CITY4;
	locations[CITY5] = room_CITY5;
	locations[CITY6] = room_CITY6;
	locations[CITY7] = room_CITY7;
	locations[CITY8] = room_CITY8;
	locations[CITY9] = room_CITY9;
	locations[CITY10] = room_CITY10;
	
	//The Else
	locations[THE_ELSE1] = room_THE_ELSE1;
	locations[THE_ELSE2] = room_THE_ELSE2;
	locations[THE_ELSE3] = room_THE_ELSE3;
	locations[THE_ELSE4] = room_THE_ELSE4;
	locations[THE_ELSE5] = room_THE_ELSE5;
	locations[THE_ELSE6] = room_THE_ELSE6;
	locations[THE_ELSE7] = room_THE_ELSE7;
	locations[THE_ELSE8] = room_THE_ELSE8;
	locations[THE_ELSE9] = room_THE_ELSE9;
	locations[THE_ELSE10] = room_THE_ELSE10;
	locations[THE_ELSE11] = room_THE_ELSE11;
	locations[THE_ELSE12] = room_THE_ELSE12;
	locations[THE_ELSE13] = room_THE_ELSE13;
	locations[THE_ELSE14] = room_THE_ELSE14;
	locations[THE_ELSE15] = room_THE_ELSE15;
	locations[THE_ELSE16] = room_THE_ELSE16;
		
}

#define ifte_room_functions
#endif
