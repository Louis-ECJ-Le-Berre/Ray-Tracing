#include <iostream>
#include <fstream>
#include <cstring>

#include "color.h"
#include "vec3.h"

int main(int argc, char* argv[]){

std::ofstream ppm_file(argv[1]); //Créer le fichier .ppm
std::streambuf* original_cout_buffer = std::cout.rdbuf(ppm_file.rdbuf()); //Rediriger le std::cout vers ce fichier

int image_width = 256;
int image_height = 256;

std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

for (int j=0 ; j < image_height ; j++)
{
    std::clog << "\rScanlines remaining : " << (image_height -j) << ' ' << std::flush;
    for (int i = 0 ; i<image_width ; i++)
    {
        auto pixel_color = color(0, double(j)/(image_height-1), double(i)/(image_width-1));
        write_color(std::cout,pixel_color);
    }

}

std::clog << "\rDone.           \n";
std::cout.rdbuf(original_cout_buffer); //Restaurer le buffer du std::cout

}