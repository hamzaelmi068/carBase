# makefile for A3 - 
# target: dependencies...
# 		gcc -Wall -std=c99 -c fileName.c

# Assingment 3, is due april 5 11:59pm

carBase: mainA3.o addNewCar.o loadCarData.o printAll.o printOne.o lookForCarId.o lookForCarModelType.o countCars.o sortCarId.o oneLessCar.o noMoreCars.o 
	gcc -Wall -std=c99 mainA3.o addNewCar.o loadCarData.o printAll.o printOne.o lookForCarId.o lookForCarModelType.o countCars.o sortCarId.o oneLessCar.o noMoreCars.o -o bin/carBase

# main file
mainA3.o: src/mainA3.c include/headerA3.h
	gcc -Wall -std=c99 -c src/mainA3.c
# first function
addNewCar.o: src/addNewCar.c include/headerA3.h
	gcc -Wall -std=c99 -c src/addNewCar.c
# second fun
loadCarData.o: src/loadCarData.c include/headerA3.h
	gcc -Wall -std=c99 -c src/loadCarData.c
# third func
printAll.o: src/printAll.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printAll.c
# fourth func
printOne.o: src/printOne.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printOne.c
# fifth func
lookForCarId.o: src/lookForCarId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookForCarId.c
# sixth func
lookForCarModelType.o: src/lookForCarModelType.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookForCarModelType.c
# seventh func
countCars.o: src/countCars.c include/headerA3.h 
	gcc -Wall -std=c99 -c src/countCars.c
# eight func
sortCarId.o: src/sortCarId.c include/headerA3.h 
	gcc -Wall -std=c99 -c src/sortCarId.c
# ninth func
oneLessCar.o: src/oneLessCar.c include/headerA3.h
	gcc -Wall -std=c99 -c src/oneLessCar.c
# tenth func
noMoreCars.o: src/noMoreCars.c include/headerA3.h
	gcc -Wall -std=c99 -c src/noMoreCars.c

#formatPrice.o: src/formatPrice.c include/headerA3.h
#	gcc -Wall -std=c99 -c src/formatPrice.c

# removes all object files and the executable file (carBase) 
clean:
	rm *.o
	cd bin && rm carBase

# rm *.o carBase
# cd bin && rm carBase