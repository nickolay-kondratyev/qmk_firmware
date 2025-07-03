Note: [QMK](thorg://notes/9e5ihl98dfsrkg80r0b1mqd)

### Keymap location
```bash
ii ${QMK_KEYBOARD_MAPPINGS:?}/keyboards/lily58/keymaps/nkondrat/keymap.c
```


### To put into boot ready mode 
- `RAISE + LOWER + ESC`
  - Run the following to verify `./verify_keyboard_ready_for_boot__source_me.sh`

### Scripts
- [./install_dependencies_for_build.sh](./install_dependencies_for_build.sh): prior to build no keyboard interaction.
- [compile.sh](./compile.sh) to do the compilation.
- [flash_keyboard_with_sleep.sh](./flash_keyboard_with_sleep.sh) to flash the firmware.

--------------------------------------------------------------------------------
### More references
####  Setup links
- [The QMK Tutorial](https://docs.qmk.fm/newbs)
- [Setting Up Your QMK Environment | QMK Firmware](https://docs.qmk.fm/newbs_getting_started)
- [Building Your First Firmware | QMK Firmware](https://docs.qmk.fm/newbs_building_firmware)
- [Flashing Your Keyboard | QMK Firmware](https://docs.qmk.fm/newbs_flashing)
#### More links
- [QMK & Blok reddit](https://www.reddit.com/r/ErgoMechKeyboards/comments/1csopi7/compiling_qmk_to_blok_anyone_succeeded/)
- [resource](https://www.vikasraj.dev/blog/qmk-pi-pico-rp2040)


### Original REPO
- https://github.com/qmk/qmk_firmware

