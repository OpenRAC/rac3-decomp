/* func_L01_004D0E90 (Claude wave 14 r66, 2026-11-28). First draft kept here. */
/* PAL near miss (wave 14 r66, 2026-11-28), first draft of a fresh entry: 498 instruction diffs at level 01 under the
 * file's line with divs metadata '2' (retail has two nops before its one div.s; 499 without). Written from the retail
 * assembly with the functional C's control flow (516 there): no zero-initialised out-parameters at the top, six s32
 * out-parameters in declaration order (retail's 0x0-0x14 slots), func_L01_004D25D0 with two arguments (retail sets only
 * a0/a1), the alpha bytes read as byte 3 of func_L01_004CC758's colour (lbu 3 + sll 24), the weapon table as a 0xF0-byte
 * struct array, and the file's prototypes for func_L01_004CC758 / func_003AAF00. The frame is 0xE0 as in retail.
 * Left: register pressure and spills. Retail keeps the weapon-table base (s7) and 0xF0 (fp) in callee-saved registers
 * inside the slot loop and adds the base with addu (lw 0x68(row)); here the base folds into a constant and the later
 * row accesses become mtlo/madd, which frees a register, so the loop counter stays in s6 where retail spills it
 * (0x1C(sp)) and keeps the name pointer in s6; the spill slots of the CSE'd obj+offset addresses differ from there.
 * Tried: a local table pointer (499) and an inline row helper (530). */
#include "common.h"

/* localdecomp:start func_L01_004D0E90 */
typedef struct {
    s32 name;
    u8 pad4[0x14];
    s32 weapon;
} Slot_004D0E90;
typedef struct {
    Slot_004D0E90 *slots;
} List_004D0E90;
extern List_004D0E90 *D_L01_001DFD68[];
extern u8 D_001439F4[];
extern s32 D_L01_001D67C8[];
typedef struct {
    u8 active;
    u8 level;
    u8 pad2[0x66];
    s32 max;
    u8 pad6C[0x18];
    u16 x84;
    u8 pad86[0x6A];
} Weapon_004D0E90;
extern Weapon_004D0E90 D_L01_002C5600[];
extern u8 D_001425C0[];
extern s32 D_00142DE0[];
extern s32 D_001427F0[];
extern f32 D_L01_001DB718;
__asm__(".extern D_L01_001DB718, 4");

