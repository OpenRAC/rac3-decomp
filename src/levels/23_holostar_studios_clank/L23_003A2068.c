#include "common.h"
#include "structs/hero.h"
typedef struct { f32 x0, x4, x8, xC; } Snd_3A3020;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0xC]; s32 iC; u8 pad10[0x1C - 0x10]; s32 i1C; f32 f20; f32 f24;
    u8 pad28[0x44 - 0x28]; s32 i44; u8 pad48[0x50 - 0x48]; s32 i50; s32 i54; s32 i58; s32 i5C;
    u8 pad60[0x68 - 0x60]; s32 i68; u8 pad6C[4]; f32 pos[4];
    u8 pad80[0x90 - 0x80]; s32 i90; s32 i94; s32 i98; u8 pad9C[0xD0 - 0x9C]; s32 iD0[36];
    s32 i160; s32 i164; s32 i168; s32 i16C;
} Vars_003A31D8;
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[6]; s16 h76; u8 pad78[0x94 - 0x78]; s32 i94; s16 h98; u8 pad9A[4]; s16 h9E; } G_003A31D8;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { u8 pad0[0x30]; V4 pos; u8 pad40[0x40]; } Node_3A2068;
typedef struct { u8 pad0[0x34]; u16 h34; u8 pad36[0x98 - 0x36]; s32 i98; } M10_3A2068;
typedef struct {
    u8 pad0[8]; s32 i8; s32 iC; M10_3A2068 *p10; s32 i14; s32 i18; u8 pad1C[4]; f32 f20; f32 f24;
    u8 pad28[0x30 - 0x28]; s32 i30; u8 pad34[0x3C - 0x34]; s32 i3C; u8 pad40[0x64 - 0x40]; s32 i64;
    u8 pad68[0x80 - 0x68]; s32 i80; s32 i84; s32 i88; s32 i8C; s32 i90; u8 pad94[0xB4 - 0x94];
    s32 iB4; s32 iB8; u8 padBC[4]; s32 iC0; s32 iC4; s32 iC8; s32 iCC; u8 padD0[0x160 - 0xD0];
    s32 i160; s32 i164; s32 i168; u8 pad16C[0x17C - 0x16C]; s32 i17C;
} Vars_003A2068;

