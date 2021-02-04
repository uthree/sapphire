cd src/ &&

echo "running bison..." &&
bison -dv parser.y &&
echo "running flex..." &&
flex scanner.l &&


cd .. &&

g++ ./src/main.cpp -v -ly -o ./sapphire.out