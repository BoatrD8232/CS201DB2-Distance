//Name: David Boatright
//Program 3- Distance
//Takes in or generates 2 points, then calculates the distance to the origin for those points.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    srand(time(0));
    // The number of points that will be entered/generated.
    const int numPoints = 2;
    // The number of coordinates that each point has. Exists only to avoid magic numbers.
    const int coord = 2;
    // The user inputted coordinates stored as a string and integer
    string inputCoordString;
    int inputCoordInt;
    // Stores a number of points, each with an x and y coordinate.
    int points[numPoints][coord];
    // Stores each points' distance to the origin. Is a parallel array to the points list.
    float distList[numPoints];
    // contChoice- controls the outer while loop.
    // genChoice- stores if the users want to enter their own numbers.
    // isValidInput- stores the result of the user input error checking.
    char contChoice = 'Y', genChoice = 'Y', isValidInput = 'N';

    // The outer loop controls if the whole program runs multiple times.
    while (toupper(contChoice) != 'N') {
        // Asks the user if they wish to generate their own numbers.
        cout << "Enter your own numbers? Enter Y to enter your own, "
            << "enter anything else to generate the numbers randomly : ";
        cin >> genChoice;
        // Controls if the numbers are user or computer generated.
        if (toupper(genChoice) == 'Y') {
            // Loops through the array of points.
            for (int i = 0; i < numPoints; i++) {
                for (int j = 0; j < coord; j++) {
                    // Loops until valid input is entered.
                    while (isValidInput != 'Y') {
                        // Takes input as string, tries to convert to int, throws exceptions if
                        // conversion fails or the number is out of range
                        try {
                            cout << "Enter Point " << i + 1 << ", Coordinate "
                                 << j + 1 << ":" << endl;
                            cout << "Input a number between -10 and 10 (Inclusive):"
                                 << endl;
                            cin >> inputCoordString;
                            inputCoordInt = stoi(inputCoordString);
                            if (inputCoordInt < -10 || inputCoordInt > 10) {
                                throw ("Invalid value");
                            }
                            // Sets the loop to exit. Only executed if no errors.
                            isValidInput = 'Y';
                        }
                        catch (...) {
                            // Alerts the user of an error.
                            cout << "Invalid Input!" << endl;
                        }
                    }
                    // Inputs data into points array, reprimes the input while loop for next iteration.
                    points[i][j] = inputCoordInt;
                    isValidInput = 'N';
                }

            }
        }
        // Populates the points array with random numbers in the range.
        else {
            for (int i = 0; i < numPoints; i++) {
                for (int j = 0; j < coord; j++) {
                    points[i][j] = rand() % 21 - 10;
                }
            }
        }

        // Stores the index of the point closest to the origin.
        int closestIndex = 0;

        for (int i = 0; i < numPoints; i++) {
            // Calculates the distance of the point to the origin, puts it in the array.
            distList[i] = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            // Displays the points' location and distance to the origin.
            cout << "Point " << i + 1 << " is located at (" << points[i][0]
                << ", " << points[i][1] << ")" << endl;
            cout << fixed << setprecision(2) << "The distance to the origin is "
                << distList[i] << endl;
            // Keeps track of the point with the smallest distance.
            if (distList[i] < distList[closestIndex]) {
                closestIndex = i;
            }
        }

        // Displays the point with the shortest distance to the origin.
        cout << "Point " << closestIndex + 1 << " is the closest to the origin, located at ("
            << points[closestIndex][0] << ", " << points[closestIndex][1] << ")" << endl;
        // Allows the user to run the program again.
        cout << "Generate another pair of points? (y/n)" << endl;
        cin >> contChoice;
        cout << endl;
    }
}
