#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int posicionX(int posicion, int velocidad, int tiempo)
{
    return posicion + velocidad * tiempo;
}

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;
    int vix = 5;
    int posx = 100;
    int posy = 100;

    const int canvas_width = 300;
    const int canvas_height = 300;

    while (true)
    {
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

        int nueva_posx = posicionX(posx, vix, frame);

        auto can = Canvas(canvas_width, canvas_height);

        can.DrawPointCircle(nueva_posx % canvas_width, posy + 10, 10, Color::GrayDark);       
        can.DrawPointCircle((nueva_posx + 60) % canvas_width, posy + 10, 10, Color::GrayDark); 

        for (int i = nueva_posx % canvas_width; i < (nueva_posx + 60) % canvas_width; ++i)
        {
            can.DrawPoint(i, posy, Color::Blue); 
        }
        can.DrawPoint((nueva_posx + 30) % canvas_width, posy - 20, Color::Blue); 
        can.DrawPoint((nueva_posx + 30) % canvas_width, posy - 30, Color::Blue); 

        can.DrawPointLine(nueva_posx % canvas_width, posy + 10, (nueva_posx + 30) % canvas_width, posy, Color::Blue);    
        can.DrawPointLine((nueva_posx + 60) % canvas_width, posy + 10, (nueva_posx + 30) % canvas_width, posy, Color::Blue); 

        Element lienzo = bgcolor(Color::Black, canvas(&can));
        Render(pantalla, lienzo);

        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);

        std::cout << "Frame: " << frame << ", X: " << nueva_posx << std::endl;

        this_thread::sleep_for(0.5s);

        frame++;
    }

    return 0;
}