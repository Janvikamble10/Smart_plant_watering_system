
# Design Notes and Engineering Decisions

## Sensor Selection
An analog soil moisture sensor was used instead of a digital (threshold-based) output.  
This allows threshold values to be defined and adjusted in software, making the system more flexible and easier to calibrate.

## ADC Usage
The Arduino’s 10-bit ADC (0–1023) is used to read soil moisture levels.  
Observed values in simulation were used to select stable dry and wet thresholds rather than relying on arbitrary numbers.

## Control Strategy
The system uses hysteresis with two thresholds:
- Dry threshold: start watering
- Wet threshold: stop watering

This prevents rapid relay switching when the sensor value fluctuates near a single threshold.

## Actuator Control
A relay is used to isolate the microcontroller from the pump’s power source.  
The normally-open (NO) contact is used so the pump remains OFF by default, providing fail-safe behavior.

## Known Limitations
- The project is simulated; real sensors may suffer from corrosion and drift
- Relay coil is driven directly in simulation; real hardware should use a transistor driver with a flyback diode
- Timing uses blocking delays for simplicity and observability

## Possible Improvements
- Transistor-based relay driver circuit
- Non-blocking timing using `millis()`
- IoT integration for alerts or logging (ESP32 + Wi-Fi)
