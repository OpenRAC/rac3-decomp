#include "common.h"

/* localdecomp:start func_L03_00399278 */
extern f32 D_001DE350_sda; __asm__(".extern D_001DE350_sda, 4");
extern s32 func_L01_00456250(void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
void func_L03_00399278(u8 *self)
{
    s32 s = self[0x20];
    f32 *p = *(f32 **)(self + 0x68);
    f32 v;
    switch (s) {
    case 0:
        *(u16 *)(self + 0x34) |= 0x2000;
        *p = 1.0f;
        func_L01_004450F0(self, 1, -1);
        break;
    case 1:
        if (func_L01_00456250(self)) {
            func_L01_004450F0(self, 2, -1);
        }
        break;
    case 2:
        self[0x23] = (s32)(*p * 128.0f);
        v = *p - D_001DE350_sda * 1.2f;
        *p = v;
        if (v <= 0.0f) {
            *p = 0.0f;
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(self, 1);
            func_L01_004450F0(self, 3, -1);
        }
        break;
    }
}
/* localdecomp:end func_L03_00399278 */

/* localdecomp:start func_L03_003993A0 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x40];
    f32 f40;
    f32 f44;
    u8 f48[0x5C - 0x48];
    s32 i5C;
    s32 i60;
    u8 pad64[0x70 - 0x64];
    f32 f70;
    f32 f74;
    s16 h78;
    s16 h7A;
    u8 pad7C[4];
    u8 b80;
    u8 b81;
} S_003993A0;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 b20; u8 pad21[0x47]; S_003993A0 *p68; u8 pad6C[0x95 - 0x6C]; u8 b95; } A_003993A0;
extern void func_L03_00399868(u8 *);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_003A4F28(s32);
extern s32 func_L01_004AAC98(s32, s32, u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L03_00399D30(void *);
extern void func_L03_0039A118(void *);
extern s32 func_0038CB00(void *);
extern void func_L03_003998E8(void *);
extern s32 func_00382498(s32, s32);
extern void func_L03_00399F38(void *);
extern void func_L01_004048D0(void *, u8 *);
extern void func_L03_0039A1F8(void *);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L03_00399BD8(u8 *, s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_003824E0(f32, f32);
extern void func_L03_0039A780(void *);

void func_L03_003993A0(u8 *self) {
    A_003993A0 *a = (A_003993A0 *)self;
    S_003993A0 *s;
    func_L03_00399868(self);
    s = a->p68;
    switch (a->b95) {
    case 1:
        break;
    case 2:
        func_003C41A0((f32 *)(self + 0x18), s->f48, s->f44, 0.0032000002f, 0.0032000002f, 0.16000001f);
        if (*(f32 *)(self + 0x18) <= s->f44) {
            func_003A4F28(s->i5C);
            s->b80 = 0;
            s->h78 = 100;
            s->i60 = func_L01_004AAC98(1, 4, self, 0x18EC);
            func_L01_004450F0(self, 1, 3);
        }
        break;
    case 3:
        func_L03_00399D30(self);
        if (s->h78 < 0 && (s->h78 % 4) == 0) func_L03_0039A118(self);
        if (func_0038CB00(&s->h78)) {
            func_L03_003998E8(self);
            s->b81 = 0;
            s->h78 = 100;
            s->h7A = ((func_00382498(-3, 3) + 20) * 5 + 2) / 6;
            s->i5C = func_L01_004AAC98(0, 4, self, 0x18EC);
            func_L01_004450F0(self, 2, 4);
        }
        break;
    case 4: {
        int done = 1;
        func_0038CB00(&s->h78);
        if (s->h78 > 0) {
            func_L03_00399F38(self);
            done = 0;
        }
        if (*(f32 *)(self + 0x18) < s->f40) {
            func_003C41A0((f32 *)(self + 0x18), s->f48, s->f40, 0.00040000002f, 0.00040000002f, 0.080000006f);
            done = 0;
        }
        if (done) {
            func_003A4F28(s->i60);
            s->i60 = -1;
            func_003A4F28(s->i5C);
            func_L01_004450F0(self, 0, 1);
        }
        break;
    }
    }
    switch (a->b20) {
    case 0:
        break;
    case 1:
        func_L01_004048D0(func_L03_0039A1F8, self);
        break;
    case 2:
        s->f74 = func_0038DAB8(s->f74, 0.06283186f);
        func_L01_004048D0(func_L03_0039A1F8, self);
        if (func_0038CB00(&s->h7A)) {
            func_L03_00399BD8(&s->b80, 4);
            if (s->b80 == 15) {
                s->h7A = ((func_00382498(-3, 3) + 20) * 5 + 2) / 6;
                func_L01_004450F0(self, 3, -1);
            } else {
                s->h7A = ((func_00382498(-3, 3) + 20) * 5 + 2) / 6;
            }
        }
        break;
    case 3:
        s->f74 = func_0038DAB8(s->f74, 0.06283186f);
        func_L01_004048D0(func_L03_0039A1F8, self);
        if (func_0038CB00(&s->h7A)) {
            s32 r = func_L03_00399BD8(&s->b81, 4);
            if (r != -1) {
                vu0_v4 p;
                vu0_v4 v;
                vu0_v4 w;
                f32 ang = func_0038DB48(s->f74 + (f32)r * 1.5707964f);
                p = a->pos;
                *(vu0_q *)&w = 0;
                p.z += 1.7f;
                w.x = s->f70 * func_0038D0B0(ang);
                w.y = s->f70 * func_0038D098(ang);
                v = w;
                vec_add_ab(&v, &p, &v);
                v.z = func_003824E0(s->f44, p.z);
                func_L03_0039A780(&v);
            }
            if (s->b81 == 15) {
                s->h7A = ((func_00382498(-3, 3) + 30) * 5 + 2) / 6;
                func_L01_004450F0(self, 4, -1);
            } else {
                s->h7A = ((func_00382498(-3, 3) + 20) * 5 + 2) / 6;
            }
        }
        break;
    case 4:
        func_L01_004048D0(func_L03_0039A1F8, self);
        if (func_0038CB00(&s->h7A)) {
            vu0_v4 p;
            p = a->pos;
            p.z += 1.7f;
            func_L03_0039A780(&p);
            func_003A4F28(s->i60);
            s->i60 = -1;
            func_L01_004450F0(self, 0, -1);
        }
        break;
    }
}
/* localdecomp:end func_L03_003993A0 */

/* localdecomp:start func_L03_00399868 */
extern f32 func_00382538(void);
extern void func_L01_003F5E88(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L03_00399868(u8 *self)
{
    u8 *s;

    if (self[0x95] == 0) {
        s = *(u8 **)(self + 0x68);
        *(f32 *)(s + 0x40) = *(f32 *)(self + 0x18);
        *(f32 *)(s + 0x44) = *(f32 *)(self + 0x18) - 6.8f;
        *(f32 *)(s + 0x74) = func_00382538();
        s[0x7F] = 15;
        func_L01_003F5E88(self);
        func_L01_004450F0(self, 0, 1);
    }
}
/* localdecomp:end func_L03_00399868 */

INCLUDE_ASM("asm/levels", func_L03_003998E8);

/* localdecomp:start func_L03_00399BD8 */
extern s32 func_00382498(s32, s32);

s32 func_L03_00399BD8(u8 *p, s32 n) {
    s32 i;
    s32 base;
    s32 r;

    base = func_00382498(0, n - 1);
    for (i = 0; i < n; i++) {
        r = (base + i) % n;
        if ((((*p >> r) ^ 1) & 1)) {
            *p |= 1 << r;
            return r;
        }
    }
    return -1;
}
/* localdecomp:end func_L03_00399BD8 */

/* localdecomp:start func_L03_00399C68 */
extern s32 func_L01_004AAC98(s32, s32, u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L03_00399C68(u8 *obj, s32 a1, s32 a2, s32 a3)
{
    if (obj[0x95] == 1) {
        u8 *m = *(u8 **)(obj + 0x68);
        m[0x7C] = a1;
        m[0x7D] = a2;
        m[0x7E] = a3;
        *(s32 *)(m + 0x5C) = func_L01_004AAC98(0, 4, obj, 0x18EC);
        func_L01_004450F0(obj, 0, 2);
    }
}
/* localdecomp:end func_L03_00399C68 */

/* localdecomp:start func_L03_00399CE0 */
void func_L03_00399CE0(u8 *self) {
    if (self[0x95] != 0) {
        u8 *p = *(u8 **)(self + 0x68);
        *(f32 *)(self + 0x18) = *(f32 *)(p + 0x40);
        p[0x7F] = 15;
        func_L01_004450F0(self, 0, 1);
    }
}
/* localdecomp:end func_L03_00399CE0 */
