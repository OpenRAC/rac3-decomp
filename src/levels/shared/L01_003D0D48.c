#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef int s128_3D41E8 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x3C4];
    s16 x3C4;
    s16 x3C6;
    u8 p3C8[8];
    u8 x3D0;
    u8 x3D1;
    u8 x3D2;
    u8 p3D3;
    f32 x3D4;
    f32 x3D8;
    f32 x3DC;
    u8 p3E0[0xC];
    s32 x3EC;
} V_3D41E8;
typedef struct {
    u8 p0[0x10];
    s128_3D41E8 x10;
    u8 p20[3];
    u8 x23;
    u8 p24[0xC];
    u8 x30;
    u8 x31;
    u16 x32;
    u16 x34;
    u8 p36[0x32];
    V_3D41E8 *x68;
    u8 p6C[0x10];
    u16 x7C;
    u8 p7E[0x42];
    u8 xC0[1];
} M_3D41E8;
typedef struct {
    u8 pad0[0x40];
    u8 mtx[0x15];
    u8 alpha;
    u8 pad56[0x60 - 0x56];
} Elem_003D4478;
typedef struct {
    Elem_003D4478 elem[10];
    u8 pad[0x3C4 - 0x3C0];
    s16 h3C4;
    s16 h3C6;
    u8 pad3C8[0x3D0 - 0x3C8];
    u8 mode;
    u8 pad3D1;
    u8 count;
    u8 pad3D3[0x3D8 - 0x3D3];
    f32 w;
    f32 h;
    u8 pad3E0[0x3EC - 0x3E0];
    u32 color;
} Hdr_003D4478;
typedef struct {
    f32 v[4][4];
    u32 color[4];
    f32 uv[8];
    u8 pad[0x20];
} Quad_003D4478;
typedef struct {
    u8 pad[0x68];
    Hdr_003D4478 *data;
} Moby_003D4478;
typedef int u128_3D6FB0 __attribute__((mode(TI)));
struct M_3D6FB0;
typedef struct { struct M_3D6FB0 *arr[15]; s16 h3C; u8 p3E[2]; f32 f40; f32 f44; u8 b48; u8 b49; u8 b4A; u8 b4B; } V_3D6FB0;
typedef struct M_3D6FB0 {
    u8 p0[0x10]; u128_3D6FB0 pos; u8 p20[0x10];
    u8 b30; u8 b31; s16 h32; u8 p34[0x34]; V_3D6FB0 *w68;
} M_3D6FB0;

INCLUDE_ASM("asm/levels", func_L01_003D0D48);

INCLUDE_ASM("asm/levels", func_L01_003D1210);

/* localdecomp:start func_L01_003D1848 */
f32 func_L01_00446630(s32, s32, s32, void *);
extern u8 D_001A4C60[];
extern s32 D_L01_001E0100;

void func_L01_003D1848(s32 arg0, void *arg1) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = func_L01_00446630(arg1 + 0x140, D_L01_001E0100 + ((*(s32 *)arg1) << 7) + 0x30, D_L01_001E0100 + ((*(s32 *)((u8 *)arg1 + 4)) << 7) + 0x30, D_001A4C60);
    temp_f2 = *(f32 *)((u8 *)arg1 + 8);
    *(f32 *)((u8 *)arg1 + 0x30) = temp_f0;
    *(f32 *)((u8 *)arg1 + 0x54) = (f32) (temp_f2 + (((*(f32 *)((u8 *)arg1 + 0xC)) - temp_f2) * temp_f0));
}
/* localdecomp:end func_L01_003D1848 */

/* localdecomp:start func_L01_003D18C0 */
extern void func_L01_003D1E30(void);
extern void func_L01_003D2300(void);
extern void func_L01_00404A10(void *, s32);

void func_L01_003D18C0(s32 a0, s32 *a1) {
    if (a1[4] >= 0) {
        func_L01_003D1E30();
        func_L01_00404A10(func_L01_003D2300, a0);
    }
}
/* localdecomp:end func_L01_003D18C0 */

INCLUDE_ASM("asm/levels", func_L01_003D1900);

INCLUDE_ASM("asm/levels", func_L01_003D1A50);

