#!/bin/bash

gcc -w -framework GLUT -framework OpenGL ./src/$1 -o ./bin/$2
./bin/$2
