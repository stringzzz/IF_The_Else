/*
    IF: The Else (ifte_consts_and_functions.h Header File) Interactive fiction game written in C
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
	Full version (Constants and Functions Header)
	Start date: 08-02-2024
	Complete date: 08-24-2024
	By stringzzz, Ghostwarez Co.
*/

#ifndef ifte_consts_and_functions

#define MAX_LOCATIONS	121
//locations INTRO
#define CELL	0
#define OUTSIDE_CELL	1
#define TREASURE_ROOM	2
//locations FOREST
#define FOREST1	3
#define FOREST2	4
#define FOREST3	5
#define FOREST4	6
#define FOREST5	7
#define FOREST6	8
//locations Witch's Hut
#define OUTSIDE_HUT	9
#define WITCH_HUT	10
#define SHRUNK_HUT	11
#define SHRUNK_CAT	12
#define SHRUNK_MOUSE	13
//locations Labrynth
#define LAB1	14
#define LAB2	15
#define LAB3	16
#define LAB4	17
#define LAB5	18
#define LAB6	19
#define LAB7	20
#define LAB8	21
#define LAB9	22
//locations cavern
#define CAVERN1	23
#define CAVERN2	24
#define CAVERN3	25
#define CAVERN4	26
#define CAVERN5	27
#define CAVERN6	28
#define CAVERN7	29
#define CAVERN8	30
#define CAVERN9	31
#define CAVERN10	32
#define CAVERN11	33
//locations mansion
#define OUTSIDE_MANSION	34
#define MANSION1	35
#define MANSION2	36
#define MANSION3	37
#define MANSION4	38
#define MANSION5	39
#define MANSION6	40
#define MANSION7	41
#define MANSION8	42
#define MANSION9	43	
#define MANSION10	44
#define MANSION11	45
#define MANSION12	46
#define MANSION13	47
//locations castle
#define GROWN1	48
#define CASTLE1	49
#define CASTLE2	50
#define CASTLE3	51
#define CASTLE4	52
#define CASTLE5	53
#define CASTLE6	54
#define CASTLE7	55
#define CASTLE8	56
#define CASTLE9	57
#define CASTLE10	58
#define CASTLE11	59
#define CASTLE12	60
#define CASTLE13	61
//locations temple
#define OUTSIDE_CASTLE	62
#define BEACH	63
#define TOWN	64
#define SHOP	65
#define FIELD	66
#define TAVERN	67
#define TEMPLE1	68
#define TEMPLE2	69
#define TEMPLE3	70
#define TEMPLE4	71
#define TEMPLE5	72
#define TEMPLE6	73
#define TEMPLE7	74
#define TEMPLE8	75
#define TEMPLE9	76
#define TEMPLE10	77
#define TEMPLE11	78
#define TEMPLE12	79
#define TEMPLE13	80
#define TEMPLE14	81
#define TEMPLE15	82
#define TEMPLE16	83
#define TEMPLE17	84
#define TEMPLE18	85
//locations epsilon facility
#define FACILITY1	86
#define FACILITY2	87
#define FACILITY3	88
#define FACILITY4	89
#define FACILITY5	90
#define FACILITY6	91
#define FACILITY7	92
#define FACILITY8	93
#define FACILITY9	94
//locations city
#define CITY1	95
#define CITY2	96
#define CITY3	97
#define CITY4	98
#define CITY5	99
#define CITY6	100
#define CITY7	101
#define CITY8	102
#define CITY9	103
#define CITY10	104
//locations the else
#define THE_ELSE1	105
#define THE_ELSE2	106
#define THE_ELSE3	107
#define THE_ELSE4	108
#define THE_ELSE5	109
#define THE_ELSE6	110
#define THE_ELSE7	111
#define THE_ELSE8	112
#define THE_ELSE9	113
#define THE_ELSE10	114
#define THE_ELSE11	115
#define THE_ELSE12	116
#define THE_ELSE13	117
#define THE_ELSE14	118
#define THE_ELSE15	119
#define THE_ELSE16	120

