term:main.o userinf.o lotteryinf.o vol.o mainview.o mainfun.o userfun.o adminfun.o workerfun.o
	gcc main.o userinf.o lotteryinf.o vol.o mainview.o mainfun.o userfun.o adminfun.o workerfun.o -g -o term -Wall

main.o:main.c adminfun.h
	gcc main.c -c
userinf.o:userinf.c userinf.h
	gcc userinf.c -c
lotteryinf.o:lotteryinf.c lotteryinf.h
	gcc lotteryinf.c -c
vol.o:vol.c vol.h
	gcc vol.c -c
mainview.o:mainview.c mainview.h
	gcc mainview.c -c
mainfun.o:mainfun.c mainfun.h
	gcc mainfun.c -c
userfun.o:userfun.c userfun.h
	gcc userfun.c -c
adminfun.o:adminfun.c adminfun.h
	gcc adminfun.c -c
workerfun.o:workerfun.c workerfun.h
	gcc workerfun.c -c
