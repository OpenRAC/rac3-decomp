#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003AA9C0 */
void func_L07_00334740(void *);
void func_L07_003AAA50(void *, s32);

void func_L07_003AA9C0(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    *(s32 *)(p + 0x188) &= -0x11;
    *(s32 *)(p + 0x53C) = 0;
    func_L07_00334740(arg0);
    func_L07_003AAA50(arg0, 1);
}
/* localdecomp:end func_L07_003AA9C0 */

/* localdecomp:start func_L07_003AAA08 */
void func_L07_00334800();
void func_L07_003AAA50(void *, s32);

void func_L07_003AAA08(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x2C) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x24))) + 0x24)) * 0.75f);
    func_L07_00334800();
    func_L07_003AAA50(arg0, 2);
}
/* localdecomp:end func_L07_003AAA08 */

/* localdecomp:start func_L07_003AAA50 */
typedef struct {
    u8 pad_000[0x170];
    f32 f170;
    f32 f174;
    f32 f178;
    u8 pad_17C[0xC];
    s32 w188;
    u8 pad_18C[0x3A4];
    s16 h530;
    u8 b532;
    u8 b533;
    s32 w534;
    s32 w538;
} Sub_003AAA50;

void func_L07_003AAA50(void *arg0, s32 state) {
    extern void func_003C3A10(void *, s32, s32, s32);
    extern s32 func_00382468(s32);
    extern void func_L01_004AAC98(s32, s32, void *, s32);
    extern void func_L07_003AAF98(u8 *);
    extern void func_L01_004450F0(void *, s32, s32);
    u8 *obj = arg0;
    Sub_003AAA50 *s = *(Sub_003AAA50 **)(obj + 0x68);

    switch (state) {
    case 1:
        break;
    case 2:
        if (obj[0x43] != 0) {
            func_003C3A10(obj, 0, 0, 0);
        }
        break;
    case 4:
        if (obj[0x43] != 4) {
            func_003C3A10(obj, 4, 0, 4);
        }
        s->f170 = 6.5f * 0.016666668f * 1.2f * 0.02f;
        s->f178 = 6.5f * 0.016666668f * 1.2f;
        s->f174 = 6.5f * 0.016666668f * 1.2f * 0.02f;
        *(u16 *)(obj + 0x34) |= 0x5000;
        break;
    case 6:
        s->w188 &= ~0x10;
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 4);
        }
        break;
    case 7:
        s->w188 &= ~0x10;
        s->f170 = 6.5f * 0.016666668f * 1.2f * 0.02f;
        s->f174 = 6.5f * 0.016666668f * 1.2f * 0.02f;
        s->f178 = 6.5f * 0.016666668f * 1.2f;
        if (obj[0x43] != 4) {
            func_003C3A10(obj, 4, 0, 4);
        }
        break;
    case 8:
        s->w188 |= 0x10;
        s->f170 = 3.5f * 0.016666668f * 1.2f * 0.02f;
        s->f174 = 3.5f * 0.016666668f * 1.2f * 0.02f;
        s->f178 = 3.5f * 0.016666668f * 1.2f;
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 4);
        }
        break;
    case 9:
        s->b532 = 0;
        s->w538 = 0;
        s->w534 = 0;
        if (func_00382468(2) != 0) {
            s->b533 = 0;
            if (obj[0x43] != 5) {
                func_003C3A10(obj, 5, 0, 2);
            }
        } else {
            s->b533 = 1;
            if (obj[0x43] != 9) {
                func_003C3A10(obj, 9, 0, 2);
            }
        }
        break;
    case 10:
        func_L01_004AAC98(2, 0, obj, 0x19BD);
        s->h530 = 0x25;
        if (s->b533 == 0) {
            if (obj[0x43] != 6) {
                func_003C3A10(obj, 6, 0, 2);
            }
        } else {
            if (obj[0x43] != 0xA) {
                func_003C3A10(obj, 0xA, 0, 2);
            }
        }
        break;
    case 11:
        func_L07_003AAF98(obj);
        s->h530 = 0x25;
        if (s->b533 == 0) {
            if (obj[0x43] != 7) {
                func_003C3A10(obj, 7, 0, 2);
            }
        } else {
            if (obj[0x43] != 0xB) {
                func_003C3A10(obj, 0xB, 0, 2);
            }
        }
        break;
    case 12:
        s->w188 |= 0x10;
        if (s->b533 == 0) {
            if (obj[0x43] != 8) {
                func_003C3A10(obj, 8, 0, 2);
            }
        } else {
            if (obj[0x43] != 0xC) {
                func_003C3A10(obj, 0xC, 0, 2);
            }
        }
        break;
    case 13:
        if (obj[0x43] != 0xE) {
            func_003C3A10(obj, 0xE, 0, 2);
        }
        break;
    case 14:
        s->w188 |= 0x10;
        s->f170 = 3.5f * 0.016666668f * 1.2f * 0.02f;
        s->f174 = 3.5f * 0.016666668f * 1.2f * 0.02f;
        s->f178 = 3.5f * 0.016666668f * 1.2f;
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 4);
        }
        break;
    }
    func_L01_004450F0(obj, state, -1);
}
/* localdecomp:end func_L07_003AAA50 */

