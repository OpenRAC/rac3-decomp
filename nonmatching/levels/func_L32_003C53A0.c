/* Wave 13 (c42, 2026-11-28) replaces the earlier draft of this function (Codex wave 7 near miss; round 12 (s4)). */
/* func_L32_003C53A0 (level 32): wave 13c c42 near under the line
 * "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (an existing levels line, L39_00561FF8.c
 * and others): tools/check.py --flags "-mvu0-use-vf0-vf2 @ps2as" level 32: 10 diff, 331 instructions on both sides,
 * all ten in one block (the m->f8 jitter update before func_0038CB00). The file's other function, func_L32_003C5280,
 * MATCHes under the same line, so the whole file L32_003C5280.c could take it once this one matches.
 * Changed against r30's near (280 under the file's line) and the nonmatching draft (246 with the vu0 flag and @ps2as):
 * include/vu0.h's vec_add_ab/ba and vec_sub_ab/ba in retail's load order (so the pointer steps interleave and the
 * mode-1 and blend tails share retail's vadd/sqc2), the trail record s and the particle m as structs (their stores
 * no longer block the loads of the $gp scalars: retail's order around func_003824E0 and D_L32_001DF3B8), the
 * m->count++ test as its own if before the move/else-if chain (retail's inner test falls into the mode-1 test and
 * reloads owner[0x20]: owner now s3, s s4 as in retail), a separate c3 for mode 3's colour (its tail is
 * cross-jumped with mode 2's as retail's), the D_L32_001DF410 index read before D_L32_0021FAEC[0], the phase sum
 * written frac + distance (retail's add.s order), D_L32_001DF3FC through an int k (no byte narrowing).
 * Still differs: in the m->f8 block retail computes func_0038CB00's argument (&s->fC) after the div, so s->fE sits
 * in a0; sched1 here issues the argument move in the first cycle (every wording of the update tried gives that).
 * Lead: a do { ... } while (0) around the update (its loop notes stop sched1 there) gives 9 diff with s->fE and
 * D_L32_001DF3FC read before it (W/c3_dw2.c: only s->fE/m->f8 swap a0/a1, so the argument lands after the sb);
 * with s->fE read inside it the loop weight flips owner/s to s3/s4 (51 diff). Not kept: no evidence of a macro.
 */
#include "common.h"

