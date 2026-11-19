# Pinout and Wiring

## Header pins

The common five-pin header is labelled:

| Pin | Function | Notes |
|---|---|---|
| `3V3` | Regulated 3.3 V output | An output, not the normal supply input. Published current capability is uncertain across sources/boards; avoid using it to power other modules unless verified. |
| `GND` | Ground | Connect to controller ground. |
| `OUT` | Digital trigger output | Usually LOW at idle and approximately 3.3 V HIGH after detected motion. |
| `VIN` | Power input | Common documentation specifies 4–28 V DC. A regulated 5 V supply is a practical choice. |
| `CDS` | Trigger-disable / optional light-sensor control | Leave open for a basic test. Pulling this node low can disable the output. Details depend on board implementation. |

Check the silkscreen on your exact board; clones and pin orientation can vary. Never rely only on a photograph when wiring.

## ESP32 example

| RCWL-0516 | ESP32 |
|---|---|
| `VIN` | `5V` / `VIN` pin from a suitable 5 V source |
| `GND` | `GND` |
| `OUT` | GPIO 27 |
| `3V3` | Not connected for this test |
| `CDS` | Not connected for this test |

Use a stable supply and a common ground. A typical 3.3 V `OUT` signal is suitable for ESP32 GPIO. Do not feed 5 V into an ESP32 GPIO.

## Arduino Uno example

| RCWL-0516 | Arduino Uno |
|---|---|
| `VIN` | 5 V |
| `GND` | GND |
| `OUT` | D2 |
| `3V3` | Not connected |
| `CDS` | Not connected |

The sensor's `OUT` is a logic signal, not a serial protocol. Use `digitalRead()` rather than UART, I²C or SPI libraries.

## Power and layout cautions

- Do not power the module from a GPIO.
- Do not connect `VIN` to `OUT`.
- Keep the component side facing the target area.
- Leave clearance behind the PCB; the reference guide recommends more than 1 cm from metal behind the board.
- Avoid placing metal directly in front of the sensing face.
- Keep wiring secure and prevent shorts.
- Do not connect a relay coil, motor or lamp directly to a microcontroller GPIO.

## Communication model

```text
RCWL-0516 OUT ─────> digital input pin (GPIO)
                         |
                    digitalRead()
                         |
                application decision
                         |
                optional driver / alert
```

The sensor itself does not provide Wi-Fi or Bluetooth. An ESP32 can publish the detected event over Wi-Fi, but that network communication is implemented by the ESP32 firmware, not by the RCWL-0516.