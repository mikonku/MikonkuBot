# MikonkuBot Library

The **MikonkuBot** library provides a simple way to control an RC car or robot using an Arduino. It includes methods for moving forward, backward, turning left, turning right, stopping, and adjusting motor speeds.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Installation

1. Download the `MikonkuBot` library folder from this repository.
2. Move the downloaded folder into the `libraries` folder in your Arduino sketchbook directory.
3. Restart the Arduino IDE if it's already open.

## Usage

1. Include the `MikonkuBot` library at the top of your Arduino sketch:

   ```cpp
   #include <MikonkuBot.h>
   ```

2. Create an instance of the MikonkuBot class with the desired pin configuration:

   ```cpp
   MikonkuBot myBot(ENA_PIN, IN1_PIN, IN2_PIN, IN3_PIN, IN4_PIN, ENB_PIN);
   ```

   Replace ENA_PIN, IN1_PIN, IN2_PIN, IN3_PIN, IN4_PIN, and ENB_PIN with the actual pin numbers you are using.

3. Use the available methods to control the bot:

   ```cpp
    myBot.goForward();
    delay(2000);
    myBot.stop();
    delay(1000);
    myBot.goBackward();
    delay(2000);
    myBot.stop();
    delay(1000);
    myBot.goTurnLeft();
    delay(1000);
    myBot.stop();
    delay(1000);
    myBot.goTurnRight();
    delay(1000);
    myBot.stop();

   ```

   You can also set custom pin numbers using the following methods:

   ```cpp
   myBot.setPinENA(new_ENA_PIN);
   myBot.setPinIN1(new_IN1_PIN);
   myBot.setPinIN2(new_IN2_PIN);
   myBot.setPinIN3(new_IN3_PIN);
   myBot.setPinIN4(new_IN4_PIN);
   myBot.setPinENB(new_ENB_PIN);
   ```

   Where new_ENA_PIN, new_IN1_PIN, etc., are the new pin numbers you want to use.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

## License

This library is distributed under the [MIT License](https://opensource.org/licenses/MIT)
.
