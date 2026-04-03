#include <iostream>

class TrafficLight {
private:
  bool red_on = true;
  bool yellow_on = false;
  bool green_on = false;

  enum class Phase { Red, RedYellow, Green, Yellow };

  Phase current_phase = Phase::Red;

public:
  // marked const because it doesn't change the data
  void print_traffic_light() const {
    std::cout << (red_on ? "R" : " ") << (yellow_on ? "Y" : " ")
              << (green_on ? "G" : "") << std::endl;
  }

  void next() {
    switch (current_phase) {
    case Phase::Red:
      // Switch to Red-Yellow
      yellow_on = true;
      current_phase = Phase::RedYellow;
      break;
    case Phase::RedYellow:
      // Switch to Green
      red_on = false;
      yellow_on = false;
      green_on = true;
      current_phase = Phase::Green;
      break;
    case Phase::Green:
      // Switch to Yellow
      green_on = false;
      yellow_on = true;
      current_phase = Phase::Yellow;
      break;
    case Phase::Yellow:
      // Switch to Red
      yellow_on = false;
      red_on = true;
      current_phase = Phase::Red;
      break;
    }
  }
};

int main() {
  TrafficLight traffic_light;
  traffic_light.print_traffic_light();

  // Cycle through states: Red (start) -> RedYellow -> Green -> Yellow -> Red
  for (int i = 0; i < 4; ++i) {
    traffic_light.next();
    traffic_light.print_traffic_light();
  }
}
