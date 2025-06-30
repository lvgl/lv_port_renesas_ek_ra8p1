# LVGL ported to Renesas EK-RA8P1

## Overview

The Renesas EK-RA8P1 is an evaluation board for a high-end 1GHz ARM Cortex-M85 microcontroller
with large external memory (128MB).
It has a D/AVE 2D graphics accelerator which LVGL supports and is enabled in this project.
The included display is 7" and has a resolution of 1024x600.
There is an on-chip AI accelerator as well.

## Buy

(coming soon...)

## Benchmark

The benchmark configuration is direct double-buffered with D/AVE 2D enabled and using aligned fonts.

<a href="https://www.youtube.com/watch?v=PoxDoQp51G8">
    <img src="https://github.com/user-attachments/assets/e2d3b24c-3fb4-4dab-bf80-73f72c4f6781" width="75%">
</a>

| Name                      | Avg. CPU | Avg. FPS | Avg. time | render time | flush time |
| :------------------------ | -------: | -------: | --------: | ----------: | ---------: |
| Empty screen              | 72%      | 29       | 21        | 14          | 7          |
| Moving wallpaper          | 93%      | 27       | 33        | 32          | 1          |
| Single rectangle          | 44%      | 29       | 9         | 1           | 8          |
| Multiple rectangles       | 48%      | 29       | 15        | 7           | 8          |
| Multiple RGB images       | 54%      | 29       | 14        | 7           | 7          |
| Multiple ARGB images      | 63%      | 29       | 16        | 9           | 7          |
| Rotated ARGB images       | 47%      | 30       | 13        | 6           | 7          |
| Multiple labels           | 93%      | 24       | 34        | 29          | 5          |
| Screen sized text         | 98%      | 8        | 114       | 103         | 11         |
| Multiple arcs             | 97%      | 29       | 28        | 17          | 11         |
| Containers                | 87%      | 28       | 23        | 12          | 11         |
| Containers with overlay   | 95%      | 14       | 52        | 43          | 9          |
| Containers with opa       | 84%      | 28       | 22        | 14          | 8          |
| Containers with opa_layer | 97%      | 9        | 97        | 85          | 12         |
| Containers with scrolling | 98%      | 14       | 65        | 55          | 10         |
| Widgets demo              | 98%      | 14       | 52        | 43          | 9          |
| All scenes avg.           | 79%      | 23       | 37        | 29          | 8          |


## Specification

### CPU and Memory
- **MCU:** 1GHz ARM Cortex-M85 and 250MHz Cortex-M33
- **RAM:** 1872KB internal, 128MB external
- **Flash:** 1MB
- **GPU:** D/AVE 2D

### Display and Touch
- **Resolution:** 1024x600
- **Display Size:** 7"
- **Interface:** Parallel RGB
- **Color Depth:** 16-bit
- **Technology:** LCD
- **DPI:** 170 px/inch
- **Touch Pad:**

### Connectivity
- 2x USB host or device
- 2x display connectors (connects to included display board)
- Ecosystem connectors (Arduino, mikroBUS, and Pmod)

## Getting started

### Hardware setup
- Mount the graphics expansion board to the mainboard.
- Connect a USB C cable to DEBUG1 (J10) and your PC.

### Software setup
- [Install e2 studio 2025-04.1 or newer (important) for your OS](https://www.renesas.com/en/software-tool/e2studio-information-rz-family).
  On Linux, Ubuntu 22.04 or newer is required.
  - When prompted, choose "Custom Install".
  - Ensure "RA" is included in your selection of "Device Families" to install.
  - Ensure "Renesas FSP Smart Configurator Core" and "Renesas FSP Smart Configurator ARM"
    are included in your selection of "Customize Features".
  - Ensure "LLVM Embedded Toolchain for Arm 18.1.3" is selected.
- Install FSP Packs. v6.0.0 is required.
  - On Windows, simply download FSP_Packs_v6.0.0.exe
    [from here](https://github.com/renesas/fsp/releases) under "Assets" for the desired release.
    Run the installer and follow the prompts.
  - On Linux, download FSP_Packs_v6.0.0.zip
    [from here](https://github.com/renesas/fsp/releases) under "Assets" for the desired release.
    Locate the e2 studio install location. If it is `~/.local/share/renesas/e2_studio`
    and the ZIP download is `~/Downloads/FSP_Packs_v6.0.0.zip`, unzip the file
    with the following commands:
    ```shell
    cd ~/.local/share/renesas/e2_studio
    unzip ~/Downloads/FSP_Packs_v6.0.0.zip
    ```
    The directory structure of the ZIP structure may overlap with some of the structure
    of the e2_studio install loction. This is expected. The `unzip` process will
    update the directory structure with the new FSP files from the ZIP and preserve any existing FSP packs.

### Run the project
- Clone the repository
  ```shell
  git clone https://github.com/lvgl/lv_port_renesas_ek_ra8p1.git
  ```
- Open e2 studio and go to **File > Open Projects from File System...**. Click "Directory"
  and navigate to the cloned project and then click "Finish".
- Click the hammer to build the project. If it is greyed-out, first single-click the project
  "lv_ek_rza3m" in the left sidebar and the hammer should become clickable.
- To upload and run the project, click the bug (debug) icon. The debugger will break (stop execution)
  at the beginning. Click the "Resume" button to continue execution.

### Debugging
- In the previous section, the project was run using the debugger.
  Simply continue using the interactive debugger in e2 studio to debug your program.
  Set breakpoints, continue, step, etc. as with any other Eclipse-based IDE.

## Notes

LVGL comes from the FSP so the source code will appear upon building. It can be edited
in-place, but changes will be lost if a "clean" is performed.

`src/lv_conf_user.h` is the file to edit to change LVGL configs. `ra_cfg\fsp_cfg\lvgl\lvgl\lv_conf.h` includes this file
and has some defaults which will be set if they are not explicitly set in `src/lv_conf_user.h`.

LVGL logging and `printf` goes to a virtual serial port with baud 115200 over the USB debug connection.
You can open any serial terminal on your PC to view it.

## Contribution and Support

If you find any issues with the development board feel free to open an Issue in this repository. For LVGL related issues (features, bugs, etc) please use the main [lvgl repository](https://github.com/lvgl/lvgl).

If you found a bug and found a solution too please send a Pull request. If you are new to Pull requests refer to [Our Guide](https://docs.lvgl.io/master/CONTRIBUTING.html#pull-request) to learn the basics.

