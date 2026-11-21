/* functional: high. Draft (Codex near miss, 201 diff words = loop IV/VU scheduling) re-read block by block against asm: all offsets, constants, call args and delay-slot orders agree; the saved[] copies are dead stores in retail too */
#include "common.h"
/* localdecomp:start func_L01_004DF428 */
#include "vu0.h"
typedef struct { u8 a[0x10]; u128_t pos; u8 b[0x14]; u16 flags; u8 c[0x2c]; u8 flag62; u8 d[0x47]; s16 type; u8 e[0x14]; u128_t rot[4]; } Moby_004DF428;

typedef struct {
 u8 pad0[0x80];
 u128_t f80;
 u128_t f90;
 u8 padA0[0xB58];
 u8 * fBF8;
 u8 padBFC[0x294];
 f32 fE90;
 f32 fE94;
 f32 fE98;
 u8 padE9C[0x2E4];
 s32 f1180;
 f32 f1184;
 f32 f1188;
 u8 pad118C[0x9C];
 struct { s32 value; u8 pad[0x4c]; } saved[7];
 u8 pad1458[0x1168];
 Moby_004DF428 * f25C0;
 u8 pad25C4[0x1C8];
 s32 reset[9];
 u8 pad27B0[0x5C];
 s32 f280C;
 u8 pad2810[0x14];
 f32 f2824;
 f32 f2828;
 u8 pad282C[0x24];
 s32 f2850;
 s32 f2854;
 s16 f2858;
 u8 pad285A[0x2A];
 s16 f2884;
 u8 tail[0x5A];
} Hero_004DF428;
extern G_4DD4B0 D_001A4BE0;
typedef struct { u8 pad0[8]; s32 count; u8 padC[0x34]; s16 state; u8 pad42[0x36]; s32 next; } State_004DF428;
extern State_004DF428 D_00142660;
typedef struct { u128_t pos; u8 pad10[0x2534]; u8 mode; } Checkpoint_004DF428;
extern Checkpoint_004DF428 D_001A4C90;
extern u128_t D_L01_001DFC50[];
extern s32 D_L01_001D673C;
extern Moby_004DF428 *D_L01_001E001C, *D_L01_001E0020;
typedef struct { u128_t pos, rot; } Transform_004DF428;
extern Transform_004DF428 D_0016C5F0;
extern short D_L01_001EAA20[];
extern s32 D_001D4C40;
extern S_4DC790 D_L01_002F4540[];
typedef struct { u8 b0,active; u8 pad2[0x3E]; u128_t f40,f50,f60,f70,f80,f90; u8 padA0[0x10]; } Effect_004DF428;
typedef struct { u8 a,b,enabled; } Flag_004DF428;
extern Flag_004DF428 D_00142D40, D_00142CA0;
void func_L01_004DF428(void) {
    extern void func_L01_00425978(s32);
    extern void func_0038CB78(void *, s32, s32);
    extern void func_0038D308(void *,void *);
    extern void func_0038CF68(void *, void *, f32);
    extern int func_003D3CB0(char *, char *, int, int, int);
    extern void func_L01_004EF840(void);
    extern void func_L01_004E45C8(void);
    extern void func_L01_0050FDD8(s32,s32);
    extern void func_L01_005138F8(void);
    extern s32 func_00382498(s32,s32);
    extern void func_0039EF28(void);
    extern s32 func_L01_00513EF0(void);
    extern void func_L01_004E1F00(s32);
    extern void func_L01_003F5AC0(s32,s32);
    s32 saved[7];
    struct { u128_t v1, v2; } vectors;
    s32 i;
    Moby_004DF428 *p;

    if (D_00142660.state==4 && D_00142660.next!=4) {
        D_00142660.state=(s16)D_00142660.next;
        func_L01_00425978(D_00142660.next);
    }
    for(i=0;i<7;i++) saved[i]=((Hero_004DF428 *)&D_001A4BE0)->saved[i].value;
    func_0038CB78(&D_001A4BE0,0,0x28e0);
    for(i=0;i<7;i++) saved[i]=((Hero_004DF428 *)&D_001A4BE0)->saved[i].value;
    if(D_L01_001D673C) {
        D_001A4C90.pos=D_L01_001DFC50[0];
        D_001A4C90.mode=2;
    }
    for(p=D_L01_001E001C;p<D_L01_001E0020;p++) {
        if(p->type==0) {
            Moby_004DF428 *m;
            ((Hero_004DF428 *)&D_001A4BE0)->f25C0=p;
            func_0038D308(&p->rot[0],&p->rot[3]);
            m=((Hero_004DF428 *)&D_001A4BE0)->f25C0;
            ((Hero_004DF428 *)&D_001A4BE0)->f90=m->rot[3];
            func_0038CF68(&vectors.v2,&m->rot[2],-3.0f);
            func_0038CF68(&vectors.v1,((Hero_004DF428 *)&D_001A4BE0)->f25C0->rot+2,1.0f);
            m=((Hero_004DF428 *)&D_001A4BE0)->f25C0;
            __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(vectors.v1) : "m"(vectors.v1),"m"(m->pos) : "vf1","vf2");
            __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(vectors.v2) : "m"(vectors.v2),"m"(m->pos) : "vf1","vf2");
            if(func_003D3CB0((char *)&vectors.v1,(char *)&vectors.v2,2,(s32)m,0))
                ((Hero_004DF428 *)&D_001A4BE0)->f25C0->pos=*(u128_t *)D_L01_001EAA20;
            m=((Hero_004DF428 *)&D_001A4BE0)->f25C0;
            m->flags|=2;
            m=((Hero_004DF428 *)&D_001A4BE0)->f25C0;
            ((Hero_004DF428 *)&D_001A4BE0)->fBF8=(u8 *)m;
            ((Hero_004DF428 *)&D_001A4BE0)->f80=m->pos;
            func_L01_004EF840();
            func_L01_004E45C8();
            func_L01_0050FDD8(0,0);
            D_0016C5F0.rot=((Hero_004DF428 *)&D_001A4BE0)->f90;
            D_0016C5F0.pos=((Hero_004DF428 *)&D_001A4BE0)->f80;
            break;
        }
    }
    ((Hero_004DF428 *)&D_001A4BE0)->f25C0->flag62=255;
    if(!D_001D4C40) D_001D4C40=9;
    for(i=42;i>=0;i--) {
        Effect_004DF428 *r=(Effect_004DF428 *)&D_L01_002F4540[42-i];
        r->active=0;
        qzero(&r->f60);qzero(&r->f40);qzero(&r->f50);
        qzero(&r->f90);qzero(&r->f70);qzero(&r->f80);
    }
    for(i=8;i>=0;i--) ((Hero_004DF428 *)&D_001A4BE0)->reset[i]=-1;
    ((Hero_004DF428 *)&D_001A4BE0)->f2824=2.125f;
    ((Hero_004DF428 *)&D_001A4BE0)->f2828=1.25f;
    if(D_00142660.count<10) D_00142660.count=10;
    if(!D_00142660.count) func_L01_005138F8();
    ((Hero_004DF428 *)&D_001A4BE0)->f2850=D_00142660.count;
    ((Hero_004DF428 *)&D_001A4BE0)->f2854=4;
    ((Hero_004DF428 *)&D_001A4BE0)->f2858=(s16)((Hero_004DF428 *)&D_001A4BE0)->f2850;
    ((Hero_004DF428 *)&D_001A4BE0)->f1180=func_00382498(150,250);
    ((Hero_004DF428 *)&D_001A4BE0)->f1184=0.007f;
    ((Hero_004DF428 *)&D_001A4BE0)->f1188=0.3f;
    ((Hero_004DF428 *)&D_001A4BE0)->fE90=1.15f;
    ((Hero_004DF428 *)&D_001A4BE0)->fE94=*(f32 *)(((u8 *)&D_001A4BE0)+0x88);
    ((Hero_004DF428 *)&D_001A4BE0)->fE98=0.12f;
    D_00142D40.enabled=1;
    D_00142CA0.enabled=1;
    func_0039EF28();
    ((Hero_004DF428 *)&D_001A4BE0)->f2884=0;
    if(func_L01_00513EF0() && ((Hero_004DF428 *)&D_001A4BE0)->f280C!=4 && ((Hero_004DF428 *)&D_001A4BE0)->f280C!=81)
        ((Hero_004DF428 *)&D_001A4BE0)->f280C=32;
    else if(((Hero_004DF428 *)&D_001A4BE0)->f280C==32) ((Hero_004DF428 *)&D_001A4BE0)->f280C=0;
    func_L01_004E1F00(0);
    func_L01_003F5AC0(0,1);
}
/* localdecomp:end func_L01_004DF428 */
