#include "common.h"

/* NTSC-U counterpart of func_L07_00335558 (src/levels/07_annihilation_nation/L07_00334B68.c) */
/* localdecomp:start func_L07_00334E18 */
typedef struct St_00335558 {
    u8 pad0[0x80];
    u8 f80[0x30];
    u8 bB0;
    u8 bB1;
    u8 padB2[2];
    s16 hB4;
} St_00335558;
typedef struct Obj_00335558 {
    u8 pad0[0x68];
    St_00335558 *f68;
} Obj_00335558;
typedef struct Row_00335558 {
    s32 w0;
    s32 w4;
} Row_00335558;
typedef struct GunRow_00335558 {
    u8 pad0[0x38];
    u16 icon;
    u8 pad1[0xF0 - 0x3A];
} GunRow_00335558;

extern Row_00335558 D_L07_002B0EB0_00334E18[];
extern GunRow_00335558 D_L07_002C7280[];
extern u8 D_001425C0[];
extern void func_L01_0047A230(void);
extern void func_L01_00477F48(s32, s32);
extern void func_L01_00477FD0(s32, s32);
extern void func_L01_00478168(s32);
extern void func_L01_004789D0(s32);

void func_L07_00334E18(Obj_00335558 *arg0) {
    St_00335558 *s = arg0->f68;
    Row_00335558 *row;
    GunRow_00335558 *gun;

    func_L01_0047A230();
    row = &D_L07_002B0EB0_00334E18[s->bB0];
    gun = &D_L07_002C7280[D_001425C0[row->w0]];
    func_L01_00477F48(gun->icon, 0);
    func_L01_00477FD0(s->hB4, 0);
    func_L01_00478168(row->w0);
    func_L01_004789D0(10);
    s = (St_00335558 *)((u8 *)s + s->bB1);
    row = &D_L07_002B0EB0_00334E18[s->f80[0]];
    gun = &D_L07_002C7280[D_001425C0[row->w0]];
    func_L01_00477F48(gun->icon, 1);
}
/* localdecomp:end func_L07_00334E18 */
