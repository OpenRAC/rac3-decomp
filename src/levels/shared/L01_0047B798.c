#include "common.h"

typedef struct {
    s32 v[3];
} Ids3;
typedef struct { u8 b[16]; } V16_3DF9E0;

/* localdecomp:start func_L01_0047B798 */
extern Ids3 D_L01_001D80D8;
extern void func_L01_00517190(s32 a0, s32 a1);
extern void func_L01_00516AA0(s32 a0, s32 a1, s32 a2);
void func_L01_0047B798(s32 a0, s32 a1) {
    Ids3 t;
    t = D_L01_001D80D8;
    func_L01_00517190(t.v[a1], a0);
    if (a0 == 0) {
        func_L01_00516AA0(t.v[a1], 1, 0);
    } else {
        func_L01_00516AA0(t.v[a1], 1, 1);
    }
}
/* localdecomp:end func_L01_0047B798 */

/* localdecomp:start func_L01_0047B820 */
__asm__(".extern D_L01_001D80E4, 4");
extern f32 D_L01_001D80E4;
extern char D_L01_001E0500[] __attribute__((section(".sdata")));
extern char D_L01_001D80E8[];
extern char D_L01_001D80F0[];
extern char D_L01_001D80F8[];
extern s32 func_0011B2E8(char *, char *, ...);

void func_L01_0047B820(s32 a, s32 b) {
    if (b == 0) {
        if (a == 0) {
            func_0011B2E8(D_L01_001E0500, D_L01_001D80E8);
        } else {
            func_0011B2E8(D_L01_001E0500, D_L01_001D80F0, a);
        }
        D_L01_001D80E4 = 0.0f;
        return;
    }
    if ((f32)a < (f32)b * 0.15f) {
        D_L01_001D80E4 = D_L01_001D80E4 + 0.060000002f;
        if (2.0f <= D_L01_001D80E4) {
            D_L01_001D80E4 = D_L01_001D80E4 - 2.0f;
        }
    } else {
        if (1.0f < D_L01_001D80E4) {
            D_L01_001D80E4 = 2.0f - D_L01_001D80E4;
        }
        D_L01_001D80E4 = D_L01_001D80E4 * 0.94f;
    }
    func_0011B2E8(D_L01_001E0500, D_L01_001D80F8, a, b);
}
/* localdecomp:end func_L01_0047B820 */

/* localdecomp:start func_L01_0047B948 */
__asm__(".extern D_L01_001D80CD, 1");
extern u8 D_L01_001D80CD;
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_0047C368(s32);
extern s32 func_L01_00516010(s32);
s32 func_L01_0047B948(void) {
    if (D_L01_001D80CD != 0) {
        func_L01_00516AA0(0x20000, 1, 0);
        return func_L01_00516010(func_L01_0047C368(0));
    }
    return 0;
}
/* localdecomp:end func_L01_0047B948 */

/* localdecomp:start func_L01_0047B990 */
s32 func_L01_0047C368(s32);
s32 func_L01_00516050(s32);

void func_L01_0047B990(void) {
    func_L01_00516050(func_L01_0047C368(0));
}
/* localdecomp:end func_L01_0047B990 */

/* localdecomp:start func_L01_0047B9B8 */
typedef struct {
    s32 v[10];
} Ids10_0047B9B8;
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[0x66];
    s32 f68;
    u8 pad6C[0xF0 - 0x6C];
} Ent_0047B9B8;
extern u8 D_001425C0[];
extern s32 D_00142DE0[];
extern Ent_0047B9B8 D_L01_002C5600[];
__asm__(".extern D_L01_001D80D0, 4");
extern f32 D_L01_001D80D0;
extern Ids10_0047B9B8 D_L01_001D8148;
extern s32 func_L01_00418DE0(s32, s32);
extern void func_L01_00478450(s32, s32, s32, f32, f32);
extern s32 func_L01_00516FD8(s32, s32);
extern void func_L01_00516D60(s32, s32);