/* localdecomp:start func_L32_003C53A0 */
#include "vu0.h"
typedef struct Vec_003C53A0 { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003C53A0;
extern f32 D_L32_001DF404, D_L32_001DF400;
extern u8 D_L32_001DF3F8;
extern s32 D_L32_001DF410[2];
extern u8 *D_L32_0021FAEC[];
extern s32 D_L32_001DF3FC,D_L32_001DF3D4,D_L32_001DF3D0;
extern f32 D_L32_001DF3CC,D_L32_001DF3C8,D_L32_001DF3C4,D_L32_001DF3C0,D_L32_001DF3F4;
extern s32 D_L32_001DF420,D_L32_001DF3D8,D_L32_001DF3DC,D_L32_001DF3E0,D_L32_001DF3E4;
extern Vec_003C53A0 D_001A4C60;
extern s32 D_L32_001DF9C0;
__asm__(".extern D_L32_001DF9C0, 16");
extern s32 D_L32_001DF3B8;
__asm__(".extern D_L32_001DF3B8, 4");
extern s32 D_L32_001DF3E8;
__asm__(".extern D_L32_001DF3E8, 4");
extern f32 func_003C4088(f32, f32, f32);
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
typedef struct S_003C53A0 {
    u8 *owner;
    s32 w;
    s16 f8;
    u16 fA;
    s16 fC;
    s16 fE;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
} S_003C53A0;
typedef struct M_003C53A0 {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    u16 fA;
    f32 fC;
    Vec_003C53A0 pos;
} M_003C53A0;
void func_L32_003C53A0(M_003C53A0 *m,S_003C53A0 *s) {
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
    owner=s->owner;
    w=s->w;
    st=*(u8 **)(owner+0x68);
    if (!owner || !st || !w) return;
    if (s->fA&1) {
        func_00382580(&m->pos,0.0f,*(f32 *)(st+0x10));
        vec_add_ba(&m->pos, &m->pos, owner+0x10);
        m->f4=D_L32_001DF3E8;
        s->fC=0;
        s->f18=*(f32 *)(owner+0x10);
        s->f1C=*(f32 *)(owner+0x18);
        m->f8=func_00382498(0,255);
        m->fC=func_003824E0(D_L32_001DF404,D_L32_001DF400);
        m->f3=D_L32_001DF3F8;
        { s32 i=D_L32_001DF410[func_00382498(0,2)]; m->f2=D_L32_0021FAEC[0][i]; }
    }
    { s32 k=D_L32_001DF3FC; m->f8+=(s->fE%(k*2))-k; }
    if (func_0038CB00(&s->fC)) {
        if (owner[0x20]==2 || owner[0x20]==3) {
            s->fC=func_00382498(D_L32_001DF3D4,D_L32_001DF3D0);
            s->f10=func_0038DB48(func_003824E0(0.0f,6.2831855f));
            s->f14=func_003824E0(D_L32_001DF3CC,D_L32_001DF3C8);
        }
    }
    if (owner[0x20]==2 || owner[0x20]==3) {
        m->fA+=1;
    }
    if (owner[0x20]==2 || owner[0x20]==3) {
        {
            func_L32_00347C30(&m->pos,&s->f18,*(f32 *)(owner+0x10));
            func_L32_00347C30(&m->pos.z,&s->f1C,*(f32 *)(owner+0x18));
            move.x=func_0038D098(s->f10)*s->f14;
            move.z=func_0038D0B0(s->f10)*s->f14;
            move.y=0;
            vec_add_ab(&m->pos, &m->pos, &move);
            vec_sub_ba(&delta, &m->pos, owner+0x10);
            if (func_0038CEA8(&delta)<*(f32 *)(st+0x10)) length=func_0038CEA8(&delta);
            else length=*(f32 *)(st+0x10);
            func_0038CF68(&delta,&delta,length);
            vec_add_ba(&m->pos, owner+0x10, &delta);
            vec_sub_ab(&toward, &D_001A4C60, owner+0x10);
            func_0038CF68(&toward,&toward,1.0f);
            vec_sub_ba(&delta, &m->pos, owner+0x10);
            func_0038D890(&blend,&delta,&toward,func_003C4088(D_L32_001DF3C4,D_L32_001DF3C0,func_0038CEA8(&delta)/ *(f32 *)(st+0x10)));
            vec_add_ab(&m->pos, owner+0x10, &blend);
        }
    } else if (owner[0x20]==1) {
        {
            vec_sub_ba(&delta, &m->pos, owner+0x10);
            func_0038CF68(&delta,&delta,D_L32_001DF3F4);
            vec_add_ab(&m->pos, &m->pos, &delta);
        }
    }
    weight=(f32)(u8)s->fE*0.00390625f;
    phase=(f32)(D_L32_001DF9C0%D_L32_001DF420)/(f32)D_L32_001DF420+func_0038CF00(&m->pos,owner+0x10)/ *(f32 *)(st+0x10);
    phase-=cvtsw_asm(cvtws_asm(phase));
    c1=func_0038DBD8(D_L32_001DF3D8,D_L32_001DF3DC,weight);
    c2=func_0038DBD8(D_L32_001DF3E0,D_L32_001DF3E4,weight);
    color=func_0038DBD8(c2,c1,func_0038D0B0(func_0038DB48(phase*6.2831855f))*0.5f+0.5f);
    if (owner[0x20]==3) {
        s32 c3=func_0038DBD8(color,D_L32_001DF3E8,(f32)*(s32 *)(st+0x18)/(f32)D_L32_001DF3B8);
        m->f4=c3;
        m->f4=(c3&0xffffff)|((s32)((f32)(D_L32_001DF3B8-*(s32 *)(st+0x18))*128.0f/(f32)D_L32_001DF3B8)<<24);
    } else if (owner[0x20]==2) {
        m->f4=(color&0xffffff)|0x80000000;
    } else if (owner[0x20]==1) {
        m->f4=color;
        m->f4=(color&0xffffff)|((s32)((f32)(s16)m->fA*128.0f/(f32)s->f8)<<24);
    }
}
/* localdecomp:end func_L32_003C53A0 */
