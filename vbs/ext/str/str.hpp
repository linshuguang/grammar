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
#include "../../array.hpp"

ADT* strtolower_wrapper(ListADT *param_list);
ADT* substr_wrapper(ListADT *param_list);
ADT* strpos_wrapper(ListADT *param_list);
ADT* stripslashes_wrapper(ListADT *param_list);
ADT* explode_wrapper(ListADT *param_list);