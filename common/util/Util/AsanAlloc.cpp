/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "Util/AsanAlloc.h"

#if !defined (__clang__)
#include <malloc.h>
#endif

void* alignedAlloc(size_t alignment, size_t size) noexcept {
// GCC only supports ASAN aligned_alloc as of September 2014, which roughly
// corresponds to version 5 and above. This code can be deprecated once
// Facebook upgrade to GCC 5.x
#if __clang__ || __GNUC__ > 4
  return aligned_alloc(alignment, size);
#else
  return memalign(alignment, size);
#endif
}
