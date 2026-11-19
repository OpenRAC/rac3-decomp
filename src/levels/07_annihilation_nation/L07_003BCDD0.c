#include "common.h"

/* localdecomp:start func_L07_003BCDD0 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);

void func_L07_003BCDD0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 t;
    f32 v;

    *(f32 *)(a0 + 0x18) -= *(f32 *)(s + 0x2AC);
    t = func_0038DAB8(*(f32 *)(s + 0x2A8), 0.12566371f);
    *(f32 *)(s + 0x2A8) = t;
    v = func_0038D0B0(t) * 0.2f;
    *(f32 *)(s + 0x2AC) = v;
    *(f32 *)(a0 + 0x18) += v;
}
/* localdecomp:end func_L07_003BCDD0 */

/* localdecomp:start func_L07_003BCE50 */
void func_L07_003BCE50(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x18) = (f32) ((*(f32 *)((u8 *)arg0 + 0x18)) - (*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x2AC)));
}
/* localdecomp:end func_L07_003BCE50 */

/* localdecomp:start func_L07_003BCE68 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L07_003BCEE8(void *, void *, f32);
void func_L07_003BCE68(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 t = func_0038DAB8(*(f32 *)(s + 0x2A8), 0.12566371f);
    f32 v;
    *(f32 *)(s + 0x2A8) = t;
    v = func_0038D0B0(t) * 0.2f;
    *(f32 *)(s + 0x2AC) = v;
    *(f32 *)(a0 + 0x18) += v;
    func_L07_003BCEE8(a0, s + 0xD0, *(f32 *)(s + 0xE4));
}
/* localdecomp:end func_L07_003BCE68 */

/* localdecomp:start func_L07_003BCEE8 */
extern f32 func_0038CE68(void *, void *);

void func_L07_003BCEE8(void *a0, void *a1, f32 t) {
    u8 *p = (u8 *)a0;
    f32 k;
    f32 d;
    f32 e;
    f32 m;

    *(f32 *)(p + 0xF0) -= t * 0.2f * 1.164f;
    d = func_0038CE68(a1, p + 0xD0) / 0.6f;
    if (d < 1.0f) {
        k = func_0038CE68(a1, p + 0xD0) / 0.6f * -0.34906584f;
    } else {
        k = -0.34906584f;
    }
    *(f32 *)(p + 0xF0) = *(f32 *)(p + 0xF0) * 0.9640000462532043f + k * 0.035999953746795654f;
    e = func_0038CE68(a1, p + 0xC0) / 0.6f;
    if (e < 1.0f) {
        m = func_0038CE68(a1, p + 0xC0) / 0.6f * 0.34906584f;
    } else {
        m = 0.34906584f;
    }
    *(f32 *)(p + 0xF4) = *(f32 *)(p + 0xF4) * 0.9640000462532043f + m * 0.035999953746795654f;
}
/* localdecomp:end func_L07_003BCEE8 */

/* localdecomp:start func_L07_003BD078 */
extern s32 D_001DF41C;
s32 func_L07_003BAC58(s32);
s32 func_L07_003BADA8(s32);
s32 func_L07_003BAF28(void *);

s32 func_L07_003BD078(void *arg0) {
    u8 *p;
    s32 t;

    p = *(u8 **)((u8 *)arg0 + 0x68);
    if (*(s16 *)(p + 0x234) == 0) {
        return 0;
    }
    if (*(s32 *)(p + 0x278) != -1) {
        if (func_L07_003BAC58(D_001DF41C + (*(s32 *)(p + 0x278) << 8)) == 0) {
            return 0;
        }
    }
    if (*(s32 *)(p + 0x27C) != -1) {
        if (func_L07_003BADA8(*(s32 *)(p + 0x27C)) == 0) {
            return 0;
        }
    }
    t = func_L07_003BAF28(arg0);
    *(s16 *)(p + 0x260) = t;
    return (s16)t < *(s16 *)(p + 0x262);
}
/* localdecomp:end func_L07_003BD078 */

/* localdecomp:start func_L07_003BD118 */
/* The callee's own parameters are (f32, f32, f32, void *, s32, s32, s32, s32, s32);
 * this ABI-equivalent order gives retail's argument moves here. */
extern s32 func_L01_004468C8(void *, s32, f32, f32, s32, f32, s32, s32, s32);

