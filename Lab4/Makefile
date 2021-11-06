default:
	@echo "Please specify exercise that you want to execute. E.g. make -Makefile ex1"
ex1:
	gcc node.c ex1_driver_code.c -o ex1.o
	./ex1.o
ex2:
	gcc array_manipulations.c ex2_driver_code.c -o ex2.o
	./ex2.o
ex3_ll:
	gcc ex3_node.c ex3_driver_code_for_linked-list.c -o ex3_ll.o
	./ex3_ll.o
ex3_am:
	gcc ex3_array_manipulations.c ex3_driver_code_for_array.c -o ex3_am.o
	./ex3_am.o
clean:
	rm *.o

