#include <iostream>
#include <SFML/window.hpp>
#include <SFML/graphics.hpp>

using namespace sf;

Texture enemigot,inocentet , fondot, cursort, platat;
Sprite enemigos, inocentes, fondos, cursors, platas;

int main() {

	//Cargamos la textura del archivo
	enemigot.loadFromFile("Imagenes/enemigo.png");
	inocentet.loadFromFile("Imagenes/inocente.png");
	fondot.loadFromFile("Imagenes/fondo.jpg");
	platat.loadFromFile("Imagenes/plataforma.jpg");
	cursort.loadFromFile("Imagenes/mira.png");
	//Configuramos el material del sprite
	platas.setTexture(platat);
	fondos.setTexture(fondot);
	enemigos.setTexture(enemigot);
	inocentes.setTexture(inocentet);
	cursors.setTexture(cursort);
	//Le establecemos el tamaño
	platas.setScale(0.2,0.2);
	enemigos.setScale(5,5);
	cursors.setScale(0.3, 0.3);
	//Le damos una posición
	platas.setPosition(0, 550);
	enemigos.setPosition(700, 100);
	cursors.setPosition(0, 0);
	//En caso de que la imagen se vea pixelada, utilizar este código
	cursort.setSmooth(true);
	//Para rotar una imagen primero le seteamos el origen de rotación en el centro, pq por default está arriba a la izquierda
	enemigos.setOrigin(enemigos.getTexture()->getSize().x / 2.f, enemigos.getTexture()->getSize().y / 2.f);
	inocentes.setOrigin(inocentes.getTexture()->getSize().x / 2.f, inocentes.getTexture()->getSize().y / 2.f);
	cursors.setOrigin(cursors.getTexture()->getSize().x / 2.f, cursors.getTexture()->getSize().y / 2.f);
	//Con el getTexture()->getSize().x/2.0 se consigue se consigue la mitad del ancho de la imagen, con el .y/2, la mitad del alto
	//Para rotar una imagen: sprite.setRotation(sprite.getRotation() + 0.1);

	//Creamos la ventana
	sf::RenderWindow App(sf::VideoMode(1000, 770, 32),"Ventanita");

	//Ocultamos el cursor del sistema
	App.setMouseCursorVisible(false);

	//Loop principal
	while (App.isOpen())
	{
		//Para poder modificar la ventana a voluntad
		Event evt; 
		while (App.pollEvent(evt))
		{
			switch (evt.type)
			{
				case Event::Closed:
					App.close();
				case sf::Event::MouseMoved:
					//Actualizamos la posicion del sprite con la informacion del evento del mouse
					cursors.setPosition(
						evt.mouseMove.x,
						evt.mouseMove.y);
			}
		}
		// Limpiamos la ventana
		App.clear();
		//Dibujamos la escena
		App.draw(fondos);
		App.draw(platas);
		App.draw(enemigos);
		App.draw(inocentes);
		App.draw(cursors);
		// Mostramos la ventana
		App.display();
	}
	return 0;
}
