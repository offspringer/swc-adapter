[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

## About The Project

This project aims to adapt existing steering wheel controls for a non standard car radio. It's designed to work with Nissan models, but should work in any other resistive steering wheel controls. Essentially, it converts resistive analog values read from the buttons present in the steering wheel into values the car radio is programmed to understand. Naturally, there are several adapting interfaces on the market, but not seemed to work with the setup being used by me, simply because the radio being installed belongs to another car of the same manufacturer, thus, not a standard off the shelf brand, like Pioneer, Kenwood or JVC. Interfaces available on the market are non programmable and non customizable. Additionally, I'd like to learn a different technology as well. Who doesn't?!

### Built With

* [RoboCore](https://www.robocore.net/) - Arduino development kit
* [Visual Studio Code](https://code.visualstudio.com/) - Code editor
* [PlatformIO](https://platformio.org/) - A platform for embedded development
 
## Getting Started

To get a copy up and running follow these steps.

### Prerequisites

This project requires an Arduino compatible board with at least 2 analogue inputs, two digital potentiometers, steering wheels controls removed from the steering wheel itself (of course, depending on how advanced you're with Arduino prototyping, you could simulate your own buttons as well), a multimeter and a car radio (or just a multimeter if you're a hundred percent sure it's gonna work once installed).

### Components
These were the components used (so far):
* Arduino Uno board;
* 1x 100000k Ω resistance;
* 2x X9C103S 10k Ω digital potentiometers;
* A tension regulator to be defined;
* A case to be defined.

### Building
Probably a diagram will be included here anytime soon, I swear.

### Installation
Once completed, flash the code into your board. Don't forget to comment out the constants responsible for enabling additional serial output, so you don't force your microcontroller to execute extra and unnecessary instructions. You'll find them in the `inbound.h` file:

```
#define  INBOUND_RESISTANCE_DEBUG // Enables serial printing for resistance
#define  INBOUND_BUTTON_DEBUG // Enables serial printing for button
```

## Usage
To install it in the car, we'll basically intercept the wires 6 and 16 from the Nissan harness J502 ( wires SWC-A and SWC-B from the famous 20-pin Nissan connector) and also the wire 15 (SWC ground), and power it on by using the car battery, which is 12v and requires a tension regulator to protect the integrity of the Arduino board.
![Nissan harness pinout][connector]

## Roadmap

See the [open issues](https://github.com/offspringer/swc-adapter/issues) for a list of proposed features (and known issues).

## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project

2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)

3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)

4. Push to the Branch (`git push origin feature/AmazingFeature`)

5. Open a Pull Request
 
## Acknowledgements

* [StackEdit](https://stackedit.io)

* [Esquema de ligação do rádio original (forumeiros.com)](https://tiidaclube.forumeiros.com/t1005-esquema-de-ligacao-do-radio-original)

* [Atomic Cactus – Resistor Ladder Steering Wheel Control Interpreter Using Arduino (atomic-cactus.com)](https://atomic-cactus.com/2013/03/29/resistor-ladder-steering-wheel-control-interpreter-using-arduino/)

* [Steering wheel remote audio control - Using Arduino / General Electronics - Arduino Forum](https://forum.arduino.cc/t/steering-wheel-remote-audio-control/223878/7)

* [othneildrew/Best-README-Template: An awesome README template to jumpstart your projects! (github.com)](https://github.com/othneildrew/Best-README-Template)

<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]: https://img.shields.io/github/contributors/offspringer/swc-adapter.svg?style=for-the-badge
[contributors-url]: https://github.com/offspringer/swc-adapter/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/offspringer/swc-adapter.svg?style=for-the-badge
[forks-url]: https://github.com/offspringer/swc-adapter/network/members
[stars-shield]: https://img.shields.io/github/stars/offspringer/swc-adapter.svg?style=for-the-badge
[stars-url]: https://github.com/offspringer/swc-adapter/stargazers
[issues-shield]: https://img.shields.io/github/issues/offspringer/swc-adapter.svg?style=for-the-badge
[issues-url]: https://github.com/offspringer/swc-adapter/issues
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/rogertdsantos/
[connector]:images/connector.jpg