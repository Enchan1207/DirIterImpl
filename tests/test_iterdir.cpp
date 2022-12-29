//
// iterdir tests
//
#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterdir.hpp>
#include <string>
#include <vector>

namespace fs = std::filesystem;

/**
 * @brief test fixture for IterDir
 */
class IterDirTest : public testing::Test {
   public:
    /**
     * @brief テスト結果出力先ディレクトリのパス
     */
    fs::path testDir;

    /**
     * @brief ログ出力ストリーム
     */
    std::ofstream logStream;

   protected:
    void SetUp() override {
        // テスト結果出力先ディレクトリの作成
        testDir = fs::temp_directory_path() / "net.enchan-lab.IterdirTest";
        fs::create_directories(testDir);

        // ログ出力ストリームの構成
        logStream = std::ofstream(fs::current_path() / "unittest.log", std::ios_base::app);

        // テストケース名を出力しておく
        logStream << "Testcase: " << ::testing::UnitTest::GetInstance()->current_test_info()->name() << std::endl;
    }

    void TearDown() override {
        // ディレクトリのクリーンアップ
        fs::remove_all(testDir);

        // ログ出力ストリームの後片付け
        logStream.flush();
        logStream.close();
    }

    /**
     * @brief Create empty file with specified name in testDir
     *
     * @param name file name to create
     * @return true file created successfully
     * @return false creation failed
     */
    bool createFile(const std::string& name) const {
        const fs::path destination = testDir / name;
        try {
            std::ofstream stream(destination);
            stream << std::endl;
            stream.close();
        } catch (const fs::filesystem_error& error) {
            std::cerr << error.what() << std::endl;
            return false;
        }
        return true;
    }
};

/**
 * @brief ソートせずそのまま出力
 */
TEST_F(IterDirTest, iterate_with_raw_order) {
    // テストファイル生成
    const std::vector<std::string> fileNames = {"a", "b", "c", "aa", "ab", "ac", "5", "4", "3", "2", "1"};
    for (auto&& fileName : fileNames) {
        EXPECT_TRUE(createFile(fileName));
    }

    // 実行
    EXPECT_EQ(iterdir(testDir, logStream, false), 0);
}

/**
 * @brief 辞書順ソートされていることを確認する
 */
TEST_F(IterDirTest, sorting_confirmation_using_set) {
    // テストファイル生成
    const std::vector<std::string> fileNames = {"a", "b", "c", "aa", "ab", "ac", "5", "4", "3", "2", "1"};
    for (auto&& fileName : fileNames) {
        EXPECT_TRUE(createFile(fileName));
    }

    // 想定される出力順
    const std::vector<std::string> expectedFileNames = {"1", "2", "3", "4", "5", "a", "aa", "ab", "ac", "b", "c"};

    // 出力キャプチャを構成し、実行
    std::ostringstream captureStream(std::ios_base::out);
    EXPECT_EQ(iterdir(testDir, captureStream, true), 0);
    std::istringstream captureResult(captureStream.str());

    // 結果を比較
    std::string line = "";
    std::getline(captureResult, line);  // 1行目はいらないので捨てる

    int index = 0;
    while (std::getline(captureResult, line)) {
        EXPECT_EQ(expectedFileNames[index].compare(line), 0);
        index++;
    }
}
