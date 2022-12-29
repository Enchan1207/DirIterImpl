//
//
//
#ifndef ITERDIR_H
#define ITERDIR_H

#include <filesystem>
#include <iostream>

/**
 * @brief 引数で指定されたパスのファイルを走査・出力する。
 *
 * @param path パス
 * @param output 出力先ストリーム
 * @return int 処理結果
 */
int iterdir(const std::filesystem::path& targetPath, std::ostream& output);

#endif /* ITERDIR_H */
