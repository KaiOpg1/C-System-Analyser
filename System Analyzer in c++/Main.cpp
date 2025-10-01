
#include <iostream>
#include <string>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#include <sysinfoapi.h>
#elif defined(__linux__)
#include <unistd.h>
#include <fstream>
#endif

using namespace std;

void printSystemInfo() {
#if defined(_WIN32) || defined(_WIN64)
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);

    cout << "===== System Analyzer (Windows) =====" << endl;
    cout << "CPU cores: " << sysInfo.dwNumberOfProcessors << endl;
    cout << "Page size: " << sysInfo.dwPageSize << " bytes" << endl;
    cout << "Total RAM: " << memInfo.ullTotalPhys / (1024 * 1024) << " MB" << endl;
    cout << "Available RAM: " << memInfo.ullAvailPhys / (1024 * 1024) << " MB" << endl;

#elif defined(__linux__)
    cout << "===== System Analyzer (Linux) =====" << endl;

    long cores = sysconf(_SC_NPROCESSORS_ONLN);
    long page_size = sysconf(_SC_PAGESIZE);

    cout << "CPU cores: " << cores << endl;
    cout << "Page size: " << page_size << " bytes" << endl;

    ifstream meminfo("/proc/meminfo");
    string key;
    long value;
    string unit;
    while (meminfo >> key >> value >> unit) {
        if (key == "MemTotal:") {
            cout << "Total RAM: " << value / 1024 << " MB" << endl;
        }
        if (key == "MemAvailable:") {
            cout << "Available RAM: " << value / 1024 << " MB" << endl;
        }
    }
#endif
}

int main() {
    printSystemInfo();
    system("pause");
    return 0;
}