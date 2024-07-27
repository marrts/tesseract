/**
 * @file any.cpp
 * @brief This a boost serializable any
 *
 * @author Levi Armstrong
 * @date February 27, 2021
 * @version TODO
 * @bug No known bugs
 *
 * @copyright Copyright (c) 2021, Southwest Research Institute
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

#include <tesseract_common/any_poly.h>

#include <boost/serialization/unordered_map.hpp>

namespace tesseract_common
{
template <class Archive>
void AnyPoly::serialize(Archive& ar, const unsigned int /*version*/)  // NOLINT
{
  ar& boost::serialization::make_nvp("base", boost::serialization::base_object<AnyPolyBase>(*this));
}

}  // namespace tesseract_common

#include <tesseract_common/serialization.h>
BOOST_CLASS_EXPORT_IMPLEMENT(tesseract_common::AnyPolyBase)
BOOST_CLASS_EXPORT_IMPLEMENT(tesseract_common::AnyPoly)

TESSERACT_SERIALIZE_ARCHIVES_INSTANTIATE(tesseract_common::AnyPolyBase)
TESSERACT_SERIALIZE_ARCHIVES_INSTANTIATE(tesseract_common::AnyPoly)

TESSERACT_ANY_EXPORT_IMPLEMENT(IntegralBool)
TESSERACT_ANY_EXPORT_IMPLEMENT(IntegralInt)
TESSERACT_ANY_EXPORT_IMPLEMENT(IntegralUnsigned)
TESSERACT_ANY_EXPORT_IMPLEMENT(IntegralDouble)
TESSERACT_ANY_EXPORT_IMPLEMENT(IntegralFloat)
TESSERACT_ANY_EXPORT_IMPLEMENT(StdString)
TESSERACT_ANY_EXPORT_IMPLEMENT(StdSizeT)

TESSERACT_ANY_EXPORT_IMPLEMENT(StdUnorderedMapStringString)
TESSERACT_ANY_EXPORT_IMPLEMENT(StdUnorderedMapStringBool)
TESSERACT_ANY_EXPORT_IMPLEMENT(StdUnorderedMapStringInt)
TESSERACT_ANY_EXPORT_IMPLEMENT(StdUnorderedMapStringUnsigned)
TESSERACT_ANY_EXPORT_IMPLEMENT(StdUnorderedMapStringDouble)
TESSERACT_ANY_EXPORT_IMPLEMENT(StdUnorderedMapStringFloat)
TESSERACT_ANY_EXPORT_IMPLEMENT(StdUnorderedMapStringStdSizeT)
