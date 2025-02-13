/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Support for Intel Camera Imaging ISP subsystem.
 * Copyright (c) 2015, Intel Corporation.
 */

#ifndef _IA_CSS_CIRCBUF_COMM_H
#define _IA_CSS_CIRCBUF_COMM_H

#include <linux/build_bug.h>

#include <type_support.h>  /* uint8_t, uint32_t */

#define IA_CSS_CIRCBUF_PADDING 1 /* The circular buffer is implemented in lock-less manner, wherein
				   * the head and tail can advance independently without any locks.
				   * But to achieve this, an extra buffer element is required to detect
				   * queue full & empty conditions, wherein the tail trails the head for
				   * full and is equal to head for empty condition. This causes 1 buffer
				   * not being available for use.
				   */

/****************************************************************
 *
 * Portable Data structures
 *
 ****************************************************************/
/**
 * @brief Data structure for the circular descriptor.
 */
typedef struct ia_css_circbuf_desc_s ia_css_circbuf_desc_t;
struct ia_css_circbuf_desc_s {
	u8 size;	/* the maximum number of elements*/
	u8 step;   /* number of bytes per element */
	u8 start;	/* index of the oldest element */
	u8 end;	/* index at which to write the new element */
};

#define SIZE_OF_IA_CSS_CIRCBUF_DESC_S_STRUCT				\
	(4 * sizeof(uint8_t))

static_assert(sizeof(struct ia_css_circbuf_desc_s) == SIZE_OF_IA_CSS_CIRCBUF_DESC_S_STRUCT);

/**
 * @brief Data structure for the circular buffer element.
 */
typedef struct ia_css_circbuf_elem_s ia_css_circbuf_elem_t;
struct ia_css_circbuf_elem_s {
	u32 val;	/* the value stored in the element */
};

#define SIZE_OF_IA_CSS_CIRCBUF_ELEM_S_STRUCT				\
	(sizeof(uint32_t))

static_assert(sizeof(struct ia_css_circbuf_elem_s) == SIZE_OF_IA_CSS_CIRCBUF_ELEM_S_STRUCT);

#endif /*_IA_CSS_CIRCBUF_COMM_H*/
