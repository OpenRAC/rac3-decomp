#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x5628 - 0x4958];
    u8 fX[1];
} S_func_00496AB0;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} E_496DC0;
typedef struct {
    s32 id;
    s32 pad[3];
} Ent_497BC8;
typedef struct { s32 a; s32 b; s32 c; s32 d; } Ent_00497C30;

/* declared by functions of L01_00499C80.c, which this file was cut from */
extern void func_L01_0049A5B0(void *a);
extern void func_L01_0049A600(void);
extern void func_L01_00517748(int);
extern s32 D_L01_001D92DC;
extern void func_L01_0049A570(void);
extern void *D_L01_001D92E0;
extern void *D_L01_001D92E4;
extern void *func_003B42F8(s32);

/* localdecomp:start func_L01_0049A570 */
extern void *D_L01_001D92E4;
extern void *D_L01_001D92E0;
extern void *func_003B42F8(s32);
extern void func_003BB468(s32);
void func_L01_0049A570(void) {
    O_49A988 *o = ((O_49A988 * (*)(s32))func_003B42F8)(0);
    o->vt->fn(o);
    func_003BB468((*(s32 *)&D_L01_001D92E0));
    func_003BB468((*(s32 *)&D_L01_001D92E4));
}
/* localdecomp:end func_L01_0049A570 */

/* localdecomp:start func_L01_0049A5B0 */
__asm__(".extern D_L01_001D52FC, 16");
extern char *D_L01_001D52FC;
extern int func_L01_004A1128(void *);
extern void func_L01_00517748(int);
extern void func_L01_00516090_0049A5B0(void *);

void func_L01_0049A5B0(void *a)
{
    if (*(unsigned int *)(D_L01_001D52FC + 0x1C4) & 0x910) {
        func_L01_00517748(func_L01_004A1128(a));
        func_L01_00516090_0049A5B0(a);
    }
}
/* localdecomp:end func_L01_0049A5B0 */

/* localdecomp:start func_L01_0049A600 */
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 D_L01_001D92D8;
extern s32 D_L01_001D92DC;
extern E_496DC0 *D_L01_001D92E8;
extern s32 D_L01_001D933C;

void func_L01_0049A600(void) {
    s32 cur = func_003B9C58(func_003B9BD0(0));

    D_L01_001D92D8 = cur;
    if (cur != D_L01_001D92DC) {
        func_L01_00516FD8(0x4B000C, func_00381FF0(D_L01_001D92E8[cur].x0));
        func_L01_00516FD8(0x4B0005, func_00381FF0(D_L01_001D92E8[D_L01_001D92D8].x0));
        func_L01_00516FD8(0x4B0006, func_00381FF0(D_L01_001D92E8[D_L01_001D92D8].x4));
        D_L01_001D933C = 30;
    }
    D_L01_001D92DC = D_L01_001D92D8;
    if (D_L01_001D933C != 0) {
        if (--D_L01_001D933C == 0) {
            if (D_L01_001D92E8[D_L01_001D92D8].x8 < 0) {
                func_L01_00517190(0x4B0009, 0);
                func_L01_00516D60(0x4B0009, 1);
            } else {
                func_L01_00516D60(0x4B0009, 1);
                func_L01_00517190(0x4B0009, D_L01_001D92E8[D_L01_001D92D8].x8 + 1);
            }
        }
    }
}
/* localdecomp:end func_L01_0049A600 */
