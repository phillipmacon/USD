//
// Copyright 2022 Pixar
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
#ifndef PXR_USD_IMAGING_USD_IMAGING_DATA_SOURCE_STAGE_H
#define PXR_USD_IMAGING_USD_IMAGING_DATA_SOURCE_STAGE_H

#include "pxr/imaging/hd/dataSource.h"
#include "pxr/usdImaging/usdImaging/api.h"

#include "pxr/base/tf/declarePtrs.h"

#include "pxr/pxr.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_DECLARE_REF_PTRS(UsdStage);

/// Returns a dataSource that contains UsdStage level data.  In particular, this
/// populates the HdarSystem data.
class UsdImagingDataSourceStage : public HdContainerDataSource
{
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceStage);

public: //  HdContainerDataSource overrides
    USDIMAGING_API
    TfTokenVector GetNames() override;

    USDIMAGING_API
    HdDataSourceBaseHandle Get(const TfToken& name) override;

private:
    UsdImagingDataSourceStage(UsdStageRefPtr stage);

    UsdStageRefPtr _stage;
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceStage);

PXR_NAMESPACE_CLOSE_SCOPE

#endif
