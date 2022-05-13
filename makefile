make:
	g++ -c main.cpp Collision_System.cpp Particles.cpp Particle.cpp quadtree.cpp
	g++ main.o Collision_System.o Particle.o Particles.o quadtree.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	rm main.o Collision_System.o Particle.o Particles.o quadtree.o
	./sfml-app