#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00116F80 */
extern void func_0011B240(s32);
extern void func_0013AFE8(s32) __attribute__((noreturn));
void func_00116F80(void) {
    while (1) {
        func_0011B240(6);
        func_0013AFE8(1);
    }
}
/* localdecomp:end func_00116F80 */

/* localdecomp:start func_00116F98 */
typedef struct Reent_116F98 {
    u8 pad0[0xC];
    void *err;
} Reent_116F98;
extern void *D_0013D770[];
extern char D_00150080[];
extern s32 func_00118950(void *, char *, ...);
extern void func_00116F80(void);

void func_00116F98(char *file, s32 line, char *expr) {
    func_00118950(((Reent_116F98 *)D_0013D770[0])->err, D_00150080, expr, file, line);
    func_00116F80();
}
/* localdecomp:end func_00116F98 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00116FCC);
