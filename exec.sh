[ -d "build" ] && echo "Build dir found" || mkdir build
echo 'Compiling'
gcc -Wall app.c converter.c -o build/app
echo 'Running'
build/./app
