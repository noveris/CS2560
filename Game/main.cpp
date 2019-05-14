#include <SFML/Graphics.hpp>
#include <time.h>
const int horz_res = 800;
const int vert_res = 600;
const int square_tile_size = 20;
const int horz_tiles = (horz_res / square_tile_size);
const int vert_tiles = (vert_res / square_tile_size);
const int max_trail_size = 1000;

//Shows who won. If this is ever not -1, stop the game.
//0 - Cycle 1
//1 - Cycle 2
//2 - Draw
//If the two cycles hit each other directly, the game is a draw.
int winner = -1;

//Direction and length of trail 1
int direction1;
int length1 = 1;
//Direction and length of trail 2
int direction2;
int length2 = 1;

struct Cycle {
	int x, y;
	int vert;
}c1[max_trail_size];

struct Cycle2 {
	int x, y;
	int vert;
}c2[max_trail_size];

//Move the cycle based on direction variable
//Leave a cycle trail behind the cycle head
int move_1() {

	c1[length1].x = c1[0].x;
	c1[length1].y = c1[0].y;

	if (direction1 == 0) c1[0].y -= 1;
	if (direction1 == 1) c1[0].y += 1;
	if (direction1 == 2) c1[0].x -= 1;
	if (direction1 == 3) c1[0].x += 1;

	if ((direction1 == 0) || (direction1 == 1)) c1[length1].vert = 1;
	if ((direction1 == 2) || (direction1 == 3)) c1[length1].vert = 0;

	if (length1 < max_trail_size) length1++;

	//Check whether the cycle has crashed into its own trail
	for (int i = 1; i < length1; i++) {
		if ((c1[0].x == c1[i].x) && (c1[0].y == c1[i].y)) winner = 1;
	}
	//Check whether the cycle has crashed into the opponent trail
	for (int i = 1; i < length2; i++) {
		if ((c1[0].x == c2[i].x) && (c1[0].y == c2[i].y)) winner = 1;
	}
	//Check whether the cycle has crashed into the opponent
	if ((c1[0].x == c2[0].x) && (c1[0].y == c2[0].y)) winner = 2;

	//Check whether the cycle has crashed into the wall
	if ((c1[0].x < 0) || (c1[0].x > horz_tiles) || (c1[0].y < 0) || (c1[0].y > vert_tiles)) winner = 1;

	return 0;
}

int move_2() {

	c2[length2].x = c2[0].x;
	c2[length2].y = c2[0].y;

	if (direction2 == 0) c2[0].y -= 1;
	if (direction2 == 1) c2[0].y += 1;
	if (direction2 == 2) c2[0].x -= 1;
	if (direction2 == 3) c2[0].x += 1;

	if ((direction2 == 0) || (direction2 == 1)) c2[length2].vert = 1;
	if ((direction2 == 2) || (direction2 == 3)) c2[length2].vert = 0;

	if (length2 < max_trail_size) length2++;

	//Check whether the cycle has crashed into its own trail
	for (int i = 1; i < length2; i++) {
		if ((c2[0].x == c2[i].x) && (c2[0].y == c2[i].y)) winner = 0;
	}
	//Check whether the cycle has crashed into the opponent trail
	for (int i = 1; i < length1; i++) {
		if ((c2[0].x == c1[i].x) && (c2[0].y == c1[i].y)) winner = 0;
	}
	//Check whether the cycle has crashed into the opponent
	if ((c1[0].x == c2[0].x) && (c1[0].y == c2[0].y)) winner = 2;

	//Check whether the cycle has crashed into the wall
	if ((c2[0].x < 0) || (c2[0].x > horz_tiles) || (c2[0].y < 0) || (c2[0].y > vert_tiles)) winner = 0;

	return 0;
}

