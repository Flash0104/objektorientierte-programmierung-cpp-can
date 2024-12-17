#include <iostream>

struct TrafficLight {
    bool red_on = true;
    bool yellow_on = false;
    bool green_on = false;
    // marked const because it doesn't change the data
    void print_traffic_light() const {
        std::cout << (red_on ? "R" : " ") << (yellow_on ? "Y":" ") << (green_on ? "G" : "") <<  std::endl;
    }
};


int main() {
    // Red is the default state
    TrafficLight traffic_light;
    traffic_light.print_traffic_light();

    // Turn on yellow light
    traffic_light.yellow_on = true;
    traffic_light.print_traffic_light();

    // Now we are green, turn off red and yellow and turn on green
    traffic_light.red_on = false;
    traffic_light.yellow_on = false;
    traffic_light.green_on = true;
    traffic_light.print_traffic_light();

    // Next turn on only yellow
    traffic_light.green_on = false;
    traffic_light.yellow_on = true;
    traffic_light.print_traffic_light();

    // Next turn on only red and we're beack
    traffic_light.red_on = true;
    traffic_light.yellow_on = false;
    traffic_light.print_traffic_light();
}
