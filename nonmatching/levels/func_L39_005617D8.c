/* NTSC-U draft (Codex wave 3): C of func_L39_00560CF8, the NTSC-U twin of func_L39_005617D8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 269 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00560CF8", whose code is not the PAL one).
 * Worker's note: 269 diff; best log w122/func_L39_00560CF8.check1.log; permitted flags reverified once; literal pool vs retail inline pi/2, 0.2, 0.1, 210000 documented unlisted @ps2as blocker; retained prior best; register/VU scheduling differs; retail div 2 nops
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_00560CF8 */
static __inline__ void local_sub_ba(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}
static __inline__ void local_add_ba(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}
static __inline__ void local_add_ab(void *d,void *a,void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}
typedef struct {
    vu0_v4 vel;
    u16 x10;
    s16 x12;
    void *x14;
    s32 x18;
    s32 x1C;
    f32 x20;
    u8 *x24;
    f32 x28;
    f32 x2C;
    s32 x30;
} State39;

extern u8 D_L39_00242AB0[8];
extern u8 *D_L39_0024CF1C;
extern u8 D_L39_0025F840[],D_L39_001FE1A0[];
extern s32 func_L39_005F08A0(void *,s32);
extern s32 func_L39_005F0CE0(s32,s32,void *);
extern void func_L39_005F08F8(void *,s32),func_L39_005F0988(s32),func_L39_005FD658(s32),func_L39_005FD6D8(void);
extern f32 func_L39_005B2510(f32,f32);
extern s32 func_L39_005B2498(s32);
extern void func_00388758(void *,void *,void *);
extern void func_003BDA38(void *,s32,void *);
extern u8 *D_L22_001E9858_00343338[];
extern vu0_v4 D_L22_001E9860_00343338[];
extern void func_L39_00560B50(void *,void *,s32,s32);
extern u8 *func_0037E0B8(s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern f32 func_00388990(f32);
extern f32 func_00389410(f32);
extern void func_003BEB58(void *, void *, void *, f32);
extern f32 func_00388770(void *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_L39_005F08F8(void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_003883C8(void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_003BD360(void *);

void func_L39_00560CF8(u8 *p) {
    vu0_v4 np;
    vu0_v4 v10;
    vu0_v4 dir;
    u8 info[0x30];
    vu0_v4 v60;
    State39 *st;
    u8 *t;
    u8 *h;
    void *o;
    u8 *r;
    f32 a;
    f32 k;
    f32 sz;
    s32 hit;
    s32 n;
    s32 i;

    st = *(State39 **)(p + 0x68);
    switch (p[0x20]) {
    case 0:
        *(u16 *)(p + 0x96) += 1;
        if(!func_L39_005F08A0(p,st->x30)) st->x30=func_L39_005F0CE0(0,4,p);
        t = st->x24;
        if (t != 0) {
            r = func_0037E0B8((s32)t);
            if (t[0x20] == 0xFE) {
                st->x24 = 0;
            } else if (t[0x20] == 0xFD) {
                st->x24 = 0;
            } else if (r != 0 && *(f32 *)r <= 0.0f) {
                st->x24 = 0;
            } else if (*(u16 *)(p + 0x96) >= 6) {
                dir.x=*(f32 *)t*0.0009765625f;
                dir.y=*(f32 *)(t+4)*0.0009765625f;
                dir.z=*(f32 *)(t+8)*0.0009765625f;
                dir.w=0;
                local_sub_ba(&dir, &dir, p + 0x10);
                func_00388830(&dir, &dir, 1.0f);
                func_00388830(&v10, st, 1.0f);
                a = func_00389410(func_00388990(func_00388730(&dir, &v10)) + 1.5707964f);
                k = 1.0f;
                if (st->x28 < a) {
                    k = st->x28 / a;
                }
                func_003BEB58(&dir, &v10, &dir, k);
                func_00388830(&dir,&dir,1);
                *(vu0_v4 *)(p+0xC0)=dir;
                func_00388758(p+0xD0,p+0xC0,p+0xE0);
                func_00388758(p+0xE0,p+0xD0,p+0xC0);
                *(s32 *)(p+0xCC)=0;*(s32 *)(p+0xDC)=0;*(s32 *)(p+0xEC)=0;
                func_00388830(st, &dir, func_00388770(st));
            }
        }
        local_add_ba(&np, p + 0x10, st);
        if (st->x12 < 12) {
            st->x12++;
        }
        func_L01_00443628(&v10,p,0x10001,D_L39_00242AB0,st->x2C>0 ? 0.0f : (f32)st->x18);
        o=st->x14;
        func_L39_005FD658(D_L39_0024CF1C ? *(s32 *)(D_L39_0024CF1C+0x2548) : -1);
        hit=func_003CE740(p+0x10,&np,0,o,&v10);
        func_L39_005FD6D8();
        if(hit && *(void **)(D_L39_0025F840+0x18)!=*(void **)(p+0xB8) && *(void **)(D_L39_0025F840+0x18)!=p) {
            *(s32 *)(p+0x98)=0;
            *(u16 *)(p+0x34)=(*(u16 *)(p+0x34)|0x41)&0xEFFF;
            func_L39_005F08F8(p,1);func_L01_00441FB8(p,1,-1);
            func_L39_00560B50(p,D_L39_0025F840+0x20,10,1);
            func_L39_005F0CE0(1,0,p);
        } else if(func_003883C8(&st->x10)) {
            *(s32 *)(p+0x98)=0;
            *(u16 *)(p+0x34)=(*(u16 *)(p+0x34)|0x41)&0xEFFF;
            func_L39_005F08F8(p,1);func_L01_00441FB8(p,1,-1);
            func_L39_00560B50(p,p+0x10,10,1);
            func_L39_005F0CE0(1,0,p);
        } else {
            func_003BDA38(p,1,info);
            func_003886E8(&dir, st, 0.2f);
            for (i = 0; i < 5; i++) {
                sz = func_L39_005B2510(0.1f, 0.3f) * st->x20;
                n = func_L39_005B2498(0xFF);
                func_L01_00440A88(&v60, 0.0f, 0.1f);
                local_add_ba(&v60, &v60, info);
                func_L01_0046C468(&v60, D_L39_00242AB0, 0xF, st->x1C, n, 0x20, 0, sz * 210000.0f, sz * 0.2f * 210000.0f, 0.0f, 0);
                local_add_ab(info, info, &dir);
            }
        }
        *(vu0_v4 *)(p + 0x10) = np;
        break;
    case 1:
        if(st->x30!=-1) {
            u8 *snd=D_L39_001FE1A0+(st->x30<<7);
            if(*(void **)(snd+0xDC)==p && snd[0xD0]) func_L39_005F0988(st->x30);
        }
        st->x30=-1;
        if (--st->x12 == -1) {
            func_003BD360(p);
        }
        break;
    }
}
/* localdecomp:end func_L39_00560CF8 */
