/* functional: medium. 284 diff words at the file's flags (register allocation and loop layout only); constants (157500.0, 6.0/5.0, 1000.0, 0.40000001), the 17-entry sound/effect table read from the retail ELF (index 0 -> -1, 1..16 -> 0x27,0x2F,0x47,0x37,0x6F,0x3F,0x5F,0x11,0x7F,0x77,0x57,0x4F,0x67,0x97,0x13,0x16), loop trip counts (2, 2, 30) and the gp+0x700 threshold (n<21: 2 if n<11 else 1) checked. */
typedef struct { f32 x, y, z, w; } V4;
typedef int Q16 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 D_001A7E18[];
extern u16 D_001A8A9C[];
extern u8 D_001D66B0[];
extern u8 D_L01_00221098[];
extern s32 D_001DCFB0_sda;
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_004443E8(u8 *, s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_00451E78(u8 *, s32, s32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_00382580(void *, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004735F0(void *, void *, s32, f32);
extern s32 func_L01_00443FB0(u8 *, void *);
extern void func_L01_0030F288(void *, s32, s32, s32);

static const s32 sfx_tbl[17] = {-1, 0x27, 0x2F, 0x47, 0x37, 0x6F, 0x3F, 0x5F, 0x11, 0x7F, 0x77, 0x57, 0x4F, 0x67, 0x97, 0x13, 0x16};

void func_L01_0033C030(u8 *m) {
    Q16 buf[4];
    u8 *sp = (u8 *)buf;
    u8 *p = *(u8 **)(m + 0x68);
    u8 *hero;
    u8 *q;
    u8 *e;
    s32 type;
    s32 flag;
    s32 n;
    s32 k;
    s32 cnt;
    s32 val;
    f32 f20 = 0.0f;
    f32 f21 = 157500.0f;
    f32 f22;
    s32 cur;
    s32 b;
    V4 *a;
    V4 *c;
    V4 *d;

    type = *(s16 *)(m + 0xAA);
    flag = (*(s16 *)(p + 0xF6) == 0);
    if (type == 0x1F5 || type == 0x200 || type == 0x1F7 || type == 0x1FA) {
        flag = 0;
    }
    if (flag != 0) {
        n = D_001DCFB0_sda;
        if (n < 0x15) {
            k = (n < 0xB) ? 2 : 1;
        } else {
            k = 0;
        }
        func_L01_004443E8(m, 0x100, func_00382468(2) + k);
        return;
    }
    type = *(s16 *)(m + 0xAA);
    if (type != 0x1F5 && type != 0x200) {
        if (type == 0x1F7) {
            q = D_001A7E18 + 0x8000;
            if (*(u16 *)(q + 0x7048) == 0) {
                func_L01_0041A5B0(0x1406, 0x108);
                if (*(u16 *)(q + 0x7048) == 0) {
                    *(u16 *)(q + 0x7048) = 1;
                }
            }
            hero = D_001A4BE0;
            b = hero[0x28C8] + 1;
            hero[0x28C8] = b;
            *(s32 *)(hero + 0x230) = *(s32 *)(hero + 0x230) + 0x5DC;
            func_L01_00451E78(m, 1, b);
            f22 = 6.0f;
            *(Q16 *)sp = *(Q16 *)(m + 0x10);
            *(f32 *)(sp + 8) = *(f32 *)(sp + 8) + 0.5f;
            k = 1;
            do {
                val = (s32)func_L01_00443A18(1.0f, -1.0f);
                e = func_L01_0046A610(sp, D_001D66B0, 0x32, 6, 0x904020, val, f21 * f22, 1000.0f, f20, f20, f20);
                k = k - 1;
                if (e != 0) {
                    e[2] = (*(u8 **)(D_L01_00221098 + 0x170))[1];
                }
            } while (k >= 0);
            f22 = 5.0f;
            k = 1;
            do {
                val = (s32)func_L01_00443A18(1.0f, -1.0f);
                e = func_L01_0046A610(sp, D_001D66B0, 0x32, 0x7F, 0x804020, val, f21 * f22, 1000.0f, f20, f20, f20);
                k = k - 1;
                if (e != 0) {
                    e[2] = (*(u8 **)(D_L01_00221098 + 0x170))[0];
                }
            } while (k >= 0);
            cnt = 0x1D;
            do {
                cnt = cnt - 1;
                func_00382580(sp + 0x10, 1.5f, 2.0f);
                a = (V4 *)sp;
                c = (V4 *)(sp + 0x10);
                d = (V4 *)(sp + 0x20);
                c->x = c->x + a->x;
                c->y = c->y + a->y;
                c->z = c->z + a->z;
                d->x = a->x - c->x;
                d->y = a->y - c->y;
                d->z = a->z - c->z;
                d->w = a->w;
                func_0038CF68(sp + 0x20, sp + 0x20, 0.40000001f);
                func_L01_004735F0(sp + 0x10, sp + 0x20, 0x25, 5.0f);
            } while (cnt >= 0);
        } else if (type == 0x1FA) {
            e = *(u8 **)(p + 0x12C);
            e[0xBC] = 1;
            *(s32 *)(*(u8 **)(p + 0x12C) + 0xB8) = 0;
            if (D_001A8A9C[0] == 0) {
                func_L01_0041A5B0(0x1409, 0x10B);
            }
        } else {
            b = p[0xFB];
            if (b < 0x11) {
                val = sfx_tbl[b];
            } else {
                val = -1;
            }
            *(s32 *)(sp + 0x30) = val;
            n = func_L01_00443FB0(m, sp + 0x30);
            if (n > 0) {
                do {
                    func_L01_0030F288(m + 0x10, *(s32 *)(sp + 0x30), -1, 0);
                    n = n - 1;
                } while (n != 0);
            }
        }
    }
    if (*(s16 *)(m + 0xB4) != 0) {
        *(s16 *)(m + 0xB4) = 0;
    }
    func_L01_004443E8(m, 0x100, 0);
}
