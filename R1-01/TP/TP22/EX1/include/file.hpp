#pragma once
#ifndef __FILE__HPP__
#define __FILE__HPP__

#include <vector>
#include <filesystem>

// Takes a file full of double values -> returns a vector of thoes values
std::vector<double> file_to_vector(std::filesystem::path path);

#endif