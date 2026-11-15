#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 116F80.c's earlier functions */
extern void func_0011B240(s32);
extern void func_0013AFE8(s32);

typedef struct Reent_116F98 {
    u8 pad0[0xC];
    void *err;
} Reent_116F98;
extern void *D_0013D770[];
extern char D_00150080[];
extern s32 func_00118950(void *, char *, ...);
extern void func_00116F80(void);

typedef struct At_116FD0 {
    struct At_116FD0 *next;
    s32 ind;
    void (*fns[32])(void);
} At_116FD0;
typedef struct {
    u8 pad148[0x148];
    At_116FD0 *atexit;
    At_116FD0 atexit0;
} Reent_116FD0;
extern void *D_0013D770[];
extern void *func_001194E8(u32);

extern long func_0011BFD8(s32, s32, s32);

extern s32 func_0011A160();

typedef struct Bigint_1171C8 {
    struct Bigint_1171C8 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_1171C8;
extern s32 func_0011ABB8(Bigint_1171C8 *, Bigint_1171C8 *);

/* declarations of 118660.c's earlier functions */
/* func_00118660: returns the global pointer stored at D_0013D770.
   Retail reaches D_0013D770 through lui/%lo, so the global is declared as an
   unsized array (never small data) and read at offset 0. */

extern void *D_0013D770[];

/* localdecomp:start func_00118670 */
typedef struct Reent_118670 {
    u8 pad0[0x3C];
    void (*cleanup)(struct Reent_118670 *);
    u8 pad40[0x148 - 0x40];
    At_116FD0 *atexit;
} Reent_118670;

/* exit */
void func_00118670(s32 code)
{
    register At_116FD0 *p;
    register s32 n;

    for (p = ((Reent_118670 *)D_0013D770[0])->atexit; p; p = p->next)
        for (n = p->ind; --n >= 0;)
            (*p->fns[n])();
    if (((Reent_118670 *)D_0013D770[0])->cleanup)
        (*((Reent_118670 *)D_0013D770[0])->cleanup)((Reent_118670 *)D_0013D770[0]);
    func_0013AFE8(code);
}
/* localdecomp:end func_00118670 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011871C);
