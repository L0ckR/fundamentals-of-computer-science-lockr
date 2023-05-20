#!/bin/python3


#основная программа
from os import listdir, replace, getcwd
from os.path import isfile, splitext, join
from sys import argv


def main(root: str, symbol: str, length: int):
    length = int(length)
    for filename in listdir(root):
        if filename == 'python_script9.py':
            continue
        if isfile(join(root, filename)):
            name, extension = splitext(filename)
            filename_length = len(name)
            if filename_length < length:
                padding_length = length - filename_length
                padding = symbol * padding_length
                new_name = f"{name}{padding}{extension}"
                replace(join(root, filename), join(root, new_name))
                print(f"Файл {filename} переименован в {new_name}")

if __name__ == '__main__':
    if len(argv) != 3 and argv[1] != '?':
        print('Аргументы были введены неверно, для справки вызовите с ключом "?".')
    else:
        if argv[1] == '?':
            print("py python_script9.py [root] [symbol] [length]")
            print("\troot - это путь к директории")
            print("\tsymbol - символ, которым будет дополнено имя")
            print("\tlength - желаемая длина имени")
        elif argv[1] == '.':
            main(getcwd(), argv[2], argv[3])
            print("Готово!")
        else:
            main(argv[1], argv[2], argv[3])
            print("Готово!")
