# Programming-II-Final-Project
Final project in my Programming II Course (C++)

In this project, I utilized inheritance in C++ to create a building with rooms in it that the player can move around in. There is no graphical interface; the user interacts with the program via the terminal.

The most interesting part of the project is the memory management. Each room in the building has weak pointers to the rooms adjacent to it. The reason I used weak pointers is because shared pointers created circular ownership of the room objects. This caused a memory leak; the destructors for the rooms were not all called upon termination of the program. Weak pointers solved this problem because weak pointers have no ownership of the objects they point to. They are casual onlookers, if you will. So, this removed the circular ownership of rooms, because there only exists one shared pointer to each room. When those shared pointers go out of scope at the end of the program, the rooms are all destroyed.
