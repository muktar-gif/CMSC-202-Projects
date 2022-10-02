CXX = g++
CXXFLAGS = -Wall

proj4: Game.o Rogue.o Wizard.o Paladin.o Skeleton.o Goblin.o BabyDragon.o Character.o Monster.o Entity.o Room.o proj4.cpp
	$(CXX) $(CXXFLAGS) Game.o Rogue.o Wizard.o Paladin.o Skeleton.o Goblin.o BabyDragon.o Character.o Monster.o Entity.o Room.o proj4.cpp -o proj4

Game.o: Game.cpp Game.h Rogue.o Wizard.o Paladin.o Skeleton.o Goblin.o BabyDragon.o Character.o Monster.o Entity.o Room.o
	$(CXX) $(CXXFLAGS) -c Game.cpp

Rouge.o: Character.o Entity.o Rogue.cpp Rogue.h
	$(CXX) $(CXXFLAGS) -c Rogue.cpp

Wizard.o: Character.o Entity.o Wizard.cpp Wizard.h
	$(CXX) $(CXXFLAGS) -c Wizard.cpp

Paladin.o: Character.o Entity.o Paladin.cpp Paladin.h
	$(CXX) $(CXXFLAGS) -c Paladin.cpp

Skeleton.o: Monster.o Entity.o Skeleton.cpp Skeleton.h
	$(CXX) $(CXXFLAGS) -c Skeleton.cpp

Goblin.o: Monster.o Entity.o Goblin.cpp Goblin.h
	$(CXX) $(CXXFLAGS) -c Goblin.cpp

BabyDragon.o: Monster.o Entity.o BabyDragon.cpp BabyDragon.h
	$(CXX) $(CXXFLAGS) -c BabyDragon.cpp

Character.o: Entity.o Character.cpp Character.h
	$(CXX) $(CXXFLAGS) -c Character.cpp

Monster.o: Entity.o Monster.cpp Monster.h
	$(CXX) $(CXXFLAGS) -c Monster.cpp

Entity.o: Entity.cpp Entity.h
	$(CXX) $(CXXFLAGS) -c Entity.cpp

Room.o: Room.cpp Room.h
	$(CXX) $(CXXFLAGS) -c Room.cpp

run1:
	./proj4 map1_data.txt

val1:
	./proj4 map1_data.txt

run2:
	./proj4 map2_data.txt

val2:
	./proj4 map2_data.txt
clean:
	rm *~
