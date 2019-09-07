#!/usr/bin/python3

import numpy as np

#nomes
with open("./assets/nomes.txt", 'r') as infile:
    nomes = [nome.strip() for nome in infile]
    
#cursos 
cursos = ["Matemática", "Física", "Química", "Computação", "Eletrônica", "Letras", "Biblioteconomia",
          "Engenharia", "Arquitetura", "Psicologia"]

def compor_registro(nome):
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

    return aluno_str

#cria registros na ordem em que os nomes aparecem em nomes.txt (versão oficial)
with open("registros.txt", 'w') as outfile:
    for nome in nomes:

        aluno_str = compor_registro(nome)
        outfile.write(aluno_str)


#vamos criar registros em ordens específicas em ./assets 
#para testar os algorítmos de ordenação


#lista parcialmente ordenada por nomes


nomes_parc = sorted(nomes[:500]) + nomes[500:]

with open("./assets/registros_parc.txt", 'w') as outfile:
    for nome in nomes_parc:

        aluno_str = compor_registro(nome)
        outfile.write(aluno_str)

#lista completamente ordenada por nomes 

nomes_sorted = sorted(nomes)

with open("./assets/registros_ord.txt", 'w') as outfile:
    for nome in nomes_sorted:

        aluno_str = compor_registro(nome)
        outfile.write(aluno_str)