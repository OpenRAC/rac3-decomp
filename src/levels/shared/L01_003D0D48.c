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
extern void func_L01_003D2300(void *);
extern void func_L01_00404A10(void *, s32);

void func_L01_003D18C0(s32 a0, s32 *a1) {
    if (a1[4] >= 0) {
        func_L01_003D1E30();
        func_L01_00404A10(func_L01_003D2300, a0);
    }
}
/* localdecomp:end func_L01_003D18C0 */

/* localdecomp:start func_L01_003D1900 */
__asm__(".extern D_L01_001DF2E0, 4");
__asm__(".extern D_L01_001DF2E4, 4");
__asm__(".extern D_L01_001DF2E8, 4");
__asm__(".extern D_L01_001DF2EC, 4");
__asm__(".extern D_L01_001DF2F0, 4");
__asm__(".extern D_L01_001DF2F4, 4");
typedef struct Particle_003D1900 {
    f32 pos[4];
    f32 size, age, angle, spin, scale;
    s32 color;
    struct Particle_003D1900 *next;
} Particle_003D1900;
extern f32 D_L01_001DF2E0;
extern f32 D_L01_001DF2E4;
extern f32 D_L01_001DF2E8;
extern f32 D_L01_001DF2EC;
extern f32 D_L01_001DF2F0;
extern f32 D_L01_001DF2F4;
u8 *func_L01_003D1900(u8 *obj, u8 *state, f32 *pos, f32 scale) {
    extern f32 func_00382538(void);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    Particle_003D1900 *p = *(Particle_003D1900 **)(state + 0x138);
    if (p == 0) return 0;
    *(Particle_003D1900 **)(state + 0x138) = p->next;
    *(u128_t *)p = *(u128_t *)pos;
    p->angle = func_00382538();
    p->spin = func_L01_00443A18(D_L01_001DF2E0 * 0.017453292f * 0.020000001f, D_L01_001DF2E4 * 0.017453292f * 0.020000001f);
    p->size = func_003824E0(D_L01_001DF2E8, D_L01_001DF2EC);
    p->scale = func_003824E0(D_L01_001DF2F0, D_L01_001DF2F4) * scale;
    p->age = 0.0f;
    p->color = func_0038DBD8(*(s32 *)(state + 0x14), *(s32 *)(state + 0x18), func_003824E0(p->age, 1.0f));
    if (*(Particle_003D1900 **)(state + 0x13C)) {
        Particle_003D1900 *q = *(Particle_003D1900 **)(state + 0x13C);
        if (p->pos[2] < q->pos[2]) {
            p->next = q;
            *(Particle_003D1900 **)(state + 0x13C) = p;
        } else {
            while (q->next && q->next->pos[2] < p->pos[2]) q = q->next;
            p->next = q->next;
            q->next = p;
        }
    } else {
        *(Particle_003D1900 **)(state + 0x13C) = p;
        p->next = 0;
    }
    return (u8 *)p;
}
/* localdecomp:end func_L01_003D1900 */

/* localdecomp:start func_L01_003D1A50 */
#include "vu0.h"
typedef struct { u8 pad[0x14]; f32 life; } Particle_003D1A50;
extern s32 D_L01_001DF2DC;
extern f32 D_L01_001DF300;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DF2DC, 4");
__asm__(".extern D_L01_001DF300, 4");
void func_L01_003D1A50(u8 *obj,u8 *state) {
    extern void func_0038CE20(void *,void *,f32);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern u8 *func_L01_003D1900(u8 *,u8 *,f32 *,f32);
    vu0_v4 point,offset;
    f32 r,angle;
    s32 i;
    Particle_003D1A50 *p;
    s32 delay;
    if(*(s32 *)(state+0x10)<0) return;
    if(*(f32 *)(state+0x30)<1.0f) {
        qzero(&offset);
        func_0038CE20(&offset,obj+0xC0,-5.0f);
        offset.z-=5.0f;
    }
    for(i=0;i<D_L01_001DF2DC;) {
        r=func_003824E0(0.0f,1.0f);
        r=(1.0f-r*r*r)* *(f32 *)(state+0x54)*2.0f+5.0f;
        angle=func_0038DAB8(*(f32 *)(obj+0xF8),func_003824E0(-0.9599310756f,0.9599310756f));
        point.x=func_0038D098(angle)*r;
        point.y=func_0038D0B0(angle)*r;
        point.z=0.0f;
        vec_add_ba(&point,&point,state+0x140);
        point.z+=func_003824E0(-12.0f,2.0f);
        if(*(f32 *)(state+0x30)<1.0f) vec_add_ab(&point,&point,&offset);
        p=(Particle_003D1A50 *)func_L01_003D1900(obj,state,(f32 *)&point,1.0f);
        if(!p) break;
        i++;
        p->life=1.0f;
    }
    delay=D_L01_001DFB40+((s32)D_L01_001DF300*5+2)/6;
    *(f32 *)(state+0x20)=12.0f;
    *(s32 *)(state+0x1C)=delay;
}
/* localdecomp:end func_L01_003D1A50 */

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

