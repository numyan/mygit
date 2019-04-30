
objects=main.o userinf.o lotteryinf.o vol.o mainview.o mainfun.o userfun.o snake.o adminfun.o workerfun.o

term:$(objects)
	gcc $(objects) -g -o ./bin/term -Wall

	mv *.o ./obj/

main.o:./src/main.c ./lib/workerfun.h
	gcc ./src/main.c -c
userinf.o:./src/userinf.c ./lib/userinf.h
	gcc ./src/userinf.c -c
lotteryinf.o:./src/lotteryinf.c ./lib/lotteryinf.h
	gcc ./src/lotteryinf.c -c
vol.o:./src/vol.c ./lib/vol.h
	gcc ./src/vol.c -c
mainview.o:./src/mainview.c ./lib/mainview.h
	gcc ./src/mainview.c -c
mainfun.o:./src/mainfun.c ./lib/mainfun.h
	gcc ./src/mainfun.c -c
userfun.o:./src/userfun.c ./lib/userfun.h
	gcc ./src/userfun.c -c
snake.o:./src/snake.c ./lib/snake.h
	gcc ./src/snake.c -c
adminfun.o:./src/adminfun.c ./lib/adminfun.h
	gcc ./src/adminfun.c -c
workerfun.o:./src/workerfun.c ./lib/workerfun.h
	gcc ./src/workerfun.c -c
.PHONY:clean
clean:
	rm ./obj/*.o
