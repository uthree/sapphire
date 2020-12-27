cd src/ &&

echo "running bison..." &&
bison -dv parser.y &&
echo "running flex..." &&
flex lexer.l &&


cd .. &&

gcc ./src/main.c -v -ly -o ./sapphire.out