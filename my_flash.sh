main() {
    if ! diskutil list | grep --quiet RPI-RP2; then
      echo "Did not find RPI-RP2 in 'diskutil list'. Exiting."
      exit 1
    fi

  qmk flash -c -kb lily58/rev1 -km nkondrat -e CONVERT_TO=blok
}

main "${@}" || exit 1
