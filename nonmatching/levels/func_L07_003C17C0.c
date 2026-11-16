/* PAL retail reconstruction, P08 wave 3.
 * Stock check.py: 3 differences with the owner's unchanged
 * -O2 -G8 -fopt-stack -mno-check-zero-division flags.
 * Only the initial count-zero store versus the s3 save/state load differs.
 * Moving the state load and using a typed object gave identical residual bytes;
 * stopped after three ordinary formulations retained that residual.
 * The owning INCLUDE_ASM remains. Full PAL/US linkage is not verified.
 */
#include "common.h"
typedef struct { u8 kind; u8 pad; s16 id; u8 pad4[0x10]; s32 name, desc; u8 tail[8]; } Entry_3C17C0;
typedef struct { u8 pad[0x68]; u8 *state; } Object_3C17C0;
extern Entry_3C17C0 D_L07_002BC920_003C17C0[] __asm__("D_L07_002BC920");
extern u8 D_001426E0[];
extern u8 D_L07_001DE590[];
extern u8 D_L07_001E1708[] __attribute__((section(".sdata")));
extern u8 D_L07_001E1710[] __attribute__((section(".sdata")));
extern void func_L07_003C19C8();
extern s32 func_L07_003C1B88(s32);
extern s32 func_L07_003C1C08(s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00516FD8(s32, void *);
extern s32 func_0011B2E8(void *, void *, ...);
extern s32 func_L07_003C1360(s32);
extern void func_L07_00334878(s32, s32 *, s32 *, s32 *);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00517190(s32, s32);
void func_L07_003C17C0(void *raw) {
    u8 *arg0 = raw;
    s32 values[3];
    s32 count;
    u8 *s;
    Entry_3C17C0 *entry;
    s32 id;
    s32 i;
    s32 widget;
    count = 0;
    s = ((Object_3C17C0 *)arg0)->state;
    func_L07_003C19C8(arg0, *(s32 *)(s + 0x24), &count, 0x8066CCFF);
    func_L07_003C19C8(arg0, *(s32 *)(s + 0x20), &count, 0x80808080);
    entry = &D_L07_002BC920_003C17C0[s[0x38]];
    id = func_L07_003C1B88(s[0x38]);
    if (id == -1) {
        func_L01_00516FD8(0x47000F, (void *)func_00381FF0(entry->name));
    } else {
        func_L01_00516FD8(0x47000F, (void *)func_00381FF0(id));
    }
    id = func_L07_003C1C08(s[0x38]);
    if (id == -1) {
        func_L01_00516FD8(0x470012, (void *)func_00381FF0(entry->desc));
    } else {
        func_L01_00516FD8(0x470012, (void *)func_00381FF0(id));
    }
    func_0011B2E8(D_L07_001E1708, D_L07_001DE590, D_001426E0[s[0x38] + 0x8E]);
    id = func_L07_003C1360(s[0x38]);
    func_0011B2E8(D_L07_001E1710, D_L07_001DE590, id);
    if (entry->kind == 0) {
        func_L07_00334878(entry->id, &values[0], &values[1], &values[2]);
    } else {
        values[2] = 0;
        values[1] = 0;
        values[0] = 0;
    }
    widget = 0x470014;
    for (i = 0; i < 3; i++) {
        if (values[i] == 0) {
            func_L01_00516AA0(widget, 1, 0);
        } else {
            func_L01_00516AA0(widget, 1, 1);
            func_L01_00517190(widget, values[i]);
        }
        widget++;
    }
    func_L01_00517190(0x47001C, s[0x38] + 10);
}
