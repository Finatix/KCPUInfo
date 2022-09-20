/*
 * Copyright 2015 <copyright holder> <email>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef CPUINFORMATIONAQUIRER_H
#define CPUINFORMATIONAQUIRER_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <lscpu.h>
#include <cpuid.h>

using std::string;
using std::ifstream;

class CpuInformationAquirer
{
    public:
        CpuInformationAquirer();
        ~CpuInformationAquirer();

        // getter for cpu related informations
        string getCpuName();
        string getCodeName();
        string getBrandId();
        string getPackageName();
        string getTechnology();
        string getVID();
        string getSpecification();
        string getFamily();
        string getModel();
        string getStepping();
        string getExtFamily();
        string getExtModel();
        string getRevision();
        string getInstructions();
        string getClockSpeed();
        string getMultiplier();
        string getBusSpeed();
        string getRatedFSB();
        string getL1Data();
        string getL1DataWays();
        string getL1Inst();
        string getL1InstWays();
        string getL2();
        string getL2Ways();
        string getL3();
        string getL3Ways();
        string getCores();
        string getThreads();

    private:
        string readFirstLineFromFile(string fileName);
        void parseCPUInfo();

        string cpuName;
        string specification;
        string codeName;
        string brandId;
        string packageName;
        string cores;
        string threads;
        string family;
        string stepping;
        string model;
        string flags;
};

#endif // CPUINFORMATIONAQUIRER_H
