main() {
    eai ./compile.sh
    eai ./flash_keyboard.sh
}

main "${@}" || exit 1
