INCLUDES = -I src/ -I thirdparty/ -I ../Lab-1/src/
dirs = ./bin ./obj
test_obj = ./obj/main_test.o ./obj/MT_lib.o ./obj/MSC_lib.o ./obj/test.o
main_obj = ./obj/MT_main.o ./obj/MT_lib.o ./obj/MSC_lib.o

all: ./bin/main ./bin/test testo

./bin/main: $(dirs) $(main_obj)
	gcc $(main_obj) -Wall -o ./bin/main -lm

./bin/test: $(dirs) $(test_obj)
	gcc $(test_obj) -Wall -o ./bin/test -lm

testo:
	./bin/test

$(dirs):
	mkdir obj
	mkdir bin

./obj/MT_main.o: ./src/MT_main.c
	gcc -c ./src/MT_main.c -Wall -o ./obj/MT_main.o $(INCLUDES)

./obj/MT_lib.o: ./src/MT_lib.c
	gcc -c ./src/MT_lib.c -Wall -o ./obj/MT_lib.o $(INCLUDES)

./obj/MSC_lib.o: ./../Lab-1/src/MSC_lib.c
	gcc -c ./../Lab-1/src/MSC_lib.c -Wall -o ./obj/MSC_lib.o $(INCLUDES)

./obj/main_test.o: ./test/main.c
	gcc -c ./test/main.c -Wall -o ./obj/main_test.o $(INCLUDES)

./obj/test.o: ./test/test.c
	gcc -c ./test/test.c -Wall -o ./obj/test.o $(INCLUDES)

.PHONY: clean
clean:
	rm -f -r bin/ obj/ RAM