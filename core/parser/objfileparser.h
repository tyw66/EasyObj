#ifndef OBJFILEPARSER_H
#define OBJFILEPARSER_H

#include<string>

#include"../object/mesh.h"

class ObjFileParser
{
public:
    ObjFileParser();
    /**
     * @brief filePath
     * @return
     */
    static std::string filePath();
    /**
     * @brief setFilePath
     * @param filePath
     */
    static void setFilePath(const std::string &filePath);

    static bool parse(Mesh& mesh);



private:
    static std::string m_filePath;

    static std::vector<std::string> split(char *data, char d);

    static int str2int(const std::string& str);

};

#endif // OBJFILEPARSER_H
