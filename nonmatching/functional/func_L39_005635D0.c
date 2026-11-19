/* functional: high. Ported from the NTSC-U draft shape but re-read against PAL asm (50 Hz frame scaling (x*5+2)/6 on gp counters, PAL gp slots +0x70, PAL callees). 495 byte diffs are codegen/stack layout only. */
#include "common.h"
extern s32 D_001DFE04_sda;
__asm__(".extern D_001DFE04_sda, 4");
extern s32 D_001DFE38_sda;
__asm__(".extern D_001DFE38_sda, 4");
extern s32 D_001DFDD8_sda;
__asm__(".extern D_001DFDD8_sda, 4");
extern s32 D_001DFDDC_sda;
__asm__(".extern D_001DFDDC_sda, 4");
extern s32 D_001DFDE0_sda;
__asm__(".extern D_001DFDE0_sda, 4");
extern s32 D_001DFDE4_sda;
__asm__(".extern D_001DFDE4_sda, 4");
extern s32 D_001DFE20_sda;
__asm__(".extern D_001DFE20_sda, 4");
extern s32 D_001DFE24_sda;
__asm__(".extern D_001DFE24_sda, 4");
extern s32 D_001DFE2C_sda;
__asm__(".extern D_001DFE2C_sda, 4");
extern f32 D_001DFE08_sda;
__asm__(".extern D_001DFE08_sda, 4");
extern f32 D_001DFE28_sda;
__asm__(".extern D_001DFE28_sda, 4");
extern f32 D_001DFDF4_sda;
__asm__(".extern D_001DFDF4_sda, 4");
extern f32 D_001DFE30_sda;
__asm__(".extern D_001DFE30_sda, 4");
extern s32 D_00241128[];
extern u8 D_001FE020[];
extern u8 D_00296818[];
extern u8 *D_002637C0[];
extern u8 *D_0024D690[8];
extern s32 D_0024D6B0[8];
extern s16 D_0024D6D0[5];
extern s16 D_0024D6E0[5];
extern s16 D_0024D6F0[5];
extern f32 D_0024DE00[];
extern f32 D_003CD480[5][10][4];
void func_L01_004C93B0(void);
f32 func_L01_004C93D8(void);
s32 func_L39_005F2FA0(void *, s32);
s32 func_L39_005F33E0(s32, s32, void *);
void func_L39_005F3088(s32);
s32 func_L39_00565008(void *, f32);
void func_L01_003119E0(void);
void func_003C2880(void *);
s32 func_0038CAD0(void *);
s32 func_0038CB00(void *);
void func_0038CE20(void *, void *, f32);
void func_003C2F58(void *, s32, void *);
s32 func_0038DBD8(s32, s32, f32);
s32 func_L39_005B43C8(s32, s32);
f32 func_L39_005B44C8(void);
void func_00382760(void *, f32, f32, f32);
u8 *func_L01_0046CA28(void *, s32, s32, s32);
s32 func_L01_0040E050(void *);
s32 func_003D4D00(void *, s32, void *, s32, f32);
u8 *func_00382348(void *);
void func_0038CF68(void *, void *, f32);
void func_L01_00446978(void *, void *);
void func_L01_00343658(void *, s32);
void func_00382580(void *, f32, f32);
f32 func_L39_005B4410(f32, f32);
void func_0038D890(void *, void *, void *, f32);
void func_L01_00404808(void *, void *);
void func_L39_00563DB8(void *);

static void bf148_copy(f32 *d, f32 *s) {
    d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
}
static void bf148_add(f32 *d, f32 *a, f32 *b) {
    f32 w = a[3];
    d[0] = a[0] + b[0]; d[1] = a[1] + b[1]; d[2] = a[2] + b[2]; d[3] = w;
}
static void bf148_sub(f32 *d, f32 *a, f32 *b) {
    f32 w = a[3];
    d[0] = a[0] - b[0]; d[1] = a[1] - b[1]; d[2] = a[2] - b[2]; d[3] = w;
}
static void bf148_release(u8 *obj, u8 *st) {
    s32 id = *(s32 *)(st + 0xC);
    u8 *e;
    if (id != -1) {
        e = D_001FE020 + id * 0x80;
        if (*(u8 **)(e + 0xDC) == obj && e[0xD0] != 0) func_L39_005F3088(id);
    }
    *(s32 *)(st + 0xC) = -1;
}