//once-only actions
#define MAX_ACTIONS	187
//INTRO
#define INTRO	0
#define GET_KEY	1
#define UNLOCK_CELL	2
#define BATS_OUT	3
#define MICE_OUT	4
#define GET_TORCH	5
#define LIT_TORCH	6
//FOREST
#define FOREST_INTRO	7
#define BUSH1	8
#define GET_LONG_STICK	9
#define GET_PURPLE_MUSHROOM	10
#define GET_STICK	11
#define GET_RED_MUSHROOM	12
#define GET_AMULET	13
#define BUSH2	14
#define USE_AMULET	15
#define FED_CREATURE	16
#define GIVE_PURPLE_MUSHROOM	17
#define GIVE_STICK	18
#define MOUSE_SPOKE	19
//Labrynth
#define LEFT_PEDESTAL_SET	20
#define MIDDLE_PEDESTAL_SET	21
#define RIGHT_PEDESTAL_SET	22
#define RED_ORB_LEFT	23
#define RED_ORB_MIDDLE	24
#define RED_ORB_RIGHT	25
#define BLUE_ORB_LEFT	26
#define BLUE_ORB_MIDDLE	27
#define BLUE_ORB_RIGHT	28
#define GREEN_ORB_LEFT	29
#define GREEN_ORB_MIDDLE	30
#define GREEN_ORB_RIGHT	31
#define GET_RED_ORB	32
#define GET_BLUE_ORB	33
#define GET_GREEN_ORB	34
#define ORB_PUZZLE_SOLVED	35
//Cavern
#define CAVERN_INTRO	36
#define CHECKED_MUSHROOM1	37
#define GET_RUBY	38
#define CHECKED_MUSHROOM2	39
#define GET_SAPPHIRE	40
#define CHECKED_MUSHROOM3	41
#define GET_EMERALD	42
#define CHECKED_MUSHROOM4	43
#define GIVE_RUBY	44
#define GIVE_SAPPHIRE	45
#define GIVE_EMERALD	46
#define GET_ICE_WAND	47
#define SEEN_FLINT	48
#define GET_FLINT	49
#define USE_ICE_WAND_LAKE	50
#define GET_KEY_CAVERN	51
#define GET_BOMB	52
#define USE_ICE_WAND_LAVA	53
#define USE_BOMB	54
//Mansion
#define CHECK_PORTRAIT1	55
#define PORTRAIT1_ACTIVE	56
#define CHECK_PORTRAIT2	57
#define PORTRAIT2_ACTIVE	58
#define CHECK_PORTRAIT3	59
#define PORTRAIT3_ACTIVE	60
#define CHECK_PORTRAIT4	61
#define PORTRAIT4_ACTIVE	62
#define CHECK_PORTRAIT5	63
#define PORTRAIT5_ACTIVE	64
#define GET_RED_BOOK	65
#define GET_BLUE_BOOK	66
#define GET_GREEN_BOOK	67
#define GET_BLACK_BOOK	68
#define GET_WHITE_BOOK	69
#define LIT_CANDLES	70
#define GET_STUFFED_BEAR	71
#define PLACE_STUFFED_BEAR	72
#define SEEN_GHOST1	73
#define SEEN_GHOST2	74
#define DESK_MOVED	75
#define PLACE_RED_BOOK	76
#define PLACE_BLUE_BOOK	77
#define PLACE_GREEN_BOOK	78
#define PLACE_BLACK_BOOK	79
#define PLACE_WHITE_BOOK	80
#define ALL_BOOKS_PLACED	81
//Castle
#define PRINCE_MURDERED	82
#define GET_VIAL	83
#define GIVE_VIAL	84
#define SEEN_JESTER1	85
#define ALCHEMIST_MURDERED	86
#define OPEN_PASSAGEWAY	87
#define SEEN_PASSAGEWAY	88
#define GET_BELL	89
#define SEEN_JESTER2	90
#define GIVE_BELL	91
#define HEARD_CONVERSATION	92
#define MURDER_SOLVED	93
//Temple
#define GET_HERB	94
#define GET_SPELL_BOOK	95
#define GIVE_SPELL_BOOK	96
#define SEEN_SHARKS	97
#define TEMPLE_ENTRANCE_CENTER	98
#define TEMPLE_ENTRANCE_NORTH	99
#define TEMPLE_ENTRANCE_EAST	100
#define TEMPLE_ENTRANCE_WEST	101
#define TEMPLE_PUZZLE1_SOLVED	102
#define TEMPLE_PUZZLE1_BLOCK0	103
#define TEMPLE_PUZZLE1_BLOCK1	104
#define TEMPLE_PUZZLE1_BLOCK2	105
#define TEMPLE_PUZZLE1_BLOCK3	106
#define TEMPLE_PUZZLE1_BLOCK4	107
#define TEMPLE_PUZZLE1_BLOCK5	108
#define TEMPLE_PUZZLE1_BLOCK6	109
#define TEMPLE_PUZZLE1_BLOCK7	110
#define TEMPLE_PUZZLE1_BLOCK8	111
#define TEMPLE_PUZZLE2_SOLVED	112
#define TEMPLE_PUZZLE2_LEFT1	113
#define TEMPLE_PUZZLE2_LEFT2	114
#define TEMPLE_PUZZLE2_LEFT3	115
#define TEMPLE_PUZZLE2_LEFT4	116
#define TEMPLE_PUZZLE2_MIDDLE1	117
#define TEMPLE_PUZZLE2_MIDDLE2	118
#define TEMPLE_PUZZLE2_MIDDLE3	119
#define TEMPLE_PUZZLE2_MIDDLE4	120
#define TEMPLE_PUZZLE2_RIGHT1	121
#define TEMPLE_PUZZLE2_RIGHT2	122
#define TEMPLE_PUZZLE2_RIGHT3	123
#define TEMPLE_PUZZLE2_RIGHT4	124
#define GET_CIRCLE_STONE	125
#define GET_SQUARE_STONE	126
#define PLACE_CIRCLE_STONE	127
#define PLACE_SQUARE_STONE	128
#define TEMPLE_WATER_DRAINED	129
#define TEMPLE_PUZZLE3_DOOR_A	130
#define TEMPLE_PUZZLE3_DOOR_B	131
#define TEMPLE_PUZZLE3_DOOR_C	132
#define TEMPLE_PUZZLE3_DOOR_D	133
#define TEMPLE_PUZZLE4_SOLVED	134
#define GET_BLUE_GEM	135
#define PLACE_BLUE_GEM	136
#define PUSH_LEFT_STATUE	137
#define PUSH_RIGHT_STATUE	138
//epsilon facility
#define FACILITY_INTRO	139
#define GET_KEY_CARD_A	140
#define GET_KEY_CARD_B	141
#define PASSWORD_CLEARED	142
//city
#define GET_CROWBAR	143
#define USE_CROWBAR1	144
#define USE_CROWBAR2	145
#define GET_RED_MUSHROOM2	146
#define GET_STICK2	147
#define GET_STONE_PIECE1	148
#define GET_STONE_PIECE2	149
#define GET_STONE_PIECE3	150
#define GET_STONE_PIECE4	151
#define GET_STONE_PIECE5	152
#define PLACE_STONE_PIECES	153
//The Else
#define THE_ELSE_INTRO	154
#define FLIPPED	155
#define BLOCK_MOVED	156
#define SIDEWAYS	157
#define EYES_CLOSED	158
#define DOOR_SHUT1	159
#define SYMBOL_PUSHED	160
#define QUESTION_ANSWERED	161
#define PASSWORD_CLEARED2	162
#define BUTTON_A_LIT	163
#define BUTTON_B_LIT	164
#define BUTTON_C_LIT	165
#define BUTTON_D_LIT	166
#define BUTTON_E_LIT	167
#define BUTTON_F_LIT	168
#define BUTTON_G_LIT	169
#define BUTTON_H_LIT	170
#define BUTTON_I_LIT	171
#define BUTTON_PUZZLE1_SOLVED	172
#define BUTTON_CEIL_LEFT_LIT	173
#define BUTTON_CEIL_RIGHT_LIT	174
#define BUTTON_FLOOR_LEFT_LIT	175
#define BUTTON_FLOOR_RIGHT_LIT	176
#define BUTTON_PUZZLE2_SOLVED	177
#define CRYPTO_PUZZLE_SOLVED	178
#define ELSE_GET_RED_ORB	179
#define ELSE_GET_ORANGE_ORB	180
#define ELSE_GET_YELLOW_ORB	181
#define ELSE_GET_GREEN_ORB	182
#define ELSE_GET_BLUE_ORB	183
#define ELSE_GET_INDIGO_ORB	184
#define ELSE_GET_VIOLET_ORB	185
#define FINAL_PUZZLE_SOLVED	186

