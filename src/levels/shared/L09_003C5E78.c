#include "common.h"

typedef void (*fn_3C5D58)(u8 *);

typedef struct HrugisEffectCamera {
    char pad00[0x140];
    float position[4];
} HrugisEffectCamera;

typedef struct {
    f32 m[16];
} M_003CA6A8;
typedef struct {
    u8 pad0[0x1F0];
    M_003CA6A8 j[19];
    f32 a[4];
    f32 c[4];
} S_003CA6A8;

typedef struct {
    u8 p0[0x10];
    u8 f10[0x10];
    f32 f20;
    f32 f24;
    f32 f28;
    u8 p2C[0x14];
} M_003CA7E8;
typedef struct {
    u8 pad[0x1E0];
    M_003CA7E8 m[4];
    u8 pad2[0x3D0];
    f32 a[4];
    f32 b[4];
} S_003CA7E8;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C7568;

typedef int u128_t_003C7DF8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C7DF8;
typedef struct { u8 pad00[0x8C]; u8 *f8C; } S_003C7DF8;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003CA998;
typedef struct {
    u8 pad0[0xC0];
    V_003CA998 f270;
    u8 pad280[0x110 - 0xD0];
    s32 f2E8;
    u8 pad2EC[0x138 - 0x114];
    f32 f310;
} G_003CA998;
typedef struct {
    u8 pad0[0x2B0];
    u8 f2B0[0x100];
    u8 f3B0[0x6D0 - 0x3B0];
    G_003CA998 *f6D0;
    u8 pad6D4[0x6F0 - 0x6D4];
    f32 f6F0;
    f32 f6F4;
    u8 pad6F8[0x74C - 0x6F8];
    f32 f74C;
    f32 f750;
} P_003CA998;
typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1C[0x20 - 0x1C];
    u8 f20;
    u8 pad21[0x68 - 0x21];
    P_003CA998 *f68;
    u8 pad6C[0xBC - 0x6C];
    u8 fBC;
    u8 padBD[3];
    V_003CA998 fC0;
    V_003CA998 fD0;
    V_003CA998 fE0;
    f32 fF0;
    f32 fF4;
} M_003CA998;

typedef struct {u8 a[0x19E0];int f19E0;short f19E4;u8 b[0x25C0-0x19E6];u8 *f25C0;int f25C4;u8 c[0x280C-0x25C8];int f280C;} Hero;
typedef struct {int a,b,c;} Other;

typedef int Q_003C5F38 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L09_003C5E78);

INCLUDE_ASM("asm/levels", func_L09_003C6388);

INCLUDE_ASM("asm/levels", func_L09_003C6890);

INCLUDE_ASM("asm/levels", func_L09_003C6900);

/* localdecomp:start func_L09_003C6C38 */
/* PAL port of the NTSC-U match src/us/levels/func_L09_003C52C0.c */
#include "vu0.h"
extern void func_L09_003C6900(void *,void *);
extern void func_L01_004F50C8(void *,void *,int,int);
extern void func_L01_004450F0(void *,int,int);

extern Hero D_1A4BE0[];

extern Other D_L09_002D1E30[];
void func_L09_003C6C38(u8 *m) {
    vu0_v4 a,b;
    u8 *p=*(u8 **)(m+0x68);
    u8 *v;
    u8 *v2;
    *(vu0_q *)&b=*(vu0_q *)(m+0xF0);
    b.x=0.0f;b.y=0.0f;
    func_L09_003C6900(m,&a);
    if(D_1A4BE0[0].f25C4==49)func_L01_004F50C8(&a,&b,0,1);
    else func_L01_004F50C8(&a,&b,D_1A4BE0[0].f25C4,1);
    D_1A4BE0[0].f280C=0;
    D_1A4BE0[0].f19E0=0;
    D_1A4BE0[0].f19E4=-1;
    D_L09_002D1E30[0].a=5;
    D_L09_002D1E30[0].c=10;
    v=*(u8 **)(p+0x6D0);
    if(*(float *)(v+0x138)<=0.080000006f && *(short *)(v+0x128)==0) {
        qzero(v+0xC0);*(int *)(*(u8 **)(p+0x6D0)+0x138)=0;
    }
    v2=D_1A4BE0[0].f25C0;
    *(int *)(v2+0x98)=*(int *)(*(u8 **)(v2+0x24)+0x10);
    func_L01_004450F0(m,3,-1);
}
/* localdecomp:end func_L09_003C6C38 */