/* localdecomp:start func_L01_003D1C60 */
#include "vu0.h"
__asm__(".extern D_L01_001DF334, 4");
__asm__(".extern D_L01_001DF32C, 4");
__asm__(".extern D_L01_001DF330, 4");
__asm__(".extern D_L01_001DF338, 4");
__asm__(".extern D_L01_001DF33C, 4");
__asm__(".extern D_L01_001DF300, 4");
extern s32 D_L01_001E0100;
extern f32 D_L01_001DF334;
extern f32 D_L01_001DF32C;
extern f32 D_L01_001DF330;
extern f32 D_L01_001DF338;
extern f32 D_L01_001DF33C;
extern f32 D_L01_001DF300;
extern s32 D_L01_001DFB40;
void func_L01_003D1C60(u8 *obj, u8 *state)
{
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern u8 *func_L01_003D1900(u8 *, u8 *, f32 *, f32);
    f32 pos[4], base[4];
    f32 r, radius, angle;
    s32 i;
    u8 *p;
    if(*(s32 *)(state+0x10)<0) return;
    func_0038CE20(base,(f32 *)(obj+0xD0),D_L01_001DF334);
    vec_add_ab(base,base,(void *)((*(s32 *)(state+0x64)<<7)+D_L01_001E0100+0x30));
    for(i=0;i<160;i++) {
        r=func_003824E0(0.05f,1.0f);
        radius=(1.0f-r*r*r)**(f32 *)(state+0x54)*2.0f+5.0f;
        r=func_003824E0(D_L01_001DF32C*0.017453292f,D_L01_001DF330*0.017453292f);
        angle=func_0038DAB8(*(f32 *)(obj+0xF8),r);
        pos[0]=func_0038D098(angle)*radius;
        pos[1]=func_0038D0B0(angle)*radius;
        pos[2]=0.0f;
        pos[2]+=func_003824E0(D_L01_001DF338,D_L01_001DF33C);
        vec_add_ab(pos,pos,base);
        p=func_L01_003D1900(obj,state,pos,1.0f);
        if(p==0) break;
        *(f32 *)(p+0x14)=1.0f;
    }
    *(s32 *)(state+0x1C)=D_L01_001DFB40+(((s32)D_L01_001DF300*5+2)/6);
    *(f32 *)(state+0x20)=12.0f;
}
/* localdecomp:end func_L01_003D1C60 */

INCLUDE_ASM("asm/levels", func_L01_003D1E30);

