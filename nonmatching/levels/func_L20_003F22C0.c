/*
 * PAL reconstruction from the owner's retail ELF, 2026-11-16.
 * Owning file: src/levels/20_final_boss/L20_003F1A78.c.
 * Flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stock check.py: 241 differing instructions, candidate 03 of 3.
 * Earlier candidate 02 reported 232, but walked random-initialized rows
 * backwards; do not prefer its lower positional score over this correction.
 * Remaining: saved-register assignment, VU0/ordinary instruction interleaving,
 * switch-tail layout, callback address hoisting and store order.
 * The file lacks vf2; j-form would need a separately reviewed whole-file
 * flag decision. No alternative flags were tested.
 * No full build verification; keep INCLUDE_ASM.
 */
#include "common.h"
typedef int Q_3F22C0 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_3F22C0;
typedef struct { u8 pad[0xD0]; u8 flag; u8 padD1[0xB]; void *owner; } Slot_3F22C0;
static __inline__ void sub_3F22C0(void *d, void *a, void *b) {
    __asm__(
        "lqc2 $vf1,%1\n"
        "lqc2 $vf2,%2\n"
        "vadd.xyz $vf1,$vf1,$vf2\n"
        "sqc2 $vf1,%0\n"
        : "=m"(*(V_3F22C0 *)d) : "m"(*(V_3F22C0 *)a),"m"(*(V_3F22C0 *)b) : "vf1","vf2");
}
static __inline__ void subba_3F22C0(void *d, void *a, void *b) {
    __asm__(
        "lqc2 $vf1,%2\n"
        "lqc2 $vf2,%1\n"
        "vsub.xyz $vf2,$vf2,$vf1\n"
        "sqc2 $vf2,%0\n"
        : "=m"(*(V_3F22C0 *)d) : "m"(*(V_3F22C0 *)a),"m"(*(V_3F22C0 *)b) : "vf1","vf2");
}
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32,f32);
extern u8 *func_L01_0046A610(void *,void *,s32,s32,s32,s32,f32,f32,f32,f32,f32);
extern u8 D_L20_001D66B0[] __attribute__((section(".sdata")));
extern u8 *D_L20_002202B4[];
extern u8 D_001A30B0[];
extern s32 func_003A52A0(s32,s32,void *);
extern void func_003A4F28(s32);
extern s32 func_003D3CB0(void *,void *,s32,void *,void *);
extern Q_3F22C0 D_L20_001E9BE0;
extern Q_3F22C0 D_001A4CB0;
extern V_3F22C0 D_L20_001E2E00;
extern void func_L01_004450F0(void *,s32,s32);
extern void func_L04_00325460(void *,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,f32,f32);
extern void func_L01_00446780(void *,void *,s32,s32,s32,s32,f32,f32,f32);
extern void func_003C2880(void *);
extern f32 func_0038DAB8(f32,f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *,void *,f32);
extern void func_0038CE90(void *,void *,void *);
extern f32 func_00382538(void);
extern void func_0038D890(void *,void *,void *,f32);
extern void func_L20_003F2918(void *);
extern void func_L20_003F32D0(void *);
extern void func_L20_003F3F28(void *);
extern void func_L20_003F3FF8(void *);
extern void func_L20_003F3528(void *);
extern void func_L01_00404A10(void (*)(void *),void *);
extern s32 func_0038CB00(void *);
extern s32 D_L20_001DF404;
__asm__(".extern D_L20_001DF404, 4");
void func_L20_003F22C0(u8 *m) {
    V_3F22C0 a,b;
    u8 *p=*(u8 **)(m+0x68);
    u8 *pos=m+0x10;
    s32 rnd=func_00382468(40);
    u8 *e=func_L01_0046A610(pos,D_L20_001D66B0,33,127,0x101010,rnd,
        672000.0f,func_003824E0(500.0f,1500.0f),1.0f,0.0f,0.0f);
    s32 id;
    if(e) { e[2]=D_L20_002202B4[0][0]; e[3]=0x44; }
    id=*(s32 *)(p+0x18);
    if(id==-1 || ((Slot_3F22C0 *)(D_001A30B0+(id<<7)))->owner!=m ||
        ((Slot_3F22C0 *)(D_001A30B0+(id<<7)))->flag==0)
        *(s32 *)(p+0x18)=func_003A52A0(0,4,m);
    switch(m[0x20]) {
    case 0:
        *(Q_3F22C0 *)&a=*(Q_3F22C0 *)pos;
        sub_3F22C0(pos,pos,p);
        *(f32 *)(p+8)-=*(f32 *)(p+0x10);
        if(func_003D3CB0(&a,pos,0,*(void **)(m+0xB8),0)) {
            *(Q_3F22C0 *)pos=D_L20_001E9BE0;
            func_L01_004450F0(m,1,-1);
        }
        break;
    case 1:
        id=*(s32 *)(p+0x18);
        if(id!=-1 && ((Slot_3F22C0 *)(D_001A30B0+(id<<7)))->owner==m &&
            ((Slot_3F22C0 *)(D_001A30B0+(id<<7)))->flag!=0) func_003A4F28(id);
        *(s32 *)(p+0x18)=-1;
        func_003A52A0(1,0,m);
        func_L04_00325460(pos,0,25,20,20,20,45,1,1,0,0,0,1.0f,20.0f);
        func_L01_00446780(m,pos,1,0,1,0,2.0f,*(f32 *)(p+0x14),1.0f);
        func_003C2880(m);
        return;
    }
    *(f32 *)(p+0x20)=func_0038DAB8(*(f32 *)(p+0x20),0.0349065885f);
    *(f32 *)(p+0x24)=func_0038DAB8(*(f32 *)(p+0x24),0.104719758f);
    switch(m[0x95]) {
    case 0: {
        s32 i;
        *(Q_3F22C0 *)(p+0xD70)=D_001A4CB0;
        for(i=0;i<12;i++) {
            *(f32 *)(p+0xD30+i*4)=func_003824E0(0.0174532942f,0.0523598790f);
            *(f32 *)(p+0x4C)=2.0f;
            a.x=func_0038D098(*(f32 *)(m+0xF8));
            a.y=func_0038D0B0(*(f32 *)(m+0xF8));
            subba_3F22C0(&b,&D_L20_001E2E00,pos);
            a.z=0.0f;
            func_0038CF68(&b,&b,1.0f);
            func_0038CE90(p+0xC70+i*16,&a,&b);
            func_0038CF68(p+0xC70+i*16,p+0xC70+i*16,*(f32 *)(p+0x4C));
            func_0038D890(p+0xC70+i*16,p+0xC70+i*16,&b,func_00382538());
        }
        func_L20_003F2918(m);
        *(s16 *)(p+0x40)=(*(s32 *)(p+0x3C)*5+2)/6;
        m[0x95]=2;
        *(f32 *)(p+0x2C)=2.5f;
        *(s16 *)(p+0x38)=1;
        *(s16 *)(p+0x3A)=1;
        break;
    }
    case 2:
        if(func_0038CB00(p+0x40)) {
            m[0x95]=1;
            *(s16 *)(p+0x40)=(*(s16 *)(p+0x34)*5+2)/6;
            func_L20_003F2918(m);
        }
        break;
    case 1:
        if(func_0038CB00(p+0x40)) {
            if(*(s16 *)(p+0x36)!=0) {
                m[0x95]=2;
                *(s16 *)(p+0x40)=4;
            } else {
                *(s16 *)(p+0x40)=4;
            }
        } else if(*(s16 *)(p+0x42)==0) func_L20_003F2918(m);
        break;
    }
    func_L01_00404A10(func_L20_003F3F28,m);
    func_L01_00404A10(func_L20_003F3FF8,m);
    if(*(s16 *)(p+0x42)!=0) {
        func_L20_003F32D0(m);
        if(D_L20_001DF404 < *(s16 *)(p+0x42))
            func_L01_00404A10(func_L20_003F3528,m);
    }
}
