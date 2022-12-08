#pragma once
#include <iostream>
#include <SFML/window.hpp>
#include <SFML/graphics.hpp>
#include <SFML/audio.hpp>

using namespace sf;
using namespace std;

class Game :public NPC
{
protected:
	int* enemigos_abatidos, * inocentes_abatidos, * puntos;
	Texture fondot, cursort, cartelt;
	Sprite fondos, cursors, cartels;
	Text* puntaje, * num_puntos, * vidas, * num_vidas, * aviso, * game_over;
	Font* fuente;
	Clock* reloj3;
	float tiempo3 = 10;
	SoundBuffer bufferGO;
	Sound GO;
	Music musica;

	//Creamos la ventana
	RenderWindow* App;

	//Para poder modificar la ventana a voluntad
	Event* evt;

public:
	Game();
	void Dificultad();
	void GameOver();
	void Juego();
};