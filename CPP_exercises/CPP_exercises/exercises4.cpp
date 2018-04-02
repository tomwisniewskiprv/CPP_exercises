#include <iostream>
#include "exercises4.h"
using namespace std;

void display_maps(int *** maps, int MAP_SIZE);

struct position {
	int row = 0;
	int col = 0;
};

struct player {
	int ships = 4;
	int shots = 0;			// actual shots
	int random_shots = 0;	// random generator counter , for statistics
};

// -------------------------------------------------------------------
// Simulates player's behaviour (AI)
// 0 - empty field
// 1 - ship
// 2 - already shooted here
// -------------------------------------------------------------------
int shoot(player &current_player, player &enemy_player, int** &enemy_map, int map_size) {

	while (1) {

		int col = random(map_size);
		int row = random(map_size);

		current_player.random_shots += 1;

		if (enemy_map[row][col] != 2) { // shoot somewhere else

			current_player.shots += 1;

			if (enemy_map[row][col] == 1) { // ship is here
				enemy_map[row][col] = 0;    // sunk it
				enemy_player.ships -= 1;    // decrease ships counter

				if (enemy_player.ships == 0)// any ships left ?
					return 0;				// stop the loop
				else
					return 1;				// keep going
			}
			else if (enemy_map[row][col] == 0)	// it's empty 
				enemy_map[row][col] = 2;		// mark this field
			
			return 1;
		}
	}
}


// -------------------------------------------------------------------
// Prepare battlefield with random ships
// -------------------------------------------------------------------
int ** prepare_map(int player, int MAP_SIZE, int MAX_SHIPS) {

	int ** map = new int*[MAP_SIZE];

	for (int i = 0; i < MAP_SIZE; i++) {
		map[i] = new int[MAP_SIZE];
		for (int j = 0; j < MAP_SIZE; j++)
			map[i][j] = 0;
	}

	int unique_ships = 0;
	position *ships = new position[MAX_SHIPS];
	position tmp;
	bool is_uniqe;

	while (unique_ships != 4) {

		is_uniqe = true;
		tmp.col = random(MAP_SIZE);
		tmp.row = random(MAP_SIZE);

		for (int i = 0; i < MAX_SHIPS; i++) {
			if (ships[i].col == tmp.col && ships[i].row == tmp.row) {
				is_uniqe = false;
				break;
			}
		}
		if (is_uniqe) {
			map[tmp.row][tmp.col] = 1;
			unique_ships++;
		}
	}

	delete[] ships;
	return map;
}

// -------------------------------------------------------------------
// Release memory 
// -------------------------------------------------------------------
void clear_map(int** &map, int MAP_SIZE) {

	for (int i = 0; i < MAP_SIZE; i++)
		delete[] map[i];
	delete[] map;
}


// -------------------------------------------------------------------
// Display maps
// -------------------------------------------------------------------
void display_maps(int *** maps, int MAP_SIZE) {

	cout << "\n-------------------";

	for (int m = 0; m < 2; m++) {
		for (int i = 0; i < MAP_SIZE; i++) {
			cout << endl;
			for (int j = 0; j < MAP_SIZE; j++)
				cout << maps[m][i][j] << " ";
		}
		cout << "\n-------------------";
	}
	cout << endl;
}


// -------------------------------------------------------------------
// Gameplay loop. Main logic.
// -------------------------------------------------------------------
void gameplay_loop() {

	const int PLAYERS = 2;		// two players
	const int MAX_SHIPS = 4;	// four ships each
	const int MAP_SIZE = 10;	// 10 x 10

	player players[PLAYERS];
	int *** maps = new int**[PLAYERS];

	for (int i = 0; i < PLAYERS; i++)
		maps[i] = prepare_map(i, MAP_SIZE, MAX_SHIPS);

	// AI will shoot each other until all ships are sunk
	bool current_player;
	int main_loop = 1;			// if =/= 0 keep playing

	if (random(100) > 50)		// who goes first 
		current_player = 0;
	else current_player = 1;

	display_maps(maps, MAP_SIZE); // before game

	//Player shoots to random positon. After each shoot players are swaped.
	while (main_loop) {
		// player turn
		main_loop = shoot(players[current_player], players[!current_player], maps[!current_player] , MAP_SIZE);
		current_player = !current_player; //switch current player
	}

	display_maps(maps, MAP_SIZE); // after game

	if (players[0].ships > players[1].ships) 
		current_player = 0;
	else
		current_player = 1;

	cout << "STATISTICS: " << endl;
	cout << "Winner    : " << (current_player?"Player 2":"Player 1") << endl;
	cout << "Shots     : " << players[current_player].shots << endl;
	cout << "RNG tries : " << players[current_player].random_shots << endl;
	cout << "Player 1  : ships left: " << players[0].ships << endl;
	cout << "Player 2  : ships left: " << players[1].ships << endl;

	// Clean up
	for (int i = 0; i < PLAYERS; i++)
		clear_map(maps[i], MAP_SIZE);

	delete[] maps;
}


// -------------------------------------------------------------------
// Exectue this function to run game simulation.
// -------------------------------------------------------------------
void battleships() {
	gameplay_loop();
}
