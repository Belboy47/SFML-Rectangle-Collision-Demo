# MySFMLApp

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-3.0.2-8A2BE2?style=for-the-badge)
![License](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)

## Description
**MySFMLApp** is a C++ graphical application using **SFML 3.0.2**. It creates multiple moving rectangles on a window with random colors and velocities, avoiding overlap at initialization and bouncing off the window edges and each other.

## Features
- Randomized rectangle positions and velocities
- Collision detection between rectangles
- Edge collision handling
- Color change on collision
- Configurable number of rectangles

## Requirements
- **C++20** compatible compiler (e.g., MSVC, GCC, Clang)
- **CMake** ≥ 3.20
- **SFML 3.0.2** (dynamically linked in this setup)

## License
This project uses the MIT License.  
See [LICENSE](LICENSE) for details.

## Build Instructions

### 1. Clone the repository
```bash
git clone https://github.com/Belboy47/SFML-Rectangle-Collision-Demo.git
cd MySFMLApp
```

### 2. Create a build folder
```bash
mkdir build
cd build
```

### 3. Configure with CMake
```bash
cmake ..
```

### 4. Build the project
```bash
cmake --build . --config Release
```

### 5. Run the executable
```bash
cd Release
MySFMLApp.exe
```