void func_L07_003BD118(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    s32 sel = *(u8 *)(p + 0x14F) != 0 ? 0x10001 : 1;

    func_L01_004468C8(arg0, 0, 0.17f, (f32)*(u8 *)(p + 0x134), sel, 1.0f, 0, 1, 0);
    func_L01_004468C8(arg0, 1, 0.17f, (f32)*(u8 *)(p + 0x134), sel, 1.0f, 0, 1, 0);
}
/* localdecomp:end func_L07_003BD118 */

INCLUDE_ASM("asm/levels", func_L07_003BD1E8);

/* localdecomp:start func_L07_003BD9D0 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L01_00445F40(u8 *moby, s32 class_id);
extern s32 func_L07_003C1AF8(void);
extern f32 func_L07_003C1B40(s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L07_003BE368(char *);

/* Initialises the walker class, tuning constants and saved transform. */
void func_L07_003BD9D0(u8 *a0) {
    u8 *p;
    u8 *r;
    u8 *q;
    s32 k;
    f32 s;

    p = *(u8 **)(a0 + 0x68);
    func_L01_00445F40(a0, 0x19BE);
    r = p + 0x30;
    k = func_L07_003C1AF8();
    s = func_L07_003C1B40(k);
    *(s16 *)(r + 4) = (f32)*(s16 *)(p + 0x34) * s;
    *(f32 *)(p + 0x30) = (f32)*(s16 *)(r + 4);
    r[0x14] = (f32)p[0x44] * s;
    r[0x15] = (f32)p[0x45] * s;
    r[0x16] = (f32)p[0x46] * s;
    if (k == 1 || k == 3) {
        func_L01_00446058(a0, 0x1D89, 0x19BE);
    }
    r[0x28] = 0x14; r[0x2A] = 0xE; *(f32 *)(r + 0x10) = 1.0f; r[0xF] = 0; r[9] = 0;
    q = p + 0x70;
    q[0x48] = 0xFF; q[0x10] = 8; *(f32 *)(q + 0x3C) = 0.15f; *(f32 *)(q + 0x58) = 0.35f; *(f32 *)(q + 0x30) = 1.0f; *(f32 *)(q + 0x34) = 0.5f; *(f32 *)(q + 0xB0) = 1.0f; *(f32 *)(q + 0x5C) = 0.5f; *(s32 *)(q + 0xA8) = 0; q[0x77] = 1;
    *(f32 *)(p + 0x150) = 1.0f; *(f32 *)(p + 0x154) = 0.3f; *(f32 *)(p + 0x160) = 1.5707964f; *(f32 *)(p + 0x180) = 0.2443461f; *(f32 *)(p + 0x17C) = 0.00392000005f; *(s32 *)(p + 0x23C) = 0; *(f32 *)(p + 0x158) = 0.5f; *(f32 *)(p + 0x15C) = 0.5f; *(f32 *)(p + 0x184) = 0.5f; *(s16 *)(p + 0x4F6) = 0;
    *(u128_t *)(p + 0x340) = *(u128_t *)(a0 + 0x10);
    *(u128_t *)(p + 0x350) = *(u128_t *)(a0 + 0xF0);
    func_L01_0045BD78(a0, 0.002000000095f, 0.100000009f, 0.00502654864f, 0.125663713f);
    func_L07_003BE368((char *)a0);
}
/* localdecomp:end func_L07_003BD9D0 */

