/* PAL near miss (Codex wave 4): near miss: 3 words differ with the file's flags.
 * Worker's note: Sister build/codex/pool/X4/pal_func_L01_0030B818_rac2.c (rac2-decomp/src/levels/shared/L00_003BCDC0-rc2.c:31-43); best log build/codex/w169/func_L01_0030B818-03.log; 3 diff, improved from 5: speculative a1 move, bne instead of bnel with duplicated increment, ...
 */
#include "common.h"
/* localdecomp:start func_L01_0030B818 */
/* SPDX-License-Identifier: MIT
 * MIT License
 *
 * Copyright (c) 2026 RC2 decomp contributions
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


extern B00309EA0 D_L01_00270FF0[16];

void func_L01_0030B818(void *arg0) {
    extern void func_L01_0030B880(s32, void *);
    s32 owner = (s32)arg0;
    s8 *record;
    s8 *table_end;

    record = (s8 *)D_L01_00270FF0;
    table_end = record + 0xB00;
    do {
        if (*(s32 *)(record + 0xA0) != owner) {
            record += 0xB0;
            continue;
        }
        func_L01_0030B880(owner, record);
        record += 0xB0;
    } while ((s32) record < (s32) table_end);
}
/* localdecomp:end func_L01_0030B818 */
