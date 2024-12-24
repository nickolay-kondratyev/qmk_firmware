

main() {
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

main "${@}" || exit 1
