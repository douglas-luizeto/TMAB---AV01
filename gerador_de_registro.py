#!/usr/bin/python3

import numpy as np

#nomes
with open("./assets/nomes.txt", 'r') as infile:
    nomes = [nome.strip() for nome in infile]
    
#cursos 
cursos = ["Matemática", "Física", "Química", "Computação", "Eletrônica", "Letras", "Biblioteconomia",
          "Engenharia", "Arquitetura", "Psicologia"]

with open("registros.txt", 'w') as outfile:
    for nome in nomes:
        #CPF
        aluno_str = ''.join([str(n) for n in np.random.randint(0,9,11)])
        #DRE
        aluno_str += ''.join([str(n) for n in np.random.randint(0,9,9)])
        #Nome 
        aluno_str += nome + ','
        #Curso
        aluno_str += np.random.choice(cursos) + ','
        #Período
        aluno_str += str(np.random.randint(1,12)) + ','
        #Emails (2 por aluno)
        aluno_str += nome + str(np.random.randint(1,22)) + "@gmail.com" + ','
        aluno_str += nome + str(np.random.randint(1,22)) + "@bol.com" + ','
        aluno_str += '&'
        #Tels (1 por aluno)
        aluno_str += ''.join([str(n) for n in np.random.randint(0,9,8)]) + ',' + '\n'   
        
        outfile.write(aluno_str)