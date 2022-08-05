#include<string>
#include<iostream>
using namespace std;

int const LENGTH = 1, SPEED = 2, DENSITY = 3, TORQUE = 4, POWER = 5, PRESSURE = 6;
int const FEET = 11, INCH = 12, MILLIMETER = 13, YARD = 14, KILOMETER = 15, METER = 16;
int const METERPERSECOND = 21, MILEPERHOUR = 22, KMPERHOUR = 23;
int const GRAMPERCMCUBED = 31, KGPERMETERCUBED = 32, SLUGPERFEETCUBED = 33;
int const NEWTONMETER = 41, FOOTPOUND = 42, OUNCEINCH = 43;
int const HORSEPOWER = 51, WATT = 52, KILOWATT = 53, BRITISHTHERMAL = 54;
int const KILOPASCAL = 61, POUNDSPERSQUARE = 62, MILLIMETERSMERCURY = 63;

//all bools check that user input strings are valid for our program
bool isUserUnitFeet(string unit) { return (unit == "feet" || unit == "ft"); }

bool isUserUnitInch(string unit) { return (unit == "inch" || unit == "inches" || unit == "in"); }

bool isUserUnitMillimeter(string unit) { return (unit == "millimeter" || unit == "millimeters" || unit == "mm"); }

bool isUserUnitYard(string unit) { return (unit == "yards" || unit == "yard" || unit == "yd"); }

bool isUserUnitKilometer(string unit) { return (unit == "kilometer" || unit == "kilometers" || unit == "km"); }

bool isUserUnitMeter(string unit) { return (unit == "meter" || unit == "meters" || unit == "m"); }

bool isUserUnitMetersPerSecond(string unit) { return (unit == "meters per second" || unit == "meter per second" || unit == "m/s"); }

bool isUserUnitMilesPerHour(string unit) { return (unit == "miles per hour" || unit == "mile per hour" || unit == "mi/hr"); }

bool isUserUnitKilometersPerHour(string unit) { return (unit == "kilometers per hour" || unit == "kilometer per hour" || unit == "km/hr"); }

bool isUserUnitHorsePower(string unit) { return (unit == "horsepower" || unit == "horse power" || unit == "horsepowers" || unit == "hp"); }

bool isUserUnitWatts(string unit) { return (unit == "watts" || unit == "watt" || unit == "w"); }

bool isUserUnitKiloWatts(string unit) { return (unit == "kilowatts" || unit == "kilowatt" || unit == "kw"); }

bool isUserUnitBritishThermal(string unit) { return (unit == "british thermal units" || unit == "british thermal unit" || unit == "btu"); }

bool isUserUnitGramsPerCentimeterCubed(string unit) {
  return (unit == "grams per centimeter cubed" || unit == "g/cm^3" || unit == "gram per centimeter cubed" || unit == "grams per centimeters cubed" ||
          unit == "gram per centimeters cubed");
}

bool isUserUnitKilogramsPerMeterCubed(string unit) {
  return (unit == "kilograms per meter cubed" || unit == "kg/m^3" || unit == "kilogram per meter cubed" || unit == "kilograms per meters cubed" ||
          unit == "kilogram per meters cubed");
}

bool isUserUnitSlugsPerFeetCubed(string unit) {
  return (unit == "slugs per foot cubed" || unit == "slug/ft^3" || unit == "slug per foot cubed" || unit == "slugs per feet cubed" ||
          unit == "slug per feet cubed");
}

bool isUserUnitNewtonMeters(string unit) { return (unit == "newton meters" || unit == "newton meter" || unit == "n-m"); }

bool isUserUnitFootPounds(string unit) {
  return (unit == "foot pounds" || unit == "foot pound" || unit == "feet pound" || unit == "feet pounds" || unit == "ft-lb");
}

bool isUserUnitOunceInches(string unit) { return (unit == "ounce inches" || unit == "ounce inch" || unit == "oz-in"); }

