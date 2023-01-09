#!/bin/bash


# SCOPE:
# Run script upon fresh Debian installation;
# expectedly before switching to VSCode and WSL-Remote

# PKGS installed:
# Curl Fortune GCC Git Neofetch Tree Vim Wget Zsh

# RECOMMENDATION:
# Run <script> command beforehand to make typescript of terminal session!!


# Part-1: SYSTEM

# Verify Debian is up to date
sudo apt update

# Create working directory & move to it (documentation: TODO!! )
mkdir ~/foo && cd "$_"

# Save log-1
apt list --installed > defaultDebPkgs.log

# Install wget for 'vscode-wsl'
sudo apt-get install wget -y

# Install some tools
sudo apt install curl git vim zsh -y

# Install OhMyZsh
cd ~ && sh -c "$(wget -O- https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
    # Edit $ZSH_THEME to 'random' ($RANDOM_THEME)

# Install some more tools
sudo apt install fortune neofetch tree -y

# Install GCC compiler
sudo apt install gcc -y

# Save log-2
apt list --installed > scriptDebPkgs.log


# PART-2: C-programming

# Create TEST directory
mkdir -p ~/foo/test && cd "$_"

# Write C code — mind '\' before '"' ONLY because it's 'echo' in a Bash script; remove '\' otherwise
echo "
#include <stdio.h>

int main()
{ 
    printf(\"Hello World!\n\");
    return 0;
}
" > helloWorld.c


# Compile C-file — '-o' denotes 'into new file'
gcc helloWorld.c -o helloWorld

# Run binary
./helloWorld