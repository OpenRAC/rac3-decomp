/* PAL near miss (Codex wave 11): near miss: 283 words differ in its file's context with the file's flags.
 * Replaces the earlier draft (Codex wave 7 near miss: does not compile under tools/check.py in its file's context with the file's flags, measured 2026-11-21;
 * this one: 283).
 * Worker's note: new plain-C draft (no volatile on game data; scratchpad reads through the literal 0x70000000 volatile form AGENTS allows; file prototype kept; Ps2EeAs small-data declarations: plain externs for D_001DA050/D_001D4BB0..., .extern hint for D_001D8070, .sdata Q for D_001D8020): check.py 283 diff (wave 7 study aid 303). TEX0 grouped as retail (constants 1<<34 and 1<<63 apart) fixed the frame (0xA0, s5); left: the first loop register choice, &D_00225C00[n].image1 through its own base (retail s3 = &D_00225C00+8), the TBW clamp (retail slt with -1 then movz on the exponent, ours movn on 1<<e), D_001D4BB0 store pushed into a delay slot ($gp form) where retail keeps lui $at/sw, and the packet loop (not yet compared in detail)
 */
#include "common.h"

/* localdecomp:start func_003AA780 */
typedef unsigned int Q_003AA780 __attribute__((mode(TI)));
typedef struct {
    unsigned long tex;
    u16 image1;
    u16 image0;
    s16 width;
    s16 height;
} T_003AA780;
typedef struct {
    s16 count0;
    s16 count2;
    s16 h4;
    s16 texture_count;
    s16 anim_count;
    u8 padA[6];
    void *geometry;
    u8 *commands;
    T_003AA780 *textures;
    u8 *images;
    u8 pad20[4];
    s32 mode;
    s32 extra;
} M_003AA780;
typedef struct {
    u8 *image0;
    u16 zero;
    u16 base0;
    u8 *image1;
    u8 width;
    u8 height;
    u16 base1;
} U_003AA780;
extern s32 D_001D4BB0;
extern s32 D_001D9BFC;
extern U_003AA780 D_00225C00[];
extern u8 D_00143950[];
extern f32 D_001D8070;
__asm__(".extern D_001D8070, 4");
extern f32 D_001D8094;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern u8 *D_001DA050;
extern Q_003AA780 D_001D8020 __attribute__((section(".sdata")));

void func_003AA780(O_A4DC8 *object, f32 x, f32 y, s32 color, f32 animation, f32 *matrix) {
    extern void func_003AA328(void);
    extern void func_0038D200(f32 *, void *, f32);
    extern void func_0038DA20(f32 *, f32 *, f32 *);
    extern void func_003A08E8(void *, f32 *, s32, s32);
    extern void func_003A0A28(void *, f32 *, s32, s32, s32);
    M_003AA780 *o = (M_003AA780 *)object;
    f32 transformed[16];
    T_003AA780 *t;
    U_003AA780 *upload;
    u8 *command;
    unsigned long *q;
    volatile unsigned long *v;
    unsigned long tag;
    s32 reg;
    s32 i;
    s32 n;
    s32 base;
    s32 base0;
    s32 base1;
    s32 shift;

    if ((color >> 24) == 0) {
        return;
    }
    for (i = 0; i < o->texture_count; i++) {
        t = &o->textures[i];
        base = D_001D4BB0;
        n = D_001D9BFC;
        base0 = base >> 8;
        base += 0x400;
        base1 = base >> 8;
        shift = t->width - 6;
        shift = (shift > -1) ? shift : 0;
        t->tex = (((((unsigned long)base1 | ((unsigned long)(1 << shift) << 14))
                    | ((((long)(u16)t->width << 48) >> 22) | 0x1300000))
                   | (((long)(u16)t->height << 48) >> 18))
                  | (((unsigned long)base0 << 37) | ((unsigned long)1 << 34)))
                 | ((unsigned long)1 << 63);
        D_001D4BB0 = base + (1 << (t->width + t->height));
        if (n < 64) {
            upload = &D_00225C00[n];
            upload->base0 = base0;
            upload->zero = 0;
            upload->image0 = o->images + t->image0 * 16;
            upload->image1 = o->images + t->image1 * 16;
            upload->width = t->width;
            upload->base1 = base1;
            upload->height = t->height;
            D_001D9BFC = n + 1;
        }
    }
    func_003AA328();
    if (D_001D8064) {
        matrix[10] *= D_001D8060 * 1.126f;
        matrix[0] *= 1.18f;
    }
    func_0038D200(matrix + 12, matrix + 12, 166.666f);
    D_001D8070 = (f32)(D_001D4BC0 >> 1) / D_00225900.x;
    D_001D8094 = -((f32)(D_001D4BC4 >> 1) / D_00225900.y);
    if (D_00143950[0xAD]) {
        D_001D8094 *= 0.75000006f;
    }
    func_0038DA20(transformed, &D_001D8070, matrix);
    transformed[12] += (f32)D_001D4BD0 + x * 16.0f;
    transformed[13] += (f32)D_001D4BD4 + y * 16.0f;
    func_0038D680((f32 *)0x70001FC0);
    if (o->anim_count) {
        func_003AA168((A_003AA380 *)object, (void *)0x70002000, animation);
    }
    if (!o->mode) {
        func_003A08E8(o->geometry, transformed, o->count0, color);
    } else {
        func_003A0A28(o->geometry, transformed, o->count0, o->extra, color);
    }
    tag = 0x80000004CC007FFBUL;
    if (o->texture_count) {
        command = o->commands;
        reg = 0x5C;
    } else {
        command = o->commands + 4;
        reg = 0x4C;
    }
    for (i = 0; i < o->count2; i++) {
        if (o->texture_count && (*(s32 *)command >> 8) == -1) {
            n = command[0];
            if (n < o->texture_count) {
                tag = o->textures[n].tex;
            } else {
                tag = 0x80000004CC007FFBUL;
            }
            i--;
        } else {
            ((u32 *)D_001DA050)[0] = 0x10000008;
            ((u32 *)D_001DA050)[1] = 0;
            ((u32 *)D_001DA050)[2] = 0;
            ((u32 *)D_001DA050)[3] = 0x50000008;
            D_001DA050 += 0x10;
            *(Q_003AA780 *)D_001DA050 = D_001D8020;
            D_001DA050 += 0x10;
            q = (unsigned long *)D_001DA050;
            q[0] = tag;
            q[1] = reg;
            v = (volatile unsigned long *)(0x70000000 + command[0] * 32);
            q[2] = *v++;
            q[3] = *v++;
            q[4] = *v;
            v = (volatile unsigned long *)(0x70000000 + command[1] * 32);
            q[5] = *v++;
            q[6] = *v++;
            q[7] = *v;
            v = (volatile unsigned long *)(0x70000000 + command[3] * 32);
            q[8] = *v++;
            q[9] = *v++;
            q[10] = *v;
            v = (volatile unsigned long *)(0x70000000 + command[2] * 32);
            q[11] = *v++;
            q[12] = *v++;
            q[13] = *v;
            D_001DA050 += 0x70;
        }
        command += 4;
    }
}
/* localdecomp:end func_003AA780 */
