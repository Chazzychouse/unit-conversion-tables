//       ____   __     __
//        /   /   \  /   \
//       /   /      /
//      /    \___/  \___/
//
// Date: 3/10/2022
// Name: Chase R. Cartwright
// Project: Unit Project 2
// Inputs: dimension string, starting unit string, ending unit string, starting value, ending value, increment, initial precision, final precision
// Outputs: table, input prompts, error messages.
// Program Description: output a user defined table of unit conversions with some constraints

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include "unit2functions.h"
using namespace std;

//the flow of each switch case is identical. All notation for the switch structure will be in the first case (length)
int main() {
  int reRunProgram; //sentinel is outside scope of switch but inside main
  //dowhile allows user to rerun the program
  do {
  int choiceDimensionInt = getValidDimensionFromInput();
  switch (choiceDimensionInt) { //switch structure used with each dimension as a case

  case LENGTH: {
    cout << "Input a length unit to be converted" << endl;
    int initialLengthUnit = getLengthUnitFromUserInput(); //user string will be assigned an integer value
    while (initialLengthUnit == 0) {
      outputInvalidLengthPrompt();
      initialLengthUnit = getLengthUnitFromUserInput();
    }

    cout << "Input the unit of conversion factor" << endl;
    int finalLengthUnit = getLengthUnitFromUserInput(); //user string will be assigned an integer value
    while (finalLengthUnit == 0 || finalLengthUnit == initialLengthUnit) {
      cout << "Invalid conversion unit. End unit cannot equal starting unit." << endl;
      cout << "Input the unit of conversion factor" << endl;
      finalLengthUnit = getLengthUnitFromUserInput();
    }

    double startingValue = getStartingValue(); //output prompts and user inputs for start value, end value, and increment
    double endingValue = getEndingValue();
    double valueIncrement = getValueIncrement();

    endingValue = testForEquivalentValues(startingValue, endingValue); //test for equivalent values. Returns new ending value input if fails
    valueIncrement = testForValidRowCount(startingValue, endingValue, valueIncrement); //test for 3 or more rows but no more than 25. returns new increment if fails

    int initialPrecision = getInitialPrecision();
    int finalPrecision = getFinalPrecision();

    string tableUnitStart = getStringFromLengthUnit(initialLengthUnit); //assigns a string for the table symbol based on integer value
    string tableUnitEnd = getStringFromLengthUnit(finalLengthUnit);

    cout << "              LENGTH                " << endl;
    cout << fixed << right << setw(11) << tableUnitStart << "       |" << setw(11) << tableUnitEnd << endl;
    //loop to format a table.  not a function
    for (int rowCount = 0; startingValue + (rowCount * valueIncrement) < endingValue; rowCount++) {
      double leftValue = startingValue + (rowCount * valueIncrement);
      double rightValue = getConvertedValue(leftValue, initialLengthUnit, finalLengthUnit); //getConvertedValue handles all possible valid conversions
      cout << fixed << right << setw(11) << setprecision(initialPrecision) << leftValue << "       |" << setw(11) << setprecision(finalPrecision)
           << rightValue << endl;
    }
    break;
  }
  case SPEED: {
    cout << "Input a speed unit to be converted" << endl;
    int initialSpeedUnit = getSpeedUnitFromUserInput();
    while (initialSpeedUnit == 0) {
      outputInvalidSpeedPrompt();
      initialSpeedUnit = getSpeedUnitFromUserInput();
    }

    cout << "Input the unit of conversion factor" << endl;
    int finalSpeedUnit = getSpeedUnitFromUserInput();
    while (finalSpeedUnit == 0 || finalSpeedUnit == initialSpeedUnit) {
      cout << "Invalid conversion unit. End unit cannot equal starting unit." << endl;
      cout << "Input the unit of conversion factor" << endl;
      finalSpeedUnit = getSpeedUnitFromUserInput();
    }

    double startingValue = getStartingValue();
    double endingValue = getEndingValue();
    double valueIncrement = getValueIncrement();

    endingValue = testForEquivalentValues(startingValue, endingValue);
    valueIncrement = testForValidRowCount(startingValue, endingValue, valueIncrement);

    int initialPrecision = getInitialPrecision();
    int finalPrecision = getFinalPrecision();

    string tableUnitStart = getStringFromSpeedUnit(initialSpeedUnit);
    string tableUnitEnd = getStringFromSpeedUnit(finalSpeedUnit);

    cout << "              SPEED              " << endl;
    cout << fixed << right << setw(11) << tableUnitStart << "       |" << setw(11) << tableUnitEnd << endl;

    for (int rowCount = 0; startingValue + (rowCount * valueIncrement) < endingValue; rowCount++) {
      double leftValue = startingValue + (rowCount * valueIncrement);
      double rightValue = getConvertedValue(leftValue, initialSpeedUnit, finalSpeedUnit);
      cout << fixed << right << setw(11) << setprecision(initialPrecision) << leftValue << "       |" << setw(11) << setprecision(finalPrecision)
           << rightValue << endl;
    }
    break;
  }
  case DENSITY: {
    cout << "Input a density unit to be converted" << endl;
    int initialDensityUnit = getDensityUnitFromUserInput();
    while (initialDensityUnit == 0) {
      outputInvalidDensityPrompt();
      initialDensityUnit = getDensityUnitFromUserInput();
    }

    cout << "Input the unit of conversion factor" << endl;
    int finalDensityUnit = getDensityUnitFromUserInput();
    while (finalDensityUnit == 0 || finalDensityUnit == initialDensityUnit) {
      cout << "Invalid conversion unit. End unit cannot equal starting unit." << endl;
      cout << "Input the unit of conversion factor" << endl;
      finalDensityUnit = getDensityUnitFromUserInput();
    }
    double startingValue = getStartingValue();
    double endingValue = getEndingValue();
    double valueIncrement = getValueIncrement();

    endingValue = testForEquivalentValues(startingValue, endingValue);
    valueIncrement = testForValidRowCount(startingValue, endingValue, valueIncrement);

    int initialPrecision = getInitialPrecision();
    int finalPrecision = getFinalPrecision();
    string tableUnitStart = getStringFromDensityUnit(initialDensityUnit);
    string tableUnitEnd = getStringFromDensityUnit(finalDensityUnit);

    cout << "              DENSITY              " << endl;
    cout << fixed << right << setw(11) << tableUnitStart << "       |" << setw(11) << tableUnitEnd << endl;

    for (int rowCount = 0; startingValue + (rowCount * valueIncrement) < endingValue; rowCount++) {
      double leftValue = startingValue + (rowCount * valueIncrement);
      double rightValue = getConvertedValue(leftValue, initialDensityUnit, finalDensityUnit);
      cout << fixed << right << setw(11) << setprecision(initialPrecision) << leftValue << "       |" << setw(11) << setprecision(finalPrecision)
           << rightValue << endl;
    }
    break;
  }
  case TORQUE: {
    cout << "Input a torque unit to be converted" << endl;
    int initialTorqueUnit = getTorqueUnitFromUserInput();
    while (initialTorqueUnit == 0) {
      outputInvalidTorquePrompt();
      initialTorqueUnit = getTorqueUnitFromUserInput();
    }

    cout << "Input the unit of conversion factor" << endl;
    int finalTorqueUnit = getTorqueUnitFromUserInput();
    while (finalTorqueUnit == 0 || finalTorqueUnit == initialTorqueUnit) {
      cout << "Invalid conversion unit. End unit cannot equal starting unit." << endl;
      cout << "Input the unit of conversion factor" << endl;
      finalTorqueUnit = getTorqueUnitFromUserInput();
    }

    double startingValue = getStartingValue();
    double endingValue = getEndingValue();
    double valueIncrement = getValueIncrement();

    endingValue = testForEquivalentValues(startingValue, endingValue);
    valueIncrement = testForValidRowCount(startingValue, endingValue, valueIncrement);

    int initialPrecision = getInitialPrecision();
    int finalPrecision = getFinalPrecision();

    string tableUnitStart = getStringFromTorqueUnit(initialTorqueUnit);
    string tableUnitEnd = getStringFromTorqueUnit(finalTorqueUnit);

    cout << "               TORQUE               " << endl;
    cout << fixed << right << setw(11) << tableUnitStart << "       |" << setw(11) << tableUnitEnd << endl;

    for (int rowCount = 0; startingValue + (rowCount * valueIncrement) < endingValue; rowCount++) {
      double leftValue = startingValue + (rowCount * valueIncrement);
      double rightValue = getConvertedValue(leftValue, initialTorqueUnit, finalTorqueUnit);
      cout << fixed << right << setw(11) << setprecision(initialPrecision) << leftValue << "       |" << setw(11) << setprecision(finalPrecision)
           << rightValue << endl;
    }
    break;
  }

  case POWER: {
    cout << "Input a power unit to be converted" << endl;
    int initialPowerUnit = getPowerUnitFromUserInput();
    while (initialPowerUnit == 0) {
      outputInvalidPowerPrompt();
      initialPowerUnit = getPowerUnitFromUserInput();
    }

    cout << "Input the unit of conversion factor" << endl;
    int finalPowerUnit = getPowerUnitFromUserInput();
    while (finalPowerUnit == 0 || finalPowerUnit == initialPowerUnit) {
      cout << "Invalid conversion unit. End unit cannot equal starting unit." << endl;
      cout << "Input the unit of conversion factor" << endl;
      finalPowerUnit = getPowerUnitFromUserInput();
    }

    double startingValue = getStartingValue();
    double endingValue = getEndingValue();
    double valueIncrement = getValueIncrement();

    endingValue = testForEquivalentValues(startingValue, endingValue);
    valueIncrement = testForValidRowCount(startingValue, endingValue, valueIncrement);

    int initialPrecision = getInitialPrecision();
    int finalPrecision = getFinalPrecision();

    string tableUnitStart = getStringFromPowerUnit(initialPowerUnit);
    string tableUnitEnd = getStringFromPowerUnit(finalPowerUnit);

    cout << "               POWER               " << endl;
    cout << fixed << right << setw(11) << tableUnitStart << "       |" << setw(11) << tableUnitEnd << endl;

    for (int rowCount = 0; startingValue + (rowCount * valueIncrement) < endingValue; rowCount++) {
      double leftValue = startingValue + (rowCount * valueIncrement);
      double rightValue = getConvertedValue(leftValue, initialPowerUnit, finalPowerUnit);
      cout << fixed << right << setw(11) << setprecision(initialPrecision) << leftValue << "       |" << setw(11) << setprecision(finalPrecision)
           << rightValue << endl;
    }
    break;
  }
  case PRESSURE: {
    cout << "Input a pressure unit to be converted" << endl;
    int initialPressureUnit = getPressureUnitFromUserInput();
    while (initialPressureUnit == 0) {
      outputInvalidPressurePrompt();
      initialPressureUnit = getPressureUnitFromUserInput();
    }

    cout << "Input the unit of conversion factor" << endl;
    int finalPressureUnit = getPressureUnitFromUserInput();
    while (finalPressureUnit == 0 || finalPressureUnit == initialPressureUnit) {
      cout << "Invalid conversion unit. End unit cannot equal starting unit." << endl;
      cout << "Input the unit of conversion factor" << endl;
      finalPressureUnit = getPressureUnitFromUserInput();
    }

    double startingValue = getStartingValue();
    double endingValue = getEndingValue();
    double valueIncrement = getValueIncrement();

    endingValue = testForEquivalentValues(startingValue, endingValue);
    valueIncrement = testForValidRowCount(startingValue, endingValue, valueIncrement);

    int initialPrecision = getInitialPrecision();
    int finalPrecision = getFinalPrecision();

    string tableUnitStart = getStringFromPressureUnit(initialPressureUnit);
    string tableUnitEnd = getStringFromPressureUnit(finalPressureUnit);

    cout << "               PRESSURE               " << endl;
    cout << fixed << right << setw(11) << tableUnitStart << "       |" << setw(11) << tableUnitEnd << endl;

    for (int rowCount = 0; startingValue + (rowCount * valueIncrement) < endingValue; rowCount++) {
      double leftValue = startingValue + (rowCount * valueIncrement);
      double rightValue = getConvertedValue(leftValue, initialPressureUnit, finalPressureUnit);
      cout << fixed << right << setw(11) << setprecision(initialPrecision) << leftValue << "       |" << setw(11) << setprecision(finalPrecision)
           << rightValue << endl;
    }
    break;
  }
  }
  cout << "Would you like to run the program again? 1)yes 2)no" << endl;
  cin >> reRunProgram;
  cin.ignore();
}
while (reRunProgram == 1); //exit condition. stop program 
}

