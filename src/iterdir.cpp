//
//
//
#include "iterdir.hpp"

#include <iterator>
#include <set>

namespace fs = std::filesystem;

/**
 * @brief 引数で渡されたパスに存在するファイルを走査し、そのままストリームへ出力する
 *
 * @param targetPath パス
 * @param output 出力先ストリーム
 */
void iterateContentsOfDirectoryWithRawOrder(const fs::path& targetPath, std::ostream& output) {
    for (const auto& entry : fs::directory_iterator(targetPath)) {
        output << entry.path().filename().string() << std::endl;
    }
}

/**
 * @brief 引数で渡されたパスに存在するファイルを走査し、辞書順にソートしてストリームへ出力する
 *
 * @param targetPath パス
 * @param output 出力先ストリーム
 */
void iterateContentsOfDirectoryWithDictionaryOrder(const fs::path& targetPath, std::ostream& output) {
    std::set<fs::path> sortedContents;
    for (const auto& entry : fs::directory_iterator(targetPath)) {
        sortedContents.insert(entry.path());
    }

    for (const auto& path : sortedContents) {
        output << path.filename().string() << std::endl;
    }
}

int iterdir(const fs::path& targetPath, std::ostream& output, bool sorted) {
    if (!fs::exists(targetPath)) {
        std::cerr << "Error! Specified path " << targetPath << " not exists." << std::endl;
        return 1;
    }

    if (!fs::is_directory(targetPath)) {
        std::cerr << "Error! Specified path " << targetPath << " is not directory." << std::endl;
        return 1;
    }

    output << "Contents of " << fs::canonical(targetPath).string() << ":" << std::endl;
    if (sorted) {
        iterateContentsOfDirectoryWithDictionaryOrder(targetPath, output);
    } else {
        iterateContentsOfDirectoryWithRawOrder(targetPath, output);
    }
    return 0;
}
