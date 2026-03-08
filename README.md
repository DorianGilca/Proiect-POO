 Space Mining Simulator

This is an Object-Oriented C++ console application that simulates the profitability of space mining missions. The program processes data about rocket fleets, celestial bodies, and resource market fluctuations to determine the efficiency and financial success of each mission.

## Technologies Used
* Language: C++
* Core Libraries: Standard Template Library (STL)

## Technical Concepts Applied
* Object-Oriented Programming (OOP): The data and business logic are encapsulated in specific, separated classes (Rockets, Asteroids, Market, Mission).
* File I/O & CSV Parsing: The application reads input data from multiple `.csv` files, processes the information, and exports the final results to a structured CSV report.
* Data Structures: Extensive use of `std::vector` for object storage and `std::map` for tracking resource quantities and cumulative profits.
* Algorithms & Lambda Expressions: Used `std::sort` alongside a custom lambda function to dynamically calculate and rank the efficiency score of each rocket.

## Simulation Business Logic
The system calculates mission profitability based on the following rules:
1. Extracted quantity: Limited by the rocket's cargo capacity, the specific extraction yield, and the remaining stock on the targeted asteroid.
2. Fuel consumption: Calculated for a round-trip, factoring in the asteroid's distance and the specific fuel efficiency and cost of each rocket.
3. Market fluctuation (Supply & Demand): The selling price of a mined resource drops dynamically as the market becomes saturated, without falling below a predefined base price.

## How to run
 Compile the `.cpp` source files using a standard C++ compiler (e.g., GCC/MinGW). Also, run the resulting executable from the command line, providing the three initial database files as arguments: `./simulator rachete.csv asteroizi.csv piata.csv`