void func_L01_0047B9B8(s32 a0) {
    Ids10_0047B9B8 t;
    s32 a;
    s32 b;
    u8 *p;
    Ent_0047B9B8 *e;
    Ent_0047B9B8 *e2;

    p = D_001425C0 + a0;
    e = D_L01_002C5600 + *p;
    if (e->b0 != 0) {
        b = e->b1;
        if (e->f68 > 0) {
            a = 0;
            if (b != 0) {
                func_L01_00418DE0(a0, b - 1);
                a = D_L01_002C5600[*p].f68;
                func_L01_00418DE0(a0, b);
            }
            e2 = D_L01_002C5600 + *p;
            func_L01_00478450(0x20007, (D_00142DE0[a0] >> 5) - a, e2->f68 - a, D_L01_001D80D0, 0.009f);
        } else {
            func_L01_00478450(0x20007, 1, 1, D_L01_001D80D0, 0.009f);
        }
        t = D_L01_001D8148;
        func_L01_00516FD8(0x2000B, t.v[b]);
        func_L01_00516D60(0x2000B, 1);
    } else {
        func_L01_00478450(0x20007, 0, 1, D_L01_001D80D0, 0.009f);
        func_L01_00516D60(0x2000B, 0);
    }
}
/* localdecomp:end func_L01_0047B9B8 */

/* localdecomp:start func_L01_0047BB98 */
extern void func_L01_005169C8(s32, f32);

void func_L01_0047BB98(void) {
    func_L01_005169C8(0x20001, 0.07f);
    func_L01_005169C8(0x20002, 0.07f);
}
/* localdecomp:end func_L01_0047BB98 */

