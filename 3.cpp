#include <iostream>
#include <vector>
#include <memory>
#include <filesystem>


int main(){
    auto getFilesWithExtension = [](const std::filesystem::path& path, const std::string& extension){
        auto fileNames = std::make_unique<std::vector<std::filesystem::path>>();
        for(auto& p: std::filesystem::recursive_directory_iterator(path)){
            if (p.is_regular_file()){
                if (p.path().extension().compare(extension) == 0){
                    fileNames->push_back(p.path().filename());
                }
            }
        }
        return fileNames;
    };
    std::filesystem::path path = "test";
    std::string extension = ".txt";
    try{
        auto fileNames = getFilesWithExtension(path, extension);
        for(auto i: *fileNames){
        std::cout << i << " ";
        }
    }
    catch (const std::exception& e){
        std::cerr << e.what();
    } 
}