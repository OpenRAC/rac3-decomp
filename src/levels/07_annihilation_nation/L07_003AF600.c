#include "common.h"
#include "structs/moby.h"
#include "vu0.h"

/* localdecomp:start func_L07_003AF600 */
void func_0038CB78(s32, s32, s32);
void func_L01_0043A430(void *, s32, s32);
void func_L01_004450F0(void *, s32, s32);
void func_L01_004AA760(s32, void *);

void func_L07_003AF600(void *arg0) {
    s32 temp_s0;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        temp_s0 = (*(s32 *)((u8 *)arg0 + 0x68)) + 0x90;
        func_0038CB78(temp_s0, 0, 0x40);
        func_L01_0043A430(arg0, 0, temp_s0);
        func_L01_004AA760(1, arg0);
        func_L01_004450F0(arg0, 1, -1);
    }
}
/* localdecomp:end func_L07_003AF600 */

/* localdecomp:start func_L07_003AF678 */
typedef struct {
    u8 pad[0x144];
    void *w144;
    s32 w148;
} Pool_003AF678;
extern u8 D_L07_001E1EC0[];

extern s32 func_L01_00456250(void *);
extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L07_003AFC10(void *);

void func_L07_003AF678(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);

    if ((u32)(arg0[0x20] - 2) < 2 || func_L01_00456250(arg0) != 0) {
        func_L01_00456C98(arg0, 0.0f, 0.0f, 1.0f, *(s32 *)(p + 0xD0), 0, 1, 0, 0, 1,
                          0, 0, 0);
    }
    if (arg0[0x31] != 0) {
        func_L01_00404A10(func_L07_003AFC10, arg0);
    }
    if ((u32)(arg0[0x20] - 2) < 4) {
        if (((Pool_003AF678 *)D_L07_001E1EC0)->w144 == 0) {
            ((Pool_003AF678 *)D_L07_001E1EC0)->w144 = arg0;
            ((Pool_003AF678 *)D_L07_001E1EC0)->w148 = 0;
        }
    } else {
        if (((Pool_003AF678 *)D_L07_001E1EC0)->w144 == arg0) {
            ((Pool_003AF678 *)D_L07_001E1EC0)->w144 = 0;
        }
    }
}
/* localdecomp:end func_L07_003AF678 */

/* localdecomp:start func_L07_003AF758 */
extern s32 D_001A71A4[];
extern s32 func_L01_00456250(void *);
s32 func_L07_003AF758(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    s32 v;
    if (D_001A71A4[0] == 0x74) {
        return 0;
    }
    v = *(s16 *)(p + 0x44);
    if (v != 1) {
        return 0;
    }
    if (func_L01_00456250(arg0) == 0) {
        v = 0;
    }
    return v;
}
/* localdecomp:end func_L07_003AF758 */

/* localdecomp:start func_L07_003AF7B8 */
extern void func_0038D750(void *, s32, f32);
extern void func_0038D688(void *, void *, void *);
void func_L07_003AF7B8(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    f32 m[4];
    ((void (*)(void *, s32))func_0038D750)(m, 1);
    func_0038D688(p + 0xA0, p + 0xA0, m);
}
/* localdecomp:end func_L07_003AF7B8 */

/* localdecomp:start func_L07_003AF7F8 */
typedef int Q_003AF7F8 __attribute__((mode(TI)));
void func_L07_003AF7F8(u8 *self) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_L01_00448728(s32, f32, s32, f32, f32, f32, s32);
    Q_003AF7F8 position;
    u8 *state = *(u8 **)(self + 0x68);
    f32 yaw, pitch;
    position = *(Q_003AF7F8 *)(state + 0x30);
    ((f32 *)&position)[2] += -0.75f;
    yaw = func_0038DB00(func_0038D160(((f32 *)&position)[0] - *(f32 *)(self + 0x10),
                                  ((f32 *)&position)[1] - *(f32 *)(self + 0x14)), 1.57079637f);
    pitch = func_0038D160(func_0038CF38(self + 0x10, &position),
                         ((f32 *)&position)[2] - *(f32 *)(self + 0x18));
    func_L01_00448728((s32)(self + 0xF8), yaw, (s32)(state + 0xDC), 0.000720000069f, 0.0144000007f, 0.0f, 0);
    func_L01_00448728((s32)(self + 0xF0), pitch, (s32)(state + 0xD8), 0.000720000069f, 0.0144000007f, 0.0f, 0);
}
/* localdecomp:end func_L07_003AF7F8 */

