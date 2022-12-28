//
//
//
#ifndef ITERDIR_H
#define ITERDIR_H

#include <filesystem>

/**
 * @brief 引数で指定されたパスのファイルを走査・出力する。
 *
 * @param path パス
 * @return int 処理結果
 */
int iterdir(const std::filesystem::path& targetPath);

#endif /* ITERDIR_H */
