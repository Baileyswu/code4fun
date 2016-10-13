syntax on
set nu cindent sw=4 sts=4 ts=4
set mouse=a
nmap <F2> :w<CR>
nmap <F3> :make %< <CR>
nmap <F4> :vs %<.in <CR>
nmap <F5> :!./%< < %<.in <CR>
nmap <F6> :!./%< < %<.in > %<.out <CR> :vs %<.out <CR>
nmap <F7> ggVG "+y
nmap <F12> :wq<CR>
nmap <TAB> <SPACE><SPACE><SPACE><SPACE>
colorscheme delek

inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap " ""<ESC>i
inoremap ' ''<ESC>i
inoremap { {<CR>}<ESC>i

