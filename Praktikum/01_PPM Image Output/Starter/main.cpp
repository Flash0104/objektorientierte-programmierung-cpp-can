#include <iostream>
#include <fstream>

const unsigned int width = 100;
const unsigned int height = 100;

const unsigned int width_small = 11;
const unsigned int height_small = 11;

void printHeader(std::ofstream& ppmFile, const unsigned int width, const unsigned int height) {
    ppmFile << "P3" << std::endl; // Magic Number, we're doing a pixelmap here
    ppmFile << width << " " << height << std::endl;   // We need to specify width/height
    ppmFile << "255" << std::endl;    // Maximum value
}

struct pixel {
    double r,g,b;
};

// Sets the color of the pixel at x (horizontal) and y (vertical) in the screen
void setColor(pixel* screen, const unsigned int x, const unsigned int y, const unsigned int width, pixel color) {
    screen[y * width + x] = color;
}

void drawCircle(pixel* screen, const int x_circle, const int y_circle, const unsigned int radius, const unsigned int width, const unsigned int height, pixel color) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int dx = x - x_circle;
            int dy = y - y_circle;
            double distance = dx * dx + dy * dy;
            
            if (distance <= radius * radius) {
                setColor(screen, x, y, width, color);
            }
        }
    }
}

void printScreenToPPMFile(const pixel* screen, std::ofstream& ppmFile, const unsigned int width, const unsigned int height) {
    printHeader(ppmFile, width ,height);
    for( int y = 0; y < height; y++) {
        for( int x = 0; x < width; x++) {
            ppmFile << static_cast<int>(screen[y*width + x].r * 255.0) << " ";
            ppmFile << static_cast<int>(screen[y*width + x].g * 255.0) << " ";
            ppmFile << static_cast<int>(screen[y*width + x].b * 255.0) << " ";
        }
        ppmFile << "\n";
    }
}

int main() {

    // 11x11 gradient
    pixel screen_small[width_small*height_small];
    std::ofstream ppmFile_small("gradient_11x11.ppm");

    for(int i = 0; i < height_small; i++) {
        for(int j = 0; j < width_small; j++) {
            double nx = (double)j / (width_small - 1);
            double ny = (double)i / (height_small - 1);
            setColor(screen_small, j, i, width_small, {ny, 0, nx});
        }
    }

    printScreenToPPMFile(screen_small, ppmFile_small, width_small, height_small);
    ppmFile_small.close();


    // 100x100 with circle
    pixel screen[width*height];
    std::ofstream ppmFile("output.ppm");

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            double nx = (double)j / (width - 1);
            double ny = (double)i / (height - 1);
            setColor(screen, j, i, width, {ny, 0, nx});
        }
    }
    drawCircle(screen, 20, 80, 5, width, height, {0,1,0});

    printScreenToPPMFile(screen, ppmFile, width, height);
    ppmFile.close();


    return 0;
}
