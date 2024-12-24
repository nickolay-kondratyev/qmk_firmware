main() {
  intellij.silently_open ./keyboards/lily58/keymaps/nkondrat/keymap.c
}

main "${@}" || exit 1
