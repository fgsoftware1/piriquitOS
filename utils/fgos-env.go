package main

import (
	"os/exec"
)

func main() {
	cmd := exec.Command("cmd.exe","/C","docker run -u 0 -it --name fgos-env ")
	cmd.Run()
}