void func_L39_005635D0(u8 *obj) {
    u8 *st;
    u8 *ent;
    u8 *model;
    f32 scaled[4];
    f32 anchor[4];
    f32 position[4];
    f32 dirv[4];
    f32 temp[4];
    f32 endpoint[4];
    u8 *p;
    u8 *q;
    u8 *a;
    s32 i, j, id, count;
    f32 value, x, y, sign;
    s32 g;

    if (D_00241128[0] != 0) return;
    st = *(u8 **)(obj + 0x68);
    ent = *(u8 **)(st + 0x40);
    bf148_copy((f32 *)(obj + 0x10), (f32 *)(ent + 0xA0));
    func_L01_004C93B0();
    if (D_00241128[0] == 0) {
        if (func_L39_005F2FA0(obj, *(s32 *)(st + 0xC)) == 0)
            *(s32 *)(st + 0xC) = func_L39_005F33E0(3, 4, obj);
    } else if (func_L39_005F2FA0(obj, *(s32 *)(st + 0xC)) != 0) {
        bf148_release(obj, st);
    }
    value = func_L01_004C93D8();
    if (func_L39_00565008(obj, value) == 0 || D_001DFE04_sda == 0x28) {
        bf148_release(obj, st);
        D_001DFE04_sda = 0;
        func_L01_003119E0();
        func_L39_005F33E0(2, 0, obj);
        func_003C2880(obj);
        return;
    }
    g = D_001DFE38_sda;
    if (value != *(f32 *)(st + 0x0)) {
        *(f32 *)(st + 0x0) = value;
        *(s16 *)(st + 0x4) = (g * 5 + 2) / 6;
    }
    x = (f32)*(s16 *)(st + 0x4) / (f32)((g * 5 + 2) / 6);
    if (*(s16 *)(obj + 0xAA) == 0x1B37)
        *(s32 *)(st + 0x8) = func_0038DBD8(D_001DFDD8_sda, D_001DFDDC_sda, x);
    else
        *(s32 *)(st + 0x8) = func_0038DBD8(D_001DFDE0_sda, D_001DFDE4_sda, x);
    func_0038CB00(st + 0x4);
    ent = *(u8 **)(st + 0x40);
    model = *(u8 **)(ent + 0x2524);
    func_0038CE20(scaled, model + 0xE0, 0.75f);
    bf148_add((f32 *)(obj + 0x10), (f32 *)(ent + 0xA0), scaled);
    func_003C2F58(*(u8 **)(*(u8 **)(st + 0x40) + 0x2524), 10, anchor);
    for (i = 0; i < 8; i++) {
        if (D_0024D690[i] == 0) {
            id = (func_L39_005B43C8(D_001DFE20_sda, D_001DFE24_sda) * 5 + 2) / 6;
            x = func_L39_005B44C8();
            y = func_L39_005B44C8();
            func_00382760(position, D_001DFE08_sda, x, y);
            bf148_add(position, position, anchor);
            p = func_L01_0046CA28(position, id, 2, 1);
            D_0024D690[i] = p;
            if (p != 0) {
                a = p + 0x20;
                *(f32 *)(a + 0x10) = *(f32 *)(p + 0x10) - *(f32 *)(obj + 0x10);
                *(f32 *)(a + 0x14) = *(f32 *)(p + 0x14) - *(f32 *)(obj + 0x14);
                *(f32 *)(a + 0x18) = *(f32 *)(p + 0x18) - *(f32 *)(obj + 0x18);
                *(u8 **)(a + 0x4) = obj;
                *(f32 *)(p + 0xC) = D_001DFE28_sda * 210000.0f;
                *(s32 *)(p + 0x4) = D_001DFE2C_sda | *(s32 *)(st + 0x8);
                p[2] = (*(u8 **)(D_00296818 + 0xF8))[1];
                D_0024D6B0[i] = id;
            }
            p = func_L01_0046CA28(position, id, 2, 1);
            if (p != 0) {
                a = p + 0x20;
                *(f32 *)(a + 0x10) = *(f32 *)(p + 0x10) - *(f32 *)(obj + 0x10);
                *(f32 *)(a + 0x14) = *(f32 *)(p + 0x14) - *(f32 *)(obj + 0x14);
                *(f32 *)(a + 0x18) = *(f32 *)(p + 0x18) - *(f32 *)(obj + 0x18);
                *(u8 **)(a + 0x4) = obj;
                *(s32 *)(p + 0x4) = 0x307F7F7F;
                *(f32 *)(p + 0xC) = D_001DFE28_sda * 210000.0f * 0.3f;
                p[2] = (*(u8 **)(D_00296818 + 0xF8))[1];
            }
        } else if (func_0038CAD0(&D_0024D6B0[i]) != 0) {
            D_0024D690[i] = 0;
        }
    }
    func_0038CAD0(st + 0x14);
    for (i = 0; i < 4; i++) {
        if (func_0038CB00(st + 0x18 + i * 2) != 0) *(s32 *)(st + 0x20 + i * 4) = 0;
    }
    if (func_L01_0040E050(st + 0x10) != 0) {
        /* hit record at sp+0x30: dir(4 floats), owner, flags, a, b, kind, zero, one */
        u8 hit[0x24];
        count = func_003D4D00(obj + 0x10, 1, *(u8 **)(*(u8 **)(st + 0x40) + 0x2524), 0, D_001DFDF4_sda * 0.3f);
        if (count != 0) {
            *(f32 *)(hit + 0xC) = 5627.925f;
            *(u8 **)(hit + 0x10) = obj;
            *(s32 *)(hit + 0x14) = 0x10000;
            hit[0x18] = 3;
            hit[0x19] = 2;
            *(u16 *)(hit + 0x1A) = *(u16 *)(obj + 0xAA);
            *(s32 *)(hit + 0x1C) = 0;
            *(s32 *)(hit + 0x20) = 1;
            for (i = 0; i < count; i++) {
                u8 *h;
                p = D_002637C0[i];
                if (p[0x31] == 0) continue;
                if (p == 0 || p[0x20] == 0xFE) continue;
                if (p[0x20] == 0xFD) continue;
                if (*(u8 **)(p + 0x24) == 0) continue;
                if ((*(u8 **)(p + 0x24))[0x46] != 5) continue;
                h = func_00382348(p);
                if (h != 0) {
                    if (*(f32 *)h <= 0.0f) continue;
                    func_0038CE20(temp, obj + 0xE0, *(f32 *)(h + 0x10));
                    bf148_add(position, (f32 *)(p + 0x10), temp);
                } else {
                    bf148_copy(position, (f32 *)(p + 0x10));
                }
                bf148_sub((f32 *)hit, position, (f32 *)(obj + 0x10));
                func_0038CF68(hit, hit, 1.0f);
                func_L01_00446978(p, hit);
                func_0038CE20(temp, hit, D_001DFDF4_sda * 0.3f);
                bf148_add(endpoint, (f32 *)(obj + 0x10), temp);
                func_L01_00343658(endpoint, *(s32 *)(st + 0x8));
                *(f32 *)(st + 0x10) = 0.5f;
            }
        }
    }
    bf148_copy(position, anchor);
    for (i = 0; i < 5; i++) {
        f32 *vq;
        if (func_0038CB00(&D_0024D6D0[i]) != 0) D_0024D6D0[i] = 0;
        if (D_0024D6D0[i] == 0) {
            s16 n = (func_L39_005B43C8(3, 45) * 5 + 2) / 6;
            D_0024D6E0[i] = 0x40;
            D_0024D6F0[i] = n;
            D_0024D6D0[i] = n;
            func_00382580(dirv, D_001DFE30_sda, D_001DFE30_sda);
            vq = D_003CD480[i][0];
            bf148_copy(vq, position);
            vq[3] = 0.04f;
            sign = 1.0f;
            for (j = 0; j < 9; j++) {
                bf148_sub(temp, D_003CD480[i][j], D_0024DE00);
                x = func_L39_005B4410(0.08726646f, 1.3089969f);
                func_0038D890(dirv, dirv, temp, x * sign);
                sign = -sign;
                bf148_add(D_003CD480[i][j + 1], D_003CD480[i][j], dirv);
                D_003CD480[i][j + 1][3] = 0.04f;
            }
        }
    }
    func_L01_00404808(func_L39_00563DB8, obj);
}
