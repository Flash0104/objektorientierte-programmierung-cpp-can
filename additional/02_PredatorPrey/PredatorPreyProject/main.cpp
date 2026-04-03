#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

struct PopulationState {
    double prey;
    double predator;
};

class LotkaVolterra {
private:
    // Parameters from the equations
    double epsilon1;  // ε₁ > 0 Reproduction rate of prey
    double gamma1;    // γ₁ > 0 Death rate of prey (starvation or hunters)
    double epsilon2;  // ε₂ > 0 Death rate of hunters (no prey)
    double gamma2;    // γ₂ > 0 Reproduction rate of hunter, if prey
    
    double dt;        // Time step
    int time_steps;
    
public:
    LotkaVolterra(double e1 = 0.5, double g1 = 0.1, double e2 = 0.3, double g2 = 0.1, 
                  double time_step = 0.01, int steps = 10000)
        : epsilon1(e1), gamma1(g1), epsilon2(e2), gamma2(g2), dt(time_step), time_steps(steps) {}
    
    // dPrey/dt = Prey(ε₁ - γ₁Hunter)
    double preyDerivative(double prey, double predator) {
        return prey * (epsilon1 - gamma1 * predator);
    }
    
    // dHunter/dt = -Hunter(ε₂ - γ₂Prey)
    double predatorDerivative(double prey, double predator) {
        return -predator * (epsilon2 - gamma2 * prey);
    }
    
    std::vector<PopulationState> simulate(double initial_prey, double initial_predator) {
        std::vector<PopulationState> results;
        
        double prey = initial_prey;
        double predator = initial_predator;
        
        for (int i = 0; i < time_steps; i++) {
            results.push_back({prey, predator});
            
            // Euler's method for numerical integration
            double dprey = preyDerivative(prey, predator);
            double dpredator = predatorDerivative(prey, predator);
            
            prey += dprey * dt;
            predator += dpredator * dt;
            
            // Prevent negative populations
            if (prey < 0) prey = 0;
            if (predator < 0) predator = 0;
        }
        
        return results;
    }
    
    void saveToCSV(const std::vector<PopulationState>& data, const std::string& filename) {
        std::ofstream file(filename);
        file << "Time,Prey,Predator\n";
        
        for (int i = 0; i < data.size(); i++) {
            file << i * dt << "," << data[i].prey << "," << data[i].predator << "\n";
        }
        
        file.close();
    }
    
    void saveToSVG(const std::vector<PopulationState>& data, const std::string& filename) {
        std::ofstream file(filename);
        
        // Find max values for scaling
        double max_prey = 0, max_predator = 0;
        for (const auto& state : data) {
            if (state.prey > max_prey) max_prey = state.prey;
            if (state.predator > max_predator) max_predator = state.predator;
        }
        
        int width = 1000, height = 600;
        double scale_prey = height * 0.8 / max_prey;
        double scale_predator = height * 0.8 / max_predator;
        
        file << "<svg xmlns='http://www.w3.org/2000/svg' width='" << width << "' height='" << height << "'>\n";
        file << "<rect width='100%' height='100%' fill='white'/>\n";
        
        // Draw axes
        file << "<line x1='50' y1='" << height - 50 << "' x2='" << width - 50 << "' y2='" << height - 50 << "' stroke='black' stroke-width='2'/>\n";
        file << "<line x1='50' y1='50' x2='50' y2='" << height - 50 << "' stroke='black' stroke-width='2'/>\n";
        
        // Draw prey population (green)
        file << "<polyline points='";
        for (int i = 0; i < data.size(); i++) {
            double x = 50 + (double)i / data.size() * (width - 100);
            double y = height - 50 - data[i].prey * scale_prey;
            file << x << "," << y << " ";
        }
        file << "' stroke='green' fill='none' stroke-width='2'/>\n";
        
        // Draw predator population (red)
        file << "<polyline points='";
        for (int i = 0; i < data.size(); i++) {
            double x = 50 + (double)i / data.size() * (width - 100);
            double y = height - 50 - data[i].predator * scale_predator;
            file << x << "," << y << " ";
        }
        file << "' stroke='red' fill='none' stroke-width='2'/>\n";
        
        // Labels
        file << "<text x='" << width/2 << "' y='" << height - 20 << "' text-anchor='middle' font-family='Arial' font-size='14'>Time</text>\n";
        file << "<text x='20' y='" << height/2 << "' text-anchor='middle' font-family='Arial' font-size='14' transform='rotate(-90, 20, " << height/2 << ")'>Population</text>\n";
        file << "<text x='" << width - 100 << "' y='30' font-family='Arial' font-size='12' fill='green'>Prey</text>\n";
        file << "<text x='" << width - 100 << "' y='50' font-family='Arial' font-size='12' fill='red'>Predator</text>\n";
        
        file << "</svg>\n";
        file.close();
    }
    
    void printParameters() {
        std::cout << "Lotka-Volterra Parameters:" << std::endl;
        std::cout << "ε₁ (Prey reproduction rate): " << epsilon1 << std::endl;
        std::cout << "γ₁ (Prey death rate): " << gamma1 << std::endl;
        std::cout << "ε₂ (Predator death rate): " << epsilon2 << std::endl;
        std::cout << "γ₂ (Predator reproduction rate): " << gamma2 << std::endl;
        std::cout << "Time step: " << dt << std::endl;
        std::cout << "Total time steps: " << time_steps << std::endl;
    }
};

int main() {
    std::cout << "=== Hunter and Prey Game (Lotka-Volterra Model) ===" << std::endl;
    
    // Create simulation with realistic parameters
    LotkaVolterra simulation(0.5, 0.1, 0.3, 0.1, 0.01, 10000);
    simulation.printParameters();
    
    std::cout << "\nStarting simulation..." << std::endl;
    
    // Initial populations
    double initial_prey = 10.0;
    double initial_predator = 5.0;
    
    std::cout << "Initial populations:" << std::endl;
    std::cout << "Prey: " << initial_prey << std::endl;
    std::cout << "Predator: " << initial_predator << std::endl;
    
    // Run simulation
    auto results = simulation.simulate(initial_prey, initial_predator);
    
    // Save results
    std::cout << "\nSaving results..." << std::endl;
    simulation.saveToCSV(results, "predator_prey.csv");
    simulation.saveToSVG(results, "predator_prey.svg");
    
    // Print some statistics
    std::cout << "\nSimulation completed!" << std::endl;
    std::cout << "Total time steps: " << results.size() << std::endl;
    std::cout << "Final populations:" << std::endl;
    std::cout << "Prey: " << results.back().prey << std::endl;
    std::cout << "Predator: " << results.back().predator << std::endl;
    
    std::cout << "\nFiles created:" << std::endl;
    std::cout << "- predator_prey.csv (data)" << std::endl;
    std::cout << "- predator_prey.svg (visualization)" << std::endl;
    
    return 0;
}
