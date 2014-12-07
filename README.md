# td42

TD 42 is a 2D Tower Defense game made at EPITA, by us,
    - Pierre Gorjux
    - Valentin Iovene
    - Mathieu Corre


# Map format:

We represent each tile by one ASCII character.
Here is the complete list:
    - 'S': The start point for our units.
    - 'T': A tower.
    - 'E': An empty tile.
    - 'F': The finish point for the units.
    - 'O': An obstacle (nothing else can go on this tile).
    - 'B': Like an obstacle.

# Pathfinding



# BuildSystem

For this project, we have chosen CMake, for it's efficiency, and as it is as
easy as fast to set-up.

# Biblio

https://github.com/LaurentGomila/SFML/wiki/Tutorial:-Basic-Game-Engine

# Bonii

    - Gestion de la transparence
    - Affichage de la tour pendant son placement
    - Keyboard shortcuts
    - Open field mode : Pathfinding
    - Map elements
    - Waves
    - Earned money varies with unit type
