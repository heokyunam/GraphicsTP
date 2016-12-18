#pragma once
#include <vector>
#include <map>
#include <gl/glut.h>

typedef unsigned char uchar;
#define SVector std::vector
#define Iteator(x) std::vector<x>::iterator

typedef unsigned int uint;
typedef std::string String;
#define Pair(x) std::pair<String, x>
#define Map(x) std::map<String, x>
#define MapIterator(x) std::map<String, x>::iterator
#define Iterator(x) std::vector<x>::iterator
#define Indexing(v, i) (*v)[i]
#define UPDATE_LOOP(t, v)\
for(Iterator(t) i = v.begin(); i != v.end();)\
{\
	t obj = (*i);\
	if(obj->Update())\
	{\
		i++;\
	}\
	else\
	{\
		i = v.erase(i);\
		delete obj;\
	}\
}