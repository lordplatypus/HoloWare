#include <SFML/Graphics.hpp>
#include "DeltaTime.h"
#include "Camera.h"
#include "Game.h"

int main()
{
    bool isRunning = true;//bool for main game loop
    sf::RenderWindow render_window(sf::VideoMode(1920.0f, 1080.0f), "Game"); //game window

    DeltaTime deltaTime;

    Camera camera(&render_window, sf::Vector2f(960.0f, 540.0f));
    camera.SetView("Main");
    camera.SetView("Transition", sf::Vector2f(480.0f, 270.0f));
    render_window.setView(*camera.GetView("Main"));

    Game game{&camera};

    while (isRunning)
    {//main game loop
        sf::Event event; //events
        while (render_window.pollEvent(event))
        {//
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect viewport(0.0f, 0.0f, 1.0f, 1.0f);

                float screenwidth = event.size.width / camera.GetAspectRatio().x;
                float screenheight = event.size.height / camera.GetAspectRatio().y;

                if(screenwidth > screenheight)
                {
                    viewport.width = screenheight / screenwidth;
                    viewport.left = (1.0f - viewport.width) / 2.0f;
                }
                else if(screenwidth < screenheight)
                {
                    viewport.height = screenwidth / screenheight;
                    viewport.top = (1.0f - viewport.height) / 2.0f;
                }

                for (auto view : camera.GetAllViews())
                {
                    view.second->setViewport(viewport);
                    render_window.setView(*view.second);
                } 
            }
            else if (event.type == sf::Event::Closed)
            {
                isRunning = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                isRunning = false;
            }
        }
        game.Update(deltaTime.GetDeltaTime());
        render_window.clear();
        game.Draw(render_window);
        render_window.display();
    }
    return EXIT_SUCCESS;
}