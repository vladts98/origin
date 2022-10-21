#pragma once
#include "Figures.h"

#ifdef FunctPrint_EXPORTS
#define FunctPrint_API __declspec(dllexport)
#else
#define FunctPrint_API __declspec(dllimport)
#endif

FunctPrint_API void print_info(Figure* figure);