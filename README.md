# 🖥️ C++ System Analyzer

Ein kleines C++-Tool, das grundlegende Systeminformationen ausgibt:

- Anzahl CPU-Kerne
- Seitengröße
- Gesamter RAM
- Verfügbarer RAM

## 🔧 Features
- Plattformübergreifend (Windows & Linux)
- Nutzung von `windows.h` (Windows) oder `/proc/meminfo` (Linux)

## ▶️ Kompilieren & Starten

### Windows (MinGW oder MSVC)
```bash
g++ main.cpp -o system_analyzer.exe
./system_analyzer.exe
