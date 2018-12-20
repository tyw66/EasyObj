#include "objfileparser.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>

std::string ObjFileParser::m_filePath = "";
ObjFileParser::ObjFileParser()
{

}

std::string ObjFileParser::filePath()
{
    return m_filePath;
}

void ObjFileParser::setFilePath(const std::string &filePath)
{
    m_filePath = filePath;
}

bool ObjFileParser::parse(Mesh &mesh)
{
    //! 1.打开文件
    std::ifstream fin;
    fin.open(m_filePath,std::ios_base::in);
    //打开文件失败todo

    //! 2.读文件
    std::vector<Vec3> vList, vtList, vnList;//顶点坐标集合，纹理坐标集合，法线坐标集合
    std::vector<Vec3> v2faceList, vt2faceList, vn2faceList; //

    std::string flag;       //行首标志
    char line[100];         //单行
    std::stringstream ss;   //读字符串流
    fin.getline(line,100);
    while(fin.peek() != EOF){
        //! 分割字符串
        ss.clear();
        ss.str(line);
        ss >> flag;

        //! 顶点
        if(flag == "v") {
            std::cout << "read vertex..." <<std::endl;
            Vec3 v;
            ss >> v.x >> v.y >> v.z;
            vList.push_back(v);
        }
        //! 法线
        else if(flag == "vn") {
            std::cout << "read normal..." <<std::endl;
            Vec3 vn;
            ss >> vn.x >> vn.y >> vn.z;
            vnList.push_back(vn);

        }
        //! 纹理坐标
        else if(flag == "vt") {
            std::cout << "read texture coord..." <<std::endl;
            Vec3 vt;
            ss >> vt.x >> vt.y >> vt.z;
            vtList.push_back(vt);
        }
        //! 面
        else if(flag == "f") {
            std::cout << "read face..." <<std::endl;
            char s1[20],s2[20],s3[20];
            ss >> s1 >>s2 >> s3;

            std::vector<std::string> tr1 = split(s1, '/');
            std::vector<std::string> tr2 = split(s2, '/');
            std::vector<std::string> tr3 = split(s3, '/');

            Vec3 vVec(str2int(tr1[0]), str2int(tr2[0]), str2int(tr3[0]));   //顶点索引
            Vec3 vtVec(str2int(tr1[1]), str2int(tr2[1]), str2int(tr3[1]));  //纹理坐标索引
            Vec3 vnVec(str2int(tr1[2]), str2int(tr2[2]), str2int(tr3[2]));  //法向量索引
            v2faceList.push_back(vVec);
            vt2faceList.push_back(vtVec);
            vn2faceList.push_back(vnVec);
        }
        fin.getline(line,100);
    }
    fin.close();


    //! 3.构造面与网格
    mesh.clear();
    for(size_t i = 0; i < v2faceList.size(); ++i){
        Color c(255,0,0);
        Triangle triangle(vList.at(v2faceList[i].x - 1),//文件索引号从1开始，程序中从0开始
                          vList.at(v2faceList[i].y - 1),
                          vList.at(v2faceList[i].z - 1),
                          c);
        triangle.color_fill = Color(rand()%255,rand()%255,rand()%255);//面随机上色
        mesh.add(triangle);
    }


    return true;
}

std::vector<std::string> ObjFileParser::split(char* data, char d)
{
    std::vector<std::string> strList;

    const char *sep = "/"; //可按多个字符来分割
    char *p = strtok(data, sep);
    while(p){
        strList.push_back(p);
        printf("%s ", p);
        p = strtok(NULL, sep);
    }

    return strList;
}

int ObjFileParser::str2int(const std::string &str)
{
    if(str.empty()) return 0;

    int a;
    std::stringstream stream(str);
    stream>>a;
    return a;
}

