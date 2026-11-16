/* PAL near miss (Codex wave 8): near miss: 10 words differ with the file's flags.
 * Worker's note: Best 10 word diffs in build/codex/w395/func_L01_00326E50.01.log: loop preheader (7) and spawn index register (3); ten compiles without improvement; fixed flags and callee types preserved.
 */
#include "common.h"
/* localdecomp:start func_L01_00326E50 */
extern E_00329038 D_L01_002AEA10[];
extern u8 D_001426E0[];
extern u8 *D_L01_001E0100;
void func_L01_00326E50(u8 *arg) {
    extern s32 func_L01_003257E8(void);
    extern void func_L01_0043B510(s32);
    extern s32 func_L01_003294A0(s32, List_003290D8 *, s32);
    extern void func_0039EF28(void);
    extern void func_L01_004A3610(u8 *, u8 *);
    u8 *pv = *(u8 **)(arg + 0x68);
    s32 owner = func_L01_003257E8();
    u8 *save = *(u8 **)(owner + 0x68);
    u8 *entry;
    s32 i;
    u8 *spawn;
    E_00329038 *scan;
    if (*(s32 *)(pv + 0x44) != 0) return;
    if (*(s32 *)(pv + 8) != -1) func_L01_0043B510(*(s32 *)(pv + 8));
    if (pv[0x53] == 255) return;
    entry = (u8 *)&D_L01_002AEA10[pv[0x53]];
    if (*(s32 *)(entry + 12) == 0) return;
    D_001426E0[*(s32 *)(entry + 12)]++;
    if (D_001426E0[*(s32 *)(entry + 12)] > 100) D_001426E0[*(s32 *)(entry + 12)] = 100;
    if (D_001426E0[*(s32 *)(entry + 12)] == 1) {
        switch (*(s32 *)(entry + 40)) {
        case 1:
            D_001426E0[0x71] = 255;
            D_001426E0[0x72] = -1;
            break;
        case 2:
            func_L01_003294A0(owner, (List_003290D8 *)save, *(s32 *)(entry + 44));
            break;
        }
    }
    if (*(s32 *)(entry + 20) != 0) D_001426E0[*(s32 *)(entry + 20)] = 1;
    i = 0;
    scan = D_L01_002AEA10;
    if (*(s32 *)scan >= 0) {
        do {
            s32 gate = scan->w12;
            if (gate != 0 && gate != 47 && gate != 192) {
                if (D_001426E0[gate] == 0) break;
            }
            scan++;
            i++;
        } while (*(s32 *)scan >= 0);
    }
    if (*(s32 *)&D_L01_002AEA10[i] == -1) {
        D_001426E0[0xBD] = 1;
        func_0039EF28();
    }
    func_0039EF28();
    spawn = D_L01_001E0100 + (*(s32 *)(save + 40) << 7);
    func_L01_004A3610(spawn + 48, spawn + 112);
}
/* localdecomp:end func_L01_00326E50 */
