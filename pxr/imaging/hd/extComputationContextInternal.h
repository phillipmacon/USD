//
// Copyright 2017 Pixar
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
#ifndef PXR_IMAGING_HD_EXT_COMPUTATION_CONTEXT_INTERNAL_H
#define PXR_IMAGING_HD_EXT_COMPUTATION_CONTEXT_INTERNAL_H

#include "pxr/pxr.h"

#include "pxr/imaging/hd/api.h"
#include "pxr/imaging/hd/extComputationContext.h"

#include <map>

PXR_NAMESPACE_OPEN_SCOPE

///
/// Hydra implementation of the HdExtComputationContext public interface.
/// The class provides additional API for setting up the context.
///
class HdExtComputationContextInternal final : public HdExtComputationContext {
public:
    HD_API
    HdExtComputationContextInternal();

    HD_API
    virtual ~HdExtComputationContextInternal();

    ///
    /// Obtains the value of an named input to the computation.
    ///
    /// The code will issue a coding error and return a empty value
    /// if the input is missing.
    ///
    HD_API
    virtual const VtValue &GetInputValue(const TfToken &name) const override;

    ///
    /// Obtains the value of an named input to the computation.
    ///
    /// If the input isn't present, nullptr will be returned.
    ///
    HD_API
    virtual const VtValue *GetOptionalInputValuePtr(
                                            const TfToken &name) const override;
    ///
    /// Sets the value of the specified output.
    ///
    HD_API
    virtual void SetOutputValue(const TfToken &name,
                                 const VtValue &output) override;


    /// Adds the named input to the execution environment.
    /// If the input already exists, the value is not replaced.
    HD_API
    void SetInputValue(const TfToken &name, const VtValue &input);

    /// Fetches the named output from the execution environment.
    /// returns false if the output is not present.
    HD_API
    bool GetOutputValue(const TfToken &name, VtValue *output) const;

    /// returns true is an error occur in processing, such that the
    /// outputs are invalid.
    HD_API
    bool HasComputationError();

    ///
    /// Called to indicate an error occurred while executing a computation
    /// so that it's output are invalid.
    ///
    HD_API
    virtual void RaiseComputationError() override;

private:
    typedef std::map<TfToken, VtValue> ValueMap;

    ValueMap m_inputs;
    ValueMap m_outputs;
    bool     m_compuationError;


    HdExtComputationContextInternal(const HdExtComputationContextInternal &)
                                                                       = delete;
    HdExtComputationContextInternal &operator = (
                             const HdExtComputationContextInternal &) = delete;

};

PXR_NAMESPACE_CLOSE_SCOPE

#endif // PXR_IMAGING_HD_EXT_COMPUTATION_CONTEXT_INTERNAL_H
