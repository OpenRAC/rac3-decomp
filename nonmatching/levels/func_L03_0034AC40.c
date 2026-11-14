/* NTSC-U draft (2026-11-14, Codex worker): C of func_L03_0034A080, the NTSC-U twin of func_L03_0034AC40, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 10 words differ with its file's flags.
 */
#include "common.h"

/* localdecomp:start func_L03_0034A080 */
typedef struct { u8 pad[0xC]; s32 camera; s32 ids[4]; } Vars_34A080;
typedef struct { u8 pad[0x68]; Vars_34A080 *vars; } Object_34A080;
typedef struct { u8 pad[0x558]; u8 active; u8 rest[0x5C0-0x559]; } Player_34A080;
typedef struct Moby_34A080 { u8 pad[0x28]; struct Moby_34A080 *next; u8 pad2[0xAA-0x2C]; s16 cls; u8 pad3[0xBC-0xAC]; u8 state; } Moby_34A080;
typedef struct { u8 pad[0x1A4]; s32 buttons; } Pad_34A080;
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004FC518(s32, s32);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern void func_L01_003E9510(s32, void *), func_L01_003E94A0(s32, void *);
extern s32 func_00399C90(s32, s32);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_0038E5B8(s32, s32);
extern s32 func_L03_0034A2A8(void *, s32);
extern void func_L03_0034A318(void *, void *);
extern u8 D_L03_001E2540[];
extern u8 *D_L03_001DFB00;
__asm__(".extern D_L03_001DFB00, 16");
typedef struct { u8 flag; u8 pad[15]; } Flag_34A080;
extern Flag_34A080 D_001427BB;
extern s32 D_001DD67C_sda;
__asm__(".extern D_001DD67C_sda, 4");
extern s32 D_L03_001E1490;
__asm__(".extern D_L03_001E1490, 16");
extern s32 D_L03_001E149C;
__asm__(".extern D_L03_001E149C, 16");
extern Player_34A080 D_001CD0C0[];
extern Pad_34A080 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern Moby_34A080 *D_L03_001DFA28;
__asm__(".extern D_L03_001DFA28, 16");
extern u8 *D_L03_001DFA1C;
__asm__(".extern D_L03_001DFA1C, 16");

void func_L03_0034A080(Object_34A080 *obj) {
    s32 count = 0;
    Vars_34A080 *vars = obj->vars;
    if (func_L01_00452EC8(obj)) {
        s32 i;
        func_L01_004FC518(0x74, 1);
        func_L01_003E9588(0, D_L03_001E2540, D_L03_001E2540 + 0x10, 1, 0x78, 0);
        func_L01_003E9510(0, D_L03_001DFB00 + vars->camera * 0x80 + 0x70);
        func_L01_003E94A0(0, D_L03_001DFB00 + vars->camera * 0x80 + 0x30);
        D_001427BB.flag = 0;
        func_00399C90(0, 3);
        D_001DD67C_sda = 0;
        for (i = 3; i >= 0; i--) (&D_L03_001E149C)[i - 3] = -1;
        for (i = 0; i < 8 && count < 5; i++) {
            if (D_001CD0C0[i].active) (&D_L03_001E1490)[count++] = i;
        }
        func_L01_0044F2E8(0, 5, 0xE79, 1, 0, 0, 0);
    }
    if (D_001D52FC->buttons & 0x800) func_0038E5B8(3, 1);
    if (func_L03_0034A2A8(obj, 1) < 2) {
        Moby_34A080 *m = D_L03_001DFA28;
        D_001DD67C_sda = 1;
        while (m) {
            if (m->cls == 0x1B9B) m->state = 1;
            m = m->next;
        }
    }
    if (func_L03_0034A2A8(obj, 0) < 2) {
        s32 i;
        for (i = 0; i < 4; i++) func_L03_0034A318(obj, D_L03_001DFA1C + vars->ids[i] * 0x100);
        D_001DD67C_sda = 0;
    }
}
/* localdecomp:end func_L03_0034A080 */
