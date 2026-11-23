/* func_00393930 (frontbin): boot_elf func_00393D10's Codex wave 10 draft with its names moved (config/frontend_pairs.tsv), FE-1
   2026-11-21. Since a4d6c64c it is in src/frontbin/393620.c (line 0x00393620, -mno-split-addresses without @ps2as).
   67 differences (tools/check.py) with that line; MATCH with @ps2as on it (2026-11-22, the file's other C still MATCH).
   The one difference is a nop SN's assembler adds after mfc1 $a1, $f1; retail reads $a1 in the next instruction.
   393620.c also holds func_00393690 and func_00393B58, which another contributor claims, so the line is not changed here.
   NTSC-U: no twin in config/us/map.tsv (its code differs there). */

#include "vu0.h"
typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p10[0x5C]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_00393930;
void func_00393930(S_00393930 *p) {
    extern s32 func_003963D0();
    u8 *b = p->b70;
    s32 n, step;
    if (p->fC != 0) {
        s32 initial = *p->fC;
        if (initial < 0) initial = 0;
        p->f78 = initial;
        if (p->f8 < initial) p->f78 = p->f8;
    }
    if (p->f74 != p->f78) {
        p->f7C = 150;
        if (p->f6C >= 24) {
            n = __builtin_abs(p->f74 - p->f78);
            if (n != 0) {
                step = (s32)(sqrt_asm((f32)n / 25.0f) * 5.0f);
                { s32 quarter = n / 4; if (quarter > step) step = quarter; }
                if (step > 121) step = 121;
                else if (step < 1) step = 1;
                b[3] += step;
                if (b[3] >= 3) {
                    u32 accum = b[3];
                    s32 current = p->f74;
                    step = accum >> 1;
                    if (p->f78 < current) p->f74 = current - step;
                    else p->f74 = current + step;
                    b[3] -= step * 2;
                }
            }
        }
    }
    if (p->f7C >= 4) {
        if (b[0] < 7) b[0]++;
        else if (b[1] < 7) b[1]++;
    } else {
        if (b[1] != 0 || b[0] != 0) p->f6C = 1;
        if (b[1] != 0) b[1]--;
        else if (b[0] != 0) b[0]--;
    }
    func_003963D0((u8 *)p + 0x40);
}

