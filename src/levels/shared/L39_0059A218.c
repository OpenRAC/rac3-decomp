#include "common.h"

/* localdecomp:start func_L39_0059A218 */
extern s32  D_L39_0024CAD8[] __attribute__((section(".sdata")));
extern s8 D_L39_0025F68C[];

/* SPDX-License-Identifier: MIT
 * MIT License
 *
 * Copyright (c) 2026 Forja contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/* from rac2-decomp's func_00288970, renamed */
s32 func_L39_0059A218(u32 arg0, s32 *arg1) {
    if (arg0 > 0x40000U) {
        *arg1 = 0;
        return -1;
    }
    *arg1 = (*(s32 *)((s32)D_L39_0025F68C) + D_L39_0024CAD8[0]) - arg0;
    return 0;
}
/* localdecomp:end func_L39_0059A218 */
