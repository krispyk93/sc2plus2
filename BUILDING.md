# Building

## Compiling

1)  Clone the repo with `git clone https://github.com/aksame/sc2plus2.git`

2)  Copy your NTSC-U Soulcalibur 2 ISO to the root `sc2plus2` folder, then rename it to `grseaf.iso`.

3)  Install devkitpro.

    - Windows: Download [here](https://github.com/devkitPro/installer/releases)
    - MacOS/Linux: Read [this guide](https://devkitpro.org/wiki/Getting_Started)

4)  Download [Romhack-Compiler](https://github.com/hallcristobal/romhack-compiler/releases).
    This is used to add our compiled code into the ISO.<br>
    _(It is recommended that you add romhack.exe to your PATH.)_

5)  Run `make` in the root `sc2plus2` folder to compile the code.

6)  Run `$ROMHACK_PATH\\romhack build --raw` to create a new ISO with our changes applied.<br>
    The new ISO is located at `build/sc2plus2.iso`.

## Using Patches

Patch files are a convenient way to share your changes with others.

- To create a patch, run:

  ```
  romhack build --raw --patch
  ```

  The new patch file is located at `build/sc2plus2.patch`.

- To apply a patch, run:

  ```
  romhack apply <example.patch> <ntsc-u-input.iso> <output.iso>
  ```

  Your patched ISO will be named \<output.iso>.
