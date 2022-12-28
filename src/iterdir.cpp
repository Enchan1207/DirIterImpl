//
//
//
#include "iterdir.hpp"

#include <time.h>

#include <chrono>
#include <ctime>
#include <iostream>
#include <set>

namespace fs = std::filesystem;

int iterdir(const fs::path& targetPath) {
    if (!fs::exists(targetPath)) {
        std::cerr << "Error! Specified path " << targetPath << " not exists." << std::endl;
        return 1;
    }

    if (!fs::is_directory(targetPath)) {
        std::cerr << "Error! Specified path " << targetPath << " is not directory." << std::endl;
        return 1;
    }

    std::cout << "Contents of " << fs::canonical(targetPath).string() << ":" << std::endl;

    fs::directory_iterator contentsOfDirectory(targetPath);
    for (const auto& entry : contentsOfDirectory) {
        std::cout << entry.path().filename().string() << std::endl;
    }
    return 0;
}
