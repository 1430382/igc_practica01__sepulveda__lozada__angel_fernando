#NombreProgramaFuente=Square
NombreProgramaFuente=practica01_sepulveda_lozada_angel_fernando

rm $NombreProgramaFuente
g++ $NombreProgramaFuente.cpp -o $NombreProgramaFuente -lGL -lglut -lGLEW -lm
./$NombreProgramaFuente
