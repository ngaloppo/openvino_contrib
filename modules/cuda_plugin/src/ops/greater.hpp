// Copyright (C) 2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "cudnn_tensor_op_base.hpp"

namespace CUDAPlugin {

class GreaterOp : public CuDnnTensorOpBase {
public:
    GreaterOp(const CreationContext& context,
              const std::shared_ptr<ngraph::Node>& node,
              IndexCollection&& inputIds,
              IndexCollection&& outputIds);
};

}  // namespace CUDAPlugin