/* localdecomp:start func_L07_003AADB0 */
extern s32 D_L07_001DEF40;
void func_L07_003AADB0(u8 *obj, f32 speed) {
    extern void func_L03_0032FAF0(void *, void *, f32, f32);
    extern void func_L07_00333DB8(s32, void *, s32, s32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_L07_00332CF0(s32, void *, void *, f32);
    extern void func_L01_0045A7A8(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_L01_0040E570(void *, void *);
    extern f32 func_0038DBA0(f32, f32);
    extern f32 func_0038D160(f32 x, f32 y);
    extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
    vu0_v4 v;
    vu0_v4 old;
    vu0_v4 delta;
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *pos;
    f32 angle;

    func_L03_0032FAF0(&v, s + 0x130, *(f32 *)(s + 0x254), speed);
    if ((D_L07_001DEF40 & 7) == (((s32)obj >> 8) & 7)) {
        func_L07_00333DB8(*(s32 *)(s + 0x240), obj, 0, 0, speed);
        *(f32 *)(s + 0x258) = func_L07_00332CF0(*(s32 *)(s + 0x240), obj, &v,
            func_0038DB00(*(f32 *)(s + 0x250), *(f32 *)(s + 0x254)) * 0.15f);
    }
    pos = obj + 0x10;
    *(vu0_q *)&old = *(vu0_q *)(obj + 0x10);
    func_L01_0045A7A8(obj, &v, *(f32 *)(s + 0x258));
    vec_sub_ba(&delta, obj + 0x10, &old);
    *(f32 *)(s + 0x53C) = func_0038DAB8(*(f32 *)(s + 0x53C), func_0038CE68(&delta, obj + 0xC0) / 0.3f);
    if ((*(s32 *)(s + 0x188) & 0x10) && func_L01_0040E570(&old, pos) > 0.0001f) {
        angle = func_0038D160(*(f32 *)(obj + 0x10) - old.x, *(f32 *)(obj + 0x14) - old.y);
        if (func_0038DBA0(func_0038D160(*(f32 *)(s + 0x130) - *(f32 *)(obj + 0x10),
                                        *(f32 *)(s + 0x134) - *(f32 *)(obj + 0x14)), angle) > 1.5707964f) {
            angle = func_0038DAB8(angle, 3.1415927f);
        }
        func_L01_00448890(obj + 0xF8, s + 0x204, 0, angle, *(f32 *)(s + 0x164), *(f32 *)(s + 0x168), *(f32 *)(s + 0x16C));
    }
}
/* localdecomp:end func_L07_003AADB0 */

/* localdecomp:start func_L07_003AAF98 */
void func_L07_003AAF98(u8 *obj) {
    extern void func_003C2EC0(u8 *, s32, void *);
    extern f32 func_0038CF38(void *a, void *b);
    extern f32 func_0038D160(f32 x, f32 y);
    extern f32 func_0038DB48(f32 a);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_L01_0040E570(void *, void *);
    extern void func_L05_0043F7E0(void *, void *, f32 *, f32 *, void *, void *, void *, f32);
    extern f32 func_003C3D30(void *, s32, s32, f32);
    vu0_v4 matrix[4];
    vu0_v4 pos;
    vu0_v4 delta;
    vu0_v4 result;
    f32 weights[4];
    vu0_v4 choices[2];
    vu0_v4 target;
    u8 *p = *(u8 **)(obj + 0x68);
    f32 distance, angle;
    s32 i, best;

    func_003C2EC0(obj, p[0x533] + 3, matrix);
    *(vu0_q *)&pos = *(vu0_q *)&matrix[3];
    distance = func_0038CF38(&pos, p + 0x130);
    if (distance > 12.0f) {
        distance = 12.0f;
    } else if (distance < 4.0f) {
        distance = 4.0f;
    }
    angle = func_0038D160(*(f32 *)(p + 0x130) - pos.x, *(f32 *)(p + 0x134) - pos.y);
    angle = func_0038DB48(angle - *(f32 *)(p + 0x2A8) - *(f32 *)(obj + 0xF8));
    if (angle > 0.2617994f) {
        angle = 0.2617994f;
    } else if (angle < -0.2617994f) {
        angle = -0.2617994f;
    }
    angle = func_0038DB48(angle + *(f32 *)(p + 0x2A8) + *(f32 *)(obj + 0xF8));
    delta.x = func_0038D098(angle) * (distance + 1.0f);
    delta.y = func_0038D0B0(angle) * (distance + 1.0f);
    delta.z = 0.0f;
    vec_add_ab(&result, &pos, &delta);
    if (func_L01_0040E570(*(u8 **)(p + 0x240) + 0x10, &result) > 615.04f) {
        *(vu0_q *)&target = *(vu0_q *)(*(u8 **)(p + 0x240) + 0x10);
        func_L05_0043F7E0(&choices[0], &choices[1], &weights[0], &weights[1], &pos, &result, &target, 24.8f);
        best = -1;
        for (i = 0; i < 2; i++) {
            if (weights[i] > 0.0f) {
                best = i;
            }
        }
        if (best != -1) {
            *(vu0_q *)&result = *(vu0_q *)&choices[best];
        }
    }
    result.z = func_003C3D30(&result, 0, 0, 0.5f);
    *(vu0_q *)(p + 0x520) = *(vu0_q *)&result;
}
/* localdecomp:end func_L07_003AAF98 */

/* localdecomp:start func_L07_003AB200 */
extern void func_003C2F58(u8 *a, s32 b, f32 *out);
extern f32 func_0038CF38(void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_0038DB48(f32 a);

void func_L07_003AB200(u8 *arg0) {
    u8 *p;
    u8 *q;
    f32 v[3];
    f32 d;

    p = *(u8 **)(arg0 + 0x68);
    func_003C2F58(arg0, p[0x533] + 3, v);
    d = func_0038D160(*(f32 *)(p + 0x520) - v[0], *(f32 *)(p + 0x524) - v[1]);
    d = func_0038DB48((d - *(f32 *)(p + 0x2A8)) - *(f32 *)(arg0 + 0xF8));
    q = p + p[0x533] * 128;
    *(f32 *)(q + 0x3C8) = d;
    d = func_0038CF38(v, p + 0x520);
    d = func_0038D160(d, *(f32 *)(p + 0x528) - v[2]);
    p = p + p[0x533] * 128;
    *(f32 *)(p + 0x3C4) = -d;
}
/* localdecomp:end func_L07_003AB200 */

INCLUDE_ASM("asm/levels", func_L07_003AB2B0);

INCLUDE_ASM("asm/levels", func_L07_003AB4B8);

/* localdecomp:start func_L07_003AB678 */
typedef struct { u8 pad0[0x164]; u8 *texture; } Effects_003AB678;
extern Effects_003AB678 D_L07_0021EC98;
extern void func_003C2F58(u8 *a, s32 b, f32 *out);

void func_L07_003AB678(u8 *object) {
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_003C4C18(void *, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, u32, s32, s32, s32, f32, f32, s32, f32);
    vu0_v4 origin;
    vu0_v4 position;
    vu0_v4 velocity;
    u8 *state = *(u8 **)(object + 0x68);
    f32 speed;
    f32 angle;
    f32 size;
    s32 n;
    s32 i;
    s32 duration;
    u8 kind;
    u8 frame;
    u8 *effect;

    if (*(f32 *)(state + 0x538) == 1.0f) {
        *(vu0_q *)&origin = *(vu0_q *)(state + 0x520);
    } else {
        func_003C2F58(object, state[0x533], (f32 *)&position);
        vec_sub_ba(&origin, state + 0x520, &position);
        func_0038CE20(&origin, &origin, *(f32 *)(state + 0x538));
        vec_add_ab(&origin, &position, &origin);
    }
    n = func_00382498(0, 2);
    for (i = 0; i < n; i++) {
        *(vu0_q *)&position = *(vu0_q *)&origin;
        func_003C4C18(&position, 0.3f);
        speed = func_003824E0(3.0f, 5.5f) * 0.020000001f;
        angle = func_00382538();
        func_00382760(&velocity, speed, angle, func_003824E0(1.0471976f, 3.1415927f));
        kind = 253;
        if (func_00382468(2) == 0) {
            kind = 3;
        }
        frame = func_00382468(256);
        duration = (func_00382498(20, 40) * 5 + 2) / 6;
        size = func_003824E0(0.25f, 0.75f) * 210000.0f;
        effect = func_L01_0046FB40(&position, &velocity, duration, 0x806020, kind, 127, 0, size, size, 0, 0.00392f);
        if (effect) {
            effect[2] = *D_L07_0021EC98.texture;
            frame = effect[8] + 32;
        }
        size *= 0.3f;
        effect = func_L01_0046FB40(&position, &velocity, duration, 0xFFFFFF, kind, 127, 64, size, size, 0, 0.00392f);
        if (effect) {
            effect[8] = frame;
            effect[2] = *D_L07_0021EC98.texture;
        }
    }
}
/* localdecomp:end func_L07_003AB678 */

INCLUDE_ASM("asm/levels", func_L07_003AB918);

/* localdecomp:start func_L07_003ABD18 */
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L07_003AC2D0(void *);
extern void func_L07_003AC500(void *);
void func_L07_003ACA90(void *, s32);
extern void func_L07_003ACD58(void *, f32);
extern void func_L07_003ACF40(u8 *);
extern void func_L07_003AD088(void *);
extern void func_L07_003AD180(void *);
extern void func_L01_0045A9F0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_0045A748(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L07_00331008(u8 *, void *);
extern s32 func_L07_00334408(u8 *);
extern s32 func_L07_003346D8(u8 *);
extern void func_L07_00334588(u8 *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L01_004395E0(void *);
extern void func_L01_00404808(void *, void *);

void func_L07_003ABD18(u8 *self) {
    u8 *p;
    f32 d;

    if (self[0x20] == 0) func_L07_003AC2D0(self);
    func_L07_003AC500(self);
    p = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_0045A9F0(self);
        if (func_0038CB00(p + 0x24E)) func_L07_003ACA90(self, 3);
        break;
    case 3:
        func_L01_0045A9F0(self);
        func_L07_003ACA90(self, 4);
        break;
    case 4:
        func_L01_0045A748(self, *(u8 **)(p + 0x240) + 0x10);
        if (func_L01_0040E570(*(u8 **)(p + 0x240) + 0x10, self + 0x10) < 484.0f) {
            p[0x25E] = 1;
            func_L07_003ACA90(self, 6);
        }
        break;
    case 5:
        func_L01_0045A9F0(self);
        if (func_L01_00454370(self, p + 0x70) & 2) {
            if (p[0x25E] == 0) {
                func_L07_003ACA90(self, 4);
            } else {
                func_L07_003ACA90(self, 6);
            }
        }
        break;
    case 6:
        func_L01_0045A9F0(self);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) {
            if (func_L01_0040E570(self + 0x10, p + 0x130) < 121.0f) {
                func_L07_003ACA90(self, 8);
            } else {
                func_L07_003ACA90(self, 7);
            }
        } else {
            func_L07_003ACA90(self, 13);
        }
        break;
    case 7:
        func_L07_003ACD58(self, 5.0f);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) {
            if (func_L01_0040E570(self + 0x10, p + 0x130) < 64.0f) {
                func_L07_003ACA90(self, 8);
            }
        } else {
            func_L07_003ACA90(self, 6);
        }
        break;
    case 8:
        func_L07_003ACD58(self, 1.5f);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) {
            if (121.0f < func_L01_0040E570(self + 0x10, p + 0x130)) {
                *(s32 *)(p + 0x188) &= ~0x10;
                func_L07_003ACA90(self, 7);
            } else if (func_0038CB00(p + 0x564)) {
                if (func_L01_0040E570(self + 0x10, p + 0x130) < 6.25f) {
                    *(s16 *)(p + 0x24C) = func_L07_00334408(self);
                    if (func_L07_003346D8(self)) func_L07_003ACA90(self, 10);
                }
            }
        } else {
            *(s32 *)(p + 0x188) &= ~0x10;
            func_L07_00334588(self);
            func_L07_003ACA90(self, 6);
        }
        break;
    case 9:
        func_L07_003ACD58(self, 1.5f);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) {
            f32 dist = func_0038CF38(self + 0x10, p + 0x130);
            if (11.0f < dist) {
                *(s32 *)(p + 0x188) &= ~0x10;
                func_L07_00334588(self);
                func_L07_003ACA90(self, 7);
            } else if (dist < 2.5f) {
                func_L07_003ACA90(self, 10);
            }
        } else {
            *(s32 *)(p + 0x188) &= ~0x10;
            func_L07_00334588(self);
            func_L07_003ACA90(self, 6);
        }
        break;
    case 10:
        d = func_L01_004395E0(self);
        func_L01_0045A9F0(self);
        if (10.0f < d) {
            (*(u16 *)(p + 0x564))++;
            if (!(*(u16 *)(p + 0x564) % 2)) func_L07_003AD088(self);
            func_L01_00404808(func_L07_003AD180, self);
        }
        if (13.0f < d && d < 16.0f) func_L07_003ACF40(self);
        if (self[0x60] & 2) {
            func_L07_00334588(self);
            if (p[0x566] == 0) {
                *(s16 *)(p + 0x564) = 50;
                func_L07_003ACA90(self, 6);
            } else {
                func_L07_003ACA90(self, 12);
            }
        }
        break;
    case 11:
        (*(u16 *)(p + 0x564))++;
        if (!(*(u16 *)(p + 0x564) % 2)) func_L07_003AD088(self);
        func_L01_00404808(func_L07_003AD180, self);
        func_L01_0045A9F0(self);
        func_L07_003ACF40(self);
        if (self[0x60] & 2) {
            func_L07_00334588(self);
            if (p[0x566] != 0) {
                if (self[0x43] != 8) func_003C3A10(self, 8, 0, 10);
                func_L07_003ACA90(self, 12);
            } else {
                *(s16 *)(p + 0x564) = 50;
                if (self[0x43] != 3) func_003C3A10(self, 3, 0, 10);
                func_L01_004450F0(self, 6, -1);
            }
        }
        break;
    case 12:
        func_L07_003ACD58(self, 4.0f);
        if (self[0x60] & 2) {
            *(s32 *)(p + 0x188) &= ~0x10;
            func_L07_003ACA90(self, 6);
        }
        break;
    case 13:
        func_L07_003ACD58(self, 8.0f);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) func_L07_003ACA90(self, 6);
        break;
    }
}
/* localdecomp:end func_L07_003ABD18 */
