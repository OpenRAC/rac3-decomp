/* PAL near miss: 246 diff, 30 register-masked structural words (277 before). Measured with check.py --no-context
 * --flags=-mvu0-use-vf0-vf2 --as ps2as, i.e. the file src/levels/32_vidcomic_4/L32_003C5280.c needs `-mvu0-use-vf0-vf2` and `@ps2as`
 * added to its line (retail builds 2*pi inline with lui/ori/mtc1 here) and the .extern size hints below.
 * Round 12 (s4) changes: the nine inline VU0 asm blocks are vec_add_ba / vec_sub_ba; `D_L32_0021FAEC` is an unsized array
 * (`*X[0]`, retail reads it with lui+lw, not $gp); `.extern` hints for the $gp scalars and for D_L32_001DF410 (8 bytes, retail
 * takes its address as `addiu $v1,$gp,0x2b60`); owner, w = *(s+4) and st are loaded before the null tests (reorg then puts
 * `lw st` in the beqz delay slot, as retail does).
 * Left: saved-register roles (retail m=$s2, s=$s4, owner=$s3, st=$s5, &m[0x10]=$s6; here s=$s3, owner=$s4, &m[0x10]=$s1),
 * and the cvt.w.s / mfc1 / mtc1 GPR round trip of the two (f32)(s32) conversions (the pair retail has as `cvt.w.s; cvt.s.w` on one
 * FPU register: no plain C, see func_L30_003449B0).
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L32_003C53A0 */
typedef struct Vec_003C53A0 { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003C53A0;
extern f32 D_L32_001DF404, D_L32_001DF400;
extern u8 D_L32_001DF3F8;
extern s32 D_L32_001DF410[2];
extern u8 *D_L32_0021FAEC[];
extern s32 D_L32_001DF3FC,D_L32_001DF3D4,D_L32_001DF3D0;
extern f32 D_L32_001DF3CC,D_L32_001DF3C8,D_L32_001DF3C4,D_L32_001DF3C0,D_L32_001DF3F4;
extern s32 D_L32_001DF420,D_L32_001DF3D8,D_L32_001DF3DC,D_L32_001DF3E0,D_L32_001DF3E4;
extern Vec_003C53A0 D_001A4C60;
__asm__(".extern D_L32_001DF404, 4");
__asm__(".extern D_L32_001DF400, 4");
__asm__(".extern D_L32_001DF3F8, 1");
__asm__(".extern D_L32_001DF410, 8");
__asm__(".extern D_L32_001DF3FC, 4");
__asm__(".extern D_L32_001DF3D4, 4");
__asm__(".extern D_L32_001DF3D0, 4");
__asm__(".extern D_L32_001DF3CC, 4");
__asm__(".extern D_L32_001DF3C8, 4");
__asm__(".extern D_L32_001DF3C4, 4");
__asm__(".extern D_L32_001DF3C0, 4");
__asm__(".extern D_L32_001DF3F4, 4");
__asm__(".extern D_L32_001DF420, 4");
__asm__(".extern D_L32_001DF3D8, 4");
__asm__(".extern D_L32_001DF3DC, 4");
__asm__(".extern D_L32_001DF3E0, 4");
__asm__(".extern D_L32_001DF3E4, 4");
void func_L32_003C53A0(u8 *m,u8 *s) {
    extern void func_00382580(void *,f32,f32);
    extern s32 func_00382498(s32,s32);
    extern f32 func_003824E0(f32,f32);
    extern s32 func_0038CB00(void *);
    extern f32 func_0038DB48(f32);
    extern void func_L32_00347C30(void *,void *,f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038D890(void *,void *,void *,f32);
    extern f32 func_0038CF00(void *,void *);
    extern s32 func_0038DBD8(s32,s32,f32);
    u8 *owner,*st;
    s32 w;
    Vec_003C53A0 delta,blend,toward,move;
    f32 length,phase,weight;
    s32 c1,c2,color;
    if (!s) return;
    owner=*(u8 **)s;
    w=*(s32 *)(s+4);
    st=*(u8 **)(owner+0x68);
    if (!owner || !st || !w) return;
    if (*(u16 *)(s+0xa)&1) {
        func_00382580(m+0x10,0.0f,*(f32 *)(st+0x10));
        vec_add_ba(m+0x10, m+0x10, owner+0x10);
        *(s32 *)(m+4)=D_L32_001DF3E8;
        *(s16 *)(s+0xc)=0;
        *(f32 *)(s+0x18)=*(f32 *)(owner+0x10);
        *(f32 *)(s+0x1c)=*(f32 *)(owner+0x18);
        m[8]=func_00382498(0,255);
        *(f32 *)(m+0xc)=func_003824E0(D_L32_001DF404,D_L32_001DF400);
        m[3]=D_L32_001DF3F8;
        m[2]=D_L32_0021FAEC[0][D_L32_001DF410[func_00382498(0,2)]];
    }
    m[8]+=(*(s16 *)(s+0xe)%(D_L32_001DF3FC*2))-D_L32_001DF3FC;
    if (func_0038CB00(s+0xc)) {
        if (owner[0x20]==2 || owner[0x20]==3) {
            *(s16 *)(s+0xc)=func_00382498(D_L32_001DF3D4,D_L32_001DF3D0);
            *(f32 *)(s+0x10)=func_0038DB48(func_003824E0(0.0f,6.2831855f));
            *(f32 *)(s+0x14)=func_003824E0(D_L32_001DF3CC,D_L32_001DF3C8);
        } else goto other_mode;
    }
    if (owner[0x20]==2 || owner[0x20]==3) {
        *(u16 *)(m+0xa)+=1;
        if (owner[0x20]==2 || owner[0x20]==3) {
            func_L32_00347C30(m+0x10,s+0x18,*(f32 *)(owner+0x10));
            func_L32_00347C30(m+0x18,s+0x1c,*(f32 *)(owner+0x18));
            move.x=func_0038D098(*(f32 *)(s+0x10))**(f32 *)(s+0x14);
            move.z=func_0038D0B0(*(f32 *)(s+0x10))**(f32 *)(s+0x14);
            move.y=0;
            vec_add_ba(m+0x10, m+0x10, &move);
            vec_sub_ba(&delta, m+0x10, owner+0x10);
            if (func_0038CEA8(&delta)<*(f32 *)(st+0x10)) length=func_0038CEA8(&delta);
            else length=*(f32 *)(st+0x10);
            func_0038CF68(&delta,&delta,length);
            vec_add_ba(m+0x10, owner+0x10, &delta);
            vec_sub_ba(&toward, &D_001A4C60, owner+0x10);
            func_0038CF68(&toward,&toward,1.0f);
            vec_sub_ba(&delta, m+0x10, owner+0x10);
            weight=func_003C4088(D_L32_001DF3C4,D_L32_001DF3C0,func_0038CEA8(&delta)/ *(f32 *)(st+0x10));
            func_0038D890(&blend,&delta,&toward,weight);
            vec_add_ba(m+0x10, owner+0x10, &blend);
        }
    } else {
other_mode:
        if (owner[0x20]==1) {
            vec_sub_ba(&delta, m+0x10, owner+0x10);
            func_0038CF68(&delta,&delta,D_L32_001DF3F4);
            vec_add_ba(m+0x10, m+0x10, &delta);
        }
    }
    weight=(f32)s[0xe]*0.00390625f;
    phase=func_0038CF00(m+0x10,owner+0x10)/ *(f32 *)(st+0x10);
    phase+=(f32)(D_L32_001DF9C0%D_L32_001DF420)/(f32)D_L32_001DF420;
    phase-=(s32)phase;
    c1=func_0038DBD8(D_L32_001DF3D8,D_L32_001DF3DC,weight);
    c2=func_0038DBD8(D_L32_001DF3E0,D_L32_001DF3E4,weight);
    color=func_0038DBD8(c2,c1,func_0038D0B0(func_0038DB48(phase*6.2831855f))*0.5f+0.5f);
    if (owner[0x20]==3) {
        color=func_0038DBD8(color,D_L32_001DF3E8,(f32)*(s32 *)(st+0x18)/(f32)D_L32_001DF3B8);
        *(s32 *)(m+4)=color;
        *(s32 *)(m+4)=(color&0xffffff)|((s32)((f32)(D_L32_001DF3B8-*(s32 *)(st+0x18))*128.0f/(f32)D_L32_001DF3B8)<<24);
    } else if (owner[0x20]==2) {
        *(s32 *)(m+4)=(color&0xffffff)|0x80000000;
    } else if (owner[0x20]==1) {
        *(s32 *)(m+4)=color;
        *(s32 *)(m+4)=(color&0xffffff)|((s32)((f32)*(s16 *)(m+0xa)*128.0f/(f32)*(s16 *)(s+8))<<24);
    }
}
/* localdecomp:end func_L32_003C53A0 */
