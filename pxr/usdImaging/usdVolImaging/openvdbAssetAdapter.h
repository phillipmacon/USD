//
// Copyright 2018 Pixar
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
#ifndef PXR_USD_IMAGING_USD_VOL_IMAGING_OPENVDB_ASSET_ADAPTER_H
#define PXR_USD_IMAGING_USD_VOL_IMAGING_OPENVDB_ASSET_ADAPTER_H

/// \file usdImaging/openvdbAssetAdapter.h

#include "pxr/pxr.h"
#include "pxr/usdImaging/usdImaging/fieldAdapter.h"
#include "pxr/usdImaging/usdVolImaging/api.h"

PXR_NAMESPACE_OPEN_SCOPE


class UsdPrim;

/// \class UsdImagingOpenVDBAssetAdapter
///
/// Adapter class for fields of type OpenVDBAsset
///
class UsdImagingOpenVDBAssetAdapter : public UsdImagingFieldAdapter {
public:
    using BaseAdapter = UsdImagingFieldAdapter;

    UsdImagingOpenVDBAssetAdapter()
        : UsdImagingFieldAdapter()
    {}

    USDVOLIMAGING_API
    ~UsdImagingOpenVDBAssetAdapter() override;

    // ---------------------------------------------------------------------- //
    /// \name Scene Index Support
    // ---------------------------------------------------------------------- //

    USDIMAGING_API
    TfTokenVector GetImagingSubprims(UsdPrim const& prim) override;

    USDIMAGING_API
    TfToken GetImagingSubprimType(UsdPrim const& prim, TfToken const& subprim)
        override;

    USDIMAGING_API
    HdContainerDataSourceHandle GetImagingSubprimData(
            UsdPrim const& prim,
            TfToken const& subprim,
            const UsdImagingDataSourceStageGlobals &stageGlobals) override;

    // ---------------------------------------------------------------------- //
    /// \name Data access
    // ---------------------------------------------------------------------- //

    USDVOLIMAGING_API
    VtValue Get(UsdPrim const& prim,
                SdfPath const& cachePath,
                TfToken const& key,
                UsdTimeCode time,
                VtIntArray *outIndices) const override;

    USDVOLIMAGING_API
    TfToken GetPrimTypeToken() const override;
};


PXR_NAMESPACE_CLOSE_SCOPE

#endif // PXR_USD_IMAGING_USD_VOL_IMAGING_OPENVDB_ASSET_ADAPTER_H
