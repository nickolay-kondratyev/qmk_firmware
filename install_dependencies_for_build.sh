main() {
  if is_mac; then
    eai brew install qmk/qmk/qmk
  elif is_linux; then
    # I am not sure if this is enough
    echo.bold "NOT SURE IF THIS IS ENOUGH FOR INSTALL!!!!"
    echo.bold "NOT SURE IF THIS IS ENOUGH FOR INSTALL!!!!"
    echo.bold "NOT SURE IF THIS IS ENOUGH FOR INSTALL!!!!"
    eai brew install pipx
    eai pipx install qmk
  else
    throw "Unsupported OS uname=[$(uname)]"
  fi


  eai qmk git-submodule
  eai ./util/qmk_install.sh
}

main "${@}" || exit 1
