# Space Mining Simulator (C++)
A console-based simulator I built in C++ to model the logistics and economics of space mining. The goal of the project was to calculate whether sending a specific rocket to an asteroid is actually profitable after factoring in fuel costs, cargo limits, and dynamic market prices.

## Technologies & Concepts
Language: C++

Core Tools: STL (std::vector, std::map, std::sort)

OOP Architecture: I separated the entities into distinct classes (Rockets, Asteroids, Market, Mission) to keep the simulation logic clean.

Custom Sorting: Used lambda expressions with std::sort to rank rockets based on their calculated efficiency score.

## How the Simulation Works
The profitability of a mission isn't static. The simulator applies the following rules:

Cargo vs. Yield: A rocket can only extract what it can carry, limited by its extraction yield and the actual remaining stock on the targeted asteroid.

Fuel Costs: Calculating the round-trip fuel consumption based on the asteroid's distance and the specific fuel efficiency of the rocket used.

Dynamic Market (Supply & Demand): As a resource is mined and brought back, the market becomes saturated. The selling price drops dynamically, stopping only at a hardcoded base price.

## Biggest Challenges
Parsing multiple .csv files in pure C++ (without external libraries) was trickier than expected. I had to build a custom file I/O parser to extract and validate the data for the rockets, asteroids, and market prices before feeding it into the simulation loop.