/* localdecomp:start func_L07_003BDC08 */
#include "vu0.h"
typedef int Quad_003BDC08 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003BDC08;
extern u8 D_L07_001D66B0_003BDC08[] __attribute__((section(".sdata")));
extern u8 D_L07_001E1EC0_003BDC08[];
void func_L07_003BDC08(u8 *obj)
{
    extern s32 func_L01_00452FB0(void *,void *,s32,s32,s32);
    extern s32 func_L01_003303B8(void *,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32);
    extern void func_L01_00451FE0(void *,s32,void *,f32,f32,f32,f32,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32);
    extern void func_L01_004443E8(void *,s32,s32);
    extern void func_L07_003BE368(char *);
    extern void func_003A52A0(s32,s32,void *);
    extern void func_L01_00446A70(void *,void *,s32,void *,void *,f32);
    extern s32 func_L01_00452860(void *,void *,s32);
    extern void func_L01_00456BD0(void *,s32);
    extern void func_L01_00456C98(void *,s32,s32,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32);
    extern void func_L07_004522E8(void *,s32,void *,f32);
    extern f32 func_L01_0040E548(void *,void *);
    extern void func_L01_004472C0(void *);
    u8 *p = *(u8 **)(obj+0x68);
    Vec_003BDC08 position;
    s32 id;
    f32 speed;
    if (func_L01_00452FB0(obj,p+0x70,0,0,0)) {
        *(s32 *)(p+0x188) &= ~0x10;
    }
    if (*(f32 *)(p+0x30) <= 0.0f) {
        position = *(Vec_003BDC08 *)(obj+0x10);
        position.z += *(f32 *)(p+0x40);
        func_L01_003303B8(&position,0,10,5,4,10,15,0,
            0,0,0,0,0,1,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,
            0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0,
            0.5f,0.0f,0.0f,2.0f);
        func_L01_00451FE0(obj,0x7FFF,D_L07_001D66B0_003BDC08,3.0f,6.0f,3.0f,6.0f,
            0xFF,0xB4,0,0,0x23,0,3,-1.0f,-1.0f,1.0f,1.0f);
        func_L01_004443E8(obj,0,3);
        func_L07_003BE368((char *)obj);
        func_003A52A0(8,0,obj);
        return;
    }
    if (*(s32 *)(p+0x228)==1 || *(s32 *)(p+0x228)==11) {
        qzero(&position);
        func_L01_00446A70(obj,obj,0x10000,&position,&position,(f32)*(s16 *)(p+0x34));
    } else if (p[0x5E] || p[0x60] || p[0x3E]==2) {
        func_L01_004443E8(obj,0,3);
        func_L07_003BE368((char *)obj);
        return;
    }
    func_L01_00452860(obj,p+0x30,0);
    if (p[0x5F]) {
        func_L01_00456BD0(obj,5);
        id = obj[0x20]>=8 ? *(s32 *)(p+0x388) : *(s32 *)(p+0x380);
        speed = obj[0x20]>=8 ? *(f32 *)(p+0x38C) : *(f32 *)(p+0x384);
        func_L01_00456C98(obj,id,0,0,0,0,3,0,0,0,speed,10.0f,1.0f);
    } else {
        func_L01_00456BD0(obj,3);
        id = obj[0x20]>=8 ? *(s32 *)(p+0x388) : *(s32 *)(p+0x380);
        speed = obj[0x20]>=8 ? *(f32 *)(p+0x38C) : *(f32 *)(p+0x384);
        func_L01_00456C98(obj,id,0,0,0,0,1,0,0,0,speed,10.0f,1.0f);
    }
    func_L07_004522E8(obj,5,p+0x300,2.5f);
    if (obj[0x31] && func_L01_0040E548(D_L07_001E1EC0_003BDC08,obj+0x10) < 576.0f) {
        func_L01_004472C0(obj);
        obj[0x6F]=0x16;
    }
}
/* localdecomp:end func_L07_003BDC08 */

INCLUDE_ASM("asm/levels", func_L07_003BDFB8);

/* localdecomp:start func_L07_003BE2A0 */
typedef int Quad_003BE2A0 __attribute__((mode(TI)));

extern void func_L07_003BB1A8(u8 *);
extern void func_L07_003BE3A8(void *, int);
extern void func_L07_003BE5F8(void *);

void func_L07_003BE2A0(u8 *self, s32 idx) {
    u8 *s = *(u8 **)(self + 0x68);
    u8 *buf;

    if ((s + idx)[0x370] != 0) {
        func_L07_003BB1A8(self);
        buf = s + 0x2C0;
        *(Quad_003BE2A0 *)(self + 0x10) = *(Quad_003BE2A0 *)(s + 0x340);
        *(Quad_003BE2A0 *)(self + 0xF0) = *(Quad_003BE2A0 *)(s + 0x350);
        func_0038CB78((s32)buf, 0, 0x40);
        func_L01_0043A430(self, 3, (s32)buf);
        *(s16 *)(s + 0x4F8) = 0;
        if (*(s32 *)(s + 0x3AC) != -1) {
            func_L07_003BE3A8(self, 2);
        } else {
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) & 0xFFBE) | 0x1000;
            *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
            func_L07_003BE5F8(self);
        }
    }
}
/* localdecomp:end func_L07_003BE2A0 */

/* localdecomp:start func_L07_003BE368 */
extern void func_003C2C98(void *, void *);
extern void func_L07_003BB1F0(void *);
extern void func_L07_003BE3A8(void *, int);

void func_L07_003BE368(char *obj) {
    func_003C2C98(obj, *(char **)(obj + 0x68) + 0x2C0);
    func_L07_003BB1F0(obj);
    func_L07_003BE3A8(obj, 1);
}
/* localdecomp:end func_L07_003BE368 */

