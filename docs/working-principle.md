# Working Principle of the RCWL-0516

## 1. Overview

The RCWL-0516 is a low-cost microwave Doppler motion detector. Its job is to turn motion in its sensing region into a simple digital output. The module contains a microwave RF section and a lower-frequency signal-processing section, so a host microcontroller normally sees only `OUT`, not raw radar data.

## 2. Signal path

1. **Microwave generation:** An RF oscillator on the PCB produces a microwave carrier. Reverse-engineering of one examined board found a carrier near 3.181 GHz. This is an observation from a sample, not a precision frequency guarantee.
2. **Illumination and reflection:** Energy radiates into the surrounding area and reflects from objects.
3. **Motion changes the return:** If a target moves relative to the sensor, the reflected wave can have a small Doppler frequency shift.
4. **RF detection / mixing:** The RF section converts the tiny change into a lower-frequency signal that the onboard circuitry can process.
5. **Thresholding and timing:** The processing circuit decides whether the variation resembles motion and controls the trigger interval.
6. **Digital output:** `OUT` goes HIGH (typically around 3.3 V) for a limited interval, commonly around 2–3 seconds. Further movement may retrigger or extend the interval depending on module behavior.

This is a simplified functional explanation. Publicly available detailed documentation for the RCWL-9196 IC and exact production design is limited.

## 3. Doppler equation

For a monostatic radar (the same location is used for transmit and receive), the approximate Doppler shift for a target moving radially at speeds much smaller than the speed of light is:

\[
f_d \approx \frac{2 v f_c}{c}
\]

Where:

- \(f_d\) is the Doppler frequency shift in hertz.
- \(v\) is target velocity along the radar line of sight in metres per second.
- \(f_c\) is the carrier frequency in hertz.
- \(c\) is the speed of light, approximately \(2.998 \times 10^8\ \text{m/s}\).

For \(v = 1\ \text{m/s}\) and \(f_c = 3.181\ \text{GHz}\), the radial-motion approximation gives about **21 Hz**. Movement perpendicular to the line of sight has a smaller radial component and may produce a weaker Doppler shift.

The module does not expose this frequency as a measured value. It performs internal processing and provides a trigger.

## 4. What it does and does not measure

**It can:**
- Trigger when detectable motion changes the reflected microwave signal.
- Work in darkness because it does not depend on visible light.
- Detect motion in some installations where non-metallic material lies between the sensor and target.

**It does not directly provide:**
- Target distance.
- Direction of travel.
- Numeric speed.
- Identity or class of the target.
- Reliable static occupancy / stationary human presence.

Do not confuse “can detect through some materials” with “can see through every wall.” Metal, material thickness, geometry and mounting strongly affect the signal.

## 5. Comparison with PIR

A PIR sensor responds to changes in infrared radiation across its sensing zones. RCWL-0516 responds to motion-related microwave reflections. As a result, the radar module may trigger through some non-metallic covers and can be more sensitive to movement outside the intended room. Neither basic module is a reliable static-presence sensor.

## 6. Internal circuit notes

Reverse-engineering notes describe an RF oscillator/mixer section and an RCWL-9196 signal-processing IC. The latter has been compared functionally with circuitry used in PIR motion detectors, but a complete official datasheet for RCWL-9196 is not readily available in the cited public material. Treat detailed transistor-level explanations as reverse-engineering hypotheses unless supported by a measured schematic.

## Sources

- https://github.com/jdesbonnet/RCWL-0516/
- https://store.arduino.cc/products/microwave-motion-radar
- https://www.bastlik.cz/user/documents/upload/datasheet4/datasheet_RCWL-0516_EN.pdf