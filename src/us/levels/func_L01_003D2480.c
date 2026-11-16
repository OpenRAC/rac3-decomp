#include "common.h"

/* NTSC-U counterpart of func_L01_003D3EE0 (src/levels/shared/L01_003D0D48.c) */
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L01_003D2480 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
typedef struct {u8 pad[0x368];s16 mode;} Hero_003D3EE0;
extern s32 D_L01_001D6740_003D2480;
__asm__(".extern D_L01_001D6740_003D2480, 16");
extern s32 D_L01_001D673C_003D2480;
__asm__(".extern D_L01_001D673C_003D2480, 16");
extern vu0_v4 D_L01_001E2A40_003D2480;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_L01_001D67B0_003D2480;
__asm__(".extern D_L01_001D67B0_003D2480, 16");
extern s32 D_L01_001D67B0_003D2480;
u8 *func_L01_003D2480(u8 *src) {
    extern u8 *func_003BCFB0(s32,s32);
    extern f32 func_0037E250(f32,f32);
    extern s32 func_0037E208(s32,s32);
    extern f32 func_0037E2A8(void);
    extern void func_00388E38(void *,void *);
    extern void func_003BF360(void *,void *);
    extern s32 func_003D00C0(void);
    extern void func_00388830(vu0_v4 *,vu0_v4 *,f32);
    extern void func_00388758(void *,void *,void *);
    extern void func_L01_00458A70(void *,f32,f32,f32,f32);
    extern void func_L01_003D2D28(s32 *);
    extern u8 *func_0037E0B8(void *);
    extern void func_L01_00456960(s32);
    extern void func_L01_004412D0(void *,s32,s32);
    extern void func_003BD360(u8 *);
    extern void func_003C26C8(void *);
    union {f32 matrix[16];vu0_v4 row[4];} work;
    f32 matrix2[16];
    u8 *m=func_003BCFB0(0x1BC3,0x200);
    u8 *p,*link;
    if(m) {
        m[0x30]=127;
        *(s16 *)(m+0x32)=127;
        m[0x31]=1;
        p=*(u8 **)(m+0x68);
        *(f32 *)(m+0x48)=func_0037E250(0.85f,1.15f);
        *(f32 *)(m+0x2C)=*(f32 *)(*(u8 **)(m+0x24)+0x24)*0.9f;
        *(u16 *)(m+0x34)|=0x20;
        *(vu0_q *)(m+0x10)=*(vu0_q *)(src+0x10);
        if(D_L01_001D6740_003D2480 || D_L01_001D673C_003D2480) {
            func_00388E38(work.matrix,src+0xC0);
            func_003BF360(work.matrix,m+0xF0);
        } else if(func_003D00C0()==2 || ((Hero_003D3EE0 *)&D_001A4BE0)->mode) {
            u8 *rot=m+0xF0;
            work.row[0]=*(vu0_v4 *)(src+0xE0);
            func_00388830(&work.row[0],&work.row[0],-1.0f);
            vec_sub_ba(&work.row[1],&D_L01_001E2A40_003D2480,src+0x10);
            func_00388830(&work.row[1],&work.row[1],1.0f);
            func_00388758(&work.row[1],&work.row[1],&work.row[0]);
            func_00388758(&work.row[2],&work.row[1],&work.row[0]);
            *(vu0_q *)(m+0xC0)=*(vu0_q *)&work.row[2];
            *(vu0_q *)(m+0xD0)=*(vu0_q *)&work.row[1];
            *(vu0_q *)(m+0xE0)=*(vu0_q *)&work.row[0];
            *(vu0_q *)(m+0xF0)=*(vu0_q *)(src+0x10);
            func_00388E38(matrix2,m+0xC0);
            func_003BF360(matrix2,rot);
        } else {
            qzero(m+0xF0);
            *(f32 *)(m+0xF8)=func_0037E2A8();
        }
        *(s16 *)(p+0x166)=0;
        *(s16 *)(p+0x164)=func_0037E208(120,300);
        *(s32 *)(p+0x180)=600;
        *(s32 *)(p+0x184)=30;
        *(s32 *)(p+0x188)=450;
        *(s32 *)(p+0x16C)=0;
        if(((Hero_003D3EE0 *)&D_001A4BE0)->mode) m[0x20]=7;
        else if(D_L01_001D673C_003D2480) {
            m[0x20]=9;
            *(s32 *)(p+0x188)=1300;
        } else {
            *(s32 *)(p+0x188)=1400;
            m[0x20]=4;
        }
        *(u8 **)p=p+0x120;
        p[0x129]=1;
        *(u8 **)(p+0x1C)=p+0x30;
        *(f32 *)(p+0x64)=0.5f;
        *(f32 *)(p+0x34)=0.25f;
        *(f32 *)(p+0x30)=0.45f;
        *(f32 *)(p+0x60)=2.094395160675049f;
        *(f32 *)(p+0x5C)=0.0027222223579883575f;
        *(f32 *)(p+0x38)=0.75f;
        *(f32 *)(p+0x3C)=1.0f;
        *(f32 *)(p+0x40)=1.5707963705062866f;
        func_L01_00458A70(m,0.0005555555690079927f,0.01250000111758709f,0.0034906587097793818f,0.20943953096866608f);
        func_L01_003D2D28((s32 *)m);
        *(s32 *)(m+0x98)=*(s32 *)(*(u8 **)(m+0x24)+0x10);
        *(f32 *)(p+0x178)=4.0f;
        *(s32 *)(p+0x170)=-1;
        link=func_0037E0B8(src);
        if(link)link[0x17]=143;
        if(D_001D545C==5 && *(s16 *)(src+0xAA)==0x19DB) {
            s32 n=D_L01_001D67B0_003D2480+1;
            D_L01_001D67B0_003D2480=n;
            if(n>=15)func_L01_00456960(7);
        }
        if(*(u16 *)(m+0x34)&0x1000)func_L01_004412D0(src,0,3);
        if(link && link[0xE]==1)link[0xE]=2;
        else func_003BD360(src);
        func_003C26C8(m);
    }
    return m;
}
/* localdecomp:end func_L01_003D2480 */