bool isUserUnitKiloPascals(string unit) { return (unit == "kilopascals" || unit == "kilopascal" || unit == "kpa"); }

bool isUserUnitPoundsPerSquare(string unit) {
  return (unit == "pounds per square inch" || unit == "pound per square inch" || unit == "pound per square inches" ||
          unit == "pounds per square inches" || unit == "psi");
}

bool isUserUnitMillimetersMercury(string unit) {
  return (unit == "millimeters mercury" || unit == "millimeters of mercury" || unit == "millimeter mercury" || unit == "mmhg");
}

//convert user string input to lowercase to simplify validity tests
string convertStringToLower(string unit) {

  for (int elementCount = 0; elementCount < unit.length(); elementCount++) {
    unit[elementCount] = tolower(unit[elementCount]);
  }
  return unit;
}

//invalid user input prompts that specify valid inputs
void outputInvalidLengthPrompt() {
  cout << "Invalid unit. See below accepted unit choices:" << endl;
  cout << "feet(ft), inch(in), inches(in), millimeter(mm), millimeters(mm)" << endl
       << "yard(yd), yards(yd), kilometer(km), kilometers(km)" << endl
       << "meter(m), meters(m)" << endl;
  cout << "Input a length unit to be converted" << endl;
}

void outputInvalidSpeedPrompt() {
  cout << "Invalid unit. See below accepted unit choices:" << endl;
  cout << "meters per second(m/s), miles per hour (mi/hr), kilometers per hour(km/hr)" << endl;
  cout << "Input a speed unit to be converted" << endl;
}

void outputInvalidDimensionPrompt() {
  cout << "\nInvalid dimension: " << endl;
  cout << "Enter a dimension to convert: ";
  cout << "\nLength  Speed  Density  Torque  Power  Pressure " << endl;
}

void outputInvalidDensityPrompt() {
  cout << "Invalid unit. See below accepted unit choices:" << endl;
  cout << "grams per centimeter cubed (g/cm^3), kilograms per meter cubed (kg/m^3), slugs per feet cubed (slug/ft^3)" << endl;
  cout << "Input a speed unit to be converted" << endl;
}

void outputInvalidTorquePrompt() {
  cout << "Invalid unit. See below accepted unit choices:" << endl;
  cout << "ounce inches(oz-in), foot pounds(ft-lb), Newton meters(N-m)" << endl;
  cout << "Input a Torque unit to be converted" << endl;
}

void outputInvalidPowerPrompt() {
  cout << "Invalid unit. See below accepted unit choices:" << endl;
  cout << "horsepower(hp), watts(W), kilowatts(kW), british thermal units(BTU)" << endl;
  cout << "Input a power unit to be converted" << endl;
}

void outputInvalidPressurePrompt() {
  cout << "Invalid unit. See below accepted unit choices:" << endl;
  cout << "kilopascals(kPa), pounds per square inch(psi), millimeters mercury(mmHg)" << endl;
  cout << "Input a pressure unit to be converted" << endl;
}

//assigns a user input string (dimension) an integer value
int getIntFromDimensionString(string dimension) {
  if (dimension == "length") {
    return LENGTH;
  }
  if (dimension == "speed") {
    return SPEED;
  }
  if (dimension == "density") {
    return DENSITY;
  }
  if (dimension == "torque") {
    return TORQUE;
  }
  if (dimension == "power") {
    return POWER;
  }
  if (dimension == "pressure") {
    return PRESSURE;
  } else
    return 0;
}

//handle user input dimension
int getValidDimensionFromInput() {
  cout << "Enter a dimension to convert: ";
  cout << "Length  Speed  Density  Torque  Power  Pressure " << endl;
  string userChoiceDimension;
  getline(cin, userChoiceDimension);
  userChoiceDimension = convertStringToLower(userChoiceDimension);
  while (getIntFromDimensionString(userChoiceDimension) == 0) {
    outputInvalidDimensionPrompt();
    getline(cin, userChoiceDimension);
    userChoiceDimension = convertStringToLower(userChoiceDimension);
  }
  return getIntFromDimensionString(userChoiceDimension);
}

