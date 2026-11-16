/* PAL near miss (Codex wave 6): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: 0 diff with full declaration contract (.04.contract.log), same object MATCHes all10 (.contract-object.all.log); ordinary snippet fails (.01.log): Save_00325F60 typedef is later in owner. Retains exact existing signature; integration must move that existing ...
 */
#include "common.h"
/* localdecomp:start func_L01_00325B18 */
typedef struct {
    u8 pad[0x30];
    s32 reached;
    u8 pad34[0x1F];
    u8 gate;
    u8 pad54[4];
    f32 factor;
} Vars_00325B18;
typedef struct {
    s32 level;
    u8 pad04[0x14];
    s32 index;
    u8 pad1C[4];
    s32 health;
    s32 maximum;
    u8 pad28[0x10];
} Gate_00325B18;
extern E_00329038 D_L01_002AEA10[];
extern u16 D_L01_002C4FE8[];
extern u16 D_L01_002C4F60[];
void func_L01_00325B18(u8 *checkpoint, Save_00325F60 *save, u8 *moby) {
    extern s32 func_L01_003B2A08(u8 *);
    s32 *state = (s32 *)save;
    Vars_00325B18 *vars = *(Vars_00325B18 **)(moby + 0x68);
    Gate_00325B18 *gate;
    if (vars->reached != 0) {
        state[23] = -1;
        return;
    }
    if (state[22] <= 0) {
        state[23] = -1;
        return;
    }
    if (vars->factor <= 0.0f) {
        state[23] = -1;
        return;
    }
    if (vars->gate == 0xFF) {
        state[23] = -1;
        return;
    }
    gate = (Gate_00325B18 *)((u8 *)D_L01_002AEA10 + vars->gate * 56);
    if (gate->level <= 0) {
        state[23] = -1;
        return;
    }
    state[23] = vars->gate;
    if (gate->health < 0 || gate->maximum < 0) {
        gate->health = func_L01_003B2A08(moby);
        gate->maximum = (s32)((f32)state[22] * vars->factor / (f32)gate->health * 32.0f);
    }
    D_L01_002C4F60[gate->index] = gate->health;
    D_L01_002C4FE8[gate->index] = gate->maximum;
}
/* localdecomp:end func_L01_00325B18 */
