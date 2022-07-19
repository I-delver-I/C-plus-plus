#pragma once
#include"CompaniesContainer.h"
#include<fstream>
#include<nlohmann/json.hpp>
using json = nlohmann::json;

const string filePath = "Companies.json";

void writeCompaniesToFile(CompaniesContainer companies);
CompaniesContainer readCompaniesFromFile();