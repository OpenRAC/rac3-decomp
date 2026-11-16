/* PAL near miss (Codex wave 7): near miss: 12 words differ with the file's flags.
 * Worker's note: 12 instruction diffs; build/codex/w361/func_L07_003BB840.a1.log; all are v0 versus v1 in four post-call flag updates. Three compatible flag-update wordings repeat the same bytes. Existing void func_L07_003A2380 signature likely requires a context return-type ...
 */
#include "common.h"
/* localdecomp:start func_L07_003BB840 */
typedef struct { u8 pad[8]; s32 value; } State_003BB840;
typedef struct { u8 pad[0xAA]; s16 type; } Object_003BB840;
typedef struct { u8 pad[0x2808]; Object_003BB840 *object; u8 pad2[0x44]; s32 value; } World_003BB840;
extern State_003BB840 D_00142660;
extern World_003BB840 D_001A4BE0;
void func_L07_003BB840(s32 arg0) {
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern void func_L07_003A2380(s32, s32, s32, s32);
    S_003BB7A8 *st = *(S_003BB7A8 **)((u8 *)arg0 + 0x68);
    if ((D_00142660.value >> 3) >= D_001A4BE0.value) {
        switch (func_00382468(3)) {
        case 0:
            if (!(st->flags & 0x40)) {
                func_L07_003A2380(0x59, arg0, 0, 100);
                st->flags |= 0x40;
                return;
            }
        case 1:
            if (!(st->flags & 0x80)) {
                func_L07_003A2380(0x5A, arg0, 0, 100);
                st->flags |= 0x80;
                return;
            }
        }
    }
    if ((D_00142660.value >> 2) >= D_001A4BE0.value) {
        switch (func_00382468(3)) {
        case 0:
            if (!(st->flags & 0x100)) {
                func_L07_003A2380(0x57, arg0, 0, 100);
                st->flags |= 0x100;
                return;
            }
        case 1:
            if (!(st->flags & 0x200)) {
                func_L07_003A2380(0x58, arg0, 0, 100);
                st->flags |= 0x200;
                return;
            }
        }
    }
    if (D_001A4BE0.object) {
        switch (D_001A4BE0.object->type) {
        case 0x197E:
            if (!func_00382468(5)) {
                func_L07_003A2380(0x5B, arg0, 0, 100);
                return;
            }
        case 0x1A85:
        case 0x1ADB:
        case 0x1B36:
        case 0x1D88:
        case 0x1D89:
        case 0x1D8B:
            func_L07_003A2380(func_00382498(0x54, 0x56) & 0xFF, arg0, 0, 100);
            return;
        }
    }
    func_L07_003A2380(func_00382498(0x52, 0x53) & 0xFF, arg0, 0, 100);
}
/* localdecomp:end func_L07_003BB840 */
