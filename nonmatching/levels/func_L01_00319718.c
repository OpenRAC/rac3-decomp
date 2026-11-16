/* PAL near miss (Codex wave 4): near miss: 15 words differ with the file's flags.
 * Worker's note: 15 diff: count-up loop becomes countdown/bgez; all calls, constants and body loads/stores agree. Retail bound 6 retained. Sister build/codex/pool/X4/pal_func_L01_00319718_rac2.c; best log build/codex/w185/func_L01_00319718-01.log. Six checks: != loop 78 diff, ...
 */
#include "common.h"

/* localdecomp:start func_L01_00319718 */
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
/* Ported from rac2-decomp/src/game/0032BA88-rc2.c. */
extern s8 D_L01_00273B80[];
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(s32, s32, s32, s32, f32, f32, f32);
void func_L01_00319718(s32 owner) {
    extern void func_L01_00319880(s32, s32);
    s32 i;
    s32 table_addr;
    s8 *piece;
    s8 *table;

    table = D_L01_00273B80;
    piece = table + 0x30;
    table_addr = (s32) table;
    for (i = 0; i < 6;) {
        i++;
        if ((*(s32 *)((s8 *)(piece) + (0x6C))) == owner) {
            func_L01_00319880(owner, table_addr);
            if ((*(s32 *)((s8 *)(piece) + (0x70))) == 0) {
                func_003D9508((s32)piece, 0x31, 0x3F7F0000, 1, func_003824E0(0.125f, 0.25f) * 5.0f, 1.25f, 0.0f);
                func_003D9508((s32)piece, 0x31, 0x5F7F7F7F, 1, func_003824E0(0.0625f, 0.125f) * 5.0f, 1.24f, 0.0f);
                func_003D9508((s32)piece, 0xB, 0x103F0000, 1, func_003824E0(0.15f, 0.35f) * 5.0f, 1.23f, 0.0f);
            }
        }
        piece += 0xB0;
        table_addr += 0xB0;
    }
}
/* localdecomp:end func_L01_00319718 */
