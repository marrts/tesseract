/**
 * @file set_active_continuous_contact_manager_command.cpp
 * @brief Used to set the active continuous contact manager
 *
 * @author Levi Armstrong
 * @author Matthew Powelson
 * @date March 18, 2022
 * @version TODO
 * @bug No known bugs
 *
 * @par License
 * Software License Agreement (Apache License)
 * @par
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * @par
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <tesseract_common/macros.h>
TESSERACT_COMMON_IGNORE_WARNINGS_PUSH
#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>
#include <string>
TESSERACT_COMMON_IGNORE_WARNINGS_POP

#include <tesseract_common/utils.h>
#include <tesseract_environment/commands/set_active_continuous_contact_manager_command.h>

namespace tesseract_environment
{
SetActiveContinuousContactManagerCommand::SetActiveContinuousContactManagerCommand()
  : Command(CommandType::SET_ACTIVE_CONTINUOUS_CONTACT_MANAGER)
{
}

SetActiveContinuousContactManagerCommand::SetActiveContinuousContactManagerCommand(std::string active_contact_manager)
  : Command(CommandType::SET_ACTIVE_CONTINUOUS_CONTACT_MANAGER)
  , active_contact_manager_(std::move(active_contact_manager))
{
}

const std::string& SetActiveContinuousContactManagerCommand::getName() const { return active_contact_manager_; }

bool SetActiveContinuousContactManagerCommand::operator==(const SetActiveContinuousContactManagerCommand& rhs) const
{
  bool equal = true;
  equal &= Command::operator==(rhs);
  equal &= active_contact_manager_ == rhs.active_contact_manager_;
  return equal;
}
bool SetActiveContinuousContactManagerCommand::operator!=(const SetActiveContinuousContactManagerCommand& rhs) const
{
  return !operator==(rhs);
}

template <class Archive>
void SetActiveContinuousContactManagerCommand::serialize(Archive& ar, const unsigned int /*version*/)
{
  ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Command);
  ar& BOOST_SERIALIZATION_NVP(active_contact_manager_);
}
}  // namespace tesseract_environment

#include <tesseract_common/serialization.h>
BOOST_CLASS_EXPORT_IMPLEMENT(tesseract_environment::SetActiveContinuousContactManagerCommand)
TESSERACT_SERIALIZE_ARCHIVES_INSTANTIATE(tesseract_environment::SetActiveContinuousContactManagerCommand)
