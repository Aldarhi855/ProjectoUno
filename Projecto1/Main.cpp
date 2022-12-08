#include <iostream>
#include <SFML/window.hpp>
#include <SFML/graphics.hpp>
#include <SFML/audio.hpp>
#include "NPC.h"
#include "Game.h"

using namespace sf;
using namespace std;

int main() {

	srand(time(NULL));
	
	Game * play;
	play = new Game;

	play->Juego();

	return 0;
}