INCLUDE_ASM("asm/levels", func_L09_003C6D50);

/* localdecomp:start func_L09_003C70C0 */
extern HrugisEffectCamera D_L09_001E29C0;
extern void func_003C2F58(void *, int, void *);
extern float func_0038D160(float, float);
extern float func_L01_00443A18(float, float);
extern float func_003824E0(float, float);
extern float func_0038DAB8(float, float);
extern void func_00382760(void *, float, float, float);
extern unsigned char *func_L01_004669B0(float, float, float, float,
                                    void *, int, void *, int, int);
extern int func_00382498(int, int);

void func_L09_003C70C0(char *object, int a1, int joint, float radius) {
    float initial[4], point[4], velocity[4];
    float heading, speed, tilt, yaw;
    unsigned char *particle;
    unsigned char *data;
    int one = 1;
    int r;
    func_003C2F58(object, a1, initial);
    heading = func_0038D160(D_L09_001E29C0.position[0] - *(float *)(object + 0x10),
                            D_L09_001E29C0.position[1] - *(float *)(object + 0x14));
    point[0] = initial[0] + func_L01_00443A18(0, radius);
    point[1] = initial[1] + func_L01_00443A18(0, radius);
    point[2] = initial[2] + func_L01_00443A18(0, radius);
    if (joint != 0) {
        speed = func_003824E0(radius * 0.020000001f, radius * 2 * 0.020000001f);
        tilt = func_L01_00443A18(0, 1.3962634f);
    } else {
        speed = func_003824E0(radius * 2 * 0.020000001f, radius * 4.0f * 0.020000001f);
        tilt = func_L01_00443A18(0.69813168f, 0.87266463f);
    }
    yaw = func_0038DAB8(heading, func_L01_00443A18(0, 1.5707964f));
    func_00382760(velocity, speed, yaw, tilt);
    particle = func_L01_004669B0(0, 1.0f, 1.01f, radius * 210000.0f,
                             point, -one, velocity, 0x101010, 0);
    if (particle != 0) {
        particle[3] = 0x44;
        *(short *)(particle + 0xA) = (func_00382498(40, 70) * 5 + 2) / 6;
        particle[9] = 0x64;
        data = particle + 0x20;
        r = func_00382498(1, 10);
        *(int *)(data + 4) = 3;
        data[0xA] = 0x7F;
        *(float *)(data + 0x1C) = (r * 5 + 2) / 6;
        data[0xB] = particle[0xA];
    }
}
/* localdecomp:end func_L09_003C70C0 */

/* localdecomp:start func_L09_003C7338 */
extern HrugisEffectCamera D_L09_001E29C0;
extern void func_003C2F58(void *, int, void *);
extern float func_0038D160(float, float);
extern float func_L01_00443A18(float, float);
extern float func_003824E0(float, float);
extern float func_0038DAB8(float, float);
extern void func_00382760(void *, float, float, float);
extern unsigned char *func_L01_004669B0(float, float, float, float,
                                    void *, int, void *, int, int);
extern int func_00382498(int, int);
extern u8 *D_L09_00220184[];

void func_L09_003C7338(char *object, int a1, int joint, float radius) {
    float initial[4], point[4], velocity[4];
    float heading, speed, tilt, yaw;
    unsigned char *particle;
    unsigned char *data;
    int r;

    func_003C2F58(object, a1, initial);
    heading = func_0038D160(D_L09_001E29C0.position[0] - *(float *)(object + 0x10),
                            D_L09_001E29C0.position[1] - *(float *)(object + 0x14));
    point[0] = initial[0] + func_L01_00443A18(0, radius);
    point[1] = initial[1] + func_L01_00443A18(0, radius);
    point[2] = initial[2] + func_L01_00443A18(0, radius);
    speed = func_003824E0(radius * 0.5f * 0.020000001f, radius * 0.020000001f);
    tilt = func_L01_00443A18(0, 1.3962634f);
    yaw = func_0038DAB8(heading, func_L01_00443A18(0, 1.5707964f));
    func_00382760(velocity, speed, yaw, tilt);
    particle = func_L01_004669B0(0, 1.0f, 1.01f, radius * 210000.0f,
                             point, -1, velocity, 0x306F6FAF, 0);
    if (particle != 0) {
        particle[3] = 0x48;
        *(short *)(particle + 0xA) = (func_00382498(40, 70) * 5 + 2) / 6;
        particle[9] = 100;
        data = particle + 0x20;
        r = func_00382498(1, 10);
        *(int *)(data + 4) = 3;
        data[0xA] = 0x7F;
        *(float *)(data + 0x1C) = (r * 5 + 2) / 6;
        data[0xB] = particle[0xA];
        particle[2] = *D_L09_00220184[0];
    }
}
/* localdecomp:end func_L09_003C7338 */

