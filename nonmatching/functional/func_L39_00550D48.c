/* functional: medium. Projectile collision test for the multiplayer menu (returns 1 on hit): builds a sweep request, queries the world with func_003D3CB0 (falls back to a straight-line distance test), filters hits on the owner/own target/non-player objects, then pulls the projectile back to the hit point, notifies the owner, applies the impact via func_L01_00446A70 and releases the sweep; vector math written component-wise (w kept as the VU0 ops would) and the PAL-only D_L39_0025F740/0x60 hit record fields named by offset; 226 words differ (scheduling/regalloc); the field at 0x4C of the state is an optional ignore target. */
#include "common.h"
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00550D48;

typedef struct {
    V4_00550D48 dir;
    u8 *ignore;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1a;
    f32 f1c;
    s32 f20;
} Req_00550D48;

extern u8 D_L39_0025F740[];
extern V4_00550D48 D_L39_0025F760[];
extern u8 D_L39_0049C890[];
__asm__(".extern D_L39_0049C890, 16");
extern s32 func_L39_00648AE0(void *, s32);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L01_00446720(void);
extern void func_L01_00446A70(void *, void *, s32, void *, f32, void *);
extern u8 *func_L39_0061D7B0(void *);
extern void func_L39_005514A0(u8 *, void *);
extern void func_L39_005510B0(u8 *, void *);
extern void func_L39_005F33E0(s32, s32, u8 *);

s32 func_L39_00550D48(u8 *m, V4_00550D48 *old) {
    u8 *p;
    u8 *owner;
    u8 *settings;
    u8 *t;
    u8 *x;
    u8 *hitobj;
    Req_00550D48 req;
    V4_00550D48 seg;
    V4_00550D48 d;
    V4_00550D48 d2;
    s32 hit;
    s32 pointhit;

    p = *(u8 **)(m + 0x68);
    req.flags = 0x10001;
    req.ignore = m;
    if (func_L39_00648AE0(*(void **)(p + 0x3C), 3) != 0) {
        settings = D_L39_0049C890 + ((s8 *)D_L39_0049C890)[0x1A1] * 0x80;
    } else {
        settings = D_L39_0049C890 + 0x180;
    }
    req.f1c = *(f32 *)(settings + 0x30);
    req.f20 = 1;
    req.dir = *(V4_00550D48 *)p;
    func_0038CF68(&req, &req, 1.0f);
    req.h1a = *(u16 *)(m + 0xAA);
    seg = *(V4_00550D48 *)(m + 0x10);
    req.dir.w = 5600.0f;
    req.b19 = 1;
    req.b18 = 1;
    owner = *(u8 **)(p + 0x3C);
    func_L39_005FFDF8(*(s32 *)(owner + 0x2548));
    owner = *(u8 **)(p + 0x3C);
    hit = func_003D3CB0(old, &seg, 0, *(void **)(owner + 0x2524), p[0x39] ? (void *)&req : 0);
    if (hit == 0) {
        if (*(s16 *)(p + 0x40) != 0) {
            if (*(f32 *)(p + 0x50) < func_L01_0040E548(p + 0x10, &seg)) {
                D_L39_0025F760[0] = *(V4_00550D48 *)(p + 0x20);
                hit = 1;
                *(s32 *)(D_L39_0025F740 + 0x18) = 0;
            }
        }
    }
    if (hit == 0) {
        func_L39_005FFE78();
        return 0;
    }
    hitobj = *(u8 **)(D_L39_0025F740 + 0x18);
    if (hitobj != 0 && hitobj != *(u8 **)(p + 0x4C) && (*(u8 **)(p + 0x3C))[0x1A14] == 0 &&
        func_L01_00446720() == 0) {
        if (*(s32 *)(p + 0x4C) != 0) {
            func_L39_005FFE78();
            return 0;
        }
        t = func_L39_0061D7B0(*(void **)(D_L39_0025F740 + 0x18));
        x = 0;
        if (t != 0) {
            x = t;
            if ((t[3] & 0xF) != 0) x = 0;
        }
        if (x != 0) {
            func_L39_005FFE78();
            return 0;
        }
    }
    d.x = old->x - seg.x;
    d.y = old->y - seg.y;
    d.z = old->z - seg.z;
    d.w = old->w;
    func_0038CF68(&d, &d, 0.25f);
    d2.x = d.x + D_L39_0025F760[0].x;
    d2.y = d.y + D_L39_0025F760[0].y;
    d2.z = d.z + D_L39_0025F760[0].z;
    d2.w = d.w;
    func_0038CF68(&d, &d, -0.5f);
    ((V4_00550D48 *)(m + 0x10))->x = d.x + D_L39_0025F760[0].x;
    ((V4_00550D48 *)(m + 0x10))->y = d.y + D_L39_0025F760[0].y;
    ((V4_00550D48 *)(m + 0x10))->z = d.z + D_L39_0025F760[0].z;
    ((V4_00550D48 *)(m + 0x10))->w = d.w;
    t = func_L39_0061D7B0(*(void **)(D_L39_0025F740 + 0x18));
    x = 0;
    if (t != 0) {
        if ((t[3] & 0xF) == 0) x = t;
    }
    owner = *(u8 **)(p + 0x3C);
    if (owner != 0 && owner[0x1A14] != 0 && p[0x39] != 0 && p[0x3B] == 0) {
        func_L39_005514A0(m, *(void **)(D_L39_0025F740 + 0x18));
    }
    if (*(s32 *)(p + 0x4C) == 0 && (*(u8 **)(p + 0x3C))[0x1A14] == 0 &&
        *(void **)(D_L39_0025F740 + 0x18) != 0) {
        if (func_L39_00648AE0(*(void **)(p + 0x3C), 3) != 0) {
            settings = D_L39_0049C890 + ((s8 *)D_L39_0049C890)[0x1A1] * 0x80;
        } else {
            settings = D_L39_0049C890 + 0x180;
        }
        func_L01_00446A70(*(void **)(D_L39_0025F740 + 0x18), m, 0x10001, D_L39_0025F760,
                          *(f32 *)(settings + 0x30), &req);
    }
    func_L39_005510B0(m, &d2);
    func_L39_005FFE78();
    if (x == 0) {
        func_L39_005F33E0(0, 0, m);
    }
    return 1;
}
