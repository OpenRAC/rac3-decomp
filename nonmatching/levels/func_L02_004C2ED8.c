/* PAL near miss: 259 diff, 44 register-masked structural words (302 before). Measured with check.py --no-context
 * --flags=-mvu0-use-vf0-vf2 --as ps2as and a divs_nops row `func_L02_004C2ED8 1` (retail has one nop before its div.s;
 * neither is committed), i.e. src/levels/shared/L02_004C2ED8.c needs `-mvu0-use-vf0-vf2` and `@ps2as` on its line.
 * Round 12 (s4): the two inline VU0 asm blocks are vec_sub_ba / vec_copy + vec_add_ba + vec_add_ab from vu0.h.
 * Left: the branch layout of the early returns (retail keeps the `reject` block `b epilogue; move $v0,$zero` right after the
 * mode == 0x74 test, with the first two tests branching into it and the third inverted; here the block is merged
 * with the other returns: no_label / one_if / separate_ifs / late label all 258-260), the movn/movz choice of the n clamp
 * (retail `movz $a0,$zero,$v0`, here `movn $a0,$a1,$v0`), and the state-3 branch shape.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L02_004C2ED8 */
typedef struct {
    u8 pad0[0x80]; vu0_v4 pos;
    u8 pad90[0x60]; vu0_v4 offset;
    u8 pad100[0x10]; vu0_v4 offset2;
    u8 pad120[0xBC]; s16 timer;
    u8 pad1DE[0x3E]; s16 timer2;
    u8 pad21E[0x16]; s32 blocked;
    u8 pad238[0x1241]; u8 grounded;
    u8 pad147A[0x236]; s32 camera;
    u8 pad16B4[0xF0C]; u8 *target;
    s32 mode; s32 pad25C8; s32 state;
    u8 pad25D0[0x14]; u8 form;
    u8 pad25E5[0x223]; u8 *interacted;
    u8 pad280C[0x44]; s32 active;
} Hero_004C2ED8;
typedef struct {
    u8 pad0[0x10]; vu0_v4 direction;
    u8 *target; u32 flags; u8 kind; u8 pad29[3];
    f32 amount; u32 flags30; s32 pad34; u8 *owner; s32 pad3C;
} Contact_004C2ED8;
extern Hero_004C2ED8 D_001A4BE0;
extern s32 D_L02_001D6694[];
extern Contact_004C2ED8 D_L02_001EC2C0[];
extern u8 D_00142660[];
extern s16 D_001426A0[];
s32 func_L02_004C2ED8(s32 apply) {
    extern s32 func_L01_0041A4F0(void);
    extern f32 func_L01_004C93D8(void);
    extern f32 func_L01_004C9360(f32);
    extern f32 func_L01_004DFE88(s32);
    extern void func_L01_004E1560(void);
    extern void func_L01_005110E8(void *,s32,f32,f32,f32);
    extern void func_L02_004D36C0(s32,s32);
    extern u8 *func_L01_00447490(u8 *,s32,s32);
    extern void func_L01_004DFEA0(s32);
    extern void func_L01_003F1F20(s32,s32);
    extern void func_L01_004F4E70(s32,s32);
    extern void func_L01_004ED838(void *,s32,f32,f32);
    extern void func_L01_00511618(void *,void *,f32);
    Contact_004C2ED8 *c;
    vu0_v4 move,copy;
    u8 *other;
    s32 n;
    f32 rate;
    if (D_001A4BE0.state==20 || D_001A4BE0.state==7 || D_001A4BE0.mode==0x74) {
reject:
        return 0;
    }
    if (D_001A4BE0.mode==0x31) return 0;
    if (D_001A4BE0.timer) return 0;
    if (D_L02_001D6694[0]) return 0;
    D_001A4BE0.interacted=0;
    if (D_001A4BE0.target[0xA8]==255) goto reject;
    c=&D_L02_001EC2C0[D_001A4BE0.target[0xA8]];
    if (c->owner!=D_001A4BE0.target) return 0;
    if (!(c->flags&9)) return 0;
    if (D_001A4BE0.blocked) return 0;
    if (c->amount!=0.0f && func_L01_0041A4F0() && D_001A4BE0.form!=5) {
        D_00142660[0x5A]=0;
        D_00142660[0x5B]=0;
    }
    if (func_L01_004C93D8()!=0.0f && D_001A4BE0.form==0 && !(c->flags&0x20000000)) {
        c->amount=func_L01_004C9360(c->amount);
        if (c->amount==0.0f) goto reject;
    }
    if ((c->flags&0x20000000) && D_001A4BE0.form==0) {
        n=D_001426A0[0];
        if (n>4) n=4;
        if (n<=-1) n=0;
        c->amount/=func_L01_004DFE88(n);
    }
    D_001A4BE0.interacted=c->target;
    if (apply) {
        func_L01_004E1560();
        apply=0;
        if (c->flags30&1) {
            *(vu0_q *)&move=*(vu0_q *)&c->direction;
            if (c->direction.w==5627.9248046875f) apply=1;
        } else if (c->target) {
            vec_sub_ba(&move, &D_001A4BE0.pos, c->target+0x10);
        } else {
            func_L01_005110E8(&move,0,-1.0f,0.0f,0.0f);
        }
        if (D_001A4BE0.form==0) {
            if (D_001A4BE0.interacted) {
                n=*(s16 *)(D_001A4BE0.interacted+0xAA);
                if (n==0x4EB || n==0x558 || n==0x1C5F) {
                    func_L02_004D36C0(0x82,1);
                    return 1;
                }
            }
            if ((D_001A4BE0.mode==1 || D_001A4BE0.mode==29 || D_001A4BE0.camera==2) && !(c->flags&8)) {
                other=func_L01_00447490(D_001A4BE0.target,1,0);
                if (other) func_L01_004DFEA0((s32)*(f32 *)(other+0x2C));
                if (!D_001A4BE0.active) func_L02_004D36C0(22,1);
                else func_L01_003F1F20(18,0);
                D_001A4BE0.timer=64;
                if (D_001A4BE0.timer2==0) D_001A4BE0.timer2=15;
                func_L01_004F4E70(20,0);
                return 0;
            }
            if (D_001A4BE0.state==18) func_L02_004D36C0(0x77,1);
            else if (D_001A4BE0.state==17) func_L02_004D36C0(0x78,1);
            else if (c->flags&8) func_L02_004D36C0(0x91,1);
            else func_L02_004D36C0(22,1);
            if (D_001A4BE0.mode==0x91) {
                qzero(&move);
            } else {
                rate=0.0660000071f;
                if (D_001A4BE0.grounded) rate=0.0f;
                func_L01_004ED838(&move,apply,rate,0.0340000018f);
                if (apply && c->kind==4) func_L01_00511618(&move,&move,2.0f);
            }
        } else if (D_001A4BE0.form==3) {
            func_L02_004D36C0(0x55,1);
            func_L01_004ED838(&move,apply,0.10000000894f,0.0480000041f);
        }
        vec_copy(&copy, &move);
        vec_add_ba(&D_001A4BE0.offset, &D_001A4BE0.offset, &move);
        vec_add_ab(&D_001A4BE0.offset2, &D_001A4BE0.offset2, &copy);
        return 1;
    }
    if (!D_001A4BE0.timer) {
        other=func_L01_00447490(D_001A4BE0.target,1,0);
        if (other) func_L01_004DFEA0((s32)*(f32 *)(other+0x2C));
        else func_L01_004DFEA0(1);
        D_001A4BE0.timer=64;
    }
    return 1;
}
/* localdecomp:end func_L02_004C2ED8 */
