In this project I recode the system’s command ls. It works fine on OS X El Capitan, I didn't test it on another OS's.
It has no memory leaks. My ls supports the following flags: -A -R -@ -a -l -f -r -t -1. You can read about it in man.
These flags work like in standard ls. You need to use Makefile to compile my program. Binary will have name ft_ls.