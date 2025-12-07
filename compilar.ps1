#ps
Remove-Item engine\*.o
gcc -c engine\lista.c -o engine\lista.o
gcc -c engine\frame.c -o engine\frame.o
gcc -c engine\animation.c -o engine\animation.o
gcc -c engine\help.c -o engine\help.o
gcc -c engine\entity.c -o engine\entity.o