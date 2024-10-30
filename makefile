bin/programa : src/main.cpp include/*.hpp
	g++ src/main.cpp -Iinclude -o bin/programa

bin/animacion : src/animacion.cpp include/*.hpp
	g++ src/animacion.cpp -Iinclude -o bin/animacion -lftxui-screen -lftxui-dom -lftxui-component -std=c++2a

bin/Prueba : src/Prueba.cpp include/*.hpp
	g++ src/Prueba.cpp -Iinclude -o bin/Prueba -lftxui-screen -lftxui-dom -lftxui-component -std=c++2a

ejecutar: bin/programa
	./bin/programa

ejecutar2: bin/animacion
	./bin/animacion

ejecutar3: bin/Prueba
	./bin/Prueba

clean : bin/programa
	rm bin/programa
	