//assigns a user input string (unit) an integer value
int getIntFromLengthString(string unitLength) {
  if (isUserUnitFeet(unitLength)) {
    return FEET;
  }
  if (isUserUnitInch(unitLength)) {
    return INCH;
  }
  if (isUserUnitMillimeter(unitLength)) {
    return MILLIMETER;
  }
  if (isUserUnitYard(unitLength)) {
    return YARD;
  }
  if (isUserUnitKilometer(unitLength)) {
    return KILOMETER;
  }
  if (isUserUnitMeter(unitLength)) {
    return METER;
  } else
    return 0;
}

int getIntFromSpeedString(string unitSpeed) {
  if (isUserUnitMetersPerSecond(unitSpeed)) {
    return METERPERSECOND;
  }
  if (isUserUnitMilesPerHour(unitSpeed)) {
    return MILEPERHOUR;
  }
  if (isUserUnitKilometersPerHour(unitSpeed)) {
    return KMPERHOUR;
  } else
    return 0;
}

int getIntFromDensityString(string unitDensity) {
  if (isUserUnitGramsPerCentimeterCubed(unitDensity)) {
    return GRAMPERCMCUBED;
  }
  if (isUserUnitKilogramsPerMeterCubed(unitDensity)) {
    return KGPERMETERCUBED;
  }
  if (isUserUnitSlugsPerFeetCubed(unitDensity)) {
    return SLUGPERFEETCUBED;
  } else
    return 0;
}

int getIntFromTorqueString(string unitTorque) {
  if (isUserUnitNewtonMeters(unitTorque)) {
    return NEWTONMETER;
  }
  if (isUserUnitFootPounds(unitTorque)) {
    return FOOTPOUND;
  }
  if (isUserUnitOunceInches(unitTorque)) {
    return OUNCEINCH;
  } else
    return 0;
}

int getIntFromPowerString(string unitPower) {
  if (isUserUnitHorsePower(unitPower)) {
    return HORSEPOWER;
  }
  if (isUserUnitWatts(unitPower)) {
    return WATT;
  }
  if (isUserUnitKiloWatts(unitPower)) {
    return KILOWATT;
  }
  if (isUserUnitBritishThermal(unitPower)) {
    return BRITISHTHERMAL;
  } else
    return 0;
}

int getIntFromPressureString(string unitPressure) {
  if (isUserUnitKiloPascals(unitPressure)) {
    return KILOPASCAL;
  }
  if (isUserUnitPoundsPerSquare(unitPressure)) {
    return POUNDSPERSQUARE;
  }
  if (isUserUnitMillimetersMercury(unitPressure)) {
    return MILLIMETERSMERCURY;
  } else
    return 0;
}

//handle user unit input
int getLengthUnitFromUserInput() {
  string userChoiceUnit;
  getline(cin, userChoiceUnit);
  userChoiceUnit = convertStringToLower(userChoiceUnit);
  return getIntFromLengthString(userChoiceUnit);
}

int getSpeedUnitFromUserInput() {
  string userChoiceUnit;
  getline(cin, userChoiceUnit);
  userChoiceUnit = convertStringToLower(userChoiceUnit);
  return getIntFromSpeedString(userChoiceUnit);
}

int getDensityUnitFromUserInput() {
  string userChoiceUnit;
  getline(cin, userChoiceUnit);
  userChoiceUnit = convertStringToLower(userChoiceUnit);
  return getIntFromDensityString(userChoiceUnit);
}

int getTorqueUnitFromUserInput() {
  string userChoiceUnit;
  getline(cin, userChoiceUnit);
  userChoiceUnit = convertStringToLower(userChoiceUnit);
  return getIntFromTorqueString(userChoiceUnit);
}

