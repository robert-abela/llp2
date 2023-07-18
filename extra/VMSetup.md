# Systems Programming Linux Setup

## Step 0: Get a Linux running
It is suggested to create a VM using latest LTS of your preferred Linux. You can use [Zorin](https://zorin.com/os/download/16/core/), [Ubuntu](https://ubuntu.com/download/desktop), [Xubuntu](http://ftp.uni-kl.de/pub/linux/ubuntu-dvd/xubuntu/releases/20.04/release/) or any Linux from [Debian family](https://en.wikipedia.org/wiki/List_of_Linux_distributions#Debian-based).

If you need VM software, you can use:
- [VMWare Pro (trial)](https://www.vmware.com/go/getworkstation-win) - ask me for a license, don't pirate software!
- [VMWare Player (free)](https://www.vmware.com/go/getplayer-win) - some limitations (e.g. no snapshots)
- [VirtualBox](https://www.virtualbox.org/wiki/Downloads) - use this if your computer does not like VMWare.

## Step 1: Update Linux
    sudo apt update && sudo apt upgrade

## Step 2: Install Visual Studio Code
    sudo apt install software-properties-common apt-transport-https wget
    wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add -
    sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main"
    sudo apt update
    sudo apt install code

## Step 3: Install Chrome
    sudo apt-get install chromium-browser

## Step 4: Install development tools
    sudo apt-get install gcc make gdb git g++

## Step 5: Clone git repository
    mkdir ~/git/
    cd ~/git/
    git clone https://github.com/robert-abela/llp2

- [Optional GitHub Desktop](https://github.com/kontr0x/github-desktop-install#readme)
