/* PAL near miss (Codex wave 4): near miss: 1 words differ with the file's flags.
 * Worker's note: sister build/codex/pool/X4/pal_func_L01_002FD818_rac2.c; best log build/codex/w184/func_L01_002FD818-04.log; 1 diff: unsigned counter prevents countdown, but emits sltiu where retail uses slti; assigned flags verified
 */
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
#include "common.h"
/* localdecomp:start func_L01_002FD818 */
extern s8 D_L01_0026EAB0_002FD818[];
void func_L01_002FD818(s32 owner) {
    extern void func_L01_002FDA10(s32, s32);
    extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
    extern f32 func_003824E0(f32, f32);
    u32 i;
    s32 state;
    s8 *slot;
    s8 *pool;

    pool = D_L01_0026EAB0_002FD818;
    slot = pool + 0x30;
    state = (s32) pool;
    i = 0;
    for (;;) {
        ++i;
        if ((*(s32 *)((s8 *)(slot) + (0x5C))) == owner) {
            func_L01_002FDA10(owner, state);
            if ((*(s32 *)((s8 *)(slot) + (0x64))) == 0) {
                func_003D9508(slot, 0x31, 0x3F007F00, 1, func_003824E0(0.125f, 0.25f) * 5.0f, 1.25f, 0.0f);
                func_003D9508(slot, 0x31, 0x5F7F7F7F, 1, func_003824E0(0.0625f, 0.125f) * 5.0f, 1.24f, 0.0f);
                func_003D9508(slot, 0xB, 0x10003F00, 1, func_003824E0(0.15f, 0.35f) * 5.0f, 1.23f, 0.0f);
            }
        }
        slot += 0xA0;
        state += 0xA0;
        if (i >= 3) break;
    }
}
/* localdecomp:end func_L01_002FD818 */
