/* near miss (open-rac-engine names it hero_enter_water), 3 words, all scheduling: where the
 * water jump's check starts (state == 18), retail loads the state before it loads the 18
 * (lw $v1; addiu $v0, 18; bne $v1, $v0); this schedules the 18 first, into $v1 beside the
 * block's address (addiu $v1, 18; lw $v0), and a bc1f then takes the 18 into its delay slot
 * where retail's bc1fl takes the load. Every other word matches. Uses the file context of
 * src/levels/shared/L01_004FE668.c.
 * 2026-11-11: sched1 has the block's `addiu` address and the 18 both ready in its first cycle
 * and issues them together, the load a cycle later; retail's order needs the 18 not ready
 * then. Same 8 words with: a nested if, a switch, `!(state != 18)`, `18 == state`, a u32
 * cast, `state - 18 == 0`, and a hero pointer local set before the test (a pointer local set
 * before both this test and the next one is worse, 23 words). */
#include "common.h"

/* localdecomp:start func_L01_00504FE0 */
typedef struct {
    u8 pad0[0x88];
    f32 feet;              /* 0x88: pos.z, the height of his feet */
    u8 pad8C[0xF8 - 0x8C];
    f32 intended_vel_z;    /* 0xF8 */
    u8 padFC[0x118 - 0xFC];
    f32 vel_z;             /* 0x118 */
    u8 pad11C[0x23C - 0x11C];
    s32 drown_counter;     /* 0x23C */
    u8 pad240[0x350 - 0x240];
    f32 surface;           /* 0x350: the water's surface under him */
    u8 pad354[0x46E - 0x354];
    u8 past_apex;          /* 0x46E: the jump is on its way down */
    u8 pad46F[0x1476 - 0x46F];
    u8 water;              /* 0x1476: water under him */
    u8 pad1477[0x25C0 - 0x1477];
    s32 hero_moby;         /* 0x25C0 */
    s32 state;             /* 0x25C4 */
    s32 substate;          /* 0x25C8 */
    s32 state_type;        /* 0x25CC */
    u8 pad25D0[0x2848 - 0x25D0];
    f32 depth;             /* 0x2848: the surface less the floor */
    u8 pad284C[0x2850 - 0x284C];
    s32 health;            /* 0x2850 */
} H_504FE0;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} V_504FE0;
extern s32 D_L01_001DFB40; /* the frame counter */
extern f32 D_L01_001EAA20[]; /* the last probe's hit point */
extern void func_L01_004EF6F0(V_504FE0 *from, V_504FE0 *to, s32 a2, f32 length, f32 height);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_003D5630(void);
extern s32 func_L01_005003D0_00504FE0(s32 state, s32 flag);
extern s32 func_L01_004F4E70(s32 a0, s32 a1);

/* hero_enter_water: puts a hero in water into surface idle (54), or surfaces one rising under
   it; every 16 frames, a hero over ground he can't stand on under the water sinks (51). */
s32 func_L01_00504FE0(void) {
    s32 gets_in;
    f32 slack;
    f32 fall;
    V_504FE0 from;
    V_504FE0 to;
    f32 length;

    if ((*(H_504FE0 *)&D_001A4BE0).state == 121 || (*(H_504FE0 *)&D_001A4BE0).state == 108) {
        return 0;
    }
    gets_in = 0;
    if ((*(H_504FE0 *)&D_001A4BE0).water != 0) {
        if ((*(H_504FE0 *)&D_001A4BE0).state_type == 17) {
            /* under water: surfaces rising within 0.4 u of the top */
            if ((*(H_504FE0 *)&D_001A4BE0).substate != 1 && (*(H_504FE0 *)&D_001A4BE0).vel_z > 0.0f &&
                (*(H_504FE0 *)&D_001A4BE0).surface - 0.4f < (*(H_504FE0 *)&D_001A4BE0).feet) {
                gets_in = 1;
            }
        } else if ((*(H_504FE0 *)&D_001A4BE0).state_type != 18 && (*(H_504FE0 *)&D_001A4BE0).state_type != 3) {
            /* 0.2 u of slack, or this frame's fall and 0.07 u */
            slack = 0.2f;
            fall = __builtin_fabsf((*(H_504FE0 *)&D_001A4BE0).intended_vel_z) + 0.07f;
            if (fall > slack) {
                slack = fall;
            }
            /* falling with his feet about 0.45 u under in water over 0.8 u deep */
            if (__builtin_fabsf((*(H_504FE0 *)&D_001A4BE0).surface - ((*(H_504FE0 *)&D_001A4BE0).feet + 0.45f)) < slack &&
                ((*(H_504FE0 *)&D_001A4BE0).state_type != 4 || (*(H_504FE0 *)&D_001A4BE0).past_apex != 0) &&
                (*(H_504FE0 *)&D_001A4BE0).depth > 0.8f && (*(H_504FE0 *)&D_001A4BE0).vel_z < 0.0f) {
                gets_in = 1;
            }
            /* or more than 0.8 u under */
            if ((*(H_504FE0 *)&D_001A4BE0).feet < (*(H_504FE0 *)&D_001A4BE0).surface - 0.8f &&
                ((*(H_504FE0 *)&D_001A4BE0).state_type != 4 || (*(H_504FE0 *)&D_001A4BE0).past_apex != 0)) {
                gets_in = 1;
            }
        }
    }
    /* a water jump back down, 0.7 u under */
    if ((*(H_504FE0 *)&D_001A4BE0).state == 18 && (*(H_504FE0 *)&D_001A4BE0).past_apex != 0 &&
        (*(H_504FE0 *)&D_001A4BE0).feet < (*(H_504FE0 *)&D_001A4BE0).surface - 0.7f) {
        gets_in = 1;
    }
    if ((*(H_504FE0 *)&D_001A4BE0).state_type != 17 && (*(H_504FE0 *)&D_001A4BE0).state_type != 18 &&
        (*(H_504FE0 *)&D_001A4BE0).state_type != 7 && (*(H_504FE0 *)&D_001A4BE0).state != 18 &&
        (D_L01_001DFB40 & 0xF) == 0) {
        length = 4.0f;
        if (D_L01_001DFB40 % 63 == 0) {
            length = 16.0f;
        }
        func_L01_004EF6F0(&from, &to, 0, length, 1.3f);
        if (func_003D3CB0(&from, &to, 2, (*(H_504FE0 *)&D_001A4BE0).hero_moby, 0) != 0 && func_003D5630() == 0) {
            from.z = D_L01_001EAA20[2] - 0.01f;
            if (func_003D3CB0(&from, &to, 2, (*(H_504FE0 *)&D_001A4BE0).hero_moby, 0) == 0) {
                if ((*(H_504FE0 *)&D_001A4BE0).state_type == 20 || (*(H_504FE0 *)&D_001A4BE0).health == 0) {
                    func_L01_005003D0_00504FE0(108, 1);
                } else {
                    func_L01_005003D0_00504FE0(51, 1);
                }
                return 1;
            }
        }
    }
    if (gets_in != 0) {
        if ((*(H_504FE0 *)&D_001A4BE0).state_type == 20 || (*(H_504FE0 *)&D_001A4BE0).health == 0) {
            if (func_L01_005003D0_00504FE0(108, 3) != 0) {
                (*(H_504FE0 *)&D_001A4BE0).drown_counter = 58;
            }
        } else {
            func_L01_005003D0_00504FE0(54, 1);
        }
        func_L01_004F4E70(3, 0);
    }
    return gets_in;
}
/* localdecomp:end func_L01_00504FE0 */
