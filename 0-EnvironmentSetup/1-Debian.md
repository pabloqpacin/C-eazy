# Debian Setup


1. [x] Read documentation (@Microsoft: [Install Linux on Windows with WSL](https://learn.microsoft.com/en-us/windows/wsl/install))

2. [x] Install **Debian** for WSL —alongside Ubuntu— via **PowerShell**

```powershell
wsl --list                  # See installed distros
wsl -l -v                   # See WSL version of such

wsl --list --online         # See available distros
wsl -l -o

wsl --install -d Debian     # Install Debian
```

3. [x] Basic tweaks post-install: curl, git, vim, wget, zsh

```bash
# Update the system; in our case, 'up to date'
sudo apt update

# Save log (OPTIONAL)
mkdir -p ~/foo && cd "$_"
    apt list --installed > log01.txt

# Install 'wget' to run VSCode-server via WSL
sudo apt-get install wget

# Install Curl, Git, Vim and OhMyZsh (OhMyZsh can also be installed via 'Curl')
sudo apt install curl git vim zsh
cd ~ && sh -c "$(wget -O- https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

# Install extra tools (OPTIONAL)
sudo apt install fortune neofetch tree
```

4. [ ] Setup [dotfiles](https://github.com/pabloqpacin/dotfiles) — especially **.vimrc**


5. [x] Install compiler
   1. [ ] ~~minwg~~
   2. [x] gcc — [gcc 101s](https://www.cs.binghamton.edu/~rhainin1/walkthroughs/gccbasics.html)

```bash
gcc --version           # "zsh: command not found: gcc"
whereis gcc             # "gcc: /usr/share/gcc"

sudo apt install gcc    # "NEW: 33 packages"
gcc --version           # success message

whereis gcc             # gcc: /usr/bin/gcc /usr/lib/gcc /usr/share/gcc
```

<!--
NEOVIM
`sudo apt remove vim -y && sudo apt autoremove` ('vim-runtime')
-->