/* localdecomp:start func_L01_003D25D8 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern s32 D_L01_001E0100;
extern f32 D_L01_001E2A40[];
extern f32 D_L01_001DF380;
__asm__(".extern D_L01_001DF380, 4");
extern f32 D_L01_001DF384;
__asm__(".extern D_L01_001DF384, 4");
extern f32 D_L01_001DF388;
__asm__(".extern D_L01_001DF388, 4");
extern f32 D_L01_001DF38C;
__asm__(".extern D_L01_001DF38C, 4");
extern f32 D_L01_001DF390;
__asm__(".extern D_L01_001DF390, 4");
extern f32 D_L01_001DF394;
__asm__(".extern D_L01_001DF394, 4");
extern f32 D_L01_001DF398;
__asm__(".extern D_L01_001DF398, 4");
extern f32 D_L01_001DF39C;
__asm__(".extern D_L01_001DF39C, 4");
extern f32 D_L01_001DF3A0;
__asm__(".extern D_L01_001DF3A0, 4");
extern f32 D_L01_001DF3A4;
__asm__(".extern D_L01_001DF3A4, 4");
extern f32 D_L01_001DF3A8;
__asm__(".extern D_L01_001DF3A8, 4");
extern f32 D_L01_001DF3AC;
__asm__(".extern D_L01_001DF3AC, 4");
extern f32 D_L01_001DF3B0;
__asm__(".extern D_L01_001DF3B0, 4");
extern f32 D_L01_001DF3B4;
__asm__(".extern D_L01_001DF3B4, 4");

void func_L01_003D25D8(u8 *obj,u8 *state,void *target)
{
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DBA0(f32,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_0038D308(void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_L01_00443A18(f32,f32);
    extern void *func_L01_0043B568(s32,s32,s32);
    vu0_v4 pos,rot,vel,matrix[3],delta,angles,hero;
    f32 floor,angle,pitch,spread,limit;
    floor=*(f32 *)((*(s32 *)(state+4)<<7)+D_L01_001E0100+0x38)+*(f32 *)(state+0x3C);
    if(target==D_001A4BE0.hero_moby && *(s32 *)(state+0x5C)!=-1) {
        vec_sub_ba(&delta,(void *)((*(s32 *)(state+0x5C)<<7)+D_L01_001E0100+0x30),&D_001A4BE0.pos);
        pitch=func_0038D160(func_0038CED8(&delta),delta.z);
        angle=func_0038DBA0(D_L01_001E2A40[5],-pitch);
        if(D_L01_001DF39C*0.017453292f<angle) {
            qzero(&angles);
            angles.y=func_0038DAB8(D_L01_001E2A40[5],D_L01_001DF39C);
            angles.z=func_0038D160(delta.x,delta.y);
            func_0038D308(matrix,&angles);
            *(u128_t *)&delta=*(u128_t *)matrix;
        }
        func_0038CF68(&delta,&delta,D_L01_001DF398);
        vec_add_ba(&pos,&delta,&D_001A4BE0.pos);
        spread=func_003824E0(D_L01_001DF3A0*0.017453292f,D_L01_001DF3A4*0.017453292f);
        limit=D_L01_001DF39C*0.017453292f;
        if(limit*0.3f<angle) spread*= (angle-limit*0.3f)/(limit*0.7f);
    } else {
        func_0038CE20((f32 *)&pos,(f32 *)(obj+0xC0),func_003824E0(D_L01_001DF380,D_L01_001DF384));
        pitch=func_L01_00443A18(D_L01_001DF388,D_L01_001DF38C);
        if(target==D_001A4BE0.hero_moby) pitch*=0.25f;
        func_0038CE20((f32 *)&delta,(f32 *)(obj+0xD0),pitch);
        __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tlqc2 $vf1, %3\n\tsqc2 $vf1, %1\n\tsqc2 $vf2, %0\n\tlqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "+m"(pos), "=m"(hero) : "m"(delta), "m"(D_001A4BE0.pos) : "vf1","vf2");
        if(target && target!=D_001A4BE0.hero_moby)
            pos.z-=func_003824E0(D_L01_001DF390,D_L01_001DF394)*0.5f;
        else pos.z-=func_003824E0(D_L01_001DF390,D_L01_001DF394);
        if(target==D_001A4BE0.hero_moby)
            spread=func_003824E0(D_L01_001DF3A0*0.017453292f,D_L01_001DF3A4*0.017453292f);
        else spread=func_003824E0(D_L01_001DF3A8*0.017453292f,D_L01_001DF3AC*0.017453292f);
    }
    if(pos.z<floor) {
        if(D_001A4BE0.pos.z-floor<64.0f) return;
        if(target==D_001A4BE0.hero_moby && D_L01_001DF398*0.3f<floor-pos.z) return;
        pos.z=floor;
    }
    qzero(&rot);
    rot.y=spread;
    if(target)
        rot.z=func_0038DAB8(*(f32 *)(obj+0xF8),func_003824E0(D_L01_001DF3B0*0.017453292f,D_L01_001DF3B4*0.017453292f));
    else
        rot.z=func_0038DAB8(*(f32 *)(obj+0xF8),(func_003824E0(D_L01_001DF3B0*0.017453292f,D_L01_001DF3B4*0.017453292f)+3.1415927f)*0.5f);
    func_0038D308(matrix,&rot);
    func_0038CE20((f32 *)&vel,(f32 *)matrix,0.36f);
    (*(s32 (**)(void *,void *,void *,void *,f32))func_L01_0043B568(7556,0,4))(obj,target,&pos,&vel,(f32)*(s32 *)(state+0x48));
}
/* localdecomp:end func_L01_003D25D8 */

