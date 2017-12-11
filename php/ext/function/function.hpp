#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "../../sym.hpp"
#include "../../adt.hpp"
#include "../../mod.hpp"

ADT* function_exists_wrapper(ListADT *param_list); 
ADT* is_callable_wrapper(ListADT *param_list);