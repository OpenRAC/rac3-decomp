/* functional: high. Near miss (21 words): register allocation/scheduling and global address loading only. Every branch, offset, callee and constant re-read against PAL asm; the lui/lw (D_001E001C, D_001D6764, D_001E0ED4) vs gp loads are the same memory. */
#include "common.h"
/* localdecomp:start func_L01_003C4C40 */
#include "vu0.h"
extern u16 *D_L01_0021DE20[];
extern struct U_3C41F8 D_L01_001E001C __attribute__((section(".sdata")));
extern s32 D_L01_001E0058;
extern u16 **D_L01_001D6764;
extern u8 *D_L01_001E0ED4;
__asm__(".extern D_001DEC54_sda, 4");
extern f32 D_001DEC54_sda;
typedef struct { u8 pad[0x10]; s16 h10; u8 pad12[10]; u8 b1C; u8 tail[3]; } Static_003C4C40;
typedef struct { u8 pad[0x98]; f32 f98,f9C; s32 a0,a4,a8,ac,b0; f32 b4,b8,bc; u8 padC0[0xD0-0xC0]; s32 d0,d4; u8 *d8,*dc; u8 padE0[0xF4-0xE0]; f32 f4,f8,fc; } State_003C4C40;
__asm__(".extern D_001E001C_sda, 4");
extern u8 *D_001E001C_sda;
extern u8 *D_L01_001E001C_003C4C40 __attribute__((section(".data")));
void func_L01_003C4C40(u8 *m, u8 *p) {
    extern void func_L01_0044ED88(u8 *, u8 *, s32, s32, s32, s32, s32, s32);
    extern void func_0038CB78(void *, s32, s32);
    extern void func_L01_0044F888(u8 *, s32, s32, u8 *, s32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_L01_003C5698(u8 *, u8 *);
    extern void func_L01_003C76A0(u8 *, u8 *, s32);
    extern void func_L01_003C5710(u8 *, u128_3C3E90 *, u128_3C3E90 *);
    extern void func_L01_003C6128(void *, O3C48A8 *);
    extern void func_L01_00477BC0(s32, s32);
    s32 index;
    u16 *list;
    u8 *o;
    u8 *base;
    s32 *a, *b, *c, *d;
    s32 *v, *w, *z;
    u128_3C3E90 *pos, *dir;
    func_L01_0044ED88(m, p+0x170, 16, *(s32 *)(p+0x24), *(s32 *)(p+0x20), -1, 7, 0);
    p[0x1BD] = 1;
    func_0038CB78(p+0x40, 0, 24);
    list = D_L01_0021DE20[*(s32 *)(p+0x24)];
    for (; (*(s32 *)(p+0x24) & 255) != 255 && D_L01_001E0058 >= *(s32 *)(p+0x24) && list != 0 &&
          ((s16)list[-1] >= 0 || list == D_L01_0021DE20[*(s32 *)(p+0x24)]); list++) {
        base = *(u8 **)&D_L01_001E001C;
        o = base + (list[0] & 0x7FFF) * 256;
        if (o == 0) break;
        *(s16 *)(o+0x32) = 128;
        if (*(s16 *)(o+0xAA) == *(s32 *)(p+0x34)) *(u8 **)(p+0x48) = o;
        else if (*(s16 *)(o+0xAA) == *(s32 *)(p+0x90)) *(u8 **)(p+0x40) = o;
        else if (*(s16 *)(o+0xAA) == *(s32 *)(p+0x94)) *(u8 **)(p+0x44) = o;
        else if (*(s16 *)(o+0xAA) != *(s32 *)(p+0x30)) {
            if (*(s16 *)(o+0xAA) == *(s32 *)(p+0x28)) {
                *(u8 **)(p+0x4C) = o;
                func_L01_0044F888(p+0x170, 0, (o-base)>>8, p+0x670, 96);
            } else if (*(s16 *)(o+0xAA) == *(s32 *)(p+0x2C)) {
                *(u8 **)(p+0x50) = o;
                func_L01_0044F888(p+0x170, 0, (o-base)>>8, p+0x690, 96);
            } else if (*(s16 *)(o+0xAA) == *(s32 *)(p+0x38)) {
                *(u8 **)(p+0x54) = o;
                func_L01_0044F888(p+0x170, 0, (o-base)>>8, p+0x690, 96);
                *(s32 *)(o+0x98) = 0;
            }
        }
    }
    { u16 **initial = D_L01_001D6764;
    *(u16 *)(*(u8 **)(p+0x40)+0x34) |= 0x41;
    *(u16 *)(*(u8 **)(p+0x44)+0x34) |= 0x41;
    *(u16 *)(*(u8 **)(p+0x48)+0x34) |= 0x41;
    { u16 *list2 = initial[*(s32 *)(p+0x20)];
    for (; list2 && ((s16)list2[-1] >= 0 || list2 == D_L01_001D6764[*(s32 *)(p+0x20)]); list2++) {
        Static_003C4C40 *o2 = (Static_003C4C40 *)D_L01_001E0ED4 + (list2[0] & 0x7FFF);
        if (o2 == 0) break;
        o2->b1C = 128;
        o2->h10 = 0x7F80;
    }
    }
    v = (s32 *)(p+0x58);
    w = (s32 *)(p+0x70);
    z = (s32 *)(p+0x80);
    a = (s32 *)(p+0x700);
    b = (s32 *)(p+0x720);
    pos=(u128_3C3E90 *)(m+0x10);
    dir=(u128_3C3E90 *)(m+0xF0);
    c = (s32 *)(p+0x780);
    d = (s32 *)(p+0x790);
    }
    { index = ((State_003C4C40 *)p)->d0;
    if (index != -1)
        ((State_003C4C40 *)p)->d8 = D_001E001C_sda + index * 1 * 256;
    index = ((State_003C4C40 *)p)->d4;
    if (index != -1)
        ((State_003C4C40 *)p)->dc = (u8 *)((index << 8) + (s32)D_L01_001E001C_003C4C40);
    }
    m[0x30] = 255;
    p[0x100] = 0;
    ((State_003C4C40 *)p)->b0 = 0;
    ((State_003C4C40 *)p)->f98 = 0.0f;
    ((State_003C4C40 *)p)->f9C = 0.0f;
    ((State_003C4C40 *)p)->f8 = 0.0f;
    ((State_003C4C40 *)p)->fc = 0.0f;
    ((State_003C4C40 *)p)->a4 = 0;
    ((State_003C4C40 *)p)->a0 = -1;
    ((State_003C4C40 *)p)->a8 = -1;
    ((State_003C4C40 *)p)->ac = -1;
    ((State_003C4C40 *)p)->b4 = func_003824E0(-D_001DEC54_sda, D_001DEC54_sda);
    ((State_003C4C40 *)p)->b8 = func_003824E0(0.0f, 3.1415927f);
    ((State_003C4C40 *)p)->bc = func_003824E0(0.0f, 3.1415927f);
    *(f32 *)(p+0xF4) = 1.0f;
    { s32 i; for(i=5;i>=0;i--) v[i]=0; }
    { s32 j; for(j=3;j>=0;j--) { w[3-j]=0; z[3-j]=0; } }
    qzero(p+0x110);
    qzero(p+0x120);
    *(s32 *)(p+0x6BC) = func_L01_003C5698(m,p);
    func_L01_003C76A0(m,p,1);
    func_L01_003C5710(p,pos,dir);
    p[0x102] = 1;
    if (*(s32 *)(p+0x108) != -1) func_L01_003C6128(m,(O3C48A8 *)p);
    p[0x103] = 0;
    { s32 *dd=d, *cc=c; s32 i; s32 *bb=b; o=(u8 *)a;
    for (i=3; i>=0; i--) {
        { s32 n=*(s32 *)o; if (n != -1) func_L01_00477BC0(n,0); o+=4; }
        { s32 n=*bb++; if (n != -1) func_L01_00477BC0(n,0); }
        { s32 n=*cc++; if (n != -1) func_L01_00477BC0(n,0); }
        { s32 n=*dd++; if (n != -1) func_L01_00477BC0(n,0); }
    } }
}
/* localdecomp:end func_L01_003C4C40 */
