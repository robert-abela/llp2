# Systems Programming Linux Setup

## Step 0: Get a Linux running
It is suggested to create a VM using latest LTS of your preferred Linux. Suggestions:
- I use [Zorin 16](https://zorin.com/os/download/16/core/) 
- MCAST uses [xubuntu](http://ftp.uni-kl.de/pub/linux/ubuntu-dvd/xubuntu/releases/20.04/release/) 
- Any Linux is fine, ideally pick from [Debian family](https://en.wikipedia.org/wiki/List_of_Linux_distributions#Debian-based)

If you need VM software, you can use:
- VMWare Pro (ask me for a license, don't pirate software!)
- VMWare Player
- VirtualBox

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

## Optional Steps

# Optional Step 1: Install the default JDK
    sudo apt-get install default-jdk

# Optional Step 2: Install Eclipse
- Go to https://www.eclipse.org/downloads/packages/release/2020-06/r/eclipse-ide-cc-developers
- Download Eclipse for Linux 64-bit
- Extract contents to /home/llp2/eclipse

# Optional Step 3: Create eclipse shortcut
    cd /usr/bin
    sudo ln -s ~/eclipse/eclipse

Create a ``/usr/share/applications/eclipse.desktop`` file with the following contents:

    [Desktop Entry]
    Name=Eclipse 
    Type=Application
    Exec=eclipse
    Terminal=false
    Icon=~/eclipse/icon.xpm
    Comment=Integrated Development Environment
    NoDisplay=false
    Categories=Development;IDE;
    Name[en]=Eclipse