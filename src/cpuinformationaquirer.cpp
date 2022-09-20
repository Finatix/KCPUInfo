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

#include "cpuinformationaquirer.h"

CpuInformationAquirer::CpuInformationAquirer() {
  parseCPUInfo();
}

CpuInformationAquirer::~CpuInformationAquirer() {}

string CpuInformationAquirer::getCpuName() {
  return cpuName;
}

string CpuInformationAquirer::getCodeName() {
  return codeName;
}

string CpuInformationAquirer::getBrandId() {
  return brandId;
}

string CpuInformationAquirer::getPackageName() {
  return packageName;
}

string CpuInformationAquirer::getTechnology() {
  return "TODO";
}

string CpuInformationAquirer::getVID() {
  return "TODO";
}

string CpuInformationAquirer::getSpecification() {
  return specification;
}

string CpuInformationAquirer::getFamily() {
  return family;
}

string CpuInformationAquirer::getModel() {
  return model;
}

string CpuInformationAquirer::getStepping() {
  return stepping;
}

string CpuInformationAquirer::getExtFamily() {
  return "TODO";
}

string CpuInformationAquirer::getExtModel() {
  return "TODO";
}

string CpuInformationAquirer::getRevision() {
  return "TODO";
}

string CpuInformationAquirer::getInstructions() {
  return flags;
}

string CpuInformationAquirer::getClockSpeed() {
  string firstLine = readFirstLineFromFile("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq");
  unsigned int megaherz = (int) strtol(firstLine.c_str(), NULL, 10);
  megaherz = megaherz / 1000;
  char dest[15];
  sprintf(dest, "%i", megaherz);
  string destination = dest;
  return destination + " MHz";
}

string CpuInformationAquirer::getMultiplier() {
  return "TODO";
}

string CpuInformationAquirer::getBusSpeed() {
  return "TODO";
}

string CpuInformationAquirer::getRatedFSB() {
  return "TODO";
}

string CpuInformationAquirer::getL1Data() {
  // vor die cache menge muss noch die anzahl der CPU Kerne!! TODO hinzufuegen!!
  return readFirstLineFromFile("/sys/devices/system/cpu/cpu0/cache/index0/size");
}

string CpuInformationAquirer::getL1DataWays() {
  return readFirstLineFromFile("/sys/devices/system/cpu/cpu0/cache/index0/ways_of_associativity") + "-way";
}

string CpuInformationAquirer::getL1Inst() {
  return readFirstLineFromFile("/sys/devices/system/cpu/cpu0/cache/index1/size");
}

string CpuInformationAquirer::getL1InstWays() {
  return readFirstLineFromFile("/sys/devices/system/cpu/cpu0/cache/index1/ways_of_associativity") + "-way";
}


string CpuInformationAquirer::getL2() {
  return readFirstLineFromFile("/sys/devices/system/cpu/cpu0/cache/index2/size");
}

string CpuInformationAquirer::getL2Ways() {
  return readFirstLineFromFile("/sys/devices/system/cpu/cpu0/cache/index2/ways_of_associativity") + "-way";
}

string CpuInformationAquirer::getL3() {
  return readFirstLineFromFile("/sys/devices/system/cpu/cpu0/cache/index3/size");
}

string CpuInformationAquirer::getL3Ways() {
  return readFirstLineFromFile("/sys/devices/system/cpu/cpu0/cache/index3/ways_of_associativity") + "-way";
}

string CpuInformationAquirer::getCores()
{
  return cores;
}

string CpuInformationAquirer::getThreads()
{
  return threads;
}

string CpuInformationAquirer::readFirstLineFromFile(string fileName) {
  FILE *file = fopen(fileName.c_str(), "rb");
  char *arg = 0;
  size_t size = 0;
  getline(&arg, &size, file);

  unsigned int len = sizeof(arg);
  if (arg[len - 1] == '\n') {
    arg[len - 1] = '\0';
  }

  string destination = arg;
  free(arg);
  fclose(file);
  
  if (destination.find("\n") != string::npos) {
    destination = destination.replace(destination.find("\n"), 1, "");
  }
  
  return destination;
}

void CpuInformationAquirer::parseCPUInfo() {
  ifstream file("/proc/cpuinfo");
  string destination;

  while (getline(file, destination)) {
    if (destination.find("\n") != string::npos) {
      destination = destination.replace(destination.find("\n"), 1, "");
    }

    if (destination.find("model") != string::npos && destination.find("model name") == string::npos) {
      model = destination.substr(destination.find(":") + 2, destination.length());
    }
    
    if (destination.find("model name") != string::npos) {
      specification = destination.substr(destination.find(":") + 2, destination.length());
      cpuName = specification.substr(0, specification.find("CPU"));
    }
    
    if (destination.find("cpu cores") != string::npos) {
      cores = destination.substr(destination.find(":") + 2, destination.length());
    }
    
    if (destination.find("siblings") != string::npos) {
      threads = destination.substr(destination.find(":") + 2, destination.length());
    }
    
    if (destination.find("vendor_id") != string::npos) {
      brandId = destination.substr(destination.find(":") + 2, destination.length());
    }
    
    if (destination.find("cpu family") != string::npos) {
      family = destination.substr(destination.find(":") + 2, destination.length());
    }
    
    if (destination.find("stepping") != string::npos) {
      stepping = destination.substr(destination.find(":") + 2, destination.length());
    }
    
    if (destination.find("flags") != string::npos) {
      flags = destination.substr(destination.find(":") + 2, destination.length());
    }
    /*if (destination.find("model") != string::npos) {
      model = destination.substr(destination.find(":") + 2, destination.length());
    }*/
  }
}

