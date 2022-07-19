#pragma once
#include"CompaniesContainer.h"
#include<fstream>
#include<nlohmann/json.hpp>
using json = nlohmann::json;

const string mainFilePath = "Companies.json";
const string secondaryFilePath = "Positive deviation companies.json";

void writeCompaniesToFile(const string filePath, CompaniesContainer& companies);
CompaniesContainer readCompaniesFromFile(const string filePath);