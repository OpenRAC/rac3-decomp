#include "common.h"

typedef struct S_L02_003532F0 {
    f32 x;
    f32 y;
    u8 pad08[0xC];
    s32 state;
    f32 t18;
    f32 t1C;
} S_L02_003532F0;
typedef struct T_L02_003532F0 {
    f32 thr;
    f32 pad[6];
} T_L02_003532F0;
typedef struct O_L02_003532F0 {
    u8 pad00[0x20];
    s32 count;
    u8 pad24[0xC];
    f32 vx;
    f32 vy;
} O_L02_003532F0;

typedef struct B_L02_00352C80 {
    s32 id;
    u8 pad04[0x1C];
    s32 cnt20;
    s32 a24;
    s32 a28;
    s32 r2C;
    u8 pad30[0x10];
    s32 cnt40;
    s32 a44;
    s32 a48;
    s32 r4C;
    s32 flag50;
    f32 f54;
    f32 f58;
} B_L02_00352C80;
typedef struct A_L02_00352C80 {
    u8 pad00[0x20];
    u8 b20;
    u8 pad21[0x47];
    B_L02_00352C80 *sub;
} A_L02_00352C80;

/* declared by functions of L02_00352C80.c, which this file was cut from */
extern T_L02_003532F0 D_L02_002B0E50[];
extern void func_L02_003536D8(s32);

/* localdecomp:start func_L02_003536D8 */
#include "vu0.h"
typedef struct { f32 u; f32 v; } UV_003536D8;
typedef struct { f32 x; f32 y; f32 z; } V3_003536D8;
typedef struct { vu0_v4 pos; f32 size; s32 state; f32 t; f32 dt; } P_003536D8;
typedef struct { u8 pad0[0xa]; u8 half; u8 padb[0xd]; s32 tex; u8 pad1c[4]; s32 count; u8 pad24[0x3c]; P_003536D8 parts[1]; } O_003536D8;
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern vu0_v4 D_L02_001E1280;
__asm__(".extern D_L02_001DCFCC, 4");
extern f32 D_L02_001DCFCC;
__asm__(".extern D_L02_001DCFD0, 8");
extern UV_003536D8 D_L02_001DCFD0[] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DD000, 4");
extern f32 D_L02_001DD000;
__asm__(".extern D_L02_001DD004, 4");
extern f32 D_L02_001DD004;
__asm__(".extern D_L02_001DD008, 4");
extern f32 D_L02_001DD008;
__asm__(".extern D_L02_001DD00C, 4");
extern f32 D_L02_001DD00C;
extern u32 D_L02_001E0420[] __attribute__((section(".sdata")));
extern UV_003536D8 D_L02_001E0440[] __attribute__((section(".sdata")));
extern V3_003536D8 D_L02_00282FA0[];

void func_L02_003536D8(s32 arg) {
    O_003536D8 *o = (O_003536D8 *)arg;
    P_003536D8 *p;
    s32 i;
    s32 j;
    f32 a;
    f32 b;
    f32 t;
    T_L02_003532F0 *k;
    vu0_v4 up;
    vu0_v4 d;
    vu0_v4 n;
    f32 s[3];

    qzero(&up);
    up.z = 1.0f;
    func_003A9440(8, 5);
    b = 0.0f;
    func_003A9440(0x14, 0xFF9000000260);
    a = b;
    func_003A9440(0x47, 0x513F1);
    func_003A9440(6, func_00389598(o->tex + 0x64));
    func_0038C750();
    func_003A9440(0x42, 0x8000000044);
    p = o->parts;
    for (i = 0; i < o->count; i++, p++) {
        if (p->state == -1) continue;
        vec_sub_ba(&d, &D_L02_001E1280, &p->pos);
        func_0038CE90(&n, &d, &up);
        func_0038CF68(&n, &n, 1.0f);
        k = &D_L02_002B0E50[p->state];
        t = p->t / k->thr;
        s[0] = func_003C4088(k->pad[0], k->pad[1], t) * p->size;
        s[1] = func_003C4088(k->pad[2], k->pad[3], t) * p->size;
        s[2] = func_003C4088(k->pad[4], k->pad[5], t) * p->size;
        if (o->half) {
            s[2] *= D_L02_001DCFCC;
            s[0] *= D_L02_001DCFCC;
            s[1] *= D_L02_001DCFCC;
        }
        for (j = 0; j < 6; j++) {
            D_L02_001E0420[j] = 0x80808080;
            D_L02_001E0440[j].u = D_L02_001DCFD0[j].u;
            D_L02_001E0440[j].v = D_L02_001DCFD0[j].v;
            switch (j) {
            case 0: case 2: case 4: a = s[0] * -D_L02_001DD000; break;
            case 1: case 3: case 5: a = s[0] * D_L02_001DD000; break;
            }
            switch (j) {
            case 0: case 1: b = D_L02_001DD004; break;
            case 2: case 3: b = D_L02_001DD008 * s[1]; break;
            case 4: case 5: b = D_L02_001DD008 * s[1] + (D_L02_001DD00C - D_L02_001DD008) * s[2]; break;
            }
            D_L02_00282FA0[j].x = p->pos.x + n.x * a + up.x * b;
            D_L02_00282FA0[j].y = p->pos.y + n.y * a + up.y * b;
            D_L02_00282FA0[j].z = p->pos.z + n.z * a + up.z * b;
        }
        func_003D3A24(6, D_L02_00282FA0, D_L02_001E0420, D_L02_001E0440, 1);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L02_003536D8 */
