#include <iostream>
#include <SFML/Graphics.hpp>
#include "classes.cpp"


int main()
{
    Rectangles boxes[9] = {
    Rectangles(160,40,290,140),
    Rectangles(315,40,460,140),
    Rectangles(500,40,610,140),
    Rectangles(160,170,290,280),
    Rectangles(315,170,460,280),
    Rectangles(500,170,610,280),
    Rectangles(160,310,290,430),
    Rectangles(315,310,460,430),
    Rectangles(500,310,610,430)};
    int licznikBalejaz = 0, licznikPrecel = 0;
    std::vector<Cats> pictures;
    int check[9] = { 0,0,0,0,0,0,0,0,0 };
    int win=0;
    bool picture = false;
    sf::Clock clock;
    sf::Font font;    
    if (!font.loadFromFile("Freya Bowie.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;       
    }
    sf::Text precel("Precel",font,40), balejaz("Balejaz", font, 40), wynikPrecel("0", font, 40), wynikBalejaz("0", font, 40), communicat(" ", font, 40), reset("reset",font, 40);
    reset.setPosition(60, 300);
    communicat.setPosition(50, 15);    
    precel.setPosition(50, 70);
    balejaz.setPosition(50, 170);
    wynikPrecel.setPosition(80, 120);
    wynikBalejaz.setPosition(80, 220);    
    sf::Color orange(255, 175, 17, 255);
    sf::Color balayage(30, 223, 217, 255);
    reset.setFillColor(sf::Color::Red);
    precel.setFillColor(orange);
    wynikPrecel.setFillColor(orange);
    balejaz.setFillColor(balayage);
    wynikBalejaz.setFillColor(balayage);


    sf::RenderWindow window(sf::VideoMode(786, 480, 32), "Precel vs Balejaz");
    window.setFramerateLimit(20);
    window.setActive();
    sf::Texture background;    
    background.loadFromFile("background.jpg");
    sf::Sprite bg(background);
    
    sf::Event e;

    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
            if (e.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                std::cout << mousePos.x << " " << mousePos.y << std::endl;               
                if (reset.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    for (int i = 0; i < 9; i++)
                    {
                        check[i] = 0;
                    }
                    pictures.clear();
                    communicat.setString("");
                    licznikBalejaz = 0;
                    licznikPrecel = 0;
                    wynikPrecel.setString("0");
                    wynikBalejaz.setString("0");
                }
                sf::Texture T;
                for (int i = 0; i < 9; i++)
                {
                    if (check[i] == 0)
                    {
                        if (boxes[i].ifContains(mousePos))
                        {
                            if (picture == false)
                            {
                                pictures.push_back(Cats(boxes[i].returnCoords(), "balejaz.png"));
                                check[i] = 1;
                            }
                            else
                            {
                                pictures.push_back(Cats(boxes[i].returnCoords(), "precel.png"));
                                check[i] = 2;
                            }
                            picture = !picture;
                        }
                    }                    
                }           
            }
        }

        //poziomy
        if (check[0] == check[1] && check[1] == check[2] && check[0] != 0) { win = check[0]; }
        if (check[3] == check[4] && check[4] == check[5] && check[3] != 0) { win = check[3]; }
        if (check[6] == check[7] && check[7] == check[8] && check[6] != 0) { win = check[6]; }
        //piony
        if (check[0] == check[3] && check[3] == check[6] && check[0] != 0) { win = check[0]; }
        if (check[1] == check[4] && check[4] == check[7] && check[1] != 0) { win = check[1]; }
        if (check[2] == check[5] && check[5] == check[8] && check[2] != 0) { win = check[2]; }
        //skosy
        if (check[0] == check[4] && check[4] == check[8] && check[0] != 0) { win = check[0]; }
        if (check[2] == check[4] && check[4] == check[6] && check[2] != 0) { win = check[2]; }

        for (const auto& fan : pictures)
        {
            window.draw(fan);
        }
        
        window.display();
        if (win == 2)
        {
            std::cout << "lol" << std::endl;
            licznikPrecel++;
            win = 0;
            communicat.setString("Wygral Precel!");
            wynikPrecel.setString(std::to_string(licznikPrecel));
            for (int i = 0; i < 9; i++)
            {
                check[i] = 0;
            }
            pictures.clear();
        }
       if (win == 1)
            
        {
            std::cout << "lodscsdl" << std::endl;
            licznikBalejaz++;
            win = 0;
            communicat.setString("Wygrala Balejaz!");            
            wynikBalejaz.setString(std::to_string(licznikBalejaz));
            for (int i = 0; i < 9; i++)
            {
                check[i] = 0;
            }
            pictures.clear();
        }
        
        
        window.draw(bg);
        window.draw(reset);
        window.draw(communicat);
        window.draw(precel);
        window.draw(balejaz);
        window.draw(wynikPrecel);
        window.draw(wynikBalejaz);
       
        
    }
    return 0;
}