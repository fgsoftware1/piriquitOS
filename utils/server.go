package main

import (
	"os/exec"
)

func main() {
	cmd := exec.Command("cmd.exe","/C","docker run -u 0 -it --name teamcity-server -v C:/Users/gabri/Desktop/projects/fgOS-BETA/ci/data:/data/teamcity_server/datadir -v /ci/logs:/opt/teamcity/logs -p 8111:8111 jetbrains/teamcity-server")
	cmd.Run()
}