/* localdecomp:start func_L01_003D2A18 */
extern s32 D_001A71A0 __attribute__((section(".data")));
typedef struct {
    u8 pad0[0x30];
    f32 t;              /* 0x30 */
    u8 pad1[4];         /* 0x34 */
    s32 sel;            /* 0x38 */
    u8 pad2[0xB4];      /* 0x3C */
    f32 times[4];       /* 0xF0 */
    s32 values[4];      /* 0x100 */
} S_003D2A18;

void func_L01_003D2A18(void *obj, void *sv) {
    S_003D2A18 *s = sv;
    extern s32 func_0038CAD0(s32 *);
    s32 i;

    if (s->sel == 0) {
        if (s->t < s->times[0]) return;
        if (s->times[3] < s->t) return;
    } else if (!func_0038CAD0(&s->sel)) {
        return;
    }
    func_L01_003D25D8(obj, (u8 *)s, (void *)D_001A71A0);
    for (i = 1; i < 4; i++) {
        if (s->t < s->times[i]) {
            f32 lower = s->times[i - 1];
            s32 base = s->values[i - 1];
            s32 delta = s->values[i] - base;
            s32 value = (s32)((f32)delta * ((s->t - lower) / (s->times[i] - lower))) + base;
            s->sel = (value * 5 + 2) / 6;
            break;
        }
    }
}
/* localdecomp:end func_L01_003D2A18 */

/* localdecomp:start func_L01_003D2B50 */
typedef struct { u8 pad[8]; s32 (*test)(u8 *); } Callbacks_003D2B50;
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C[] __attribute__((section(".sdata")));
extern u8 *D_L01_001E001C_003D2B50;
extern s32 D_L01_001E0058;
__asm__(".extern D_L01_001E0058, 4");
__asm__(".extern D_L01_001E001C_003D2B50, 4");
static inline s32 state_003D2B50(u8 *m) { return m[0x20]; }
void func_L01_003D2B50(void *owner, void *state)
{
    extern Callbacks_003D2B50 *func_L01_0043B568(s32, s32, s32);
    extern s32 func_0038CAD0(s32 *);
    extern void func_L01_00446BC8(u8 *, void *, s32, u8 *, f32);
    extern void func_L01_003D25D8(u8 *, u8 *, void *);
    u8 *s=state;
    u16 *p=D_L01_0021DE20[*(s32 *)(s+0x2C)];
    s32 count=0;
    s32 index;
    f32 *thresholds;
    s32 child_index;
    u8 *child;
    s32 status;
    u8 *m;
    Callbacks_003D2B50 *vt;
    for (; (*(s32 *)(s+0x2C)&255)!=255 && *(s32 *)(s+0x2C)<=D_L01_001E0058 && p &&
         ((s16)p[-1]>=0 || p==D_L01_0021DE20[*(s32 *)(s+0x2C)]); p++) {
        m=(u8 *)((s32)D_L01_001E001C[0]+((*p&0x7FFF)<<8));
        if (!m) break;
        status=state_003D2B50(m);
        if (status==254) continue;
        if (status==253) continue;
        if (*(s32 *)(s+0x40)!=-1) {
            vt=func_L01_0043B568(*(s16 *)(m+0xAA),1,28);
            if (!vt || vt->test(m)) continue;
        }
        count++;
    }
    *(s32 *)(s+0xE8)=count;
    if (!count || count<=*(s32 *)(s+0xE4)) return;
    if (*(s32 *)(s+0xEC)!=0 && !func_0038CAD0((s32 *)(s+0xEC)) &&
        (*(s32 *)(s+0xEC)>=22 || *(f32 *)(s+0x30)<*(f32 *)(s+0xE0))) return;
    thresholds=(f32 *)(s+0xD0);
    index=5-*(s32 *)(s+0xE8);
    if (*(f32 *)(s+0x30)<*(f32 *)((s32)thresholds+(index<<2))) {
        *(s32 *)(s+0xEC)=5;
        return;
    }
    goto dispatch;
kill_child:
    child=D_L01_001E001C_003D2B50+(child_index<<8);
    func_L01_00446BC8(child,owner,0x10001,child+0x10,9999.0f);
    return;
dispatch:
    if ((index<4 && *(f32 *)((s32)thresholds+((index+1)<<2))<=*(f32 *)(s+0x30)) || 0.95f<*(f32 *)(s+0x30)) {
        for (p=D_L01_0021DE20[*(s32 *)(s+0x2C)]; (*(s32 *)(s+0x2C)&255)!=255 &&
             *(s32 *)(s+0x2C)<=D_L01_001E0058 && p &&
             ((s16)p[-1]>=0 || p==D_L01_0021DE20[*(s32 *)(s+0x2C)]); p++) {
            m=(u8 *)((s32)D_L01_001E001C[0]+((*p&0x7FFF)<<8));
            if (!m) return;
            status=state_003D2B50(m);
        if (status==254) continue;
        if (status==253) continue;
            if (*(s32 *)(s+0x40)!=-1) {
                vt=func_L01_0043B568(*(s16 *)(m+0xAA),1,28);
                if (!vt || vt->test(m)) continue;
            }
            child_index=*(s32 *)(*(u8 **)(m+0x68)+0x50);
            if (child_index!=-1) goto kill_child;
        }
    } else {
        for (p=D_L01_0021DE20[*(s32 *)(s+0x2C)]; (*(s32 *)(s+0x2C)&255)!=255 &&
             *(s32 *)(s+0x2C)<=D_L01_001E0058 && p &&
             ((s16)p[-1]>=0 || p==D_L01_0021DE20[*(s32 *)(s+0x2C)]); p++) {
            m=(u8 *)((s32)D_L01_001E001C[0]+((*p&0x7FFF)<<8));
            if (!m) break;
            status=state_003D2B50(m);
        if (status==254) continue;
        if (status==253) continue;
            if (*(s32 *)(s+0x40)!=-1) {
                vt=func_L01_0043B568(*(s16 *)(m+0xAA),1,28);
                if (!vt || vt->test(m)) continue;
            }
            func_L01_003D25D8(owner,state,m);
            break;
        }
        *(s32 *)(s+0xEC)=67;
    }
}
/* localdecomp:end func_L01_003D2B50 */