/* localdecomp:start func_L09_003C7568 */
extern s32 D_L09_001DFBC0;
extern s32 func_L01_003303B8(void*, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00382468(s32 a);
extern float func_003824E0(float, float);
extern void func_003C2F58(void *a, int b, void *c);
extern void func_L09_003C70C0(char *object, int a1, int joint, float radius);
extern void func_L09_003C7338(char *object, int a1, int joint, float radius);

void func_L09_003C7568(u8 *o, s32 n, s32 *arr) {
    V4_003C7568 v;
    s32 i;
    if (o[0xBC] == 9) {
    for (i = 0; i < n; i++) {
        if (func_00382468(2) != 0) {
            func_L09_003C70C0(o, arr[i], 0, func_003824E0(0.3f, 0.7f));
            func_L09_003C7338(o, arr[i], 0, func_003824E0(0.2f, 0.4f));
        }
    }
    if (D_L09_001DFBC0 % 30 == 0) {
        func_003C2F58(o, arr[func_00382468(n)], &v.x);
        func_L01_003303B8(&v, 0, 5, 0, 5, 10, 0, 0, 0.5f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    }
}
/* localdecomp:end func_L09_003C7568 */

/* localdecomp:start func_L09_003C7748 */

extern fn_3C5D58 *func_L01_0043B548(s32, s32);
extern void func_L09_003C6C38(u8 *);
extern void func_003C2880(u8 *);
extern u8 *D_001A65C0[];

void func_L09_003C7748(u8 *a0, s32 a1) {
    u8 *pv = *(u8 **)(a0 + 104);
    fn_3C5D58 *tbl;
    if (*(s32 *)(pv + 464) != 0) {
        tbl = func_L01_0043B548(6625, 108);
        if (a1 == 0 && D_001A65C0[0] == a0) {
            func_L09_003C6C38(a0);
        }
        tbl[0](a0);
        if (a1 != 0) {
            tbl[1](a0);
        }
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L09_003C7748 */

/* localdecomp:start func_L09_003C77E8 */
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00452310(void *, s32, void *, s32, s32, f32, f32, f32, f32, f32, s32, f32, f32, s32, s32);
extern u8 D_L09_001D66B0[8];

void func_L09_003C77E8(u8 *a0) {
    func_L01_003303B8(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.5f, 10.0f, 0.0f, 2.0f,
                      0, 0, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                      0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_L01_00452310(a0, 0x3FF, D_L09_001D66B0, 1, 0x23, -1.0f, 3.0f, 6.0f, 5.0f, 15.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
}
/* localdecomp:end func_L09_003C77E8 */

/* localdecomp:start func_L09_003C7928 */
/* PAL port of the NTSC-U match src/us/levels/func_L09_003C5F38.c */
#include "vu0.h"

extern u8 *D_L09_001E009C;
extern u8 D_L09_001DE890[8];
__asm__(".extern D_L09_001DE890, 8");
extern Hero D_1A4BE0[];
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_003E4D10(s32);
extern void func_0038CB00(void *);
extern void func_L09_003C6890(void *);
extern void func_L09_003C7748(u8 *, s32);
extern void func_L01_004450F0(void *,int,int);
extern void func_L09_003C7568(u8 *, s32, s32 *);
extern void func_L01_003F1F20(s32, s32);
extern void func_L09_003C77E8(u8 *);

void func_L09_003C7928(u8 *obj) {
    u8 *vars = *(u8 **)(obj + 0x68);
    u8 *hit = func_L01_00447490(obj, 1, 0);
    Q_003C5F38 v;
    func_003E4D10(25);
    func_0038CB00(vars + 0x36);
    if (hit != 0) {
        if (*(s16 *)(vars + 0x36) <= 0) {
            if (obj[0xBC] != 9 && obj[0xBC] != 11 && obj[0xBC] != 10) {
                *(f32 *)(vars + 0x30) -= *(f32 *)(hit + 0x2C);
                func_L09_003C6890(obj);
                *(s16 *)(vars + 0x36) = 50;
                if (*(f32 *)(vars + 0x30) < 0.0f) *(f32 *)(vars + 0x30) = 0.0f;
                if (*(f32 *)(vars + 0x30) <= 0.0f) {
                    obj[0xBC] = 9;
                    *(s16 *)(obj + 0x96) = 0;
                }
            }
        }
        obj[0xA8] = 255;
    }
    if (obj[0xBC] == 10) {
        if (*(u16 *)(obj + 0x96) >= 168) {
            s32 idx;
            u8 *q;
            if (*(s32 *)(vars + 0x7D4)) func_L09_003C7748(obj, 1);
            *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
            *(u16 *)(obj + 0x34) &= 0xFFBE;
            obj[0xBC] = 0;
            func_L01_004450F0(obj, 1, -1);
            *(Q_003C5F38 *)(obj + 0x10) = *(Q_003C5F38 *)(*(u8 **)(vars + 0x6D0) + 0xE0);
            *(Q_003C5F38 *)(obj + 0xF0) = *(Q_003C5F38 *)(*(u8 **)(vars + 0x6D0) + 0xF0);
            *(f32 *)(vars + 0x30) = (f32)*(s16 *)(vars + 0x34);
            idx = *(s32 *)(vars + 0x758);
            if (idx != -1) {
                q = D_L09_001E009C + (idx << 8);
                *(u16 *)(q + 0x34) &= 0xFFBE;
                *(u16 *)(q + 0x34) |= *(u16 *)(*(u8 **)(q + 0x24) + 0x44) & 0x1000;
                *(s32 *)(q + 0x98) = *(s32 *)(*(u8 **)(q + 0x24) + 0x10);
            }
        }
    } else if (obj[0xBC] == 9) {
        func_L09_003C7568(obj, 6, D_L09_001DE890);
        if (*(u16 *)(obj + 0x96) >= 76) {
            u8 *hero;
            obj[0xBC] = 10;
            func_L01_004450F0(obj, 4, -1);
            *(s32 *)(obj + 0x98) = 0;
            *(u16 *)(obj + 0x34) |= 0x41;
            hero = D_1A4BE0;
            if (*(u8 **)(hero + 0x19E0) == obj) {
                qzero(&v);
                func_L09_003C6C38(obj);
                *(s32 *)(hero + 0x2850) = 0;
                *(s32 *)(vars + 0x7D4) = 1;
                func_L01_003F1F20(0x1C, 0);
            } else {
                *(s32 *)(vars + 0x7D4) = 0;
            }
            func_L09_003C77E8(obj);
        }
    }
}
/* localdecomp:end func_L09_003C7928 */

INCLUDE_ASM("asm/levels", func_L09_003C7B78);

/* localdecomp:start func_L09_003C7DF8 */
#include "vu0.h"

__asm__(".extern D_L09_001DE994, 4");
__asm__(".extern D_L09_001DE998, 4");
extern f32 D_L09_001DE994;
extern f32 D_L09_001DE998;

extern S_003C7DF8 D_L09_00220018;
extern s32 func_L01_00459590(void *, s32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_003016B0(void *, s32, f32, f32);
extern void func_L01_0046A938(void *, void *, s32, f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L09_003C7DF8(u8 *a0, f32 *a1, s32 n2, s32 n3, s32 n1) {
    V4_003C7DF8 q;
    V4_003C7DF8 v;
    V4_003C7DF8 vel;
    V4_003C7DF8 pos;
    f32 r, ang, spd;
    s32 i, j;
    u8 *e;
    V4_003C7DF8 *pv;

    *(u128_t_003C7DF8 *)&q = *(u128_t_003C7DF8 *)(a0 + 0x10);
    q.w = 5.0f;
    if (func_L01_00459590(&q, 0, 32.0f) > 0) {
        for (i = 0; i < n1; i++) {
            vec_add_ab(&v, a1, a0 + 0x10);
            func_L01_003016B0(&v, 3, func_003824E0(D_L09_001DE994 * 0.75f, D_L09_001DE994 * 1.25f), 1.025f);
        }
        for (i = 0; i < n2; i++) {
            pv = &v;
            v.x = *(f32 *)(a0 + 0x10) + a1[0] + func_003824E0(-0.3f, 0.3f);
            v.y = *(f32 *)(a0 + 0x14) + a1[1] + func_003824E0(-0.3f, 0.3f);
            v.z = *(f32 *)(a0 + 0x18) + a1[2];
            r = func_003824E0(0.3f, 0.6f);
            func_L01_0046A938(pv, a1 + 2, -1, r * D_L09_001DE994 * 0.5f, 5250.0f);
        }
        for (j = 0; j < n3; j++) {
            ang = func_00382538();
            spd = func_003824E0(0.040000003f, 0.120000005f);
            vel.x = func_0038D098(ang) * spd;
            vel.y = func_0038D0B0(ang) * spd;
            vel.z = func_003824E0(0.10000001f, 0.16000001f);
            pos.x = *(f32 *)(a0 + 0x10) + a1[0] + vel.x * 8.0f;
            pos.y = *(f32 *)(a0 + 0x14) + a1[1] + vel.x * 8.0f;
            pos.z = *(f32 *)(a0 + 0x18) + a1[2] - func_003824E0(0.0f, 0.2f);
            e = func_L01_00475C60(&pos, &vel, (func_00382498(60, 120) * 5 + 2) / 6, 2, 0x80808080, 0x808080, 0,
                                  D_L09_001DE998 * 210000.0f,
                                  func_003824E0(D_L09_001DE998 * 0.5f, D_L09_001DE998) * 210000.0f, 10.0f);
            if (e != 0) {
                e[3] = 0x44;
                e[2] = *D_L09_00220018.f8C;
            }
        }
    }
}
/* localdecomp:end func_L09_003C7DF8 */

INCLUDE_ASM("asm/levels", func_L09_003C8158);

INCLUDE_ASM("asm/levels", func_L09_003C8740);

INCLUDE_ASM("asm/levels", func_L09_003C92E0);

/* localdecomp:start func_L09_003CA6A8 */
extern void func_0038D750(void *, s32, f32);


void func_L09_003CA6A8(S_003CA6A8 *p, s32 i) {
    f32 a;
    f32 sign;
    s32 s;
    s32 t;
    f32 v;
    s32 o;
    s32 q;
    s32 r;

    a = p->a[i];
    if (__builtin_fabsf(a - p->c[i]) < 0.0005f) {
        return;
    }
    sign = 1.0f;
    s = 0;
    if (i == 0) {
        s = 8;
    } else if (i == 1) {
        sign = -1.0f;
        s = 0xB;
    }
    v = a * sign;
    p->c[i] = p->a[i];
    o = s << 6;
    q = o + (s32)p;
    q += 0x1F0;
    func_0038D750((void *)q, 0, v);
    q = o + (s32)p;
    q += 0x230;
    func_0038D750((void *)q, 0, -v);
    r = o + (s32)p;
    r += 0x270;
    func_0038D750((void *)r, 0, a * 0.42f);
    t = s + 2;
    *(f32 *)((s32)p + (t << 6) + 0x200) = 1.0f;
    *(f32 *)((s32)p + (t << 6) + 0x204) = 1.0f;
    *(f32 *)((s32)p + (t << 6) + 0x208) = 1.0f - a * 1.15f;
}
/* localdecomp:end func_L09_003CA6A8 */

/* localdecomp:start func_L09_003CA7E8 */
extern void func_0038D750(void *, s32, f32);
extern f32 func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);


void func_L09_003CA7E8(S_003CA7E8 *s0, s32 idx) {
    u8 *s = (u8 *)s0;
    f32 ang;
    f32 sign;
    f32 w;
    s32 k;
    f32 *p;
    f32 *q;
    u8 *t;

    ang = s0->a[idx];
    if (__builtin_fabsf(ang - s0->b[idx]) < 0.001f) {
        return;
    }
    sign = 1.0f;
    k = 0;
    p = 0;
    q = 0;
    if (idx == 2) {
        p = (f32 *)(s + 0x6E0);
        q = (f32 *)(s + 0x6E4);
    } else if (idx == 3) {
        sign = -1.0f;
        k = 4;
        p = (f32 *)(s + 0x6E8);
        q = (f32 *)(s + 0x6EC);
    }
    w = ang * sign;
    s0->b[idx] = s0->a[idx];
    func_0038D750(s0->m[k].f10, 0, w);
    func_L01_00448728(p, w * sign, q, 0.050400004f, 0.072000004f, 0.0f, 0);
    func_0038D750(s0->m[k + 1].f10, 2, *p);
    func_0038D750(s0->m[k + 2].f10, 1, ang * 0.32f);
    t = s + (k + 2) * 64;
    *(f32 *)(t + 0x200) = 1.0f;
    *(f32 *)(t + 0x204) = 1.0f;
    *(f32 *)(t + 0x208) = 1.0f - ang * 1.15f;
}
/* localdecomp:end func_L09_003CA7E8 */

/* localdecomp:start func_L09_003CA998 */
#include "vu0.h"

__asm__(".extern D_L09_001DE9A0, 4");
extern f32 D_L09_001DE9A0;
__asm__(".extern D_L09_001DE9A4, 4");
extern f32 D_L09_001DE9A4;
__asm__(".extern D_L09_001DE9A8, 4");
extern f32 D_L09_001DE9A8;
__asm__(".extern D_L09_001DE9B0, 4");
extern f32 D_L09_001DE9B0;
__asm__(".extern D_L09_001DE9B4, 4");
extern f32 D_L09_001DE9B4;
extern f32 D_L09_001A6E40[];
extern void func_003A52A0(s32, s32, void *);
extern float func_003824E0(float, float);
extern void func_0038CE20(void *, void *, f32);
extern int func_00382498(int, int);
extern void func_L09_003C7DF8(u8*a0, f32*a1, s32 n2, s32 n3, s32 n1);
extern s32 func_0038CAD0(void *);
extern float func_0038DAB8(float, float);
extern f32 func_L01_00448728(void*, f32, void*, f32, f32, f32, s32);
extern void func_003C3FC0(void *, void *);
extern void func_L09_003CA6A8(S_003CA6A8*p, s32 i);
extern void func_L09_003CA7E8(S_003CA7E8*s0, s32 idx);
void func_L09_003CA998(M_003CA998 *m) {
    V_003CA998 v0;
    V_003CA998 v1;
    P_003CA998 *p = m->f68;
    G_003CA998 *g = p->f6D0;

    if (m->fBC == 11) {
        if (g->f2E8 >= 0x94) {
            if (g->f2E8 == 0x96) {
                func_003A52A0(10, 0, m);
            }
            func_0038CE20(&v0, &m->fC0, func_003824E0(-1.5f, 1.5f));
            func_0038CE20(&v1, &m->fD0, func_003824E0(-1.5f, 1.5f));
            vec_add_ba(&v0, &v0, &v1);
            func_0038CE20(&v1, &m->fE0, func_003824E0(-1.0f, 0.0f));
            vec_add_ab(&v0, &v0, &v1);
            func_L09_003C7DF8(m, &v0, 5, func_00382498(0x14, 0x23), 2);
        }
        m->fF0 += 0.003f;
        m->fF4 += 0.003f;
        m->f18 -= 0.01f;
        g->f310 = 0.0f;
        qzero(&g->f270);
        func_0038CAD0(&g->f2E8);
    }
    p->f6F4 = g->f310 * D_L09_001DE9A0;
    p->f6F0 = func_0038DAB8(p->f6F0, p->f6F4);
    if (m->f20 == 2) {
        func_L01_00448728((s32)&p->f74C, D_L09_001A6E40[0] * D_L09_001DE9A8, (s32)&p->f750,
                          D_L09_001DE9B0 * 0.017453292f * 0.00040000002f, D_L09_001DE9B4 * 0.017453292f * 0.00040000002f, 0.0f, 0);
        if (D_L09_001DE9A4 < p->f74C) {
            p->f74C = D_L09_001DE9A4;
        }
        if (p->f74C < -D_L09_001DE9A4) {
            p->f74C = -D_L09_001DE9A4;
        }
    }
    qzero(&v0);
    v0.x = p->f6F0;
    v0.y = p->f74C;
    func_003C3FC0(p->f2B0, &v0);
    qzero(&v0);
    v0.x = p->f6F0;
    v0.y = -p->f74C;
    func_003C3FC0(p->f3B0, &v0);
    func_L09_003CA6A8(p, 0);
    func_L09_003CA6A8(p, 1);
    func_L09_003CA7E8(p, 2);
    func_L09_003CA7E8(p, 3);
}
/* localdecomp:end func_L09_003CA998 */
