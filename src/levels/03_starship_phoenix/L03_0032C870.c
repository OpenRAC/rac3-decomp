#include "common.h"

typedef struct S_Foo_0032D228 {
    u8 pad0[0xF2];
    u16 f2;
    u8 f4;
    u8 pad1[0x108 - 0xF5];
    s32 f108;
} S_Foo_0032D228;

typedef struct S_0032D598 {
    u8 pad[0xB4];
    s32 cnt[16];
} S_0032D598;

typedef struct { u8 pad0[0x30]; u8 b30[0x40]; u8 b70[0x10]; } Ent_32CF78;
typedef struct { u8 pad0[0x68]; struct { u8 pad[0xD0]; s32 idx; } *p68; } Obj_32CF78;


/* localdecomp:start func_L03_0032C870 */
extern s32 D_001DD118_sda;
__asm__(".extern D_001DD118_sda, 4");
s32 *func_L03_0032C870(void *unused, s32 a1, s32 *out) {
    if (a1 == 0) {
        *out = 16;
        return &D_001DD118_sda;
    }
    return 0;
}
/* localdecomp:end func_L03_0032C870 */

/* localdecomp:start func_L03_0032C890 */
extern u8 D_001DD10A_sda;
__asm__(".extern D_001DD10A_sda, 1");
extern void *D_001DD104_sda;
__asm__(".extern D_001DD104_sda, 4");
extern u32 D_001A7F70[];
__asm__(".extern D_001A7F70, 16");
extern u32 D_001D545C;
__asm__(".extern D_001D545C, 16");
void func_L01_0041A5B0(s32 a, s32 b);
void func_L03_0032CF78_0032C890(void *a, s32 b);

void func_L03_0032C890(s32 a, u8 b) {
    D_001DD10A_sda = b;
    if (a == 0x7F) {
        if ((D_001A7F70[0] & (1 << D_001D545C)) == 0) {
            func_L01_0041A5B0(0xB79, 0x1C);
        }
    }
    func_L03_0032CF78_0032C890(D_001DD104_sda, a);
}
/* localdecomp:end func_L03_0032C890 */

/* localdecomp:start func_L03_0032C8F8 */
extern u8 D_L03_001DD10A;

s32 func_L03_0032C8F8(void) {
    if (D_L03_001DD10A != 0) {
        D_L03_001DD10A = 0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L03_0032C8F8 */

INCLUDE_ASM("asm/levels", func_L03_0032C918);

INCLUDE_ASM("asm/levels", func_L03_0032CBD8);
