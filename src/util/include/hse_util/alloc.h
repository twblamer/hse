/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2015-2020 Micron Technology, Inc.  All rights reserved.
 */

#ifndef HSE_PLATFORM_ALLOC_H
#define HSE_PLATFORM_ALLOC_H

#include <hse_util/base.h>
#include <hse_util/inttypes.h>

/* MTF_MOCK_DECL(alloc) */

#if defined(HSE_UNIT_TEST_MODE) && HSE_UNIT_TEST_MODE == 1
#include <hse_test_support/allocation.h>
#endif /* HSE_UNIT_TEST_MODE */

/**
 * alloc_aligned() - allocated aligned memory
 * @size:   desired number of bytes
 * @align:  desired alignment
 *
 * %align must be a power-of-two
 */
/* MTF_MOCK */
void *
alloc_aligned(size_t size, size_t align);

/* MTF_MOCK */
void
free_aligned(const void *ptr);

#define alloc_page_aligned(_sz) alloc_aligned((_sz), PAGE_SIZE)

#if defined(HSE_UNIT_TEST_MODE) && HSE_UNIT_TEST_MODE == 1
#include "alloc_ut.h"
#endif /* HSE_UNIT_TEST_MODE */

#include <hse_util/slab.h>

#endif
