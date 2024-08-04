main() {
  qmk flash -c -kb lily58/rev1 -km nkondrat -e CONVERT_TO=blok
}

main "${@}" || exit 1
