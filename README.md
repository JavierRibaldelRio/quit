# Stop
## Description
Stop in an application for Linux terminal, to shutdown, reboot or suspend the computer, is developed in c++. But you can make a shutdown timed. To use it, is necessary to have installed the "sudo" command and the gcc compiler, that usually are pre-installed in the system 

## Requirements

- A Linux distribution
- Have installed sudo
- Gcc compiler

## Installation

1. First you have to make the file executable
```shell
chmod +x install.sh
```

2. An then execute script 
```shell
sudo ./install.sh
```
## Working
```mermaid
graph TD;
A([Start Stop])-->B{Insert: 1 to shutdown,<br>2 to suspend or<br>3 to reboot}

B-- 1:shutdown -->C{Do you want to<BR> add a timer?:}

C--No--> F[sudo shutdown now]-->J

C -- yes --> H>'How long doyou want the timer?'] --> G[/Define: timer as a number/] -->I[ 'sudo shutdown -H ' + timer]-->J



B-- 2:suspend -->D[sudo systemctl supend -i]-->J
B-- 3:reboot -->E[sudo reboot] -->J([End])


	
```

