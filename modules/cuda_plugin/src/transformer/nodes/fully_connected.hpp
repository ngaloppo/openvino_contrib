// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <array>
#include <ngraph/ops.hpp>
#include <ngraph/type/element_type.hpp>

namespace CUDAPlugin::nodes {

class FullyConnected : public ngraph::op::Op {
 public:
  FullyConnected(const ngraph::Output<Node>& A,
                 const ngraph::Output<Node>& B,
                 const ngraph::Output<Node>& C,
                 const bool& transpose_a,
                 const bool& transpose_b);

  inline static constexpr type_info_t type_info{"FullyConnected", 0};
  const type_info_t& get_type_info() const override { return type_info; }

  bool visit_attributes(ngraph::AttributeVisitor& visitor) override;

  std::shared_ptr<ngraph::Node> clone_with_new_inputs(
      const ngraph::OutputVector& new_args) const override;

  void validate_and_infer_types() override;

  bool get_transpose_a() const { return m_transpose_a; }
  bool get_transpose_b() const { return m_transpose_b; }

 private:
  bool m_transpose_a;
  bool m_transpose_b;
};

} // namespace CUDAPlugin::nodes