/* localdecomp:start func_L01_0047BBE0 */
__asm__(".extern D_L01_001D80CD, 1");
__asm__(".extern D_L01_001D8170, 4");
__asm__(".extern D_L01_001D8174, 4");
__asm__(".extern D_L01_001DC1B0, 4");
extern u8 D_L01_001D80CD;
extern f32 D_L01_001D8170;
extern f32 D_L01_001D8174;
extern s32 D_L01_001DC1B0;
extern s32 D_L01_001E15E0[];
extern char D_L01_001E0500[] __attribute__((section(".sdata")));
typedef struct Obj_0047BBE0 Obj_0047BBE0;
typedef struct { u8 pad[16]; s32 (*test)(Obj_0047BBE0 *, s32); } Vt_0047BBE0;
struct Obj_0047BBE0 { u8 pad[8]; Vt_0047BBE0 *vt; u8 padC[0x3E]; s16 f4A; };
extern void func_L01_0047B798(s32, s32);
extern void func_L01_00516468_0047BBE0(s32);
extern void func_0038CB78(void *, s32, s32);
extern s32 func_003B5060(s32);
extern s32 func_003E5090(s32);
extern s32 func_003E51F8(s32);
extern s32 func_003E5360(s32);
extern void func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E7AC8(s32, s32);
extern s32 func_00392A18(void);
extern void func_L01_00517448(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern void func_L01_005169C8(s32, f32);
extern s32 func_L01_00516FD8(s32, s32);
extern void func_L01_00516B90(s32, s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 *func_003E6C08(void);
extern void *func_003E6DE8(s32 *);
extern Obj_0047BBE0 *func_003E6378(void *, s32);
extern void func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E8630(s32, s32);
extern void func_003E8348(s32, s32);
extern s32 func_003E6FF0(s32, s32);

void func_L01_0047BBE0(s32 a0) {
    f32 x0 = 0.074f;
    f32 x1 = 0.412f;
    f32 y1;
    f32 x2, y2, one, x3, y3;
    s32 *root;
    Obj_0047BBE0 *o;
    Obj_0047BBE0 *t;

    D_L01_001D80CD = 1;
    func_L01_00516468_0047BBE0(1);
    func_0038CB78(D_L01_001E0500, 0, 0x18);
    y1 = 0.422f;
    x2 = 0.8f;
    func_003B5060(0x20000);
    y2 = 0.78f;
    one = 1.0f;
    x3 = 0.040599998f;
    func_003E5090(0x20001);
    y3 = 0.04996923f;
    func_003E5090(0x20002);
    func_003E5090(0x20008);
    func_003E5090(0x20009);
    func_003E51F8(0x20004);
    func_003E51F8(0x20005);
    func_003E51F8(0x20006);
    func_003E5360(0x20003);
    func_003E5090(0x20007);
    func_003E8FE8(0x2000B, 0, 0x8066CCFF, 0.28f, 0.123f, 0.75f, 0.75f);
    func_003E7AC8(0x2000B, 1);
    func_L01_00517448(0x20002, func_00392A18(), 0x1F);
    func_L01_00517448(0x20001, func_00392A18(), 0x20);
    func_L01_00517448(0x20007, func_00392A18(), 0x6F);
    func_L01_00517448(0x20008, func_00392A18(), 0x4E);
    func_L01_00517448(0x20009, func_00392A18(), 0x4F);
    func_L01_00516470(0x20004, 0.0745f, 0.086666f);
    func_L01_00516470(0x20005, x0, 0.189f);
    func_L01_00516470(0x20006, x0, 0.258f);
    func_L01_00516470(0x20009, x1, y1);
    func_L01_00516470(0x20008, x1, y1);
    func_L01_00516470(0x20003, D_L01_001D8170, D_L01_001D8174);
    func_L01_00516470(0x20007, 0.4940f, 0.495f);
    func_L01_00517538(0x20009, x2, y2);
    func_L01_00517538(0x20008, x2, y2);
    func_L01_00517538(0x20001, one, one);
    func_L01_00517538(0x20002, one, one);
    func_L01_00517538(0x20004, 0.057749998f, 0.07107692f);
    func_L01_00517538(0x20005, x3, y3);
    func_L01_00517538(0x20006, x3, y3);
    func_L01_00517538(0x20003, one, one);
    func_L01_005170B8(0x20001, 0x331465B7);
    func_L01_005170B8(0x20002, 0x332299DE);
    func_L01_005170B8(0x20004, 0x706EC8FF);
    func_L01_005170B8(0x20003, 0x7075D5FF);
    func_L01_005170B8(0x20007, 0x706EC8FF);
    func_L01_005170B8(0x20009, 0x331465B7);
    func_L01_005170B8(0x20008, 0x332299DE);
    func_L01_005170B8(0x20005, 0x506EC8FF);
    func_L01_005170B8(0x20006, 0x306EC8FF);
    func_L01_005169C8(0x20007, 0.0f);
    func_L01_00516FD8(0x20003, (s32)D_L01_001E0500);
    func_L01_00516B90(0x20003, 3, 1);
    func_L01_00516AA0(0x20003, 0x40, 1);
    func_L01_0047B798(0, 0);
    func_L01_0047B798(0, 1);
    func_L01_0047B798(0, 2);
    root = D_L01_001E15E0;
    if (root[1] == 0) {
        root = func_003E6C08();
    }
    o = func_003E6378(func_003E6DE8(root), 0x20004);
    t = (o != 0 && o->vt->test(o, D_L01_001DC1B0)) ? o : 0;
    t->f4A = 0;
    func_003E9138(0x2000A, 0x332299DE, 0, 0.074f, 0.224f, 0.05f, 0.005f);
    func_003E8630(0x20000, 0x20001);
    func_003E8630(0x20000, 0x20002);
    func_003E8630(0x20000, 0x20009);
    func_003E8630(0x20000, 0x20008);
    func_003E8630(0x20000, 0x2000A);
    func_003E8630(0x20000, 0x20004);
    func_003E8630(0x20000, 0x20005);
    func_003E8630(0x20000, 0x20006);
    func_003E8630(0x20000, 0x20003);
    func_003E8630(0x20000, 0x20007);
    func_003E8630(0x20000, 0x2000B);
    func_003E8348(6, 0x20000);
    func_003E6FF0(a0, 1);
    func_L01_00516468_0047BBE0(0);
}
/* localdecomp:end func_L01_0047BBE0 */

/* localdecomp:start func_L01_0047C220 */
extern s32 func_L01_0047C368(s32);
extern s32 func_L01_00516000(s32);
extern void func_L01_00516AA0(s32, s32, s32);
__asm__(".extern D_L01_001D80C8, 4");
__asm__(".extern D_L01_001D80CC, 1");
extern s32 D_L01_001D80C8;
extern u8 D_L01_001D80CC;

void func_L01_0047C220(s32 a) {
    if (func_L01_00516000(func_L01_0047C368(0)) == 1) {
        D_L01_001D80C8 = a;
        D_L01_001D80CC = 0;
        func_L01_00516AA0(0x20000, 1, a != 0);
    }
}
/* localdecomp:end func_L01_0047C220 */

/* localdecomp:start func_L01_0047C278 */
__asm__(".extern D_L01_001D80C8, 4");
__asm__(".extern D_L01_001D80CC, 1");
__asm__(".extern D_L01_001D80E4, 4");
extern s32 D_L01_001D80C8;
extern u8 D_L01_001D80CC;
extern f32 D_L01_001D80E4;
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_0047BB98(void);


void func_L01_0047C278(void) {
    f32 x;
    f32 t;
    if (D_L01_001D80C8 != 0) {
        x = D_L01_001D80E4;
        if (1.0f < x) {
            t = 2.0f - x;
        } else {
            t = x;
        }
        t = func_0038D098(t * 3.1415927f);
        func_L01_005170B8(0x20003, func_0038DBD8(0x8066CCFF, 0x60202080, (1.0f - t) * 0.5f));
        D_L01_001D80C8--;
    } else {
        ((s32 (*)(s32, s32, s32))func_L01_00516AA0)(0x20000, 1, 0);
        D_L01_001D80CC = 1;
    }
    func_L01_0047BB98();
}
/* localdecomp:end func_L01_0047C278 */

/* localdecomp:start func_L01_0047C348 */
__asm__(".extern D_L01_001D80CD, 1");
extern u8 D_L01_001D80CD;
extern s32 func_L01_00517918();

void func_L01_0047C348(void) {
    D_L01_001D80CD = 0;
    func_L01_00517918(6);
}
/* localdecomp:end func_L01_0047C348 */

/* localdecomp:start func_L01_0047C368 */
extern s32 func_L01_0047C368(s32);
extern void func_L01_0047C278();

extern void func_L01_0047BBE0(s32);
extern void func_L01_0047C348(void);
extern void func_L01_0047C278(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
__asm__(".extern D_L01_001E0498, 4");
__asm__(".extern D_L01_001E04B8, 4");
__asm__(".extern D_L01_001E04D8, 4");
__asm__(".extern D_L01_001E04F8, 4");
__asm__(".extern D_L01_001E0480, 8");
__asm__(".extern D_L01_001E04A0, 8");
__asm__(".extern D_L01_001E04C0, 8");
__asm__(".extern D_L01_001E04E0, 8");
extern s32 D_L01_001E0498;
extern s32 D_L01_001E04B8;
extern s32 D_L01_001E04D8;
extern s32 D_L01_001E04F8;
extern s32 D_L01_001E0480[2];
extern s32 D_L01_001E04A0[2];
extern s32 D_L01_001E04C0[2];
extern s32 D_L01_001E04E0[2];
extern V16_3DF9E0 D_L01_001D8178[];
s32 func_L01_0047C368(s32 idx) {
    V16_3DF9E0 v;
    if (D_L01_001E0498 == 0) {
        func_003E6FA0(D_L01_001E0480, (s32)func_L01_0047BBE0, (s32)func_L01_0047C348, (s32)func_L01_0047C278, 0, 0);
        D_L01_001E0498 = 1;
    }
    if (D_L01_001E04B8 == 0) {
        func_003E6FA0(D_L01_001E04A0, (s32)func_L01_0047BBE0, (s32)func_L01_0047C348, (s32)func_L01_0047C278, 0, 0);
        D_L01_001E04B8 = 1;
    }
    if (D_L01_001E04D8 == 0) {
        func_003E6FA0(D_L01_001E04C0, (s32)func_L01_0047BBE0, (s32)func_L01_0047C348, (s32)func_L01_0047C278, 0, 0);
        D_L01_001E04D8 = 1;
    }
    if (D_L01_001E04F8 == 0) {
        func_003E6FA0(D_L01_001E04E0, (s32)func_L01_0047BBE0, (s32)func_L01_0047C348, (s32)func_L01_0047C278, 0, 0);
        D_L01_001E04F8 = 1;
    }
    v = D_L01_001D8178[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L01_0047C368 */

/* localdecomp:start func_L01_0047C4A8 */
__asm__(".extern D_L01_001E0518, 8");
__asm__(".extern D_L01_001E0530, 4");
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern void func_L01_0047C4F8_0047C4A8(void);
extern void func_L01_0047C518_0047C4A8(void);
extern void func_L01_0047C538_0047C4A8(void);
extern s32 D_L01_001E0518[2];
extern s32 D_L01_001E0530;
s32 *func_L01_0047C4A8(void) {
    if (D_L01_001E0530 == 0) {
        func_003E6FA0(D_L01_001E0518, (s32)func_L01_0047C4F8_0047C4A8, (s32)func_L01_0047C518_0047C4A8, (s32)func_L01_0047C538_0047C4A8, 0, 0);
        D_L01_001E0530 = 1;
    }
    return D_L01_001E0518;
}
/* localdecomp:end func_L01_0047C4A8 */

/* localdecomp:start func_L01_0047C4F8 */
extern void func_L01_0047C728_0047C4F8();

void func_L01_0047C4F8(void) {
    func_L01_0047C728_0047C4F8();
}
/* localdecomp:end func_L01_0047C4F8 */

/* localdecomp:start func_L01_0047C518 */
extern void func_L01_0047C970_0047C518();

void func_L01_0047C518(void) {
    func_L01_0047C970_0047C518();
}
/* localdecomp:end func_L01_0047C518 */

/* localdecomp:start func_L01_0047C538 */
__asm__(".extern D_L01_001D8188_0047C538, 8");
__asm__(".extern D_L01_001D8198_0047C538, 8");
__asm__(".extern D_L01_001D81A8_0047C538, 8");
__asm__(".extern D_L01_001D81B8_0047C538, 4");
extern s32 D_L01_001D8188_0047C538[2];
extern s32 D_L01_001D8198_0047C538[2];
extern f32 D_L01_001D81A8_0047C538[2];
extern s32 D_L01_001D81B8_0047C538;
extern s32 func_0038CAD0(void *);
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00517190(s32 a0, s32 a1);
extern s32 func_L01_005170B8(s32, s32);
extern void func_L01_005169C8(s32, f32);
extern void func_L01_00517F50(s32, s32, s32);

void func_L01_0047C538(void) {
    s32 i;
    s32 id;
    s32 col;
    f32 t;

    for (i = 0; i < 4; i++) {
        id = i * 5 + 0x550001;
        if (func_0038CAD0(&D_L01_001D8188_0047C538[i]) != 0) {
            func_L01_00516D60(id, 0);
            func_L01_00517190(id + 4, 0);
        } else {
            func_L01_00516D60(id, 1);
            t = (f32)D_L01_001D8188_0047C538[i] / (f32)(D_L01_001D81B8_0047C538 - 1);
            col = (s32)(t * 51.0f) << 24;
            func_L01_005170B8(id + 1, col | 0x1465B7);
            func_L01_005170B8(id + 2, col | 0x2299DE);
            func_L01_005170B8(id + 3, ((s32)(t * 128.0f) << 24) | 0x66CCFF);
            func_L01_005169C8(id + 3, 1.0f - D_L01_001D81A8_0047C538[i]);
            if (D_L01_001D8198_0047C538[i] != -1) {
                func_L01_00516D60(id + 4, 1);
                func_L01_00517F50(id + 4, 0xED59, D_L01_001D8198_0047C538[i]);
                func_L01_005170B8(id + 4, ((s32)(t * 112.0f) << 24) | 0x6EC8FF);
            } else {
                func_L01_00516D60(id + 4, 0);
            }
        }
    }
}
/* localdecomp:end func_L01_0047C538 */

/* localdecomp:start func_L01_0047C728 */
__asm__(".extern D_L01_001D81BC, 4");
__asm__(".extern D_L01_001D81C0, 4");
__asm__(".extern D_L01_001D81C4, 4");
__asm__(".extern D_L01_001D81C8, 4");
extern f32 D_L01_001D81BC;
extern f32 D_L01_001D81C0;
extern f32 D_L01_001D81C4;
extern f32 D_L01_001D81C8;
extern void func_L01_00518D40_0047C728(s32);
extern void func_L01_0047C800(s32, f32, f32, f32);
extern void func_003E8630(s32, s32);
extern void func_003E8348(s32, s32);

void func_L01_0047C728(void) {
    s32 i;
    s32 p = 0x550001;
    func_L01_00518D40_0047C728(0x550000);
    for (i = 0; i < 4; i++) {
        f32 t = (f32)(i >> 1);
        f32 x = D_L01_001D81BC + t * D_L01_001D81C4;
        f32 y = D_L01_001D81C0 + t * D_L01_001D81C8;
        if (i & 1) {
            func_L01_0047C800(p, 1.0f - x, y, -1.0f);
        } else {
            func_L01_0047C800(p, x, y, 1.0f);
        }
        func_003E8630(0x550000, p);
        p += 5;
    }
    func_003E8348(12, 0x550000);
}
/* localdecomp:end func_L01_0047C728 */

/* localdecomp:start func_L01_0047C800 */
__asm__(".extern D_L01_001D81CC, 4");
__asm__(".extern D_L01_001D81D0, 4");
__asm__(".extern D_L01_001D81D4, 4");
extern f32 D_L01_001D81CC;
extern f32 D_L01_001D81D0;
extern f32 D_L01_001D81D4;
extern void func_L01_00518D40_0047C800(s32);
extern void func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E8A58(s32, s32, s32, s32, s32);

void func_L01_0047C800(s32 p, f32 x, f32 y, f32 z) {
    func_L01_00518D40_0047C800(p);
    func_003E8EF0(p + 1, 0x71, 0x331465B7, x, y, -z, -1.0f, 0.0f);
    func_003E8EF0(p + 2, 0x70, 0x332299DE, x, y, -z, -1.0f, 0.0f);
    func_003E8EF0(p + 3, 0x72, 0x8066CCFF, x, y, -z, -1.0f, 0.0f);
    func_003E9138(p + 4, 0x706EC8FF, 0, x + D_L01_001D81D0 * z, y + D_L01_001D81D4 * z, D_L01_001D81CC, D_L01_001D81CC * 1.2307693f);
    func_003E8A58(p, p + 1, p + 2, p + 3, p + 4);
}
/* localdecomp:end func_L01_0047C800 */

/* localdecomp:start func_L01_0047C970 */
extern s32 func_L01_00517918();
void func_L01_0047C970(void) {
    ((void (*)(s32))func_L01_00517918)(12);
}
/* localdecomp:end func_L01_0047C970 */

/* localdecomp:start func_L01_0047C990 */
__asm__(".extern D_L01_001D8188, 8");
__asm__(".extern D_L01_001D8198, 8");
__asm__(".extern D_L01_001D81A8, 8");
__asm__(".extern D_L01_001D81B8, 4");
extern s32 D_L01_001D8188[2];
extern s32 D_L01_001D8198[2];
extern f32 D_L01_001D81A8[2];
extern s32 D_L01_001D81B8;

void func_L01_0047C990(s32 a0, s32 idx, u8 flag, f32 f) {
    if (f > 1.0f) {
        f = 1.0f;
    }
    if (f < 0.0f) {
        f = 0.0f;
    }
    D_L01_001D8188[idx] += 2;
    D_L01_001D81A8[idx] = f;
    if (flag) {
        if (D_L01_001D81B8 >> 1 < D_L01_001D8188[idx]) {
            D_L01_001D8188[idx] = D_L01_001D81B8 >> 1;
        }
    } else {
        if (D_L01_001D81B8 < D_L01_001D8188[idx]) {
            D_L01_001D8188[idx] = D_L01_001D81B8;
        }
    }
    D_L01_001D8198[idx] = a0;
}
/* localdecomp:end func_L01_0047C990 */

LINKER_REMNANT("asm/levels", func_L01_0047CA30);
