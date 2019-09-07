siga: main.o novo_aluno.o carregar_registro.o print_aluno.o ordenar.o insertsort.o mergesort.o comparar_algoritmos.o
	g++ main.o novo_aluno.o carregar_registro.o print_aluno.o ordenar.o insertsort.o mergesort.o comparar_algoritmos.o -o siga

main.o: main.cpp
	g++ -c main.cpp 

novo_aluno.o: novo_aluno.cpp	
	g++ -c novo_aluno.cpp

carregar_registro.o: carregar_registro.cpp
	g++ -c carregar_registro.cpp

print_aluno.o: print_aluno.cpp
	g++ -c print_aluno.cpp 

ordenar.o: ordenar.cpp 
	g++ -c ordenar.cpp

insertsort.o: insertsort.cpp
	g++ -c insertsort.cpp 

mergesort.o: mergesort.cpp
	g++ -c mergesort.cpp

comparar_algoritmos.o: comparar_algoritmos.cpp
	g++ -c comparar_algoritmos.cpp

clean: 
	rm *.o siga