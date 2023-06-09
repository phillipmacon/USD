//
// Copyright 2021 Pixar
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
#ifndef PXR_IMAGING_HD_LEGACY_PRIM_SCENE_INDEX_H
#define PXR_IMAGING_HD_LEGACY_PRIM_SCENE_INDEX_H

#include "pxr/imaging/hd/retainedSceneIndex.h"

PXR_NAMESPACE_OPEN_SCOPE

class HdSceneDelegate;

TF_DECLARE_REF_PTRS(HdLegacyPrimSceneIndex);

/// \class HdLegacyPrimSceneIndex
///
/// Extends HdRetainedSceneIndex to instantiate and dirty HdDataSourceLegacyPrim
/// data sources.
/// 
/// During emulation of legacy HdSceneDelegates, HdRenderIndex forwards
/// prim insertion calls here to produce a comparable HdSceneIndex
/// representation 
class HdLegacyPrimSceneIndex : public HdRetainedSceneIndex
{
public:

    static HdLegacyPrimSceneIndexRefPtr New() {
        return TfCreateRefPtr(new HdLegacyPrimSceneIndex);
    }

    /// custom insertion wrapper called by HdRenderIndex during population
    /// of legacy HdSceneDelegates
    void AddLegacyPrim(SdfPath const &id, TfToken const &type,
        HdSceneDelegate *sceneDelegate);

    /// Remove only the prim at \p id without affecting children.
    ///
    /// If \p id has children, it is replaced by an entry with no type
    /// and no data source.  If \p id does not have children, it is
    /// removed from the retained scene index.
    ///
    /// This is called by HdRenderIndex on behalf of legacy
    /// HdSceneDelegates to emulate the original behavior of
    /// Remove{B,R,S}Prim, which did not remove children.
    ///
    void RemovePrim(SdfPath const &id);

    /// extends to also call DirtyPrim on HdDataSourceLegacyPrim
    void DirtyPrims(
        const HdSceneIndexObserver::DirtiedPrimEntries &entries) override;
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif
