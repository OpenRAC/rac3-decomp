/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_0032DE00, the NTSC-U twin of func_L01_0032E2D0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L01_0032C6B8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0032DE00 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_0032DE00;
typedef struct { Vec_0032DE00 rows[3]; } Mat_0032DE00;
typedef struct {
    Vec_0032DE00 from, to, velocity;
    u8 *hit;
    s32 *info;
    s32 kind;
    f32 radius, step, scale;
    s32 zero48, zero4c, enabled;
    u8 *surface;
    s32 enabled58;
    f32 skin;
} Query_0032DE00;
__asm__(".extern D_L01_001DCE8C, 16");
extern s32 D_L01_001DCE8C;
extern f32 D_L01_001DCEF0, D_L01_001DCEF8;
extern void *D_L01_001E1110;
extern void *D_L01_001E1118[];
extern u8 D_L01_00278A10[];
extern u8 *D_L01_001DB02C[];
extern u8 *D_L01_002783D0[];
extern f32 D_L01_00278560[][3];
extern u8 D_001A4BE0[];
extern s32 D_L01_001D673C[], D_L01_001D6740[];
extern u8 *D_L01_001EEB00[];
extern Vec_0032DE00 D_001A4C60;
extern s32 D_001A71A4[];
extern void func_L01_004C41E8(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388978(f32), func_00388960(f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003890D8(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern void func_L01_004C4AD8(s32, void *, s32);
extern void func_L01_004C4190(void *, void *, f32);
extern s32 func_L01_004C42C0(Query_0032DE00 *, s32);
extern s32 func_L01_004C7670(void);
extern void func_L01_004C6EC8(void *, void *);
extern s32 func_L01_004C73B0(void *);
extern void func_L01_004C2BF8(void *, void *, s32, f32, f32, f32, f32);
extern u8 *func_L01_00301508(void *, s32, f32, f32);
extern s32 func_L01_004C7180(void *, void *);
extern void func_L01_0032F658(void);
extern void func_L01_004A72A8(s32, s32, void *, s32);
extern void func_L01_00441E00(void *, s32, s32, s32, s32);
extern void func_L01_004C4AB8(s32);
extern void func_00388E78(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern f32 func_L01_00436500(void *);
extern void func_L01_0032ECC0(void *);
extern s32 func_L01_004C4A18(void *, s32, f32, f32, f32);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_003883C8(void *);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_0032EEE8(void *), func_L01_0032EFE8(void *);
extern s32 func_L01_004C4548(void *, s32);
extern void func_L01_0032EA90(void *), func_L01_0032EB28(void *);
extern void func_L01_004488B8(void *, void *, s32, f32, f32);
extern void func_L01_004C45F8(s32);
extern void func_L01_004C71F8(void *, s32);
extern void func_003BD360(void *);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_00407010(void *, void *, void *, void *, void *, s32, s32, s32, u32, u32);
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern s32 func_L01_0032E950(void *, void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_L01_0032F208(void *);
extern void func_L01_0040BB20(void *);
extern s32 func_00388398(void *);
extern void func_L01_0032EBE0(void *), func_L01_0032EC40(void *);
extern void func_L01_004026A0(void (*)(void *), void *);
extern void func_L01_0032F678(void *);

static __inline__ void add_0032DE00(Vec_0032DE00 *d, const Vec_0032DE00 *a, const Vec_0032DE00 *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void sub_0032DE00(Vec_0032DE00 *d, const Vec_0032DE00 *a, const Vec_0032DE00 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}

void func_L01_0032DE00(u8 *m) {
    Vec_0032DE00 old_position;
    s32 info[2];
    Vec_0032DE00 direction, forward, quaternion, axis;
    Mat_0032DE00 rotation;
    Query_0032DE00 query;
    Vec_0032DE00 delta;
    Vec_0032DE00 inverse[4];
    u8 *p = *(u8 **)(m + 0x68);
    s32 collision;
    f32 angle;
    switch (m[0x20]) {
    case 0:
        m[0x20] = 1;
        *(s32 *)(p + 0x6C) = D_L01_001DCE8C;
        D_L01_001DCE8C = (D_L01_001DCE8C + 1) % 100;
        *(s16 *)(p + 0x90) = 180;
        *(s32 *)(m + 0x98) = 0;
    case 1:
        func_L01_004C41E8(m + 0x10, &direction);
        func_00388830(&forward, m + 0xE0, 1.0f);
        func_00388758(&axis, &forward, &direction);
        angle = func_00388730(&forward, &direction) * 0.5f;
        func_003886E8(&quaternion, &axis, func_00388978(angle));
        quaternion.w = func_00388960(angle);
        func_003890D8(&quaternion, &rotation);
        func_00388EB8(m + 0xC0, &rotation, m + 0xC0);
        old_position = *(Vec_0032DE00 *)(m + 0x10);
        add_0032DE00((Vec_0032DE00 *)(m + 0x10), (Vec_0032DE00 *)(m + 0x10), (Vec_0032DE00 *)p);
        func_L01_004C4AD8(*(s8 *)(p + 0x4F), p, 0);
        func_L01_004C4190(m + 0x10, p, D_L01_001DCEF0 * 0.00027777778450399637f);
        query.from = old_position;
        query.to = *(Vec_0032DE00 *)(m + 0x10);
        info[0] = 0; info[1] = 0xC5A;
        query.velocity = *(Vec_0032DE00 *)p;
        query.info = info;
        query.radius = 0.12999999523162842f;
        query.step = D_L01_001DCEF8;
        query.scale = 0.5555555820465088f;
        query.skin = 0.09619999676942825f;
        query.hit = m;
        query.kind = 2;
        query.zero48 = 0;
        query.zero4c = 0;
        query.enabled = 1;
        query.enabled58 = 1;
        collision = func_L01_004C42C0(&query, -1);
        *(Vec_0032DE00 *)(m + 0x10) = query.to;
        *(Vec_0032DE00 *)p = query.velocity;
        if (func_L01_004C7670()) func_L01_004C6EC8(m + 0x10, m + 0x10);
        if (collision == 2) {
            if (query.hit && (*(s16 *)(query.hit + 0xAA) == 0xCB || *(s16 *)(query.hit + 0xAA) == 0x1366 || *(s16 *)(query.hit + 0xAA) == 0x1367)) {
                func_003886E8(p, p, 1.100000023841858f);
                break;
            }
            qzero(p);
            *(u8 **)(p + 0x70) = query.hit;
            if (query.hit) {
                *(f32 *)(p + 0x74) = *(f32 *)(query.hit + 0x10);
                *(f32 *)(p + 0x78) = *(f32 *)(query.hit + 0x14);
                *(f32 *)(p + 0x7C) = *(f32 *)(query.hit + 0x18);
            }
            collision = func_L01_004C73B0(query.surface);
            if (collision == 2) {
                *(f32 *)(p + 8) = -0.02500000223517418f;
                m[0x20] = 7;
                if (!query.surface) {
                    u8 *effect;
                    func_L01_004C2BF8(D_L01_001E1110, D_L01_001E1118[0], 1, *(f32 *)(m+0x10), *(f32 *)(m+0x14), 0.5f, -0.3499999940395355f);
                    effect = func_L01_00301508(m + 0x10, 3, 2.0f, 1.024999976158142f);
                    if (effect) effect[0x23] = 0x70;
                }
            } else if (collision == 1) {
                m[0x20] = 8;
            } else {
                *(s8 *)(p + 0x4E) = func_L01_004C7180(D_L01_00278A10, m);
                func_L01_0032F658();
                if (*(s32 *)(D_L01_00278A10 + 0x100 + *(s8 *)(p + 0x4E) * 4)) {
                    m[0x20] = 2;
                    func_L01_004A72A8(1, 0, m, 0x1367);
                    func_L01_00441E00(m, 1, 0, 0, 0);
                } else m[0x20] = 6;
            }
            func_L01_004C4AB8(*(s8 *)(p + 0x4F));
            D_L01_002783D0[*(s32 *)(p + 0x6C)] = D_L01_001DB02C[0];
            if (D_L01_001DB02C[0]) {
                sub_0032DE00(&delta, (Vec_0032DE00 *)(m + 0x10), (Vec_0032DE00 *)(D_L01_001DB02C[0] + 0x10));
                func_00388E78(&inverse, D_L01_002783D0[*(s32 *)(p + 0x6C)] + 0xC0);
                func_003888F0(&delta, &delta, &inverse);
                D_L01_00278560[*(s32 *)(p + 0x6C)][0] = delta.x;
                D_L01_00278560[*(s32 *)(p + 0x6C)][1] = delta.y;
                D_L01_00278560[*(s32 *)(p + 0x6C)][2] = delta.z;
            }
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        }
        break;
    case 2:
        if (func_L01_00436500(m) >= 6.5f) {
            func_L01_00441E00(m, 2, 0, 0, 0);
            m[0x20] = 3;
        }
        break;
    case 3:
        func_L01_0032ECC0(m);
        if (*(u8 **)(p + 0x70) && ((*(u8 **)(p + 0x70))[0x20] == 0xFE || (*(u8 **)(p + 0x70))[0x20] == 0xFD)) {
            *(s32 *)(m + 0x98) = 0;
            *(s8 *)(p + 0x4F) = func_L01_004C4A18(m, 0, 1.0f, 1.0f, 1.0f);
            m[0x20] = 1; *(s32 *)(p + 0x70) = 0;
        }
        if (!*(s16 *)(D_001A4BE0 + 0x368) && !D_L01_001D673C[0] && !D_L01_001D6740[0]) {
            if (func_L01_0040C040(D_001A4BE0 + 0x80, m + 0x10) > 400.0f && func_003883C8(p + 0x90)) {
                s32 found = 0;
                s32 n = func_003CF790(D_001A4BE0 + 0x80, 1, *(void **)(D_001A4BE0 + 0x25C0), 0, 20.0f);
                u8 **it = D_L01_001EEB00;
                while (n > 0) {
                    u8 *o = *it++;
                    if (o && *(u8 **)(o + 0x24) && (*(u8 **)(o + 0x24))[0x46] == 5) found = 1;
                    n--;
                }
                if (found) {
                    *(s16 *)(p + 0x90) = func_0037E208(180, 240);
                    func_L01_00441FB8(m, 10, -1);
                }
            }
        }
        break;
    case 4:
        func_L01_0032EEE8(m); func_L01_0032EFE8(m);
        if (*(u8 **)(p + 0x70) && ((*(u8 **)(p + 0x70))[0x20] == 0xFE || (*(u8 **)(p + 0x70))[0x20] == 0xFD)) {
            *(s32 *)(m + 0x98) = 0;
            *(s8 *)(p + 0x4F) = func_L01_004C4A18(m, 0, 1.0f, 1.0f, 1.0f);
            m[0x20] = 1; *(s32 *)(p + 0x70) = 0;
        }
        break;
    case 5:
        if (func_L01_00436500(m) <= 1.0f) {
            func_L01_00441E00(m, 0, 0, 0, 0);
            *(f32 *)(m + 0x48) = 1.0f; m[0x20] = 6;
        }
        break;
    case 6:
        if (*(s32 *)(D_L01_00278A10 + 0x100 + *(s8 *)(p + 0x4E) * 4)) {
            m[0x20] = 2;
            func_L01_004A72A8(1, 0, m, 0x1367);
            func_L01_00441E00(m, 1, 0, 0, 0);
            *(s32 *)(p + 0x48) = func_L01_004C4548(m, 0);
        }
        break;
    case 7:
        func_L01_0032EA90(m); func_L01_0032EB28(m);
        break;
    case 8:
        func_L01_004A72A8(3, 0, m, 0x1367);
        func_L01_004488B8(m, m + 0x10, -1, 0.5f, 13.0f);
        m[0x20] = 9; *(u16 *)(m + 0x34) |= 0x41;
        break;
    case 9:
        if (*(s32 *)(p + 0x48) != -1) func_L01_004C45F8(*(s32 *)(p + 0x48));
        if (*(s8 *)(p + 0x4E) != -1) func_L01_004C71F8(D_L01_00278A10, *(s8 *)(p + 0x4E));
        func_003BD360(m);
        return;
    case 11:
        if (*(s16 *)(p + 0x9E) == 2) {
            func_L01_00441FB8(m, 3, -1);
            break;
        }
        if ((*(unsigned long *)(p + 0x98) & 0xFFFFFFFF00000000UL) == 0x1002800000000UL) func_0039FE80(5, 0, m);
        func_L01_00407010(m, p + 0x9C, p + 0x9E, p + 0x80, m + 0xF0, 2, 3, 45, 0xFF8040, 0x8F1010);
        break;
    case 10:
        func_0037E2F0(&delta, 3.0f, 6.5f);
        add_0032DE00(&delta, &delta, &D_001A4C60);
        if (delta.z < D_001A4C60.z) delta.z = D_001A4C60.z;
        delta.z = func_003BE7F0(&delta, 0, 0, 0.5f) + 1.0f;
        if (func_L01_0032E950(p + 0x80, &delta, m, 10.0f)) {
            if (func_L01_0040C040(&D_001A4C60, m + 0x10) > 400.0f && !func_L01_004C7670()) {
                func_L01_00441FB8(m, 11, -1);
                func_0039FE80(5, 0, m);
                *(s16 *)(p + 0x9E) = 0; *(s16 *)(p + 0x9C) = 45;
                break;
            }
        }
        func_L01_00441FB8(m, 3, -1);
        break;
    case 12:
        break;
    }
    if (m[0x20] >= 2 && D_L01_002783D0[*(s32 *)(p + 0x6C)]) {
        s32 idx = *(s32 *)(p + 0x6C);
        direction.x = D_L01_00278560[idx][0]; direction.y = D_L01_00278560[idx][1]; direction.z = D_L01_00278560[idx][2]; direction.w = 0;
        func_003888C8(&direction, &direction, D_L01_002783D0[*(s32 *)(p + 0x6C)] + 0xC0);
        add_0032DE00((Vec_0032DE00 *)(m + 0x10), (Vec_0032DE00 *)(D_L01_002783D0[*(s32 *)(p + 0x6C)] + 0x10), &direction);
    }
    if (m[0x20] == 3 || m[0x20] == 4) func_L01_0032F208(m);
    func_L01_0040BB20(p + 0x5C);
    if (func_00388398(p + 0x40) || D_001A71A4[0] == 0x74) { if (m[0x20] != 9) m[0x20] = 8; }
    if (m[0x20] == 3 || m[0x20] == 4) {
        func_L01_0032EBE0(m);
        if (!*(s32 *)(D_L01_00278A10 + 0x100 + *(s8 *)(p + 0x4E) * 4)) {
            func_L01_00441E00(m, 1, 9, 0, 0);
            m[0x20] = 5; *(f32 *)(m + 0x48) = -1.0f;
            func_L01_004C45F8(*(s32 *)(p + 0x48));
            *(s32 *)(p + 0x48) = -1; *(s16 *)(p + 0x4C) = 1;
            *(Vec_0032DE00 *)(p + 0x20) = *(Vec_0032DE00 *)(p + 0x10);
            *(Vec_0032DE00 *)(p + 0x30) = *(Vec_0032DE00 *)(p + 0x10);
            *(s32 *)(p + 0x50) = 0; *(s32 *)(p + 0x44) = 0; *(s32 *)(p + 0x64) = 0;
        }
    }
    if (m[0x20] < 8 && *(u8 **)(p + 0x70)) {
        if (!*(s32 *)(*(u8 **)(p + 0x70) + 0x24)) *(s32 *)(p + 0x70) = 0;
        else func_L01_0032EC40(m);
    }
    func_L01_004026A0(func_L01_0032F678, m);
}
/* localdecomp:end func_L01_0032DE00 */