int getPowerUnitFromUserInput() {
  string userChoiceUnit;
  getline(cin, userChoiceUnit);
  userChoiceUnit = convertStringToLower(userChoiceUnit);
  return getIntFromPowerString(userChoiceUnit);
}

int getPressureUnitFromUserInput() {
  string userChoiceUnit;
  getline(cin, userChoiceUnit);
  userChoiceUnit = convertStringToLower(userChoiceUnit);
  return getIntFromPressureString(userChoiceUnit);
}

//conversion factors for all possible valid inputs
double convertFeetToInches(double feet) { return feet * 12; }

double convertFeetToMeters(double feet) { return feet * 0.3048; }

double convertFeetToKilometers(double feet) { return feet * 0.000305; }

double convertFeetToYards(double feet) { return feet / 3.0; }

double convertFeetToMillimeters(double feet) { return feet * 304.8; }

double convertInchesToFeet(double inches) { return inches / 12; }

double convertInchesToMillimeters(double inches) { return inches * 25.4; }

double convertInchesToYards(double inches) { return inches / 36; }

double convertInchesToKilometers(double inches) { return inches / 39370; }

double convertInchesToMeters(double inches) { return inches / 39.37; }

double convertMillimetersToFeet(double millimeters) { return millimeters / 305; }

double convertMillimetersToInches(double millimeters) { return millimeters / 25.4; }

double convertMillimetersToYards(double millimeters) { return millimeters / 914; }

double convertMillimetersToKilometers(double millimeters) { return millimeters / 1E6; }

double convertMillimetersToMeters(double millimeters) { return millimeters / 1000; }

double convertYardsToFeet(double yards) { return yards * 3; }

double convertYardsToInches(double yards) { return yards * 36; }

double convertYardsToMillimeters(double yards) { return yards * 914; }

double convertYardsToKilometers(double yards) { return yards / 1094; }

double convertYardsToMeters(double yards) { return yards / 1.094; }

double convertKilometersToFeet(double kilometers) { return kilometers * 3281; }

double convertKilometersToInches(double kilometers) { return kilometers * 39370; }

double convertKilometersToMillimeters(double kilometers) { return kilometers * 1E6; }

double convertKilometersToYards(double kilometers) { return kilometers * 1094; }

double convertKilometersToMeters(double kilometers) { return kilometers * 1000; }

double convertMetersToFeet(double meters) { return meters * 3.281; }

double convertMetersToInches(double meters) { return meters * 39.37; }

double convertMetersToMillimeters(double meters) { return meters * 1000; }

double convertMetersToYards(double meters) { return meters * 1.094; }

double convertMetersToKilometers(double meters) { return meters / 1000; }

double convertMetersPerSecondToMilesPerHour(double metersPerSecond) { return metersPerSecond * 2.237; }

double convertMetersPerSecondToKilometersPerHour(double metersPerSecond) { return metersPerSecond * 3.6; }

double convertMilesPerHourToMetersPerSecond(double milesPerHour) { return milesPerHour * 2.237; }

double convertMilesPerHourToKilometersPerHour(double milesPerHour) { return milesPerHour * 1.609; }

double convertKilometersPerHourToMetersPerSecond(double kilometersPerHour) { return kilometersPerHour / 3.6; }

double convertKilometersPerHourToMilesPerHour(double kilometersPerHour) { return kilometersPerHour / 1.609; }

double convertGramsPerCentimeterToKilogramsPerMeter(double gramsPerCentimeter) { return gramsPerCentimeter * 1000; }

double convertGramsPerCentimeterToSlugsPerFeet(double gramsPerCentimeter) { return gramsPerCentimeter * 1.94032; }

double convertKilogramsPerMeterToGramsPerCentimeter(double kilogramsPerMeter) { return kilogramsPerMeter / 1000; }

