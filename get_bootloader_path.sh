#!/usr/bin/env bash

set -euo pipefail


# Function to verify and get bootloader path on macOS
_mac_get_bootloader_path() {
  if ! diskutil list | grep --quiet RPI-RP2; then
    echo "Error: RPI-RP2 not found in 'diskutil list'. Please enter bootloader mode." >&2
    return 1
  fi

  local bootloader_path="/Volumes/RPI-RP2"
  if [[ ! -d "$bootloader_path" ]]; then
    echo "Error: RP2040 bootloader not detected at $bootloader_path. Please enter bootloader mode." >&2
    return 1
  fi

  echo "$bootloader_path"
  return 0
}

# Function to verify and get bootloader path on Linux
_linux_get_bootloader_path() {
  if ! lsblk | grep --quiet RPI-RP2; then
    echo "Error: RPI-RP2 not found in 'lsblk'. Please enter bootloader mode." >&2
    return 1
  fi

  local bootloader_path="/media/$(whoami)/RPI-RP2"
  if [[ ! -d "$bootloader_path" ]]; then
    echo "Error: RP2040 bootloader not detected at $bootloader_path. Please enter bootloader mode." >&2
    return 1
  fi

  echo "$bootloader_path"
  return 0
}

# Main function
main() {
  if is_mac; then
    _mac_get_bootloader_path
  elif is_linux; then
    _linux_get_bootloader_path
  else
    echo "Error: Unsupported OS (uname=$(uname))" >&2
    return 1
  fi
}

main "$@" || exit 1
