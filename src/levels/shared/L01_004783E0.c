#include "common.h"

/* localdecomp:start func_L01_004783E0 */
extern void func_L01_00517538(f32);
void func_L01_004783E0(s32 a0, s32 a1, s32 a2, f32 f) {
    f32 r;
    if (a2 == 0) {
        a2 = 1;
    }
    if (a2 > 0) {
        r = (f32)a1 / (f32)a2;
    } else {
        r = 0.0f;
    }
    if (r > 1.0f) {
        r = 1.0f;
    }
    func_L01_00517538(f * r);
}
/* localdecomp:end func_L01_004783E0 */

/* localdecomp:start func_L01_00478450 */
extern void func_L01_005169C8(f32);
void func_L01_00478450(s32 a0, s32 a1, s32 a2, f32 f) {
    f32 r;
    if (a2 == 0) {
        a2 = 1;
    }
    if (a2 > 0) {
        r = (f32)a1 / (f32)a2;
    } else {
        r = 0.0f;
    }
    if (r > 1.0f) {
        r = 1.0f;
    }
    func_L01_005169C8(f * r);
}
/* localdecomp:end func_L01_00478450 */

INCLUDE_ASM("asm/levels", func_L01_004784C0);

/* localdecomp:start func_L01_004785E8 */
typedef struct { u8 pad[4648]; s32 w; u8 pad2[9700 - 4652]; u8 b; } S474;
extern S474 D_001A4BE0;
s32 func_L01_004785E8(void) {
    S474 *p = &D_001A4BE0;
    s32 v = p->w;
    if (v == 9) v = 0;
    if (p->b) v = 0;
    return v;
}
/* localdecomp:end func_L01_004785E8 */

INCLUDE_ASM("asm/levels", func_L01_00478608);

/* localdecomp:start func_L01_00478898 */
extern void func_L01_00478898(void);
extern void *func_003E6C08();

extern void func_003E69F8(void *);
extern u8 D_L01_001E15E0[];
 
void func_L01_00478898(void) {
    void *x = D_L01_001E15E0;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E6C08();
    }
    func_003E69F8(x);
}
/* localdecomp:end func_L01_00478898 */

INCLUDE_ASM("asm/levels", func_L01_004788D0);

/* localdecomp:start func_L01_00478AA0 */
extern void func_L01_00478AA0(void);
extern void *func_003E6C08();

extern void func_003E6A98(void *);
extern u8 D_L01_001E15E0[];
 
void func_L01_00478AA0(void) {
    void *x = D_L01_001E15E0;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E6C08();
    }
    func_003E6A98(x);
}
/* localdecomp:end func_L01_00478AA0 */

/* localdecomp:start func_L01_00478AD8 */
extern void func_L01_00478AD8(void);
extern void *func_003E6C08();

extern void func_003E6B28(void *);
extern u8 D_L01_001E15E0[];
 
void func_L01_00478AD8(void) {
    void *x = D_L01_001E15E0;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E6C08();
    }
    func_003E6B28(x);
}
/* localdecomp:end func_L01_00478AD8 */
