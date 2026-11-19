# Test Procedure

## Goal

Verify that the RCWL-0516 produces a digital motion-trigger output and that the controller reads it correctly. This is a functional bench test, not a calibrated range test.

## Equipment

- RCWL-0516 module
- ESP32 development board or Arduino Uno
- Stable regulated 5 V supply (or an appropriate board supply)
- Jumper wires
- USB cable and computer with Arduino IDE
- Serial Monitor

## Before powering on

1. Read the pin labels on the actual PCB.
2. Connect `GND` to controller ground.
3. Connect `VIN` to 5 V.
4. Connect `OUT` to the selected digital input.
5. Leave `CDS` and `3V3` disconnected.
6. Check for shorts and reversed power.

## Test with ESP32

1. Open `firmware/esp32/rcwl0516_esp32_test/rcwl0516_esp32_test.ino`.
2. Select the correct ESP32 board and COM port.
3. Upload.
4. Open Serial Monitor at 115200 baud.
5. Wait several seconds after power-up.
6. Move your hand or walk across the sensing area, then stop moving.
7. Observe the reported state and event counter.

## Test with Arduino Uno

1. Open `firmware/arduino/rcwl0516_serial_test/rcwl0516_serial_test.ino`.
2. Select Arduino Uno and its COM port.
3. Upload and open Serial Monitor at 115200 baud.
4. Move across the sensing area and observe the readings.

## Record results

Record:
- Board/module markings and supply voltage.
- Controller board and GPIO used.
- Distance and target movement direction.
- Whether triggers occur with no deliberate movement.
- How long the output remains HIGH.
- Whether adjacent-room or behind-wall movement causes triggers.
- Mounting orientation and nearby metal or moving objects.

Do not claim a precise detection range from one hand-wave test. Repeat at several distances and directions in the final enclosure.

## Expected behavior

Typically, output is LOW while idle and HIGH for about 2–3 seconds after detected motion. Continuous or repeated movement can retrigger it. Exact timing and sensitivity vary across modules and installations.