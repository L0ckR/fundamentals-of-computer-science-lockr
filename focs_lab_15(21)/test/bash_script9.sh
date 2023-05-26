#!/bin/bash

# функция для удлинения имени файла до заданной длины
function rename_files() {
  local root=$1
  local symbol=$2
  local length=$3

  for filename in "$root"/*; do
    echo $(basename -- $filename)
    if [ -f "$filename" ] && [ "$(basename -- $filename)" != "${0##*/}" ]
    then
      name=$(basename -- "$filename")
      extension="${name##*.}"
      name="${name%.*}"
      filename_length=${#name}
      if [ "$filename_length" -lt "$length" ]; then
        padding_length=$((length - filename_length))
        padding=$(printf "%0.s${symbol}" $(seq 1 $padding_length))
        new_name="${name}${padding}.${extension}"
        mv "$filename" "$root/$new_name"
        echo "Файл $name.$extension переименован в $new_name"
      fi
    fi
  done
}

if [ "$#" == "3" ]
then 
  echo "ok"
    if [ "$1" == "." ]
    then
      rename_files "$PWD" "$2" "$3"
      echo "Готово!"
    else
      rename_files "$1" "$2" "$3"
      echo "Готово!"
    fi
else
  if [ "$#" == "1" ] && [ "$1" == "?" ]
  then
    echo "bash bash_script.sh [root] [symbol] [length]"
    echo -e "\troot - это путь к директории"
    echo -e "\tsymbol - символ, которым будет дополнено имя"
    echo -e "\tlength - желаемая длина имени"
  else
    echo "Аргументы были введены неверно, для справки вызовите с ключом "?"."
  fi
fi