double convertKilogramsPerMeterToSlugsPerFeet(double kilogramsPerMeter) { return kilogramsPerMeter * 0.00194; }

double convertSlugsPerFeetToGramsPerCentimeter(double slugsPerFeet) { return slugsPerFeet * 0.51538; }

double convertSlugsPerFeetToKilogramsPerMeter(double slugsPerFeet) { return slugsPerFeet * 515.3788; }

double convertNewtonMetersToFootPounds(double newtonMeters) { return newtonMeters / 1.356; }

double convertNewtonMetersToOunceInches(double newtonMeters) { return newtonMeters * 141.6119; }

double convertFootPoundsToNewtonMeters(double footPounds) { return footPounds * 1.3558; }

double convertFootPoundsToOunceInches(double footPounds) { return footPounds * 191.999; }

double convertOunceInchesToNewtonMeters(double ounceInches) { return ounceInches * 0.007061; }

double convertOunceInchesToFootPounds(double ounceInches) { return ounceInches * 0.005208; }

double convertHorsePowerToWatts(double horsePower) { return horsePower * 745.7; }

double convertHorsePowerToKiloWatts(double horsePower) { return horsePower * 0.7457; }

double convertHorsePowerToBritishThermal(double horsePower) { return horsePower * 2544.434; }

double convertWattsToHorsePower(double watts) { return watts * 0.00134102; }

double convertWattsToKiloWatts(double watts) { return watts * 0.001; }

double convertWattsToBritishThermal(double watts) { return watts * 3.41; }

double convertKiloWattsToHorsePower(double kilowatts) { return kilowatts * 1.34102; }

double convertKiloWattsToWatts(double kilowatts) { return kilowatts * 1000; }

double convertKiloWattsToBritishThermal(double kilowatts) { return kilowatts * 3412.142; }

double convertBritishThermalToHorsePower(double britishThermal) { return britishThermal * 0.00039; }

double convertBritishThermalToWatts(double britishThermal) { return britishThermal * 0.293; }

double convertBritishThermalToKiloWatts(double britishThermal) { return britishThermal * 0.000293; }

double convertKiloPascalsToPoundsPerSquareInch(double kiloPascals) { return kiloPascals * 0.145038; }

double convertKiloPascalsToMillimetersMercury(double kiloPascals) { return kiloPascals * 7.50062; }

double convertPoundsPerSquareInchToKiloPascals(double poundsPerSquareInch) { return poundsPerSquareInch * 6.89476; }

double convertPoundsPerSquareInchToMillimetersMercury(double poundsPerSquareInch) { return poundsPerSquareInch * 51.7149; }

double convertMillimetersMercuryToKiloPascals(double millimetersMercury) { return millimetersMercury * 0.133322; }

double convertMillimetersMercuryToPoundsPerSquareInch(double millimetersMercury) { return millimetersMercury * 0.0193368; }

//reassigns the integer-assigned user input to its proper string symbol for table output
string getStringFromLengthUnit(int unit) {
  if (unit == FEET)
    return "ft";
  if (unit == INCH)
    return "in";
  if (unit == MILLIMETER)
    return "mm";
  if (unit == YARD)
    return "yd";
  if (unit == KILOMETER)
    return "km";
  if (unit == METER)
    return "m";
  return "";
}

string getStringFromSpeedUnit(int unit) {
  if (unit == METERPERSECOND)
    return "m/s";
  if (unit == MILEPERHOUR)
    return "mi/hr";
  if (unit == KMPERHOUR)
    return "km/hr";
  return "";
}

string getStringFromDensityUnit(int unit) {
  if (unit == GRAMPERCMCUBED)
    return "g/cm^3";
  if (unit == KGPERMETERCUBED)
    return "kg/m^3";
  if (unit == SLUGPERFEETCUBED)
    return "slug/ft^3";
  return "";
}