//Other constants
#define TOTAL_WORDS	250

//For final room
#define EMPTY	0
#define RED	1
#define ORANGE	2
#define YELLOW	3
#define GREEN	4
#define BLUE	5
#define INDIGO	6
#define VIOLET	7

#define FIRST	1
#define SECOND	2
#define THIRD	3
#define FOURTH	4
#define FIFTH	5
#define SIXTH	6
#define SEVENTH	7

void lowercase(char * str) {
	for (int i = 0; i < strlen(str); i++) {
		str[i] = tolower(str[i]);
	}
}

int getChoiceAndSave(char chosen_action[], char name[], int current_location, bool actions[], int coins) {
	printf("\nEnter an action: ");
	scanf(" %[^\n]%*c", chosen_action);
	system("clear");
	lowercase(chosen_action);
	printf("Action: %s\n", chosen_action);
	
	if (strcmp(chosen_action, "save game") == 0) {
		unsigned char save_file[128];
		strcpy(save_file, name);
		strcat(save_file, ".txt");
		FILE* save_ptr;
		save_ptr = fopen(save_file, "w");
		if (save_ptr == NULL) {
			printf("Couldn't create file for saving!\n");
			exit(1);
		}
		fprintf(save_ptr, "%i\n%i\n", current_location, coins);
		for (int i = 0; i < MAX_ACTIONS; i++) {
			fprintf(save_ptr, "%i\n", actions[i]);
		}
		fclose(save_ptr);		
		printf("Game saved, continue playing? (y/n): ");
		char yn[4];
		scanf("%[^\n]%*c", yn);
		if (strcmp(yn, "y") != 0) {
			return -1;
		}
		return 0;
	}
	return 1;

} 

void loadGame(char name[], int *current_location, bool actions[], int *coins) {
	unsigned char load_file[128];
	strcpy(load_file, name);
	strcat(load_file, ".txt");
	FILE* load_ptr;
	load_ptr = fopen(load_file, "r");
	if (load_ptr == NULL) {
		printf("Save file doesn't exist under that name!\n");
		exit(1);
	}
	fscanf(load_ptr, "%i", current_location);
	fscanf(load_ptr, "%i", coins);
	for (int i = 0; i < MAX_ACTIONS; i++) {
		int temp;
		fscanf(load_ptr, " %i", &temp);
		actions[i] = (bool) temp;
	}
	fclose(load_ptr);
	
	//Reset puzzle 1 block back to center
	actions[TEMPLE_PUZZLE1_BLOCK4] = 1;
	//There is probably a better way to do this...
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
}

#define ifte_consts_and_functions
#endif
