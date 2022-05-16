make:
	g++ -c main.cpp System/Collision_System.cpp System/Particles.cpp System/Particle.cpp Trees/pquadtree.cpp
	g++ main.o Collision_System.o Particle.o Particles.o pquadtree.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	rm main.o Collision_System.o Particle.o Particles.o pquadtree.o
	./sfml-app