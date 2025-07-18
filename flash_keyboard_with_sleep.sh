main() {
  echo.bold "Sleeping for 5 seconds (before the flash so you can put your keyboard into being ready to accept flashing)..."
  sleep 5

  source ./verify_keyboard_ready_for_boot__source_me.sh

  # Define the path to the compiled firmware file
  local firmware_file="$PWD/.build/lily58_rev1_nkondrat_blok.uf2"

  # Check if the firmware file exists
  if [[ ! -f "$firmware_file" ]]; then
    echo "Error: Compiled firmware not found at [$firmware_file]. Please compile first."
    exit 1
  fi

  # Check if the RP2040 bootloader is mounted
  local bootloader_path
  bootloader_path="$(./get_bootloader_path.sh)" || {
    echo "Error: Failed to get bootloader path. Please ensure the RP2040 is in bootloader mode."
    exit 1
  }

  # Copy the firmware file to the bootloader volume
  echo.log "Flashing firmware by copying [$firmware_file] to [$bootloader_path/NEW.UF2]..."
  cp "$firmware_file" "$bootloader_path/NEW.UF2" || {
    echo "Error: Failed to copy firmware to bootloader volume."
    exit 1
  }

  echo.green "Firmware flashed successfully! The keyboard will now reboot."
}

main "${@}" || exit 1
