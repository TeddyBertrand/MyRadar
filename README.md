# 🌌 My Radar: The Air Traffic Control Panel

## 📖 Description

**My Radar** is a 2D air traffic simulation game where aircrafts fly from one location to another while avoiding collisions. The game simulates aircrafts that take off, fly, and land, managing control tower areas where collisions are allowed. The aircrafts and control towers are displayed visually on a simulation panel with real-time updates.

---

## 🖥️ Installation

To run the game, you need to compile the project using the provided `Makefile`. Follow the steps below:

1. **Clone the repository**:
    ```bash
    git clone <repository_url>
    cd my_radar
    ```

2. **Compile the project**:
    ```bash
    make
    ```

3. **Run the game**:
    ```bash
    ./my_radar <path_to_file>
    ```

    If you need help, use the `-h` option:
    ```bash
    ./my_radar -h
    ```

---

## 🎮 Features

### ✅ Implemented Features

- **Aircraft Movement**: Aircrafts move in a straight line with constant speed, and disappear after landing or collision.
- **Collision Handling**: Aircrafts collide and disappear unless they're under the control area of a control tower.
- **Control Towers**: Display static towers with defined control areas that allow collision immunity within their radius.
- **Hitboxes & Control Areas**: Toggle hitboxes and control areas visibility using key `L`.
- **Sprites**: Toggle sprite visibility using key `S`.
- **Timer**: A timer in the top-right corner of the window updates in real time during the simulation.

### ⏱️ Performance Features

- **Smooth Animation**: Time-based movement of aircrafts, independent of frame rate.
- **Event-driven Window Closure**: Window closes based on events rather than manually.
- **Window Size**: Fixed window size at **1920x1080** pixels for consistent rendering.

---

## 🧠 Usage

### Command Line Options

- **`<path_to_script>`**: Path to the file with tower and planes.
- **`-h`**: Displays help and usage instructions.

### Example Commands:

1. **Run the game**:
    ```bash
    ./my_radar planes.txt
    ```

2. **Display Help**:
    ```bash
    ./my_radar -h
    ```

## Help Output Example:

Air traffic simulation panel
USAGE
./my_radar [FILE]
-h print the usage and quit.
USER INTERACTIONS
`L' key enable/disable hitboxes and areas.
`S' key enable/disable sprites.

## 📜 Example Script

The script file contains the entities and their parameters. Below is an example of the format:

A 815 321 1484 166 5 0  
A 1589 836 811 936 2 0  
A 202 894 103 34 3 0  
T 93 47 19  
T 49 56 25  

## Entities:

- **Aircrafts**:  
  - `A`: Aircraft type  
  - Coordinates of departure and arrival  
  - Speed (in pixels per second)  
  - Delay before takeoff (in seconds)

- **Control Towers**:  
  - `T`: Tower type  
  - Coordinates of the tower  
  - Radius of the control area

## ⚠️ Error Handling

If the script is not found or is incorrect, an error message is displayed and the program exits with the error code 84.

## 🛠️ Authorized Functions

**C Library**:

- `malloc`, `free`, `stat`, `memset`, `rand`, `srand`, `time`, `(f)open`, `(f)read`, `(f)write`, `(f)close`, `getline`

**CSFML Library**:

- sfRenderWindow_create, sfRenderWindow_destroy, sfRenderWindow_isOpen, sfRenderWindow_close, sfRenderWindow_pollEvent, sfRenderWindow_setFramerateLimit, sfRenderWindow_clear, sfRenderWindow_drawSprite, sfRenderWindow_draw*Shape, sfRenderWindow_display, sfMusic_*, sfSprite_create, sfSprite_destroy, sfSprite_setTexture, sfSprite_setPosition, sfSprite_setRotation, sfSprite_move, sfSprite_rotate, sfTexture_create, sfTexture_createFromFile, sfTexture_destroy, sfTexture_updateFromPixels, sfText_*, sfView_*, sfShape_* (except _getLocalBounds and _getGlobalBounds), sfConvexShape_* (except _getLocalBounds and _getGlobalBounds), sfRectangleShape_* (except _getLocalBounds and _getGlobalBounds), sfCircleShape_* (except _getLocalBounds and _getGlobalBounds), sfTransform_*, sfClock_*

**Math Library**:

- All mathematical functions.
