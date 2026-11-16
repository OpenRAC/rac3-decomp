/* PAL near miss, P01 wave 2 (2026-11-16), reconstructed from retail.
 * File flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stock checker: 21 positional differences. Three final source forms produced
 * identical checker diffs. Remaining: f20/f21 allocation, division scheduling
 * and the zero temporary used for the second angular bound.
 * Not a full-program match; retain the source INCLUDE_ASM.
 */
#include "common.h"
typedef struct { f32 xyz[3]; u8 pad[4]; u8 *target; } B_333DB8;
typedef struct { u8 pad[0x10]; f32 angle, result; u8 gap[4]; u8 state; } R_333DB8;
extern s32 *func_L07_00333918(void *);
extern u8 *func_L01_00449020(u8 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L03_0032FB70(f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458_00333DB8;
extern u8 *D_L07_001DF41C_00333DB8;
extern f32 D_L07_001E1EC0[];
void func_L07_00333DB8(u8 *self, u8 *obj, f32 *outA, f32 *outB, f32 range) {
    R_333DB8 *r = (R_333DB8 *)func_L07_00333918(obj);
    B_333DB8 *b = (B_333DB8 *)func_L01_00449020(obj);
    f32 a = 100.0f, c = 100.0f, heading, angle, dist, x, y;
    u16 *p;
    if (!b->target) return;
    r->angle = func_0038D160(*(f32 *)(obj+0x10)-b->xyz[0], *(f32 *)(obj+0x14)-b->xyz[1]);
    heading = func_L03_0032FB70(r->angle);
    if (range > 0.0f) {
        dist = 24.8f - func_0038CF38(self+0x10, b);
        if (dist < range) {
            a = func_0038D160(*(f32 *)(self+0x10)-*(f32 *)(b->target+0x10),
                             *(f32 *)(self+0x14)-*(f32 *)(b->target+0x14));
            dist = (dist / range) * 1.5707964f;
            dist += 1.5707964f;
            angle = func_0038DB00(r->angle, func_0038DAB8(a, dist));
            c = angle < 0.0f ? func_L03_0032FB70(-angle) : 0.0f;
            angle = func_0038DB00(r->angle, func_0038DB00(a, dist));
            a = angle > 0.0f ? func_L03_0032FB70(angle) : 0.0f;
        }
    }
    if (obj[0x21] != 255) {
        for (p = D_L07_0021C020[obj[0x21]];
             obj[0x21] != 255 && obj[0x21] <= D_L07_001DF458_00333DB8 && p; p++) {
            u8 *other;
            R_333DB8 *otherR;
            B_333DB8 *otherB;
            if (((s16 *)p)[-1] < 0 && p != D_L07_0021C020[obj[0x21]]) break;
            other = D_L07_001DF41C_00333DB8 + ((*p & 0x7FFF) << 8);
            if (!other) break;
            if (other == obj || *(s16 *)(other+0xAA) != *(s16 *)(obj+0xAA)) continue;
            otherR = (R_333DB8 *)func_L07_00333918(other);
            otherB = (B_333DB8 *)func_L01_00449020(other);
            if (r->state != otherR->state || b->target != otherB->target) continue;
            dist = func_L03_0032FB70(otherR->angle);
            dist = heading - dist;
            x = func_L03_0032FB70(dist);
            y = func_L03_0032FB70(-dist);
            if (x < a) a = x;
            if (y < c) c = y;
        }
    }
    if (a > 10.0f) {
        if (outA) *outA = 6.2831855f;
        if (outB) *outB = 6.2831855f;
        r->result = r->angle;
    } else {
        if (outA) *outA = a;
        if (outB) *outB = c;
        angle = func_L03_0032FB70(heading - func_L03_0032FB70(D_L07_001E1EC0[6]));
        if (angle < a) r->result = D_L07_001E1EC0[6];
        else r->result = func_0038DAB8(r->angle, (c-a)*0.5f);
    }
}
