#include <iostream>
#include <SFML/window.hpp>
#include <SFML/graphics.hpp>

using namespace sf;

Texture texture, fondot, platat;
Sprite sprite, fondos, platas, platas1, platas2, platas3, platas4, platas5, platas6, platas7, platas8, platas9, platas10, platas11, platas12, platas13, platas14, platas15, platas16, platas17, platas18, platas19, platas20, platas21, platas22, platas23, platas24, platas25, platas26, platas27, platas28, platas29, platas30;

int main() {

	//Cargamos la textura del archivo
	texture.loadFromFile("Imagenes/Gaviota.png");
	fondot.loadFromFile("Imagenes/fondo.jpg");
	platat.loadFromFile("Imagenes/plataforma.jpg");
	//Configuramos el material del sprite
	platas.setTexture(platat);
	platas1.setTexture(platat);
	platas2.setTexture(platat);
	platas3.setTexture(platat);
	platas4.setTexture(platat);
	platas5.setTexture(platat);
	platas6.setTexture(platat);
	platas7.setTexture(platat);
	platas8.setTexture(platat);
	platas9.setTexture(platat);
	platas10.setTexture(platat);
	platas11.setTexture(platat);
	platas12.setTexture(platat);
	platas13.setTexture(platat);
	platas14.setTexture(platat);
	platas15.setTexture(platat);
	platas16.setTexture(platat);
	platas17.setTexture(platat);
	platas18.setTexture(platat);
	platas19.setTexture(platat);
	platas20.setTexture(platat);
	platas21.setTexture(platat);
	platas22.setTexture(platat);
	platas23.setTexture(platat);
	platas24.setTexture(platat);
	platas25.setTexture(platat);
	platas26.setTexture(platat);
	platas27.setTexture(platat);
	platas28.setTexture(platat);
	platas29.setTexture(platat);
	platas30.setTexture(platat);
	fondos.setTexture(fondot);
	sprite.setTexture(texture);
	//Le establecemos el tamaño
	platas.setScale(0.2,0.2);
	platas1.setScale(0.2, 0.2);
	platas2.setScale(0.2, 0.2);
	platas3.setScale(0.2, 0.2);
	platas4.setScale(0.2, 0.2);
	platas5.setScale(0.2, 0.2);
	platas6.setScale(0.2, 0.2);
	platas7.setScale(0.2, 0.2);
	platas8.setScale(0.2, 0.2);
	platas9.setScale(0.2, 0.2);
	platas10.setScale(0.2, 0.2);
	platas11.setScale(0.2, 0.2);
	platas12.setScale(0.2, 0.2);
	platas13.setScale(0.2, 0.2);
	platas14.setScale(0.2, 0.2);
	platas15.setScale(0.2, 0.2);
	platas16.setScale(0.2, 0.2);
	platas17.setScale(0.2, 0.2);
	platas18.setScale(0.2, 0.2);
	platas19.setScale(0.2, 0.2);
	platas20.setScale(0.2, 0.2);
	platas21.setScale(0.2, 0.2);
	platas22.setScale(0.2, 0.2);
	platas23.setScale(0.2, 0.2);
	platas24.setScale(0.2, 0.2);
	platas25.setScale(0.2, 0.2);
	platas26.setScale(0.2, 0.2);
	platas27.setScale(0.2, 0.2);
	platas28.setScale(0.2, 0.2);
	platas29.setScale(0.2, 0.2);
	platas30.setScale(0.2, 0.2);
	sprite.setScale(5,5);
	//Le damos una posición
	platas.setPosition(0, 550);
	platas1.setPosition(100, 550);
	platas2.setPosition(100, 500);
	platas3.setPosition(200, 550);
	platas4.setPosition(200, 500);
	platas5.setPosition(200, 450);
	platas6.setPosition(300, 550);
	platas7.setPosition(300, 500);
	platas8.setPosition(300, 450);
	platas9.setPosition(300, 400);
	platas10.setPosition(400, 550);
	platas11.setPosition(400, 500);
	platas12.setPosition(400, 450);
	platas13.setPosition(400, 400);
	platas14.setPosition(400, 350);
	platas15.setPosition(500, 550);
	platas16.setPosition(500, 500);
	platas17.setPosition(500, 450);
	platas18.setPosition(500, 400);
	platas19.setPosition(500, 350);
	platas20.setPosition(500, 300);
	platas21.setPosition(600, 550);
	platas22.setPosition(600, 500);
	platas23.setPosition(600, 450);
	platas24.setPosition(600, 400);
	platas25.setPosition(600, 350);
	platas26.setPosition(600, 300);
	platas27.setPosition(600, 250);
	platas28.setPosition(650, 150);
	platas29.setPosition(700, 150);
	platas30.setPosition(750, 150);
	sprite.setPosition(700, 100);
	//En caso de que la imagen se vea pixelada, utilizar este código: texture.setSmooth(true);
	//Para rotar una imagen primero le seteamos el origen de rotación en el centro, pq por default está arriba a la izquierda
	sprite.setOrigin(sprite.getTexture()->getSize().x / 2.f, sprite.getTexture()->getSize().y / 2.f);
	//Con el getTexture()->getSize().x/2.0 se consigue se consigue la mitad del ancho de la imagen, con el .y/2, la mitad del alto

	//Creamos la ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),"Ventanita");

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
			}
		}
		// Limpiamos la ventana
		App.clear();
		//Dibujamos la escena
		App.draw(fondos);
		App.draw(platas1);
		App.draw(platas2);
		App.draw(platas3);
		App.draw(platas4);
		App.draw(platas5);
		App.draw(platas6);
		App.draw(platas7);
		App.draw(platas8);
		App.draw(platas9);
		App.draw(platas10);
		App.draw(platas11);
		App.draw(platas12);
		App.draw(platas13);
		App.draw(platas14);
		App.draw(platas15);
		App.draw(platas16);
		App.draw(platas17);
		App.draw(platas18);
		App.draw(platas19);
		App.draw(platas20);
		App.draw(platas21);
		App.draw(platas22);
		App.draw(platas23);
		App.draw(platas24);
		App.draw(platas25);
		App.draw(platas26);
		App.draw(platas27);
		App.draw(platas28);
		App.draw(platas29);
		App.draw(platas30);
		App.draw(platas);
		App.draw(sprite);
		// Mostramos la ventana
		App.display();
		//Rotamos la imagen
		sprite.setRotation(sprite.getRotation() + 0.1);
	}
	return 0;
}
