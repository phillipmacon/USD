//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#include "pxr/usdImaging/usdviewq/utils.h"
#include "pxr/base/plug/registry.h"
#include "pxr/base/tf/staticTokens.h"

#include "pxr/usd/usd/attribute.h"
#include "pxr/usd/usd/attributeQuery.h"
#include "pxr/usd/usd/modelAPI.h"
#include "pxr/usd/usd/prim.h"
#include "pxr/usd/usd/schemaBase.h"
#include "pxr/usd/usd/stage.h"
#include "pxr/usd/usd/primRange.h"
#include "pxr/usd/usdGeom/camera.h"
#include "pxr/usd/usdGeom/imageable.h"

PXR_NAMESPACE_OPEN_SCOPE

/*static*/
std::vector<UsdPrim> 
UsdviewqUtils::_GetAllPrimsOfType(UsdStagePtr const &stage, 
                                  TfType const& schemaType)
{
    std::vector<UsdPrim> result;
    UsdPrimRange range = stage->Traverse();
    std::copy_if(range.begin(), range.end(), std::back_inserter(result),
                 [schemaType](UsdPrim const &prim) {
                     return prim.IsA(schemaType);
                 });
    return result;
}

TF_DEFINE_PRIVATE_TOKENS(
    _tokens,
    (root)
);

UsdviewqUtils::PrimInfo::PrimInfo(const UsdPrim &prim, const UsdTimeCode time)
{
    hasCompositionArcs = (prim.HasAuthoredReferences() ||
                          prim.HasAuthoredPayloads() ||
                          prim.HasAuthoredInherits() ||
                          prim.HasAuthoredSpecializes() ||
                          prim.HasVariantSets());
    isActive = prim.IsActive();
    UsdGeomImageable img(prim);
    isImageable = static_cast<bool>(img);
    isDefined = prim.IsDefined();
    isAbstract = prim.IsAbstract();

    // isInPrototype is meant to guide UI to consider the prim's "source", so
    // even if the prim is a proxy prim, then unlike the core
    // UsdPrim.IsInPrototype(), we want to consider it as coming from a
    // prototype to make it visually distinctive.  If in future we need to
    // decouple the two concepts we can, but we're sensitive here to python
    // marshalling costs.
    isInPrototype = prim.IsInPrototype() || prim.IsInstanceProxy();


    // only show camera guides for now, until more guide generation logic is
    // moved into usdImaging
    supportsGuides = prim.IsA<UsdGeomCamera>();

    supportsDrawMode = isActive && isDefined && 
        !isInPrototype && prim.GetPath() != SdfPath::AbsoluteRootPath() &&
        UsdModelAPI(prim).IsModel();

    isInstance = prim.IsInstance();
    isVisibilityInherited = false;
    if (img){
        UsdAttributeQuery query(img.GetVisibilityAttr());
        TfToken visibility = UsdGeomTokens->inherited;
        query.Get(&visibility, time);
        isVisibilityInherited = (visibility == UsdGeomTokens->inherited);
        visVaries = query.ValueMightBeTimeVarying();
    }
    else {
        visVaries = false;
    }

    if (prim.GetParent())
        name = prim.GetName().GetString();
    else
        name = _tokens->root.GetString();
    typeName = prim.GetTypeName().GetString();

    displayName = prim.GetDisplayName();
}

/*static*/
UsdviewqUtils::PrimInfo
UsdviewqUtils::GetPrimInfo(const UsdPrim &prim, const UsdTimeCode time)
{
    return PrimInfo(prim, time);
}

PXR_NAMESPACE_CLOSE_SCOPE

