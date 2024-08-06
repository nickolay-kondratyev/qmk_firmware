main() {
  eai qmk git-submodule
  eai ./util/qmk_install.sh
}

main "${@}" || exit 1
