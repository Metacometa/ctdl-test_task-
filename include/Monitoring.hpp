#pragma once

#include <sstream>
#include <unordered_map>

#include <chrono>
#include <thread>
#include <cmath>
#include <ctime>
#include <iomanip>

#include "Configuration.hpp"
#include "CPUStats.hpp"

class Monitoring
{
    Configuration config;

public:
    Monitoring() = delete;
    Monitoring(char *json_path);

    std::unordered_map<int, float> instant_cpu_loads;
    unsigned long free_memory = 0;
    unsigned long used_memory = 0;

private:
    void ReadCpuStats(std::vector<CPUStats>& cpu_stats);
    void UpdateInstantCpuLoad();
    float CalculateInstantCpuLoads(const CPUStats& prev, const CPUStats& curr);

    void UpdateMemInfo();

    void StartMonitoring();
    void Output(std::ostream& stream);
};