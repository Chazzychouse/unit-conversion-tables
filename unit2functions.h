#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

double convertFeetToInches(double), convertFeetToMeters(double), convertFeetToKilometers(double), convertFeetToYards(double),
    convertFeetToMillimeters(double), convertInchesToFeet(double), convertInchesToMillimeters(double), convertInchesToYards(double),
    convertInchesToKilometers(double), convertInchesToMeters(double), convertYardsToFeet(double), convertYardsToInches(double),
    convertYardsToInches(double), convertYardsToMillimeters(double), convertYardsToKilometers(double), convertYardsToMeters(double),
    convertKilometersToFeet(double), convertKilometersToInches(double), convertKilometersToMillimeters(double), convertKilometersToYards(double),
    convertKilometersToMeters(double), convertMetersToFeet(double), convertMetersToInches(double), convertMetersToMillimeters(double),
    convertMetersToYards(double), convertMetersToKilometers(double), getStartingValue(), getEndingValue(), getValueIncrement();
double getConvertedValue(double, int, int), convertMillimetersToFeet(double), convertMillimetersToInches(double), convertMillimetersToYards(double),
    convertMillimetersToKilometers(double), convertMillimetersToMeters(double), convertMetersPerSecondToMilesPerHour(double),
    convertMetersPerSecondToKilometersPerHour(double), convertMilesPerHourToMetersPerSecond(double), convertMilesPerHourToKilometersPerHour(double),
    convertKilometersPerHourToMetersPerSecond(double), convertKilometersPerHourToMilesPerHour(double),
    convertGramsPerCentimeterToKilogramsPerMeter(double), convertGramsPerCentimeterToSlugsPerFeet(double),
    convertKilogramsPerMeterToGramsPerCentimeter(double), convertKilogramsPerMeterToSlugsPerFeet(double),
    convertSlugsPerFeetToGramsPerCentimeter(double), convertSlugsPerFeetToKilogramsPerMeter(double), convertNewtonMetersToFootPounds(double),
    convertNewtonMetersToOunceInches(double), convertFootPoundsToNewtonMeters(double), convertFootPoundsToOunceInches(double),
    convertOunceInchesToNewtonMeters(double), convertOunceInchesToFootPounds(double), convertHorsePowerToWatts(double),
    convertHorsePowerToKiloWatts(double), convertHorsePowerToBritishThermal(double), convertWattsToHorsePower(double),
    convertWattsToKiloWatts(double), convertWattsToBritishThermal(double), convertKiloWattsToHorsePower(double), convertKiloWattsToWatts(double),
    convertKiloWattsToBritishThermal(double), convertBritishThermalToHorsePower(double), convertBrithishThermalToWatts(double),
    convertBritishThermalToKiloWatts(double), converKiloPascalsToPoundsPerSquareInch(double), convertKiloPascalsToMillimetersMercury(double),
    convertPoundsPerSquareInchToKiloPascals(double), convertPoundsPerSquareInchToMillimetersMercury(double),
    convertMillimetersMercuryToKiloPascals(double), convertMillimetersMercuryToPoundsPerSquareInch(double), testForEquivalentValues(double, double), testForValidRowCount(double, double, double);
bool isUserUnitFeet(string), isUserUnitInch(string), isUserUnitMillimeter(string), isUserUnitYard(string), isUserUnitKilometer(string),
    isUserUnitMeter(string), isUserUnitNewtonMeters(string), isUserUnitFootPounds(string), isUserUnitOunceInches(string),
    isUserUnitBritishThermal(string), isUserUnitHorsePower(string), isUserUnitWatts(string), isUserUnitKiloWatts(string),
    isUserUnitKiloPascals(string), isUserUnitPoundsPerSquare(string), isUserUnitMillimetersMercury(string);

string convertStringToLower(string), getStringFromLengthUnit(int), getStringFromSpeedUnit(int), getStringFromDensityUnit(int),
    getStringFromTorqueUnit(int), getStringFromPowerUnit(int), getStringFromPressureUnit(int);
void outputInvalidLengthPrompt(), outputInvalidDimensionPrompt(), outputInvalidSpeedPrompt(), outputInvalidDensityPrompt(),
    outputInvalidTorquePrompt(), outputInvalidPowerPrompt(), outputInvalidPressurePrompt();
int getLengthUnitFromUserInput(), getSpeedUnitFromUserInput(), getDensityUnitFromUserInput(), getTorqueUnitFromUserInput(),
    getPowerUnitFromUserInput(), getPressureUnitFromUserInput(), getInitialPrecision(), getFinalPrecision();
int getIntFromDimensionString(string), getValidDimensionFromInput(), getIntFromLengthString(string), getIntFromSpeedString(string),
    getIntFromDensityString(string), getIntFromTorqueString(string), getIntFromPowerString(string), getIntFromPressureString(string);

//using constants to prevent user input type errors
int const LENGTH = 1, SPEED = 2, DENSITY = 3, TORQUE = 4, POWER = 5, PRESSURE = 6;
int const FEET = 11, INCH = 12, MILLIMETER = 13, YARD = 14, KILOMETER = 15, METER = 16;
int const METERPERSECOND = 21, MILEPERHOUR = 22, KMPERHOUR = 23;
int const GRAMPERCMCUBED = 31, KGPERMETERCUBED = 32, SLUGPERFEETCUBED = 33;
int const NEWTONMETER = 41, FOOTPOUND = 42, OUNCEINCH = 43;
int const HORSEPOWER = 51, WATT = 52, KILOWATT = 53, BRITISHTHERMAL = 54;
int const KILOPASCAL = 61, POUNDSPERSQUARE = 62, MILLIMETERSMERCURY = 63;

