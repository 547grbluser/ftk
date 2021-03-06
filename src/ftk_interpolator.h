/*
 * File: ftk_interpolator.h    
 * Author:  Li XianJing <xianjimli@hotmail.com>
 * Brief:   interpolator for animation.
 *
 * Copyright (c) 2009 - 2011  Li XianJing <xianjimli@hotmail.com>
 *
 * Licensed under the Academic Free License version 2.1
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
 * History:
 * ================================================================
 * 2011-03-20 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef FTK_INTERPOLATOR_H
#define FTK_INTERPOLATOR_H
#include "ftk_typedef.h"
#include "ftk_log.h"

FTK_BEGIN_DECLS

struct _FtkInterpolator;
typedef struct _FtkInterpolator FtkInterpolator;

typedef float (*FtkInterpolatorGet)(FtkInterpolator* thiz, float percent);
typedef void  (*FtkInterpolatorDestroy)(FtkInterpolator* thiz);

struct _FtkInterpolator
{
	FtkInterpolatorGet get;
	FtkInterpolatorDestroy destroy;

	char priv[ZERO_LEN_ARRAY];
};

static inline float ftk_interpolator_get(FtkInterpolator* thiz, float percent)
{
	return_val_if_fail(thiz != NULL && thiz->get != NULL, 0);

	return thiz->get(thiz, percent);
}

static inline void ftk_interpolator_destroy(FtkInterpolator* thiz)
{
	if(thiz != NULL && thiz->destroy != NULL)
	{
		thiz->destroy(thiz);
	}

	return;
}

FTK_END_DECLS

#endif/*FTK_INTERPOLATOR_H*/