/* localdecomp:start func_L07_003BE3A8 */
void func_L07_003BE3A8(void *arg, s32 state) {
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    u8 *p = arg;
    switch (state) {
    case 1: case 2: case 3:
        if (p[0x43] != 0) func_003C3A10(p, 0, 0, 0);
        break;
    case 4:
        if (p[0x43] != 0) func_003C3A10(p, 0, 0, 7);
        break;
    case 5:
        if (p[0x43] != 0) func_003C3A10(p, 0, 0, 7);
        break;
    case 10:
        if (p[0x43] != 2) func_003C3A10(p, 2, 0, 7);
        break;
    case 6:
        if (p[0x43] != 0) func_003C3A10(p, 0, 0, 7);
        break;
    case 7:
        if (p[0x43] != 0) func_003C3A10(p, 0, 0, 7);
        break;
    case 9:
        if (p[0x43] != 1) func_003C3A10(p, 1, 0, 7);
        break;
    case 11:
        if (p[0x43] != 3) func_003C3A10(p, 3, 0, 7);
        break;
    case 12:
        if (p[0x43] != 3) func_003C3A10(p, 3, 0, 7);
        break;
    case 13:
        if (p[0x43] != 5) func_003C3A10(p, 5, 0, 7);
        break;
    case 14:
        if (p[0x43] != 6) func_003C3A10(p, 6, 0, 7);
        break;
    case 15:
        if (p[0x43] != 8) func_003C3A10(p, 8, 0, 7);
        break;
    case 16:
        if (p[0x43] != 7) func_003C3A10(p, 7, 0, 7);
        break;
    case 17:
        if (p[0x43] != 7) func_003C3A10(p, 7, 0, 7);
        break;
    }
    func_L01_004450F0(p, state, -1);
}
/* localdecomp:end func_L07_003BE3A8 */

/* localdecomp:start func_L07_003BE570 */
extern s32 D_001DF41C;
s32 func_L07_003BAC58(s32);
s32 func_L07_003BADA8(s32);

s32 func_L07_003BE570(void *arg0) {
    u8 *p;

    p = *(u8 **)((u8 *)arg0 + 0x68);
    if (*(s16 *)(p + 0x144) != 1) {
        return 0;
    }
    if (*(s32 *)(p + 0x390) != -1) {
        if (func_L07_003BAC58(D_001DF41C + (*(s32 *)(p + 0x390) << 8)) == 0) {
            return 0;
        }
    }
    if (*(s32 *)(p + 0x394) != -1) {
        if (func_L07_003BADA8(*(s32 *)(p + 0x394)) == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L07_003BE570 */

/* localdecomp:start func_L07_003BE5F8 */
void func_L07_003BE988(void *);
s32 func_L07_003BE570(void *);
void func_L07_003BE678(void *);
void func_L07_003BE708(void *);
void func_L07_003BE3A8(void *, s32);

void func_L07_003BE5F8(void *arg0) {
    u8 *temp;

    temp = *(u8 **)((u8 *)arg0 + 0x68);
    func_L07_003BE988(arg0);
    *(s16 *)(temp + 0x4F6) = 0;
    if (*(long *)(temp + 0x3A0) == -1) {
        if (func_L07_003BE570(arg0) != 0) {
            func_L07_003BE708(arg0);
        } else {
            func_L07_003BE678(arg0);
        }
    } else {
        func_L07_003BE3A8(arg0, 7);
    }
}
/* localdecomp:end func_L07_003BE5F8 */

/* localdecomp:start func_L07_003BE678 */
void func_L07_003BE3A8(void *, s32);

void func_L07_003BE678(void *arg0) {
    if (*(s32 *)(*(s32 *)((char *)arg0 + 0x68) + 0x398) != -1) {
        func_L07_003BE3A8(arg0, 4);
    } else {
        func_L07_003BE3A8(arg0, 5);
    }
}
/* localdecomp:end func_L07_003BE678 */

/* localdecomp:start func_L07_003BE6C0 */
extern void func_L07_003BE3A8(void *, int);
extern void func_L07_003BE678(void *);
void func_L07_003BE6C0(char *arg0) {
    if (*(int *)(*(char **)(arg0 + 0x68) + 0x39C) != -1) {
        func_L07_003BE3A8(arg0, 6);
    } else {
        func_L07_003BE678(arg0);
    }
}
/* localdecomp:end func_L07_003BE6C0 */

/* localdecomp:start func_L07_003BE708 */
void func_L07_003BE3A8(void *, s32);

void func_L07_003BE708(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x39C)) != -1) {
        func_L07_003BE3A8(arg0, 0xB);
        return;
    }
    func_L07_003BE3A8(arg0, 0xC);
}
/* localdecomp:end func_L07_003BE708 */

