INCLUDES = -I src/ -I thirdparty/
dirs = ./bin ./obj
test_obj = ./obj/main_test.o ./obj/MSC_lib.o  ./obj/test.o
main_obj = ./obj/MSC_main.o ./obj/MSC_lib.o 

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

./obj/MSC_main.o: ./src/MSC_main.c
	gcc -c ./src/MSC_main.c -Wall -o ./obj/MSC_main.o $(INCLUDES)

./obj/MSC_lib.o: ./src/MSC_lib.c
	gcc -c ./src/MSC_lib.c -Wall -o ./obj/MSC_lib.o $(INCLUDES)

./obj/main_test.o: ./test/main.c
	gcc -c ./test/main.c -Wall -o ./obj/main_test.o $(INCLUDES)

./obj/test.o: ./test/test.c
	gcc -c ./test/test.c -Wall -o ./obj/test.o $(INCLUDES)

.PHONY: clean
clean:
	rm -f -r bin/ obj/ RAM