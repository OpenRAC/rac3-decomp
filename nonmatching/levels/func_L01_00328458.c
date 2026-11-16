/* PAL near miss (Codex wave 10): near miss: 63 words differ with the file's flags.
 * Worker's note: try5.log: 63 positional diffs (316 vs 320 bytes), one missing epilogue-delay instruction before DF D38 gate; three formulations unchanged; plain C draft retained
 */
#include "common.h"
/* localdecomp:start func_L01_00328458 */
extern s32 D_001A71A4[];
extern s32 D_001D545C;
extern s32 D_L01_001DFD38[];
extern s32 D_L01_001DF95C;
extern s32 D_L01_001E15E0[];
extern u8 D_L01_003287D8[];
typedef struct { u8 pad[0x951C]; u16 flag; } State_00328458;
extern State_00328458 D_001A7E18;
extern s32 D_001DFB40_sda;
void func_L01_00328458(s32 unused, u8 *arg) {
    extern s32 func_L01_00327A78(void);
    extern s32 func_L01_00327968(void);
    extern s32 *func_003E6C08(void);
    extern void func_L01_00515C78(s32 *, u8 *);
    extern s32 func_L01_0041A5B0(s32, s32);
    u8 *v = *(u8 **)(*(u8 **)(arg + 0x30) + 0x68);
    s32 *p;
    State_00328458 *state;
    if (*(s32 *)(v + 0x30) == 0 && func_L01_00327A78() && func_L01_00327968()) {
    if (D_001A71A4[0] != 116 && D_001A71A4[0] != 101 && !D_L01_001DFD38[0] && !D_L01_001DF95C) {
    p = D_L01_001E15E0;
    if (!p[1]) p = func_003E6C08();
    func_L01_00515C78(p, D_L01_003287D8);
    if (D_001D545C == 4 && *(s32 *)v == 500) {
        state = &D_001A7E18;
        if (state->flag == 0 &&
            (*(s32 *)(v + 0x60) != 0 && D_001DFB40_sda - *(s32 *)(v + 0x60) >= 301)) {
            if (func_L01_0041A5B0(3181, 87) && state->flag == 0)
                state->flag = 1;
        }
    }
    }
    }
}
/* localdecomp:end func_L01_00328458 */
