#include "common.h"

typedef struct S_005C2BB8 {
    u8 pad0[4];
    s16 h4;
    u8 b6;
    u8 pad7[0x11];
    void (*f18)(s32, s32);
    s32 f1C;
} S_005C2BB8;

/* localdecomp:start func_L39_005C2B10 */
extern s16 D_00225660[];
extern void func_L39_005C2148(void);
extern void func_00194670(void);
extern void func_00193590(void);
extern void func_00194668(void);
extern void func_0038CB50(s32);

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
/* from rac2-decomp's func_002B7CE0, renamed */
s16 func_L39_005C2B10(s32 arg0) {
    s16 *q;
    if (arg0 != 0) {
        while (1) {
            func_L39_005C2148();
            func_00194670();
            func_00193590();
            func_00194668();
            if (D_00225660[2] == 0) {
                break;
            }
            func_0038CB50(10000);
            if (D_00225660[2] == 0) {
                break;
            }
        }
    } else {
        func_L39_005C2148();
        func_00194670();
        func_00193590();
        func_00194668();
    }
    q = D_00225660;
    return q[2];
}
/* localdecomp:end func_L39_005C2B10 */

/* localdecomp:start func_L39_005C2BB8 */
extern S_005C2BB8 D_225660;
extern s32 func_194B40(void);
extern void func_1264E0(s32);

void func_L39_005C2BB8(s32 a0) {
    S_005C2BB8 *p;
    void (*cb)(s32, s32);
    s32 data;
    s32 flag;

    if (a0 == 1) {
        p = &D_225660;
        if (p->h4 == 0) {
            p->f18 = 0;
            p->f1C = 0;
        } else if (func_194B40() != 0) {
            p->h4 = 2;
        } else {
            func_1264E0(0);
            flag = p->b6 == 0;
            cb = p->f18;
            p->h4 = 0;
            p->b6 = 0;
            if (cb != 0) {
                data = p->f1C;
                p->f18 = 0;
                p->f1C = 0;
                cb(data, flag);
            }
        }
    }
}
/* localdecomp:end func_L39_005C2BB8 */
