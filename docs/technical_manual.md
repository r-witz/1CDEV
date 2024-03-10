# Technical Documentation
 ```
             ▄█▀▀▀█▄█
           ▄██    ▀█
            ▀███▄   ▀███  ▀███ ▀████████▄  ▄▄█▀██▀████████▄█████▄   ▄██▀██▄▀████████▄
             ▀█████▄ ██    ██   ██   ▀██ ▄█▀   ██ ██    ██    ██  ██▀   ▀██ ██    ██
           ▄     ▀██ ██    ██   ██    ██ ██▀▀▀▀▀▀ ██    ██    ██  ██     ██ ██    ██
           ██     ██ ██    ██   ██   ▄██ ██▄    ▄ ██    ██    ██  ██▄   ▄██ ██    ██
           █▀█████▀  ▀████▀███▄ ██████▀   ▀█████▀████  ████  ████▄ ▀█████▀▄████  ████▄
                                ██
                              ▄████▄
```


## Overview and Purpose

The Supémon CLI game project is commissioned by SUPINFO World CLI Gaming with the objective of developing a console-based version of Pokémon using the C programming language. Named "Supémon", this project challenges students to apply their knowledge gained during the course while also encouraging research and problem-solving to complete certain aspects. The project duration spans three weeks and is to be completed by groups of up to two students, with a single exception for groups consisting of three members under specific circumstances.

The primary goal of the Supémon project is to recreate the core gameplay elements of Pokémon in a command-line interface environment. Players will be able to engage in battles, capture and train Supémons, manage their inventory, and explore the game world. Adherence to coding standards, proper documentation, and version control practices are crucial for the successful completion of the project.

## Installation and Setup

To set up the Supémon CLI game project on your system, follow these steps depending on your Operating System:

### Windows

1. First you have the make sure git and gcc or another compiler are installed on your system. You can check by doing so :
    ```bash
    git --version
    gcc --version
    ```

2. **Clone the Repository:** Open Powershell and run the following command to clone the repository :
    ```bash
    git clone https://github.com/r-witz/1CDEV.git
    ```

3. **Navigate to the Directory:** Change your current directory to the cloned repository:
    ```bash
    cd 1CDEV
    ```

4. **Compile the Game:** Run the following command to compile the game:
     ```bash
     gcc src/*.c -o run
     ```

5. **Run the Game:** Launch the game using the following command
    ```bash
    ./run.exe
    ```

### Linux / MacOS

1. **Clone the Repository:** Open Terminal and run the following command to clone the repository:
   ```bash
   git clone https://github.com/r-witz/1CDEV.git
   ```
   
2. **Navigate to the Directory:** Change your current directory to the cloned repository:
   ```bash
   cd 1CDEV
   ```

3. **Compile and Run the Game:** Run the following command to compile and launch the game:
   ```bash
   make run
   ```

## Code Structure

The Supémon CLI game project follows a structured organization of source code files and directories:

```
1CDEV/
│
├─ backup/                  Reserved folder for storing save files as well as Supemon's data.
│  ├─ move.json                 Houses the data for every move existing in the game.
│  ├─ player.json               Contains the player's save.
│  └─ supemon.json              Enclose all the data for every supemon.
│
├─ bin/                     Reserved for compiled files created by the make command.
│
├─ docs/                    Stores documentation files (.md).
│  ├─ technical_manual.md       Houses the technical documention made for developers.
│  └─ user_guide.md             Contains the user documentation as well as the rules.
│
├─ include/                 Houses all header files (.h).
│
├─ src/                     Contains all source code files (.c).
│  ├─ battle.c                  Implement all the battle system of the game.
│  ├─ cJSON.c                   Houses the cJSON entire library, shipped with the project.
│  ├─ display.c                 Enclose all the menu's print.
│  ├─ input.c                   Contains the input function used accross all the project.
│  ├─ main.c                    The program from where everything is launched
│  ├─ menu.c                    Enclose the begining's menu as well as the main menu.
│  ├─ player.c                  Houses the creation, saving and loading of the player.
│  ├─ pokecenter.c              Implement the pokecenter system (healing, and displaying team).
│  ├─ shop.c                    Reserved for the shop implementation.
│  ├─ starter.c                 Handle the starter donation at game start.
│  └─ supemon.c                 Enclose the implementation of Supemon creation and load.
│
├─ .gitignore               Specifying files and directory to be ignored by VCS.
├─ LICENSE                  Specifying the terms for using and distributing the project code.
├─ makefile                 For building the project, specifying compilation instructions.
└─ README.md                Provide an overview of the project.
```

## Contributing Guidelines

Contributors are encouraged to adhere to the following guidelines when contributing to the project:

### Code Style:
Follow the coding style conventions specified below, including file naming conventions, variable and function naming conventions.

1. **File Naming Conventions:**

    - C source files: Use descriptive names related to their functionality, all lowercase with underscores for spaces (e.g., `main.c`, `battle_system.c`, `player.c`).
    - Header files: Same naming convention as source files with the `.h` extension (e.g., `main.h`, `battle_system.h`, `player.h`).
    - Documentation files: Use clear names like `user_documentation.md`, `technical_documentation.md`.

    </br>

2. **Variables and Functions Naming Convention:**

    - **snake_case:** For variable and function names (e.g., `player_turn`, `game_state`).
    - **Constants UPPERCASE:** For constants (e.g., `BOARD_SIZE`, `MAX_PLAYERS`).

    </br>

### Modularity:
- Ensure modularity and maintainability of code by keeping functions small, focusing on single responsibilities</br>
- Use meaningful and descriptive names for variables and functions to enhance code readability.</br>
- Global variables are forbidden. Limit the scope of variables wherever possible by declaring them inside the smallest scope that applies, such as inside a function or a block

### Documentation:
Update documentation (both user and technical) for any changes made to the codebase, including new features, bug fixes, and refactoring efforts.

### Version Control:
Use Git for version control, and adhere to the commit message structure and branch naming conventions outlined in the [git conventional commits](https://www.conventionalcommits.org/en/v1.0.0/
). Here are some highlights about it :

**Commit Types:**

1. **feat:** Use for new features implemented.
2. **fix:** Use for bug fixes.
3. **refactor:** Use for code refactoring.
4. **docs:** Use for documentation updates.
5. **test:** Use for adding or modifying tests.
6. **chore:** Use for general maintenance or miscellaneous tasks.

Add "!" at the end of the keyword to denote a breaking change (e.g., `feat!`, `fix!`, etc.).

**Example Commit Messages:**

- feat!(graphics): Add new background image
- fix(network): Fix connection timeout issue
- docs(user): Update user manual for gameplay instructions
- test(utils): Add unit tests for utility function
- refactor(game): Refactor game logic for improved performance
- chore!(deps): Update dependencies to latest versions

## References and Resources

The following external library is utilized in the Supémon CLI game project:
- **cJSON**: A lightweight JSON parser library for C. It is used for parsing and manipulating JSON data structures in the project. More information about cJSON can be found at [cJSON GitHub Repository](https://github.com/DaveGamble/cJSON).
