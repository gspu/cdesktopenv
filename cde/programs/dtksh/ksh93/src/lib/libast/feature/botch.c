/*
 * CDE - Common Desktop Environment
 *
 * Copyright (c) 1993-2012, The Open Group. All rights reserved.
 *
 * These libraries and programs are free software; you can
 * redistribute them and/or modify them under the terms of the GNU
 * Lesser General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * These libraries and programs are distributed in the hope that
 * they will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with these libraries and programs; if not, write
 * to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301 USA
 */
/* $XConsortium: botch.c /main/3 1995/11/01 17:25:22 rswiston $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*        THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF        *
*                    AT&T BELL LABORATORIES                    *
*         AND IS NOT TO BE DISCLOSED OR USED EXCEPT IN         *
*            ACCORDANCE WITH APPLICABLE AGREEMENTS             *
*                                                              *
*          Copyright (c) 1994 AT&T Bell Laboratories           *
*              Unpublished & Not for Publication               *
*                     All Rights Reserved                      *
*                                                              *
*       The copyright notice above does not evidence any       *
*      actual or intended publication of such source code      *
*                                                              *
*               This software was created by the               *
*           Software Engineering Research Department           *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                   advsoft@research.att.com                   *
*                 Randy Hackbarth 908-582-5245                 *
*                  Dave Belanger 908-582-7427                  *
*                                                              *
***************************************************************/

/* : : generated by proto : : */

#line 1

#if !defined(__PROTO__)
#if defined(__STDC__) || defined(__cplusplus) || defined(_proto) || defined(c_plusplus)
#if defined(__cplusplus)
#define __MANGLE__	"C"
#else
#define __MANGLE__
#endif
#define __STDARG__
#define __PROTO__(x)	x
#define __OTORP__(x)
#define __PARAM__(n,o)	n
#if !defined(__STDC__) && !defined(__cplusplus)
#if !defined(c_plusplus)
#define const
#endif
#define signed
#define void		int
#define volatile
#define __V_		char
#else
#define __V_		void
#endif
#else
#define __PROTO__(x)	()
#define __OTORP__(x)	x
#define __PARAM__(n,o)	o
#define __MANGLE__
#define __V_		char
#define const
#define signed
#define void		int
#define volatile
#endif
#if defined(__cplusplus) || defined(c_plusplus)
#define __VARARG__	...
#else
#define __VARARG__
#endif
#if defined(__STDARG__)
#define __VA_START__(p,a)	va_start(p,a)
#else
#define __VA_START__(p,a)	va_start(p)
#endif
#endif

#line 9
#include <sys/types.h>

#include "FEATURE/types"
#include <ast_lib.h>

extern __MANGLE__ int		getgroups __PROTO__((int, gid_t*));
extern __MANGLE__ int		printf __PROTO__((const char*, ...));

int main()
{
#if _lib_getgroups
	if (sizeof(gid_t) < sizeof(int))
	{
		int	n;
		gid_t		groups[32 * sizeof(int) / sizeof(gid_t)];

		for (n = 0; n < sizeof(int) / sizeof(gid_t); n++)
			groups[n] = ((gid_t)0);
		if ((n = getgroups((sizeof(groups) / sizeof(groups[0])) / (sizeof(int) * sizeof(int)), groups)) > 0)
		{
			if (groups[1] != ((gid_t)0)) n = 0;
			else
			{
				for (n = 0; n < sizeof(int) / sizeof(gid_t); n++)
					groups[n] = ((gid_t)-1);
				if ((n = getgroups((sizeof(groups) / sizeof(groups[0])) / (sizeof(int) * sizeof(int)), groups)) > 0)
				{
					if (groups[1] != ((gid_t)-1)) n = 0;
				}
			}
		}
		if (n <= 0)
		{
			printf("#undef	getgroups\n");
			printf("#define getgroups	_ast_getgroups /* implementation botches gid_t* arg */\n");
		}
	}
#endif
	return(0);
}
