/* PAL near miss (Codex wave 6): near miss: 3 words differ with the file's flags.
 * Worker's note: 3 diff: RPC packet+0x10 zero store scheduled late; struct, array and reordered stores produce identical wrong bytes; build/codex/w292/func_0012EE18.reorder.log. Fixed flags, no metadata.
 */
#include "common.h"
/* localdecomp:start func_0012EE18 */
typedef struct { u8 pad[0x10]; s32 a, b, c; } Slot_0012EE18;
extern Slot_0012EE18 D_0015BB90_0012EE18[2][4];
typedef struct { s32 command, a, b, result, start, mode; s32 pad[26]; } Packet_0012EE18;
extern s32 D_15BD80_0012EF10[];
extern u8 D_15BB40_0012EF10[];
extern s32 D_00141564;
extern s32 D_00141560;
s32 func_0012EE18(s32 unused) {
    extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);
    extern s32 func_00124920(void);
    extern s32 func_00124970(void);
    extern void func_00121B70();
    extern void func_0012EDD0(void);
    s32 i, state;
    for (i = 0; i < 4; i++) {
        D_0015BB90_0012EE18[0][i].a = 0;
        D_0015BB90_0012EE18[0][i].c = 0;
        D_0015BB90_0012EE18[0][i].b = 0;
        D_0015BB90_0012EE18[1][i].a = 0;
        D_0015BB90_0012EE18[1][i].c = 0;
        D_0015BB90_0012EE18[1][i].b = 0;
    }
    ((Packet_0012EE18 *)D_15BD80_0012EF10)->start = 0;
    ((Packet_0012EE18 *)D_15BD80_0012EF10)->command = 16;
    ((Packet_0012EE18 *)D_15BD80_0012EF10)->mode = D_00141564;
    if (func_00122810(D_15BB40_0012EF10, 1, 0, (void *)D_15BD80_0012EF10, 128, (void *)D_15BD80_0012EF10, 128, 0, 0) < 0) return 0;
    D_00141560 = 0;
    state = func_00124920();
    func_00121B70(0x80000019, func_0012EDD0, 0);
    if (state == 1) func_00124970();
    return ((Packet_0012EE18 *)D_15BD80_0012EF10)->result;
}
/* localdecomp:end func_0012EE18 */
