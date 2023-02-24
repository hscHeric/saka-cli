#!/bin/bash

# Se o número de argumentos for igual a 1, define o valor máximo como o argumento passado
# e o valor mínimo como 0.
if [ $# -eq 1 ]; then
  max_mem=$(($1*1024))
  min_mem=0
# Se o número de argumentos for igual a 2, define o valor máximo como o primeiro argumento
# e o valor mínimo como o segundo argumento.
elif [ $# -eq 2 ]; then
  max_mem=$(($1*1024))
  min_mem=$(($2*1024))
# Se o número de argumentos for diferente de 1 ou 2, exibe uma mensagem de erro e sai do script.
else
  echo "Uso: $0 [memória máxima] [memória mínima (opcional)]"
  exit 1
fi

# Obtém uma lista de todos os processos e suas informações de memória,
# ignorando a primeira linha que contém o cabeçalho.
processes=$(ps -e -o pid,user,comm,rss --sort=-rss | sed '1d')

# Cria o cabeçalho da tabela.
header="ID\tNOME\tMEMÓRIA (MB)\n"

# Inicializa a variável que vai armazenar as informações dos processos filtrados.
filtered_processes=""

# Filtra os processos que usam memória entre os limites definidos.
while read -r line; do
  pid=$(echo $line | awk '{print $1}')
  name=$(echo $line | awk '{print $3}')
  mem=$(echo $line | awk '{print $4}')
  mem_mb=$(($mem/1024))
  if [ $mem -ge $min_mem ] && [ $mem -le $max_mem ]; then
    filtered_processes+="$pid\t$name\t$mem_mb\n"
  fi
done <<< "$processes"

# Ordena os processos filtrados por quantidade de memória usada.
filtered_processes=$(echo -e "$filtered_processes" | sort -rnk 3)

# Exibe a tabela com as informações dos processos filtrados.
echo -e "$header$filtered_processes"
