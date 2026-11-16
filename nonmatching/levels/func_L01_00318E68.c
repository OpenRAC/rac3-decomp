/* PAL near miss (Codex wave 10): near miss: 47 words differ with the file's flags.
 * Worker's note: 47 word diffs: build/codex/w537/func_L01_00318E68.try3.log; color argument allocation lacks retail intermediate move; injected divs 0,2 tested, no MATCH
 */
#include "common.h"
/* localdecomp:start func_L01_00318E68 */
extern unsigned long D_L01_001E1770;
typedef struct { u8 pad[0x150]; s16 height, width; } Screen_00318E68;
extern Screen_00318E68 D_001CFEC0;
void func_L01_00318E68(u8 *object) {
    extern unsigned long func_00389598(s32);
    extern f32 func_L01_004451A0(f32);
    extern f32 func_L01_004451A8(f32);
    extern void func_0038AF30(s32, s32, s32, s32, s32);
    extern void func_L01_00319718(u8 *);
    extern void func_L01_00318D80(u8 *);
    u8 *state = *(u8 **)(object + 0x68);
    if (*(s32 *)(state + 0x18) == 0) {
        D_L01_001E1770 = func_00389598(-1);
        if (object[0x20] == 2) {
            f32 fade = func_L01_004451A0(1.0f - (f32)*(s32 *)(state + 4) / 50.0f);
            s32 color = ((s32)(fade * 128.0f) << 24) | 0xFFFFFF;
            func_0038AF30(0, D_001CFEC0.width, 0, D_001CFEC0.height, color);
            func_L01_00319718(object);
        } else if (*(s32 *)(state + 4) >= 88) {
            f32 fade = func_L01_004451A8((f32)(*(s32 *)(state + 4) - 87) / 12.0f);
            s32 color = ((s32)(fade * 128.0f) << 24) | 0xFFFFFF;
            func_0038AF30(0, D_001CFEC0.width, 0, D_001CFEC0.height, color);
        }
    }
    func_L01_00318D80(object);
}
/* localdecomp:end func_L01_00318E68 */
