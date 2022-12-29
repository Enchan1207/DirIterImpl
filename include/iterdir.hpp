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
 * @param sorted 出力を辞書順ソートするかどうか
 * @return int 処理結果
 */
int iterdir(const std::filesystem::path& targetPath, std::ostream& output, bool sorted);

#endif /* ITERDIR_H */
