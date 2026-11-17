/* NTSC-U draft (Claude wave C4): C of func_L18_003230E8, the NTSC-U twin of func_L18_00323760, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 142 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L18_003230E8", whose code is not the PAL one).
 * Worker's note: flags + 142 diff (register allocation and the order of the request-struct stores): needs -mvu0-use-vf0-vf2 and @ps2as (the PAL file src/levels/shared/L18_00322F80.c has '-O2 -G8 -fopt-stack -mno-check-zero-division' only: VU0 macro ops vec_sub_ab/vec_add_ab, ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L18_003230E8 */
typedef struct {
    u8 pad_00[0x10];
    vu0_v4 pos10;
    vu0_v4 vec20;
    u8 pad_30[8];
    f32 f38;
    u8 pad_3C[8];
    f32 f44;
    u8 pad_48[0x14];
    f32 f5C;
    s32 w60;
} Sub_3230E8;

typedef struct {
    vu0_v4 pos;
    vu0_v4 vel;
    vu0_v4 diff;
    f32 dir[4];
    u8 *owner;
    s32 flags;
    u8 b48;
    u8 b49;
    u16 h4A;
    f32 f4C;
    s32 w50;
    u8 pad_54[4];
    s32 w58;
} Req_3230E8;

typedef struct {
    u8 pad_00[0x18];
    u8 *w18;
    s32 w1C;
} Hit_3230E8;

extern f32 D_001DC7E4_sda;
__asm__(".extern D_001DC7E4_sda, 4");
extern f32 D_001DC7E8_sda;
__asm__(".extern D_001DC7E8_sda, 4");
extern f32 D_001DC7EC_sda;
__asm__(".extern D_001DC7EC_sda, 4");
extern f32 D_001DC7F0_sda;
__asm__(".extern D_001DC7F0_sda, 4");
extern Hit_3230E8 D_L18_001EAB00;
extern u8 D_L18_001EAB20[];

extern void func_L01_004026A0(void *, void *);
extern void func_L18_00323498();
extern f32 func_00388A28(f32, f32);
extern f32 func_L18_00454598(void *, f32, f32, f32, f32, f32);
extern f32 func_003887A0(void *);
extern f32 func_00388770(void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L18_00322EB0(void *, void *);
extern void func_00388880(void *, void *, f32);
extern s32 func_L18_00322B10(s32, void *, void *, s32, u8 *, void *);
extern void func_L01_0040C260(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L18_00322918(u8 *, void *, void *, f32, f32);
extern void func_003BD360(void *);
extern s32 func_00388398(void *);

void func_L18_003230E8(u8 *obj) {
    Req_3230E8 r;
    vu0_v4 w;
    Sub_3230E8 *s;
    f32 f20;
    f32 f21;
    f32 e;
    f32 t;
    u8 *pos;
    u8 *hp;
    f32 sc;
    u8 *o;

    if (obj == 0) {
        return;
    }
    s = *(Sub_3230E8 **)(obj + 0x68);
    if (s == 0) {
        return;
    }
    f21 = 6.0f;
    f20 = 0.1f;
    *(f32 *)(obj + 0x2C) = *(f32 *)(obj + 0x2C) + (*(f32 *)(*(u8 **)(obj + 0x24) + 0x24) - *(f32 *)(obj + 0x2C)) * 0.05f;
    s->f38 = s->f38 + (D_001DC7E4_sda - s->f38) * f20;
    func_L01_004026A0(func_L18_00323498, obj);
    vec_sub_ab(&r.diff, &s->pos10, obj + 0x10);
    e = func_00388A28(r.diff.x, r.diff.y);
    *(f32 *)(obj + 0xF8) = func_L18_00454598((u8 *)s + 0x3C, *(f32 *)(obj + 0xF8), e, D_001DC7EC_sda, D_001DC7E8_sda, D_001DC7F0_sda);
    t = func_00388A28(func_003887A0(&r.diff), r.diff.z);
    *(f32 *)(obj + 0xF4) = func_L18_00454598((u8 *)s + 0x40, *(f32 *)(obj + 0xF4), -t, D_001DC7EC_sda, D_001DC7E8_sda, D_001DC7F0_sda);
    vec_sub_ab(&r.diff, &s->pos10, &s->vec20);
    if (func_00388770(&r.diff) < f21) {
        s->f44 = s->f44 * (func_00388770(&r.diff) / f21);
    } else {
        s->f44 = s->f44 + f20;
    }
    func_0037E4B8(&r.vel, s->f38, *(f32 *)(obj + 0xF8), -*(f32 *)(obj + 0xF4));
    if (obj[0x31] != 0) {
        func_L18_00322EB0(obj, &r.vel);
    }
    *(vu0_q *)&r.pos = *(vu0_q *)(obj + 0x10);
    pos = obj + 0x10;
    vec_add_ab(&s->vec20, &s->vec20, &r.vel);
    *(vu0_q *)(obj + 0x10) = *(vu0_q *)&s->vec20;
    if (*(f32 *)(obj + 0x10) < 0.0f || *(f32 *)(obj + 0x14) < 0.0f || *(f32 *)(obj + 0x18) < 0.0f) {
        func_003BD360(obj);
        return;
    }
    r.owner = obj;
    r.flags = 0x01030001;
    *(vu0_q *)&r.dir = *(vu0_q *)&r.vel;
    r.w50 = 1;
    r.f4C = s->f5C;
    func_00388880(r.dir, r.dir, 1.0f);
    r.dir[2] = 1.0f;
    r.dir[3] = 5627.9248f;
    r.b49 = 3;
    r.h4A = *(u16 *)(obj + 0xAA);
    r.b48 = 3;
    r.w58 = s->w60;
    if (func_L18_00322B10(-1, &r, pos, 0, *(u8 **)((u8 *)s + 0x30), r.dir) != 0) {
        if ((D_L18_001EAB00.w18 == 0 || D_L18_001EAB00.w18 == *(u8 **)((u8 *)s + 0x30) || *(s16 *)(D_L18_001EAB00.w18 + 0xAA) == 0x15A5) && D_L18_001EAB00.w1C <= 0) {
            if (func_00388398((u8 *)s + 0x34) != 0) {
                func_003BD360(obj);
            }
            return;
        }
        hp = D_L18_001EAB20;
        *(vu0_q *)(obj + 0x10) = *(vu0_q *)hp;
        func_0037E4B8(&r.vel, s->f38, *(f32 *)(obj + 0xF8), -*(f32 *)(obj + 0xF4));
        func_L01_0040C260(&w, &r.vel, hp + 0x20);
        func_00388830(&w, &w, 0.033333335f);
        sc = 1.5f;
        o = *(u8 **)(hp - 8);
        if (o != 0 && o != *(u8 **)((u8 *)s + 0x30) && *(s16 *)(o + 0xAA) != 0x15A5) {
            sc = 2.5f;
        }
        func_L18_00322918(*(u8 **)((u8 *)s + 0x30), &w, pos, sc, s->f5C);
        func_003BD360(obj);
        return;
    }
    if (func_00388398((u8 *)s + 0x34) != 0) {
        func_003BD360(obj);
    }
}
/* localdecomp:end func_L18_003230E8 */