string getStringFromTorqueUnit(int unit) {
  if (unit == NEWTONMETER)
    return "N-m";
  if (unit == FOOTPOUND)
    return "ft-lb";
  if (unit == OUNCEINCH)
    return "oz-in";
  return "";
}

string getStringFromPowerUnit(int unit) {
  if (unit == HORSEPOWER)
    return "hp";
  if (unit == WATT)
    return "W";
  if (unit == KILOWATT)
    return "kW";
  if (unit == BRITISHTHERMAL) {
    return "btu";
  }
  return "";
}

string getStringFromPressureUnit(int unit) {
  if (unit == KILOPASCAL)
    return "kPa";
  if (unit == POUNDSPERSQUARE)
    return "psi";
  if (unit == MILLIMETERSMERCURY)
    return "mmHg";
  return "";
}

//one function to handle all possible conversions based on valid user inputs
double getConvertedValue(double value, int dimensionStart, int dimensionEnd) {
  if (dimensionStart == FEET) {
    if (dimensionEnd == METER) {
      return convertFeetToMeters(value);
    }
    if (dimensionEnd == INCH) {
      return convertFeetToInches(value);
    }
    if (dimensionEnd == MILLIMETER) {
      return convertFeetToMillimeters(value);
    }
    if (dimensionEnd == YARD) {
      return convertFeetToYards(value);
    }
    if (dimensionEnd == KILOMETER) {
      return convertFeetToKilometers(value);
    }
  }
  if (dimensionStart == INCH) {
    if (dimensionEnd == FEET) {
      return convertInchesToFeet(value);
    }
    if (dimensionEnd == MILLIMETER) {
      return convertInchesToMillimeters(value);
    }
    if (dimensionEnd == YARD) {
      return convertInchesToYards(value);
    }
    if (dimensionEnd == KILOMETER) {
      return convertInchesToKilometers(value);
    }
    if (dimensionEnd == METER) {
      return convertInchesToMeters(value);
    }
  }
  if (dimensionStart == MILLIMETER) {
    if (dimensionEnd == FEET) {
      return convertMillimetersToFeet(value);
    }
    if (dimensionEnd == INCH) {
      return convertMillimetersToInches(value);
    }
    if (dimensionEnd == YARD) {
      return convertMillimetersToYards(value);
    }
    if (dimensionEnd == KILOMETER) {
      return convertMillimetersToKilometers(value);
    }
    if (dimensionEnd == METER) {
      return convertKilometersToMeters(value);
    }
  }
  if (dimensionStart == YARD) {
    if (dimensionEnd == FEET) {
      return convertYardsToFeet(value);
    }
    if (dimensionEnd == INCH) {
      return convertYardsToInches(value);
    }
    if (dimensionEnd == MILLIMETER) {
      return convertYardsToMillimeters(value);
    }
    if (dimensionEnd == KILOMETER) {
      return convertYardsToKilometers(value);
    }
    if (dimensionEnd == METER) {
      return convertYardsToMeters(value);
    }
  }
  if (dimensionStart == KILOMETER) {
    if (dimensionEnd == FEET) {
      return convertKilometersToFeet(value);
    }
    if (dimensionEnd == INCH) {
      return convertKilometersToInches(value);
    }
    if (dimensionEnd == MILLIMETER) {
      return convertKilometersToMillimeters(value);
    }
    if (dimensionEnd == YARD) {
      return convertKilometersToYards(value);
    }
    if (dimensionEnd == METER) {
      return convertKilometersToMeters(value);
    }
  }
  if (dimensionStart == METER) {
    if (dimensionEnd == FEET) {
      return convertMetersToFeet(value);
    }
    if (dimensionEnd == INCH) {
      return convertMetersToInches(value);
    }
    if (dimensionEnd == MILLIMETER) {
      return convertMetersToMillimeters(value);
    }
    if (dimensionEnd == YARD) {
      return convertMetersToYards(value);
    }
    if (dimensionEnd == KILOMETER) {
      return convertMetersToKilometers(value);
    }
  }
  if (dimensionStart == METERPERSECOND) {
    if (dimensionEnd == MILEPERHOUR) {
      return convertMetersPerSecondToMilesPerHour(value);
    }
    if (dimensionEnd == KMPERHOUR) {
      return convertMetersPerSecondToKilometersPerHour(value);
    }
  }
  if (dimensionStart == MILEPERHOUR) {
    if (dimensionEnd == METERPERSECOND) {
      return convertMilesPerHourToMetersPerSecond(value);
    }
    if (dimensionEnd == KMPERHOUR) {
      return convertMilesPerHourToKilometersPerHour(value);
    }
  }
  if (dimensionStart == KMPERHOUR) {
    if (dimensionEnd == METERPERSECOND) {
      return convertKilometersPerHourToMetersPerSecond(value);
    }
    if (dimensionEnd == MILEPERHOUR) {
      return convertKilometersPerHourToMilesPerHour(value);
    }
  }
  if (dimensionStart == GRAMPERCMCUBED) {
    if (dimensionEnd == KGPERMETERCUBED) {
      return convertGramsPerCentimeterToKilogramsPerMeter(value);
    }
    if (dimensionEnd == SLUGPERFEETCUBED) {
      return convertGramsPerCentimeterToSlugsPerFeet(value);
    }
  }
  if (dimensionStart == KGPERMETERCUBED) {
    if (dimensionEnd == GRAMPERCMCUBED) {
      return convertKilogramsPerMeterToGramsPerCentimeter(value);
    }
    if (dimensionEnd == SLUGPERFEETCUBED) {
      return convertKilogramsPerMeterToSlugsPerFeet(value);
    }
  }
  if (dimensionStart == SLUGPERFEETCUBED) {
    if (dimensionEnd == GRAMPERCMCUBED) {
      return convertSlugsPerFeetToGramsPerCentimeter(value);
    }
    if (dimensionEnd == KGPERMETERCUBED) {
      return convertSlugsPerFeetToKilogramsPerMeter(value);
    }
  }
  if (dimensionStart == NEWTONMETER) {
    if (dimensionEnd == FOOTPOUND) {
      return convertNewtonMetersToFootPounds(value);
    }
    if (dimensionEnd == OUNCEINCH) {
      return convertNewtonMetersToOunceInches(value);
    }
  }
  if (dimensionStart == FOOTPOUND) {
    if (dimensionEnd == NEWTONMETER) {
      return convertFootPoundsToNewtonMeters(value);
    }
    if (dimensionEnd == OUNCEINCH) {
      return convertFootPoundsToOunceInches(value);
    }
  }
  if (dimensionStart == OUNCEINCH) {
    if (dimensionEnd == NEWTONMETER) {
      return convertOunceInchesToNewtonMeters(value);
    }
    if (dimensionEnd == FOOTPOUND) {
      return convertOunceInchesToFootPounds(value);
    }
  }

  if (dimensionStart == HORSEPOWER) {
    if (dimensionEnd == WATT) {
      return convertHorsePowerToWatts(value);
    }
    if (dimensionEnd == KILOWATT) {
      return convertHorsePowerToKiloWatts(value);
    }
    if (dimensionEnd == BRITISHTHERMAL) {
      return convertHorsePowerToBritishThermal(value);
    }
  }

  if (dimensionStart == WATT) {
    if (dimensionEnd == HORSEPOWER) {
      return convertWattsToHorsePower(value);
    }
    if (dimensionEnd == KILOWATT) {
      return convertWattsToKiloWatts(value);
    }
    if (dimensionEnd == BRITISHTHERMAL) {
      return convertWattsToBritishThermal(value);
    }
  }

  if (dimensionStart == KILOWATT) {
    if (dimensionEnd == HORSEPOWER) {
      return convertKiloWattsToHorsePower(value);
    }
    if (dimensionEnd == WATT) {
      return convertKiloWattsToWatts(value);
    }
    if (dimensionEnd == BRITISHTHERMAL) {
      return convertKiloWattsToBritishThermal(value);
    }
  }

  if (dimensionStart == BRITISHTHERMAL) {
    if (dimensionEnd == HORSEPOWER) {
      return convertBritishThermalToHorsePower(value);
    }
    if (dimensionEnd == WATT) {
      return convertBritishThermalToWatts(value);
    }
    if (dimensionEnd == KILOWATT) {
      return convertBritishThermalToKiloWatts(value);
    }
  }

  if (dimensionStart == FOOTPOUND) {
    if (dimensionEnd == NEWTONMETER) {
      return convertFootPoundsToNewtonMeters(value);
    }
    if (dimensionEnd == OUNCEINCH) {
      return convertFootPoundsToOunceInches(value);
    }
  }
  if (dimensionStart == OUNCEINCH) {
    if (dimensionEnd == NEWTONMETER) {
      return convertOunceInchesToNewtonMeters(value);
    }
    if (dimensionEnd == FOOTPOUND) {
      return convertOunceInchesToFootPounds(value);
    }
  }
  if (dimensionStart == KILOPASCAL) {
    if (dimensionEnd == POUNDSPERSQUARE) {
      return convertKiloPascalsToPoundsPerSquareInch(value);
    }
    if (dimensionEnd == MILLIMETERSMERCURY) {
      return convertKiloPascalsToMillimetersMercury(value);
    }
  }
  if (dimensionStart == POUNDSPERSQUARE) {
    if (dimensionEnd == KILOPASCAL) {
      return convertPoundsPerSquareInchToKiloPascals(value);
    }
    if (dimensionEnd == MILLIMETERSMERCURY) {
      return convertPoundsPerSquareInchToMillimetersMercury(value);
    }
  }
  if (dimensionStart == MILLIMETERSMERCURY) {
    if (dimensionEnd == KILOPASCAL) {
      return convertMillimetersMercuryToKiloPascals(value);
    }
    if (dimensionEnd == POUNDSPERSQUARE) {
      return convertMillimetersMercuryToPoundsPerSquareInch(value);
    }
  }
  return 0;
}

