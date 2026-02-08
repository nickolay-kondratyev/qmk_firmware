_mac_verify_keyboard_ready_for_boot() {
  if ! diskutil list | grep --quiet RPI-RP2; then
    echo.yellow "Did not find RPI-RP2 in 'diskutil list'. Exiting."
    exit 1
  else
    echo.log "Found RPI-RP2 in 'diskutil list'. Deeming as ready for boot. Continuing."
  fi

  # Ensure the RP2040 is mounted and ready
  local bootloader_path="/Volumes/RPI-RP2"
  if [[ ! -d "$bootloader_path" ]]; then
      echo.yellow "Error: RP2040 bootloader not detected at $bootloader_path. Please enter bootloader mode."
      exit 1
  else
      echo.log "RP2040 bootloader detected at $bootloader_path. Continuing."
  fi
}

_linux_verify_keyboard_ready_for_boot() {
  if ! lsblk | grep --quiet RPI-RP2; then
    echo.yellow "Did not find RPI-RP2 in 'lsblk'. Exiting."
    exit 1
  else
    echo.log "Found RPI-RP2 in 'lsblk'. Deeming as ready for boot. Continuing."
  fi

  # Ensure the RP2040 is mounted and ready
  # Fedora mounts at /run/media/, Ubuntu/PopOS at /media/
  local bootloader_path="/run/media/$(whoami)/RPI-RP2"
  if [[ ! -d "$bootloader_path" ]]; then
    bootloader_path="/media/$(whoami)/RPI-RP2"
  fi
  if [[ ! -d "$bootloader_path" ]]; then
    echo.yellow "Error: RP2040 bootloader not detected at $bootloader_path. Please enter bootloader mode."
    exit 1
  else
    echo.log "RP2040 bootloader detected at $bootloader_path. Continuing."
  fi
}

main() {
  if is_mac; then
    _mac_verify_keyboard_ready_for_boot
  elif is_linux; then
    # Linux with PopOS/Ubuntu
    _linux_verify_keyboard_ready_for_boot
  else
    throw "Unsupported OS uname=[$(uname)]"
  fi
}

main "${@}" || exit 1
