// Copyright 2021 Kenji Brameld
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <vector>
#include "comp3431_ass3_planner/plan_parser.hpp"

PlanParser::PlanParser(std::string planPath)
{
  // Parser is in charge of extracting the important information from the ff planner output, and
  // converting it to lower case.
  //
  // FFPlanner output would look like the following:
  //
  //----------------------------------------------------------------
  // ...
  //   ff: found legal plan as follows
  //
  // step    0: MOVE TURTLEBOT INITIAL-ROOM KITCHEN
  //         1: PICK TURTLEBOT KITCHEN APPLE
  //         2: MOVE TURTLEBOT KITCHEN LIVING-ROOM
  //         3: PLACE TURTLEBOT LIVING-ROOM APPLE
  //
  //
  // time spent:    0.00 seconds instantiating 21 easy, 0 hard action templates
  // ...
  //----------------------------------------------------------------
  //
  // "..." means other text that is not of concern.
  //
  // The goal is to create a queue of vector of strings that looks like the following:
  // [["move", "turtlebot", "initial-room", "kitchen"],
  //  ["pick", "turtlebot", "kitchen", "apple"],
  //  ["move", "turtlebot", "kitchen", "living-room"],
  //  ["place", "turtlebot", "living-room", "apple"]]

  std::string line;
  std::ifstream planFile(planPath);

  bool firstStepFound = false;
  if (planFile.is_open()) {
    while (std::getline(planFile, line) ) {
      if (line.substr(0, 4) == "step") {
        firstStepFound = true;
      }

      if (firstStepFound) {
        auto columnIndex = line.find(":");

        // Check if we couldn't find a column. If there is none, we've reached end of steps
        if (columnIndex == std::string::npos) {
          break;
        }

        int startIndex = columnIndex + 2;  // +2 to skip ": "
        std::vector<std::string> split = splitString(line.substr(startIndex, line.back()));
        steps.push(split);
      }
    }
    planFile.close();
  }
}

std::vector<std::string> PlanParser::getNextStep()
{
  auto retVal = steps.front();
  steps.pop();
  return retVal;
}

bool PlanParser::done()
{
  return steps.empty();
}

std::vector<std::string> PlanParser::splitString(std::string data)
{
  std::vector<std::string> dataSplit;
  std::istringstream ss(data);
  std::string token;
  while (std::getline(ss, token, ' ')) {
    // Convert to lower case
    std::transform(
      token.begin(), token.end(), token.begin(),
      [](unsigned char c) {return std::tolower(c);});

    dataSplit.push_back(token);
  }
  return dataSplit;
}
