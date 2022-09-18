
#include <iostream>
#include <filesystem>
#include <memory>

int main()
{
  std::filesystem::path pt("TestMap");

  auto recursiveGetFileNamesByExtension = [](std::filesystem::path pt, const std::string extension) {
	std::vector<std::filesystem::path> fileName;
	if (std::filesystem::exists(pt) && std::filesystem::is_directory(pt)) {
	  for (const auto& p : std::filesystem::recursive_directory_iterator(pt)) {
	    if (std::filesystem::is_regular_file(p)) {
	      if (p.path().extension().compare(extension)) {
		fileName.push_back(p.path().filename());
	      }
	    }
	  }
	}
	return std::make_unique<std::vector<std::filesystem::path>>(begin(fileName), end(fileName));
  };
  
  std::unique_ptr<std::vector<std::filesystem::path>> p = recursiveGetFileNamesByExtension(pt, " .txt");
  for (auto& el : *p) std::cout << el << " ";

  
  return 0;
}

