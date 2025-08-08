g++ 06-main.cpp MTexture06.cpp -std=c++2a ^
-I "..\lib\SDL3-3.2.18\x86_64-w64-mingw32\include" -L "..\lib\SDL3-3.2.18\x86_64-w64-mingw32\lib" -lSDL3 ^
-I "..\lib\SDL3_image-3.2.4\x86_64-w64-mingw32\include" -L "..\lib\SDL3_image-3.2.4\x86_64-w64-mingw32\lib" -lSDL3_image ^
-o ../main.exe && start ../main.exe