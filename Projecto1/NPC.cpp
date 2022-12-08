#include <iostream>
#include <SFML/window.hpp>
#include <SFML/graphics.hpp>
#include <SFML/audio.hpp>
#include "NPC.h"

using namespace sf;
using namespace std;

NPC::NPC()
{
	random1 = new int(0);
	random2 = new int(0);
	vida = new int(3);
	reloj1 = new Clock;
	reloj2 = new Clock;

	bufferD.loadFromFile("Audio/disparo.wav");
	disparo.setBuffer(bufferD);

	muerteE.loadFromFile("Audio/enemigo.wav");
	sonidoE.setBuffer(muerteE);
	sonidoE.setVolume(20);

	muerteI.loadFromFile("Audio/inocente.wav");
	sonidoI.setBuffer(muerteI);
	sonidoI.setVolume(20);

	enemigo.loadFromFile("Imagenes/enemigo.png");
	inocente.loadFromFile("Imagenes/inocente.png");

	enemigos.setTexture(enemigo);
	inocentes.setTexture(inocente);

	enemigos.setScale(4, 4);
	inocentes.setScale(4, 4);

	enemigos.setOrigin(enemigos.getTexture()->getSize().x / 2.f, enemigos.getTexture()->getSize().y / 2.f);
	inocentes.setOrigin(inocentes.getTexture()->getSize().x / 2.f, inocentes.getTexture()->getSize().y / 2.f);

	//Para rotar una imagen: sprite.setRotation(sprite.getRotation() + 0.1);
}

void NPC::Daño()
{
	if (reloj2->getElapsedTime().asSeconds() > tiempo2 && spawnE == true)
	{
		*vida -= 1;
	}
};

void NPC::Pos()
{
	switch (*random1)
	{
	case 1:
		if (*random2 > 15)
		{
			spawnE = true;
			enemigos.setPosition(125, 155);
		}
		else
		{
			spawnI = true;
			inocentes.setPosition(132, 155);
		}
		break;
	case 2:

		if (*random2 > 15)
		{
			spawnE = true;
			enemigos.setPosition(125, 422);
		}
		else
		{
			spawnI = true;
			inocentes.setPosition(132, 422);
		}
		break;
	case 3:
		if (*random2 > 15)
		{
			spawnE = true;
			enemigos.setPosition(505, 160);
		}
		else
		{
			spawnI = true;
			inocentes.setPosition(507, 155);
		}
		break;
	case 4:
		if (*random2 > 15)
		{
			spawnE = true;
			enemigos.setPosition(505, 418);
		}
		else
		{
			spawnI = true;
			inocentes.setPosition(504, 423);
		}
		break;
	case 5:
		if (*random2 > 15)
		{
			spawnE = true;
			enemigos.setPosition(870, 155);
		}
		else
		{
			spawnI = true;
			inocentes.setPosition(877, 155);
		}
		break;
	case 6:
		if (*random2 > 15)
		{
			spawnE = true;
			enemigos.setPosition(870, 422);
		}
		else
		{
			spawnI = true;
			inocentes.setPosition(877, 422);
		}
		break;
	}
};

void NPC::Spawn()
{
	if (reloj1->getElapsedTime().asSeconds() > tiempo1)
	{
		reloj1->restart();
		reloj2->restart();
		*random1 = rand() % 6 + 1;
		*random2 = rand() % 100 + 1;
		Pos();
	}
}

void NPC::Despawn()
{
	if (reloj1->getElapsedTime().asSeconds() > tiempo2)
	{
		spawnE = false;
		spawnI = false;
	}
}