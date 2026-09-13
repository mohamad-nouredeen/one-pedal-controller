# Embedded Arduino Deployment

This folder contains the embedded deployment stage of the One-Pedal Controller project.

The Simulink controller was adapted for execution on a simulated **Arduino Uno**. Embedded C code and AVR firmware were generated from the model, and the resulting firmware was tested using **SimulIDE**.

## Folder Structure

```text
embedded/
├── arduino/
│   └── controller_arduino_4_mahdy_f.slx
├── firmware/
│   └── controller_arduino_4_mahdy_f.hex
├── generated-code/
│   └── generated C source and headers
└── simulide/
    └── lab_4_final_arduino_simi.sim1