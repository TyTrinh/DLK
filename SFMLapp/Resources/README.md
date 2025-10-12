# SFML Appointment App (Demo)

This is a minimal demo showing:
- C++ classes: User (base), Patient, Doctor, Admin
- Simple in-memory DataStore and Appointment struct
- A tiny SFML GUI to register a patient and book a demo appointment

## Build (Linux/macOS)
```bash
mkdir build && cd build
cmake ..
make
./SFMLAppointmentApp
```

## Build (Windows with MSYS2/CMake)
- Ensure SFML is installed and CMake can find it.
- Same commands from a shell that has CMake in PATH.

## Notes
- This demo keeps everything in memory and is deliberately small for teaching and iteration.
- Real projects: separate compilation units, better input handling, persistence (sqlite), and polished UI.