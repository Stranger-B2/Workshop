#include <sil/sil.hpp>
#include <iostream>

void Green(sil::Image im){
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            im.pixel(x, y).r = 0.f;
            im.pixel(x, y).b = 0.f;
        }
    }
    im.save("output/green.png");
}
float InnnerSwitch(sil::Image& im, char chan2, int x, int y, float entry){
    float sorti;
    switch(chan2){
        case 'r':
            sorti = im.pixel(x, y).r;
            im.pixel(x, y).r = entry;
            break;
        case 'g':
            sorti = im.pixel(x, y).g;
            im.pixel(x, y).g = entry;
            break;
        case 'b':
            sorti = im.pixel(x, y).b;
            im.pixel(x, y).b = entry;
        break;
        default:
            std::cout<< "chan2" << std::endl;
            return entry;
    }
    return sorti;
}
void SwichChannel(sil::Image im, std::string chan1, std::string chan2){
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            switch(chan1[0]){
                case 'r':
                    im.pixel(x, y).r = InnnerSwitch(im, chan2[0], x, y, im.pixel(x, y).r);
                    break;
                case 'g':
                    im.pixel(x, y).g = InnnerSwitch(im, chan2[0], x, y, im.pixel(x, y).g);
                    break;
                case 'b':
                    im.pixel(x, y).b = InnnerSwitch(im, chan2[0], x, y, im.pixel(x, y).b);
                    break;
                default:
                    std::cout<< "chan1" << std::endl;
                    return;
            }
        }
    }
    std::string name("output/switch");
    name.append(chan1);
    name.append(chan2);
    name.append(".png");
    im.save(name);
}
int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    image.save("output/pouet.png");
    //Green(image);
    /*SwichChannel(image,"r","b");
    SwichChannel(image,"g","r");
    SwichChannel(image,"b","g");
    SwichChannel(image,"r","r");*/
    

}
//compil cmake .    puis    cmake --build .
//exec ./ImageEditor

//dificulté une l'oublie que se sont des copies et non l'original pour les fonctions auxiliaire