/* localdecomp:start func_L01_003D2F58 */
typedef struct { u8 pad[0x30]; f32 time; u8 pad34[0x44-0x34]; s32 timer; u8 pad48[0x110-0x48]; f32 times[4]; s32 values[4]; } State_003D2F58;
void func_L01_003D2F58(void *obj, void *arg) {
    extern s32 func_0038CAD0(s32 *);
    extern void func_L01_003D25D8(u8 *, u8 *, void *);
    State_003D2F58 *state = arg;
    s32 i;
    if (state->timer == 0) {
        if (state->time < state->times[0]) return;
        if (state->time > state->times[3]) return;
    } else {
        if (!func_0038CAD0(&state->timer)) return;
    }
    func_L01_003D25D8(obj, (u8 *)state, 0);
    for (i = 1; i < 4; i++) {
        if (state->time < state->times[i]) {
            s32 n = (s32)((f32)(state->values[i] - state->values[i-1]) *
                ((state->time - state->times[i-1]) / (state->times[i] - state->times[i-1]))) + state->values[i-1];
            state->timer = (n * 5 + 2) / 6;
            break;
        }
    }
}
/* localdecomp:end func_L01_003D2F58 */

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

/* localdecomp:start func_L01_003D3100 */
typedef struct {
    u8 p0[0xB0];
    s32 xB0;
    u8 pB4[0x168 - 0xB4];
    u8 x168[0x18];
    s32 x180;
    u8 p184[4];
    s32 x188;
} P_003D3100;
typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 p21[0x21];
    u8 x42;
    u8 p43[5];
    f32 x48;
    u8 p4C[0x14];
    u8 x60;
    u8 p61[7];
    P_003D3100 *p68;
    u8 p6C[0x10];
    s16 x7C;
    u8 p7E[0x42];
    vu0_v4 xC0;
    u8 pD0[0x20];
    vu0_v4 xF0;
} M_003D3100;
typedef struct { u8 p0[0x18]; void *w18; u8 p1C[4]; vu0_v4 v20; } T_003D3100;
typedef struct { u8 p0[1]; u8 b1; u8 p2[0xEE]; } R_003D3100;
extern T_003D3100 D_L01_001EAA00;
extern R_003D3100 D_L01_002C5600[];
extern u8 D_001425C0[];
extern void *D_L01_001DAFEC;
extern s32 D_L01_001D6740;
extern s32 D_L01_001D673C;
extern void func_0038D570(void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_L01_0044C638(void *, s32, void *, void *, void *, void *);
extern void func_0038D308(void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_0038CAD0(s32 *);
extern void func_L01_003D42D0(void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_004471A8(void *, f32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_003D3CF8(u8 *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_004455E8(void *, f32, f32, void *, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68_003D3100(vu0_v4 *, vu0_v4 *, f32);
extern s32 func_L01_0045A898(void *, void *, f32);
extern void func_003C3DA0(void *, void *, s32, s32, f32);
extern s32 func_003D5630(void);
extern void func_L01_00451290(void *, void *, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
typedef struct { u8 p0[0x368]; s16 mode; } Hero_003D3100;

void func_L01_003D3100(M_003D3100 *obj)
{
    P_003D3100 *p = obj->p68;
    vu0_v4 a, b;
    f32 angle, r;
    s32 m;

    if (obj->state != 0 && D_L01_001DAFEC != 0) {
        f32 mtx[16];
        {
        func_0038D570(mtx, &obj->xC0);
        func_003C48A8(mtx, &a);
        func_L01_0044C638(obj, (s32)D_L01_001DAFEC, &obj->pos, &a, &obj->pos, &b);
        func_0038D308(&obj->xC0, &b);
        obj->xF0 = b;
        }
    }
    m = func_L01_00447490(obj, 0x8010000, 0);
    if (func_0038CAD0(&p->x188) || m) {
        func_L01_003D42D0(obj);
    }
    if (((R_003D3100 *)((u8 *)D_L01_002C5600 + D_001425C0[0x8F] * 0xF0))->b1 >= 2) {
        obj->x7C = 3;
    }
    angle = func_0038D160(obj->pos.x - D_001A4BE0.pos.x, obj->pos.y - D_001A4BE0.pos.y);
    if (((Hero_003D3100 *)&D_001A4BE0)->mode == 0 && D_L01_001D673C == 0) {
        func_L01_004471A8(obj, 0.4f);
    }
    switch (obj->state) {
    case 0:
        func_L01_004450F0((u8 *)obj, 1, -1);
        break;
    case 1:
        if (obj->x60 & 2) {
            r = func_003824E0(0.0f, 100.0f);
            if (0.0f <= r && r < 20.0f) func_003C3A10(obj, 0, 0, 8);
            if (20.0f <= r && r < 40.0f) func_003C3A10(obj, 1, 0, 8);
            if (40.0f <= r && r < 100.0f) func_003C3A10(obj, 2, 0, 8);
        }
        if (func_L01_0044E1B8(obj, 15.0f) && obj->x42 == 2) {
            u8 n = ((R_003D3100 *)((u8 *)D_L01_002C5600 + D_001425C0[0x8F] * 0xF0))->b1;
            if (n != 0) {
                if (n < 4) {
                    func_003A52A0(0, 0, obj);
                    func_L01_003D3CF8((u8 *)obj);
                }
            }
        }
        if (obj->x42 == 2) {
            func_L01_004455E8(obj, func_0038DAB8(obj->xF0.z, 3.1415927f), 0.0004886922f, p->x168, 0.0006283186f, 0.03141593f);
        }
        if (func_0038CF38(&obj->pos, D_001A4C60) < 2.0f && D_L01_001D6740 == 0 && D_L01_001D673C == 0) {
            func_L01_004450F0((u8 *)obj, 2, -1);
            func_003C3A10(obj, 3, 0, 8);
            obj->x48 = 0.75f;
        }
        if (func_0038CAD0(&p->x180) && D_L01_001D6740 == 0 && D_L01_001D673C == 0) {
            if (func_00382468(2)) {
                func_L01_004450F0((u8 *)obj, 5, -1);
                p->x180 = (func_00382498(400, 600) * 5 + 2) / 6;
                func_003C3A10(obj, 3, 0, 8);
                obj->x48 = 0.75f;
            } else {
                func_L01_004450F0((u8 *)obj, 6, -1);
                p->x180 = (func_00382498(180, 360) * 5 + 2) / 6;
                func_003C3A10(obj, 4, 0, 8);
            }
        }
        break;
    case 6:
        if (obj->x60 & 2) {
            func_003C3A10(obj, 4, 0, 8);
        }
        if (func_0038CAD0(&p->x180)) {
            func_L01_004450F0((u8 *)obj, 1, -1);
            p->x180 = (func_00382498(120, 600) * 5 + 2) / 6;
            func_003C3A10(obj, func_00382468(2), 0, 8);
        }
        break;
    case 5:
        if (obj->x60 & 2) {
            func_003C3A10(obj, 3, 0, 8);
            obj->x48 = 0.75f;
        }
        if (func_0038CF38(&obj->pos, D_001A4C60) < 2.0f) {
            func_L01_004450F0((u8 *)obj, 2, -1);
            obj->x48 = 0.1f;
            func_003C3A10(obj, 3, 0, 8);
        }
        if (func_0038CAD0(&p->x180)) {
            func_L01_004450F0((u8 *)obj, 1, -1);
            p->x180 = (func_00382498(400, 600) * 5 + 2) / 6;
        }
        {
            vu0_v4 c;
            func_L01_004455E8(obj, func_0038DAB8(obj->xF0.z, func_003824E0(-45.0f, 45.0f) * 0.017453292f), 0.00020943953f, p->x168, 0.0006283186f, 0.015707964f);
            func_0038CF68_003D3100(&b, &obj->xC0, 10.0f);
            vec_add_ba(&a, &obj->pos, &b);
            c = obj->pos;
            func_L01_0045A898(obj, &a, obj->xF0.z);
            if (p->xB0 >= 10) {
                func_L01_004455E8(obj, func_0038DAB8(obj->xF0.z, 3.1415927f), 0.00055850536f, p->x168, 0.0006283186f, 0.015707964f);
            }
        }
        break;
    case 2:
        if (func_0038CF38(&obj->pos, D_001A4C60) < 2.0f) {
            vu0_v4 c;
            func_L01_004455E8(obj, func_0038DAB8(obj->xF0.z, func_003824E0(-30.0f, 30.0f) * 0.017453292f), 0.00020943953f, p->x168, 0.0006283186f, 0.015707964f);
            func_0038CF68_003D3100(&b, &obj->xC0, 10.0f);
            vec_add_ba(&a, &obj->pos, &b);
            c = obj->pos;
            func_L01_0045A898(obj, &a, obj->xF0.z);
            if (p->xB0 >= 10) {
                func_L01_004455E8(obj, func_0038DAB8(obj->xF0.z, 3.1415927f), 8.377581e-05f, p->x168, 0.0006283186f, 0.015707964f);
            } else if (func_0038DBA0(angle, obj->xF0.z) > 0.5235988f) {
                func_L01_004455E8(obj, angle, 0.00055850536f, p->x168, 0.0006283186f, 0.015707964f);
            }
        } else {
            obj->x48 = 1.0f;
            func_L01_004450F0((u8 *)obj, 1, -1);
        }
        break;
    case 9:
        func_003C3DA0(&obj->pos, &obj->pos, 0, 0, 0.5f);
        {
            s32 mode = func_003D5630();
            if (mode > 0 && mode != 10 && mode != 7 && D_L01_001D6740 == 0) {
                func_L01_003D42D0(obj);
                return;
            }
        }
        func_L01_004450F0((u8 *)obj, 8, -1);
        break;
    case 4:
        {
            vu0_v4 d, e, f;
            func_L01_00451290(obj, &d, 0);
            func_0038CF68_003D3100(&d, &d, 4.0f);
            vec_add_ba(&e, &obj->pos, &d);
            func_0038CF68_003D3100(&d, &d, -1.0f);
            vec_add_ba(&f, &obj->pos, &d);
            if (func_003D3CB0(&f, &e, 0, obj, 0) && D_L01_001EAA00.w18 != D_001A4BE0.hero_moby) {
                obj->pos = D_L01_001EAA00.v20;
            }
        }
        {
            s32 mode = func_003D5630();
            if (mode > 0 && mode != 10 && mode != 7 && D_L01_001D6740 == 0) {
                func_L01_003D42D0(obj);
                return;
            }
        }
        if (D_L01_001D673C != 0) {
            func_L01_004450F0((u8 *)obj, 8, -1);
        } else {
            func_L01_004450F0((u8 *)obj, 0, -1);
        }
        if (obj->x60 & 2) {
            r = func_003824E0(0.0f, 100.0f);
            if (0.0f <= r && r < 20.0f) func_003C3A10(obj, 0, 0, 8);
            if (20.0f <= r && r < 40.0f) func_003C3A10(obj, 1, 0, 8);
            if (40.0f <= r && r < 100.0f) func_003C3A10(obj, 2, 0, 8);
        }
        if (func_L01_0044E1B8(obj, 15.0f) && obj->x42 == 2) {
            u8 n = ((R_003D3100 *)((u8 *)D_L01_002C5600 + D_001425C0[0x8F] * 0xF0))->b1;
            if (n != 0) {
                if (n < 4) {
                    func_003A52A0(0, 0, obj);
                    func_L01_003D3CF8((u8 *)obj);
                }
            }
        }
        if (func_0038CAD0(&p->x188)) {
            func_L01_003D42D0(obj);
            return;
        }
        break;
    case 7:
    case 8:
        if (obj->x60 & 2) {
            r = func_003824E0(0.0f, 100.0f);
            if (0.0f <= r && r < 20.0f) func_003C3A10(obj, 0, 0, 8);
            if (20.0f <= r && r < 40.0f) func_003C3A10(obj, 1, 0, 8);
            if (40.0f <= r && r < 100.0f) func_003C3A10(obj, 2, 0, 8);
        }
        if (func_L01_0044E1B8(obj, 15.0f) && obj->x42 == 2) {
            u8 n = ((R_003D3100 *)((u8 *)D_L01_002C5600 + D_001425C0[0x8F] * 0xF0))->b1;
            if (n != 0) {
                if (n < 4) {
                    func_003A52A0(0, 0, obj);
                    func_L01_003D3CF8((u8 *)obj);
                }
            }
        }
        if (func_0038CAD0(&p->x188)) {
            func_L01_003D42D0(obj);
            return;
        }
        break;
    }
    if (D_L01_001D6740 == 0 && D_L01_001D673C == 0) {
        vu0_v4 t;
        s32 mode;
        t = obj->pos;
        t.z += 0.5f;
        obj->pos.z = func_003C3D30(&t, 0, 0, 0.5f);
        mode = func_003D5630();
        if (mode > 0 && mode != 10 && mode != 7 && mode != 2 && D_L01_001D6740 == 0) {
            func_L01_003D42D0(obj);
        }
    }
}
/* localdecomp:end func_L01_003D3100 */

/* localdecomp:start func_L01_003D3CF8 */
#include "vu0.h"
void func_L01_003D3CF8(u8 *obj)
{
    extern void func_L01_004C7D98(u8 *, f32 *);
    extern void func_0038CF68(vu0_v4 *, vu0_v4 *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_0038D000(void *, void *, void *);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_003D6218(void *, void *, s32, s32, s32);
    vu0_v4 basis[3], perp, velocity, pos;
    u8 *state = *(u8 **)(obj + 0x68);
    f32 heading, elevation, speed;
    u8 *spawn;
    func_L01_004C7D98(obj + 0x10, (f32 *)&basis[2]);
    perp.x = basis[2].z;
    perp.y = basis[2].z;
    perp.z = -(basis[2].x + basis[2].y);
    func_0038CF68(&basis[0], &perp, 1.0f);
    func_0038CE90(&basis[1], &basis[0], &basis[2]);
    basis[0].w = basis[1].w = basis[2].w = 0.0f;
    speed = func_003824E0(160.0f, 200.0f);
    heading = func_0038DAB8(*(f32 *)(obj + 0xF8), speed * 0.017453292f);
    elevation = func_003824E0(0.17453292f, 0.87266463f);
    speed = func_003824E0(2.0f, 5.0f);
    func_00382760(&velocity, speed * 0.020000001f, heading, elevation);
    velocity.w = 0.0f;
    func_0038D000(&velocity, &velocity, basis);
    *(s32 *)(state + 0x18C) = (func_00382498(60, 120) * 5 + 2) / 6;
    func_L01_004C7D98(obj + 0x10, (f32 *)&pos);
    func_0038CF68(&pos, &pos, 0.75f);
    vec_add_ba(&pos, obj + 0x10, &pos);
    spawn = func_L01_003D6218(&pos, &velocity, 0, 0, 0);
    if (spawn != 0) *(s32 *)(spawn + 0xB8) = *(s32 *)(obj + 0xB8);
}
/* localdecomp:end func_L01_003D3CF8 */

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

/* localdecomp:start func_L01_003D52A8 */
extern vu0_v4 D_L01_001D66E0 __attribute__((section(".sdata")));
extern f32 func_0038D160(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038CAD0(s32 *);
extern f32 func_L01_0044AE78(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_003D57E8(vu0_v4 *);
extern void func_L01_004450F0(u8 *, int, int);
extern void func_003C2880(u8 *);
extern void func_L01_003D5F28(Moby_003D4478 *);
extern void func_L01_00404808(void *, void *);

void func_L01_003D52A8(u8 *m) {
    vu0_v4 origin, temp;
    s32 i = 0, finished;
    u8 *p = *(u8 **)(m + 0x68);
    origin = *(vu0_v4 *)(m + 0x10);
    origin.w = *(f32 *)(p + 0x3D8) * 3.0f;
    finished = 0;
    for (; i < p[0x3D2] && i < 10; i++) {
        f32 w = *(f32 *)(p + i * 0x60 + 0xC);
        f32 radius = *(f32 *)(p + i * 0x60 + 0x4C);
        f32 fall = *(f32 *)(p + i * 0x60 + 0x1C);
        switch (p[i * 0x60 + 0x54]) {
        case 0: {
            u8 *q = p + i * 0x60;
            *(f32 *)(q + 0x48) = func_0038D160(*(f32 *)(q + 0x10), *(f32 *)(q + 0x14));
            *(f32 *)(q + 0x44) = 3.1415927f;
            q[0x54] = 1;
            *(s32 *)(q + 0x50) = (func_00382498(10, 20) * 5 + 2) / 6;
            break;
        }
        case 1: {
            u8 *q;
            vec_add_ab(p + i * 0x60, p + i * 0x60, p + i * 0x60 + 0x10);
            q = p + i * 0x60;
            func_0038CE20(q + 0x10, q + 0x10, 0.90400004f);
            if (func_0038CAD0((s32 *)(q + 0x50))) {
                func_0038CE20(&temp, q + 0x30, -radius);
                vec_add_ab(q + 0x20, &temp, q);
                *(f32 *)(q + 0x28) -= radius * 0.5f;
                *(f32 *)(q + 0x58) = 1.5707964f;
                *(f32 *)(q + 0x5C) = 3.1415927f / (w + w);
                q[0x54] = 2;
                *(s32 *)(q + 0x50) = 1000;
            }
            break;
        }
        case 2: {
            f32 angle, sine, height, vertical, linear;
            u8 *q;
            *(f32 *)(p + i * 0x60 + 0x28) -= fall;
            angle = func_L01_0044AE78(*(f32 *)(p + i * 0x60 + 0x5C) * w);
            sine = func_0038D0B0(angle);
            linear = sine * 3.0f;
            if (sine >= 0.0f) {
                height = radius * (sqrt_asm(sine) + linear) * 0.25f;
            } else {
                height = radius * (-sqrt_asm(-sine) + linear) * 0.25f;
            }
            q = p + i * 0x60;
            vertical = radius * sine * sine * (*(f32 *)(q + 0x58) / 1.5707964f) * 0.5f;
            *(f32 *)(q + 0x44) = -(*(f32 *)(q + 0x58) * sine + 1.5707964f);
            *(f32 *)(q + 0x48) = -(*(f32 *)(q + 0x58) * func_0038D0B0(func_L01_0044AE78((*(f32 *)(q + 0x5C) * w) * 2.0f)) + 1.5707964f);
            if (p[0x3D1]) func_L01_003D57E8((vu0_v4 *)(q + 0x20));
            func_0038CE20(&temp, &D_L01_001D66E0, vertical);
            vec_add_ab(q, &temp, q + 0x20);
            func_0038CE20(&temp, q + 0x30, height);
            vec_add_ab(q, &temp, q);
            if (fabs_asm(angle) < 0.1f) *(f32 *)(q + 0x58) = func_003824E0(30.0f, 60.0f) * 0.017453292f;
            if (*(f32 *)(q + 8) < *(f32 *)(p + 0x3D4) || func_0038CAD0((s32 *)(q + 0x50))) {
                q[0x54] = 3;
                *(s32 *)(q + 0x50) = 50;
            }
            break;
        }
        case 3: {
            u8 *q = p + i * 0x60;
            *(f32 *)(q + 0x44) = (*(f32 *)(q + 0x44) + 1.5707964f) * 0.94f - 1.5707964f;
            q[0x55] = ((f32)*(s32 *)(q + 0x50) / 50.0f) * 127.0f;
            if (func_0038CAD0((s32 *)(q + 0x50))) {
                *(s32 *)(q + 0x50) = 0;
                q[0x54] = 4;
            }
            break;
        }
        case 4:
            finished++;
            break;
        }
        {
            u8 *q = p + i * 0x60;
            *(f32 *)(q + 0xC) = w;
            *(f32 *)(q + 0x4C) = radius;
            *(f32 *)(q + 0x1C) = fall;
            *(f32 *)(q + 0x5C) += 1.0f;
        }
    }
    func_L01_004450F0(m, 1, -1);
    if (finished == p[0x3D2]) {
        func_L01_004450F0(m, 4, -1);
        func_003C2880(m);
    } else if (m[0x20] != 0 && m[0x20] != 4) {
        func_L01_00404808(func_L01_003D5F28, m);
    }
}
/* localdecomp:end func_L01_003D52A8 */

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

/* localdecomp:start func_L01_003D6218 */
typedef struct { u128_t rotation; u8 vec[16]; s16 life, time; s32 owner, handle; } Data_003D6218;
typedef struct { u8 pad0[16]; u128_t position; u8 state; u8 pad21[11]; f32 scale; u8 opacity, pad31; s16 group; u16 flags; u8 pad36[0x68-0x36]; Data_003D6218 *data; u8 pad6C[0xC0-0x6C]; u8 matrix[0x30]; f32 rotation[4]; } Moby_003D6218;
extern s32 D_L01_001DF424;
__asm__(".extern D_L01_001DF424, 4");
u8 *func_L01_003D6218(void *position, void *rotation, s32 lifetime, s32 owner, s32 unused) {
    extern u8 *func_003C24B0(s32, s32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern void func_0038D308(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_003C4840(void *, void *, f32);
    extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
    extern void func_003C7C38(void *);
    Moby_003D6218 *m = (Moby_003D6218 *)func_003C24B0(0x1C59, 0x80);
    Data_003D6218 *data;
    if (m) {
        m->state = 0;
        m->opacity = m->group = 255;
        data = m->data;
        m->position = *(u128_t *)position;
        data->rotation = *(u128_t *)rotation;
        data->life = (func_00382498(360, 500) * 5 + 2) / 6;
        m->flags |= 0x100;
        m->rotation[0] = func_00382538();
        m->rotation[1] = func_00382538();
        m->rotation[2] = func_00382538();
        func_0038D308(m->matrix, m->rotation);
        { f32 speed = func_003824E0(0.05235987901687622f, 0.10471975803375244f);
        func_003C4840(data->vec, m->matrix + 0x10, speed); }
        data->owner = owner;
        data->time = lifetime + (D_L01_001DF424 * 5 + 2) / 6;
        m->scale *= 0.25f;
        data->handle = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
        func_003C7C38(m);
    }
    return (u8 *)m;
}
/* localdecomp:end func_L01_003D6218 */

INCLUDE_ASM("asm/levels", func_L01_003D6398);

/* localdecomp:start func_L01_003D6F10 */
typedef struct { vu0_v4 axis; vu0_v4 normal; vu0_v4 points[8]; f32 radius; u8 padA4[0x1A]; u8 mode; } Vars_003D6F10;
extern const vu0_v4 D_L01_001D66B0;
extern vu0_v4 D_L01_001EAA40;
void func_L01_003D6F10(u8 *obj) {
    extern f32 func_003C3D30(void *, s32, s32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    vu0_v4 v;
    vu0_v4 pos;
    vu0_v4 normal;
    Vars_003D6F10 *vars = *(Vars_003D6F10 **)(obj + 0x68);
    f32 half = vars->radius * 0.5f;
    f32 radius, angle, z;
    s32 i;
    s32 j;
    if (vars->mode == 0) {
        z = func_003C3D30(obj + 0x10, 0, 0, 3.0f);
        func_0038CF68(&vars->axis, &D_L01_001EAA40, 1.0f);
        vars->axis.w = z;
        for (i = 0; i < 8; i++) {
            if (i < 3) radius = func_003824E0(0.0f, half);
            else radius = func_003824E0(half, vars->radius);
            angle = func_00382538();
            qzero(&v);
            v.x = func_0038D098(angle) * radius;
            v.y = func_0038D0B0(angle) * radius;
            vec_add_ba(&vars->points[i], &v, obj + 0x10);
            { f32 height = vars->axis.w;
            vars->points[i].w = radius;
            vars->points[i].z = height; }
        }
    } else {
        vu0_q c, p, n, pq;
        pq = *(vu0_q *)(obj + 0x10);
        __asm__("lqc2 %0, %1" : "=j"(c) : "i"(&D_L01_001D66B0));
        *(vu0_q *)&pos = pq;
        __asm__("lqc2 %0, %1" : "=j"(p) : "m"(pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(n) : "j"(c), "j"(p));
        __asm__("sqc2 %1, %0" : "=m"(normal) : "j"(n));
        func_0038CE20(&normal, &vars->axis, func_0038CE68(&vars->axis, &normal));
        vec_add_ba(&normal, &pos, &normal);
        { vu0_q c2, n2, r2;
            __asm__("lqc2 %0, %1" : "=j"(c2) : "i"(&D_L01_001D66B0));
            __asm__("lqc2 %0, %1" : "=j"(n2) : "m"(normal));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(r2) : "j"(c2), "j"(n2));
            __asm__("sqc2 %1, %0" : "=m"(normal) : "j"(r2));
        }
        func_0038CF68(&normal, &normal, 1.0f);
        *(vu0_q *)&vars->normal = *(vu0_q *)&normal;
        for (j = 0; j < 8; j++) {
            qzero(&v);
            func_0038D890(&v, &normal, &vars->axis, func_00382538());
            if (j < 3) radius = func_003824E0(0.0f, half);
            else radius = func_003824E0(half, vars->radius);
            func_0038CE20(&v, &v, radius);
            vec_add_ab(&vars->points[j], &v, obj + 0x10);
            vars->points[j].w = radius;
        }
    }
}
/* localdecomp:end func_L01_003D6F10 */
