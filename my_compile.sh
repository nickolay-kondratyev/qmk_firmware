main() {
  qmk compile -kb lily58/rev1 -km nkondrat
}

main "${@}" || exit 1
