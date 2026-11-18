#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <math.h>
#include <complex>

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
void DegradIm(sil::Image im){
    float val = 1.0f;
    for (int x{0}; x < im.width(); ++x)
    {
        val = 1.0-((im.width()-x)/(im.width()*1.0f));
        for (int y{0}; y < im.height(); ++y)
        {
            im.pixel(x, y) = im.pixel(x, y)+glm::vec3{val,val,val};
        }
    }
    im.save("output/DegradAsh.png");
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
void Disque(int centreX, int centreY, int r){
    sil::Image im{500/*width*/, 500/*height*/};
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            if(((x-centreX)*(x-centreX)+(y-centreY)*(y-centreY) <r*r))
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
sil::Image DisqueAnim(int centreX, int centreY, int r){
    sil::Image im{500/*width*/, 500/*height*/};
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            if(((x-centreX)*(x-centreX)+(y-centreY)*(y-centreY) <r*r))
                im.pixel(x, y) = glm::vec3{1.0f};
            else
                im.pixel(x, y) = glm::vec3{0.0f};
        }
    }
    return im;
}
void AnimationDisqueEnter(int centreX, int centreY, int r){
    if (centreX < 0 || centreY < 0 || r <0)
        return;
    for(int i = 0; i < centreX; i+=3){
        if(i >= 500)
            return;
        std::string name("output/anim/animation");
        name.append(std::to_string(i));
        name.append(".png");
        DisqueAnim(i, centreY, r).save(name);
    }
}
void miRosace(sil::Image& im, int x, int y, int testx, int testy, int r, float thick){//doubt
    if((testx*testx + testy*testy <(r+thick/2)*(r+thick/2)) && !(testx*testx + testy*testy < (r-thick/2)*(r-thick/2)))
                im.pixel(x, y) = glm::vec3{1.0f};
}
void Rosace(int r, float thick){
    sil::Image im{500/*width*/, 500/*height*/};
    if (thick < 0 )
        thick = 0;
    if (thick > r )
        thick = r;
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            im.pixel(x, y) = glm::vec3{0.0f};
            miRosace(im, x, y, x-250,                 y-250, r, thick);
            miRosace(im, x, y, x-250+r,     y-250, r, thick);
            miRosace(im, x, y, x-250-r,    y-250, r, thick);
            miRosace(im, x, y, x-250+(r/2), y-250+(std::sqrt(3)*r/2), r, thick);
            miRosace(im, x, y, x-250-(r/2), y-250+(std::sqrt(3)*r/2), r, thick);
            miRosace(im, x, y, x-250+(r/2), y-250-(std::sqrt(3)*r/2), r, thick);
            miRosace(im, x, y, x-250-(r/2), y-250-(std::sqrt(3)*r/2), r, thick);
        }
    }
    im.save("output/rosace.png");
}
void miRosaceCroissant(sil::Image& im, int x, int y, int testx, int testy, int r, float thick, int direcX, int direcY){
    if((testx*testx + testy*testy <(r+thick/2)*(r+thick/2)) && !((testx - (thick*direcX))*(testx - (thick*direcX)) + (testy - (thick*direcY))*(testy - (thick*direcY)) < r*r))
        im.pixel(x, y) = glm::vec3{1.0f};
}
void RosaceCroissant(int r, float thick){
    sil::Image im{500/*width*/, 500/*height*/};
    if (thick < 0 )
        thick = 0;
    if (thick > r )
        thick = r;
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            im.pixel(x, y) = glm::vec3{0.0f};
            miRosaceCroissant(im, x, y, x-250+r,     y-250, r, thick,                     1,  1);
            miRosaceCroissant(im, x, y, x-250-r,     y-250, r, thick,                    -1,  1);
            miRosaceCroissant(im, x, y, x-250+(r/2), y-250-(std::sqrt(3)*r/2), r, thick,  1, -1);
            miRosaceCroissant(im, x, y, x-250-(r/2), y-250-(std::sqrt(3)*r/2), r, thick, -1, -1);
            miRosaceCroissant(im, x, y, x-250+(r/2), y-250+(std::sqrt(3)*r/2), r, thick,  1,  1);
            miRosaceCroissant(im, x, y, x-250-(r/2), y-250+(std::sqrt(3)*r/2), r, thick, -1,  1);
        }
    }
    im.save("output/rosacecroissanr.png");
}
void Mosaique(sil::Image& im, int boucle){//doubt
    boucle++;
    sil::Image Newim{im.width(), im.height()};
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            Newim.pixel(x,y) = im.pixel((x*boucle)%im.width(), (y*boucle)%im.height());
        }
    }
    Newim.save("output/mosaique.png");
}
void MosaiqueMirrorBug(sil::Image& im, int boucle){//doubt
    boucle++;
    int xF;
    int yF;
    sil::Image Newim{im.width(), im.height()};
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            if(((x*boucle)/2)%2)
                xF = im.width() - ((x*boucle)%im.width())-1;
            else
                xF = (x*boucle)%im.width();
            if(((y*boucle)/2)%2)
                yF = im.height() - ((y*boucle)%im.height())-1;
            else
                yF = (y*boucle)%im.height();

            Newim.pixel(x,y) = im.pixel(xF, yF); 
        }
    }
    Newim.save("output/mirromosaiqueBug.png");
}
void MosaiqueMirror(sil::Image& im, int boucle){//doubt
    boucle++;
    int xF;
    int yF;
    sil::Image Newim{im.width(), im.height()};
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            if(((x*boucle)/im.width())%2)
                xF = im.width() - ((x*boucle)%im.width())-1;
            else
                xF = (x*boucle)%im.width();
            if(((y*boucle)/im.height())%2)
                yF = im.height() - ((y*boucle)%im.height())-1;
            else
                yF = (y*boucle)%im.height();

            Newim.pixel(x,y) = im.pixel(xF, yF); 
        }
    }
    Newim.save("output/mirromosaique.png");
}
float nbComplexe(std::complex<float> c){
    std::complex<float> z = {0.0f,0.0f};
    int i =0;
    for (; i< 30; i++){
        z = z*z +c;
        if (std::abs(z) > 2)
            return (i)/30.0f;//i/100.0f;
    }
    return 1.0;
}
void fractale1(){
    sil::Image im{500,500};
    float n;
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            n=nbComplexe({(x-250)/250.0f,(y-250)/250.0f});
            im.pixel(x, y) = glm::vec3{n,n,n};
        }
    }
    im.save("output/fractal.png");
}
float nbComplexe2(std::complex<float> c){
    std::complex<float> z = {1.0f,0.0f};
    int i =0;
    for (; i< 30; i++){
        z = z*z +c;
        if (std::abs(z) > 2)
            return (i)/30.0f;//i/100.0f;
    }
    return 1.0;
}
void fractale2(){
    sil::Image im{500,500};
    float n;
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            n=nbComplexe2({(x-450)/200.0f,(y-250)/200.0f});
            im.pixel(x, y) = glm::vec3{n,0.0f,n};
        }
    }
    im.save("output/fractal2.png");
}
float nbComplexeP(std::complex<float> c, float v){
    std::complex<float> z = {0.0f,0.0f};
    int i =0;
    for (; i< 30; i++){
        z = std::pow(z,v) +c;
        if (std::abs(z) > 2)
            return (i)/30.0f;//i/100.0f;
    }
    return 1.0;
}
void fractalepuissance(float v, glm::vec3 col){
    sil::Image im{500,500};
    float n;
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            n=nbComplexeP({(x-250)/200.0f,(y-250)/200.0f}, v);
            im.pixel(x, y) = col * n;
        }
    }
    std::string name("output/fractalPuissance/puissance0,0/");
    name.append(std::to_string(v));
    name.append(".png");
    im.save(name);
}
void DegradColor(glm::vec3 col1, glm::vec3 col2){
    sil::Image im{300/*width*/, 200/*height*/};
    float val = 1.0f;
    for (int x{0}; x < im.width(); ++x)
    {
        val = 1-((300.0f-x)/300.0f);
        for (int y{0}; y < im.height(); ++y)
        {
            im.pixel(x, y) = glm::mix(col1, col2,val);
        }
    }
    im.save("output/DegradColor.png");
}
sil::Image tramageBasique(sil::Image im){
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            if ((im.pixel(x, y).r+im.pixel(x, y).g+im.pixel(x, y).b)/3 <0.5f)
                im.pixel(x, y) = glm::vec3{0.0f,0.0f,0.0f};
            else
                im.pixel(x, y) = glm::vec3{1.0f,1.0f,1.0f};
        }
    }
    //im.save("output/Tramage/black&white.png");
    return im;
}
sil::Image tramage2(sil::Image im){
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            if (((im.pixel(x, y).r+im.pixel(x, y).g+im.pixel(x, y).b)/3 + random_float(-0.4f,0.4f))<0.5f)
                im.pixel(x, y) = glm::vec3{0.0f,0.0f,0.0f};
            else
                im.pixel(x, y) = glm::vec3{1.0f,1.0f,1.0f};
        }
    }
    //im.save("output/Tramage/black&white2.png");
    return im;
}
sil::Image pointillage(sil::Image im, int puissance){
    float val;
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            if (x%2 == 1)
                val = -0.5f;
            else 
                val = -0.3f;
            if(y%2 == 0){
                if (x%2 == 1)
                    val = 0.3f;
                else 
                    val = 0.5f;
            }
            if (((im.pixel(x, y).r+im.pixel(x, y).g+im.pixel(x, y).b)/3 + std::pow(val, puissance))<0.5f)
                im.pixel(x, y) = glm::vec3{0.0f,0.0f,0.0f};
            else
                im.pixel(x, y) = glm::vec3{1.0f,1.0f,1.0f};
        }
    }
    return im;
}
sil::Image tramage3(sil::Image im){
    float val;
    for (int x{0}; x < im.width(); ++x)
    {
        for (int y{0}; y < im.height(); ++y)
        {
            if (x%2 == 1)
                val = -0.5f;
            else 
                val = -0.3f;
            if(y%2 == 0){
                if (x%2 == 1)
                    val = 0.3f;
                else 
                    val = 0.5f;
            }
            if (((im.pixel(x, y).r+im.pixel(x, y).g+im.pixel(x, y).b)/3 + val)<0.5f)
                im.pixel(x, y) = glm::vec3{0.0f,0.0f,0.0f};
            else
                im.pixel(x, y) = glm::vec3{1.0f,1.0f,1.0f};
        }
    }
    return im;
}
int main()
{   
    set_random_seed(0);
    sil::Image image{"images/logo.png"};
    sil::Image image2{"images/photo.jpg"};
    sil::Image image3{"images/AshBaby.jpg"};
    sil::Image p{"images/pont.png"};
    sil::Image p2{"images/pont2.png"};
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
    //DegradIm(image3);
    //Miroir(image);
    //Sound(image);
    //Rotation(image);
    //Dephasage(image);
    //Luminosite(image2,  true);
    //Disque(250,250,100);
    //Cercle(10);
    //AnimationDisqueEnter(250,250,100);
    //Rosace(100,10.0f);
    //RosaceCroissant(100,25.0f);
    //Mosaique(image, 8);
    //MosaiqueMirror(image, 8);
//    for(int i =0; i < 100; i++){
//        std::cout<<i<<std::endl;
//        fractale1();
//    }
 //   fractale2();
    /*for(int i =0; i < 20; i++){
        fractalepuissance(i, glm::vec3{ random_float(0.0f,1.0f),random_float(0.0f,1.0f),random_float(0.0f,1.0f)});
    }*/
   //MosaiqueMirrorBug(image3,1);
   //DegradColor(glm::vec3{1.0f,0.0f,0.0f},glm::vec3{0.0f,1.0f,0.0f});

   //tramageBasique(image2);
   //tramageBasique(p).save("output/Tramage/pon11.png");
   //tramageBasique(p2).save("output/Tramage/pont12.png");
   //tramage2(p).save("output/Tramage/pon21.png");
   //tramage2(p2).save("output/Tramage/pont22.png");
   //pointillage(p, 4).save("output/Tramage/quatre1.png");
   //pointillage(p2, 4).save("output/Tramage/quatre2.png");
   //tramage3(p).save("output/Tramage/pont31.png");
   //tramage3(p2).save("output/Tramage/pont32.png");
}
//compil cmake .    puis    cmake --build .
//exec ./ImageEditor

//dificulté une l'oublie que se sont des copies et non l'original pour les fonctions auxiliaire