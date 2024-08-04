main() {
  eai ./my_compile.sh
  eai ./my_flash.sh
}

main "${@}" || exit 1
