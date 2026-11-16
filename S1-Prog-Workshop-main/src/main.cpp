#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <math.h>

void Green(sil::Image im){
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            im.pixel(x, y).r = 0.f;
            im.pixel(x, y).b = 0.f;
        }
    }
    im.save("output/Star/green.png");
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
    std::string name("output/Star/switch");
    name.append(chan1);
    name.append(chan2);
    name.append(".png");
    im.save(name);
}
void BlackWhite(sil::Image im){
    for (glm::vec3& color : im.pixels())
    {
        float c =(color.r+color.g+color.b)/3;
        color.r = c;
        color.g = c;
        color.b = c;
    }
    im.save("output/Star/black&white.png");
}
void Negatif(sil::Image im){
    for (glm::vec3& color : im.pixels())
    {
        color.r = 1-color.r;
        color.g = 1-color.g;
        color.b = 1-color.b;
    }
    im.save("output/Star/Negatif.png");
}
void Degrad(){
    sil::Image im{300/*width*/, 200/*height*/};
    float val = 1.0f;
    for (int x{0}; x < im.width(); ++x)
    {
        val = 1-((300.0f-x)/300.0f);
        for (int y{0}; y < im.height(); ++y)
        {
            im.pixel(x, y) = glm::vec3{val,val,val};
        }
    }
    im.save("output/Star/Degrad.png");
}
void Miroir(sil::Image im){
    for (int x{0}; x < im.width()/2; ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            std::swap( im.pixel(x, y),  im.pixel(im.width()-x-1, y));
        }
    }
    im.save("output/Star2/Miroir.png");
}
void Sound(sil::Image im){
    float x;
    float y;
    for (int i = 0; i <(im.width()*im.height()*2/3); i++){
        x = random_int(0, im.width());
        y = random_int(0, im.height());
        im.pixel(x,y).r = random_float(0, 1);
        im.pixel(x,y).g = random_float(0, 1);
        im.pixel(x,y).b = random_float(0, 1);

    }
    im.save("output/Star2/Sound.png");
}
void Rotation(sil::Image im){
    sil::Image NewIm{im.height(), im.width()};
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            NewIm.pixel(y,x) = im.pixel(x,y);
        }
    }
    NewIm.save("output/Star2/rotation.png");
}
void Dephasage(sil::Image im){
    sil::Image NewIm{im.height(), im.width()};
    NewIm = im;
    int decal = im.width()/10;
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            NewIm.pixel(x,y).r = ((x-decal >= 0)?im.pixel(x-decal,y).r:0.0f);
            NewIm.pixel(x,y).b = ((x+decal < im.width())?im.pixel(x+decal,y).b:0.0f);
            //NewIm.pixel(x,y).g = (im.pixel(x,y).g*2 > 1.0f)?im.pixel(x,y).g*2:1.0f;
        }
    }
    NewIm.save("output/Star2/dephaser.png");
}
void Luminosite(sil::Image im, bool type){
    for (glm::vec3& color : im.pixels())
    {
        if(!type){
            color.r = std::pow(color.r, 1.5f);
            color.g = std::pow(color.g, 1.5f);
            color.b = std::pow(color.b, 1.5f);
        }else{
            color.r = std::pow(color.r, 0.75f);
            color.g = std::pow(color.g, 0.75f);
            color.b = std::pow(color.b, 0.75f);
        }
    }
    im.save("output/Star2/Luminosite.png");
}
void Disque(){
    sil::Image im{500/*width*/, 500/*height*/};
    int r =100;
    int centre = 250;
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            if(((x-centre)*(x-centre)+(y-centre)*(y-centre) <r*r))
                im.pixel(x, y) = glm::vec3{1.0f};
            else
                im.pixel(x, y) = glm::vec3{0.0f};
        }
    }
    im.save("output/disque.png");
}
void Cercle(int thickness){
    sil::Image im{500/*width*/, 500/*height*/};
    int r =100;
    int r2 = r-thickness;
    if (thickness < 0 )
        r2 = 0;
    if (thickness > r )
        r2 = r;
    int centre = 250;
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            if(((x-centre)*(x-centre)+(y-centre)*(y-centre) <r*r) && !((x-centre)*(x-centre)+(y-centre)*(y-centre) <r2*r2))
                im.pixel(x, y) = glm::vec3{1.0f};
            else
                im.pixel(x, y) = glm::vec3{0.0f};
        }
    }
    im.save("output/cercle.png");
}
int main()
{   
    set_random_seed(0);
    sil::Image image{"images/logo.png"};
    sil::Image image2{"images/photo.jpg"};
    // TODO: modifier l'image
    //image.save("output/pouet.png");
    /* étoile 1
        Green(image);
        SwichChannel(image,"r","b");
        SwichChannel(image,"g","r");
        SwichChannel(image,"b","g");
        SwichChannel(image,"r","r");
        BlackWhite(image);
        Negatif(image);
        Degrad();
    */
    //Miroir(image);
    //Sound(image);
    //Rotation(image);
    //Dephasage(image);
    //Luminosite(image2,  true);
    //Disque();
    Cercle(1);
}
//compil cmake .    puis    cmake --build .
//exec ./ImageEditor

//dificulté une l'oublie que se sont des copies et non l'original pour les fonctions auxiliaire