//user inputs starting value of table, ending value of table, and increment
double getStartingValue()
{
  double startingValue;
  cout << "Input the starting value:" << endl;
  cin >> startingValue;
  return startingValue;
}

double getEndingValue()
{
  double endingValue;
  cout << "Input the ending value:" << endl;
  cin >> endingValue;
  return endingValue;
}

double getValueIncrement()
{
  double valueIncrement;
  cout << "Input the increment:" << endl;
  cin >> valueIncrement;
  return valueIncrement;
}

//tests for equivalent starting and ending values. returns new ending value if fails. 
double testForEquivalentValues(double startingValue, double endingValue)
{
  while (startingValue == endingValue) {
      cout << "Ending value must be different than starting value" << endl;
      cout << "Input the ending value:" << endl;
      cin >> endingValue;
    }
    return endingValue;
}
//tests for valid rowcount. returns new increment if fails
double testForValidRowCount(double startingValue, double endingValue, double valueIncrement)
{
  while ((endingValue - startingValue) / valueIncrement < 3 || (endingValue - startingValue) / valueIncrement > 25) {
      cout << "Not enough values. Please reduce the increment" << endl;
      cout << "Input the increment:" << endl;
      
      cin >> valueIncrement;
      
    }
    return valueIncrement;
}

//user inputs precision of initial unit and final unit
int getInitialPrecision()
{
  int initialPrecision;
  cout << "How many decimal point for starting value?" << endl;
  cin >> initialPrecision;
  return initialPrecision;
}

int getFinalPrecision()
{
  int finalPrecision;
  cout << "How many decimal point for ending value?" << endl;
  cin >> finalPrecision;
  return finalPrecision;
}

