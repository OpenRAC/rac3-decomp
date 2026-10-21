#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 D_001D5C78;
extern void (*D_001D9A40[2])(s32);
extern void func_003AFA18(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AF4B8.c's earlier functions (tools/port_from_us.py) */
extern u8 D_001D8798[];
extern u8 D_001D87B0[];
extern void func_00116F98(void *, s32, void *);

/* localdecomp:start func_003AF760 */
extern void func_003AF420(void *, s32);
void func_003AF760(void) {
    s32 i;
    if (D_001D5C78 != 0) {
        for (i = 0; i < 1; i++) {
            func_003AF420((void *)(D_001D5C78 + 0x1FCA8), i);
        }
    }
}
/* localdecomp:end func_003AF760 */

extern void func_003AC590();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AF7C0);

/* localdecomp:start func_003AF850 */
typedef s32 (*FN_A9EF0)();
typedef struct { FN_A9EF0 a; s32 b; } E_A9EF0;
typedef struct { u8 pad[0x24DD0]; void (*cb24DD0)(); u8 padA[0x14]; FN_A9EF0 cb24DE8; u8 padB[4]; E_A9EF0 e1[4]; E_A9EF0 e2[3]; } P_A9EF0;
extern P_A9EF0 *D_001D5C78_003AF850;
extern s32 D_001D9EC0;
extern s32 D_001D5B94;
extern s32 func_003E17A8();
extern void func_003AF760();
void func_003AF850(void) {
    s32 r, i, t;
    E_A9EF0 *e;
    if (D_001D9EC0 == 0) {
        if (D_001D5C78_003AF850 != 0) {
            if (D_001D5C78_003AF850->cb24DE8 != 0) {
                if (D_001D5C78_003AF850->cb24DE8() != 0) return;
            }
            r = 0;
            for (i = 0; i < 4; i++) {
                if (D_001D5C78_003AF850->e1[i].a != 0) {
                    E_A9EF0 *e2 = (E_A9EF0 *)(i * 8 + (s32)D_001D5C78_003AF850 + 0x24DF0);
                    r |= e2->a();
                }
            }
            if (r != 0) return;
            for (i = 0; i < 3; i++) {
                if (D_001D5C78_003AF850->e2[i].a != 0) {
                    E_A9EF0 *e3 = (E_A9EF0 *)(i * 8 + (s32)D_001D5C78_003AF850 + 0x24E10);
                    r |= e3->a();
                }
            }
            if (r != 0) return;
        }
        t = D_001D5B94;
        if (t != 0 && t != 5 && t == 4) {
            if (func_003E17A8() != 7) return;
        }
        if (D_001D5C78_003AF850 != 0) {
            D_001D5C78_003AF850->cb24DD0();
            func_003AF760();
        }
    }
}
/* localdecomp:end func_003AF850 */

/* localdecomp:start func_003AF9E0 */
extern s32 D_001D5C78;
extern s32 D_001D52F0;
void func_003AF9E0(void) {
    if (D_001D5C78 != 0) {
        func_003AF448(D_001D5C78 + 0x1FCA8, D_001D52F0);
    }
}
/* localdecomp:end func_003AF9E0 */

/* localdecomp:start func_003AFA18 */
typedef s32 (*FN_AA0B8)();
typedef struct { s32 a; FN_AA0B8 f; } E_AA0B8;
typedef struct { u8 pad[0x24DCC]; void (*cb24DCC)(); u8 pad2[0x1C]; FN_AA0B8 cb24DEC; E_AA0B8 e1[4]; E_AA0B8 e2[3]; } P_AA0B8;
extern P_AA0B8 *D_001D5C78_003AFA18;
extern s32 D_001D9EC0;
extern s32 D_001D5B94;
typedef struct { u8 p0[0xB0]; f32 fB0; } G_AA0B8;
extern G_AA0B8 D_00225900[];
extern void func_00397FC0();
extern s32 func_003E17A8();
extern void func_003877A0();
extern void func_003AF9E0();
void func_003AFA18(void) {
    s32 r, i, t;
    E_AA0B8 *e;
    G_AA0B8 *g;
    f32 sv;
    if (D_001D9EC0 == 0) {
        if (D_001D5C78_003AFA18 != 0) {
            func_00397FC0();
            r = 0;
            if (D_001D5C78_003AFA18->cb24DEC != 0) r = D_001D5C78_003AFA18->cb24DEC() != 0;
            for (i = 0; i < 4; i++) {
                if (D_001D5C78_003AFA18->e1[i].f != 0) {
                    E_AA0B8 *e2 = (E_AA0B8 *)(i * 8 + (s32)D_001D5C78_003AFA18 + 0x24DF0);
                    r |= e2->f();
                }
            }
            for (i = 0; i < 3; i++) {
                if (D_001D5C78_003AFA18->e2[i].f != 0) {
                    E_AA0B8 *e3 = (E_AA0B8 *)(i * 8 + (s32)D_001D5C78_003AFA18 + 0x24E10);
                    r |= e3->f();
                }
            }
            if (r != 0) return;
        }
        t = D_001D5B94;
        if (t != 0x11 && t != 0 && t != 5 && t == 4) {
            if (func_003E17A8() != 7) return;
        }
        if (D_001D5C78_003AFA18 != 0) {
            D_001D5C78_003AFA18->cb24DCC();
            g = D_00225900;
            sv = g->fB0;
            g->fB0 = 0.62f;
            func_003877A0();
            func_003AF9E0();
            g->fB0 = sv;
            func_003877A0();
        }
    }
}
/* localdecomp:end func_003AFA18 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AFBD8);

/* localdecomp:start func_003AFBF0 */
extern s32 D_001D5C78;
extern s32 D_0031D050[];
extern void func_00396948();
extern void func_003AF850();
void func_003AFBF0(void) {
    if (D_001D5C78 != 0 && D_0031D050[0] == 0) {
        func_00396948(1);
        func_003AF850();
    }
}
/* localdecomp:end func_003AFBF0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AFC30);
