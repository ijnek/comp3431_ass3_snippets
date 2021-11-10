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

#ifndef COMP3431_ASS3_PLANNER__PLAN_PARSER_HPP_
#define COMP3431_ASS3_PLANNER__PLAN_PARSER_HPP_

#include <string>
#include <vector>
#include <queue>

class PlanParser
{
public:
  explicit PlanParser(std::string planPath);

  bool done();
  std::vector<std::string> getNextStep();

private:
  std::queue<std::vector<std::string>> steps;
  int current = 0;

  std::vector<std::string> splitString(std::string data);
};

#endif  // COMP3431_ASS3_PLANNER__PLAN_PARSER_HPP_