/* localdecomp:start func_L23_003A2068 */
extern s32 D_L23_001D6694;
__asm__(".extern D_L23_001D6694, 16");
extern s32 D_L23_001D6690;
__asm__(".extern D_L23_001D6690, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001BBC40[][16];
extern s32 D_00142C60[];
__asm__(".extern D_00142C60, 16");
extern u8 D_001426E0[];
extern struct Hero D_001A4BE0;
extern u8 D_L23_001E8540[];
extern f32 D_L23_001D6720;
__asm__(".extern D_L23_001D6720, 16");
extern f32 D_L23_001DEA50;
__asm__(".extern D_L23_001DEA50, 16");
extern s32 D_L23_001DEC94;
__asm__(".extern D_L23_001DEC94, 16");
extern s32 D_L23_001DDF9C;
__asm__(".extern D_L23_001DDF9C, 4");
extern s32 D_L23_001DDFA0;
__asm__(".extern D_L23_001DDFA0, 4");
extern Node_3A2068 *D_L23_001DF240;
__asm__(".extern D_L23_001DF240, 16");

extern s32 func_L01_004561E0(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_00456500(void *, s32);
extern void func_L23_003A2A08(u8 *);
extern void func_L23_003A4008(u8 *);
extern void func_L23_0039B990(u8 *, V4);
extern void func_L01_003F1740(void *);
extern void func_L23_003B44E8(void *);
extern void func_L23_003B6D78(s32);
extern void func_L01_003F5498(s32, f32);
extern void func_L23_003D8628(s32, s32, f32);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern void func_00392DF0(s32, s32);
extern void func_0039EC28(s32, s32);
extern s32 func_0039EF28(void);
extern void func_L01_0043B510(s32);
extern u8 *func_00382348(void *);
extern void func_L03_004330B8(s32, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_0045F1E8(s32, s32);
extern s32 func_L01_0047B420(void);
extern void func_L01_004A3610(u8 *, u8 *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_004BA800(void);
extern void func_L01_004EDE10(void);
extern void func_L01_004450F0(void *, s32, s32);
void func_L23_003A3860(void *);
void func_L23_003A2E78(u8 *);
void func_L23_003A2EF0(u8 *);
void func_L23_003A2F68(void *, s32);
void func_L23_003A2FB8(void *);
void func_L23_003A3020(u8 *, u8 *);
void func_L23_003A31D8(u8 *);
void func_L23_003A3FC8(u8 *, s32);
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern u8 D_001A4C60[];
extern G_003A31D8 D_001CCFD0;
extern s32 func_00382380(void *, s32, s32);
extern s32 func_00382498(s32, s32);

void func_L23_003A2068(u8 *o)
{
    Vars_003A2068 *v = *(Vars_003A2068 **)(o + 0x68);
    s32 r;
    u8 *p;
    f32 f;
    unsigned long t;
    V4 pos;

    if (D_L23_001D6694 == 1 || D_L23_001D6694 == 2 || D_L23_001D6690 == 1 || D_L23_001D6690 == 2)
        return;
    if (o[0x95] == 0 && func_L01_004561E0(o)) {
        func_L23_003A2A08(o);
        func_L23_003A3FC8(o, 0);
    }
    if (o[0x20] == 0) {
        if (D_001BBC40[D_001D545C][v->i14] & 0x80)
            func_L01_004450F0(o, 5, 2);
        else
            func_L01_004450F0(o, 1, 1);
    }
    switch (o[0x95]) {
    case 2:
        if (func_L01_004561E0(o)) {
            func_L23_003A2EF0(o);
            func_L23_003A3FC8(o, 1);
        }
        func_L23_003A4008(o);
        break;
    case 1:
        if (func_L01_004561E0(o)) {
            func_L23_003A2E78(o);
            func_L23_003A3FC8(o, 0);
        }
        break;
    }
    switch (o[0x20]) {
    case 1:
        t = D_00142C60[0];
        if (!((t >> 2) & 1) && func_00392B20(D_L23_001E8540, 0xC2)) {
            func_00392C78(D_L23_001E8540);
            D_L23_001D6720 = 2.0f;
            v->i30 = 1;
            break;
        }
        func_L23_003A2F68(o, 500);
        func_L01_004450F0(o, 2, -1);
        break;
    case 2:
        if (func_L01_004561B8(o)) {
            r = D_L23_001DDF9C++;
            switch (r) {
            case 0: if (0x12 != v->i168 && 0x12 != v->i164) v->i160 = 0x12; break;
            case 2: if (0x1F != v->i168 && 0x1F != v->i164) v->i160 = 0x1F; break;
            case 4: if (0x20 != v->i168 && 0x20 != v->i164) v->i160 = 0x20; break;
            case 6: if (0x21 != v->i168 && 0x21 != v->i164) v->i160 = 0x21; break;
            case 11: if (0x1E != v->i168 && 0x1E != v->i164) v->i160 = 0x1E; break;
            default: if (0x1D != v->i168 && 0x1D != v->i164) v->i160 = 0x1D; break;
            }
        }
        if (func_00382380(D_001A4C60, v->iB8, 0))
            *(f32 *)(D_001A4C60 + 0x19DC) = 0.61086524f;
        else
            *(f32 *)(D_001A4C60 + 0x19DC) = 0.0f;
        *(s32 *)(*(u8 **)(D_L23_001DF15C + v->i80 * 0x100 + 0x68) + 0xC) =
            func_L01_00456250(D_L23_001DF15C + v->i84 * 0x100);
        if (v->i164 == 0 || v->i164 == 1 || (v->i64 >= 2 && v->i64 < 10)) {
            func_L23_003A2FB8(o);
            func_L23_003B6D78(v->i90);
            v->i164 = -1;
            v->i168 = -1;
        }
        if (__builtin_fabsf(D_001A4BE0.pos.z - D_L23_001DF240[v->iC8].pos.z) < 1.0f &&
            __builtin_fabsf(*(f32 *)(D_L23_001DF15C + v->i8 * 0x100 + 0x18) - D_L23_001DF240[v->iC4].pos.z) < 1.0f) {
            if (func_00382380(&D_001A4BE0.pos, v->iC0, 0)) {
                p = D_L23_001DF15C + (v->i8 << 8);
                pos = D_L23_001DF240[v->iC4].pos;
                func_L23_0039B990(p, pos);
            } else {
                p = D_L23_001DF15C + (v->i8 << 8);
                pos = D_L23_001DF240[v->iCC].pos;
                func_L23_0039B990(p, pos);
            }
        }
        if (v->i8C >= 0 && func_00382380(D_001A4C60, v->i8C, 0)) {
            func_L03_004330B8(v->i88, 1);
            v->i8C = -1;
        }
        if (v->i164 == 0x17)
            func_L01_004450F0(o, 4, -1);
        if (func_L01_00456500(D_001A4C60, v->iB4))
            func_L01_004450F0(o, 3, -1);
        break;
    case 3:
        func_L23_003A2F68(o, 2);
        if (D_L23_001DEA50 < 1.0f) {
            func_003C4138(&D_L23_001DEA50, 1.0f, 0.05f);
        } else {
            *(s16 *)((u8 *)&D_001A4BE0 + 0x22A) = 0;
            if (func_L01_004561B8(o)) {
                s32 k;

                if (D_001CCFD0.h76 != 6 && D_001CCFD0.h76 != 7) D_001CCFD0.h76 = 5;
                if (D_001CCFD0.h9E != 6 && D_001CCFD0.h9E != 7) D_001CCFD0.h9E = 5;
                k = func_00382498(8, 0xC);
                if (k != v->i168 && k != v->i164) v->i160 = k;
            }
            if (v->i160 == -1 && v->i168 == -1)
                func_L01_004EDE10();
        }
        break;
    case 4:
        if (func_L01_004561B8(o))
            func_L23_003D8628(0, 1, 17.0f);
        if (1.0f <= D_L23_001DEA50) {
            func_L01_0043B510(v->i14);
            func_L01_004450F0(o, 5, 2);
            D_001426E0[0xC2] = 1;
            func_L01_004A3610(D_001A4C60, D_001A4C60 + 0x10);
            func_0039EC28(0, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(o)) {
            func_L01_003F5498(0, 12.0f);
            func_L01_0045F1E8(v->i17C, -1);
            v->p10->h34 |= 0x41;
            v->p10->h34 &= ~0x1000;
            v->p10->i98 = 0;
            func_L01_004AA7E8(v->p10, 1);
            func_L23_003A2F68(o, 500);
        }
        func_L01_004450F0(o, 6, -1);
        break;
    case 6:
        p = func_00382348(D_L23_001DF15C + (v->iC << 8));
        if (p != 0 && *(s16 *)(p + 4) != 0) {
            f = *(f32 *)p / (f32)*(s16 *)(p + 4);
            if (f < 0.0f) f = 0.0f;
        } else {
            f = 1.0f;
        }
        v->f24 = f;
        f = (f32)*(s32 *)((u8 *)&D_001A4BE0 + 0x1A84) / 1500.0f;
        if (f < 0.0f) f = 0.0f;
        v->f20 = f;
        if (func_L01_004561B8(o)) {
            r = D_L23_001DDFA0++;
            switch (r) {
            case 0: if (0x10 != v->i168 && 0x10 != v->i164) v->i160 = 0x10; break;
            case 2: if (0x1F != v->i168 && 0x1F != v->i164) v->i160 = 0x1F; break;
            case 4: if (0x20 != v->i168 && 0x20 != v->i164) v->i160 = 0x20; break;
            case 6: if (0x21 != v->i168 && 0x21 != v->i164) v->i160 = 0x21; break;
            case 11: if (0x1E != v->i168 && 0x1E != v->i164) v->i160 = 0x1E; break;
            default: if (0x1D != v->i168 && 0x1D != v->i164) v->i160 = 0x1D; break;
            }
        }
        if (v->i164 == 0 || v->i164 == 1 || (v->i64 >= 2 && v->i64 < 10)) {
            func_L23_003A2FB8(o);
            func_L23_003B44E8(D_L23_001DF15C + (v->iC << 8));
            v->i164 = -1;
            v->i168 = -1;
        }
        if (v->f20 < 0.0f)
            func_L01_004450F0(o, 7, -1);
        if (v->i164 == 0x1B)
            func_L01_004450F0(o, 8, -1);
        func_L23_003A3020(o, D_L23_001DF15C + (v->iC << 8));
        break;
    case 7:
        func_L23_003A2F68(o, 2);
        if (D_L23_001DEA50 < 1.0f) {
            func_003C4138(&D_L23_001DEA50, 1.0f, 0.05f);
        } else {
            *(s16 *)((u8 *)&D_001A4BE0 + 0x22A) = 0;
            if (func_L01_004561B8(o)) {
                s32 k;

                if (D_001CCFD0.h76 != 6 && D_001CCFD0.h76 != 7) D_001CCFD0.h76 = 5;
                if (D_001CCFD0.h9E != 6 && D_001CCFD0.h9E != 7) D_001CCFD0.h9E = 5;
                k = func_00382498(8, 0xC);
                if (k != v->i168 && k != v->i164) v->i160 = k;
            }
            if (v->i160 == -1 && v->i168 == -1)
                func_L01_004EDE10();
        }
        break;
    case 8:
        if (func_L01_004561B8(o))
            func_L01_003F1740(o);
        if (*(u16 *)(o + 0x96) > 300) {
            if (!(D_00142C60[0] & 1) && func_00392B20(D_L23_001E8540, 0xC0)) {
                func_00392B20(D_L23_001E8540, 0xC1);
                func_00392C78(D_L23_001E8540);
                D_L23_001DEC94 = 0;
                v->i3C = 1;
            } else if (!func_L01_004BA800()) {
                D_L23_001DEC94 = 2;
                D_001426E0[0x32] = 1;
                func_0039EF28();
                func_L01_0043B510(v->i18);
                func_L01_0047B420();
                func_00392DF0(0xD, 1);
                func_L01_004450F0(o, 9, -1);
            }
        }
        break;
    }
    func_L23_003A31D8(o);
    func_L23_003A3860(o);
}
/* localdecomp:end func_L23_003A2068 */

INCLUDE_ASM("asm/levels", func_L23_003A2A08);

/* localdecomp:start func_L23_003A2E78 */
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_001DBD14;
__asm__(".extern D_001DBD14, 16");
extern void func_L23_004CF590(s32, s32, void *);
extern void func_L01_004F50C8(void *a, void *b, s32 c, s32 d);

void func_L23_003A2E78(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x68);
    u8 *e;

    func_L23_004CF590(1, 0x3F, D_L23_001DF15C + (*p << 8));
    e = D_L23_001DF15C + (*p << 8);
    func_L01_004F50C8(e + 0x10, e + 0xF0, -1, 1);
    D_001DBD14 = 1;
}
/* localdecomp:end func_L23_003A2E78 */

/* localdecomp:start func_L23_003A2EF0 */
extern s32 func_L01_0047B3D8(void);
extern void func_L01_004CB540(u8);
extern void func_L23_004CF590(s32, s32, void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");

void func_L23_003A2EF0(u8 *self)
{
    u8 *s = *(u8 **)(self + 0x68);
    u8 *e;

    func_L01_0047B3D8();
    func_L01_004CB540(1);
    func_L23_004CF590(2, 0x5A, D_L23_001DF15C + (*(s32 *)(s + 4) << 8));
    e = D_L23_001DF15C + (*(s32 *)(s + 4) << 8);
    func_L01_004F50C8(e + 0x10, e + 0xF0, -1, 1);
}
/* localdecomp:end func_L23_003A2EF0 */

/* localdecomp:start func_L23_003A2F68 */
void func_L23_004E3428(s32, s32);
extern s32 D_001A71A4[];

void func_L23_003A2F68(void *arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    if (D_001A71A4[0] != 0x74) {
        func_L23_004E3428(0x74, 1);
    }
    *(s32 *)((u8 *)temp_s0 + 0x64) = arg1;
}
/* localdecomp:end func_L23_003A2F68 */

/* localdecomp:start func_L23_003A2FB8 */
void func_L23_003A2FB8(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    if (D_001A71A4[0] == 0x74) {
        if (*(u8 *)((u8 *)arg0 + 0x95) == 1) {
            func_L23_004E3428(0x3F, 1);
        } else {
            func_L23_004E3428(0x5A, 1);
        }
    }
    *(s32 *)((u8 *)temp_s0 + 0x64) = 0;
}
/* localdecomp:end func_L23_003A2FB8 */

/* localdecomp:start func_L23_003A3020 */
extern f32 D_L23_001DDFA4;
__asm__(".extern D_L23_001DDFA4, 4");
extern f32 D_L23_001DDFA8;
__asm__(".extern D_L23_001DDFA8, 4");
extern f32 D_L23_001DDFAC;
__asm__(".extern D_L23_001DDFAC, 4");
extern f32 D_L23_001DDFB0;
__asm__(".extern D_L23_001DDFB0, 4");
extern s32 func_L01_003F2A50(s32, s32);
extern void func_L16_00402D30(s32, s32);
extern void func_L01_003F2AF8(s32, s32);

void func_L23_003A3020(u8 *self, u8 *other)
{
    u8 *v = *(u8 **)(self + 0x68);
    u8 *ov = *(u8 **)(other + 0x68);
    Snd_3A3020 *s;

    if (D_001A71A4[0] == 0x5F) {
        if (*(s32 *)(v + 0xB0) == 0) {
            *(s32 *)(v + 0xB0) = func_L01_003F2A50(0, 5);
            if (*(s32 *)(v + 0xB0) == 0)
                goto next;
        }
        ((Snd_3A3020 *)*(s32 *)(v + 0xB0))->xC = D_L23_001DDFB0;
        func_L16_00402D30(0, *(s32 *)(v + 0xB0));
    } else if (*(s32 *)(v + 0xB0) != 0) {
        ((Snd_3A3020 *)*(s32 *)(v + 0xB0))->xC = -1.0f;
    }
next:
    if (*(s32 *)(ov + 0x300) == 3 && other[0x95] != 2 && self[0x20] == 6 && other != 0 &&
        other[0x20] != 0xFE && other[0x20] != 0xFD) {
        if (*(s32 *)(v + 0xB0) == 0) {
            *(s32 *)(v + 0xB0) = func_L01_003F2A50(0, 5);
            if (*(s32 *)(v + 0xB0) == 0)
                return;
        }
        ((Snd_3A3020 *)*(s32 *)(v + 0xB0))->x4 = D_L23_001DDFAC;
        ((Snd_3A3020 *)*(s32 *)(v + 0xB0))->x8 = D_L23_001DDFA4;
        ((Snd_3A3020 *)*(s32 *)(v + 0xB0))->x0 = D_L23_001DDFA8;
        func_L16_00402D30(0, *(s32 *)(v + 0xB0));
    } else {
        if (*(s32 *)(v + 0xB0) == 0)
            return;
        ((Snd_3A3020 *)*(s32 *)(v + 0xB0))->x4 = -1.0f;
        ((Snd_3A3020 *)*(s32 *)(v + 0xB0))->x8 = -1.0f;
        ((Snd_3A3020 *)*(s32 *)(v + 0xB0))->x0 = -1.0f;
    }
    s = (Snd_3A3020 *)*(s32 *)(v + 0xB0);
    if (s != 0 && s->xC < 0.0f && s->x4 < 0.0f) {
        func_L01_003F2AF8(0, (s32)s);
        *(s32 *)(v + 0xB0) = 0;
    }
}
/* localdecomp:end func_L23_003A3020 */

/* localdecomp:start func_L23_003A31D8 */
extern u8 D_001A4C60[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern G_003A31D8 D_001CCFD0;
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_00382498(s32, s32);
extern void func_003A2B68(s32, s32);
extern void func_003A1798(void);

void func_L23_003A31D8(u8 *a0)
{
    Vars_003A31D8 *v = *(Vars_003A31D8 **)(a0 + 0x68);
    s32 r;
    s32 t;
    f32 d;

    if (a0[0x95] == 1) {
        if (v->i164 == 0x12) {
            if (v->i168 != 1 && v->i164 != 1) v->i160 = 1;
            v->i164 = -1;
        }
        if ((u32)(v->i164 - 0x1D) < 5) {
            if (v->i168 != 0 && v->i164 != 0) v->i160 = 0;
            v->i164 = -1;
        }
        if (v->i50 >= 0 && func_00382380(D_001A4C60, v->i50, 0) != 0) {
            if (v->i168 != 2 && v->i164 != 2) v->i160 = 2;
            v->i50 = -1;
        }
        if (v->i54 >= 0 && func_00382380(D_001A4C60, v->i54, 0) != 0) {
            if (v->i168 != 3 && v->i164 != 3) v->i160 = 3;
            v->i54 = -1;
        }
        if (v->i58 >= 0 && func_00382380(D_001A4C60, v->i58, 0) != 0 && func_L01_00445AD0(v->i94, -1, 0) == 0) {
            if (v->i168 != 7 && v->i164 != 7) v->i160 = 7;
            v->i58 = -1;
        }
        if (v->i5C >= 0 && func_00382380(D_001A4C60, v->i5C, 0) != 0) {
            if (v->i168 != 0x14 && v->i164 != 0x14) v->i160 = 0x14;
            v->i5C = -1;
        }
        if (v->i98 >= 0 && func_L01_00445AD0(v->i98, -1, 0) == 0) {
            if (v->i168 != 6 && v->i164 != 6) v->i160 = 6;
            v->i98 = -1;
        }
        if (v->i90 >= 0 && func_L01_00445AD0(v->i90, -1, 0) == 0) {
            if (v->i168 != 0x1C && v->i164 != 0x1C) v->i160 = 0x1C;
            v->i90 = -1;
        }
        if (func_L01_0040E570(D_001A4C60, v->pos) > 2.0f) {
            *(u128_t *)v->pos = *(u128_t *)D_001A4C60;
            v->i68 = func_00382498(500, 1000);
        } else if (func_0038CAD0(&v->i68) != 0) {
            r = func_00382498(0xE, 0xF);
            if (r != v->i168 && r != v->i164) v->i160 = r;
            v->i68 = 1500;
        }
        if (v->i44 >= 0 && func_00382380(D_001A4C60, v->i44, 0) != 0) {
            if (v->i168 != 0x17 && v->i164 != 0x17) v->i160 = 0x17;
            v->i44 = -1;
        }
    } else if (a0[0x95] == 2) {
        if (v->i164 == 0x10) {
            if (v->i168 != 1 && v->i164 != 1) v->i160 = 1;
            v->i164 = -1;
        }
        if ((u32)(v->i164 - 0x1D) < 5) {
            if (v->i168 != 0 && v->i164 != 0) v->i160 = 0;
            v->i164 = -1;
        }
        t = *(s32 *)(*(u8 **)(D_L23_001DF15C + v->iC * 0x100 + 0x68) + 0x390);
        if (t != v->i16C) {
            if (t == 2) {
                if (v->i168 != 4 && v->i164 != 4) v->i160 = 4;
            }
            if (t == 3) {
                if (v->i168 != 0x11 && v->i164 != 0x11) v->i160 = 0x11;
            }
            if (t == 5) {
                if (v->i168 != 5 && v->i164 != 5) v->i160 = 5;
            }
            if (t == 7) {
                if (v->i168 != 0x13 && v->i164 != 0x13) v->i160 = 0x13;
            }
            v->i16C = t;
        }
        if (v->f24 <= 0.0f) {
            if (v->i168 != 0x1B && v->i164 != 0x1B) v->i160 = 0x1B;
        } else {
            d = v->f24 - v->f20;
            if (d > 0.5f && v->i1C < 5) {
                if (v->i168 != 0x1A && v->i164 != 0x1A) v->i160 = 0x1A;
                v->i1C = 5;
            } else if (d > 0.4f && v->i1C < 4) {
                if (v->i168 != 0x16 && v->i164 != 0x16) v->i160 = 0x16;
                v->i1C = 4;
            } else if (d > 0.3f && v->i1C < 3) {
                if (v->i168 != 0x15 && v->i164 != 0x15) v->i160 = 0x15;
                v->i1C = 3;
            } else if (d > 0.2f && v->i1C < 2) {
                if (v->i168 != 0x19 && v->i164 != 0x19) v->i160 = 0x19;
                v->i1C = 4;
            } else if (d > 0.4f && v->i1C < 1) {
                if (v->i168 != 0x18 && v->i164 != 0x18) v->i160 = 0x18;
                v->i1C = 1;
            }
        }
    }
    if (D_001CCFD0.i6C == 0 && D_001CCFD0.i24 == -1 && D_001CCFD0.i94 == 0) {
        if (v->i168 >= 0) {
            v->i164 = v->i168;
            v->i168 = -1;
        }
        t = v->i160;
        if (t >= 0) {
            v->i160 = -1;
            v->i168 = t;
            func_003A2B68((v->iD0[t] & 0x3FFF) + 6000, 0);
        }
    }
    if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
        func_003A1798();
    }
}
/* localdecomp:end func_L23_003A31D8 */

/* localdecomp:start func_L23_003A3860 */
extern s32 func_0038CAD0(void *);
void func_L23_003A2FB8(void *);
extern s32 D_001A71A4[];

void func_L23_003A3860(void *arg0) {
    u8 *temp_s1;

    temp_s1 = *(u8 **)((u8 *)arg0 + 0x68);
    *(u16 *)((u8 *)arg0 + 0x96) += 1;
    func_0038CAD0(temp_s1 + 0x64);
    if (D_001A71A4[0] == 0x74 && *(s32 *)(temp_s1 + 0x64) <= 0) {
        func_L23_003A2FB8(arg0);
    }
}
/* localdecomp:end func_L23_003A3860 */

/* localdecomp:start func_L23_003A38C8 */
extern f32 D_L23_001DDFCC;
__asm__(".extern D_L23_001DDFCC, 4");
extern f32 D_L23_001DDFD0;
__asm__(".extern D_L23_001DDFD0, 4");
extern f32 D_L23_001DDFD4;
__asm__(".extern D_L23_001DDFD4, 4");
extern f32 D_L23_001DDFD8;
__asm__(".extern D_L23_001DDFD8, 4");
extern f32 D_L23_001DDFDC;
__asm__(".extern D_L23_001DDFDC, 4");
extern f32 D_L23_001DDFE0;
__asm__(".extern D_L23_001DDFE0, 4");
extern f32 D_L23_001DDFE4;
__asm__(".extern D_L23_001DDFE4, 4");
extern f32 D_L23_001DDFE8;
__asm__(".extern D_L23_001DDFE8, 4");
extern f32 D_L23_001DDFEC;
__asm__(".extern D_L23_001DDFEC, 4");
extern f32 D_L23_001DDFF0;
__asm__(".extern D_L23_001DDFF0, 4");
extern f32 D_L23_001DDFF4;
__asm__(".extern D_L23_001DDFF4, 4");
extern f32 D_L23_001DDFF8;
__asm__(".extern D_L23_001DDFF8, 4");
extern f32 D_L23_001DDFFC;
__asm__(".extern D_L23_001DDFFC, 4");
extern f32 D_L23_001DE004;
__asm__(".extern D_L23_001DE004, 4");
extern f32 D_L23_001DE008;
__asm__(".extern D_L23_001DE008, 4");
extern f32 D_L23_001DE00C;
__asm__(".extern D_L23_001DE00C, 4");
extern f32 D_L23_001DE010;
__asm__(".extern D_L23_001DE010, 4");
extern char D_L23_001DE018[];
extern void func_L01_004D4340(s32);
extern s32 func_003B5060(s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E51F8(s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516B90(s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_003EA778(s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_00518670(s32, s32, s32);
extern s32 func_003E8348(s32, s32);

void func_L23_003A38C8(void)
{
    func_L01_004D4340(0);
    func_003B5060(0x730000);
    func_003B5060(0x73000F);
    func_003E8630(0x730000, 0x73000F);
    func_003E8EF0(0x730010, 0x74, 0x331465B7, D_L23_001DDFD4 + D_L23_001DE004, D_L23_001DDFCC + D_L23_001DE008, D_L23_001DE00C, D_L23_001DE010, 0.0f);
    func_003E8630(0x73000F, 0x730010);
    func_003E8EF0(0x730011, 0x73, 0x332299DE, D_L23_001DDFD4 + D_L23_001DE004, D_L23_001DDFCC + D_L23_001DE008, D_L23_001DE00C, D_L23_001DE010, 0.0f);
    func_003E8630(0x73000F, 0x730011);
    func_003E8EF0(0x730012, 0x75, 0x8066CCFF, D_L23_001DDFD4 + D_L23_001DE004, D_L23_001DDFCC + D_L23_001DE008, D_L23_001DE00C, D_L23_001DE010, 0.0f);
    func_003E8630(0x73000F, 0x730012);
    func_003E8EF0(0x730001, 0x71, 0x331465B7, D_L23_001DDFD4, D_L23_001DDFCC, 1.0f, 1.0f, 0.0f);
    func_003E8630(0x730000, 0x730001);
    func_003E8EF0(0x730002, 0x72, 0x8066CCFF, D_L23_001DDFD4, D_L23_001DDFCC, 1.0f, 1.0f, 1.0f);
    func_003E8630(0x730000, 0x730002);
    func_003E8EF0(0x730003, 0x70, 0x332299DE, D_L23_001DDFD4, D_L23_001DDFCC, 1.0f, 1.0f, 0.0f);
    func_003E8630(0x730000, 0x730003);
    func_003E51F8(0x730004);
    func_L01_00517538(0x730004, D_L23_001DDFE0, D_L23_001DDFE0);
    func_L01_005170B8(0x730004, 0x8066CCFF);
    func_L01_00516B90(0x730004, 3, 3);
    func_L01_00516470(0x730004, D_L23_001DDFD4 + D_L23_001DDFE4, D_L23_001DDFCC + D_L23_001DDFE8);
    func_L01_00517190(0x730004, 0xED47);
    func_003E8630(0x730000, 0x730004);
    func_003EA778(0x730005);
    func_L01_005170B8(0x730005, 0x8066CCFF);
    func_L01_00517538(0x730005, 0.5f, 0.1f);
    func_L01_00516470(0x730005, D_L23_001DDFD4, D_L23_001DDFCC + 0.05f);
    func_L01_00516B90(0x730005, 3, 3);
    func_L01_00516FD8(0x730005, (s32)D_L23_001DE018);
    func_L01_00518670(0x730005, 1, 1);
    func_003E8EF0(0x730006, 0x71, 0x331465B7, D_L23_001DDFD0, D_L23_001DDFCC, -1.0f, 1.0f, 0.0f);
    func_003E8630(0x730000, 0x730006);
    func_003E8EF0(0x730007, 0x72, 0x8066CCFF, D_L23_001DDFD0, D_L23_001DDFCC, -1.0f, 1.0f, 1.0f);
    func_003E8630(0x730000, 0x730007);
    func_003E8EF0(0x730008, 0x70, 0x332299DE, D_L23_001DDFD0, D_L23_001DDFCC, -1.0f, 1.0f, 0.0f);
    func_003E8630(0x730000, 0x730008);
    func_003E51F8(0x730009);
    func_L01_00517538(0x730009, D_L23_001DDFE0, D_L23_001DDFE0);
    func_L01_005170B8(0x730009, 0x8066CCFF);
    func_L01_00516B90(0x730009, 3, 3);
    func_L01_00516470(0x730009, D_L23_001DDFD0 - D_L23_001DDFE4 + 0.004f, D_L23_001DDFCC + D_L23_001DDFE8 + 0.004f);
    func_L01_00517190(0x730009, 0xED46);
    func_003E8630(0x730000, 0x730009);
    func_003EA778(0x73000A);
    func_L01_005170B8(0x73000A, 0x8066CCFF);
    func_L01_00517538(0x73000A, 0.5f, 0.1f);
    func_L01_00516470(0x73000A, D_L23_001DDFD0, D_L23_001DDFCC + 0.05f);
    func_L01_00516B90(0x73000A, 3, 3);
    func_L01_00516FD8(0x73000A, (s32)D_L23_001DE018);
    func_L01_00518670(0x73000A, 1, 1);
    func_003E8EF0(0x73000B, 0x77, 0x331465B7, D_L23_001DDFD8, D_L23_001DDFDC, 1.0f, 1.0f, D_L23_001DDFFC);
    func_003E8630(0x730000, 0x73000B);
    func_003E8EF0(0x73000C, 0x76, 0x332299DE, D_L23_001DDFD8, D_L23_001DDFDC, 1.0f, 1.0f, D_L23_001DDFFC);
    func_003E8630(0x730000, 0x73000C);
    func_003E51F8(0x73000D);
    func_L01_00517538(0x73000D, D_L23_001DDFE0, D_L23_001DDFE0);
    func_L01_005170B8(0x73000D, 0x8066CCFF);
    func_L01_00516B90(0x73000D, 3, 3);
    func_L01_00516470(0x73000D, D_L23_001DDFD8 + D_L23_001DDFEC, D_L23_001DDFDC + D_L23_001DDFF0);
    func_L01_00517190(0x73000D, 0xED48);
    func_003E8630(0x730000, 0x73000D);
    func_003EA778(0x73000E);
    func_L01_005170B8(0x73000E, 0x8066CCFF);
    func_L01_00517538(0x73000E, D_L23_001DDFE0 * 5.0f, D_L23_001DDFE0);
    func_L01_00516470(0x73000E, D_L23_001DDFD8 + D_L23_001DDFF4, D_L23_001DDFDC + D_L23_001DDFF8);
    func_L01_00516B90(0x73000E, 1, 3);
    func_L01_00516FD8(0x73000E, (s32)D_L23_001DE018);
    func_L01_00518670(0x73000E, 1, 1);
    func_003E8630(0x730000, 0x73000E);
    func_003E8348(0, 0x730000);
}
/* localdecomp:end func_L23_003A38C8 */

/* localdecomp:start func_L23_003A3FC8 */
s32 func_L01_00516AA0(s32, s32, s32);

void func_L23_003A3FC8(u8 *arg0, s32 arg1) {
    if (arg1 != 0) {
        func_L01_00516AA0(0x730000, 1, 1);
        return;
    }
    func_L01_00516AA0(0x730000, 1, 0);
}
/* localdecomp:end func_L23_003A3FC8 */
