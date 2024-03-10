# User Guide
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

## Introduction

Welcome to Supémon, a command-line interface (CLI) game inspired by Pokémon! In Supémon, you embark on an adventure where you capture and train Supémons, engage in battles, and explore various in-game features. This document provides instructions on how to install and play Supémon on different operating systems.

## Installation

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

6. **Enjoy Playing**:
   Once the game is launched, follow the on-screen instructions to start playing and explore the world of Supémon.


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

4. **Enjoy Playing**:
   Once the game is launched, follow the on-screen instructions to start playing and explore the world of Supémon.


## How to Play

### Goal of the Game

The goal of Supémon is to become the strongest trainer by capturing, training, and battling with different Supémons. Explore the world, defeat opponents, and earn rewards to enhance your Supémons' abilities.

### Gameplay Overview

1. **Program Launch:** Upon launching the game, you will be prompted to enter your name and offered a starting Supémon.

2. **Out-of-Combat Actions:** You can perform various actions outside of battles, including:
   - Entering the wild to initiate a fight against a random Supémon.
   - Accessing the shop to buy or sell items.
   - Visiting the Supémon Center to heal your Supémons for free.
   - Leaving the game with or without saving progress.
   
3. **Battle:** Engage in turn-by-turn battles against wild Supémons. During battles, you can:
   - Choose moves from your Supémon's move list.
   - Switch to a different Supémon from your team.
   - Use items to aid your Supémon
   - Attempt to capture the enemy Supémon.
   - Attempt to run away from the battle.
   
4. **Experience and Leveling:** Your Supémons can gain experience and levels through battles. Each level-up increases their statistics.

## Conclusion

Congratulations! You're now ready to embark on your journey in the world of Supémon. Explore, battle, and become the ultimate Supémon trainer! If you encounter any issues or have feedback, feel free to reach out to the game developers. Enjoy your adventure!