/* localdecomp:start func_L07_003BE750 */
void func_L07_003BE988(void *);
s32 func_00382468(s32);

void func_L07_003BE750(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    func_L07_003BE988(arg0);
    *(s16 *)(p + 0x4F6) = 0;
    *(u8 *)(p + 0x4FA) = 0;
    if (func_00382468(2) != 0) {
        *(u8 *)(p + 0x4FB) = 1;
        func_L07_003BE3A8(arg0, 0xD);
    } else {
        *(u8 *)(p + 0x4FB) = 2;
        func_L07_003BE3A8(arg0, 0xE);
    }
}
/* localdecomp:end func_L07_003BE750 */

/* localdecomp:start func_L07_003BE7C8 */
void func_L07_003BE3A8(void *, s32);

void func_L07_003BE7C8(void *arg0) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    *(s16 *)((u8 *)temp_v1 + 0x4F8) = 0x32;
    if ((*(u8 *)((u8 *)temp_v1 + 0x4FA)) != 0) {
        func_L07_003BE3A8(arg0, 0xF);
        return;
    }
    func_L07_003BE3A8(arg0, 0xC);
}
/* localdecomp:end func_L07_003BE7C8 */

/* localdecomp:start func_L07_003BE818 */
void func_L07_003BE3A8(void *, s32);

void func_L07_003BE818(void *arg0) {
    u8 *temp_v1;
    s32 v;

    temp_v1 = *(u8 **)((u8 *)arg0 + 0x68);
    v = *(s32 *)(temp_v1 + 0x3A0);
    if (v != -1) {
        temp_v1[0x4FB] = 3;
        func_L07_003BE3A8(arg0, 0x10);
        return;
    }
    if (*(s32 *)(temp_v1 + 0x3A4) != v) {
        temp_v1[0x4FB] = 3;
        func_L07_003BE3A8(arg0, 0x11);
    }
}
/* localdecomp:end func_L07_003BE818 */

/* localdecomp:start func_L07_003BE870 */
typedef struct {
    u8 pad[0x25C0];
    s32 hero;
} S_003BE870;

extern S_003BE870 D_001A4BE0;
extern s32 D_L07_001ECC80[];
extern void func_003C2F58(void *, s32, f32 *);
extern s32 func_L01_00446780(void *, f32, f32 *, s32, f32, f32, s32, s32, s32);

void func_L07_003BE870(u8 *arg0) {
    u8 *h = *(u8 **)(arg0 + 0x68);
    s32 i;
    s32 n;
    s32 j;
    f32 buf[4];

    for (i = 0; i < 2; i++) {
        if ((h[0x4FB] >> i) & 1) {
            func_003C2F58(arg0, i, buf);
            n = func_L01_00446780(arg0, 0.5625f, buf, 0x10001, (f32)h[0x44], 1.0f, 0, 1, 0);
            for (j = 0; j < n; j++) {
                if (D_L07_001ECC80[j] == D_001A4BE0.hero) {
                    h[0x4FA] = 1;
                    break;
                }
            }
        }
    }
}
/* localdecomp:end func_L07_003BE870 */

/* localdecomp:start func_L07_003BE988 */
void func_L07_003BE988(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68) + 0x4F0;
    s32 i;
    for (i = 1; i >= 0; i--) {
        p[2] = 0;
        p[0] = 0;
        p++;
    }
}
/* localdecomp:end func_L07_003BE988 */

/* localdecomp:start func_L07_003BE9B8 */
extern void func_003C2F58(void *, s32, f32 *);

void func_L07_003BE9B8(u8 *arg0) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    u8 *p = s + 0x4F2;
    u8 *q = s + 0x4F0;
    s32 ten = 10;
    s32 i;

    for (i = 0; i < 2; i++) {
        if ((s[0x4FB] >> i) & 1) {
            u8 *t = q + i;
            u8 *r = s + 0x4F2;
            if (++p[i - 2] > 10) {
                p[i - 2] = ten;
                p[i] = (p[i] + 1) % ten;
            }
            func_003C2F58(arg0, i, (f32 *)(s + 0x3B0 + i * 0xA0 + ((r[i] + *t - 1) % ten) * 16));
        }
    }
}
/* localdecomp:end func_L07_003BE9B8 */
