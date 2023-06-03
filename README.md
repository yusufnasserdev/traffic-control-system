# traffic-control-system
Car registry and Fine recording and payment simple System.

This project was developed as the requirement to pass the Structured Programming Course at Ain Shams University, Faculty of Computer Science and Information Systems.

Due to the nature of the course, the project was developed in `C++` language.

## Requirements
The project was developed using Visual Studio 2019, so it is recommended to use it to open the project. However, the project can be opened using any IDE that supports C++.

The college requirements for this course can be found in the [assets](./assets/Requirement.pdf) folder.

## Documentation
The documentation of the project is available in the [assets](./assets/Report.pdf) folder, it is thorough and explains the project in detail.

## Data Validation
The project uses data validation to ensure the correctness of the data entered by the user. 
It is done through the use of multiple functions that check the data entered by the user falls within the required range.

Functions used for data validation:
- `bool valid_license(unsigned int license)` - Checks if the license number is valid.
- `bool valid_license(unsigned int license)` - Checks if the license number is valid.
- `bool valid_car_plate(unsigned int plate)` - Checks if the car plate number is valid.

- `bool valid_date(date input_date)` - Checks if the date is valid, uses the `bool valid_month(unsigned int month)`, `bool leap_year(unsigned int year)`, and `bool valid_day(unsigned int day, unsigned int month, unsigned int year)` functions.

- `bool valid_month(unsigned int month)` - Checks if the month is valid.
- `bool leap_year(unsigned int year)` - Checks if the year is a leap year.
- `bool valid_day(unsigned int day, unsigned int month, unsigned int year)` - Checks if the day is valid.


## Overview
This is a simple system that allows the registration of cars and drivers, and the recording of fines. The system also allows the payment of fines.

- Driver Operations:
  - Car registry
  - Driver registry
  - Fine payment
  - Car Search

- Police Operations:
  - Fine recording

## Screenshots
![Screenshot 1](./assets/screenshots/1.png)
![Screenshot 2](./assets/screenshots/2.png)
![Screenshot 3](./assets/screenshots/3.png)
![Screenshot 4](./assets/screenshots/4.png)
![Screenshot 5](./assets/screenshots/5.png)
![Screenshot 6](./assets/screenshots/6.png)
![Screenshot 7](./assets/screenshots/7.png)
![Screenshot 8](./assets/screenshots/8.png)
![Screenshot 9](./assets/screenshots/9.png)
![Screenshot 10](./assets/screenshots/10.png)
![Screenshot 11](./assets/screenshots/11.png)
![Screenshot 12](./assets/screenshots/12.png)
![Screenshot 13](./assets/screenshots/13.png)
![Screenshot 14](./assets/screenshots/14.png)
![Screenshot 15](./assets/screenshots/15.png)
![Screenshot 16](./assets/screenshots/16.png)
