//
// DirIterImpl
//

#include <filesystem>
#include <iostream>
#include <string>

#include "iterdir.hpp"

int main(int argc, char const *argv[]) {
    // 引数で指定がなければカレントディレクトリを対象とする
    std::string pathStr = ".";
    if (argc > 1) {
        pathStr = argv[1];
    }

    // ディレクトリのイテレーションを実行
    const int result = iterdir(std::filesystem::path(pathStr), std::cout, false);
    if (result != 0) {
        std::cerr << "An error occured during process." << std::endl;
        return result;
    }
    return result;
}
