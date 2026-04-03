#include <iostream>
#include <fstream>
#include <complex>
#include <vector>

struct ComplexPlane {
    double min_real, max_real;
    double min_imag, max_imag;
    int width, height;
};

class MandelbrotSet {
private:
    int max_iterations;
    
public:
    MandelbrotSet(int max_iter = 1000) : max_iterations(max_iter) {}
    
    int iterate(const std::complex<double>& c) {
        std::complex<double> z = 0;
        
        for (int i = 0; i < max_iterations; i++) {
            if (std::abs(z) > 2.0) {
                return i;  // Exploded
            }
            z = z * z + c;  // z_{n+1} = z_n² + c
        }
        
        return max_iterations;  // Didn't explode
    }
    
    void generatePPM(const ComplexPlane& plane, const std::string& filename) {
        std::ofstream file(filename);
        file << "P3\n" << plane.width << " " << plane.height << "\n255\n";
        
        for (int y = 0; y < plane.height; y++) {
            for (int x = 0; x < plane.width; x++) {
                // Convert pixel coordinates to complex plane
                double real = plane.min_real + (double)x / plane.width * (plane.max_real - plane.min_real);
                double imag = plane.min_imag + (double)y / plane.height * (plane.max_imag - plane.min_imag);
                
                std::complex<double> c(real, imag);
                int iterations = iterate(c);
                
                // Color based on iterations
                if (iterations == max_iterations) {
                    // Black for points that don't explode (in the set)
                    file << "0 0 0 ";
                } else {
                    // Color gradient for points that explode
                    int color_intensity = (iterations * 255) / max_iterations;
                    file << color_intensity << " " << (color_intensity / 2) << " " << (255 - color_intensity) << " ";
                }
            }
            file << "\n";
        }
        
        file.close();
    }
    
    void generateSVG(const ComplexPlane& plane, const std::string& filename) {
        std::ofstream file(filename);
        file << "<svg xmlns='http://www.w3.org/2000/svg' width='" << plane.width << "' height='" << plane.height << "'>\n";
        file << "<rect width='100%' height='100%' fill='black'/>\n";
        
        for (int y = 0; y < plane.height; y++) {
            for (int x = 0; x < plane.width; x++) {
                double real = plane.min_real + (double)x / plane.width * (plane.max_real - plane.min_real);
                double imag = plane.min_imag + (double)y / plane.height * (plane.max_imag - plane.min_imag);
                
                std::complex<double> c(real, imag);
                int iterations = iterate(c);
                
                if (iterations != max_iterations) {
                    // Color gradient for points that explode
                    int color_intensity = (iterations * 255) / max_iterations;
                    file << "<rect x='" << x << "' y='" << y << "' width='1' height='1' fill='rgb(" 
                         << color_intensity << "," << (color_intensity / 2) << "," << (255 - color_intensity) << ")'/>\n";
                }
            }
        }
        
        file << "</svg>\n";
        file.close();
    }
};

int main() {
    std::cout << "Generating Mandelbrot Set..." << std::endl;
    
    // Define the complex plane region to explore
    ComplexPlane plane;
    plane.min_real = -2.5;
    plane.max_real = 1.5;
    plane.min_imag = -2.0;
    plane.max_imag = 2.0;
    plane.width = 800;
    plane.height = 800;
    
    MandelbrotSet mandelbrot(1000);
    
    // Generate PPM image
    std::cout << "Creating PPM image..." << std::endl;
    mandelbrot.generatePPM(plane, "mandelbrot.ppm");
    
    // Generate SVG image
    std::cout << "Creating SVG image..." << std::endl;
    mandelbrot.generateSVG(plane, "mandelbrot.svg");
    
    std::cout << "Mandelbrot set generated successfully!" << std::endl;
    std::cout << "Files created: mandelbrot.ppm and mandelbrot.svg" << std::endl;
    
    return 0;
}
