if has("syntax")
	syntax on
endif

set nu
set mouse=a
set hlsearch
set list listchars=tab:>-,trail:~,eol:$

let data_dir = has('nvim') ? stdpath('data') . '/site' : '~/.vim'
if empty(glob(data_dir . '/autoload/plug.vim'))
	silent execute '!curl -fLo '.data_dir.'/autoload/plug.vim --create-dirs  https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
	autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif

call plug#begin('~/.vim/plugged')

Plug ('preservim/nerdtree')
Plug ('nanotech/jellybeans.vim')
Plug ('itchyny/lightline.vim')
call plug#end()

colorscheme jellybeans
let NERDTreeShowHidden=1
nmap nerd :NERDTreeToggle<CR>
