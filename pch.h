#ifndef PCH_H
#define PCH_H

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

#include "json.hpp"
using json = nlohmann::json;

////////////////////////////////////////////////////////
#include "Define.h"
#include "Management.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Field.h"
#include "RendererService.h"

////////////////////////////////////////////////////////
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

#endif //PCH_H