void func_L01_004D0E90(u8 *obj, s32 idx) {
    extern s32 func_L01_004526F8(void);
    extern void func_003AAF00(u8 *, s32);
    extern u32 *func_L01_004CC758(u8 *);
    extern void func_003AB988(u8 *, s32, s32);
    extern u8 *func_L01_004D25D0(s32, s32);
    extern void func_L01_004CD880(s32, s32 *, s32 *, s32 *);
    extern void func_003AB530(u8 *, s32, s32);
    extern void func_003ABBE0(u8 *, s32);
    extern void func_003ABBE8(u8 *, s32);
    extern s32 func_L01_00418DE0(s32, s32);
    extern s32 func_00396690(void);
    extern void func_L01_004CF498(u8 *, s32);
    extern void func_003AD590(u8 *, s32);
    extern void func_L01_004CF3A0(u8 *);
    extern f32 *func_003AB390(u8 *);
    s32 x0, x1, x2;
    s32 y0, y1, y2;
    s32 i;
    s32 w;
    s32 k;
    s32 prev;
    s32 level;
    s32 saved;
    s32 active;
    s32 max;
    Weapon_004D0E90 *row;
    u8 *name;
    u8 *box;
    u32 *p;
    u32 alpha;
    u32 m;
    u32 c0, c1, c2, c3;
    List_004D0E90 *list;
    Slot_004D0E90 *slot;
    f32 ratio;
    f32 g;

    *(s32 *)(obj + 0xB4C) = func_L01_004526F8();
    if (D_L01_001DFD68[0] != 0) {
        if (D_001439F4[0] == 0) {
            func_003AAF00(obj + 0x5C8, 1);
            func_003AAF00(obj + 0x5F8, 0);
        } else {
            func_003AAF00(obj + 0x5C8, 0);
            func_003AAF00(obj + 0x5F8, 1);
        }
        name = obj + 0x664;
        for (i = 0; i < 8; i++) {
            if (D_L01_001DFD68[0]->slots[i].name == 0) {
                func_003AAF00(name, 0);
            } else {
                func_003AAF00(name, 1);
                func_003AB988(name, D_L01_001DFD68[0]->slots[i].name, 0);
            }
            func_003AAF00(func_L01_004D25D0(D_L01_001D67C8[0] + 0x1FCA8, 0) + i * 0x3C, 0);
            x0 = 0;
            x1 = 0;
            x2 = 0;
            func_L01_004CD880(D_L01_001DFD68[0]->slots[i].weapon, &x0, &x1, &x2);
            box = func_L01_004D25D0(D_L01_001D67C8[0] + 0x1FCA8, 0) + i * 0x3C;
            func_003AAF00(box, 1);
            func_003AB530(box, x0, x1);
            func_003ABBE0(box, 100);
            func_003ABBE8(box, 100);
            w = D_L01_001DFD68[0]->slots[i].weapon;
            row = &D_L01_002C5600[D_001425C0[w]];
            if (row->active != 0) {
                level = row->level;
                if (row->max != 0 || level != 0) {
                    saved = 0;
                    if (level != 0) {
                        func_L01_00418DE0(w, level - 1);
                        saved = D_L01_002C5600[D_001425C0[w]].max;
                        func_L01_00418DE0(w, level);
                    }
                    func_003ABBE0(box, D_L01_002C5600[D_001425C0[w]].max - saved);
                    if (D_L01_002C5600[D_001425C0[w]].max > 0) {
                        func_003ABBE8(box, (D_00142DE0[w] >> 5) - saved);
                    }
                }
            }
            name += 0x30;
        }
    }
    if (obj[0xB40] != 0) {
        w = *(s32 *)(obj + 0xB44);
    } else {
        w = func_00396690();
    }
    active = D_L01_002C5600[D_001425C0[w]].active;
    y0 = 0;
    y1 = 0;
    y2 = 0;
    func_L01_004CD880(w, &y0, &y1, &y2);
    *func_L01_004CC758(obj + 0x110) = y2;
    func_L01_004CF498(obj + 0x7E8, 1);
    func_L01_004CF498(obj + 0x870, 1);
    func_L01_004CF498(obj + 0x8F8, 1);
    func_L01_004CF498(obj + 0x980, 1);
    func_L01_004CF498(obj + 0xA08, 1);
    alpha = ((u8 *)func_L01_004CC758(obj + 0x664))[3] << 24;
    for (i = 0; i < 7; i++) {
        p = func_L01_004CC758(obj + 0x694 + i * 0x30);
        *p = (*p & 0xFFFFFF) | alpha;
    }
    p = func_L01_004CC758(obj + 0x5C8);
    *p = (*p & 0xFFFFFF) | alpha;
    p = func_L01_004CC758(obj + 0x5F8);
    *p = (*p & 0xFFFFFF) | alpha;
    func_L01_004CF498(obj + 0xA90, 1);
    m = ((u8 *)func_L01_004CC758(obj + 0x2BC))[3];
    for (i = 0; i < 8; i++) {
        prev = i - 1;
        if (prev < 0) {
            prev = 7;
        }
        list = D_L01_001DFD68[idx];
        if (list != 0) {
            slot = &list->slots[i];
            if (slot->name != 0) {
                k = slot->weapon;
                row = &D_L01_002C5600[D_001425C0[k]];
                if (row->active == 0 || D_001427F0[k] != 0 || row->x84 == 0) {
                    *func_L01_004CC758(obj + prev * 0x3C + 0x2BC) = 0x331465B7;
                } else {
                    *func_L01_004CC758(obj + prev * 0x3C + 0x2BC) = 0x70202080;
                }
            }
        }
        p = func_L01_004CC758(obj + prev * 0x3C + 0x2BC);
        *p = (*p & 0xFFFFFF) | (m << 24);
    }
    p = func_L01_004CC758(obj + 0x244);
    *p = (*p & 0xFFFFFF) | (m << 24);
    c0 = *func_L01_004CC758(obj + 0x280) & 0xFF000000;
    p = func_L01_004CC758(obj + 0x628);
    *p = (*p & 0xFFFFFF) | c0;
    c1 = *func_L01_004CC758(obj + 0xD0) & 0xFF000000;
    c2 = *func_L01_004CC758(obj + 0x110) & 0xFF000000;
    c3 = *func_L01_004CC758(obj) & 0xFF000000;
    if (c3 < c1) {
        c1 = c3;
    }
    p = func_L01_004CC758(obj + 0xD0);
    if (c3 < c2) {
        c2 = c3;
    }
    *p = (*p & 0xFFFFFF) | c1;
    p = func_L01_004CC758(obj + 0x110);
    *p = (*p & 0xFFFFFF) | c2;
    if (*(s32 *)(obj + 0xB38) != 0) {
        if (--*(s32 *)(obj + 0xB38) == 0 && *(s32 *)(obj + 0xB3C) != 1) {
            *(s32 *)(obj + 0xB3C) = 1;
            func_003AAF00(obj + 0x628, 0);
            func_003AD590(obj + 0x7E8, -1);
            func_003AD590(obj + 0x870, -1);
            func_003AD590(obj + 0x8F8, -1);
            func_003AD590(obj + 0x980, -1);
            func_003AD590(obj + 0xA08, -1);
            func_003AD590(obj + 0xA90, -1);
            func_L01_004CF3A0(obj + 0x7E8);
            func_L01_004CF3A0(obj + 0x870);
            func_L01_004CF3A0(obj + 0x8F8);
            func_L01_004CF3A0(obj + 0x980);
            func_L01_004CF3A0(obj + 0xA08);
            func_L01_004CF3A0(obj + 0xA90);
        }
    }
    if (w != 0 && active != 0) {
        max = D_L01_002C5600[D_001425C0[w]].max;
        if (max > 0) {
            ratio = (f32)(D_00142DE0[w] >> 5) / (f32)max;
            g = D_L01_001DB718 * (0.5f - ratio * 0.5f);
            if (g < 1.0f) {
                g = 1.0f;
            }
            ratio = ratio * 30.0f * g;
            if (30.0f < ratio) {
                ratio = 30.0f;
            }
        } else {
            ratio = 30.0f;
        }
        *func_003AB390(obj + 0x78) = ratio;
    }
}
/* localdecomp:end func_L01_004D0E90 */
