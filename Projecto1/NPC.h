#pragma once
#include <iostream>
#include <SFML/window.hpp>
#include <SFML/graphics.hpp>
#include <SFML/audio.hpp>

using namespace sf;
using namespace std;

class NPC
{
protected:
	int* random1, * random2, *vida;
	Texture enemigo, inocente;
	Sprite enemigos, inocentes;
	Clock* reloj1,* reloj2;
	float tiempo1 = 3, tiempo2 = 2;
	bool spawnE = false, spawnI = false;
	SoundBuffer bufferD, muerteE, muerteI;
	Sound disparo, sonidoE, sonidoI;
public:
	NPC();
	void Daño();
	void Pos();
	void Spawn();
	void Despawn();
};