/* localdecomp:start func_L01_003D2158 */
extern s32 D_0016C580[];
extern u8 D_L01_0023ACC0[];
extern u8 D_L01_001D98B0[] __attribute__((section(".sdata")));
extern u8 D_L01_001D98C0[] __attribute__((section(".sdata")));
extern u8 D_L01_001D98D0[] __attribute__((section(".sdata")));
extern u8 D_L01_001D98E0[] __attribute__((section(".sdata")));
extern u8 D_L01_001D98F0[] __attribute__((section(".sdata")));
extern u8 D_L01_001D9900[] __attribute__((section(".sdata")));
extern u8 D_L01_001D9910[] __attribute__((section(".sdata")));
extern f32 D_L01_001D9920;
__asm__(".extern D_L01_001D9920, 16");
void func_L01_003D2158(s32 unused, u8 *state) {
    extern void func_0038D308(void *, void *);
    extern void func_0038CB78(s32, s32, s32);
    extern void func_L01_0043A430(void *, s32, s32);
    extern void func_0038D750(void *, s32, f32);
    extern void func_003C6680(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
    u8 *row = (u8 *)D_L01_001E0100 + (*(s32 *)(state + 0x64) << 7);
    *(u128_t *)((u8 *)D_0016C580[0] + 0x10) = *(u128_t *)(row + 0x30);
    *(u128_t *)((u8 *)D_0016C580[0] + 0xF0) = *(u128_t *)(row + 0x70);
    func_0038D308((u8 *)D_0016C580[0] + 0xC0, (u8 *)D_0016C580[0] + 0xF0);
    if (*(s32 *)(state + 0x60)) {
        func_0038CB78((s32)(state + 0x70), 0, 0x40);
        func_L01_0043A430((void *)D_0016C580[0], 0, (s32)(state + 0x70));
        func_0038D750(state + 0x80, 1, -1.3962634f);
    }
    D_L01_001D9920 = *(f32 *)((u8 *)D_0016C580[0] + 0x18);
    func_003C6680((void *)D_0016C580[0], D_L01_0023ACC0, 0, 0,
                 D_L01_001D98E0, D_L01_001D98F0, D_L01_001D98B0, D_L01_001D9910,
                 D_L01_001D9900, D_L01_001D98C0, D_L01_001D98D0);
}
/* localdecomp:end func_L01_003D2158 */

/* localdecomp:start func_L01_003D2278 */
extern s32 D_0016C580[];
extern void func_003C2C98(s32, void *);

void func_L01_003D2278(s32 a0, u8 *a1) {
    if (*(s32 *)(a1 + 96)) {
        func_003C2C98(D_0016C580[0], a1 + 112);
    }
}
/* localdecomp:end func_L01_003D2278 */

/* localdecomp:start func_L01_003D22A8 */
extern s32 D_L01_001DF320;
__asm__(".extern D_L01_001DF320, 4");
extern s32 D_001A4E18[];
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
void func_L01_003D22A8(void) {
    D_001A4E18[0] = (D_L01_001DF320 * 5 + 2) / 6;
    func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
}
/* localdecomp:end func_L01_003D22A8 */

INCLUDE_ASM("asm/levels", func_L01_003D2300);

INCLUDE_ASM("asm/levels", func_L01_003D25D8);

INCLUDE_ASM("asm/levels", func_L01_003D2A18);

INCLUDE_ASM("asm/levels", func_L01_003D2B50);

INCLUDE_ASM("asm/levels", func_L01_003D2F58);

/* localdecomp:start func_L01_003D3090 */
extern void func_L01_003D2A18(void *, void *);
extern void func_L01_003D2B50(void *, void *);
extern void func_L01_003D2F58(void *, void *);

void func_L01_003D3090(void *a0, u8 *a1) {
    if (*(s32 *)(a1 + 52) != 0) {
        func_L01_003D2A18(a0, a1);
        func_L01_003D2B50(a0, a1);
        func_L01_003D2F58(a0, a1);
    }
}
/* localdecomp:end func_L01_003D3090 */

/* localdecomp:start func_L01_003D30E8 */
int func_L01_003D30E8(u8 *a) {
    u8 *p = *(u8 **)(a + 104);
    return *(s32 *)(p + 232) > *(s32 *)(p + 228);
}
/* localdecomp:end func_L01_003D30E8 */

INCLUDE_ASM("asm/levels", func_L01_003D3100);

INCLUDE_ASM("asm/levels", func_L01_003D3CF8);

/* localdecomp:start func_L01_003D3EE0 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
typedef struct {u8 pad[0x368];s16 mode;} Hero_003D3EE0;
extern s32 D_L01_001D6740_003D3EE0;
__asm__(".extern D_L01_001D6740_003D3EE0, 16");
extern s32 D_L01_001D673C_003D3EE0;
__asm__(".extern D_L01_001D673C_003D3EE0, 16");
extern vu0_v4 D_L01_001E29C0_003D3EE0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_L01_001D67B0_003D3EE0;
__asm__(".extern D_L01_001D67B0_003D3EE0, 16");
extern s32 D_L01_001D67B0;
u8 *func_L01_003D3EE0(u8 *src) {
    extern u8 *func_003C24B0(s32,s32);
    extern f32 func_003824E0(f32,f32);
    extern s32 func_00382498(s32,s32);
    extern f32 func_00382538(void);
    extern void func_0038D570(void *,void *);
    extern void func_003C48A8(void *,void *);
    extern s32 func_003D5630(void);
    extern void func_0038CF68(vu0_v4 *,vu0_v4 *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_L01_0045BD78(void *,f32,f32,f32,f32);
    extern void func_L01_003D4788(s32 *);
    extern u8 *func_00382348(void *);
    extern void func_L01_00459C50(s32);
    extern void func_L01_004443E8(void *,s32,s32);
    extern void func_003C2880(u8 *);
    extern void func_003C7C38(void *);
    union {f32 matrix[16];vu0_v4 row[4];} work;
    f32 matrix2[16];
    u8 *m=func_003C24B0(0x1BC3,0x200);
    u8 *p,*link;
    if(m) {
        m[0x30]=127;
        *(s16 *)(m+0x32)=127;
        m[0x31]=1;
        p=*(u8 **)(m+0x68);
        *(f32 *)(m+0x48)=func_003824E0(0.85f,1.15f);
        *(f32 *)(m+0x2C)=*(f32 *)(*(u8 **)(m+0x24)+0x24)*0.9f;
        *(u16 *)(m+0x34)|=0x20;
        *(vu0_q *)(m+0x10)=*(vu0_q *)(src+0x10);
        if(D_L01_001D6740_003D3EE0 || D_L01_001D673C_003D3EE0) {
            func_0038D570(work.matrix,src+0xC0);
            func_003C48A8(work.matrix,m+0xF0);
        } else if(func_003D5630()==2 || ((Hero_003D3EE0 *)&D_001A4BE0)->mode) {
            u8 *rot=m+0xF0;
            work.row[0]=*(vu0_v4 *)(src+0xE0);
            func_0038CF68(&work.row[0],&work.row[0],-1.0f);
            vec_sub_ba(&work.row[1],&D_L01_001E29C0_003D3EE0,src+0x10);
            func_0038CF68(&work.row[1],&work.row[1],1.0f);
            func_0038CE90(&work.row[1],&work.row[1],&work.row[0]);
            func_0038CE90(&work.row[2],&work.row[1],&work.row[0]);
            *(vu0_q *)(m+0xC0)=*(vu0_q *)&work.row[2];
            *(vu0_q *)(m+0xD0)=*(vu0_q *)&work.row[1];
            *(vu0_q *)(m+0xE0)=*(vu0_q *)&work.row[0];
            *(vu0_q *)(m+0xF0)=*(vu0_q *)(src+0x10);
            func_0038D570(matrix2,m+0xC0);
            func_003C48A8(matrix2,rot);
        } else {
            qzero(m+0xF0);
            *(f32 *)(m+0xF8)=func_00382538();
        }
        *(s16 *)(p+0x166)=0;
        *(s16 *)(p+0x164)=func_00382498(100,250);
        *(s32 *)(p+0x180)=500;
        *(s32 *)(p+0x184)=25;
        *(s32 *)(p+0x188)=375;
        *(s32 *)(p+0x16C)=0;
        if(((Hero_003D3EE0 *)&D_001A4BE0)->mode) m[0x20]=7;
        else if(D_L01_001D673C_003D3EE0) {
            m[0x20]=9;
            *(s32 *)(p+0x188)=1083;
        } else {
            *(s32 *)(p+0x188)=1167;
            m[0x20]=4;
        }
        *(u8 **)p=p+0x120;
        p[0x129]=1;
        *(u8 **)(p+0x1C)=p+0x30;
        *(f32 *)(p+0x64)=0.5f;
        *(f32 *)(p+0x34)=0.25f;
        *(f32 *)(p+0x30)=0.45f;
        *(f32 *)(p+0x60)=2.094395160675049f;
        *(f32 *)(p+0x5C)=0.003920000046491623f;
        *(f32 *)(p+0x38)=0.75f;
        *(f32 *)(p+0x3C)=1.0f;
        *(f32 *)(p+0x40)=1.5707963705062866f;
        func_L01_0045BD78(m,0.000800000037997961f,0.015000000596046448f,0.005026548635214567f,0.25132742524147034f);
        func_L01_003D4788((s32 *)m);
        *(s32 *)(m+0x98)=*(s32 *)(*(u8 **)(m+0x24)+0x10);
        *(f32 *)(p+0x178)=4.0f;
        *(s32 *)(p+0x170)=-1;
        link=func_00382348(src);
        if(link)link[0x17]=143;
        if(D_001D545C==5 && *(s16 *)(src+0xAA)==0x19DB) {
            s32 n=D_L01_001D67B0_003D3EE0+1;
            D_L01_001D67B0=n;
            if(n>=15)func_L01_00459C50(7);
        }
        if(*(u16 *)(m+0x34)&0x1000)func_L01_004443E8(src,0,3);
        if(link && link[0xE]==1)link[0xE]=2;
        else func_003C2880(src);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L01_003D3EE0 */

INCLUDE_ASM("asm/levels", func_L01_003D42D0);

/* localdecomp:start func_L01_003D4718 */
extern s32 D_L01_001E2360[1];

int func_L01_003D4718(void)
{
    int i = 0;
    s32 *p = D_L01_001E2360;

    for (; i < 12; i++, p++) {
        if (*p == 0)
            return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_003D4718 */

/* localdecomp:start func_L01_003D4750 */
extern s32 D_L01_001E2360[1];
void func_L01_003D4750(void *arg) {
    int i = 0;
    s32 *p = D_L01_001E2360;
    for (; i < 12; i++, p++) {
        if (*p == (s32)arg) {
            *p = 0;
            return;
        }
    }
}
/* localdecomp:end func_L01_003D4750 */

/* localdecomp:start func_L01_003D4788 */
extern s32 func_L01_003D4718(void);
extern void func_L01_003D42D0(void *);
extern void func_L01_003D4750(void *);
extern s32 func_00382468(s32);

void func_L01_003D4788(s32 *arg) {
    s32 i;
    s32 **slot;
    if (((s32 (*)(s32 *))func_L01_003D4718)(arg) == 0) {
        for (i = 0; i < 12; i++) {
            if (((s32 **)D_L01_001E2360)[i] == 0) {
                ((s32 **)D_L01_001E2360)[i] = arg;
                return;
            }
        }
    } else {
        slot = &((s32 **)D_L01_001E2360)[func_00382468(12)];
        func_L01_003D42D0(*slot);
        func_L01_003D4750(*slot);
        *slot = arg;
    }
}
/* localdecomp:end func_L01_003D4788 */

INCLUDE_ASM("asm/levels", func_L01_003D4828);

/* localdecomp:start func_L01_003D4BB0 */

extern u8 *func_003C24B0(s32, s32);

u8 *func_L01_003D4BB0(u8 *src) {
    u8 *o = func_003C24B0(7110, 128);
    if (o != 0) {
        *(u128_t *)(o + 16) = *(u128_t *)(src + 16);
        o[48] = 64;
        *(u8 **)(o + 184) = src;
    }
    return o;
}
/* localdecomp:end func_L01_003D4BB0 */

/* localdecomp:start func_L01_003D4C00 */
void func_L01_003D4C00(void) {

}
/* localdecomp:end func_L01_003D4C00 */

/* localdecomp:start func_L01_003D4C08 */
typedef struct {
    u8 pad0[0x20];
    u32 color0, color1, color2, color3;
    u8 pad30[0xC0 - 0x30];
    s32 time0, time1;
    u8 *second;
    u8 padCC[4];
    u8 *first;
    u8 padD4[0xE0 - 0xD4];
} Pair_003D4C08;
typedef struct { u8 pad[0x1C]; f32 width, height; } Style_003D4C08;
typedef struct {
    Pair_003D4C08 pairs[3];
    Style_003D4C08 *style;
    s32 count;
} Effect_003D4C08;
typedef struct { u8 pad0[0x20]; u8 state; u8 pad21[0x30-0x21]; u8 opacity; u8 pad31; u16 group; u16 flags; u8 pad36[0x68-0x36]; Effect_003D4C08 *data; u8 pad6C[0x98-0x6C]; s32 update; } Moby_003D4C08;
__asm__(".extern D_L01_001DF3C0, 4");
__asm__(".extern D_L01_001DF3B8, 4");
__asm__(".extern D_L01_001DF3BC, 4");
extern Style_003D4C08 D_L01_001DF3C0 __attribute__((section(".sdata")));
extern u32 D_L01_001DF3B8;
extern u32 D_L01_001DF3BC;
u8 *func_L01_003D4C08(s32 count, u8 **objects, s32 mode, s32 maximum, s32 ticks, f32 scale) {
    extern u8 *func_003C24B0(s32, s32);
    extern void func_L01_004AA7E8(u8 *, s32);
    Moby_003D4C08 *m;
    s32 pair = 0;
    s32 limit;
    Effect_003D4C08 *data;
    s32 index;
    s32 accepted;
    Pair_003D4C08 *entry;
    u8 *object;
    m = (Moby_003D4C08 *)func_003C24B0(0x1BE6, 0x2B0);
    if (m != 0) {
        data = m->data;
        m->group = 255;
        m->opacity = 255;
        m->state = 0;
        data->style = &D_L01_001DF3C0;
        data->style->height = scale * 0.02f;
        data->style->width = scale * 0.05f;
        limit = maximum < 4 ? maximum : 3;
        data->count = limit;
        index = 0;
        accepted = 0;
        while (accepted < count && pair < data->count) {
            object = objects[index];
            if (object == 0 || object[0x20] == 0xFE || object[0x20] == 0xFD || (*(u16 *)(object + 0x34) & 2)) goto next;
            entry = &data->pairs[pair];
            if (entry->first == 0) {
                entry->first = object;
                switch (mode) {
                case 1: D_L01_001DF3B8 = 0xFF0086FF; D_L01_001DF3BC = 0x200057FF; break;
                case 4: D_L01_001DF3B8 = 0xFFEB86C9; D_L01_001DF3BC = 0x20BA008D; break;
                case 5: D_L01_001DF3B8 = 0xFFBEDB6B; D_L01_001DF3BC = 0x200057FF; break;
                case 2: D_L01_001DF3B8 = 0xFFD1C0FF; D_L01_001DF3BC = 0x204500FF; break;
                case 3:
                default: D_L01_001DF3B8 = 0xFFE6925B; D_L01_001DF3BC = 0x20A40032; break;
                }
                {
                    Pair_003D4C08 *color = &data->pairs[pair];
                    color->color0 = D_L01_001DF3B8;
                    color->color2 = D_L01_001DF3BC;
                    color->color1 = D_L01_001DF3B8;
                    color->color3 = D_L01_001DF3BC;
                }
            } else {
                entry->second = object;
                entry->time1 = (ticks * 5 + 2) / 6;
                entry->time0 = (ticks * 5 + 2) / 6;
                pair++;
            }
            accepted++;
next:
            index++;
        }
        m->update = 0;
        m->flags = (m->flags | 0x41) & 0xEFFF;
        func_L01_004AA7E8((u8 *)m, 1);
    }
    return (u8 *)m;
}
/* localdecomp:end func_L01_003D4C08 */

/* localdecomp:start func_L01_003D4E70 */
extern void func_L01_0040C948(u8 *, s32);
void func_L01_003D4E70(u8 *a0) {
    s32 i;
    u8 *p = *(u8 **)(a0 + 104);
    for (i = 0; i < *(s32 *)(p + 676); i++) {
        if (*(s32 *)(p + i * 224 + 192) > 0) {
            func_L01_0040C948(p + i * 224, *(s32 *)(p + 672));
        }
    }
}
/* localdecomp:end func_L01_003D4E70 */

/* localdecomp:start func_L01_003D4EE0 */
void func_L01_003D4EE0(void *dst, u8 *obj) {
    func_0038D000(dst, *(u8 **)(obj + 0x68) + 0x20, obj + 0xC0);
    vec_add_ba(dst, dst, obj + 0x10);
}
/* localdecomp:end func_L01_003D4EE0 */

INCLUDE_ASM("asm/levels", func_L01_003D4F30);

/* localdecomp:start func_L01_003D5198 */
extern void func_L01_00404A10_003D5198(void *, s32);
extern void func_003C2880(u8 *);
extern void func_L01_004450F0(u8 *, int, int);
extern void func_L01_003D4F30(u8 *, int);
extern void func_L01_003D4E70(u8 *);

void func_L01_003D5198(u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);
    u8 *e;
    u8 *t;
    int i;

    if (m[0x20] == 0) {
        for (i = 0; i < *(int *)(pv + 676); i++) {
            e = pv + i * 224;
            t = *(u8 **)(e + 208);
            if (t == 0) {
                goto kill;
            }
            if (t[0x20] == 254) {
                goto kill;
            }
            if (t[0x20] == 253) {
                goto kill;
            }
            if (*(u16 *)(t + 0x34) & 2) {
                goto kill;
            }
            t = *(u8 **)(e + 200);
            if (t == 0) {
                goto ok;
            }
            if (t[0x20] == 254) {
                goto kill;
            }
            if (t[0x20] == 253) {
                goto kill;
            }
            if (!(*(u16 *)(t + 0x34) & 2)) {
                goto ok;
            }
        kill:
            func_L01_004450F0(m, 1, -1);
            continue;
        ok:
            func_L01_003D4F30(m, i);
            ((void (*)(void (*)(u8 *), u8 *))func_L01_00404A10_003D5198)(func_L01_003D4E70, m);
        }
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L01_003D5198 */

INCLUDE_ASM("asm/levels", func_L01_003D52A8);

/* localdecomp:start func_L01_003D57E8 */
#include "vu0.h"
extern u8 D_001A4C60[];
void func_L01_003D57E8(vu0_v4 *p) {
    extern f32 func_0038CE68(vu0_v4 *, vu0_v4 *);
    extern f32 func_0038CED8(vu0_v4 *);
    extern void func_0038CF68(vu0_v4 *, vu0_v4 *, f32);
    vu0_v4 d, e;
    f32 dot, dist, strength, z;
    vec_sub_ba(&d, p, D_001A4C60 + 0x60);
    vec_sub_ab(&e, D_001A4C60, D_001A4C60 + 0x2260);
    if (d.z < 0.0f) { d.z *= 0.05f; }
    if (d.z < 0.0f) { z = d.z * 0.02f; } else { z = 0.005f; }
    d.z = z;
    dot = func_0038CE68(&d, &e);
    dist = func_0038CED8(&d);
    if (3.5f - dist > 0.0f) {
        if (dot > -0.5f && dot < 0.0f) { dot = -0.5f; }
        if (dot < 0.1f && dot >= 0.0f) { dot = 0.1f; }
        strength = (3.5f - dist) / 3.5f;
        dist = func_0038CED8(&e);
        func_0038CF68(&d, &d, dist * strength * 1.6f * dot);
        vec_add_ab(p, p, &d);
    }
}
/* localdecomp:end func_L01_003D57E8 */

INCLUDE_ASM("asm/levels", func_L01_003D59C0);

/* localdecomp:start func_L01_003D5C98 */
extern void func_L01_004450F0(u8 *, int, int);
extern u8 *func_003C24B0(s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_00382468(s32);
extern void func_L01_003D59C0(M_3D41E8 *, s32, void *, void *, f32, f32, f32, f32, f32);
extern f32 func_003824E0(f32, f32);

M_3D41E8 *func_L01_003D5C98(M_3D41E8 *o, s128_3D41E8 *pos, s32 n, s32 mode, s32 a, s32 b, u8 c,
                        f32 f0, f32 f1, f32 f2, f32 f3, f32 f4) {
    M_3D41E8 *m = ((M_3D41E8 * (*)(s32, s32))func_003C24B0)(7181, 1008);
    if (m) {
        V_3D41E8 *v;
        s32 i;
        v = m->x68;
        m->x30 = o->x30;
        m->x32 = o->x30;
        m->x10 = *pos;
        ((void (*)(M_3D41E8 *, s32, s32))func_L01_004450F0)(m, 0, -1);
        v->x3D1 = c;
        v->x3D0 = mode;
        v->x3D2 = n;
        v->x3D4 = func_003C3D30(pos, 0, 0, 0.5f) + 0.1f;
        if (v->x3D0 == 1) {
            v->x3EC = func_00382468(2) ? 0x7F205050 : 0x7F50A0A0;
        }
        for (i = 0; i < n && i < 10; i++) {
            func_L01_003D59C0(m, i, pos, o->xC0, f3, f4, f0, f1, f2);
        }
        if (mode == 0) {
            m->x23 = 127;
            m->x31 = 1;
            m->x34 &= ~1;
            m->x7C = (1 << func_00382468(4)) - 0x8000;
        } else {
            m->x31 = 0;
            m->x34 |= 1;
            v->x3C4 = a;
            v->x3C6 = b;
            v->x3D8 = func_003824E0(0.06f, 0.1f) * f3;
            v->x3DC = func_003824E0(0.06f, 0.1f) * f3;
        }
    }
    return m;
}
/* localdecomp:end func_L01_003D5C98 */

/* localdecomp:start func_L01_003D5ED0 */
extern void func_0038D000(void *, void *, void *);

void func_L01_003D5ED0(void *a0, void *a1, f32 *a2, f32 x, f32 y, f32 z) {
    a2[0] = x;
    a2[1] = y;
    a2[2] = z;
    func_0038D000(a2, a2, a1);
    vec_add_ba(a2, a2, a0);
}
/* localdecomp:end func_L01_003D5ED0 */

/* localdecomp:start func_L01_003D5F28 */




extern s32 func_00382468(s32);
extern void func_003D93B0(Quad_003D4478 *, s32, s32, s32);
extern void func_0038D308(void *, void *);
extern void func_L01_003D5ED0(void *, void *, f32 *, f32, f32, f32);
extern void func_003D2DA0(Quad_003D4478 *, s32, s32);

void func_L01_003D5F28(Moby_003D4478 *moby) {
    Quad_003D4478 q;
    u8 mtx[48];
    Hdr_003D4478 *hdr;
    Elem_003D4478 *e;
    u32 color;
    s32 odd;
    s32 i;

    hdr = moby->data;
    for (i = 0; i < hdr->count && i < 10; i++) {
        e = &hdr->elem[i];
        odd = i % 2;
        q.uv[0] = 0.0f;
        q.uv[1] = 0.0f;
        q.uv[2] = 0.0f;
        q.uv[3] = 1.0f;
        q.uv[4] = 1.0f;
        q.uv[5] = 0.0f;
        q.uv[6] = 1.0f;
        q.uv[7] = 1.0f;
        switch (hdr->mode) {
        case 1:
            color = hdr->color;
            break;
        case 2:
            color = odd ? 0x7F00E7B9 : 0x7F297E38;
            break;
        case 3:
            func_00382468(2);
            color = 0x7F54F6D9;
            break;
        default:
            color = 0x7F808080;
            break;
        }
        color &= 0xFFFFFF;
        color += e->alpha << 24;
        q.color[3] = color;
        q.color[2] = color;
        q.color[1] = color;
        q.color[0] = color;
        func_003D93B0(&q, odd ? hdr->h3C4 : hdr->h3C6, 0, 128);
        func_0038D308(mtx, hdr->elem[i].mtx);
        func_L01_003D5ED0(e, mtx, q.v[0], 0.0f, hdr->w, -hdr->h);
        func_L01_003D5ED0(e, mtx, q.v[1], 0.0f, hdr->w, hdr->h);
        func_L01_003D5ED0(e, mtx, q.v[2], 0.0f, -hdr->w, -hdr->h);
        func_L01_003D5ED0(e, mtx, q.v[3], 0.0f, -hdr->w, hdr->h);
        func_003D2DA0(&q, 0, 0);
    }
}
/* localdecomp:end func_L01_003D5F28 */

/* localdecomp:start func_L01_003D6158 */
extern void func_L01_00450DE8(void *, void *, f32, f32, f32);
extern M_3D41E8 *func_L01_003D5C98(M_3D41E8 *o, s128_3D41E8 *pos, s32 n, s32 mode, s32 a, s32 b, u8 c, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4);
void func_L01_003D6158(M_3D41E8 *a0, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13) {
    s128_3D41E8 loc;

    func_L01_00450DE8(a0, &loc, 0.35f, 0.0f, f13);
    func_L01_003D5C98(a0, &loc, a3, 1, a1, a2, 1, 0.2f, 1.0f, 0.004f, f12, 0.0f);
}
/* localdecomp:end func_L01_003D6158 */

INCLUDE_ASM("asm/levels", func_L01_003D6218);

INCLUDE_ASM("asm/levels", func_L01_003D6398);

INCLUDE_ASM("asm/levels", func_L01_003D6F10);

INCLUDE_ASM("asm/levels", func_L01_003D7168);

/* localdecomp:start func_L01_003D7288 */
#include "vu0.h"
extern u8 *D_L01_00221098_003D7288[];
void func_L01_003D7288(u8 *m,void *parent,s32 kind,s32 count,s32 mode,vu0_v4 *direction,f32 speed,f32 lo,f32 hi,f32 rotation,f32 spread) {
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32,s32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CF68(vu0_v4 *,vu0_v4 *,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_L01_003D7168(s32 *,u32 *,u32 *,s32 *);
    extern u8 *func_L01_00475C60(void *,void *,s32,s32,s32,s32,f32,f32,f32,s32);
    vu0_v4 velocity,axis,temp;
    s32 color1,color2,unused;
    s32 alpha=127;
    s32 cheap;
    s32 color;
    u8 *p=*(u8 **)(m+0x68);
    s32 mask=p[0xBD];
    cheap=func_00382468(3)==0;
    if(cheap) {mode=4;lo*=0.7f;hi*=0.7f;alpha=48;}
    func_L01_003D7168(&mode,(u32 *)&color1,(u32 *)&color2,&unused);
    if(p[0xBE]==0) func_0038CF68(&velocity,direction,speed*0.020000001f);
    else {rotation=0.0f;qzero(&velocity);}
    *(vu0_q *)&axis=0;
    axis.x=1.0f;
    if(count>0) do {
        u8 *particle;
        if(p[0xBE]==0) {
            func_0038CE20(&temp,&axis,func_003824E0(0.2f,spread)*0.020000001f);
            vec_add_ab(&velocity,&temp,&velocity);
        }
        color=func_00382468(2)?color2:color1;
        if(cheap) color|=alpha<<24;
        else color|=p[0xBC]<<24;
        if(m[0x20]==2) mask=0;
        particle=func_L01_00475C60(parent,&velocity,kind,func_00382498(-2,2),color,color&((mask<<24)|0xFFFFFF),lo**(f32 *)(p+0xB8)*210000.0f,hi**(f32 *)(p+0xB8)*210000.0f,rotation,0);
        if(particle) {
            particle[2]=cheap?D_L01_00221098_003D7288[0x61][4]:D_L01_00221098_003D7288[4][0];
            particle[3]=68;
        }
        --count;
    } while(count);
}
/* localdecomp:end func_L01_003D7288 */

/* localdecomp:start func_L01_003D7510 */
#include "vu0.h"
void func_L01_003D7510(u8 *obj,vu0_v4 *point,s32 a,s32 b,s32 c,vu0_v4 *direction,
                       f32 x,f32 y,f32 z,f32 spread,f32 distance,f32 d,f32 e) {
    extern f32 func_003824E0(f32,f32);
    extern void func_00382580(void *,f32,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_L01_003D7288(u8 *,void *,s32,s32,s32,vu0_v4 *,f32,f32,f32,f32,f32);
    vu0_v4 offset,tmp;
    u8 *data=*(u8 **)(obj+0x68);
    qzero(&offset);
    if(data[0xBE]==0) {
        offset.x=func_003824E0(-spread,spread);
        offset.y=func_003824E0(-spread,spread);
        offset.z=func_003824E0(0.0f,distance);
        if(*(u32 *)(data+0xB4)&0x80)offset.y*=0.26249998807907104f;
    } else {
        func_00382580(&offset,-spread,spread);
        func_0038CE20(&tmp,direction,func_003824E0(0.0f,distance));
        vec_add_ab(&offset,&tmp,&offset);
    }
    vec_add_ba(&offset,&offset,point);
    func_L01_003D7288(obj,&offset,a,b,c,direction,x,y,z,d,e);
}
/* localdecomp:end func_L01_003D7510 */

INCLUDE_ASM("asm/levels", func_L01_003D76C0);

INCLUDE_ASM("asm/levels", func_L01_003D79D0);

INCLUDE_ASM("asm/levels", func_L01_003D7C60);

INCLUDE_ASM("asm/levels", func_L01_003D80D0);

INCLUDE_ASM("asm/levels", func_L01_003D8298);

INCLUDE_ASM("asm/levels", func_L01_003D8780);

/* localdecomp:start func_L01_003D8B10 */
extern s32 D_L01_001DF4C0;
__asm__(".extern D_L01_001DF4C0, 4");

s32 *func_L01_003D8B10(void *self, s32 a1, s32 *out) {
    if (a1 == 0) {
        *out = 4;
        return &D_L01_001DF4C0;
    }
    return 0;
}
/* localdecomp:end func_L01_003D8B10 */

/* localdecomp:start func_L01_003D8B30 */
extern void func_L01_004450F0(u8 *, int, int);
extern u8 *func_003C24B0(s32, s32);
extern s32 func_00382468(s32);

M_3D6FB0 *func_L01_003D8B30(s32 n, M_3D6FB0 **list, s32 chance, s32 a, s32 b, f32 x, f32 y) {
    M_3D6FB0 *m;
    V_3D6FB0 *v;
    s32 i;
    m = ((M_3D6FB0 * (*)(s32, s32))func_003C24B0)(7383, 80);
    if (m == 0) return 0;
    if (n == 0 || list == 0) return 0;
    if (list[0] == 0) return 0;
    v = m->w68;
    m->h32 = 0xFF;
    m->b30 = 0xFF;
    m->pos = list[0]->pos;
    v->f40 = x;
    v->b48 = a;
    v->b49 = b;
    v->f44 = y;
    v->b4A = 0;
    v->b4B = 0;
    for (i = 0; i < n; i++) {
        if (list[i] != 0 && func_00382468(100) < chance) {
            v->arr[v->h3C] = list[i];
            v->h3C++;
        }
    }
    ((void (*)(M_3D6FB0 *, s32, s32))func_L01_004450F0)(m, 0, -1);
    return m;
}
/* localdecomp:end func_L01_003D8B30 */

LINKER_REMNANT("asm/levels", func_L01_003D8C78);

INCLUDE_ASM("asm/levels", func_L01_003D8C80);