int main()
{
	//Main window
	sf::RenderWindow window(sf::VideoMode(horz_res, vert_res), "Tron", sf::Style::Titlebar | sf::Style::Close);

	//Load textures
	sf::Texture trail_blue_vert_texture, trail_blue_horz_texture, trail_red_vert_texture, trail_red_horz_texture, floor_tile_texture, cycle_1_texture, cycle_2_texture;
	sf::Texture victory_1_texture, victory_2_texture, no_victory_texture;
	floor_tile_texture.loadFromFile("images/floor_tile.png");
	trail_blue_vert_texture.loadFromFile("images/cycle_trail_blue_vert.png");
	trail_blue_horz_texture.loadFromFile("images/cycle_trail_blue_horz.png");
	trail_red_vert_texture.loadFromFile("images/cycle_trail_red_vert.png");
	trail_red_horz_texture.loadFromFile("images/cycle_trail_red_horz.png");
	cycle_1_texture.loadFromFile("images/cycle_blue.png");
	cycle_2_texture.loadFromFile("images/cycle_red.png");
	victory_1_texture.loadFromFile("images/victory_1.png");
	victory_2_texture.loadFromFile("images/victory_2.png");
	no_victory_texture.loadFromFile("images/no_victory.png");

	//Load sprites
	sf::Sprite floor_tile(floor_tile_texture);
	sf::Sprite trail_blue_vert(trail_blue_vert_texture);
	sf::Sprite trail_blue_horz(trail_blue_horz_texture);
	sf::Sprite trail_red_vert(trail_red_vert_texture);
	sf::Sprite trail_red_horz(trail_red_horz_texture);
	sf::Sprite cycle_1(cycle_1_texture);
	sf::Sprite cycle_2(cycle_2_texture);
	sf::Sprite victory_1(victory_1_texture);
	sf::Sprite victory_2(victory_2_texture);
	sf::Sprite no_victory(no_victory_texture);

	//Resize sprite textures to match the square size
	floor_tile.setScale(square_tile_size / floor_tile.getLocalBounds().width, square_tile_size / floor_tile.getLocalBounds().height);
	trail_blue_horz.setScale(square_tile_size / trail_blue_horz.getLocalBounds().width, square_tile_size / trail_blue_horz.getLocalBounds().height);
	trail_blue_vert.setScale(square_tile_size / trail_blue_vert.getLocalBounds().width, square_tile_size / trail_blue_vert.getLocalBounds().height);
	trail_red_horz.setScale(square_tile_size / trail_red_horz.getLocalBounds().width, square_tile_size / trail_red_horz.getLocalBounds().height);
	trail_red_vert.setScale(square_tile_size / trail_red_vert.getLocalBounds().width, square_tile_size / trail_red_vert.getLocalBounds().height);

	//Init Sequence
	//Sleep a bit because the window needs to load
	sf::sleep(sf::milliseconds(100));
	//Texture for init sequence cycle rider
	sf::Texture init_cycle_drawing_texture;
	init_cycle_drawing_texture.loadFromFile("images/init_cycle_drawing.png");
	//Sprite for cycle rider
	sf::Sprite init_cycle_drawing(init_cycle_drawing_texture);
	sf::Texture main_logo_texture;
	main_logo_texture.loadFromFile("images/tron_logo.png");
	sf::Sprite main_logo(main_logo_texture);
	main_logo.setPosition((horz_res / 2) - 200, 25);
	bool show_logo = true;
	//Draw the cycle rider crossing the screen
	for (int i = 0; i < horz_res; i++) {
		window.clear();
		init_cycle_drawing.setPosition(i, (vert_res / 2) - 100);
		window.draw(init_cycle_drawing);
		if (show_logo) {
			show_logo = false;
			window.draw(main_logo);
		}
		else {
			show_logo = true;
		}

		window.display();
		sf::sleep(sf::milliseconds(5));
	}

	window.clear();

	//Main game loop
	//Set initial cycle positions
	c1[0].y = vert_tiles / 2;
	c1[0].x = (horz_tiles / 2) - 5;
	c2[0].y = vert_tiles / 2;
	c2[0].x = (horz_tiles / 2) + 5;

	//Set up timer and timer step
	sf::Clock clock;
	float timer = 0.0f;
	float delay = 0.1f;

	int vic_drawn = 0;
	while (window.isOpen()) {
		if (winner == -1) {
			float time = clock.getElapsedTime().asSeconds();
			clock.restart();
			timer += time;

			//Set up event listener
			sf::Event e;

			//Listen to see if the game has been closed
			while (window.pollEvent(e)) {
				if (e.type == sf::Event::Closed) {
					//Close the window if exit key has been clicked.
					window.close();
				}
			}

			//Player 1 controls
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction1 = 0; //Up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction1 = 1; //Down
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction1 = 2; //Left
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction1 = 3; //Right

			//Player 2 controls
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) direction2 = 0; //Up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) direction2 = 1; //Down
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) direction2 = 2; //Left
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction2 = 3; //Right

			//If we have crossed the time delay, update the positions of the cycles
			if (timer > delay) {
				timer = 0;
				move_1();
				move_2();
			}

			//Clear old frame
			window.clear();

			//Draw the floor
			for (int i = 0; i < horz_tiles; i++) {
				for (int j = 0; j < vert_tiles; j++) {
					floor_tile.setPosition(i * square_tile_size, j * square_tile_size);
					window.draw(floor_tile);
				}
			}

			//Draw cycles and trails
			//Cycle 1
			for (int i = 0; i < length1; i++) {
				//If i = 0; draw the head (cycle)
				if (i == 0) {
					//Draw the cycle
					cycle_1.setPosition(c1[i].x * square_tile_size, c1[i].y * square_tile_size);
					window.draw(cycle_1);
				}
				else {
					//The tile is a trail
					//Draw appropriate vert or horz trail
					if (c1[i].vert == 1) {
						trail_blue_vert.setPosition(c1[i].x * square_tile_size, c1[i].y * square_tile_size);
						window.draw(trail_blue_vert);
					}
					else {
						trail_blue_horz.setPosition(c1[i].x * square_tile_size, c1[i].y * square_tile_size);
						window.draw(trail_blue_horz);
					}
				}
			}

			//Cycle 2
			for (int i = 0; i < length2; i++) {
				//If i = 0; draw the head (cycle)
				if (i == 0) {
					//Draw the cycle
					cycle_2.setPosition(c2[i].x * square_tile_size, c2[i].y * square_tile_size);
					window.draw(cycle_2);
				}
				else {
					//The tile is a trail
					//Draw appropriate vert or horz trail
					if (c2[i].vert == 1) {
						trail_red_vert.setPosition(c2[i].x * square_tile_size, c2[i].y * square_tile_size);
						window.draw(trail_red_vert);
					}
					else {
						trail_red_horz.setPosition(c2[i].x * square_tile_size, c2[i].y * square_tile_size);
						window.draw(trail_red_horz);
					}
				}
			}

			//Show the window.
			window.display();
		}
		else {
			delay = 2.0f;
			float time = clock.getElapsedTime().asSeconds();
			clock.restart();
			timer += time;
			if (timer > delay) {
				window.close();
				return 0;
			}

			if (winner == 0) {
				window.clear();
				victory_1.setPosition(0, 0);
				window.draw(victory_1);
				window.display();
			}
			else if (winner == 1) {
				window.clear();
				victory_2.setPosition(0, 0);
				window.draw(victory_2);
				window.display();
			}
			else if (winner == 2) {
				window.clear();
				no_victory.setPosition(0, 0);
				window.draw(no_victory);
				window.display();
			}
		}
	}
	return 0;
}