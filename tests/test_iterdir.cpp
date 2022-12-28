//
// iterdir tests
//
#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <iterdir.hpp>
#include <string>
#include <vector>

namespace fs = std::filesystem;

/**
 * @brief test fixture for IterDir
 */
class IterDirTest : public testing::Test {
   public:
    fs::path testDir;

   protected:
    void SetUp() override {
        testDir = fs::temp_directory_path() / "net.enchan-lab.IterdirTest";
        fs::create_directories(testDir);
    }

    void TearDown() override {
        fs::remove_all(testDir);
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
            std::cerr << error.what() << '\n';
            return false;
        }
        return true;
    }
};

/**
 * @brief 辞書順ソート?
 */
TEST_F(IterDirTest, dict_ordered) {
    // テストファイル生成
    const std::vector<std::string> fileNames = {"a", "b", "c", "aa", "ab", "ac"};
    for (auto&& fileName : fileNames) {
        EXPECT_TRUE(createFile(fileName));
    }

    // 実行
    EXPECT_EQ(iterdir(testDir), 0);
}

/**
 * @brief 作成タイミング順?
 */
TEST_F(IterDirTest, creation_ordered) {
    // テストファイル生成
    const std::vector<std::string> fileNames = {"5", "4", "3", "2", "1"};
    for (auto&& fileName : fileNames) {
        EXPECT_TRUE(createFile(fileName));
    }

    // 実行
    EXPECT_EQ(iterdir(testDir), 0);
}
