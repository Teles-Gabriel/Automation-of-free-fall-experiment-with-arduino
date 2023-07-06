# Automation-of-free-fall-experiment-with-arduino
This project was developed for the delivery of the final work of the Scientific Instrumentation Laboratory discipline offered at the University of Brasília(UnB).
The ultimate goal of this project is to have an automated device using Arduino that is easy to assemble and calculates the value of gravity at the location where it is assembled.
# Introduction
The free fall experiment consists of dropping an object from a height X<sub>0</sub> and measuring the time of fall to a point X<sub>1</sub>, to calculate the value of gravitational acceleration(g), we use the hourly equation of space(eq.1), isolating the variable g(eq.2).
<br/>
$x_1 = x_0 + v_0 \cdot t + \frac{1}{2} \cdot a \cdot t^2\$  (eq.1)
<br/>
<br/>
$g = a$
<br/>
$v_0 = 0$
<br/>
$X_0 = 0$
<br/>
$X_1 = Height$
<br/>
$h = \Delta X$
<br/>
<br/>
$g = \frac{2h}{t²}$   (eq.2)
<br/>
# Code
To edit this code you need to have the Arduino IDE installed and to implement this code you need to have an arduino Uno r3 board.
# Materials
* 1 Arduino Uno R3
* 1 Protoboard
* 1 Phototransistor
* 1 Laser diode
* 1 Button
* 1 Electromagnet coil
* Jumpers

# Test the components

To test the button, use the code available in the folder [Button-state-read-test](https://github.com/Teles-Gabriel/Automation-of-free-fall-experiment-with-arduino/blob/main/Button-state-read-test/Button-state-read-test.ino), mount a normally open button on the breadboard, in one of the terminals connect the +5v supply, in the corresponding output terminal, connect the digital port 7. See the results on the serial port.
<br/>
To avoid interference from the environment, pull down the button output(connect to GND).
<br/>
To test the phototransistor reading, use the standard example available in the Arduino IDE, AnalogReadSerial.
<br/>
