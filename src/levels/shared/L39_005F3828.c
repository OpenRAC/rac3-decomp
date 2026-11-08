#include "common.h"

typedef struct { u8 before[0xB8]; s32 count; u8 *table; } CallbackGlobals;
typedef struct { u8 active; u8 pad[0x5F]; } Slot;

/* localdecomp:start func_L39_005F3828 */
extern u8 D_001FE020[];
extern Slot D_L39_002B8DA0[12];
extern void func_L39_005F3B18(Slot *p);

void func_L39_005F3828(void) {
    s32 i;
    for (i = 0; i < ((CallbackGlobals *)D_001FE020)->count; i++) {
        u8 *entry = (u8 *)(i * 0x90 + (s32)((CallbackGlobals *)D_001FE020)->table);
        void (*callback)(u8 *) = *(void (**)(u8 *))(entry + 4);
        if (callback) callback(entry);
    }
    for (i = 0; i < 12; i++) {
        if (D_L39_002B8DA0[i].active) func_L39_005F3B18(&D_L39_002B8DA0[i]);
    }
}
/* localdecomp:end func_L39_005F3828 */

INCLUDE_ASM("asm/levels", func_L39_005F38D0);

INCLUDE_ASM("asm/levels", func_L39_005F3948);
