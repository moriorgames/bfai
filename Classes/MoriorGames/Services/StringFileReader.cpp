#include "StringFileReader.h"

std::string StringFileReader::getStringFromFile(std::string file)
{
    auto fullPath = FileUtils::getInstance()->fullPathForFilename(file);
    assert(FileUtils::getInstance()->isFileExist(fullPath));

    return FileUtils::getInstance()->getStringFromFile(fullPath);
}
