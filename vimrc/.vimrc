" General {

set nocompatible            " Must be first line
let mapleader=","

set incsearch
set ignorecase smartcase

set background=dark         " Assume a dark background

filetype plugin indent on   " Automatically detect file types.
syntax on                   " Syntax highlighting

" encodings
set encoding=utf-8
set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1

"set ruler
set cursorline

set history=1000                    " Store a ton of history (default is 20)
set hidden                          " Allow buffer switching without saving

set backspace=indent,eol,start  " Backspace for dummies
set linespace=0                 " No extra spaces between rows
set number                      " Line numbers on
set showmatch                   " Show matching brackets/parenthesis
set incsearch                   " Find as you type search
set hlsearch                    " Highlight search terms
set winminheight=0              " Windows can be 0 line high
set ignorecase                  " Case insensitive search
set smartcase                   " Case sensitive when uc present
set wildmenu                    " Show list instead of just completing
set wildmode=list:longest,full  " Command <Tab> completion, list matches, then longest common part, then all.
set whichwrap=b,s,h,l,<,>,[,]   " Backspace and cursor keys wrap too
set scrolljump=5                " Lines to scroll when cursor leaves screen
set scrolloff=3                 " Minimum lines to keep above and below cursor
set foldenable                  " Auto fold code
set list
set listchars=tab:›\ ,trail:•,extends:#,nbsp:. " Highlight problematic whitespace

" }

" Fullscreen {
"
if has("gui_running")
    if has('win32')
        autocmd GUIEnter * simalt ~x
    else
        " GUI is running or is about to start.
        " Maximize gvim window (for an alternative on Windows, see simalt below).
        set lines=999 columns=999
    endif
endif
"
" }

" GUI {
"
if has('gui_running')
    set gcr=i:ver1
    set gcr+=a:blinkon0

    set guioptions-=l
    set guioptions-=L
    set guioptions-=r
    set guioptions-=R

    set guioptions-=m
    set guioptions-=T

    if has('unix')
        set guifont=Monaco\ 12
    endif
    if has('win32')
        set guifont=Consolas:h13
    endif
endif
"
" }

" Formatting {

set nowrap                      " Do not wrap long lines
set autoindent                  " Indent at the same level of the previous line
set shiftwidth=4                " Use indents of 4 spaces
set expandtab                   " Tabs are spaces, not tabs
set tabstop=4                   " An indentation every four columns
set softtabstop=4               " Let backspace delete indent
set nojoinspaces                " Prevents inserting two spaces after punctuation on a join (J)
set splitright                  " Puts new vsplit windows to the right of the current
set splitbelow                  " Puts new split windows to the bottom of the current

" }

" Backup {
if has('win32')
    set backupdir=$VIM/_backup
    set backup

    set undodir=$VIM/_undo
    set undofile

    set directory=$VIM/_swp
else
    set backupdir=~/.vim/.backup
    set backup

    set undodir=~/.vim/.undo
    set undofile

    set directory=~/.vim/.swp
endif
"}

" Clipboard {

vnoremap <Leader>y "+y
nmap <Leader>p "+p

" }


" Plugins {

call plug#begin('~/.vim/plugged')

Plug 'tomasr/molokai'
Plug 'vim-airline/vim-airline'
Plug 'octol/vim-cpp-enhanced-highlight'
Plug 'scrooloose/nerdcommenter'
Plug 'vim-scripts/a.vim'
Plug 'Raimondi/delimitMate'
Plug 'mileszs/ack.vim'
Plug 'Yggdroot/LeaderF'
Plug 'nathanaelkane/vim-indent-guides'
Plug 'rhysd/vim-clang-format'

"Plug 'prabirshrestha/async.vim'
"Plug 'prabirshrestha/vim-lsp'
"Plug 'ajh17/vimcompletesme'
"Plug 'tpope/vim-fugitive'
"Plug 'vim-scripts/AutoComplPop'
"Plug 'SirVer/ultisnips'
"Plug 'honza/vim-snippets'
"Plug 'terryma/vim-multiple-cursors'
"Plug 'tpope/vim-surround'
"Plug 'easymotion/vim-easymotion'

call plug#end()

" }

" Leaderf {
noremap <F2> :LeaderfFunction<cr>
" }

" vim-indent-guides {
let g:indent_guides_enable_on_vim_startup = 1
let g:indent_guides_start_level = 1
let g:indent_guides_guide_size = 1
let g:indent_guides_tab_guides = 0
" }

" colorscheme {
colorscheme molokai
" }

" Ack settings {
if executable('ag')
    let g:ackprg = 'ag --vimgrep'
    nnoremap \ :Ack!<SPACE>
endif
" }

" vim-clang-format {
if has('win32')
    let g:clang_format#command='C:\Program Files\LLVM\bin\clang-format.exe'
endif
let g:clang_format#detect_style_file = 1

" map to <Leader>cf in C++ code
autocmd FileType c,cpp nnoremap <buffer><Leader>cf :<C-u>ClangFormat<CR>
autocmd FileType c,cpp vnoremap <buffer><Leader>cf :ClangFormat<CR>
" }

" vim-lsp for clangd {
"if has('win32')
    "let s:my_clangd_path='C:\Program Files\LLVM\bin\clangd.exe'
    "if executable(s:my_clangd_path)
        "au User lsp_setup call lsp#register_server({
                    "\ 'name': 'clangd',
                    "\ 'cmd': {server_info->[''.s:my_clangd_path, '-background-index']},
                    "\ 'whitelist': ['c', 'cpp', 'objc', 'objcpp'],
                    "\ })
        "autocmd FileType c setlocal omnifunc=lsp#complete
        "autocmd FileType cpp setlocal omnifunc=lsp#complete
        "autocmd FileType objc setlocal omnifunc=lsp#complete
        "autocmd FileType objcpp setlocal omnifunc=lsp#complete
    "endif
"endif
" }