/* localdecomp:start func_L07_003AF920 */
#include "vu0.h"
extern f32 D_L07_001DE438, D_L07_001DE43C, D_L07_001DE440;
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
__asm__(".extern D_L07_001DE438, 4");
__asm__(".extern D_L07_001DE43C, 4");
__asm__(".extern D_L07_001DE440, 4");
void func_L07_003AF920(u8 *self) {
    extern void func_003C2EC0(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L07_003CAE10(void *, void *, void *, s32, s32, s32, u32, f32, f32);
    extern void func_L01_0046B458(void *, s32, u32, s32, s32, void *, s32, f32, f32, f32);
    extern void func_L01_00470C78(void *, s32, u32, s32, s32, void *, s32, s32, s32, s32, f32, f32);
    vu0_v4 matrix[4], direction, point, sum, position, particle;
    u8 *state = *(u8 **)(self + 0x68);
    func_003C2EC0(self, 1, matrix);
    *(vu0_q *)&direction = *(vu0_q *)&matrix[1];
    *(vu0_q *)&point = *(vu0_q *)&matrix[3];
    func_0038CF68(&direction, &direction, D_L07_001DE438 * 0.020000001415610313f);
    *(vu0_q *)&position = *(vu0_q *)&matrix[3];
    *(vu0_q *)&particle = *(vu0_q *)&matrix[3];
    vec_add_ab(&sum, &position, &direction);
    func_L07_003CAE10(&position, &direction, self, 0, 0, -1, 0xFFFFFFFFu, D_L07_001DE43C, (f32)state[0x64]);
    func_L01_0046B458(&particle, 7, 0xBF204080, 2, 1, D_L07_001D66B0, 1, D_L07_001DE440 * 7.0f, 0.1f, 0.0f);
    func_L01_0046B458(&particle, 7, 0xBF2040A0, 2, -1, D_L07_001D66B0, 1, D_L07_001DE440 * 5.0f, 0.1f, 0.0f);
    func_L01_0046B458(&particle, 7, 0xC0FFFFFF, 2, 1, D_L07_001D66B0, 1, D_L07_001DE440 * 3.5f, 0.1f, 0.0f);
    func_L01_0046B458(&particle, 7, 0xB0FFFFFF, 2, -1, D_L07_001D66B0, 1, D_L07_001DE440 * 2.5f, 0.1f, 0.0f);
    func_L01_00470C78(&particle, 6, 0x46787878, 2, 2, D_L07_001D66B0, 0, 2, 6, 1, 1.08f, 0.8400000333786011f);
    func_L01_00470C78(&particle, 8, 0x46787878, 2, -1, D_L07_001D66B0, 1, 2, 6, 1, 2.0400002002716064f, 0.8400000333786011f);
    func_L01_00470C78(&particle, 8, 0x2D787878, 2, 1, D_L07_001D66B0, 1, 2, 6, 1, 2.4000000953674316f, 1.8000000715255737f);
}
/* localdecomp:end func_L07_003AF920 */

/* localdecomp:start func_L07_003AFC10 */
typedef int Quad_003AFC10 __attribute__((mode(TI)));
void func_L07_003AFC10(void *arg0) {
    extern void func_0038CC88(void *, void *, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003D9740(void *, s32, u32, s32, s32, f32);
    Quad_003AFC10 m[4];
    u8 *self = arg0;
    u8 *p = *(u8 **)(self + 0x68);
    *(f32 *)(p + 0xE0) += 0.066f;
    if (*(f32 *)(p + 0xE0) >= 7.0f)
        *(f32 *)(p + 0xE0) -= 7.0f;
    func_0038CC88(m, self + 0xC0, 0x30);
    m[3] = *(Quad_003AFC10 *)(self + 0x10);
    func_0038CE20(m, m, 2.2f);
    func_0038CE20(m + 1, m + 1, 2.2f);
    func_0038CE20(m + 2, m + 2, 2.2f);
    func_003D9740(m, 0x15, 0x20FF8080, 8, 1, *(f32 *)(p + 0xE0));
    func_003D9740(m, 0x2B, 0x20FF8080, 8, 1, *(f32 *)(p + 0xE0));
}
/* localdecomp:end func_L07_003AFC10 */

/* localdecomp:start func_L07_003AFD10 */
typedef struct {
    u8 pad[0x80];
    f32 x, y;
} Hero_003AFD10;
extern Hero_003AFD10 D_001A4BE0_003AFD10;
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern s32 func_L07_003B05B0(void *);
extern void func_003C2880(void *);
extern s32 func_L01_004561B8(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_00448890(char *a0, char *a1, int a2, float f12, float f13,
                              float f14, float f15);
extern void func_L07_003B0738(u8 *);
extern void func_L07_003B0660(u8 *);
extern void func_L01_00404A10(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_0038CF68_003AFD10(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_003AA018(void *, void *, void *, s32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L07_003B0970(u8 *);

static __inline__ void release_003AFD10(u8 *self, u8 *p) {
    s32 index = *(s32 *)(p + 0x7C);
    if (index != -1) {
        u8 *slot = D_001A30B0 + index * 128;
        if (*(u8 **)(slot + 0xDC) == self && slot[0xD0])
            func_003A4F28(index);
    }
    *(s32 *)(p + 0x7C) = -1;
}

void func_L07_003AFD10(u8 *self) {
    vu0_v4 position, direction;
    u8 *p = *(u8 **)(self + 0x68);
    f32 angle;

    if (func_L07_003B05B0(self)) {
        func_003C2880(self);
        return;
    }
    switch (self[0x20]) {
    case 1:
        if (func_L01_004561B8(self) && self[0x43] != 0)
            func_003C3A10(self, 0, 0, 8);
        if (*(s32 *)(p + 0x80) != -1 ? func_L01_00456500(D_001A4C60, *(s32 *)(p + 0x80))
                                     : func_0038CF38(self + 0x10, D_001A4C60) < *(f32 *)(p + 0x84))
            func_L01_004450F0(self, 2, -1);
        break;
    case 2:
        if (func_L01_004561B8(self)) {
            s32 index = *(s32 *)(p + 0x7C);
            u8 *slot;
            if (index == -1 || (slot = D_001A30B0 + index * 128, *(u8 **)(slot + 0xDC) != self) || !slot[0xD0])
                *(s32 *)(p + 0x7C) = ((s32 (*)(s32, s32, void *))func_003A52A0)(3, 4, self);
            if (self[0x43] != 1)
                func_003C3A10(self, 1, 0, 0);
        }
        if (self[0x60] & 2) {
            release_003AFD10(self, p);
            func_L01_004450F0(self, 4, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(self) && self[0x43] != 2)
            func_003C3A10(self, 2, 0, 0);
        if (func_0038DBA0(*(f32 *)(self + 0xF8), *(f32 *)(p + 0x90)) <= 0.017453292f)
            func_L01_004450F0(self, 7, -1);
        else
            ((void (*)(void *, void *, f32, f32, f32, f32, s32))func_L01_00448890)(self + 0xF8, p + 0x94, *(f32 *)(p + 0x90), 0.004f, 0.004f, 0.6f, 0);
        break;
    case 4:
        if (func_L01_004561B8(self)) {
            s32 index = *(s32 *)(p + 0x7C);
            u8 *slot;
            if (index == -1 || (slot = D_001A30B0 + index * 128, *(u8 **)(slot + 0xDC) != self) || !slot[0xD0])
                *(s32 *)(p + 0x7C) = ((s32 (*)(s32, s32, void *))func_003A52A0)(0, 4, self);
            if (self[0x43] != 2)
                func_003C3A10(self, 2, 0, 0);
            *(s32 *)(p + 0xA0) = 50;
        }
        angle = func_0038DB00(func_0038D160(D_001A4BE0_003AFD10.x - *(f32 *)(self + 0x10),
                                            D_001A4BE0_003AFD10.y - *(f32 *)(self + 0x14)),
                              *(f32 *)(p + 0x90));
        if (angle > 0.7853982f)
            angle = 0.7853982f;
        else if (angle < -0.7853982f)
            angle = -0.7853982f;
        angle = func_0038DAB8(*(f32 *)(p + 0x90), angle);
        ((void (*)(void *, void *, f32, f32, f32, f32, s32))func_L01_00448890)(self + 0xF8, p + 0x94, angle, 0.004f, 0.004f, 0.6f, 0);
        func_L07_003B0738(self);
        func_L01_00404A10(func_L07_003B0660, self);
        if (func_0038CAD0(p + 0xA0)) {
            release_003AFD10(self, p);
            func_L01_004450F0(self, 5, -1);
        } else {
            angle = func_0038DBA0(func_0038D160(D_001A4BE0_003AFD10.x - *(f32 *)(self + 0x10),
                                                D_001A4BE0_003AFD10.y - *(f32 *)(self + 0x14)),
                                  *(f32 *)(p + 0x90));
            if (angle > 1.5707964f || *(s32 *)(p + 0x88) != -1) {
                if (func_L01_00456500(&D_001A4BE0_003AFD10.x, *(s32 *)(p + 0x88)))
                    break;
            } else if (!(func_0038CF38(self + 0x10, &D_001A4BE0_003AFD10.x) > *(f32 *)(p + 0x8C))) {
                break;
            }
            release_003AFD10(self, p);
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(self)) {
            s32 index = *(s32 *)(p + 0x7C);
            u8 *slot;
            if (index == -1 || (slot = D_001A30B0 + index * 128, *(u8 **)(slot + 0xDC) != self) || !slot[0xD0])
                *(s32 *)(p + 0x7C) = ((s32 (*)(s32, s32, void *))func_003A52A0)(1, 4, self);
            if (self[0x43] != 3)
                func_003C3A10(self, 3, 0, 0);
            *(s32 *)(p + 0xA0) = 50;
            func_0038CF68_003AFD10(&direction, self + 0xC0, 1.0000001f);
            func_003C2F58(self, 1, &position);
            func_L01_003AA018(self, &direction, &position, 1, (f32)p[0x44]);
        }
        if (func_0038CAD0(p + 0xA0)) {
            release_003AFD10(self, p);
            func_L01_004450F0(self, 4, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(self)) {
            p[0xA8] = 1;
            if (self[0x43] != 4)
                func_003C3A10(self, 4, 0, 0);
        }
        if (self[0x60] & 2)
            func_L01_004450F0(self, 7, -1);
        break;
    case 7:
        if (func_L01_004561B8(self)) {
            s32 index = *(s32 *)(p + 0x7C);
            u8 *slot;
            if (index == -1 || (slot = D_001A30B0 + index * 128, *(u8 **)(slot + 0xDC) != self) || !slot[0xD0])
                *(s32 *)(p + 0x7C) = ((s32 (*)(s32, s32, void *))func_003A52A0)(3, 4, self);
            if (self[0x43] != 0)
                func_003C3A10(self, 0, 0, 8);
            *(s32 *)(p + 0xA0) = 10;
        }
        if (p[0xA8])
            func_L07_003B0970(self);
        if (func_0038CAD0(p + 0xA0)) {
            release_003AFD10(self, p);
        }
        break;
    }
}
/* localdecomp:end func_L07_003AFD10 */

/* localdecomp:start func_L07_003B0458 */
void func_L07_003B0530(void *);

void func_L07_003B0458(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x20) == 0) {
        u8 *s;
        u8 *p;
        s32 i;

        f32 f;
        u8 one;

        s = (u8 *)(*(s32 *)((u8 *)arg0 + 0x68));
        f = *(f32 *)((u8 *)arg0 + 0xF8);
        one = 1;
        s[0x3E] = 3;
        *(f32 *)(s + 0x90) = f;
        p = s + 0x44;
        s[0x3F] = 0;
        s[0x64] = 0;
        *(s32 *)(s + 0x94) = 0;
        i = 0;
        do {
            *p = one;
            p--;
            i--;
        } while (i >= 0);
        func_L07_003B0530(arg0);
    }
}
/* localdecomp:end func_L07_003B0458 */

/* localdecomp:start func_L07_003B04C8 */
void func_L07_003B04C8(u8 *a0, s32 a1) {
    u8 *base;
    u8 *a24;
    s32 f34;
    s32 t;
    s32 v;

    base = *(u8 **)(a0 + 0x68);
    if (*(u8 *)(base + a1 + 0x70) != 0) {
        f34 = *(u16 *)(a0 + 0x34);
        a24 = *(u8 **)(a0 + 0x24);
        t = f34 & 0xFFBE;
        *(u16 *)(a0 + 0x34) = t;
        t = t | (*(u16 *)(a24 + 0x44) & 0x1000);
        *(u16 *)(a0 + 0x34) = t;
        t = t & 0xFFFD;
        v = *(s32 *)(a24 + 0x10);
        *(u16 *)(a0 + 0x34) = t;
        *(s32 *)(a0 + 0x98) = v;
        base[0xA8] = 0;
        func_L01_004450F0(a0, 1, -1);
    }
}
/* localdecomp:end func_L07_003B04C8 */

/* localdecomp:start func_L07_003B0530 */
void func_L01_004AA7E8(void *, s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003B0530(void *a0) {
    u8 *arg0 = (u8 *)a0;
    u8 *v1;

    *(s32 *)(arg0 + 0x98) = 0;
    v1 = *(u8 **)(arg0 + 0x68);
    *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x43) & 0xEFFF;
    *(u8 *)(arg0 + 0xA8) = 0xFF;
    func_L01_004AA7E8(arg0, 1);
    *(f32 *)(arg0 + 0xF8) = *(f32 *)(v1 + 0x90);
    *(s32 *)(v1 + 0x94) = 0;
    func_L01_004450F0(arg0, 8, -1);
}
/* localdecomp:end func_L07_003B0530 */

/* localdecomp:start func_L07_003B05A0 */
s32 func_L07_003B05A0(void *arg0) {
    return (u32) ((*(u8 *)((u8 *)arg0 + 0x20)) - 7) < 2U;
}
/* localdecomp:end func_L07_003B05A0 */

/* localdecomp:start func_L07_003B05B0 */
s32 func_L01_00447490(void *, s32, s32);
void func_L01_00456BD0(void *, s32);
void func_L07_003B0458(void *);

s32 func_L07_003B05B0(void *arg0) {
    s32 kind = *(u8 *)((u8 *)arg0 + 0x20);

    if (kind == 0) {
        func_L07_003B0458(arg0);
        return 0;
    }
    kind -= 4;
    if ((u8)kind >= 2) {
        *(u8 *)((u8 *)arg0 + 0xA8) = 0xFF;
        *(u16 *)((u8 *)arg0 + 0x34) &= 0xEFFF;
        return 0;
    }
    {
        s32 r;

        *(u16 *)((u8 *)arg0 + 0x34) |= 0x1000;
        r = func_L01_00447490(arg0, 0x30000, 0);
        if (r != 0) {
            *(u8 *)((u8 *)arg0 + 0xA8) = 0xFF;
            func_L01_004450F0(arg0, 6, -1);
        }
        func_L01_00456BD0(arg0, 3);
        return 0;
    }
}
/* localdecomp:end func_L07_003B05B0 */

/* localdecomp:start func_L07_003B0660 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003B0660;

extern void func_003C2F58(void *, s32, void *);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L07_003B0660(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    V4_003B0660 v;
    f32 s1;
    f32 s2;

    s1 = (1.0f - (f32) * (s32 *)(p + 0xA0) / 50.0f) * 3.0f;
    func_003C2F58(arg0, 1, &v);
    func_003D9508(&v, 0x31, 0x60208040, 1, s1, 0.5f, func_00382538());
    s2 = s1 * 0.4f;
    func_003D9508(&v, 0x31, 0x7F208040, 1, s2, 0.5f, func_00382538());
}
/* localdecomp:end func_L07_003B0660 */

/* localdecomp:start func_L07_003B0738 */
#include "vu0.h"

typedef struct V4_3B0738 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_3B0738;
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_00382498(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);

void func_L07_003B0738(u8 *obj) {
    V4_3B0738 w;
    V4_3B0738 q;
    u8 *vars;
    f32 t;
    f32 scale;
    f32 ang;
    s32 n;
    s32 i;
    s32 s;

    vars = *(u8 **)(obj + 0x68);
    t = 1.0f - (f32) * (s32 *)(vars + 0xA0) / 50.0f;
    n = (s32)(t * 4.0f + 2.0f);
    scale = (t * 0.8f + 0.2f) * 12.0f;
    for (i = 0; i < n; i++) {
        {
            ang = func_0038DAB8(*(f32 *)(obj + 0xF8), func_003824E0(-0.7853982f, 0.7853982f));
            func_00382760(&w, scale, ang, func_003824E0(-0.7853982f, 0.7853982f));
            func_003C2F58(obj, 1, &q);
            if (*(s32 *)(vars + 0xA0) < (func_00382498(0x14, 0x28) * 5 + 2) / 6) {
                s = *(s32 *)(vars + 0xA0);
            } else {
                s = (func_00382498(0x14, 0x28) * 5 + 2) / 6;
            }
            vec_add_ab(&q, &q, &w);
            func_0038CE20(&w, &w, -1.0f / (f32)s);
            func_L01_00474078(&q, &w, s, 0.15f, 0.75f, 1.2f, 1.0f, 0x8020FF40, 0x40A0FFA0, 0, 0);
        }
    }
}
/* localdecomp:end func_L07_003B0738 */

/* localdecomp:start func_L07_003B0970 */
#include "vu0.h"
extern s32 D_L07_001DEF40;
void func_L07_003B0970(u8 *obj) {
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_004668A0(void *, void *, u32, s32, f32, s32);
    vu0_v4 pos, vel, temp;
    f32 angle, radius, speed, height, size;
    u32 color, green;
    vu0_v4 *velocity;
    s32 c;
    s32 life;
    if (D_L07_001DEF40 & 3) {
        *(vu0_q *)&pos = *(vu0_q *)(obj + 0x10);
        pos.z += 0.5f;
        angle = func_00382538();
        radius = func_003824E0(0.0f, 0.5f);
        pos.x += func_0038D098(angle) * radius;
        pos.y += func_0038D0B0(angle) * radius;
        speed = func_003824E0(0.010000000707805157f, 0.04000000283122063f);
        height = func_003824E0(0.04000000283122063f, 0.08000000566244125f);
        *(vu0_q *)&temp = 0;
        temp.x = speed * func_0038D098(angle);
        temp.y = speed * func_0038D0B0(angle);
        temp.z = height;
        *(vu0_q *)&vel = *(vu0_q *)&temp;
        c = func_00382498(8, 16) & 0xFF;
        green = (c << 8) | 0x80000000;
        color = (c << 16) | green | c;
        velocity = &vel;
        size = func_003824E0(315000.0f, 630000.0f);
        func_L01_004668A0(&pos, velocity, color, 0x101010, size, func_00382498(50, 67));
    }
}
/* localdecomp:end func_L07_003B0970 */

/* localdecomp:start func_L07_003B0B08 */
void func_L07_003B0B08(u8 *self)
{
    extern void func_L07_003B0CF8(u8 *);
    extern void func_L01_004AA760(s32, void *);
    extern void func_L07_003B0FE0(u8 *);
    extern void func_L07_003B0F20(u8 *);
    extern void func_L07_003B0E08(void *, s32);
    extern s32 func_L07_003B12D8(u8 *);
    extern void func_L07_003B13E8(u8 *);
    extern f32 func_003C3BE8(f32, f32, f32);
    extern void func_003C7C38(void *);
    u8 *vars;
    func_L07_003B0CF8(self);
    vars=*(u8 **)(self+0x68);
    switch (self[0x20]) {
    case 3:
        if(self[0x60]&2) {
            func_L01_004AA760(0,self);
            func_L07_003B0FE0(self);
            func_L07_003B0E08(self,4);
        } else func_L07_003B0F20(self);
        break;
    case 4:
        *(f32 *)(vars+0x48)+=0.012f;
        if(*(f32 *)(vars+0x48)>=1.0f) {
            *(f32 *)(vars+0x48)=1.0f;
            func_L01_004AA760(1,self);
            func_L07_003B0E08(self,2);
        }
        *(f32 *)(*(u8 **)(vars+0x44)+0xf0)=func_003C3BE8(0.0f,-1.5707964f,*(f32 *)(vars+0x48));
        func_003C7C38(*(void **)(vars+0x44));
        break;
    case 2:
        if(func_L07_003B12D8(self)) func_L07_003B0E08(self,5);
        break;
    case 5: {
        f32 zero;
        if(!func_L07_003B12D8(self)) {
            func_L07_003B0E08(self,4);
            break;
        }
        zero = 0.0f;
        *(f32 *)(vars+0x48)-=0.012f;
        if(*(f32 *)(vars+0x48)<=zero) {
            *(f32 *)(vars+0x48)=zero;
            func_L01_004AA760(1,self);
            func_L07_003B0E08(self,6);
        }
        *(f32 *)(*(u8 **)(vars+0x44)+0xf0)=func_003C3BE8(zero,-1.5707964f,*(f32 *)(vars+0x48));
        func_003C7C38(*(void **)(vars+0x44));
        break;
    }
    case 6:
        if(self[0x60]&2) {
            func_L01_004AA760(0,self);
            func_L07_003B13E8(self);
            func_L07_003B0E08(self,1);
        } else func_L07_003B0F20(self);
        break;
    case 1: break;
    }
}
/* localdecomp:end func_L07_003B0B08 */

/* localdecomp:start func_L07_003B0CF8 */
#include "vu0.h"
void func_L07_003B0CF8(u8 *self) {
    extern void func_003C2F58(void *, s32, void *);
    extern u8 *func_003C24B0(s32, s32);
    extern void func_003C7C38(void *);
    extern void func_L07_003B0F78(void *);
    extern void func_L07_003B0FC0(void *);
    vu0_q position;
    u8 *child;
    u8 *state;
    if (self[0x20] == 0) {
        state = *(u8 **)(self + 0x68);
        func_003C2F58(self, 0, &position);
        child = func_003C24B0(0x1172, 0x80);
        if (child) {
            *(u16 *)(child + 0x34) |= 7;
            child[0x30] = self[0x30];
            *(u16 *)(child + 0x32) = 0;
            *(vu0_q *)(child + 0x10) = position;
            *(f32 *)(child + 0xF8) = *(f32 *)(self + 0xF8);
            func_003C7C38(child);
        }
        *(u8 **)(state + 0x40) = child;
        child = func_003C24B0(0x1D6D, 0x80);
        if (child) {
            *(u16 *)(child + 0x34) |= 6;
            child[0x30] = self[0x30];
            *(u16 *)(child + 0x32) = *(u16 *)(self + 0x32);
            child[0x31] = 1;
            *(unsigned long *)(child + 0x38) = *(unsigned long *)(self + 0x38);
            *(vu0_q *)(child + 0x10) = position;
            *(f32 *)(child + 0xF8) = *(f32 *)(self + 0xF8);
            func_003C7C38(child);
        }
        *(u8 **)(state + 0x44) = child;
        *(void (**)(void *))(state + 4) = func_L07_003B0F78;
        *(void (**)(void *))(state + 8) = func_L07_003B0FC0;
        func_L07_003B0F78(self);
    }
}
/* localdecomp:end func_L07_003B0CF8 */

/* localdecomp:start func_L07_003B0E08 */
void func_L07_003B0E08(void *self,s32 state) {
 extern void func_L01_004AAC98(s32,s32,void *,s32);
 extern void func_003C3A10(void *,s32,s32,s32);
 extern void func_L01_004450F0(void *,s32,s32);
 u8 *m=self;
 switch(state) {
 case 1:
  if(m[0x43]!=0)func_003C3A10(m,0,0,0);
  break;
 case 3:
  func_L01_004AAC98(0,4,m,0x19E7);
  if(m[0x43]!=1)func_003C3A10(m,1,0,0);
  break;
 case 4:case 5:
  func_L01_004AAC98(1,4,m,0x19E7);
 case 2:
  if(m[0x43]!=2)func_003C3A10(m,2,0,0);
  break;
 case 6:
  func_L01_004AAC98(0,4,m,0x19E7);
  if(m[0x43]!=3)func_003C3A10(m,3,0,0);
  break;
 }
 func_L01_004450F0(m,state,-1);
}
/* localdecomp:end func_L07_003B0E08 */

/* localdecomp:start func_L07_003B0F20 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B0F20;
extern void func_003C2F58(void *, s32, void *);
extern void func_003C7C38(void *);
void func_L07_003B0F20(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    V4_003B0F20 v;
    func_003C2F58(arg0, 0, &v);
    *(V4_003B0F20 *)(*(u8 **)(p + 0x40) + 0x10) = v;
    func_003C7C38(*(u8 **)(p + 0x40));
    *(V4_003B0F20 *)(*(u8 **)(p + 0x44) + 0x10) = v;
    func_003C7C38(*(u8 **)(p + 0x44));
}
/* localdecomp:end func_L07_003B0F20 */

/* localdecomp:start func_L07_003B0F78 */
void func_003C7C38(void *);
void func_L07_003B0E08(void *, s32);

void func_L07_003B0F78(void *arg0) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    *(s32 *)((u8 *)temp_v0 + 0x48) = 0;
    *(s32 *)((u8 *)((*(void **)((u8 *)temp_v0 + 0x44))) + 0xF0) = 0;
    func_003C7C38((*(void **)((u8 *)temp_v0 + 0x44)));
    func_L07_003B0E08(arg0, 1);
}
/* localdecomp:end func_L07_003B0F78 */

/* localdecomp:start func_L07_003B0FC0 */
/* from rac4-decomp's func_01EEBC54 */
void func_L07_003B0FC0(void *arg0) {
    func_L07_003B0E08(arg0, 3);
}
/* localdecomp:end func_L07_003B0FC0 */

INCLUDE_ASM("asm/levels", func_L07_003B0FE0);

/* localdecomp:start func_L07_003B12D8 */
extern s32 D_001A4F3C[];
extern u8 *func_L01_0045B958(u8 *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_003C2F58(void *, s32, void *);

s32 func_L07_003B12D8(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    f32 v[4];
    s32 i;
    s32 j;
    u8 *q;

    if (D_001A4F3C[0] == *(s32 *)(p + 0x40)) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        q = *(u8 **)(p + 0x20 + i * 4);
        if (q != 0 && q[0x20] >= 2 &&
            *(s32 *)(func_L01_0045B958(q) + 0x88) == *(s32 *)(p + 0x40)) {
            return 0;
        }
    }
    func_003C2F58(arg0, 1, v);
    for (j = 0; j < 4; j++) {
        q = *(u8 **)(p + 0x30 + j * 4);
        if (q != 0 && q[0x20] >= 2 &&
            func_L01_0040E548(q + 0x10, v) < 36.0f) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L07_003B12D8 */

/* localdecomp:start func_L07_003B13E8 */
#include "vu0.h"
typedef struct { u8 pad[4]; s16 damage; } Damage_003B13E8;
extern u8 *D_L07_001ECC80[];
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
void func_L07_003B13E8(u8 *self) {
    extern void func_003C2F58(void *, s32, void *);
    extern s32 func_003D4D00(void *, s32, f32, void *, void *);
    extern s32 func_L07_00333A18(u8 *);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_L01_0040E4C0(void *);
    extern Damage_003B13E8 *func_00382348(u8 *);
    extern void func_L01_00446A70(u8 *, u8 *, s32, void *, void *, f32);
    vu0_v4 position, diff, projection;
    s32 total;
    s32 count;
    u8 **list;
    func_003C2F58(self, 1, &position);
    total = func_003D4D00(&position, 9, 6.0f, 0, 0);
    if (total <= 0) return;
    list = D_L07_001ECC80;
    count = total;
    do {
        u8 *moby = *list;
        if (func_L07_00333A18(moby) && moby[0x20] != 1) {
            f32 dot;
            vec_sub_ab(&diff, moby + 0x10, &position);
            dot = func_0038CE68(&diff, self + 0xC0);
            if (fabs_asm(dot) < 3.5f) {
                func_0038CE20(&projection, self + 0xC0, dot);
                vec_sub_ab(&diff, &diff, &projection);
                if (func_L01_0040E4C0(&diff) < 19.36000061f) {
                    Damage_003B13E8 *damage = func_00382348(moby);
                    func_L01_00446A70(moby, self, 0x10000, moby + 0x10, D_L07_001D66B0, (f32)damage->damage);
                }
            }
        }
        --count;
        ++list;
    } while (count != 0);
}
/* localdecomp:end func_L07_003B13E8 */

/* localdecomp:start func_L07_003B1578 */
typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x20];
    u8 f20;
};

/* from rac4-decomp's func_L05_004E00A8, renamed, constants adapted */
s32 func_L07_003B1578(Type1 *arg0) {
    s32 var_a0;
    u8 temp_v1;
    temp_v1 = arg0->f20;
    var_a0 = 0;
    if ((temp_v1 == 4) || (temp_v1 == 2) || (temp_v1 == 5)) {
        var_a0 = 1;
    }
    return var_a0;
}
/* localdecomp:end func_L07_003B1578 */

/* localdecomp:start func_L07_003B15A8 */
typedef struct {
    f32 f00;
    f32 f04;
    f32 f08;
    u8 pad0C[4];
    f32 f10;
    f32 f14;
    f32 f18;
    u8 pad1C[4];
    u8 b20;
    u8 pad21[3];
    u8 b24;
    u8 pad25;
    u8 b26;
} Priv_003AFCF0;

typedef struct {
    u8 pad00[0x18];
    u8 *p18;
    s32 w1C;
    vu0_v4 v20;
} Glob_003AFCF0;

extern Glob_003AFCF0 D_L07_001E8C00;
extern u8 *D_001A71A0[];
extern void func_L07_003B1C08(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004CB320(void);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L01_004CB358(void);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_00446A70(s32, s32, s32, void *, void *, f32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L07_003B1A30(u8 *);
extern void func_L01_00404A10(void *, void *);
extern void func_003C2880(void *);

void func_L07_003B15A8(u8 *obj) {
    extern void func_0038CF68(void *, void *, f32);
    vu0_v4 v0;
    vu0_v4 v10;
    Priv_003AFCF0 *p;
    u8 *e;
    s32 hit;
    s32 w;

    p = *(Priv_003AFCF0 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0:
        p->f18 = func_0038DAB8(p->f18, 0.12566371262073517f);
        p->f10 = p->f10 + 1.6000001430511475f;
        func_0038CE20(&v0, obj + 0xC0, p->f10);
        w = *(s32 *)(obj + 0xB8);
        vec_add_ba(&v0, obj + 0x10, &v0);
        func_L01_004CB320();
        hit = func_003D3CB0(obj + 0x10, &v0, 0, w, 0);
        if (hit != 0) {
            e = D_L07_001E8C00.p18;
            if (e != 0 && *(s16 *)(e + 0xAA) == 0x186D && e[0x20] != 2 && e[0x20] != 5) {
                e[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit != 0) {
            p->f10 = func_0038CF00(obj + 0x10, &D_L07_001E8C00.v20);
            if (D_L07_001E8C00.w1C > 0) {
                *(vu0_q *)p = *(vu0_q *)&D_L07_001E8C00.v20;
                p->b24 = 1;
                p->f08 = p->f08 + 0.1f;
            }
            if (D_L07_001E8C00.p18 == D_001A71A0[0]) {
                func_0038CF68(&v10, obj + 0xC0, 0.10000000894069672f);
                func_L01_00446A70((s32)D_L07_001E8C00.p18, *(s32 *)(obj + 0xB8), 1, &D_L07_001E8C00.v20, &v10, (f32)p->b26);
                func_L01_00456230(*(void **)(obj + 0xB8), 1);
            }
            func_L01_004450F0(obj, 1, -1);
        } else {
            *(u16 *)(obj + 0x96) += 1;
            if (*(u16 *)(obj + 0x96) >= 0x33) {
                func_L01_004450F0(obj, 1, -1);
            }
        }
        func_L01_00404A10(func_L07_003B1C08, obj);
        break;
    case 1:
        if (p->f14 < 0.5f) {
            func_0038CE20(&v0, obj + 0xC0, p->f10);
            vec_add_ba(&v0, obj + 0x10, &v0);
            if (func_003D3CB0(obj + 0x10, &v0, 0, *(s32 *)(obj + 0xB8), 0) != 0) {
                if (D_L07_001E8C00.p18 == D_001A71A0[0]) {
                    func_0038CF68(&v10, obj + 0xC0, 0.10000000894069672f);
                    func_L01_00446A70((s32)D_L07_001E8C00.p18, *(s32 *)(obj + 0xB8), 1, &D_L07_001E8C00.v20, &v10, (f32)p->b26);
                    func_L01_00456230(*(void **)(obj + 0xB8), 1);
                }
            }
        }
        func_L07_003B1A30(obj);
        p->f18 = func_0038DAB8(p->f18, 0.12566371262073517f);
        p->f14 = p->f14 + 0.09600000083446503f;
        if (p->f14 >= 1.0f) {
            p->f14 = 1.0f;
            if (p->b24 != 0) {
                func_L01_004450F0(obj, 2, -1);
            } else {
                func_L01_004450F0(obj, 3, -1);
            }
        }
        func_L01_00404A10(func_L07_003B1C08, obj);
        break;
    case 2:
        if (func_L07_003B1A30(obj) != 0) {
            func_L01_004450F0(obj, 3, -1);
        }
        func_L01_00404A10(func_L07_003B1C08, obj);
        break;
    case 3:
        func_003C2880(obj);
        break;
    }
}
/* localdecomp:end func_L07_003B15A8 */

/* localdecomp:start func_L07_003B1958 */
typedef int Quad_003B1958 __attribute__((mode(TI)));
u8 *func_L07_003B1958(void *parent, Quad_003B1958 *position, f32 yaw, f32 pitch, u8 kind) {
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038D308(void *, void *);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    u8 *obj;
    u8 *state;
    obj = func_003C24B0(0x19F3, 0x80);
    if (obj != 0) {
        *(void **)(obj + 0xB8) = parent;
        state = *(u8 **)(obj + 0x68);
        *(Quad_003B1958 *)(obj + 0x10) = *position;
        *(f32 *)(obj + 0xF4) = pitch;
        *(f32 *)(obj + 0xF8) = yaw;
        *(s16 *)(obj + 0x32) = 0;
        obj[0x30] = 0xFF;
        func_0038D308(obj + 0xC0, obj + 0xF0);
        *(s32 *)(state + 0x10) = 0;
        *(f32 *)(state + 0x18) = func_00382538();
        *(f32 *)(state + 0x20) = func_003824E0(0.0f, 1.0f);
        state[0x26] = kind;
        func_L01_004450F0(obj, 0, -1);
    }
    return obj;
}
/* localdecomp:end func_L07_003B1958 */

/* localdecomp:start func_L07_003B1A30 */
extern u8 *D_L07_001ECC80[];
typedef struct { u8 pad[0x25C0]; u8 *hero; } HeroState_003B1A30;
extern HeroState_003B1A30 D_001A4BE0;
s32 func_L07_003B1A30(u8 *self) {
    extern s32 func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_00456230(void *, s32);
    u8 *p = *(u8 **)(self + 0x68);
    f32 radius;
    s32 count, remaining;
    u8 **list;
    if (p[0x24]) {
    if (*(f32 *)(p + 0x1C) < 1.6f) {
        radius = *(f32 *)(p + 0x1C);
        if (radius < 1.0f) radius *= 0.7f;
        else radius = 0.7f;
        count = func_L01_00446780(*(void **)(self + 0xB8), p, 1, 0, 1, 0, radius, (f32)p[0x26], 1.0f);
        if (count > 0) {
            list = D_L07_001ECC80;
            remaining = count;
            do {
                if (*list == D_001A4BE0.hero)
                    func_L01_00456230(*(void **)(self + 0xB8), 1);
                --remaining;
                ++list;
            } while (remaining);
        }
    }
    *(f32 *)(p + 0x20) += 0.096f;
    if (*(f32 *)(p + 0x20) > 1.0f) *(f32 *)(p + 0x20) -= 1.0f;
    if (!(*(f32 *)(p + 0x1C) < 1.0f)) {
        *(f32 *)(p + 0x1C) += 0.036000002175569534f;
        if (*(f32 *)(p + 0x1C) >= 2.0f) {
            *(f32 *)(p + 0x1C) = 2.0f;
            goto done;
        }
    } else {
        *(f32 *)(p + 0x1C) += 0.06000000238418579f;
        if (*(f32 *)(p + 0x1C) >= 1.0f) *(f32 *)(p + 0x1C) = 1.0f;
    }
    return 0;
    }
done:
    return 1;
}
/* localdecomp:end func_L07_003B1A30 */

INCLUDE_ASM("asm/levels", func_L07_003B1C08);

/* localdecomp:start func_L07_003B24C8 */
extern u8 D_001A4C60[];
extern u8 *D_L07_001DF41C;
void func_L07_003B24C8(u8 *obj)
{
    extern void func_0038D308(void *, void *);
    extern void func_L07_003B2870(u8 *);
    extern s32 func_00382380(void *, s32, s32);
    extern s32 func_L01_004561B8(void *);
    extern void func_L01_004AAC98(s32, s32, void *, s32);
    extern void func_L01_004AA760(s32, void *);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L07_003B2738(u8 *);
    u8 *s = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 0) {
        func_0038D308(obj + 0xC0, obj + 0xF0);
        func_L07_003B2870(obj);
    }
    switch (obj[0x20]) {
    case 1:
        if (*(s32 *)(s + 12) != -1 && func_00382380(D_001A4C60, *(s32 *)(s + 12), 0))
            obj[0xBE] |= 4;
        if (obj[0xBE] & 4) func_L01_004450F0(obj, 2, -1);
        break;
    case 2:
        if (func_L01_004561B8(obj)) {
            func_L01_004AAC98(0, 4, obj, 0x1D79);
            if (*(s32 *)(s + 16) != -1)
                ((u8 *)((s32)D_L07_001DF41C + (*(s32 *)(s + 16) << 8)))[0xBE] |= 4;
        }
        if (!(obj[0xBE] & 4)) {
            func_L01_004AA760(0, obj);
            func_L01_004450F0(obj, 4, -1);
            break;
        }
        *(f32 *)(s + 20) += 0.012f;
        if (*(f32 *)(s + 20) >= 1.0f) {
            *(f32 *)(s + 20) = 1.0f;
            func_L01_004AA760(0, obj);
            func_L01_004450F0(obj, 3, -1);
        }
        func_L07_003B2738(obj);
        break;
    case 3:
        if (!(obj[0xBE] & 4)) func_L01_004450F0(obj, 4, -1);
        break;
    case 4:
        if (func_L01_004561B8(obj)) {
            func_L01_004AAC98(0, 4, obj, 0x1D79);
            if (*(s32 *)(s + 16) != -1)
                ((u8 *)((s32)D_L07_001DF41C + (*(s32 *)(s + 16) << 8)))[0xBE] &= 0xFB;
        }
        if (obj[0xBE] & 4) {
            func_L01_004AA760(0, obj);
            func_L01_004450F0(obj, 2, -1);
            break;
        }
        *(f32 *)(s + 20) -= 0.012f;
        if (*(f32 *)(s + 20) <= 0.0f) {
            *(f32 *)(s + 20) = 0.0f;
            func_L01_004AA760(0, obj);
            func_L01_004450F0(obj, 1, -1);
        }
        func_L07_003B2738(obj);
        break;
    }
}
/* localdecomp:end func_L07_003B24C8 */

/* localdecomp:start func_L07_003B2738 */
#include "vu0.h"
#include "structs/moby.h"
extern u8 *D_L07_001DF41C;
void func_L07_003B2738(u8 *obj) {
    extern f32 func_003C3BE8(f32, f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C7C38(void *);
    struct Moby *m = (struct Moby *)obj;
    u8 *state = m->pvar;
    u8 *child = D_L07_001DF41C + (*(s32 *)state << 8);
    vu0_v4 v;
    f32 amount;
    *(f32 *)(child + 0x18) = m->position.z + *(f32 *)(state + 0x18) * func_003C3BE8(2.025f, 6.5f, *(f32 *)(state + 0x14));
    amount = func_003C3BE8(1.96f, 6.7f, *(f32 *)(state + 0x14));
    func_0038CE20(&v, &m->matrix[1], *(f32 *)(state + 0x18) * amount);
    v.z = *(f32 *)(state + 0x18) * -0.52f;
    { u8 *a = D_L07_001DF41C + (*(s32 *)(state + 4) << 8);
    vec_add_ab(a + 0x10, &m->position, &v);
    func_003C7C38(a); }
    v.x = -v.x;
    v.y = -v.y;
    { u8 *b = D_L07_001DF41C + (*(s32 *)(state + 8) << 8);
    vec_add_ab(b + 0x10, &m->position, &v);
    func_003C7C38(b); }
}
/* localdecomp:end func_L07_003B2738 */

/* localdecomp:start func_L07_003B2870 */
extern void func_L07_003B2738(u8 *);
void func_L07_003B2870(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    arg0[0xBE] &= ~4;
    *(s32 *)(p + 0x14) = 0;
    func_L07_003B2738(arg0);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003B2870 */

/* localdecomp:start func_L07_003B28B8 */
typedef struct {
    char _p0[0x20];
    u8 state;
} S_3B28B8;

/* from rac4-decomp's func_L01_0045B5D8 */
s32 func_L07_003B28B8(S_3B28B8 *arg0) {
    return arg0->state < 2;
}
/* localdecomp:end func_L07_003B28B8 */

/* localdecomp:start func_L07_003B28C8 */
#include "vu0.h"
extern void func_L07_003B3028(u8 *);
extern void func_L07_003B3160(u8 *);
extern s32 func_00382468(s32);
extern s32 func_L07_003A2380(u8, s32, u8, s16);
extern void func_L07_003B3798(u8 *, u8);
extern void func_L01_0045A9F0(void *);
extern s32 func_0038CB00(void *);
extern void func_L07_003B37D0(u8 *, s32);
extern void func_L01_0045A748(void *, void *);
extern void func_L07_003B4470(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L07_003B4370(u8 *);
extern void func_L07_003B3C78(void *);
extern void func_L07_003B4B68(void *, s16, f32);
extern void func_L07_003B3A88(struct Moby *, f32);
extern s32 func_L01_00456250(void *);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L07_003B4250(u8 *);
extern s32 func_L01_004468C8(void *, s32, f32, s32, f32, f32, s32, s32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L07_003B4308(u8 *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_003B28C8(u8 *self) {
    vu0_q stack[6];
    vu0_q *dst, *src;
    u8 *p;
    u8 *position;
    s32 i;
    if (self[0x20] == 0) func_L07_003B3028(self);
    func_L07_003B3160(self);
    p = *(u8 **)(self + 0x68);
    switch (self[0x95]) {
    case 0:
        if (*(f32 *)(p + 0x30) < (f32)*(s16 *)(p + 0x34) * 0.8f) {
            if (func_00382468(2)) {
                func_L07_003A2380(18, (s32)self, 0, 100);
                p[0x66B] |= 1;
            } else {
                func_L07_003A2380(19, (s32)self, 0, 100);
                p[0x66B] |= 2;
            }
            func_L07_003B3798(self, 1);
            p[0x668] = 255;
        }
        break;
    case 1:
        if (*(f32 *)(p + 0x30) < (f32)*(s16 *)(p + 0x34) * 0.5f) {
            func_L07_003A2380(21, (s32)self, 0, 100);
            func_L07_003B3798(self, 2);
            p[0x668] = 255;
        }
        break;
    case 2:
        if (*(f32 *)(p + 0x30) < (f32)*(s16 *)(p + 0x34) * 0.25f) {
            if (p[0x66B] & 1) {
                func_L07_003A2380(19, (s32)self, 0, 100);
                p[0x66B] |= 2;
            } else {
                func_L07_003A2380(18, (s32)self, 0, 100);
                p[0x66B] |= 1;
            }
            func_L07_003B3798(self, 3);
            p[0x668] = 255;
        }
        break;
    }
    switch (self[0x20]) {
    case 1: break;
    case 2:
        func_L01_0045A9F0(self);
        if (func_0038CB00(p + 0x19E)) func_L07_003B37D0(self, 3);
        break;
    case 3:
        func_L07_003B37D0(self, 4);
        break;
    case 4:
        position = self + 0x10;
        dst = stack;
        src = (vu0_q *)(p + 0x330);
        i = 5;
        do {
            *dst++ = *src++;
        } while (--i >= 0);
        func_L01_0045A748(self, *(u8 **)(p + 0x190) + 0x10);
        func_L07_003B4470(self, stack);
        if (func_L01_0040E570(position, *(u8 **)(p + 0x190) + 0x10) < 484.0f) {
            p[0x1AE] = 1;
            func_L07_003B37D0(self, 5);
        }
        break;
    case 5:
        func_L07_003B4370(self);
        break;
    case 6:
        if (func_0038CB00(p + 0x664)) {
            if (func_0038CB00(p + 0x660) ||
                func_L01_0040E570(self + 0x10, p + 0x80) < 196.0f) {
                func_L07_003B37D0(self, 7);
                break;
            }
        }
        func_L07_003B3A88((struct Moby *)self, 13.0f);
        break;
    case 7:
        func_L07_003B3C78(self);
        func_L07_003B4B68(self, *(s16 *)(self + 0x96), 1.0f);
        ++*(u16 *)(self + 0x96);
        func_L07_003B3A88((struct Moby *)self, 8.0f);
        if (func_L01_00456250(self)) {
            if (!*(s16 *)(p + 0x66E)) {
                if (func_00382468(20)) func_L07_003A2380(22, (s32)self, 0, 100);
                else func_L07_003A2380(26, (s32)self, 0, 100);
                *(s16 *)(p + 0x66E) = func_00382468(167) + 333;
            }
            func_L07_003B37D0(self, 8);
        } else {
            if (*(s16 *)(p + 0x660) == -1 || !func_0038CB00(p + 0x660)) break;
            if (self[0x95] == 3) func_L01_00456230(self, 1);
            func_L07_003B37D0(self, 8);
        }
        break;
    case 8:
        func_L07_003B3C78(self);
        func_L07_003B4B68(self, -1, (f32)*(s16 *)(p + 0x660) / 42.0f);
        if (func_0038CB00(p + 0x660)) {
            if (func_L01_00456250(self)) func_L07_003B37D0(self, 12);
            else func_L07_003B37D0(self, 5);
        }
        break;
    case 9:
        if (func_0038CB00(p + 0x664)) {
            if (func_0038CB00(p + 0x660) ||
                func_L01_0040E570(self + 0x10, p + 0x80) > 144.0f) {
                func_L07_003B37D0(self, 10);
                break;
            }
        }
        func_L07_003B3A88((struct Moby *)self, 13.0f);
        break;
    case 10:
        if (func_L01_004561B8(self)) {
            if (!*(s16 *)(p + 0x66C)) {
                if ((*(unsigned long *)(p + 0x668) & 0xC000000) == 0xC000000)
                    p[0x66B] &= 0xF3;
                if ((*(unsigned long *)(p + 0x668) & 0xC000000) == 0x4000000 ||
                    func_00382468(2)) {
                    func_L07_003A2380(24, (s32)self, 0, 100);
                    p[0x66B] |= 8;
                } else {
                    func_L07_003A2380(23, (s32)self, 0, 100);
                    p[0x66B] |= 4;
                }
                *(s16 *)(p + 0x66C) = func_00382468(250) + 500;
            }
            if (p[0x667] == 2) p[0x667] = 1;
            else if (p[0x667] == 1) p[0x667] = 2;
        }
        func_L01_0045A9F0(self);
        func_L07_003B4250(self);
        func_L01_004468C8(self, 13, 1.5f, 1, (f32)p[0x45], 1.5f, 0, 1, 0);
        if (func_L01_0044E1B8(self, 19.0f)) {
            func_L07_003B4308(self);
            --p[0x666];
            func_L07_003B37D0(self, 11);
        }
        break;
    case 11: {
        f32 size, range;
        func_L01_0045A9F0(self);
        func_L07_003B4250(self);
        size = 1.5f;
        range = 1.5f;
        func_L01_004468C8(self, 13, size, 1, (f32)p[0x45], range, 0, 1, 0);
        if (self[0x60] & 2) {
            if (!p[0x666]) {
                ++p[0x668];
                func_L07_003B37D0(self, 5);
            } else if (func_L01_00456250(self)) {
                ++p[0x668];
                func_L07_003B37D0(self, 12);
            } else {
                if (self[0x43] != 4) func_003C3A10(self, 4, 0, 0);
                func_L01_004450F0(self, 10, -1);
            }
        }
        break;
    }
    case 12:
        func_L07_003B3A88((struct Moby *)self, 17.0f);
        func_L07_003B4250(self);
        if (self[0x60] & 2) func_L07_003B37D0(self, 5);
        break;
    }
}
/* localdecomp:end func_L07_003B28C8 */

/* localdecomp:start func_L07_003B3028 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0044E7D8(void *);
extern void func_L07_003B34A0(u8 *);
extern void func_L07_003B3570(u8 *);

void func_L07_003B3028(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 t;

    *(f32 *)(p + 0x40) = 1.0f;
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    p[0x3E] = 3;
    *(u16 *)(p + 0x672) = *(u16 *)(p + 0x34);
    p[0x3F] = 0;
    p[0x64] = 0;
    t = *(u16 *)(a0 + 0xB6);
    p[0x39] = 0;
    *(s32 *)(p + 0xD4) = 0;
    *(f32 *)(p + 0xA0) = 3.0f;
    *(f32 *)(p + 0xA4) = 1.0f;
    *(f32 *)(p + 0xA8) = 1.5f;
    *(f32 *)(p + 0xAC) = 0.25f;
    *(f32 *)(p + 0xB0) = 3.1415927f;
    *(f32 *)(p + 0xD0) = 0.17453292f;
    *(f32 *)(p + 0xCC) = 0.00392f;
    *(u16 *)(p + 0x674) = t;
    func_L01_0045BD78(a0, 0.008f, 0.20000002f, 0.0025132743f, 0.06283186f);
    *(void **)(p + 0x194) = func_L07_003B3570;
    *(void **)(p + 0x198) = func_L07_003B34A0;
    *(u8 *)(p + 0x1AD) = 0xFF;
    *(s16 *)(p + 0x19C) = -1;
    *(s32 *)(p + 0x67C) = func_L01_0044E7D8(a0);
    func_L07_003B34A0(a0);
}
/* localdecomp:end func_L07_003B3028 */

/* localdecomp:start func_L07_003B3160 */
typedef struct { u8 b[16]; } Hit_003B3160;
extern f32 func_L01_004474E8(void *, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00459BE8(void *, s32, f32);
extern void func_003C4A40(void *, void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_0044E820(void *, s32);
extern void func_L01_00459C50(s32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_003A2450(void);
extern void func_L07_003315B0(void *);
extern s32 func_L07_00333D20(s32);
extern void func_L07_003B4DF8(u8 *);
extern void func_L02_003FB148(s32, s32, f32);
extern void func_L07_003B46E8(u8 *);

void func_L07_003B3160(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    Hit_003B3160 saved;
    f32 amount, previous;
    s32 hit;

    if (m[0x20] == 1) return;
    hit = func_L01_00447490(m, -1, 0);
    amount = func_L01_004474E8(m, hit);
    m[0xA8] = 255;
    if ((*(u16 *)(m + 0x34) & 0x4000) && amount > 0.0f) {
        func_003A52A0(7, 0, m);
        previous = *(f32 *)(p + 0x30);
        *(f32 *)(p + 0x30) = previous - amount;
        func_L01_00459BE8(m, p[0x47], amount);
        p[0x77] = 255;
        if (p[0x47] != 9 && p[0x47] != 25) p[0x676] = 0;
        func_003C4A40(m, p + 0x70);
        if (*(f32 *)(p + 0x30) < previous - (f32)*(s16 *)(p + 0x34) * 0.1f && *(s16 *)(p + 0x670) == 0) {
            func_L07_003A2380(20, (s32)m, 0, 100);
            *(s16 *)(p + 0x670) = func_00382468(125) + 250;
        }
    }
    func_L01_0044ABD0(m, p + 0x70);
    if (*(s16 *)(p + 0x70) == 0) func_L01_0044E820(m, *(s32 *)(p + 0x67C));
    if (*(f32 *)(p + 0x30) <= 0.0f) {
        if (p[0x676]) func_L01_00459C50(8);
        saved = *(Hit_003B3160 *)(p + 0x70);
        func_L01_0043B9E8(m, saved.b[4], saved.b[5], saved.b[6]);
        func_L01_00451FE0(m, 0x3FFF, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f,
                          255, 180, 0, 0, 35, 0, 3);
        func_L07_003A2450();
        func_L07_003A2380(81, (s32)m, 0, 100);
        func_L07_003315B0(m);
    } else if (p[0x5E]) {
        func_L07_003315B0(m);
        p[0x5E] = 0;
    } else if (p[0x60]) {
        func_L07_003315B0(m);
        p[0x60] = 0;
    } else {
        func_L01_00456BD0(m, 3);
        hit = func_L07_00333D20(*(s32 *)(p + 0x190));
        ((s32 (*)(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32))func_L01_00456C98)(
            m, 0.0f, 0.0f, 1.0f, hit, 0, 0, 0, 0, 1, 0, 0, 0);
        func_L07_003B4DF8(m);
        func_L02_003FB148(6, 0, *(f32 *)(p + 0x30) / (f32)*(s16 *)(p + 0x34));
        func_L07_003B46E8(m);
        func_0038CB00(p + 0x66C);
        func_0038CB00(p + 0x66E);
        func_0038CB00(p + 0x670);
    }
}
/* localdecomp:end func_L07_003B3160 */

/* localdecomp:start func_L07_003B34A0 */
extern u8 D_L07_001E1EC0[];
extern void func_003C2C98(void *, void *);
extern void func_L07_00334740(void *);
extern void func_L07_003B37D0(u8 *, s32);

void func_L07_003B34A0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    u8 *a = p + 0x1B0;
    u8 *b = p + 0x1B1;
    s32 i;

    for (i = 5; i >= 0; i--) {
        if (*b != 0) {
            func_003C2C98(arg0, a);
        }
        a += 0x40;
        b += 0x40;
    }
    if (p[0x391] != 0) {
        func_003C2C98(arg0, p + 0x390);
    }
    *(s32 *)(p + 0xD8) &= ~0x10;
    p[0x77] = 0;
    p[0x78] = 0;
    p[0x79] = 0;
    {
        u8 *g = D_L07_001E1EC0;

        if (*(u8 **)(g + 0x144) == arg0) {
            *(u8 **)(g + 0x144) = 0;
        }
    }
    func_L07_00334740(arg0);
    func_L07_003B37D0(arg0, 1);
}
/* localdecomp:end func_L07_003B34A0 */

/* localdecomp:start func_L07_003B3570 */
typedef struct { u8 pad[0x144]; void *obj; s32 count; } G_003B3570;
extern u8 D_001426E0[];
extern u8 D_00142660[];
extern u8 D_L07_001E1EC0[];
void func_L07_003B3570(u8 *obj) {
    extern s32 func_L01_0041A4F0(void);
    extern f32 func_L07_00334A98(s32);
    extern f32 func_L01_004DFE88(s32);
    extern void func_0038CB78(s32, s32, s32);
    extern void func_L01_0043A430(void *, s32, s32);
    extern void func_L07_003B4688(void *);
    extern void func_L07_00334800(void *);
    extern void func_L07_003B3798(u8 *, u8);
    extern void func_L07_003B37D0(u8 *, s32);
    u8 *p = *(u8 **)(obj + 0x68);
    f32 scale, health;
    s32 i;
    u8 *m;
    u8 *extra;
    G_003B3570 *g;
    u8 color;
    if (!D_001426E0[0x84]) {
        D_001426E0[0x84] = D_00142660[8];
        D_001426E0[0xD8] = D_00142660[0x40];
    }
    if (func_L01_0041A4F0()) scale = 5.0f;
    else scale = func_L07_00334A98(D_001426E0[0x84]);
    *(s16 *)(p + 0x34) = *(s16 *)(p + 0x672) * scale;
    health = scale * *(s16 *)(p + 0x674);
    *(f32 *)(p + 0x30) = *(s16 *)(p + 0x34);
    if (health > 65535.0f) health = 65535.0f;
    *(s16 *)(obj + 0xB6) = health;
    i = 0;
    extra = p + 0x390;
    color = (s32)(D_001426E0[0x84] / func_L01_004DFE88(D_001426E0[0xD8]) * 0.125f);
    p[0x44] = color; p[0x45] = color; p[0x46] = color;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
    m = p + 0x1B0;
    for (; i < 6; i++, m += 0x40) {
        func_0038CB78((s32)m, 0, 0x40);
        func_L01_0043A430(obj, i, (s32)m);
    }
    func_0038CB78((s32)extra, 0, 0x40);
    func_L01_0043A430(obj, 13, (s32)extra);
    func_L07_003B4688(obj);
    func_L07_00334800(obj);
    g = (G_003B3570 *)D_L07_001E1EC0;
    if (!g->obj) { g->obj = obj; g->count = 0; }
    p[0x668] = 0;
    p[0x66B] = 0;
    *(s16 *)(p + 0x66C) = 0;
    *(s16 *)(p + 0x66E) = 0;
    *(s16 *)(p + 0x670) = 0;
    p[0x676] = 1;
    func_L07_003B3798(obj, 0);
    func_L07_003B37D0(obj, 2);
}
/* localdecomp:end func_L07_003B3570 */

/* localdecomp:start func_L07_003B3798 */
extern void func_L07_003B37D0(u8 *, s32);

void func_L07_003B3798(u8 *arg0, u8 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    s32 s = p[0x1AE] == 0 ? 4 : 5;

    arg0[0x95] = arg1;
    func_L07_003B37D0(arg0, s);
}
/* localdecomp:end func_L07_003B3798 */

/* localdecomp:start func_L07_003B37D0 */
void func_L07_003B37D0(u8 *obj, s32 state) {
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L01_00456230(void *, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    u8 *p = *(u8 **)(obj + 0x68);
    switch (state) {
    case 1: case 3: break;
    case 2:
        if (obj[0x43] != 1) func_003C3A10(obj, 1, 0, 0);
        break;
    case 4:
        *(f32 *)(p + 0xC8) = 0.20000001788139343f;
        *(u16 *)(obj + 0x34) |= 0x5000;
        break;
    case 5:
        *(s16 *)(p + 0x664) = ((func_00382468(10) + 20) * 5 + 2) / 6;
        if (obj[0x95] >= 2) {
            if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 2);
        } else {
            if (obj[0x43] != 1) func_003C3A10(obj, 1, 0, 2);
        }
        *(f32 *)(p + 0xC8) = 0.20000001788139343f;
        *(s32 *)(p + 0xD8) |= 0x10;
        break;
    case 6:
        *(s16 *)(p + 0x660) = ((func_00382468(30) + 60) * 5 + 2) / 6;
        break;
    case 7:
        func_L01_00456230(obj, 0);
        p[0x66A] = 0;
        *(f32 *)(p + 0xC8) = (func_003824E0(0.0f, 1.0f) + 3.0f) * 0.020000001415610313f;
        *(f32 *)(p + 0x658) = func_003824E0(0.0f, 2.0f);
        *(f32 *)(p + 0x65C) = func_003824E0(0.0f, 2.0f);
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 3);
        break;
    case 8:
        *(s16 *)(p + 0x660) = 42;
        break;
    case 9:
        p[0x667] = 1 << func_00382498(0, 1);
        *(s16 *)(p + 0x660) = ((func_00382468(30) + 60) * 5 + 2) / 6;
        break;
    case 10:
        func_L01_00456230(obj, 0);
        if (obj[0x43] != 4) func_003C3A10(obj, 4, 0, 0);
        break;
    case 11:
        if (obj[0x43] != 6) func_003C3A10(obj, 6, 0, 0);
        break;
    case 12:
        p[0x66A] = 0;
        p[0x667] = 3;
        if (obj[0x43] != 2) func_003C3A10(obj, 2, 0, 2);
        break;
    }
    func_L01_004450F0(obj, state, -1);
}
/* localdecomp:end func_L07_003B37D0 */

/* localdecomp:start func_L07_003B3A88 */
#include "structs/moby.h"
#include "vu0.h"
typedef struct { vu0_q q[6]; } Saved_003B3A88;
void func_L07_003B3A88(struct Moby *m, f32 arg1) {
    extern void func_0038CF68(void *, void *);
    extern f32 func_L07_00332CF0(void *, void *, void *, f32);
    extern s32 func_L01_0045A7A8(void *, void *, f32);
    extern f32 func_L01_0040E570(void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_00448890(char *, char *, int, float, float, float, float);
    extern void func_0038D308(void *, void *);
    extern void func_L07_003B4470(void *, void *);
    extern void func_L01_00446780(void *, void *, f32, f32, f32, s32, s32, s32, s32);
    vu0_v4 direction;
    vu0_v4 previous;
    Saved_003B3A88 saved;
    u8 *p = m->pvar;
    f32 yaw;
    vu0_q *source;
    s32 i;
    vu0_q *destination;
    vu0_q *saved_start;
    vec_sub_ab(&direction, &m->position, p + 0x80);
    func_0038CF68(&direction, &direction);
    vec_add_ab(&direction, p + 0x80, &direction);
    *(vu0_q *)&previous = *(vu0_q *)&m->position;
    saved_start = saved.q;
    source = (vu0_q *)(p + 0x330);
    destination = saved_start;
    for (i = 5; i >= 0; i--) {
        *destination++ = *source++;
    }
    func_L01_0045A7A8(m, &direction, func_L07_00332CF0(*(void **)(p + 0x190), m, &direction, 0.0f));
    if ((*(s32 *)(p + 0xD8) & 0x10) && func_L01_0040E570(&previous, &m->position) > 1.0000001111620804e-06f) {
        yaw = func_0038D160(m->position.x - previous.x, m->position.y - previous.y);
        if (fabs_asm(func_0038DB00(func_0038D160(*(f32 *)(p + 0x80) - m->position.x, *(f32 *)(p + 0x84) - m->position.y), yaw)) > 1.5707963705062866f) {
            yaw = func_0038DAB8(yaw, 3.1415927410125732f);
        }
        func_L01_00448890((char *)m + 0xF8, (char *)p + 0x154, 0, yaw, *(f32 *)(p + 0xB4), *(f32 *)(p + 0xB8), *(f32 *)(p + 0xBC));
        func_0038D308((u8 *)m + 0xC0, (u8 *)m + 0xF0);
    }
    func_L07_003B4470(m, saved_start);
    func_L01_00446780(m, &m->position, 3.0f, 1.0f, 1.0f, 0x08000000, 0, 1, 0);
}
/* localdecomp:end func_L07_003B3A88 */

INCLUDE_ASM("asm/levels", func_L07_003B3C78);

INCLUDE_ASM("asm/levels", func_L07_003B3DB0);

/* localdecomp:start func_L07_003B4250 */
extern f32 func_0038DBA0(f32, f32);
extern void func_L07_003B4978(void *, u8);

void func_L07_003B4250(u8 *obj) {
    u8 *base = *(u8 **)(obj + 0x68);
    s32 i;

    for (i = 0; i < 2; i++) {
        if ((base[0x667] >> i) & 1) {
            *(f32 *)(base + i * 0x80 + 0x434) = -1.5707964f;
            if (func_0038DBA0(*(f32 *)(base + i * 0x80 + 0x414), -1.5707964f) < 0.17453292f)
                func_L07_003B4978(obj, i);
        }
    }
}
/* localdecomp:end func_L07_003B4250 */

/* localdecomp:start func_L07_003B4308 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B4308;
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L07_003BF158(u8 *, void *, void *, s32, u8, s32, s32);
void func_L07_003B4308(u8 *obj) {
    V4_003B4308 joint, sum;
    struct Moby *m = (struct Moby *)obj;
    u8 *p = m->pvar;
    func_003C2F58(obj, 13, (f32 *)&joint);
    vec_add_ba(&sum, &m->rotation, p + 0x610);
    func_L07_003BF158(obj, &joint, &sum, *(s32 *)(p + 0x90), p[0x45], 4, 0);
}
/* localdecomp:end func_L07_003B4308 */

/* localdecomp:start func_L07_003B4370 */
extern void func_L07_003B37D0(u8 *, s32);
extern s32 func_00382468(s32);

void func_L07_003B4370(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);

    switch (arg0[0x95]) {
    case 1:
        if (p[0x668] >= 6) {
            p[0x668] = 0;
            func_L07_003B37D0(arg0, 6);
            *(s16 *)(p + 0x660) = func_00382468(0x53) + 0xD0;
            break;
        }
        /* fall through */
    case 0:
        func_L07_003B37D0(arg0, 9);
        p[0x666] = 3;
        break;
    case 2:
        if (p[0x668] >= 3) {
            p[0x668] = 0;
            func_L07_003B37D0(arg0, 6);
            *(s16 *)(p + 0x660) = func_00382468(0xA7) + 0x1A1;
        } else {
            func_L07_003B37D0(arg0, 9);
            p[0x666] = func_00382468(2) + 3;
        }
        break;
    case 3:
        func_L07_003B37D0(arg0, 7);
        *(s16 *)(p + 0x660) = func_00382468(0x14D) + 0x341;
        break;
    }
}
/* localdecomp:end func_L07_003B4370 */

INCLUDE_ASM("asm/levels", func_L07_003B4470);

/* localdecomp:start func_L07_003B4688 */
extern void func_003C2F58(void *, s32, void *);

void func_L07_003B4688(void *arg0) {
    s32 i;
    u8 *p;

    i = 0;
    p = (u8 *)(*(s32 *)((u8 *)arg0 + 0x68)) + 0x330;
    do {
        func_003C2F58(arg0, i, p);
        i++;
        p += 0x10;
    } while (i < 6);
}
/* localdecomp:end func_L07_003B4688 */

/* localdecomp:start func_L07_003B46E8 */
void func_L07_003B46E8(u8 *obj) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_003C3BE8(f32, f32, f32);
    extern f32 func_L07_003B48E8(f32 x, f32 lo, f32 hi);
    extern void func_L01_0044E850(void *, void *, s32, f32, f32);
    extern void func_0038D750(void *, s32, f32);
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *a, *b, *matrix;
    s32 i, j, k;
    if (*(s32 *)(p + 0xD8) & 0x10) {
        *(f32 *)(p + 0x638) = func_0038DB00(func_0038D160(*(f32 *)(p + 0x80) - *(f32 *)(obj + 0x10), *(f32 *)(p + 0x84) - *(f32 *)(obj + 0x14)), *(f32 *)(obj + 0xF8));
        if (obj[0x20] == 7) {
            f32 t = *(f32 *)(p + 0x658);
            if (t > 1.0f) t = 2.0f - t;
            *(f32 *)(p + 0x638) = func_0038DAB8(*(f32 *)(p + 0x638), func_003C3BE8(-0.34906584f, 0.34906584f, t));
        }
        *(f32 *)(p + 0x638) = func_L07_003B48E8(*(f32 *)(p + 0x638), -1.0471976f, 1.0471976f);
    } else *(s32 *)(p + 0x638) = 0;
    func_L01_0044E850(obj, p + 0x5D0, 12, 0.014400000683963299f, 0.4320000410079956f);
    matrix = p + 0x3A0;
    k = 7;
    b = p + 0x4D0;
    j = 6;
    a = p + 0x3D0;
    for (i = 1; i >= 0; i--) {
        func_L01_0044E850(obj, a, j, 0.0432f, 0.4320000410079956f);
        j += 3;
        a += 0x80;
        func_L01_0044E850(obj, b, k, 0.0432f, 0.4320000410079956f);
        k += 3;
        b += 0x80;
    }
    *(f32 *)(p + 0x654) = func_0038DAB8(*(f32 *)(p + 0x654), 0.25132743f);
    func_0038D750(matrix, 1, *(f32 *)(p + 0x654));
}
/* localdecomp:end func_L07_003B46E8 */

/* localdecomp:start func_L07_003B48E8 */
/* localdecomp:start func_L07_003B48E8 */
/* Fold x into [lo, hi]: relative position, absolute value, 0.4/0.5 wrap, sign back. */
f32 func_L07_003B48E8(f32 x, f32 lo, f32 hi) {
    f32 denom = hi - lo;
    f32 mid = (lo + hi) * 0.5f;
    f32 t;
    s32 neg = 0;

    t = x - mid / denom;
    if (t < 0.0f) {
        t = -t;
        neg = 1;
    }
    if (0.4f < t) {
        f32 u = (t - 0.4f) * 0.5f + 0.4f;

        if (0.5f < u)
            u = 0.5f;
        t = u;
    }
    if (neg)
        t = -t;
    return mid + denom * t;
}
/* localdecomp:end func_L07_003B48E8 */
/* localdecomp:end func_L07_003B48E8 */

INCLUDE_ASM("asm/levels", func_L07_003B4978);

/* localdecomp:start func_L07_003B4B68 */
void func_L07_003B4C30(void *, u8, f32, u8);

void func_L07_003B4B68(void *arg0, s16 arg1, f32 arg2) {
    s32 i;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    if (arg1 != -1 && arg1 < 0x15) {
        return;
    }
    for (i = 0; i < 2; i++) {
        if ((arg1 & 3) == 0 && arg1 != -1) {
            func_L07_003B4C30(arg0, i, arg2, p[0x44]);
        } else {
            func_L07_003B4C30(arg0, i, arg2, 0);
        }
    }
}
/* localdecomp:end func_L07_003B4B68 */

/* localdecomp:start func_L07_003B4C30 */
#include "vu0.h"
extern u8 *D_L07_0021EE04 __attribute__((section(".data")));
void func_L07_003B4C30(void *self, u8 side, f32 amount, u8 kind)
{
    extern void func_003C2EC0(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003C4C18(void *, f32);
    extern u8 *func_L01_00475128(void *, void *, void *, f32, f32, f32, u32, s32, s32, s32, s32);
    vu0_v4 matrix[4];
    vu0_v4 position;
    vu0_v4 velocity;
    u8 *effect;
    func_003C2EC0(self, side * 3 + 8, matrix);
    if (side == 1) vec_neg(matrix, matrix);
    func_0038CF68(&position, matrix, 1.0f);
    vec_add_ab(&position, &matrix[3], &position);
    func_0038CF68(&velocity, matrix, 0.40000003576278687f);
    func_003C4C18(&velocity, 0.04000000283122063f);
    effect = func_L01_00475128(self, &position, &velocity, *(f32 *)((u8 *)self + 0x18), 84000.0f, amount * 420000.0f,
        0x7F808080, (s32)(amount * 42.0f), 5, kind, 0);
    if (effect) effect[2] = D_L07_0021EE04[0];
    if (amount >= 1.0f) {
        func_003C4C18(&position, 0.2f);
        effect = func_L01_00475128(self, &position, &velocity, *(f32 *)((u8 *)self + 0x18), 84000.0f, 84000.0f,
            0x7F808080, 8, 0, 0, 0);
        if (effect) effect[2] = D_L07_0021EE04[0];
    }
}
/* localdecomp:end func_L07_003B4C30 */

/* localdecomp:start func_L07_003B4DF8 */
typedef struct { u8 pad[0x1F0]; u8 *p; } G_003B4DF8;
extern G_003B4DF8 D_L07_0021EC98;
void func_L07_003B4DF8(u8 *self) {
    extern void func_003C2F58(void *, s32, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C4C18(void *, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    f32 position[4];
    f32 velocity[4];
    s32 i, j, next;
    s32 three = 3;
    G_003B4DF8 *g = &D_L07_0021EC98;
    f32 a, b, c;
    u8 *particle;
    i = 0;
    do {
        func_003C2F58(self, i + 14, position);
        next = i + 1;
        for (j = 1; j >= 0; j--) {
            func_0038CE20(velocity, self + 0xC0, -func_003824E0(0.20000001788139343f, 0.30000001192092896f));
            func_003C4C18(velocity, 0.08000000566244125f);
            i = func_00382498(40, 60);
            a = func_003824E0(63000.00390625f, 147000.0f);
            b = func_003824E0(315000.0f, 525000.0f);
            c = func_003824E0(-0.004000000189989805f, -0.00800000037997961f);
            particle = func_L01_0046FB40(position, velocity, i, 0x202020, func_00382468(2) ? three : -3, 96, 0, 0, a, b, c);
            if (particle) {
                u8 color = g->p[1];
                particle[3] = 0x44;
                particle[2] = color;
            }
        }
        i = next;
    } while (i < 2);
}
/* localdecomp:end func_L07_003B4DF8 */

INCLUDE_ASM("asm/levels", func_L07_003B4FD0);

/* localdecomp:start func_L07_003B5CC8 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0044E7D8(void *);
extern void func_L07_003B6320(u8 *);
extern void func_L07_003B62C8(u8 *);

void func_L07_003B5CC8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 t;

    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    *(f32 *)(p + 0x40) = 1.0f;
    p[0x3E] = 3;
    *(u16 *)(p + 0x32C) = *(u16 *)(p + 0x34);
    p[0x3F] = 0;
    p[0x64] = 0;
    t = *(u16 *)(a0 + 0xB6);
    p[0x39] = 0;
    *(f32 *)(p + 0xA0) = 3.0f;
    *(f32 *)(p + 0xA4) = 1.2f;
    *(f32 *)(p + 0xA8) = 1.2f;
    *(f32 *)(p + 0xAC) = 1.2f;
    *(f32 *)(p + 0xB0) = 3.1415927f;
    *(f32 *)(p + 0xD0) = 0.7853982f;
    *(f32 *)(p + 0xCC) = 0.00392f;
    *(f32 *)(p + 0xD4) = 0.2f;
    *(u16 *)(p + 0x32E) = t;
    func_L01_0045BD78(a0, 0.072000005f, 0.40000004f, 0.0012566372f, 0.06283186f);
    *(void **)(p + 0x194) = func_L07_003B6320;
    *(void **)(p + 0x198) = func_L07_003B62C8;
    *(u8 *)(p + 0x1AD) = 0xFF;
    *(s16 *)(p + 0x19C) = -1;
    *(s32 *)(p + 0x33C) = func_L01_0044E7D8(a0);
    func_L07_003B62C8(a0);
}
/* localdecomp:end func_L07_003B5CC8 */

/* localdecomp:start func_L07_003B5E08 */
typedef struct { u8 bytes[16]; } Saved_003B5E08;
typedef struct { u8 pad0[0x20]; u8 state; u8 pad21[0x89]; s16 oclass; } M_003B5E08;
typedef struct {
    u8 pad0[0x30]; f32 health; s16 max_health; u8 pad36[0x11]; u8 color;
    u8 pad48[0x16]; u8 flag5E, pad5F, flag60; u8 pad61[0xF]; Saved_003B5E08 damage;
    u8 pad80[0x110]; s32 anim; u8 pad194[0x11C]; u8 bone[0x50]; s32 child_index;
    u8 pad304[4]; M_003B5E08 *child; u8 pad30C[0x15]; u8 phase; u8 pad322[2]; u8 tracking;
    u8 pad325; u8 effect; u8 pad327; s16 timer; u8 pad32A[6]; s16 cooldown;
    u8 pad332[10]; s32 saved;
} State_003B5E08;
extern u8 *D_L07_001DF41C;
extern u8 D_L07_001E1EC0[];
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
void func_L07_003B5E08(u8 *obj)
{
    extern s32 func_L01_00447490(void *, s32, s32);
    extern f32 func_L01_004474E8(void *, s32);
    extern s32 func_L01_004AAC98(s32, s32, void *, s32);
    extern void func_L01_00459BE8(void *, s32, f32);
    extern void func_003C4A40(void *, void *);
    extern void func_L01_0044ABD0(void *, void *);
    extern void func_L01_0044E820(void *, s32);
    extern s32 func_0038CB00(void *);
    extern s32 func_L07_003A2380(u8, s32, u8, s16);
    extern void func_L07_003B64D0(u8 *, s32);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, f32, f32, f32, f32,
                                s32, s32, s32, s32, s32, s32, s32);
    extern void func_L07_003315B0(void *);
    extern void func_L01_0047C990(s32, s32, s32, f32);
    extern void func_L01_00456BD0(void *, s32);
    extern s32 func_L07_00333D20(s32);
    extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32,
                                s32, s32, s32, s32);
    extern void func_L07_003B6870(u8 *);
    extern void func_L07_004522E8(void *, s32, void *, f32);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L01_004472C0(void *);
    Saved_003B5E08 saved;
    State_003B5E08 *p = *(State_003B5E08 **)(obj + 0x68);
    Saved_003B5E08 *damage;
    u8 *child;
    f32 amount;
    s32 hit;
    Pool_003AF678 *pool;
    if (obj[0x20] == 1) return;
    hit = func_L01_00447490(obj, -1, 0);
    damage = &p->damage;
    amount = func_L01_004474E8(obj, hit);
    obj[0xA8] = 255;
    if ((*(u16 *)(obj + 0x34) & 0x4000) && amount > 0.0f) {
        if (p->cooldown == 0) {
            func_L01_004AAC98(0, 0, obj, 0x1A1C);
            p->cooldown = 50;
        }
        p->health -= amount;
        func_L01_00459BE8(obj, p->color, amount);
        p->damage.bytes[7] = 255;
        func_003C4A40(obj, damage);
        if ((f32)p->max_health * 0.1f <= amount) {
            child = D_L07_001DF41C + (p->child_index << 8);
            if (child[0xBC] == 0) child[0xBC] = 2;
        }
    }
    func_L01_0044ABD0(obj, damage);
    if (*(s16 *)&p->damage == 0) func_L01_0044E820(obj, p->saved);
    func_0038CB00(&p->cooldown);
    if (p->phase == 0) {
        if (p->health < (f32)p->max_health * 0.66f) {
            func_L07_003A2380(6, (s32)obj, 0, 100);
            func_L07_003B64D0(obj, 18);
            p->phase = 1;
            p->effect = 3;
            p->health = (f32)p->max_health * 0.66f;
        }
    } else if (p->phase == 1) {
        if (p->health < (f32)p->max_health * 0.33f) {
            func_L07_003B64D0(obj, 18);
            p->phase = 2;
            p->effect = 3;
            p->health = (f32)p->max_health * 0.33f;
        }
    }
    if (p->effect) {
        M_003B5E08 *linked = p->child;
        if (linked) {
            if (linked->oclass != 0x1C81 || linked->state == 0xFE || linked->state == 0xFD) p->child = 0;
        } else {
            ((u8 *)((p->child_index << 8) + (s32)D_L07_001DF41C))[0xBC] = p->effect;
            p->effect = 0;
        }
    }
    if (p->health <= 0.0f) {
        saved = p->damage;
        func_L01_0043B9E8(obj, saved.bytes[4], saved.bytes[5], saved.bytes[6]);
        func_L01_00451FE0(obj, 0x3FFF, D_L07_001D66B0,
                          8.0f, 12.0f, 8.0f, 12.0f, -1.0f, -1.0f, 1.0f, 1.0f, 255, 180, 0, 0, 35, 0, 3);
        func_L07_003315B0(obj);
        return;
    }
    if (p->flag5E) {
        func_L07_003315B0(obj);
        p->flag5E = 0;
        return;
    }
    if (p->flag60) {
        func_L07_003315B0(obj);
        p->flag60 = 0;
        return;
    }
    if (p->tracking) {
        Pool_003AF678 *g = (Pool_003AF678 *)D_L07_001E1EC0;
        if (g->w144 != obj && g->w144 == 0) {
            g->w144 = obj;
            g->w148 = 0;
        }
    } else {
        Pool_003AF678 *g = (Pool_003AF678 *)D_L07_001E1EC0;
        if (g->w144 == obj) g->w144 = 0;
    }
    pool = (Pool_003AF678 *)D_L07_001E1EC0;
    func_L01_0047C990(2, 0, pool->w144 != obj, p->health / (f32)p->max_health);
    func_L01_00456BD0(obj, 3);
    hit = func_L07_00333D20(p->anim);
    func_L01_00456C98(obj, 0.0f, 0.0f, 1.0f, hit, 0, 0, 0, 0, 1, 0, 0, 0);
    func_L07_003B6870(obj);
    func_0038CB00(&p->timer);
    func_L07_004522E8(obj, 17, p->bone, 2.5f);
    if (func_L01_0040E548(pool, obj + 0x10) < 5625.0f) {
        func_L01_004472C0(obj);
        obj[0x6F] = 70;
    }
}
/* localdecomp:end func_L07_003B5E08 */

/* localdecomp:start func_L07_003B62C8 */
extern u8 D_L07_001E1EC0[];
extern void func_L07_00334740(void *);
extern void func_L07_003B64D0(u8 *, s32);
void func_L07_003B62C8(u8 *arg0) {
    u8 *g = D_L07_001E1EC0;
    u8 *p = *(u8 **)(arg0 + 0x68);
    p[0x77] = 0;
    p[0x78] = 0;
    p[0x79] = 0;
    if (*(u8 **)(g + 0x144) == arg0) *(u8 **)(g + 0x144) = 0;
    func_L07_00334740(arg0);
    func_L07_003B64D0(arg0, 1);
}
/* localdecomp:end func_L07_003B62C8 */

/* localdecomp:start func_L07_003B6320 */
extern u8 D_001426E0[];
extern u8 D_00142660[];
void func_L07_003B6320(u8 *self) {
    extern s32 func_L01_0041A4F0(void);
    extern f32 func_L07_00334A98(s32);
    extern f32 func_L01_004DFE88(s32);
    extern void func_L07_00334800(u8 *);
    u8 *g = D_001426E0;
    u8 *p = *(u8 **)(self + 0x68);
    f32 ratio, health;
    u8 tint;
    if (!g[0x83]) {
        g[0x83] = D_00142660[8];
        g[0xD7] = D_00142660[0x40];
    }
    if (func_L01_0041A4F0()) {
        *(s16 *)(p + 0x34) = 1000;
        *(f32 *)(p + 0x30) = 1000.0f;
        ratio = 1000.0f / (f32)*(s16 *)(p + 0x32C);
    } else {
        ratio = func_L07_00334A98(g[0x83]);
        *(s16 *)(p + 0x34) = (f32)*(s16 *)(p + 0x32C) * ratio;
        *(f32 *)(p + 0x30) = (f32)*(s16 *)(p + 0x34);
    }
    health = ratio * (f32)*(s16 *)(p + 0x32E);
    if (health > 65535.0f) health = 65535.0f;
    *(s16 *)(self + 0xB6) = health;
    tint = (u8)(((f32)D_001426E0[0x83] / func_L01_004DFE88(D_001426E0[0xD7])) * 0.125f);
    {
    s32 one = 1;
    p[0x327] = 0;
    p[0x321] = 0;
    *(s16 *)(p + 0x328) = 0;
    p[0x324] = one;
    *(f32 *)(p + 0x310) = (f32)*(s16 *)(p + 0x34);
    p[0x44] = tint;
    p[0x45] = tint;
    p[0x46] = tint;
    func_L07_00334800(self);
    }
    func_L07_003B64D0(self, 2);
}
/* localdecomp:end func_L07_003B6320 */
