main() {
  source ./_verify_keyboard_ready_for_boot__source_me.sh

  eai ./my_compile.sh
  eai ./my_flash.sh
}

main "${@}" || exit 1
