# RCWL-0516 Microwave Radar Motion Sensor

A practical, source-linked learning repository for understanding, wiring, testing, and troubleshooting the RCWL-0516 microwave Doppler motion sensor with Arduino-compatible boards and ESP32.

> **Scope:** This project documents and tests the commercially available RCWL-0516 module. It does not claim to be the original design or an official manufacturer repository.
>
> **Verification status:** The example sketches are provided for bench testing but have not been compiled against your specific board setup or verified on physical hardware as part of this repository upload. Please follow the test procedure and report measured results separately from expected behavior.

## What is the RCWL-0516?

The RCWL-0516 is a compact microwave Doppler motion detector. It transmits a low-power microwave signal and detects changes in the reflected signal caused by movement. Its onboard processing circuit converts a detected event into a digital `OUT` signal.

It is a **motion trigger**, not a distance sensor, speedometer, object classifier, or reliable stationary-presence detector.

## Quick facts

| Item | Typical / documented value | Notes |
|---|---|---|
| Operating principle | Microwave Doppler radar | Detects motion-induced changes in reflected RF energy |
| Observed carrier frequency | Approximately 3.18 GHz on one examined board | Not a guaranteed precision specification; module variation is possible |
| Supply (`VIN`) | 4–28 V DC | A regulated 5 V supply is convenient for common microcontroller projects |
| Current | About 2.8 mA typical; approximately 3 mA commonly specified | Verify your board and supply |
| Detection range | Commonly advertised around 5–9 m | Depends heavily on target, movement, orientation, installation and environment |
| Output (`OUT`) | Digital active-HIGH pulse, approximately 3.3 V | Usually stays HIGH for about 2–3 seconds after a trigger; retriggering may extend it |
| Communication | Single digital GPIO signal | No UART, I²C, SPI, Wi-Fi or Bluetooth protocol |
| Controller compatibility | Arduino, ESP32, Raspberry Pi GPIO (with correct electrical precautions) | The sensor output is not a data stream |

Values are representative, not guarantees for every clone or board revision. See [References and further reading](#references-and-further-reading).

## Contents

- [Repository map](#repository-map)
- [How it works](docs/working-principle.md)
- [Pins and wiring](docs/pinout-and-wiring.md)
- [Arduino test sketch](firmware/arduino/rcwl0516_serial_test/rcwl0516_serial_test.ino)
- [ESP32 test sketch](firmware/esp32/rcwl0516_esp32_test/rcwl0516_esp32_test.ino)
- [Testing procedure](docs/testing-procedure.md)
- [Limitations and troubleshooting](docs/troubleshooting.md)
- [History, attribution and inventor question](docs/history-and-attribution.md)
- [Contribution guidelines](CONTRIBUTING.md)

## Quick start

1. Use a stable 5 V supply for `VIN` and connect sensor `GND` to controller `GND`.
2. Connect `OUT` to a digital input, for example ESP32 GPIO 27 or Arduino Uno D2.
3. Leave `CDS` unconnected for the first test.
4. Upload the relevant example sketch.
5. Open Serial Monitor at **115200 baud**.
6. Move across the sensor's field of view and observe the state changes. Allow a few seconds after power-up and test more than once.

See [pinout and wiring](docs/pinout-and-wiring.md) before powering the board.

## Repository map

```text
RCWL-0516-test-and-working/
├── README.md
├── LICENSE
├── CONTRIBUTING.md
├── docs/
│   ├── history-and-attribution.md
│   ├── pinout-and-wiring.md
│   ├── testing-procedure.md
│   ├── troubleshooting.md
│   └── working-principle.md
└── firmware/
    ├── arduino/
    │   └── rcwl0516_serial_test/
    │       └── rcwl0516_serial_test.ino
    └── esp32/
        └── rcwl0516_esp32_test/
            └── rcwl0516_esp32_test.ino
```

## Safety and responsible use

- Do not connect `VIN` to a microcontroller GPIO. `VIN` is the sensor's power input.
- `OUT` is typically about 3.3 V HIGH. Check the input limits of the controller you use.
- Use a proper driver for lamps, motors, relays or other loads; do not drive them directly from a GPIO.
- This low-cost module is not a certified safety device. Do not use it as the sole sensor for anti-crush protection, industrial machine guarding, vehicle collision avoidance or life-safety systems.
- Microwave motion detection can trigger through some non-metallic walls or enclosures. Test the complete installation for unwanted detections.
- Do not assume that a quiet output means a room is empty; a stationary person may not trigger it.

## Known limitations of the documentation

The module's public documentation is incomplete. The exact original designer/manufacturer of the RCWL-0516 board is not clearly established by the sources linked here. This repository therefore distinguishes measured observations, commonly published specifications, and uncertain attribution instead of inventing a named inventor.

## References and further reading

1. Joe Desbonnet, **RCWL-0516 research repository** — reverse-engineering notes, observed frequency, board behavior, schematic discussion and community issues: https://github.com/jdesbonnet/RCWL-0516/
2. Arduino Store, **Microwave motion radar** — summary specifications and digital output behavior: https://store.arduino.cc/products/microwave-motion-radar
3. Handson Technology, **RCWL-0516 Microwave Radar Motion Detector user guide** (PDF): https://www.bastlik.cz/user/documents/upload/datasheet4/datasheet_RCWL-0516_EN.pdf
4. John Taylor, **RCWL-0516 schematic reference** (PDF, linked by the reverse-engineering repository): https://www.tayloredge.com/reference/Electronics/RF/0242.pdf
5. European Patent Office / Google Patents, **EP3091605A1** (related planar microwave antenna module; related technology is not proof of authorship of the RCWL-0516 board): https://patents.google.com/patent/EP3091605A1/en

Check the sources and board revision you actually own before treating any numerical specification as guaranteed.

## License

Original documentation and example code in this repository are provided under the MIT License; see [LICENSE](LICENSE). Third-party documents, schematics, trademarks and linked material remain the property of their respective rights holders. Their links are provided for reference, not relicensing.
