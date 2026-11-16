/* PAL near miss (Codex wave 4): near miss: 4 words differ with the file's flags.
 * Worker's note: sister build/codex/pool/X4/pal_func_L01_00447490_rac2.c (rac2-decomp/src/game/002A9640-rc2.c); best log build/codex/w182/func_L01_00447490-03-final.log; 4 diff: repeated slot-byte read reloads instead of retail move, table-base scheduling differs; ...
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
/* localdecomp:start func_L01_00447490 */

extern s8 D_L01_001EEC80[];

/* Finds the effect slot owned by this object. Returns it if it matches the flag mask, otherwise releases the slot when allowed. */

void *func_L01_00447490(void *object, u32 flag_mask, s32 keep_slot) {
    s8 *entry;
    void *owner;

    if (*(u8 *)((s8 *)object + 0xA8) == 0xFF) {
        return 0;
    }
    entry = (s8 *)&D_L01_001EEC80 + (*(u8 *)((s8 *)object + 0xA8) << 6);
    owner = *(void **)(entry + 0x38);
    if (owner != object) {
        return 0;
    }
    if (*(u32 *)(entry + 0x24) & flag_mask) {
        return entry;
    }
    if (keep_slot == 0) {
        *(u8 *)((s8 *)owner + 0xA8) = 0xFF;
    }
    return 0;
}
/* localdecomp:end func_L01_00447490 */
