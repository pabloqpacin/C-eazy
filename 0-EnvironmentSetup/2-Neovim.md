# Neovim Setup

Documentation:
- @NeuralNine: [Awesome Neovim Setup From Scratch - Full Guide](https://youtu.be/JWReY93Vl6g)


## Getting started!

1. [x] Run `script` command
2. [x] Install and prepare **config** file

```bash
# Install Neovim
sudo apt install neovim     # "NEW: 30 packages"

# Create CONFIG dir
mkdir -p ~/.config/nvim && cd "$_"

# Create and edit config file
nvim init.vim               # Notice '~/.local/share/nvim/swap/%.swp'
```

3. [x] Write basic `.config/nvim/init.vim` instructions <!-- notice ":" unlike in former '.vmrc' files-->

```vim
" https://github.com/NeuralNine/config-files/blob/master/init.vim
    :set number
    :set relativenumber
    :set autoindent
    :set tabstop=4
    :set shiftwidth=4
    :set smarttab
    :set softtabstop=4
    ":set mouse=a

" https://github.com/pabloqpacin/dotfiles/blob/main/.vimrc
    :inore jj <Esc>
    :colo pablo
    :map <Left> <NOP>
    :map <Down> <NOP>
    :map <Up> <NOP>
    :map <Right> <NOP>
```

4. [x] Install PLUGINS with [vim-plug](https://github.com/junegunn/vim-plug)

```bash
# Install 'vim-plug' for Neovim
sh -c 'curl -fLo "${XDG_DATA_HOME:-$HOME/.local/share}"/nvim/site/autoload/plug.vim --create-dirs \
       https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
```

5. [x] Add plugins to **'init.vim'** <!--errors with 'Ctrl+V' within NVIM; had to do via VSCode-->

```vim
" ...

call plug#begin()

Plug 'https://github.com/vim-airline/vim-airline'

call plug#end()
```

6. [x] Activate plugin entering command back in **nvim**

```vim
:w
:so %
:PlugInstall
```


<!-- TO-DO
- Continue tutorial from Nerdfonts ON (11:45)
-->