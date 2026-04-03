#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

struct Point {
    double x, y;
};

int number_of_points = 100;

void drawPoints(std::vector<Point> points, int index) {
    std::string filename = "output" + std::to_string(index) + ".svg";
    std::ofstream svg(filename);
    svg << "<svg xmlns='http://www.w3.org/2000/svg' width='1000' height='1000'>\n";

    // Draw lines between points
    svg << "<polyline points='";
    for (auto &p : points)
        svg << p.x << "," << p.y << " ";
    svg << "' stroke='black' fill='none' stroke-width='2'/>\n";

    // Draw points
    for (auto &p : points)
        svg << "<circle cx='" << p.x << "' cy='" << p.y
            << "' r='4' fill='red'/>\n";

    svg << "</svg>\n";
    svg.close();
}

double totalLength(std::vector<Point> points) {
    double total = 0.0;
    for (int i = 0; i < points.size() - 1; i++) {
        double distX = points[i].x - points[i + 1].x;
        double distY = points[i].y - points[i + 1].y;
        total += std::sqrt(distX * distX + distY * distY);
    }
    return total;
}

std::vector<Point> iterate(std::vector<Point> points) {
    double total_length = totalLength(points);
    //std::cout << total_length << std::endl;
    int iterations = 10000000;
    int index = 1;
    std::srand(std::time({}));
    for (int i = 0; i < iterations; i++) {
        int index1 = std::rand() % number_of_points;
        int index2 = std::rand() % number_of_points;
        std::swap(points[index1], points[index2]);
        double new_length = totalLength(points);
        if (new_length >= total_length) {
            std::swap(points[index1], points[index2]);
        }
        else {
            total_length = new_length;
            //std::cout << new_length << std::endl;

        }
    }
    return points;

}

int main() {
    int number_of_points = 100;
    std::vector<Point> points;
    for (int i = 0; i < number_of_points; i++) {
        Point point = {(double)(std::rand() % 1000), (double)(std::rand() % 1000)};
        points.push_back(point);
    }

    drawPoints(points, 0);
    double minLength = 10000000000000;
    int minLengthIndex = 0;
    for (int i = 0; i < 1000; i++) {
        std::vector<Point> p = iterate(points);
        double length = totalLength(p);
        if (length < minLength) {
            std::cout << totalLength(p) << std::endl;
            minLength = length;
            drawPoints(p, minLengthIndex++);
        }
       
    }
    

    return 0;
}
