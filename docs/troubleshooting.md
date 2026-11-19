# Troubleshooting and Limitations

## No motion detected

- Confirm `VIN` is within the module's supply range; try a stable 5 V source.
- Confirm grounds are connected together.
- Verify the pin labels and that `OUT` reaches the intended GPIO.
- Leave `CDS` unconnected during initial testing.
- Face the component side toward the target area.
- Wait a few seconds after power-up and test with deliberate lateral movement, not only movement directly toward the board.
- Try another module or supply if the output never changes.

## Output always HIGH / frequent false triggers

- Move away from fans, moving curtains, nearby traffic, other moving objects and reflective metal.
- Test with the module outside its final enclosure.
- Check whether movement in adjacent rooms or behind a non-metallic wall is being detected.
- Check supply stability and wiring.
- The module is not an object classifier. It cannot distinguish an intended person from other detectable movement.

## Output is inverted or voltage looks wrong

The common behavior is active-HIGH at approximately 3.3 V. Check the exact module revision, ground reference and measurement setup. Do not assume every clone is identical. Never apply 5 V to a 3.3 V-only microcontroller GPIO.

## It triggers after movement stops

The output commonly remains HIGH for around 2–3 seconds after a detection. This is trigger timing, not proof that the target is still moving. Further movement may retrigger it.

## It detects through a wall

Microwave energy can pass through some non-metallic materials, depending on the wall/enclosure, geometry and target. Reposition the sensor, add suitable shielding or choose a sensor technology better matched to the application. Do not assume cardboard or plastic forms a reliable radar barrier.

## It does not detect a stationary person

The RCWL-0516 is a basic motion detector. A stationary target may stop producing a useful Doppler signal. Use a presence-sensing radar designed for micro-motion/static presence if that requirement matters.

## It cannot measure distance

`OUT` is a binary trigger, not a ranging output. Use a time-of-flight sensor such as VL53L0X, ultrasonic ranging, or a radar module with a documented distance interface if you need distance data.

## Safety

This is a low-cost hobby module, not a certified life-safety or industrial safety component. Do not use it as the only sensor in a system where a missed or false detection could injure someone.