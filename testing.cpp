#include <gtest/gtest.h>
#include "header.hpp"
#include <vector>


struct DirTesting : public testing::Test {
    DirStatistic dst;
    std::vector<std::string> vec_testing = {"I love cinema.", "The vertex is S.",
                                        "I am single.", "My name is KG.",
                                        "I lovE cinema.", "GeeksQuiz. is a quiz site.",
                                        "I love Geeksquiz and Geeksforgeeks.",
                                        "You are my friend.", "I love cinema"};

    std::map<std::string, int> map_testing{}; 
    std::map<std::string, int> map_word_testing{};
    std::stringstream stream{};
    
    void SetUp() override {
        for(int a = 0; a < vec_testing.size(); ++a) {
            map_testing.insert({vec_testing[a], vec_testing[a].size()});
        }
         for(int a = 0; a < vec_testing.size(); ++a) {
            stream << vec_testing[a];
            map_word_testing.insert({vec_testing[a], std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>())});
            stream = std::stringstream();    
        }

    }
    void TearDown() override {
    }
};

TEST_F(DirTesting, CountChars) {

    for(auto it = map_testing.begin(); it != map_testing.end(); ++it) {
        ASSERT_EQ(dst.getAllChars(it->first), it->second);
    }
}

TEST_F(DirTesting, CountWords) {
    for(auto it = map_word_testing.begin(); it != map_word_testing.end(); ++it) {
        size_t words = dst.countWords(it->first);
        ASSERT_EQ(words, it->second);
    }
}
