if ! diskutil list | grep --quiet RPI-RP2; then
    echo "Did not find RPI-RP2 in 'diskutil list'. Exiting."
    exit 1
fi
