#include <SFML/Graphics.hpp>

using namespace sf;

//вариант 3

int main()
{
	int key = 0;
	int x = 200;
	int y = 100;

	RenderWindow window(VideoMode(600, 600), "prmng");
	window.clear(Color::Black);
	RectangleShape rectangle(Vector2f(x, y));
	rectangle.setFillColor(Color::Green);
	rectangle.move(0, 0);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::S) key = 1;
				if (event.key.code == Keyboard::D) key = 2;
				if (event.key.code == Keyboard::Space) key = 3;
			}
		}

		if (key == 1) 
		{
			rectangle.scale(1, 1.01);
			window.draw(rectangle);
			sleep(milliseconds(10));
		}

		else if (key == 2)
		{
			rectangle.scale(1.01, 1);
			window.draw(rectangle);
			sleep(milliseconds(10));
		}

		window.draw(rectangle);
		window.display();
	}
}