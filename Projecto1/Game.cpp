#include <iostream>
#include <SFML/window.hpp>
#include <SFML/graphics.hpp>
#include <SFML/audio.hpp>
#include "NPC.h"
#include "Game.h"

using namespace sf;
using namespace std;

Game::Game()
{
	enemigos_abatidos = new int(0);
	inocentes_abatidos = new int(0);
	puntos = new int(0);
	puntaje = new Text;
	num_puntos = new Text;
	vidas = new Text;
	num_vidas = new Text;
	aviso = new Text;
	game_over = new Text;
	fuente = new Font;
	App = new RenderWindow(VideoMode(1000, 770, 32), "Ventanita");
	evt = new Event;
	reloj3 = new Clock;

	bufferGO.loadFromFile("Audio/game over.wav");
	GO.setBuffer(bufferGO);

	musica.openFromFile("Audio/musica.ogg");
	musica.setVolume(20);

	App->setMouseCursorVisible(false);

	fuente->loadFromFile("Fuentes/SquaredanceFontV1-Regular.ttf");

	puntaje->setFont(*fuente);
	puntaje->setString("Puntos ");
	puntaje->setCharacterSize(30);
	puntaje->setPosition(80, 660);

	vidas->setFont(*fuente);
	vidas->setString("Vidas ");
	vidas->setCharacterSize(30);
	vidas->setPosition(750, 660);

	aviso->setFont(*fuente);
	aviso->setString("Pulsa Esc para salir");
	aviso->setOrigin(aviso->getGlobalBounds().width / 2, aviso->getGlobalBounds().height / 2);
	//widht = ancho y height = alto
	aviso->setCharacterSize(30);
	aviso->setPosition((float)App->getSize().x/2, (float)App->getSize().y / 2);

	game_over->setFont(*fuente);
	game_over->setString("Game Over");
	game_over->setOrigin(game_over->getGlobalBounds().width / 2, game_over->getGlobalBounds().height / 2);
	game_over->setCharacterSize(30);
	game_over->setPosition(500, 250);

	num_puntos->setFont(*fuente);
	num_puntos->setCharacterSize(30);
	num_puntos->setPosition(210, 660);

	num_vidas->setFont(*fuente);
	num_vidas->setCharacterSize(30);
	num_vidas->setPosition(860, 660);

	cartelt.loadFromFile("Imagenes/Cartel.png");
	cartels.setTexture(cartelt);
	cartels.setScale((float)8, (float)8);
	cartels.setOrigin(cartels.getTexture()->getSize().x / 2.f, cartels.getTexture()->getSize().y / 2.f);
	cartels.setPosition(500, 317);

	//para ponerle un color: aviso.setColor(Color::Red);

	cursort.loadFromFile("Imagenes/mira.png");
	cursors.setTexture(cursort);
	cursors.setScale((float)0.3, (float)0.3);
	cursors.setPosition(0, 0);
	cursors.setOrigin(cursors.getTexture()->getSize().x / 2.f, cursors.getTexture()->getSize().y / 2.f);
	//En caso de que la imagen se vea pixelada, utilizar este código:
	cursort.setSmooth(true);

	fondot.loadFromFile("Imagenes/casa.png");
	fondos.setTexture(fondot);
	fondos.setScale((float)3.33, (float)4.1);
};

void Game::Dificultad()
{
	if (reloj3->getElapsedTime().asSeconds() > tiempo3)
	{
		tiempo2 -= (float)0.1;
		tiempo1 -= (float)0.1;
		reloj3->restart();
	}
}

void Game::GameOver()
{
	if (*vida == 0)
	{
		num_puntos->setCharacterSize(40);
		puntaje->setCharacterSize(40);
		num_puntos->setPosition(560, 317);
		puntaje->setPosition(370, 317);
		App->draw(cartels);
		App->draw(*game_over);
		App->draw(*aviso);
		App->draw(*puntaje);
		App->draw(*num_puntos);
		musica.setLoop(false);
		musica.stop();
		GO.play();
		tiempo1 = 1000000;
	}
};

void Game::Juego()
{	
	App->clear();

	reloj2->restart();

	musica.play();
	musica.setLoop(true);

	while (App->isOpen())
	{
		App->clear();

		while (App->pollEvent(*evt))
		{
			switch (evt->type)
			{
			case Event::Closed:
				App->close();
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					exit(1);
				}
			case Event::MouseMoved:
				cursors.setPosition((float)evt->mouseMove.x, (float)evt->mouseMove.y);
			case Event::MouseButtonPressed:

				FloatRect recta(cursors.getPosition(), (Vector2f)cursors.getTexture()->getSize());

				if (Mouse::isButtonPressed(Mouse::Left))
				{
					disparo.play();
					if (enemigos.getGlobalBounds().intersects(recta))
					{
						spawnE = false;
						enemigos.setPosition(1, 1);
						sonidoE.play();
						enemigos_abatidos++;
						*puntos += 10;
					}
					else if (inocentes.getGlobalBounds().intersects(recta))
					{
						spawnI = false;
						inocentes.setPosition(1, 1);
						sonidoI.play();
						inocentes_abatidos++;
						*puntos -= 10;
						*vida -= 1;
					}
				}
			}
		}
		num_vidas->setString(to_string(*vida));
		num_puntos->setString(to_string(*puntos));

		Spawn();
		Daño();
		Despawn();
		Dificultad();

		if (spawnE == true)
		{
			App->draw(enemigos);
		}
		if(spawnI == true)
		{
		App->draw(inocentes); 
		}
		App->draw(fondos);
		App->draw(cursors);
		App->draw(*vidas);
		App->draw(*num_vidas);
		App->draw(*puntaje);
		App->draw(*num_puntos);

		GameOver();

		App->display();
	}
};