#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L21_003B0F18 */
/* PAL port of the NTSC-U match src/us/levels/func_L21_003AF360.c */
#include "vu0.h"
extern void func_003C2880(void *);
extern void func_0038CE20(void *,void *,float);
extern void func_L01_00446748(void *,void *,int,float);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern int func_003D3CB0(void *,void *,int,void *,void *);
extern u8 *D_L21_001E8458[];
extern void func_L21_003B1280(void *);
extern void func_L01_0032FE90(void *,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,float,float,float,float);
void func_L21_003B0F18(u8 *obj) {
    vu0_v4 old; u8 loc[0x30];
    vu0_v4 *op;
    u8 *v=*(u8 **)(obj+0x68);
    int hit;
    u8 *owner;
    if (++*(int *)(v+0x2c)>250) {func_003C2880(obj);return;}
    op=&old; old=*(vu0_v4 *)(obj+0x10);
    *(vu0_v4 *)(v+0x10)=*(vu0_v4 *)(obj+0xc0);
    func_0038CE20(v+0x10,v+0x10,*(float *)(v+0x28));
    vec_add_ba(obj+0x10,v+0x10,obj+0x10);
    func_L01_00446748(&loc,obj,0x10001,*(float *)(v+0x24));
    owner=*(u8 **)(obj+0xb8);
    func_L01_004CB320();
    hit=func_003D3CB0(op,obj+0x10,16,owner,&loc);
    if(hit && D_L21_001E8458[0] && *(short *)(D_L21_001E8458[0]+0xaa)==0x186d &&
       D_L21_001E8458[0][0x20]!=2 && D_L21_001E8458[0][0x20]!=5)
        D_L21_001E8458[0][0x20]=4;
    func_L01_004CB358();
    if(hit) {
        func_L01_0032FE90(obj+0x10,0,0,5,0,5,5,0,0,0,0,0,0,0,0,0,0xffde5ced,0xffe01fc8,0x407fff,0x20ff,0x8fff,0x3064ff,0x7f60a0ff,0x280000ff,0x3064ff,0,0.75f,0.0f,0.0f,0.0f);
        func_003C2880(obj);
    } else func_L21_003B1280(obj);
}
/* localdecomp:end func_L21_003B0F18 */

INCLUDE_ASM("asm/levels", func_L21_003B1118);

/* localdecomp:start func_L21_003B1280 */
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern u8 D_001D66B0;
extern u8 *D_0021E644[];

void func_L21_003B1280(u8 *arg0) {
    u8 *pos;
    s32 life;
    u8 *r;

    pos = arg0 + 0x10;
    life = func_00382498(0x14, 0x1E);
    r = func_L01_004713C8(pos, &D_001D66B0, life, 0x7FFFFFFF, func_00382498(-5, 5), 0x4F, 0, 0, 210000.0f, 0.0f, -0.00040000002f);
    if (r != 0) {
        r[2] = D_0021E644[0][3];
    }
}
/* localdecomp:end func_L21_003B1280 */

INCLUDE_ASM("asm/levels", func_L21_003B1328);

INCLUDE_ASM("asm/levels", func_L21_003B1518);

/* localdecomp:start func_L21_003B1690 */
typedef struct {
    u8 pad0[0x24];
    f32 angle;
    u8 pad28[0xC];
    s32 count;
    u8 pad38[0x8];
    vu0_q pos[4];
    f32 size[4];
} S_003B1690;

static __inline__ void copy_003B1690(vu0_q *d, vu0_q *src) {
    *d = *src;
}

extern f32 func_0038DAB8(f32, f32);
void func_L21_003B17D8(void *, s32, f32);

void func_L21_003B1690(u8 *arg0) {
    S_003B1690 *s;
    s32 i;
    s32 j;

    s = *(S_003B1690 **)(arg0 + 0x68);
    s->angle = func_0038DAB8(s->angle, -0.62831855f);
    func_L21_003B17D8(arg0 + 0x10, 0xFF, s->angle);
    for (i = 0; i < s->count; i++) {
        func_L21_003B17D8(&s->pos[i], 0xFF - i * 0x10, s->size[i]);
    }
    s->count++;
    if (s->count >= 4) {
        s->count = 3;
    }
    for (j = s->count; j >= 0; j--) {
        if (j == 0) {
            copy_003B1690(&s->pos[0], (vu0_q *)(arg0 + 0x10));
            s->size[0] = s->angle;
        } else {
            copy_003B1690(&s->pos[j], &s->pos[j - 1]);
            s->size[j] = s->size[j - 1];
        }
    }
}
/* localdecomp:end func_L21_003B1690 */

/* localdecomp:start func_L21_003B17D8 */
typedef struct {
    vu0_v4 m[4];
    s32 c40, c44, c48, c4C;
    f32 x50, x54, x58, x5C, x60, x64, x68, x6C;
    long x70, x78, x80, x88;
} S_003B17D8;
extern long func_00389598(s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L21_003B17D8(void *pos, s32 alpha, f32 ang) {
    S_003B17D8 s;
    vu0_v4 p[4];
    vu0_v4 t;
    f32 a;
    s32 c;
    s32 i;

    s.x78 = func_00389598(0x65);
    s.x80 = 0xFF9000000260L;
    s.x88 = ((long)alpha << 32) | 0x48;
    c = (alpha << 24) + 0xFF20AF;
    s.x70 = 0;
    s.c4C = c;
    s.c48 = c;
    s.c44 = c;
    s.c40 = c;
    s.x50 = 0.0f;
    s.x54 = 0.0f;
    s.x58 = 1.0f;
    s.x5C = 0.0f;
    s.x60 = 0.0f;
    s.x64 = 1.0f;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    for (i = 0; i < 4; i++) {
        a = (f32)(i * 90) * 0.017453292f;
        t.x = func_0038D098(func_0038DAB8(ang, a)) * 2.0f;
        t.y = func_0038D0B0(func_0038DAB8(ang, a)) * 2.0f;
        t.z = 0.0f;
        vec_add_ab(&p[i], pos, &t);
    }
    s.m[0] = p[0];
    s.m[2] = p[1];
    s.m[3] = p[2];
    s.m[1] = p[3];
    func_003D2DA0(&s, 0, 0);
}
/* localdecomp:end func_L21_003B17D8 */
