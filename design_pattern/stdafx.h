///    Copyright (C) 2018 cpp_prime5 DG.C
///        http://www.futuresoft.com.cn
///
///    \brief 标准系统包含文件的包含文件
///
///    \author   zhoudeguang
///    \version  1.0
///    \2018/05/03
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//
#pragma once
#ifndef STDAFX_H
#define STDAFX_H
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <algorithm>
#include <ctime>
#include <vector>
#include <iterator>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <random>
#include <memory>
#include <numeric>
#include <map>
#include <assert.h>

//不使用命名空间
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::ostream;
using std::ostringstream;
using std::set;
using std::vector;
using std::ostream_iterator;
using std::random_device;
using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;
using std::make_shared;
using std::logic_error;
using std::map;

//自定义头文件
#include "CommonFunctions.h"





#endif  //STDAFX_H


