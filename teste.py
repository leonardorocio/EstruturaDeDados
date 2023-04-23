import os
import sys

cwd = os.getcwd()
print(cwd)
for root, dirs, files in os.walk(cwd):
    for file in files:
        fpath = os.path.join(root, file)
        f, ext = os.path.splitext(fpath)
        if ext in [".o", ".exe"]:
            print(f'Arquivo deletado: {fpath}')
            os.remove(fpath)
