main() {
  source ./_verify_keyboard_ready_for_boot__source_me.sh

  qmk flash -c -kb lily58/rev1 -km nkondrat -e CONVERT_TO=blok
}

main "${@}" || exit 1
