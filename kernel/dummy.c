// (c) Copyright Paul Campbell paul@taniwha.com 2013
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) version 3, or any
// later version accepted by Paul Campbell , who shall
// act as a proxy defined in Section 6 of version 3 of the license.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public 
// License along with this library.  If not, see <http://www.gnu.org/licenses/>.
//

#include "protocol.h"

static void xxxx() __naked {
	__asm;
	.area CSEG    (CODE)
	.globl	_CODE_HEADER
_CODE_HEADER:
	.db	0, 0, 0, 0	// CRC will go here
	.db	0, 0		// len from arch to end of code - must be 0
	.db	THIS_ARCH
	.db	THIS_CODE_BASE
	.db	0, 0		// version (little endian)
	clr	a
	mov	dpl, a
	ret
	.area DSEG    (DATA)
	.globl	_data_end
_data_end:
	.ds	1
	.area XSEG    (XDATA)
	.globl	_xseg_end
_xseg_end:
	.ds	1

	__endasm;
}
