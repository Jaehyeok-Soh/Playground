#include "pch.h"

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

using namespace std;

int main()
{
	bool bIsQuit = false;

	Management tagManagement;

	while (!bIsQuit)
	{
		bIsQuit = tagManagement.Start();
	}

	tagManagement.Quit();

	return 0;
}

//#include "pch.h"
//
//using json = nlohmann::json;
//
//int main() {
//    // JSON 객체 생성
//    json j;
//
//    j["name"] = "John";
//    j["age"] = 30;
//    j["isDeveloper"] = true;
//    j["skills"] = { "C++", "Python", "JavaScript" };
//
//    // 출력
//    std::cout << j.dump(4) << std::endl;  // 4는 들여쓰기
//
//    // 문자열 -> JSON 파싱
//    std::string json_str = R"({"name":"Alice","age":25})";
//    json j2 = json::parse(json_str);
//
//    std::cout << j2["name"] << " is " << j2["age"] << " years old." << std::endl;
//
//    return 0;
//}