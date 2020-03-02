#include "Tutorial.h"

Tutorial::Tutorial(int x, int y) 
{
	//Add all needed images in the order you want them to play
	std::cout << "Tutorial Created\n";
	AddSprite("graphics/Tutorial/Ball Intro.png");
	AddSprite("graphics/Tutorial/Charmingly_Self_Deprecating_Ball.png");
	AddSprite("graphics/Tutorial/Face_Ball.png");
	AddSprite("graphics/Tutorial/No_Face_Ball.png");
	AddSprite("graphics/Tutorial/Power Example1.png");
	AddSprite("graphics/Tutorial/Power Example2.png");
	AddSprite("graphics/Tutorial/Power_Example3.png");
	AddSprite("graphics/Tutorial/Accuracy_Example1.png");
	AddSprite("graphics/Tutorial/Accuracy_Example2.png");
	AddSprite("graphics/Tutorial/Accuracy_Example3.png");
	AddSprite("graphics/Tutorial/Rotation_Example1.png");
	AddSprite("graphics/Tutorial/Rotation_Example2.png");
	AddSprite("graphics/Tutorial/Rotation_Example3.png");
	AddSprite("graphics/Tutorial/Rotation_Example4.png");
	AddSprite("graphics/Tutorial/Hole_Example1.png");
	AddSprite("graphics/Tutorial/Hole_Example2.png");
	AddSprite("graphics/Tutorial/Hole_Example3.png");
	AddSprite("graphics/Tutorial/Sand_example1.png");
	AddSprite("graphics/Tutorial/Sand_example2.png");
	AddSprite("graphics/Tutorial/Sand_example3.png");
	AddSprite("graphics/Tutorial/Anakin.jpg");
	AddSprite("graphics/Tutorial/Windmill_Example1.png");
	AddSprite("graphics/Tutorial/Windmill_Example2.png");
	AddSprite("graphics/Tutorial/Door_Example1.png");
	AddSprite("graphics/Tutorial/Door_Example2.png");
	AddSprite("graphics/Tutorial/Door_Example3.png");
	AddSprite("graphics/Tutorial/Door_Example4.png");
	AddSprite("graphics/Tutorial/Ball_Ending1.png");
	AddSprite("graphics/Tutorial/Ball_Ending2.png");
	currentImage.setScale(2.1, 4.2);
	currentImage.setTexture(textureQueue.front());
	
	currentImage.setPosition(20, 100);

	m_SM->playTutorialMusic();
}

Tutorial::~Tutorial()
{
	std::cout << "Tutorial Destroyed\n";
	m_SM->stopTutorialMusic();
}

void Tutorial::AddSprite(string name)
{
	//Creates a texture from the filename and adds a copy to TextureVector
	//Original Texture is deleted after function completes.
	Texture texture;
	texture.loadFromFile(name);
	texture.setSmooth(true);
	textureQueue.push(texture);
	std::cout << "Texture added to queue.\n";
}

Sprite Tutorial::Update(float dt, RenderWindow& window)
{
	//window.clear(Color::Black);
	//After 3.5 seconds, the iterator iterates, and timeElapsed resets.
	TimeElapsed += dt;
	if (TimeElapsed > 3.5 && textureQueue.size() > 1)
	{
		textureQueue.pop();
		TimeElapsed = 0.0;
		currentImage.setTexture(textureQueue.front());
		
		std::cout << "Displaying: " << &textureQueue.front() << endl;
	}
	else if (TimeElapsed > 3.5 && textureQueue.size() > 1) {

	}
	//Ensure the iterator is within bounds, destroy if not.
	if (textureQueue.empty())
	{
		
	}
	return currentImage;
}

