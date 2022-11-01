# Cyclic-Redundancy-Check---CRC

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT "MIT License")

With this code you can test the function of CRC and its robustness. The menu is

![Even-Parity cover image](https://github.com/NikitasMaragkos/Cyclic-Redundancy-Check---CRC/blob/main/Image/1.PNG?raw=true)

#### Case 1

Here, the user gives:

* k: The length of the message to be seny
* P: The known key to both sides. 
* BER: probability of an error through transmission.

Then, a random message for transmission is created and CRC is applied. An example can be seen below.

![CRC cover image](https://github.com/NikitasMaragkos/Cyclic-Redundancy-Check---CRC/blob/main/Image/2.PNG?raw=true)

#### Case 2

Here, the user gives as previous the same variables. This time the program runs many times in order to present us the statistics.

An example of 10.000 runs:

![CRC cover image](https://github.com/NikitasMaragkos/Cyclic-Redundancy-Check---CRC/blob/main/Image/3.PNG?raw=true)

An example of 100.000 runs:

![CRC cover image](https://github.com/NikitasMaragkos/Cyclic-Redundancy-Check---CRC/blob/main/Image/4.PNG?raw=true)

An example of 1.000.000 runs:

![CRC cover image](https://github.com/NikitasMaragkos/Cyclic-Redundancy-Check---CRC/blob/main/Image/5.PNG?raw=true)

In all cases we can see that CRC cannot detect only 0.01% of the errors.
